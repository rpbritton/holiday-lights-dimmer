/*******************************************************************************
* File Name: zero_cross_isr.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_zero_cross_isr_H)
#define CY_ISR_zero_cross_isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void zero_cross_isr_Start(void);
void zero_cross_isr_StartEx(cyisraddress address);
void zero_cross_isr_Stop(void);

CY_ISR_PROTO(zero_cross_isr_Interrupt);

void zero_cross_isr_SetVector(cyisraddress address);
cyisraddress zero_cross_isr_GetVector(void);

void zero_cross_isr_SetPriority(uint8 priority);
uint8 zero_cross_isr_GetPriority(void);

void zero_cross_isr_Enable(void);
uint8 zero_cross_isr_GetState(void);
void zero_cross_isr_Disable(void);

void zero_cross_isr_SetPending(void);
void zero_cross_isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the zero_cross_isr ISR. */
#define zero_cross_isr_INTC_VECTOR            ((reg32 *) zero_cross_isr__INTC_VECT)

/* Address of the zero_cross_isr ISR priority. */
#define zero_cross_isr_INTC_PRIOR             ((reg32 *) zero_cross_isr__INTC_PRIOR_REG)

/* Priority of the zero_cross_isr interrupt. */
#define zero_cross_isr_INTC_PRIOR_NUMBER      zero_cross_isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable zero_cross_isr interrupt. */
#define zero_cross_isr_INTC_SET_EN            ((reg32 *) zero_cross_isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the zero_cross_isr interrupt. */
#define zero_cross_isr_INTC_CLR_EN            ((reg32 *) zero_cross_isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the zero_cross_isr interrupt state to pending. */
#define zero_cross_isr_INTC_SET_PD            ((reg32 *) zero_cross_isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the zero_cross_isr interrupt. */
#define zero_cross_isr_INTC_CLR_PD            ((reg32 *) zero_cross_isr__INTC_CLR_PD_REG)



#endif /* CY_ISR_zero_cross_isr_H */


/* [] END OF FILE */
