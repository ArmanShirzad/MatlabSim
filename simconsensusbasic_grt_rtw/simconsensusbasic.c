/*
 * simconsensusbasic.c
 *
 * Code generation for model "simconsensusbasic".
 *
 * Model version              : 1.513
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sat Dec 14 13:24:19 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "simconsensusbasic.h"
#include "simconsensusbasic_private.h"

/* Block signals (auto storage) */
B_simconsensusbasic_T simconsensusbasic_B;

/* Continuous states */
X_simconsensusbasic_T simconsensusbasic_X;

/* Block states (auto storage) */
DW_simconsensusbasic_T simconsensusbasic_DW;

/* Real-time model */
RT_MODEL_simconsensusbasic_T simconsensusbasic_M_;
RT_MODEL_simconsensusbasic_T *const simconsensusbasic_M = &simconsensusbasic_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  simconsensusbasic_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  simconsensusbasic_output();
  simconsensusbasic_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  simconsensusbasic_output();
  simconsensusbasic_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void simconsensusbasic_output(void)
{
  real_T rtb_TmpSignalConversionAtGain13[10];
  int32_T i;
  real_T tmp[5];
  int32_T i_0;
  if (rtmIsMajorTimeStep(simconsensusbasic_M)) {
    /* set solver stop time */
    if (!(simconsensusbasic_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&simconsensusbasic_M->solverInfo,
                            ((simconsensusbasic_M->Timing.clockTickH0 + 1) *
        simconsensusbasic_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&simconsensusbasic_M->solverInfo,
                            ((simconsensusbasic_M->Timing.clockTick0 + 1) *
        simconsensusbasic_M->Timing.stepSize0 +
        simconsensusbasic_M->Timing.clockTickH0 *
        simconsensusbasic_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(simconsensusbasic_M)) {
    simconsensusbasic_M->Timing.t[0] = rtsiGetT(&simconsensusbasic_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator' */
  simconsensusbasic_B.Integrator[0] = simconsensusbasic_X.Integrator_CSTATE[0];
  simconsensusbasic_B.Integrator[1] = simconsensusbasic_X.Integrator_CSTATE[1];

  /* Integrator: '<S2>/Integrator' */
  simconsensusbasic_B.Integrator_o[0] = simconsensusbasic_X.Integrator_CSTATE_h
    [0];
  simconsensusbasic_B.Integrator_o[1] = simconsensusbasic_X.Integrator_CSTATE_h
    [1];

  /* Integrator: '<S3>/Integrator' */
  simconsensusbasic_B.Integrator_h[0] = simconsensusbasic_X.Integrator_CSTATE_g
    [0];
  simconsensusbasic_B.Integrator_h[1] = simconsensusbasic_X.Integrator_CSTATE_g
    [1];

  /* Integrator: '<S4>/Integrator' */
  simconsensusbasic_B.Integrator_h1[0] =
    simconsensusbasic_X.Integrator_CSTATE_p[0];
  simconsensusbasic_B.Integrator_h1[1] =
    simconsensusbasic_X.Integrator_CSTATE_p[1];

  /* Integrator: '<S5>/Integrator' */
  simconsensusbasic_B.Integrator_d[0] = simconsensusbasic_X.Integrator_CSTATE_o
    [0];
  simconsensusbasic_B.Integrator_d[1] = simconsensusbasic_X.Integrator_CSTATE_o
    [1];

  /* SignalConversion: '<Root>/TmpSignal ConversionAtGain13Inport1' */
  rtb_TmpSignalConversionAtGain13[0] = simconsensusbasic_B.Integrator[0];
  rtb_TmpSignalConversionAtGain13[1] = simconsensusbasic_B.Integrator[1];
  rtb_TmpSignalConversionAtGain13[2] = simconsensusbasic_B.Integrator_o[0];
  rtb_TmpSignalConversionAtGain13[3] = simconsensusbasic_B.Integrator_o[1];
  rtb_TmpSignalConversionAtGain13[4] = simconsensusbasic_B.Integrator_h[0];
  rtb_TmpSignalConversionAtGain13[5] = simconsensusbasic_B.Integrator_h[1];
  rtb_TmpSignalConversionAtGain13[6] = simconsensusbasic_B.Integrator_h1[0];
  rtb_TmpSignalConversionAtGain13[7] = simconsensusbasic_B.Integrator_h1[1];
  rtb_TmpSignalConversionAtGain13[8] = simconsensusbasic_B.Integrator_d[0];
  rtb_TmpSignalConversionAtGain13[9] = simconsensusbasic_B.Integrator_d[1];

  /* Gain: '<Root>/Gain5' */
  for (i = 0; i < 5; i++) {
    simconsensusbasic_B.Gain5[i] = 0.0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      simconsensusbasic_B.Gain5[i] += simconsensusbasic_P.Gain5_Gain[5 * i_0 + i]
        * rtb_TmpSignalConversionAtGain13[i_0];
    }
  }

  /* End of Gain: '<Root>/Gain5' */
  if (rtmIsMajorTimeStep(simconsensusbasic_M)) {
  }

  /* Gain: '<Root>/Gain8' */
  for (i = 0; i < 10; i++) {
    simconsensusbasic_B.Gain8[i] = 0.0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      simconsensusbasic_B.Gain8[i] += simconsensusbasic_P.Gain8_Gain[10 * i_0 +
        i] * rtb_TmpSignalConversionAtGain13[i_0];
    }
  }

  /* End of Gain: '<Root>/Gain8' */
  if (rtmIsMajorTimeStep(simconsensusbasic_M)) {
  }

  /* Gain: '<Root>/Gain13' */
  for (i = 0; i < 5; i++) {
    simconsensusbasic_B.Gain13[i] = 0.0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      simconsensusbasic_B.Gain13[i] += simconsensusbasic_P.Gain13_Gain[5 * i_0 +
        i] * rtb_TmpSignalConversionAtGain13[i_0];
    }
  }

  /* End of Gain: '<Root>/Gain13' */
  if (rtmIsMajorTimeStep(simconsensusbasic_M)) {
  }

  for (i = 0; i < 5; i++) {
    /* Gain: '<Root>/K' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      tmp[i] += simconsensusbasic_P.K_Gain[5 * i_0 + i] *
        simconsensusbasic_B.Gain8[i_0];
    }

    /* End of Gain: '<Root>/K' */

    /* Gain: '<Root>/Gain1' */
    simconsensusbasic_B.Gain1[i] = simconsensusbasic_P.c * tmp[i];
  }

  if (rtmIsMajorTimeStep(simconsensusbasic_M)) {
    /* ToWorkspace: '<Root>/To Workspace' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (simconsensusbasic_DW.ToWorkspace_PWORK.LoggedData),
                    &simconsensusbasic_B.Gain5[0], 0);

    /* ToWorkspace: '<Root>/To Workspace1' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (simconsensusbasic_DW.ToWorkspace1_PWORK.LoggedData),
                    &simconsensusbasic_B.Gain13[0], 0);

    /* ToWorkspace: '<Root>/To Workspace4' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (simconsensusbasic_DW.ToWorkspace4_PWORK.LoggedData),
                    &simconsensusbasic_B.Gain8[0], 0);
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/K2'
   *  Gain: '<S1>/alpha1'
   */
  simconsensusbasic_B.Sum1[0] = (simconsensusbasic_P.A[0] *
    simconsensusbasic_B.Integrator[0] + simconsensusbasic_P.A[2] *
    simconsensusbasic_B.Integrator[1]) + simconsensusbasic_P.B[0] *
    simconsensusbasic_B.Gain1[0];
  simconsensusbasic_B.Sum1[1] = (simconsensusbasic_P.A[1] *
    simconsensusbasic_B.Integrator[0] + simconsensusbasic_P.A[3] *
    simconsensusbasic_B.Integrator[1]) + simconsensusbasic_P.B[1] *
    simconsensusbasic_B.Gain1[0];

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/K2'
   *  Gain: '<S2>/alpha1'
   */
  simconsensusbasic_B.Sum1_a[0] = (simconsensusbasic_P.A[0] *
    simconsensusbasic_B.Integrator_o[0] + simconsensusbasic_P.A[2] *
    simconsensusbasic_B.Integrator_o[1]) + simconsensusbasic_P.B[0] *
    simconsensusbasic_B.Gain1[1];
  simconsensusbasic_B.Sum1_a[1] = (simconsensusbasic_P.A[1] *
    simconsensusbasic_B.Integrator_o[0] + simconsensusbasic_P.A[3] *
    simconsensusbasic_B.Integrator_o[1]) + simconsensusbasic_P.B[1] *
    simconsensusbasic_B.Gain1[1];

  /* Sum: '<S3>/Sum1' incorporates:
   *  Gain: '<S3>/K2'
   *  Gain: '<S3>/alpha1'
   */
  simconsensusbasic_B.Sum1_p[0] = (simconsensusbasic_P.B[0] *
    simconsensusbasic_B.Gain1[2] + 0.0) + (simconsensusbasic_P.A[0] *
    simconsensusbasic_B.Integrator_h[0] + simconsensusbasic_P.A[2] *
    simconsensusbasic_B.Integrator_h[1]);
  simconsensusbasic_B.Sum1_p[1] = (simconsensusbasic_P.B[1] *
    simconsensusbasic_B.Gain1[2] + 0.0) + (simconsensusbasic_P.A[1] *
    simconsensusbasic_B.Integrator_h[0] + simconsensusbasic_P.A[3] *
    simconsensusbasic_B.Integrator_h[1]);

  /* Sum: '<S4>/Sum1' incorporates:
   *  Gain: '<S4>/K2'
   *  Gain: '<S4>/alpha1'
   */
  simconsensusbasic_B.Sum1_f[0] = (simconsensusbasic_P.B[0] *
    simconsensusbasic_B.Gain1[3] + 0.0) + (simconsensusbasic_P.A[0] *
    simconsensusbasic_B.Integrator_h1[0] + simconsensusbasic_P.A[2] *
    simconsensusbasic_B.Integrator_h1[1]);
  simconsensusbasic_B.Sum1_f[1] = (simconsensusbasic_P.B[1] *
    simconsensusbasic_B.Gain1[3] + 0.0) + (simconsensusbasic_P.A[1] *
    simconsensusbasic_B.Integrator_h1[0] + simconsensusbasic_P.A[3] *
    simconsensusbasic_B.Integrator_h1[1]);

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/K2'
   *  Gain: '<S5>/alpha1'
   */
  simconsensusbasic_B.Sum1_i[0] = (simconsensusbasic_P.B[0] *
    simconsensusbasic_B.Gain1[4] + 0.0) + (simconsensusbasic_P.A[0] *
    simconsensusbasic_B.Integrator_d[0] + simconsensusbasic_P.A[2] *
    simconsensusbasic_B.Integrator_d[1]);
  simconsensusbasic_B.Sum1_i[1] = (simconsensusbasic_P.B[1] *
    simconsensusbasic_B.Gain1[4] + 0.0) + (simconsensusbasic_P.A[1] *
    simconsensusbasic_B.Integrator_d[0] + simconsensusbasic_P.A[3] *
    simconsensusbasic_B.Integrator_d[1]);

  /* Clock: '<Root>/Clock' */
  simconsensusbasic_B.Clock = simconsensusbasic_M->Timing.t[0];
  if (rtmIsMajorTimeStep(simconsensusbasic_M)) {
    /* ToWorkspace: '<Root>/To Workspace3' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (simconsensusbasic_DW.ToWorkspace3_PWORK.LoggedData),
                    &simconsensusbasic_B.Clock, 0);
  }
}

/* Model update function */
void simconsensusbasic_update(void)
{
  if (rtmIsMajorTimeStep(simconsensusbasic_M)) {
    rt_ertODEUpdateContinuousStates(&simconsensusbasic_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++simconsensusbasic_M->Timing.clockTick0)) {
    ++simconsensusbasic_M->Timing.clockTickH0;
  }

  simconsensusbasic_M->Timing.t[0] = rtsiGetSolverStopTime
    (&simconsensusbasic_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++simconsensusbasic_M->Timing.clockTick1)) {
      ++simconsensusbasic_M->Timing.clockTickH1;
    }

    simconsensusbasic_M->Timing.t[1] = simconsensusbasic_M->Timing.clockTick1 *
      simconsensusbasic_M->Timing.stepSize1 +
      simconsensusbasic_M->Timing.clockTickH1 *
      simconsensusbasic_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void simconsensusbasic_derivatives(void)
{
  XDot_simconsensusbasic_T *_rtXdot;
  _rtXdot = ((XDot_simconsensusbasic_T *) simconsensusbasic_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = simconsensusbasic_B.Sum1[0];
  _rtXdot->Integrator_CSTATE[1] = simconsensusbasic_B.Sum1[1];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_h[0] = simconsensusbasic_B.Sum1_a[0];
  _rtXdot->Integrator_CSTATE_h[1] = simconsensusbasic_B.Sum1_a[1];

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE_g[0] = simconsensusbasic_B.Sum1_p[0];
  _rtXdot->Integrator_CSTATE_g[1] = simconsensusbasic_B.Sum1_p[1];

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_p[0] = simconsensusbasic_B.Sum1_f[0];
  _rtXdot->Integrator_CSTATE_p[1] = simconsensusbasic_B.Sum1_f[1];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_o[0] = simconsensusbasic_B.Sum1_i[0];
  _rtXdot->Integrator_CSTATE_o[1] = simconsensusbasic_B.Sum1_i[1];
}

/* Model initialize function */
void simconsensusbasic_initialize(void)
{
  /* Start for ToWorkspace: '<Root>/To Workspace' */
  {
    int_T dimensions[1] = { 5 };

    simconsensusbasic_DW.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
      simconsensusbasic_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(simconsensusbasic_M),
      simconsensusbasic_M->Timing.stepSize0,
      (&rtmGetErrorStatus(simconsensusbasic_M)),
      "x1",
      SS_DOUBLE,
      0,
      0,
      0,
      5,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (simconsensusbasic_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace1' */
  {
    int_T dimensions[1] = { 5 };

    simconsensusbasic_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
      simconsensusbasic_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(simconsensusbasic_M),
      simconsensusbasic_M->Timing.stepSize0,
      (&rtmGetErrorStatus(simconsensusbasic_M)),
      "x2",
      SS_DOUBLE,
      0,
      0,
      0,
      5,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (simconsensusbasic_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace4' */
  {
    int_T dimensions[1] = { 10 };

    simconsensusbasic_DW.ToWorkspace4_PWORK.LoggedData = rt_CreateLogVar(
      simconsensusbasic_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(simconsensusbasic_M),
      simconsensusbasic_M->Timing.stepSize0,
      (&rtmGetErrorStatus(simconsensusbasic_M)),
      "e",
      SS_DOUBLE,
      0,
      0,
      0,
      10,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (simconsensusbasic_DW.ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace3' */
  {
    int_T dimensions[1] = { 1 };

    simconsensusbasic_DW.ToWorkspace3_PWORK.LoggedData = rt_CreateLogVar(
      simconsensusbasic_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(simconsensusbasic_M),
      simconsensusbasic_M->Timing.stepSize0,
      (&rtmGetErrorStatus(simconsensusbasic_M)),
      "t",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (simconsensusbasic_DW.ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  simconsensusbasic_X.Integrator_CSTATE[0] = simconsensusbasic_P.x10[0];
  simconsensusbasic_X.Integrator_CSTATE[1] = simconsensusbasic_P.x10[1];

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  simconsensusbasic_X.Integrator_CSTATE_h[0] = simconsensusbasic_P.x20[0];
  simconsensusbasic_X.Integrator_CSTATE_h[1] = simconsensusbasic_P.x20[1];

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  simconsensusbasic_X.Integrator_CSTATE_g[0] = simconsensusbasic_P.x30[0];
  simconsensusbasic_X.Integrator_CSTATE_g[1] = simconsensusbasic_P.x30[1];

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  simconsensusbasic_X.Integrator_CSTATE_p[0] = simconsensusbasic_P.x40[0];
  simconsensusbasic_X.Integrator_CSTATE_p[1] = simconsensusbasic_P.x40[1];

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  simconsensusbasic_X.Integrator_CSTATE_o[0] = simconsensusbasic_P.x50[0];
  simconsensusbasic_X.Integrator_CSTATE_o[1] = simconsensusbasic_P.x50[1];
}

/* Model terminate function */
void simconsensusbasic_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  simconsensusbasic_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  simconsensusbasic_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  simconsensusbasic_initialize();
}

void MdlTerminate(void)
{
  simconsensusbasic_terminate();
}

/* Registration function */
RT_MODEL_simconsensusbasic_T *simconsensusbasic(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)simconsensusbasic_M, 0,
                sizeof(RT_MODEL_simconsensusbasic_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&simconsensusbasic_M->solverInfo,
                          &simconsensusbasic_M->Timing.simTimeStep);
    rtsiSetTPtr(&simconsensusbasic_M->solverInfo, &rtmGetTPtr
                (simconsensusbasic_M));
    rtsiSetStepSizePtr(&simconsensusbasic_M->solverInfo,
                       &simconsensusbasic_M->Timing.stepSize0);
    rtsiSetdXPtr(&simconsensusbasic_M->solverInfo,
                 &simconsensusbasic_M->ModelData.derivs);
    rtsiSetContStatesPtr(&simconsensusbasic_M->solverInfo, (real_T **)
                         &simconsensusbasic_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&simconsensusbasic_M->solverInfo,
      &simconsensusbasic_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&simconsensusbasic_M->solverInfo, (&rtmGetErrorStatus
      (simconsensusbasic_M)));
    rtsiSetRTModelPtr(&simconsensusbasic_M->solverInfo, simconsensusbasic_M);
  }

  rtsiSetSimTimeStep(&simconsensusbasic_M->solverInfo, MAJOR_TIME_STEP);
  simconsensusbasic_M->ModelData.intgData.y =
    simconsensusbasic_M->ModelData.odeY;
  simconsensusbasic_M->ModelData.intgData.f[0] =
    simconsensusbasic_M->ModelData.odeF[0];
  simconsensusbasic_M->ModelData.intgData.f[1] =
    simconsensusbasic_M->ModelData.odeF[1];
  simconsensusbasic_M->ModelData.intgData.f[2] =
    simconsensusbasic_M->ModelData.odeF[2];
  simconsensusbasic_M->ModelData.contStates = ((real_T *) &simconsensusbasic_X);
  rtsiSetSolverData(&simconsensusbasic_M->solverInfo, (void *)
                    &simconsensusbasic_M->ModelData.intgData);
  rtsiSetSolverName(&simconsensusbasic_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = simconsensusbasic_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    simconsensusbasic_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    simconsensusbasic_M->Timing.sampleTimes =
      (&simconsensusbasic_M->Timing.sampleTimesArray[0]);
    simconsensusbasic_M->Timing.offsetTimes =
      (&simconsensusbasic_M->Timing.offsetTimesArray[0]);

    /* task periods */
    simconsensusbasic_M->Timing.sampleTimes[0] = (0.0);
    simconsensusbasic_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    simconsensusbasic_M->Timing.offsetTimes[0] = (0.0);
    simconsensusbasic_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(simconsensusbasic_M, &simconsensusbasic_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = simconsensusbasic_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    simconsensusbasic_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(simconsensusbasic_M, 3.0);
  simconsensusbasic_M->Timing.stepSize0 = 0.001;
  simconsensusbasic_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    simconsensusbasic_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(simconsensusbasic_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(simconsensusbasic_M->rtwLogInfo, (NULL));
    rtliSetLogT(simconsensusbasic_M->rtwLogInfo, "tout");
    rtliSetLogX(simconsensusbasic_M->rtwLogInfo, "");
    rtliSetLogXFinal(simconsensusbasic_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(simconsensusbasic_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(simconsensusbasic_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(simconsensusbasic_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(simconsensusbasic_M->rtwLogInfo, 1);
    rtliSetLogY(simconsensusbasic_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(simconsensusbasic_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(simconsensusbasic_M->rtwLogInfo, (NULL));
  }

  simconsensusbasic_M->solverInfoPtr = (&simconsensusbasic_M->solverInfo);
  simconsensusbasic_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&simconsensusbasic_M->solverInfo, 0.001);
  rtsiSetSolverMode(&simconsensusbasic_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  simconsensusbasic_M->ModelData.blockIO = ((void *) &simconsensusbasic_B);
  (void) memset(((void *) &simconsensusbasic_B), 0,
                sizeof(B_simconsensusbasic_T));

  /* parameters */
  simconsensusbasic_M->ModelData.defaultParam = ((real_T *)&simconsensusbasic_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &simconsensusbasic_X;
    simconsensusbasic_M->ModelData.contStates = (x);
    (void) memset((void *)&simconsensusbasic_X, 0,
                  sizeof(X_simconsensusbasic_T));
  }

  /* states (dwork) */
  simconsensusbasic_M->ModelData.dwork = ((void *) &simconsensusbasic_DW);
  (void) memset((void *)&simconsensusbasic_DW, 0,
                sizeof(DW_simconsensusbasic_T));

  /* Initialize Sizes */
  simconsensusbasic_M->Sizes.numContStates = (10);/* Number of continuous states */
  simconsensusbasic_M->Sizes.numY = (0);/* Number of model outputs */
  simconsensusbasic_M->Sizes.numU = (0);/* Number of model inputs */
  simconsensusbasic_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  simconsensusbasic_M->Sizes.numSampTimes = (2);/* Number of sample times */
  simconsensusbasic_M->Sizes.numBlocks = (36);/* Number of blocks */
  simconsensusbasic_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  simconsensusbasic_M->Sizes.numBlockPrms = (267);/* Sum of parameter "widths" */
  return simconsensusbasic_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
