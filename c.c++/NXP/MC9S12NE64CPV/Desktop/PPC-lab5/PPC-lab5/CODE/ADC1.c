/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : ADC1.c
**     Project   : Project_2
**     Processor : MC9S12NE64CPV
**     Component : Init_ADC
**     Version   : Component 01.196, Driver 01.11, CPU db: 2.87.134
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2017-03-27, 17:01
**     Abstract  :
**          This file implements the ADC (ADC) module initialization
**          according to the Peripheral Initialization Component settings,
**          and defines interrupt service routines prototypes.The ADC module
**          is an 8-channel (16-channel), 10-bit, multiplexed input successive
**          approximation analog-to-digital converter. Refer to device electrical
**          specifications for ATD accuracy. The block is designed to be
**          upwards compatible with the 68HC11 standard 8-bit A/D converter.
**          In addition, there are new operating modes that are unique to
**          the HC12 design.
**          Features :
**          - 8/10 Bit Resolution.
**          - 7msec, 10-Bit Single Conversion Time.
**          - Sample Buffer Amplifier.
**          - Programmable Sample Time.
**          - Left/Right Justified, Signed/Unsigned Result Data.
**          - External Trigger Control.
**          - Conversion Completion Interrupt Generation.
**          - Analog Input Multiplexer for 8 (16)Analog Input Channels.
**          - Analog/Digital Input Pin Multiplexing.
**          - 1 to 8 (1 to 16)Conversion Sequence Lengths.
**          - Continuous Conversion Mode.
**          - Multiple Channel Scans.
**     Settings  :
**          Component name                                 : ADC1
**          Device                                         : ADC
**          Settings:
**            Clock settings:
**              Sample Time                                : 16 A/D conversion clock periods
**              Prescaler                                  : 24
**              Frequency                                  : 500 kHz (calculated value, for information only)
**              ConvTime                                   : 56 us  (calculated value, for information only)
**            Conv. sequence length                        : 8
**            Conversion mode                              : Continuous conversion
**            Channel sample mode                          : Across several channels
**            Fast flag clear all                          : Enabled
**            Wrap around channel                          : AN7
**            External trigger                             : Disabled
**            External trigger control                     : Falling edge
**            Conv. results are placed in                  : Corresponding result register
**            Result data formats                          : 10-bit/left justified/unsigned
**            Background debug freeze                      : Freeze Immediately
**            Special channel conversion                   : Disabled
**            Power down in Wait mode                      : Disabled
**          Pins/Signals:
**            Input Pin0                                   : PAD0_AN0
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**            Input Pin1                                   : PAD1_AN1
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**            Input Pin2                                   : PAD2_AN2
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**            Input Pin3                                   : PAD3_AN3
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**            Input Pin4                                   : PAD4_AN4
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**            Input Pin5                                   : PAD5_AN5
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**            Input Pin6                                   : PAD6_AN6
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**            Input Pin7                                   : PAD7_AN7
**              Pin Signal                                 : 
**              Digital Input                              : Disabled
**          Interrupts:
**            Sequence Complete                            : Enabled
**            Interrupt                                    : Vatd
**            Priority                                     : 1
**            ISR name                                     : adc_isr
**          Initialization:
**            Call Init in CPU init. code                  : yes
**            Module                                       : Enabled
**            Start ADC conversion                         : yes
**            Initial channel select                       : AN0
**            Generate recovery delay                      : yes
**     Contents  :
**         Init - void ADC1_Init(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ADC1. */

#include "ADC1.h"

/*
** ###################################################################
**
**  The interrupt service routine(s) must be implemented
**  by user in one of the following user modules.
**
**  If the "Generate ISR" option is enabled, Processor Expert generates
**  ISR templates in the CPU event module.
**
**  User modules:
**      Project_2.c
**      Events.c
**
** ###################################################################
#pragma CODE_SEG __NEAR_SEG NON_BANKED
ISR(adc_isr)
        {
        // NOTE: The routine should include the following actions to obtain
        //       correct functionality of the hardware.
        //
        //      The interrupt will remain pending as long as the ASCIF (SCF) flag is set.
        //      The ASCIF (SCF) bit is cleared whenever the ATDCTL5 register is written.
        //      The ASCIF (SCF) bit is also cleared whenever the SCF bit is written.
        //      And the third case is whenever AFFC bit is set and read of a result register.
        //      Example:
        //               for second case : ATDSTAT0_SCF = 1;
        //               for third case : result = ATDDR0;
        }
#pragma CODE_SEG DEFAULT
*/
/*
** ===================================================================
**     Method      :  ADC1_Init (component Init_ADC)
**
**     Description :
**         This method initializes registers of the ADC module
**         according to this Peripheral Initialization Component settings.
**         Call this method in user code to initialize the module.
**         By default, the method is called by PE automatically; see
**         "Call Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ADC1_Init(void)
{
  /* Initialization of the ADC module */
  /* ATDDIEN: IEN7=0,IEN6=0,IEN5=0,IEN4=0,IEN3=0,IEN2=0,IEN1=0,IEN0=0 */
  setReg8(ATDDIEN, 0x00U);              
  /* ATDCTL0: ??=0,??=0,??=0,??=0,WRAP3=1,WRAP2=1,WRAP1=1,WRAP0=1 */
  setReg8(ATDCTL0, 0x0FU);              
  /* ATDCTL1: ETRIGSEL=0,??=0,??=0,??=0,ETRIGCH3=1,ETRIGCH2=1,ETRIGCH1=1,ETRIGCH0=1 */
  setReg8(ATDCTL1, 0x0FU);              
  /* ATDCTL3: ??=0,S8C=1,S4C=0,S2C=0,S1C=0,FIFO=0,FRZ1=1,FRZ0=1 */
  setReg8(ATDCTL3, 0x43U);              
  /* ATDCTL4: SRES8=0,SMP1=1,SMP0=1,PRS4=1,PRS3=1,PRS2=0,PRS1=0,PRS0=0 */
  setReg8(ATDCTL4, 0x78U);              
  /* ATDTEST1: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,SC=0 */
  setReg8(ATDTEST1, 0x00U);             
  /* ATDCTL2: ADPU=1,AFFC=1,AWAI=0,ETRIGLE=0,ETRIGP=0,ETRIGE=0,ASCIE=1,ASCIF=0 */
  setReg8(ATDCTL2, 0xC2U);              
  /*
     The following delay loop generates a delay of approx. 20us, which is needed for
     the module to recover from power down state.
  */
  asm {
    /*
     * Delay
     *   - requested                  : 20 us @ 25MHz,
     *   - possible                   : 500 c, 20000 ns
     */
    pshd                               /* (2 c: 80 ns) backup D */
    ldd #$00A4                         /* (2 c: 80 ns) number of iterations */
    label0:
    dbne d, label0                     /* (3 c: 120 ns) repeat 164x */
    puld                               /* (3 c: 120 ns) restore D */
    nop                                /* (1 c: 40 ns) wait for 1 c */
  };
  /* ATDCTL5: DJM=0,DSGN=0,SCAN=1,MULT=1,??=0,CC=0,CB=0,CA=0 */
  setReg8(ATDCTL5, 0x30U);              
}

/* END ADC1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
