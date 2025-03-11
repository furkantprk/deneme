/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney_3.c
 *
 * Code generated for Simulink model 'deney_3'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Mar 11 22:31:06 2025
 */

#include "deney_3.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "deney_3_private.h"
#include "rtwtypes.h"
#include <float.h>

/* Block signals and states (default storage) */
DW_deney_3_T deney_3_DW;
volatile uint_T ContinueTimeStep __attribute__ ((near)) = 0;/* Microchip Global Variable for single rate scheduler */
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void deney_3_step(void)
{
  real_T rtb_Switch1;
  real_T tmp;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DataTypeConversion1;
  boolean_T rtb_DigitalInput_o1;
  boolean_T rtb_LogicalOperator;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */
  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput_o1 = PORTAbits.RA9; /* Read pin A9 */

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  rtb_LogicalOperator = (PORTAbits.RA10 || (deney_3_DW.Memory_PreviousInput >= 100.0));

  /* CombinatorialLogic: '<S3>/Logic' incorporates:
   *  Memory: '<S3>/Memory'
   */
  rtb_DigitalInput_o1 = deney_3_ConstP.Logic_table[((((uint16_T)rtb_DigitalInput_o1 << 1) +
    rtb_LogicalOperator) << 1) + deney_3_DW.bitsForTID0.Memory_PreviousInput_p];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (rtb_LogicalOperator) {
    rtb_Switch1 = 0.0;
  } else {
    rtb_Switch1 = deney_3_DW.UnitDelay_DSTATE;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (rtb_DigitalInput_o1) {
    deney_3_DW.UnitDelay_DSTATE = rtb_Switch1 + 0.01;
  } else {
    deney_3_DW.UnitDelay_DSTATE = rtb_Switch1;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Gain: '<Root>/Gain'
   *  MultiPortSwitch: '<Root>/Index Vector1'
   *  Rounding: '<Root>/Fix'
   */
  tmp = floor(deney_3_ConstP.Constant2_Value[(int16_T)trunc(0.1 * rtb_Switch1)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Math: '<Root>/Mod'
   *  MultiPortSwitch: '<Root>/Index Vector'
   */
  tmp = floor(deney_3_ConstP.Constant2_Value[(int16_T)rt_modd_snf(rtb_Switch1, 10.0)]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp : (uint16_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (MCHP_Digital_Output_Write): '<S1>/Digital Output Write' */
  LATC = rtb_DataTypeConversion1;      /* No mask required : all pins defined as digital output are updated */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' */
  LATB = rtb_DataTypeConversion;       /* No mask required : all pins defined as digital output are updated */

  /* Update for Memory: '<Root>/Memory' */
  deney_3_DW.Memory_PreviousInput = rtb_Switch1;

  /* Update for Memory: '<S3>/Memory' */
  deney_3_DW.bitsForTID0.Memory_PreviousInput_p = rtb_DigitalInput_o1;
}

/* Model initialize function */
void deney_3_initialize(void)
{
  /* Start for S-Function (MCHP_Master): '<Root>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */
}

/* Model terminate function */
void deney_3_terminate(void)
{
  /* (no terminate code required) */
}

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    extern volatile uint_T ContinueTimeStep __attribute__ ((near)) ;
    __asm__ volatile ( "BSET.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) ) ;/* Atomic bit-set: ContinueTimeStep |= 1U */
    _T1IF = 0;                         /* Re-enable interrupt */
  }
}

/* Single rate scheduler function */
void MCHP_Scheduler(void)
{
  for (;;) {                           /* Infinite loop, no return */
    while (!ContinueTimeStep) ;

    /* Disable Scheduler Interrupt */
    _IPL0 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 0 to 1 */
    __asm__ volatile ("BCLR.b %[MyVar], #0" : [MyVar] "+m" (ContinueTimeStep) );/* Atomic bit-clear of ContinueTimeStep bit 1U */

    /* Call model Scheduler */
    /* Step the model for base rate */
    deney_3_step();

    /* Get model outputs here */

    /* Re-Enable Scheduler Interrupt */
    _IPL0 = 0;                         /* Enable Scheduler interrupt. Lower IPL from 1 to 0 */
  }                                    /* end infinite loop for(;;) */
}                                      /* End MCHP_Scheduler function */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
