/*******************************************************************************
* File Name: TCPWM2.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the TCPWM2
*  component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "TCPWM2.h"

uint8 TCPWM2_initVar = 0u;


/*******************************************************************************
* Function Name: TCPWM2_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default TCPWM2 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (TCPWM2__QUAD == TCPWM2_CONFIG)
        TCPWM2_CONTROL_REG = TCPWM2_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        TCPWM2_TRIG_CONTROL1_REG  = TCPWM2_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        TCPWM2_SetInterruptMode(TCPWM2_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        TCPWM2_SetCounterMode(TCPWM2_COUNT_DOWN);
        TCPWM2_WritePeriod(TCPWM2_QUAD_PERIOD_INIT_VALUE);
        TCPWM2_WriteCounter(TCPWM2_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (TCPWM2__QUAD == TCPWM2_CONFIG) */

    #if (TCPWM2__TIMER == TCPWM2_CONFIG)
        TCPWM2_CONTROL_REG = TCPWM2_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        TCPWM2_TRIG_CONTROL1_REG  = TCPWM2_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        TCPWM2_SetInterruptMode(TCPWM2_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        TCPWM2_WritePeriod(TCPWM2_TC_PERIOD_VALUE );

        #if (TCPWM2__COMPARE == TCPWM2_TC_COMP_CAP_MODE)
            TCPWM2_WriteCompare(TCPWM2_TC_COMPARE_VALUE);

            #if (1u == TCPWM2_TC_COMPARE_SWAP)
                TCPWM2_SetCompareSwap(1u);
                TCPWM2_WriteCompareBuf(TCPWM2_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == TCPWM2_TC_COMPARE_SWAP) */
        #endif  /* (TCPWM2__COMPARE == TCPWM2_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (TCPWM2_CY_TCPWM_V2 && TCPWM2_TIMER_UPDOWN_CNT_USED && !TCPWM2_CY_TCPWM_4000)
            TCPWM2_WriteCounter(1u);
        #elif(TCPWM2__COUNT_DOWN == TCPWM2_TC_COUNTER_MODE)
            TCPWM2_WriteCounter(TCPWM2_TC_PERIOD_VALUE);
        #else
            TCPWM2_WriteCounter(0u);
        #endif /* (TCPWM2_CY_TCPWM_V2 && TCPWM2_TIMER_UPDOWN_CNT_USED && !TCPWM2_CY_TCPWM_4000) */
    #endif  /* (TCPWM2__TIMER == TCPWM2_CONFIG) */

    #if (TCPWM2__PWM_SEL == TCPWM2_CONFIG)
        TCPWM2_CONTROL_REG = TCPWM2_CTRL_PWM_BASE_CONFIG;

        #if (TCPWM2__PWM_PR == TCPWM2_PWM_MODE)
            TCPWM2_CONTROL_REG |= TCPWM2_CTRL_PWM_RUN_MODE;
            TCPWM2_WriteCounter(TCPWM2_PWM_PR_INIT_VALUE);
        #else
            TCPWM2_CONTROL_REG |= TCPWM2_CTRL_PWM_ALIGN | TCPWM2_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (TCPWM2_CY_TCPWM_V2 && TCPWM2_PWM_UPDOWN_CNT_USED && !TCPWM2_CY_TCPWM_4000)
                TCPWM2_WriteCounter(1u);
            #elif (TCPWM2__RIGHT == TCPWM2_PWM_ALIGN)
                TCPWM2_WriteCounter(TCPWM2_PWM_PERIOD_VALUE);
            #else 
                TCPWM2_WriteCounter(0u);
            #endif  /* (TCPWM2_CY_TCPWM_V2 && TCPWM2_PWM_UPDOWN_CNT_USED && !TCPWM2_CY_TCPWM_4000) */
        #endif  /* (TCPWM2__PWM_PR == TCPWM2_PWM_MODE) */

        #if (TCPWM2__PWM_DT == TCPWM2_PWM_MODE)
            TCPWM2_CONTROL_REG |= TCPWM2_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (TCPWM2__PWM_DT == TCPWM2_PWM_MODE) */

        #if (TCPWM2__PWM == TCPWM2_PWM_MODE)
            TCPWM2_CONTROL_REG |= TCPWM2_CTRL_PWM_PRESCALER;
        #endif  /* (TCPWM2__PWM == TCPWM2_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        TCPWM2_TRIG_CONTROL1_REG  = TCPWM2_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        TCPWM2_SetInterruptMode(TCPWM2_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (TCPWM2__PWM_PR == TCPWM2_PWM_MODE)
            TCPWM2_TRIG_CONTROL2_REG =
                    (TCPWM2_CC_MATCH_NO_CHANGE    |
                    TCPWM2_OVERLOW_NO_CHANGE      |
                    TCPWM2_UNDERFLOW_NO_CHANGE);
        #else
            #if (TCPWM2__LEFT == TCPWM2_PWM_ALIGN)
                TCPWM2_TRIG_CONTROL2_REG = TCPWM2_PWM_MODE_LEFT;
            #endif  /* ( TCPWM2_PWM_LEFT == TCPWM2_PWM_ALIGN) */

            #if (TCPWM2__RIGHT == TCPWM2_PWM_ALIGN)
                TCPWM2_TRIG_CONTROL2_REG = TCPWM2_PWM_MODE_RIGHT;
            #endif  /* ( TCPWM2_PWM_RIGHT == TCPWM2_PWM_ALIGN) */

            #if (TCPWM2__CENTER == TCPWM2_PWM_ALIGN)
                TCPWM2_TRIG_CONTROL2_REG = TCPWM2_PWM_MODE_CENTER;
            #endif  /* ( TCPWM2_PWM_CENTER == TCPWM2_PWM_ALIGN) */

            #if (TCPWM2__ASYMMETRIC == TCPWM2_PWM_ALIGN)
                TCPWM2_TRIG_CONTROL2_REG = TCPWM2_PWM_MODE_ASYM;
            #endif  /* (TCPWM2__ASYMMETRIC == TCPWM2_PWM_ALIGN) */
        #endif  /* (TCPWM2__PWM_PR == TCPWM2_PWM_MODE) */

        /* Set other values from customizer */
        TCPWM2_WritePeriod(TCPWM2_PWM_PERIOD_VALUE );
        TCPWM2_WriteCompare(TCPWM2_PWM_COMPARE_VALUE);

        #if (1u == TCPWM2_PWM_COMPARE_SWAP)
            TCPWM2_SetCompareSwap(1u);
            TCPWM2_WriteCompareBuf(TCPWM2_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == TCPWM2_PWM_COMPARE_SWAP) */

        #if (1u == TCPWM2_PWM_PERIOD_SWAP)
            TCPWM2_SetPeriodSwap(1u);
            TCPWM2_WritePeriodBuf(TCPWM2_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == TCPWM2_PWM_PERIOD_SWAP) */
    #endif  /* (TCPWM2__PWM_SEL == TCPWM2_CONFIG) */
    
}


