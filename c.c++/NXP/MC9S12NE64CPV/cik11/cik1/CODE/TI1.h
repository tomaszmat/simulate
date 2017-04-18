/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TI1.h
**     Project   : cik1
**     Processor : MC9S12NE64CPV
**     Component : TimerInt
**     Version   : Component 02.159, Driver 01.20, CPU db: 2.87.134
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2017-03-13, 17:23
**     Abstract  :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings  :
**         Timer name                  : TIM_Counter (16-bit)
**         Compare name                : TC4
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 25000000 Hz
**           Initial period/frequency
**             Xtal ticks              : 2500
**             microseconds            : 100
**             seconds (real)          : 0.0001
**             Hz                      : 10000
**             kHz                     : 10
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TCNT      [$0044]
**              Mode                   : TIOS      [$0040]
**              Run                    : TSCR1     [$0046]
**              Prescaler              : TSCR2     [$004D]
**
**         Compare registers
**              Compare                : TC4       [$0058]
**
**         Flip-flop registers
**              Mode                   : TCTL1     [$0048]
**     Contents  :
**         No public methods
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TI1
#define __TI1

/* MODULE TI1. */

#include "Cpu.h"


#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void TI1_Interrupt(void);
/*
** ===================================================================
**     Method      :  TI1_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END TI1. */

#endif /* ifndef __TI1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
