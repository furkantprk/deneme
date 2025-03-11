/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney_3_main.c
 *
 * Code generated for Simulink model 'deney_3'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Mar 11 22:31:06 2025
 */

/* Set Fuses Options */

#pragma config FNOSC = PRI
#pragma config POSCMD = HS, OSCIOFNC = ON, FCKSM = CSECMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

#define MCHP_isMainFile
#include "deney_3.h"
#include "deney_3_private.h"

/* Microchip Global Variables */
/* Solver mode : SingleTasking */
int main()
{
  /* Initialize model */

  /* Start Clock Switching */
  if ((OSCCONbits.COSC & 1) && !(OSCCONbits.COSC & 4))/* check not already in PLL mode (0?1) */
  {
    __builtin_write_OSCCONH(0);        /* Clock Switch to non PLL mode */
    __builtin_write_OSCCONL(0x01);     /* Start clock switching */
    __asm__ volatile("nop\n"
                     "nop");
    while (OSCCONbits.COSC != 0) ;
  }

  PLLFBD = 110;                        /* Oscillator PLL : PLLDIV */
  CLKDIV = 0x05;                       /* Oscillator PLL : FRCDIV ; PLLPOST ; PLLPRE */
  __builtin_write_OSCCONH(3);          /* Clock Switch to desired configuration */
  __builtin_write_OSCCONL(0x01);       /* Start clock switching */

  /* Configure Pins as Analog or Digital */
  AD1PCFGL = 0x01FC;

  /* Configure Remappables Pins */

  /* Configure Digitals I/O directions */
  TRISB = 0xFF00;                      /* Port input (1) / output (0) */
  TRISC = 0xFF00;                      /* Port input (1) / output (0) */
  LATB = LATB | 0x08;                  /* Initial Outputs set to 1 */
  LATB = LATB & 0xFF08;                /* Initial Outputs set to 0 */
  LATC = LATC | 0x08;                  /* Initial Outputs set to 1 */
  LATC = LATC & 0xFF08;                /* Initial Outputs set to 0 */

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  deney_3_initialize();

  /* Configure Timers */
  /* --- TIMER 1 --- This timer is enabled at end of configuration functions. */
  T1CON = 0;                           /* Stop Timer 1 and resets control register */
  _T1IP = 2;                           /* Set timer Interrupt Priority */
  _T1IF = 0;                           /* Reset pending Interrupt */
  _T1IE = 1;                           /* Enable Timer Interrupt. */
  PR1 = 0xC34F;                        /* Period */
  T1CON = 0x10;                        /* Set timer Prescaler ; internal clock source */

  /* Enable Time-step */
  TMR1 = 0xC34E;                       /* Initialize Timer Value */
  T1CONbits.TON = 1;                /* Start timer 1. Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */

  /* Single rate scheduler function */
  MCHP_Scheduler();                    /* no return */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