/*******************************************************************************
* Function Name: TCPWM2_Enable
********************************************************************************
*
* Summary:
*  Enables the TCPWM2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    TCPWM2_BLOCK_CONTROL_REG |= TCPWM2_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (TCPWM2__PWM_SEL == TCPWM2_CONFIG)
        #if (0u == TCPWM2_PWM_START_SIGNAL_PRESENT)
            TCPWM2_TriggerCommand(TCPWM2_MASK, TCPWM2_CMD_START);
        #endif /* (0u == TCPWM2_PWM_START_SIGNAL_PRESENT) */
    #endif /* (TCPWM2__PWM_SEL == TCPWM2_CONFIG) */

    #if (TCPWM2__TIMER == TCPWM2_CONFIG)
        #if (0u == TCPWM2_TC_START_SIGNAL_PRESENT)
            TCPWM2_TriggerCommand(TCPWM2_MASK, TCPWM2_CMD_START);
        #endif /* (0u == TCPWM2_TC_START_SIGNAL_PRESENT) */
    #endif /* (TCPWM2__TIMER == TCPWM2_CONFIG) */
    
    #if (TCPWM2__QUAD == TCPWM2_CONFIG)
        #if (0u != TCPWM2_QUAD_AUTO_START)
            TCPWM2_TriggerCommand(TCPWM2_MASK, TCPWM2_CMD_RELOAD);
        #endif /* (0u != TCPWM2_QUAD_AUTO_START) */
    #endif  /* (TCPWM2__QUAD == TCPWM2_CONFIG) */
}


