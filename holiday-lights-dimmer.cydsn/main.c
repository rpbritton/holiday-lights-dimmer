/******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description:  This code example demonstrates a CapSense linear slider with
* five segments and three CapSense buttons operation. CapSense linear slider and
* buttons data is sent to CapSense Tuner or EZ-BLE PRoC Module using I2C communication.
* The CapSense linear slider touch position and buttons status is used to turn ON/OFF
* corresponding LEDs on the kit. It also demonstrates connectivity between the
* EZ-BLE PRoC Module (acting as a Peripheral and GATT server device) and mobile device
* running the CySmart mobile application (acting as a Central and GATT client device).
* This code example also demonstrates a simple breathing effect of LED with breath-in
* and breath-out rate of 1 Hz using SmartIO and PWM components.
*
* Related Document: CE210709 CapSense Linear Slider and Buttons.pdf
*
* Hardware Dependency: See CE210709 CapSense Linear Slider and Buttons.pdf
*
*******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability.
*******************************************************************************/
/*******************************************************************************
*   Included Headers
*******************************************************************************/
#include "CapSense.h"
#include <project.h>

/*****************************************************************************
* MACRO Definitions
*****************************************************************************/     

/* Boolean constants */
#define LED_ON						(0u)
#define LED_OFF						(1u)

/* Finite state machine states for device operating states 
    SENSOR_SCAN - Sensors are scanned in this state
    WAIT_FOR_SCAN_COMPLETE - CPU is put to sleep in this state
    PROCESS_DATA - Sensor data is processed, LEDs are controlled */
typedef enum
{
    SENSOR_SCAN = 0x01u,                
    WAIT_FOR_SCAN_COMPLETE = 0x02u,     
    PROCESS_DATA = 0x03u,               
} DEVICE_STATE;

/* Defining step size for LED control based on centroid position of slider. */
#define STEP_SIZE (CapSense_SLD_X_RESOLUTION/CapSense_SLD_NUM_SENSORS)

//uint32_t pwmValue;
volatile double value;

CY_ISR( Pin_ZC_Handler )
{
    // 1 full 60hz wave = 1/60 = 16.667ms
    // 1 zero cross = 1/2 wave = 8.333ms
    // 8.333ms = 83333us
    // (8333us-10us)/1 = 8323
    if(value >= 0.05)
    {l
        int dimAmount = 8323.33*(1.25-value);
        CyDelayUs(dimAmount);
        Pin_LC_Write(1u);
        CyDelayUs(10);
        Pin_LC_Write(0u);
    }
    
    Pin_ZC_ClearInterrupt();
}

int main()
{	
    /* Variable to hold the current device state 
    *  State machine starts with sensor scan state after power-up
    */
    DEVICE_STATE currentState = SENSOR_SCAN;  
    
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
        
    /* Start CapSense block */
    CapSense_Start();
    
    /* Start the light driver interrupt. */
    Pin_ZC_Int_StartEx( Pin_ZC_Handler );
     			
    for(;;)
    {
        /* Switch between SENSOR_SCAN->WAIT_FOR_SCAN_COMPLETE->PROCESS_DATA states */
        switch(currentState)
        {
            case SENSOR_SCAN:
	            /* Initiate new scan only if the CapSense block is idle */
                if(CapSense_NOT_BUSY == CapSense_IsBusy())
                {
                    /* Scan widget configured by CSDSetupWidget API */
                    CapSense_ScanAllWidgets();
                                        
                    /* Set next state to WAIT_FOR_SCAN_COMPLETE  */
                    currentState = WAIT_FOR_SCAN_COMPLETE;
                }
                break;

            case WAIT_FOR_SCAN_COMPLETE:
                /* Put the device to CPU Sleep until CapSense scanning is complete*/
                if(CapSense_NOT_BUSY != CapSense_IsBusy())
                {
                    CySysPmSleep();
                }
                /* If CapSense scanning is complete, process the CapSense data */
                else
                {
                    currentState = PROCESS_DATA;
                }
                break;
        
            case PROCESS_DATA:
                /* Process data on all the enabled widgets */
                CapSense_ProcessAllWidgets();
                
                /* Get the touch position(centroid) of CapSense Linear Slider. */
                uint32 centroid = CapSense_GetCentroidPos(CapSense_SLD_WDGT_ID);

                /*Turn ON/OFF LEDs based on the finger position (centroid) on the CapSense Linear slider*/
                if(CapSense_IsWidgetActive(CapSense_SLD_WDGT_ID))
                {
                    LED4_Write( ( (centroid > 0) || (centroid == 0)) ? LED_ON : LED_OFF );
                    LED5_Write( ( centroid > ( 1 * STEP_SIZE ) ) ? LED_ON : LED_OFF );
                    LED6_Write( ( centroid > ( 2 * STEP_SIZE ) ) ? LED_ON : LED_OFF );
                    LED7_Write( ( centroid > ( 3 * STEP_SIZE ) ) ? LED_ON : LED_OFF );
                    LED8_Write( ( centroid > ( 4 * STEP_SIZE ) ) ? LED_ON : LED_OFF );
                    
                    value = (double)centroid / (double)CapSense_SLD_X_RESOLUTION;
                }
                else
                {
                    LED4_Write(LED_OFF);
                    LED5_Write(LED_OFF);
                    LED6_Write(LED_OFF);
                    LED7_Write(LED_OFF);
                    LED8_Write(LED_OFF);
                }
               
                /*Turn ON/OFF LEDs based on the status of the corresponding CapSense buttons*/
                if(CapSense_IsWidgetActive(CapSense_BTN0_WDGT_ID))
                {
                    LED9_Write(LED_ON);
                    
                    value = 1;
                }
                else
                {
                    LED9_Write(LED_OFF);
                }
                //LED9_Write(CapSense_IsWidgetActive(CapSense_BTN0_WDGT_ID) ? LED_ON : LED_OFF );
                if(CapSense_IsWidgetActive(CapSense_BTN1_WDGT_ID))
                {
                    LED10_Write(LED_ON);
                    
                    value = 0.5;
                }
                else
                {
                    LED10_Write(LED_OFF);
                }
                //LED10_Write(CapSense_IsWidgetActive(CapSense_BTN1_WDGT_ID) ? LED_ON : LED_OFF );
                if(CapSense_IsWidgetActive(CapSense_BTN2_WDGT_ID))
                {
                    LED11_Write(LED_ON);
                    
                    value = 0;
                }
                else
                {
                    LED11_Write(LED_OFF);
                }
                //LED11_Write(CapSense_IsWidgetActive(CapSense_BTN2_WDGT_ID) ? LED_ON : LED_OFF );
                
                /* Set the device state to SENSOR_SCAN */
                currentState = SENSOR_SCAN;  
                break;  
             
            /*******************************************************************
             * Unknown power mode state. Unexpected situation.
             ******************************************************************/    
            default:
                break;
        } 
    }
}

/* [] END OF FILE */
