/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.57b (06-Aug-2024)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://forum.microchip.com/s/sub-forums?&subForumId=a553l000000J2rNAAS&forumId=a553l000000J2pvAAC&subForumName=MATLAB
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: deney_3.h
 *
 * Code generated for Simulink model 'deney_3'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Mar 11 22:31:06 2025
 */

#ifndef deney_3_h_
#define deney_3_h_
#ifndef deney_3_COMMON_INCLUDES_
#define deney_3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* deney_3_COMMON_INCLUDES_ */

#define FCY                            (40000000UL)              /* Instruction Frequency FCY set at  40.0 MHz */

/* Include for pic 33F */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "deney_3_types.h"
#include "rtGetNaN.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  struct {
    uint_T Memory_PreviousInput_p:1;   /* '<S3>/Memory' */
  } bitsForTID0;
} DW_deney_3_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [63, 6, 91, 79, 102, 109, 125, 7, 127, 111].'
   * Referenced by: '<Root>/Constant2'
   */
  real_T Constant2_Value[10];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S3>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP_deney_3_T;

/* Block signals and states (default storage) */
extern DW_deney_3_T deney_3_DW;

/* Constant parameters (default storage) */
extern const ConstP_deney_3_T deney_3_ConstP;

/* Model entry point functions */
extern void deney_3_initialize(void);
extern void deney_3_step(void);
extern void deney_3_terminate(void);

/* Single rate scheduler function */
extern void MCHP_Scheduler(void) __attribute__ ((noreturn));

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'deney_3'
 * '<S1>'   : 'deney_3/Digital Output'
 * '<S2>'   : 'deney_3/Digital Output1'
 * '<S3>'   : 'deney_3/S-R Flip-Flop'
 */
#endif                                 /* deney_3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