/*******************************************************************************
* Function Name: TCPWM2_Start
********************************************************************************
*
* Summary:
*  Initializes the TCPWM2 with default customizer
*  values when called the first time and enables the TCPWM2.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TCPWM2_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time TCPWM2_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the TCPWM2_Start() routine.
*
*******************************************************************************/
void TCPWM2_Start(void)
{
    if (0u == TCPWM2_initVar)
    {
        TCPWM2_Init();
        TCPWM2_initVar = 1u;
    }

    TCPWM2_Enable();
}


/*******************************************************************************
* Function Name: TCPWM2_Stop
********************************************************************************
*
* Summary:
*  Disables the TCPWM2.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_BLOCK_CONTROL_REG &= (uint32)~TCPWM2_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the TCPWM2. This function is used when
*  configured as a generic TCPWM2 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the TCPWM2 to operate in
*   Values:
*   - TCPWM2_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - TCPWM2_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - TCPWM2_MODE_QUAD - Quadrature decoder
*         - TCPWM2_MODE_PWM - PWM
*         - TCPWM2_MODE_PWM_DT - PWM with dead time
*         - TCPWM2_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_MODE_MASK;
    TCPWM2_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - TCPWM2_MODE_X1 - Counts on phi 1 rising
*         - TCPWM2_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - TCPWM2_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_QUAD_MODE_MASK;
    TCPWM2_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - TCPWM2_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - TCPWM2_PRESCALE_DIVBY2    - Divide by 2
*         - TCPWM2_PRESCALE_DIVBY4    - Divide by 4
*         - TCPWM2_PRESCALE_DIVBY8    - Divide by 8
*         - TCPWM2_PRESCALE_DIVBY16   - Divide by 16
*         - TCPWM2_PRESCALE_DIVBY32   - Divide by 32
*         - TCPWM2_PRESCALE_DIVBY64   - Divide by 64
*         - TCPWM2_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_PRESCALER_MASK;
    TCPWM2_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the TCPWM2 runs
*  continuously or stops when terminal count is reached.  By default the
*  TCPWM2 operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_ONESHOT_MASK;
    TCPWM2_CONTROL_REG |= ((uint32)((oneShotEnable & TCPWM2_1BIT_MASK) <<
                                                               TCPWM2_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetPWMMode(uint32 modeMask)
{
    TCPWM2_TRIG_CONTROL2_REG = (modeMask & TCPWM2_6BIT_MASK);
}



/*******************************************************************************
* Function Name: TCPWM2_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_PWM_SYNC_KILL_MASK;
    TCPWM2_CONTROL_REG |= ((uint32)((syncKillEnable & TCPWM2_1BIT_MASK)  <<
                                               TCPWM2_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_PWM_STOP_KILL_MASK;
    TCPWM2_CONTROL_REG |= ((uint32)((stopOnKillEnable & TCPWM2_1BIT_MASK)  <<
                                                         TCPWM2_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_PRESCALER_MASK;
    TCPWM2_CONTROL_REG |= ((uint32)((deadTime & TCPWM2_8BIT_MASK) <<
                                                          TCPWM2_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - TCPWM2_INVERT_LINE   - Inverts the line output
*         - TCPWM2_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_INV_OUT_MASK;
    TCPWM2_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: TCPWM2_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_WriteCounter(uint32 count)
{
    TCPWM2_COUNTER_REG = (count & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 TCPWM2_ReadCounter(void)
{
    return (TCPWM2_COUNTER_REG & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - TCPWM2_COUNT_UP       - Counts up
*     - TCPWM2_COUNT_DOWN     - Counts down
*     - TCPWM2_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - TCPWM2_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_UPDOWN_MASK;
    TCPWM2_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_WritePeriod(uint32 period)
{
    TCPWM2_PERIOD_REG = (period & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 TCPWM2_ReadPeriod(void)
{
    return (TCPWM2_PERIOD_REG & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_RELOAD_CC_MASK;
    TCPWM2_CONTROL_REG |= (swapEnable & TCPWM2_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_WritePeriodBuf(uint32 periodBuf)
{
    TCPWM2_PERIOD_BUF_REG = (periodBuf & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 TCPWM2_ReadPeriodBuf(void)
{
    return (TCPWM2_PERIOD_BUF_REG & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_CONTROL_REG &= (uint32)~TCPWM2_RELOAD_PERIOD_MASK;
    TCPWM2_CONTROL_REG |= ((uint32)((swapEnable & TCPWM2_1BIT_MASK) <<
                                                            TCPWM2_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void TCPWM2_WriteCompare(uint32 compare)
{
    #if (TCPWM2_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (TCPWM2_CY_TCPWM_4000) */

    #if (TCPWM2_CY_TCPWM_4000)
        currentMode = ((TCPWM2_CONTROL_REG & TCPWM2_UPDOWN_MASK) >> TCPWM2_UPDOWN_SHIFT);

        if (((uint32)TCPWM2__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)TCPWM2__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (TCPWM2_CY_TCPWM_4000) */
    
    TCPWM2_COMP_CAP_REG = (compare & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 TCPWM2_ReadCompare(void)
{
    #if (TCPWM2_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (TCPWM2_CY_TCPWM_4000) */

    #if (TCPWM2_CY_TCPWM_4000)
        currentMode = ((TCPWM2_CONTROL_REG & TCPWM2_UPDOWN_MASK) >> TCPWM2_UPDOWN_SHIFT);
        
        regVal = TCPWM2_COMP_CAP_REG;
        
        if (((uint32)TCPWM2__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)TCPWM2__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & TCPWM2_16BIT_MASK);
    #else
        return (TCPWM2_COMP_CAP_REG & TCPWM2_16BIT_MASK);
    #endif /* (TCPWM2_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: TCPWM2_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void TCPWM2_WriteCompareBuf(uint32 compareBuf)
{
    #if (TCPWM2_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (TCPWM2_CY_TCPWM_4000) */

    #if (TCPWM2_CY_TCPWM_4000)
        currentMode = ((TCPWM2_CONTROL_REG & TCPWM2_UPDOWN_MASK) >> TCPWM2_UPDOWN_SHIFT);

        if (((uint32)TCPWM2__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)TCPWM2__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (TCPWM2_CY_TCPWM_4000) */
    
    TCPWM2_COMP_CAP_BUF_REG = (compareBuf & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 TCPWM2_ReadCompareBuf(void)
{
    #if (TCPWM2_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (TCPWM2_CY_TCPWM_4000) */

    #if (TCPWM2_CY_TCPWM_4000)
        currentMode = ((TCPWM2_CONTROL_REG & TCPWM2_UPDOWN_MASK) >> TCPWM2_UPDOWN_SHIFT);

        regVal = TCPWM2_COMP_CAP_BUF_REG;
        
        if (((uint32)TCPWM2__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)TCPWM2__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & TCPWM2_16BIT_MASK);
    #else
        return (TCPWM2_COMP_CAP_BUF_REG & TCPWM2_16BIT_MASK);
    #endif /* (TCPWM2_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: TCPWM2_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 TCPWM2_ReadCapture(void)
{
    return (TCPWM2_COMP_CAP_REG & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 TCPWM2_ReadCaptureBuf(void)
{
    return (TCPWM2_COMP_CAP_BUF_REG & TCPWM2_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TCPWM2_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TCPWM2_TRIG_LEVEL     - Level
*     - TCPWM2_TRIG_RISING    - Rising edge
*     - TCPWM2_TRIG_FALLING   - Falling edge
*     - TCPWM2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_TRIG_CONTROL1_REG &= (uint32)~TCPWM2_CAPTURE_MASK;
    TCPWM2_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TCPWM2_TRIG_LEVEL     - Level
*     - TCPWM2_TRIG_RISING    - Rising edge
*     - TCPWM2_TRIG_FALLING   - Falling edge
*     - TCPWM2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_TRIG_CONTROL1_REG &= (uint32)~TCPWM2_RELOAD_MASK;
    TCPWM2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TCPWM2_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TCPWM2_TRIG_LEVEL     - Level
*     - TCPWM2_TRIG_RISING    - Rising edge
*     - TCPWM2_TRIG_FALLING   - Falling edge
*     - TCPWM2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_TRIG_CONTROL1_REG &= (uint32)~TCPWM2_START_MASK;
    TCPWM2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TCPWM2_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TCPWM2_TRIG_LEVEL     - Level
*     - TCPWM2_TRIG_RISING    - Rising edge
*     - TCPWM2_TRIG_FALLING   - Falling edge
*     - TCPWM2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_TRIG_CONTROL1_REG &= (uint32)~TCPWM2_STOP_MASK;
    TCPWM2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TCPWM2_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TCPWM2_TRIG_LEVEL     - Level
*     - TCPWM2_TRIG_RISING    - Rising edge
*     - TCPWM2_TRIG_FALLING   - Falling edge
*     - TCPWM2_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_TRIG_CONTROL1_REG &= (uint32)~TCPWM2_COUNT_MASK;
    TCPWM2_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TCPWM2_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - TCPWM2_CMD_CAPTURE    - Trigger Capture/Switch command
*     - TCPWM2_CMD_RELOAD     - Trigger Reload/Index command
*     - TCPWM2_CMD_STOP       - Trigger Stop/Kill command
*     - TCPWM2_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TCPWM2_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TCPWM2_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the TCPWM2.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - TCPWM2_STATUS_DOWN    - Set if counting down
*     - TCPWM2_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 TCPWM2_ReadStatus(void)
{
    return ((TCPWM2_STATUS_REG >> TCPWM2_RUNNING_STATUS_SHIFT) |
            (TCPWM2_STATUS_REG & TCPWM2_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: TCPWM2_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - TCPWM2_INTR_MASK_TC       - Terminal count mask
*     - TCPWM2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetInterruptMode(uint32 interruptMask)
{
    TCPWM2_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: TCPWM2_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - TCPWM2_INTR_MASK_TC       - Terminal count mask
*     - TCPWM2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TCPWM2_GetInterruptSourceMasked(void)
{
    return (TCPWM2_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: TCPWM2_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - TCPWM2_INTR_MASK_TC       - Terminal count mask
*     - TCPWM2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TCPWM2_GetInterruptSource(void)
{
    return (TCPWM2_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: TCPWM2_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - TCPWM2_INTR_MASK_TC       - Terminal count mask
*     - TCPWM2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_ClearInterrupt(uint32 interruptMask)
{
    TCPWM2_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: TCPWM2_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - TCPWM2_INTR_MASK_TC       - Terminal count mask
*     - TCPWM2_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM2_SetInterrupt(uint32 interruptMask)
{
    TCPWM2_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
