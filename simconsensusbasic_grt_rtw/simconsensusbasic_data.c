/*
 * simconsensusbasic_data.c
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

/* Block parameters (auto storage) */
P_simconsensusbasic_T simconsensusbasic_P = {
  /*  Variable: A
   * Referenced by:
   *   '<S1>/K2'
   *   '<S2>/K2'
   *   '<S3>/K2'
   *   '<S4>/K2'
   *   '<S5>/K2'
   */
  { 1.0, 1.0, 0.0, 2.0 },

  /*  Variable: B
   * Referenced by:
   *   '<S1>/alpha1'
   *   '<S2>/alpha1'
   *   '<S3>/alpha1'
   *   '<S4>/alpha1'
   *   '<S5>/alpha1'
   */
  { 1.0, 1.0 },
  0.72358900144717808,                 /* Variable: c
                                        * Referenced by: '<Root>/Gain1'
                                        */

  /*  Variable: x10
   * Referenced by: '<S1>/Integrator'
   */
  { 0.5, -0.5 },

  /*  Variable: x20
   * Referenced by: '<S2>/Integrator'
   */
  { -0.3, 0.0 },

  /*  Variable: x30
   * Referenced by: '<S3>/Integrator'
   */
  { -0.3, 0.2 },

  /*  Variable: x40
   * Referenced by: '<S4>/Integrator'
   */
  { 0.0, 0.1 },

  /*  Variable: x50
   * Referenced by: '<S5>/Integrator'
   */
  { 0.3, 0.0 },

  /*  Expression: kron(eye(N),[1 0])
   * Referenced by: '<Root>/Gain5'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: kron(L,eye(n))
   * Referenced by: '<Root>/Gain8'
   */
  { 3.0, 0.0, -1.0, -0.0, -1.0, -0.0, 0.0, 0.0, -1.0, -0.0, 0.0, 3.0, -0.0, -1.0,
    -0.0, -1.0, 0.0, 0.0, -0.0, -1.0, -1.0, -0.0, 2.0, 0.0, -1.0, -0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -1.0, 0.0, 2.0, -0.0, -1.0, 0.0, 0.0, 0.0, 0.0, -1.0, -0.0,
    -1.0, -0.0, 3.0, 0.0, -1.0, -0.0, 0.0, 0.0, -0.0, -1.0, -0.0, -1.0, 0.0, 3.0,
    -0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -0.0, 2.0, 0.0, -1.0, -0.0,
    0.0, 0.0, 0.0, 0.0, -0.0, -1.0, 0.0, 2.0, -0.0, -1.0, -1.0, -0.0, 0.0, 0.0,
    0.0, 0.0, -1.0, -0.0, 2.0, 0.0, -0.0, -1.0, 0.0, 0.0, 0.0, 0.0, -0.0, -1.0,
    0.0, 2.0 },

  /*  Expression: kron(eye(N),[0 1])
   * Referenced by: '<Root>/Gain13'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: kron(eye(N),K)
   * Referenced by: '<Root>/K'
   */
  { 58.99999999999882, 0.0, 0.0, 0.0, 0.0, -83.999999999998607, -0.0, -0.0, -0.0,
    -0.0, 0.0, 58.99999999999882, 0.0, 0.0, 0.0, -0.0, -83.999999999998607, -0.0,
    -0.0, -0.0, 0.0, 0.0, 58.99999999999882, 0.0, 0.0, -0.0, -0.0,
    -83.999999999998607, -0.0, -0.0, 0.0, 0.0, 0.0, 58.99999999999882, 0.0, -0.0,
    -0.0, -0.0, -83.999999999998607, -0.0, 0.0, 0.0, 0.0, 0.0, 58.99999999999882,
    -0.0, -0.0, -0.0, -0.0, -83.999999999998607 }
};
