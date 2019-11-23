/*******************************************************************************
* File Name: light_control_pin.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_light_control_pin_ALIASES_H) /* Pins light_control_pin_ALIASES_H */
#define CY_PINS_light_control_pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define light_control_pin_0			(light_control_pin__0__PC)
#define light_control_pin_0_PS		(light_control_pin__0__PS)
#define light_control_pin_0_PC		(light_control_pin__0__PC)
#define light_control_pin_0_DR		(light_control_pin__0__DR)
#define light_control_pin_0_SHIFT	(light_control_pin__0__SHIFT)
#define light_control_pin_0_INTR	((uint16)((uint16)0x0003u << (light_control_pin__0__SHIFT*2u)))

#define light_control_pin_INTR_ALL	 ((uint16)(light_control_pin_0_INTR))


#endif /* End Pins light_control_pin_ALIASES_H */


/* [] END OF FILE */
