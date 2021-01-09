//
// File: truck_adas.cpp
//
// Code generated for Simulink model 'truck_adas'.
//
// Model version                  : 1.1304
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Sun Dec 27 15:37:01 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objective: RAM efficiency
// Validation result: Not run
//
#include "truck_adas.h"
#include "truck_adas_private.h"

// Named constants for Chart: '<S182>/D3.3.1 VehStatCo_Stat_Stat'
#define truck__IN_VehStatCo_Stat_finish ((uint8_T)1U)
#define truck_a_IN_VehStatCo_Stat_ready ((uint8_T)1U)
#define truck_a_IN_VehStatCo_Stat_start ((uint8_T)3U)
#define truck_ad_IN_VehStatCo_Stat_stop ((uint8_T)2U)
#define truck_ada_IN_VehStatCo_Stat_run ((uint8_T)2U)
#define truck_adas_IN_AFTERRUN         ((uint8_T)1U)
#define truck_adas_IN_DRIVE            ((uint8_T)2U)
#define truck_adas_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define truck_adas_IN_STANDBY          ((uint8_T)3U)

// Named constants for Chart: '<S300>/VehStatCo_Stat_Stat'
#define truck_adas_IN_AEB0x07          ((uint8_T)1U)
#define truck_adas_IN_APA_AEB0x07      ((uint8_T)1U)
#define truck_adas_IN_APA_Brake0x11    ((uint8_T)1U)
#define truck_adas_IN_APA_FCW0x12      ((uint8_T)2U)
#define truck_adas_IN_APA_RP0x08       ((uint8_T)1U)
#define truck_adas_IN_APA_Running0x10  ((uint8_T)2U)
#define truck_adas_IN_APA_Start0x09    ((uint8_T)3U)
#define truck_adas_IN_APA_TF           ((uint8_T)2U)
#define truck_adas_IN_Brake0x05        ((uint8_T)1U)
#define truck_adas_IN_FCW0x06          ((uint8_T)2U)
#define truck_adas_IN_Fianl            ((uint8_T)3U)
#define truck_adas_IN_Fianl1           ((uint8_T)4U)
#define truck_adas_IN_RP0x02           ((uint8_T)5U)
#define truck_adas_IN_Running0x04      ((uint8_T)2U)
#define truck_adas_IN_Standby0x01      ((uint8_T)6U)
#define truck_adas_IN_Start0x03        ((uint8_T)3U)
#define truck_adas_IN_TF               ((uint8_T)7U)

// Named constants for Chart: '<S364>/mode 2'
#define truck_adas_IN_A                ((uint8_T)1U)
#define truck_adas_IN_L1               ((uint8_T)1U)
#define truck_adas_IN_L2               ((uint8_T)2U)
#define truck_adas_IN_Left             ((uint8_T)2U)
#define truck_adas_IN_R1               ((uint8_T)1U)
#define truck_adas_IN_R2               ((uint8_T)2U)
#define truck_adas_IN_Right            ((uint8_T)3U)
#define truck_adas_IN_start            ((uint8_T)4U)

// Block signals (default storage)
B_truck_adas_T truck_adas_B;

// Continuous states
X_truck_adas_T truck_adas_X;

// Block states (default storage)
DW_truck_adas_T truck_adas_DW;

// Real-time model
RT_MODEL_truck_adas_T truck_adas_M_;
RT_MODEL_truck_adas_T *const truck_adas_M = &truck_adas_M_;

// Exported data definition

// Definition for custom storage class: Global
real_T VehStatCo_Stat_DT = 0.0;
real_T Veh_FINISH = 0.0;
real_T Veh_READY = 0.0;
real_T Veh_RUNNING = 0.0;
real_T Veh_STANDBY = 0.0;
real_T Veh_START = 0.0;
real_T Veh_STOPPING = 0.0;
static void rate_scheduler(void);

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (truck_adas_M->Timing.TaskCounters.TID[2])++;
  if ((truck_adas_M->Timing.TaskCounters.TID[2]) > 19) {// Sample time: [1.0s, 0.0s] 
    truck_adas_M->Timing.TaskCounters.TID[2] = 0;
  }
}

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  truck_adas_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  truck_adas_step();
  truck_adas_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  truck_adas_step();
  truck_adas_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// System initialize for enable system:
//    '<S237>/Enabled Subsystem'
//    '<S237>/Enabled Subsystem1'
//    '<S237>/Enabled Subsystem2'
//
void truck_ada_EnabledSubsystem_Init(DW_EnabledSubsystem_truck_ada_T *localDW)
{
  // InitializeConditions for UnitDelay: '<S238>/Unit Delay'
  localDW->UnitDelay_DSTATE = 0.0;
}

//
// System reset for enable system:
//    '<S237>/Enabled Subsystem'
//    '<S237>/Enabled Subsystem1'
//    '<S237>/Enabled Subsystem2'
//
void truck_ad_EnabledSubsystem_Reset(DW_EnabledSubsystem_truck_ada_T *localDW)
{
  // InitializeConditions for UnitDelay: '<S238>/Unit Delay'
  localDW->UnitDelay_DSTATE = 0.0;
}

//
// Disable for enable system:
//    '<S237>/Enabled Subsystem'
//    '<S237>/Enabled Subsystem1'
//    '<S237>/Enabled Subsystem2'
//
void truck__EnabledSubsystem_Disable(DW_EnabledSubsystem_truck_ada_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

//
// Output and update for enable system:
//    '<S237>/Enabled Subsystem'
//    '<S237>/Enabled Subsystem1'
//    '<S237>/Enabled Subsystem2'
//
void truck_adas_EnabledSubsystem(RT_MODEL_truck_adas_T * const truck_adas_M,
  boolean_T rtu_Enable, real_T *rty_Out1, DW_EnabledSubsystem_truck_ada_T
  *localDW)
{
  // Outputs for Enabled SubSystem: '<S237>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S238>/Enable'

  if ((rtmIsMajorTimeStep(truck_adas_M) &&
       truck_adas_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (truck_adas_M)) {
    if (rtu_Enable) {
      if (!localDW->EnabledSubsystem_MODE) {
        truck_ad_EnabledSubsystem_Reset(localDW);
        localDW->EnabledSubsystem_MODE = true;
      }
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        truck__EnabledSubsystem_Disable(localDW);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE && (rtmIsMajorTimeStep(truck_adas_M) &&
       truck_adas_M->Timing.TaskCounters.TID[2] == 0)) {
    // Sum: '<S238>/Add' incorporates:
    //   Constant: '<S238>/Constant'
    //   UnitDelay: '<S238>/Unit Delay'

    *rty_Out1 = 1.0 + localDW->UnitDelay_DSTATE;

    // Update for UnitDelay: '<S238>/Unit Delay'
    localDW->UnitDelay_DSTATE = *rty_Out1;
  }

  // End of Outputs for SubSystem: '<S237>/Enabled Subsystem'
}

// Model step function
void truck_adas_step(void)
{
  // local block i/o variables
  boolean_T rtb_LogicalOperator = false;
  boolean_T rtb_DataTypeConversion;
  real_T rtb_Switch30_e;
  real_T rtb_Switch4_h;
  real_T rtb_Switch32_m;
  real_T rtb_Switch5;
  real_T rtb_Switch34_k;
  real_T rtb_Switch6_c;
  real_T rtb_Switch36_g;
  real_T rtb_Switch7;
  real_T rtb_Switch48;
  real_T rtb_Switch8;
  real_T rtb_Switch10;
  real_T rtb_Switch9;
  real_T rtb_Switch3_d;
  real_T rtb_Switch2_m;
  real_T rtb_Switch1_m;
  real_T rtb_Switch8_n;
  real_T rtb_Sum6;
  real_T rtb_DirectLookupTablenD1;
  real_T rtb_Gain1_d;
  int8_T rtAction;
  real_T rtb_UnitDelay1_n;
  real_T rtb_Merge;
  real_T rtb_Switch;
  real_T rtb_UnitDelay;
  real_T rtb_Fcn9_i;
  real_T rtb_DirectLookupTablenD1_tmp;
  real_T rtb_DirectLookupTablenD1_tmp_0;
  real_T rtb_DirectLookupTablenD1_tmp_1;
  real_T tmp;
  if (rtmIsMajorTimeStep(truck_adas_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&truck_adas_M->solverInfo,
                          ((truck_adas_M->Timing.clockTick0+1)*
      truck_adas_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(truck_adas_M)) {
    truck_adas_M->Timing.t[0] = rtsiGetT(&truck_adas_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // S-Function (IDS_Var_Out): '<S91>/var_out'
    truck_adas_B.var_out= ADAS_HeartBeat;

    // DataTypeConversion: '<S168>/Data Type Conversion'
    rtb_DataTypeConversion = (truck_adas_B.var_out != 0.0);

    // S-Function (IDS_Var_Out): '<S15>/var_out'
    truck_adas_B.var_out_k= Engine_Spd_504_CAN3;

    // Switch: '<S168>/Switch'
    rtb_Switch = (truck_adas_B.var_out_k > 0.0);
  }

  // S-Function (IDS_Var_Out): '<S3>/var_out'
  Navigation_CMD_st_520_CAN3= ADAS_CMD_st_502_CAN3;
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // UnitDelay: '<S163>/Unit Delay'
    rtb_UnitDelay = truck_adas_DW.UnitDelay_DSTATE;

    // UnitDelay: '<S282>/Unit Delay'
    truck_adas_B.VehMot_AccPed_vFltOld_mp = truck_adas_DW.UnitDelay_DSTATE_b;
  }

  // S-Function (IDS_Var_Out): '<S18>/var_out'
  truck_adas_B.var_out_h= g_rte_InputSignals.rmgps.RM_IMU_GPSNUM_TX;
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Fcn: '<S267>/Fcn1' incorporates:
    //   Fcn: '<S267>/Fcn2'
    //   Product: '<S267>/Product1'
    //   Product: '<S267>/Product2'
    //   Sum: '<S267>/Sum11'
    //   Sum: '<S267>/Sum12'
    //   UnitDelay: '<S267>/Unit Delay'
    //   UnitDelay: '<S267>/Unit Delay1'
    //   UnitDelay: '<S267>/Unit Delay2'
    //   UnitDelay: '<S267>/Unit Delay3'
    //   UnitDelay: '<S267>/Unit Delay4'

    truck_adas_B.A = std::atan((truck_adas_DW.UnitDelay_DSTATE_e -
      truck_adas_DW.UnitDelay1_DSTATE) * std::cos
      (truck_adas_DW.UnitDelay2_DSTATE) / (truck_adas_DW.UnitDelay3_DSTATE -
      truck_adas_DW.UnitDelay4_DSTATE));
  }

  // S-Function (IDS_Var_Out): '<S36>/var_out'
  truck_adas_B.var_out_m= g_rte_InputSignals.VisionObj[0].LatPos;

  // Abs: '<S266>/Abs'
  rtb_Switch30_e = std::abs(truck_adas_B.var_out_m);

  // S-Function (IDS_Var_Out): '<S43>/var_out'
  truck_adas_B.var_out_o= g_rte_InputSignals.VisionObj[0].LonPos;

  // Sqrt: '<S266>/Sqrt' incorporates:
  //   Math: '<S266>/Math Function'
  //   Math: '<S266>/Math Function1'
  //   Sum: '<S266>/Sum'
  //
  //  About '<S266>/Math Function':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function1':
  //   Operator: magnitude^2

  rtb_Switch4_h = std::sqrt(rtb_Switch30_e * rtb_Switch30_e +
    truck_adas_B.var_out_o * truck_adas_B.var_out_o);

  // Switch: '<S266>/Switch4' incorporates:
  //   Constant: '<S266>/Constant5'

  if (!(rtb_Switch4_h > 0.0)) {
    rtb_Switch4_h = 200.0;
  }

  // End of Switch: '<S266>/Switch4'

  // S-Function (IDS_Var_Out): '<S107>/var_out'
  truck_adas_B.var_out_ku= g_rte_InputSignals.VisionObj[1].LatPos;

  // Abs: '<S266>/Abs1'
  rtb_Switch32_m = std::abs(truck_adas_B.var_out_ku);

  // S-Function (IDS_Var_Out): '<S108>/var_out'
  truck_adas_B.var_out_f= g_rte_InputSignals.VisionObj[1].LonPos;

  // Sqrt: '<S266>/Sqrt1' incorporates:
  //   Math: '<S266>/Math Function2'
  //   Math: '<S266>/Math Function3'
  //   Sum: '<S266>/Sum1'
  //
  //  About '<S266>/Math Function2':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function3':
  //   Operator: magnitude^2

  rtb_Switch5 = std::sqrt(rtb_Switch32_m * rtb_Switch32_m +
    truck_adas_B.var_out_f * truck_adas_B.var_out_f);

  // Switch: '<S266>/Switch5' incorporates:
  //   Constant: '<S266>/Constant6'

  if (!(rtb_Switch5 > 0.0)) {
    rtb_Switch5 = 200.0;
  }

  // End of Switch: '<S266>/Switch5'

  // S-Function (IDS_Var_Out): '<S110>/var_out'
  truck_adas_B.var_out_g= g_rte_InputSignals.VisionObj[2].LonPos;

  // S-Function (IDS_Var_Out): '<S109>/var_out'
  truck_adas_B.var_out_d= g_rte_InputSignals.VisionObj[2].LatPos;

  // Abs: '<S266>/Abs2'
  rtb_Switch34_k = std::abs(truck_adas_B.var_out_d);

  // Sqrt: '<S266>/Sqrt2' incorporates:
  //   Math: '<S266>/Math Function4'
  //   Math: '<S266>/Math Function5'
  //   Sum: '<S266>/Sum2'
  //
  //  About '<S266>/Math Function4':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function5':
  //   Operator: magnitude^2

  rtb_Switch6_c = std::sqrt(truck_adas_B.var_out_g * truck_adas_B.var_out_g +
    rtb_Switch34_k * rtb_Switch34_k);

  // Switch: '<S266>/Switch6' incorporates:
  //   Constant: '<S266>/Constant7'

  if (!(rtb_Switch6_c > 0.0)) {
    rtb_Switch6_c = 200.0;
  }

  // End of Switch: '<S266>/Switch6'

  // S-Function (IDS_Var_Out): '<S111>/var_out'
  truck_adas_B.var_out_a= g_rte_InputSignals.VisionObj[3].LatPos;

  // Abs: '<S266>/Abs3'
  rtb_Switch36_g = std::abs(truck_adas_B.var_out_a);

  // S-Function (IDS_Var_Out): '<S112>/var_out'
  truck_adas_B.var_out_op= g_rte_InputSignals.VisionObj[3].LonPos;

  // Sqrt: '<S266>/Sqrt3' incorporates:
  //   Math: '<S266>/Math Function6'
  //   Math: '<S266>/Math Function7'
  //   Sum: '<S266>/Sum3'
  //
  //  About '<S266>/Math Function6':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function7':
  //   Operator: magnitude^2

  rtb_Switch7 = std::sqrt(rtb_Switch36_g * rtb_Switch36_g +
    truck_adas_B.var_out_op * truck_adas_B.var_out_op);

  // Switch: '<S266>/Switch7' incorporates:
  //   Constant: '<S266>/Constant8'

  if (!(rtb_Switch7 > 0.0)) {
    rtb_Switch7 = 200.0;
  }

  // End of Switch: '<S266>/Switch7'

  // S-Function (IDS_Var_Out): '<S113>/var_out'
  truck_adas_B.var_out_my= g_rte_InputSignals.VisionObj[4].LatPos;

  // Abs: '<S266>/Abs4'
  rtb_Switch48 = std::abs(truck_adas_B.var_out_my);

  // S-Function (IDS_Var_Out): '<S114>/var_out'
  truck_adas_B.var_out_p= g_rte_InputSignals.VisionObj[4].LonPos;

  // Sqrt: '<S266>/Sqrt4' incorporates:
  //   Math: '<S266>/Math Function8'
  //   Math: '<S266>/Math Function9'
  //   Sum: '<S266>/Sum4'
  //
  //  About '<S266>/Math Function8':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function9':
  //   Operator: magnitude^2

  rtb_Switch8 = std::sqrt(rtb_Switch48 * rtb_Switch48 + truck_adas_B.var_out_p *
    truck_adas_B.var_out_p);

  // Switch: '<S266>/Switch8' incorporates:
  //   Constant: '<S266>/Constant9'

  if (!(rtb_Switch8 > 0.0)) {
    rtb_Switch8 = 200.0;
  }

  // End of Switch: '<S266>/Switch8'

  // S-Function (IDS_Var_Out): '<S116>/var_out'
  truck_adas_B.var_out_hp= g_rte_InputSignals.VisionObj[5].LatPos;

  // Abs: '<S266>/Abs5'
  rtb_Switch10 = std::abs(truck_adas_B.var_out_hp);

  // S-Function (IDS_Var_Out): '<S117>/var_out'
  truck_adas_B.var_out_dc= g_rte_InputSignals.VisionObj[5].LonPos;

  // Sqrt: '<S266>/Sqrt5' incorporates:
  //   Math: '<S266>/Math Function10'
  //   Math: '<S266>/Math Function11'
  //   Sum: '<S266>/Sum5'
  //
  //  About '<S266>/Math Function10':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function11':
  //   Operator: magnitude^2

  rtb_Switch9 = std::sqrt(rtb_Switch10 * rtb_Switch10 + truck_adas_B.var_out_dc *
    truck_adas_B.var_out_dc);

  // Switch: '<S266>/Switch1' incorporates:
  //   Constant: '<S266>/Constant1'

  if (!(rtb_Switch9 > 0.0)) {
    rtb_Switch9 = 200.0;
  }

  // End of Switch: '<S266>/Switch1'

  // S-Function (IDS_Var_Out): '<S118>/var_out'
  truck_adas_B.var_out_gc= g_rte_InputSignals.VisionObj[6].LatPos;

  // Abs: '<S266>/Abs6'
  rtb_Switch3_d = std::abs(truck_adas_B.var_out_gc);

  // S-Function (IDS_Var_Out): '<S119>/var_out'
  truck_adas_B.var_out_kc= g_rte_InputSignals.VisionObj[6].LonPos;

  // Sqrt: '<S266>/Sqrt6' incorporates:
  //   Math: '<S266>/Math Function12'
  //   Math: '<S266>/Math Function13'
  //   Sum: '<S266>/Sum6'
  //
  //  About '<S266>/Math Function12':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function13':
  //   Operator: magnitude^2

  rtb_Switch2_m = std::sqrt(rtb_Switch3_d * rtb_Switch3_d +
    truck_adas_B.var_out_kc * truck_adas_B.var_out_kc);

  // Switch: '<S266>/Switch2' incorporates:
  //   Constant: '<S266>/Constant2'

  if (!(rtb_Switch2_m > 0.0)) {
    rtb_Switch2_m = 200.0;
  }

  // End of Switch: '<S266>/Switch2'

  // S-Function (IDS_Var_Out): '<S120>/var_out'
  truck_adas_B.var_out_l= g_rte_InputSignals.VisionObj[7].LatPos;

  // Abs: '<S266>/Abs7'
  rtb_Switch1_m = std::abs(truck_adas_B.var_out_l);

  // S-Function (IDS_Var_Out): '<S121>/var_out'
  truck_adas_B.var_out_e= g_rte_InputSignals.VisionObj[7].LonPos;

  // Sqrt: '<S266>/Sqrt7' incorporates:
  //   Math: '<S266>/Math Function14'
  //   Math: '<S266>/Math Function15'
  //   Sum: '<S266>/Sum7'
  //
  //  About '<S266>/Math Function14':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function15':
  //   Operator: magnitude^2

  rtb_Switch8_n = std::sqrt(rtb_Switch1_m * rtb_Switch1_m +
    truck_adas_B.var_out_e * truck_adas_B.var_out_e);

  // Switch: '<S266>/Switch3' incorporates:
  //   Constant: '<S266>/Constant3'

  if (!(rtb_Switch8_n > 0.0)) {
    rtb_Switch8_n = 200.0;
  }

  // End of Switch: '<S266>/Switch3'

  // S-Function (IDS_Var_Out): '<S123>/var_out'
  truck_adas_B.var_out_dn= g_rte_InputSignals.VisionObj[8].LonPos;

  // S-Function (IDS_Var_Out): '<S122>/var_out'
  truck_adas_B.var_out_n= g_rte_InputSignals.VisionObj[8].LatPos;

  // Abs: '<S266>/Abs8'
  rtb_Sum6 = std::abs(truck_adas_B.var_out_n);

  // Sqrt: '<S266>/Sqrt8' incorporates:
  //   Math: '<S266>/Math Function16'
  //   Math: '<S266>/Math Function17'
  //   Sum: '<S266>/Sum8'
  //
  //  About '<S266>/Math Function16':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function17':
  //   Operator: magnitude^2

  rtb_DirectLookupTablenD1 = std::sqrt(truck_adas_B.var_out_dn *
    truck_adas_B.var_out_dn + rtb_Sum6 * rtb_Sum6);

  // Switch: '<S266>/Switch9' incorporates:
  //   Constant: '<S266>/Constant4'

  if (!(rtb_DirectLookupTablenD1 > 0.0)) {
    rtb_DirectLookupTablenD1 = 200.0;
  }

  // End of Switch: '<S266>/Switch9'

  // S-Function (IDS_Var_Out): '<S124>/var_out'
  truck_adas_B.var_out_kz= g_rte_InputSignals.VisionObj[9].LatPos;

  // Abs: '<S266>/Abs9'
  rtb_Gain1_d = std::abs(truck_adas_B.var_out_kz);

  // S-Function (IDS_Var_Out): '<S125>/var_out'
  truck_adas_B.var_out_l3= g_rte_InputSignals.VisionObj[9].LonPos;

  // Sqrt: '<S266>/Sqrt9' incorporates:
  //   Math: '<S266>/Math Function18'
  //   Math: '<S266>/Math Function19'
  //   Sum: '<S266>/Sum9'
  //
  //  About '<S266>/Math Function18':
  //   Operator: magnitude^2
  //
  //  About '<S266>/Math Function19':
  //   Operator: magnitude^2

  rtb_Fcn9_i = std::sqrt(rtb_Gain1_d * rtb_Gain1_d + truck_adas_B.var_out_l3 *
    truck_adas_B.var_out_l3);

  // Switch: '<S266>/Switch10' incorporates:
  //   Constant: '<S266>/Constant10'

  if (!(rtb_Fcn9_i > 0.0)) {
    rtb_Fcn9_i = 200.0;
  }

  // End of Switch: '<S266>/Switch10'

  // MinMax: '<S266>/Min4'
  if (rtb_Switch4_h < rtb_Switch5) {
    rtb_Switch5 = rtb_Switch4_h;
  }

  if (rtb_Switch5 < rtb_Switch6_c) {
    rtb_Switch6_c = rtb_Switch5;
  }

  if (rtb_Switch6_c < rtb_Switch7) {
    rtb_Switch7 = rtb_Switch6_c;
  }

  if (rtb_Switch7 < rtb_Switch8) {
    rtb_Switch8 = rtb_Switch7;
  }

  if (rtb_Switch8 < rtb_Switch9) {
    rtb_Switch9 = rtb_Switch8;
  }

  if (rtb_Switch9 < rtb_Switch2_m) {
    rtb_Switch2_m = rtb_Switch9;
  }

  if (rtb_Switch2_m < rtb_Switch8_n) {
    rtb_Switch8_n = rtb_Switch2_m;
  }

  if (rtb_Switch8_n < rtb_DirectLookupTablenD1) {
    rtb_DirectLookupTablenD1 = rtb_Switch8_n;
  }

  if (rtb_DirectLookupTablenD1 < rtb_Fcn9_i) {
    Obj_distance_vision_534_CAN3 = rtb_DirectLookupTablenD1;
  } else {
    Obj_distance_vision_534_CAN3 = rtb_Fcn9_i;
  }

  // End of MinMax: '<S266>/Min4'

  // Gain: '<S267>/Gain5' incorporates:
  //   Constant: '<S267>/R'
  //   Product: '<S267>/Product5'

  rtb_Fcn9_i = Obj_distance_vision_534_CAN3 / 6.371E+6 * 57.295779513082323;

  // S-Function (IDS_Var_Out): '<S76>/var_out'
  truck_adas_B.var_out_c= g_rte_InputSignals.imu.Latitude_F2;

  // Fcn: '<S267>/Fcn19' incorporates:
  //   Fcn: '<S267>/Fcn22'

  rtb_Switch9 = std::sin(rtb_Fcn9_i);

  // Outputs for Atomic SubSystem: '<S268>/position'
  // Fcn: '<S267>/Fcn18' incorporates:
  //   Constant: '<S267>/Constant18'
  //   Fcn: '<S274>/Fcn16'
  //   Fcn: '<S284>/Fcn18'
  //   Sum: '<S267>/Sum21'

  rtb_Switch6_c = std::sin(90.0 - truck_adas_B.var_out_c);

  // Fcn: '<S267>/Fcn8' incorporates:
  //   Constant: '<S267>/Constant12'
  //   Fcn: '<S274>/Fcn14'
  //   Fcn: '<S284>/Fcn8'
  //   Sum: '<S267>/Sum20'

  rtb_Switch7 = std::cos(90.0 - truck_adas_B.var_out_c);

  // End of Outputs for SubSystem: '<S268>/position'

  // Sum: '<S267>/Sum18' incorporates:
  //   Fcn: '<S267>/Fcn11'
  //   Fcn: '<S267>/Fcn18'
  //   Fcn: '<S267>/Fcn19'
  //   Fcn: '<S267>/Fcn8'
  //   Product: '<S267>/Product11'
  //   Product: '<S267>/Product12'
  //   Product: '<S267>/Product13'

  rtb_DirectLookupTablenD1 = rtb_Switch6_c * rtb_Switch9 * truck_adas_B.A +
    rtb_Switch7 * std::cos(rtb_Fcn9_i);

  // Fcn: '<S267>/Fcn20'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  rtb_DirectLookupTablenD1 = std::acos(rtb_DirectLookupTablenD1);

  // Sum: '<S267>/Sum10' incorporates:
  //   Constant: '<S267>/Constant11'
  //   Fcn: '<S267>/Fcn20'

  truck_adas_B.Sum10 = 90.0 - rtb_DirectLookupTablenD1;

  // S-Function (IDS_Var_Out): '<S77>/var_out'
  truck_adas_B.var_out_kzu= g_rte_InputSignals.imu.Longitude_F2;
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Fcn: '<S267>/Fcn23'
    truck_adas_B.Fcn23 = std::sin(truck_adas_B.A);
  }

  // Product: '<S267>/Product14' incorporates:
  //   Fcn: '<S267>/Fcn20'
  //   Fcn: '<S267>/Fcn21'
  //   Product: '<S267>/Product15'

  rtb_DirectLookupTablenD1 = truck_adas_B.Fcn23 * rtb_Switch9 / std::sin
    (rtb_DirectLookupTablenD1);

  // Fcn: '<S267>/Fcn24'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  // Sum: '<S267>/Sum22' incorporates:
  //   Fcn: '<S267>/Fcn24'

  truck_adas_B.Sum22 = truck_adas_B.var_out_kzu + std::asin
    (rtb_DirectLookupTablenD1);

  // S-Function (IDS_Var_Out): '<S63>/var_out'
  IMU_Heading_531_CAN3= g_rte_InputSignals.imu.Heading_F1;

  // S-Function (IDS_Var_Out): '<S102>/var_out'
  truck_adas_B.var_out_i= g_rte_InputSignals.rmgps.RM_IMU_longitude_TX;

  // S-Function (IDS_Var_Out): '<S101>/var_out'
  truck_adas_B.var_out_gb= g_rte_InputSignals.rmgps.RM_IMU_latitude_TX;

  // Outputs for Atomic SubSystem: '<S285>/position'
  // Outputs for Atomic SubSystem: '<S268>/position'
  // Sum: '<S274>/Sum2' incorporates:
  //   LookupNDDirect: '<S271>/Direct Lookup Table (n-D)1'
  //   Sum: '<S293>/Sum2'
  //
  //  About '<S271>/Direct Lookup Table (n-D)1':
  //   1-dimensional Direct Look-Up returning a Scalar,

  rtb_Switch8 = truck_adas_B.var_out_i - truck_adas_B.var_out_kzu;

  // End of Outputs for SubSystem: '<S285>/position'

  // Fcn: '<S274>/Fcn9' incorporates:
  //   Sum: '<S274>/Sum2'

  rtb_Fcn9_i = std::sin(rtb_Switch8);

  // Outputs for Atomic SubSystem: '<S285>/position'
  // Fcn: '<S274>/Fcn15' incorporates:
  //   Constant: '<S274>/Constant2'
  //   Fcn: '<S274>/Fcn7'
  //   Fcn: '<S293>/Fcn7'
  //   LookupNDDirect: '<S271>/Direct Lookup Table (n-D)'
  //   Sum: '<S274>/Sum1'
  //
  //  About '<S271>/Direct Lookup Table (n-D)':
  //   1-dimensional Direct Look-Up returning a Scalar,

  rtb_DirectLookupTablenD1_tmp = std::sin(90.0 - truck_adas_B.var_out_gb);

  // Product: '<S274>/Product9' incorporates:
  //   Fcn: '<S274>/Fcn15'
  //   Product: '<S293>/Product9'

  rtb_DirectLookupTablenD1_tmp_0 = rtb_DirectLookupTablenD1_tmp * rtb_Switch6_c;

  // Product: '<S274>/Product8' incorporates:
  //   Constant: '<S274>/Constant2'
  //   Fcn: '<S274>/Fcn13'
  //   LookupNDDirect: '<S271>/Direct Lookup Table (n-D)'
  //   Product: '<S293>/Product8'
  //   Sum: '<S274>/Sum1'
  //
  //  About '<S271>/Direct Lookup Table (n-D)':
  //   1-dimensional Direct Look-Up returning a Scalar,

  rtb_DirectLookupTablenD1_tmp_1 = std::cos(90.0 - truck_adas_B.var_out_gb) *
    rtb_Switch7;

  // End of Outputs for SubSystem: '<S285>/position'

  // Fcn: '<S274>/Fcn12' incorporates:
  //   Fcn: '<S274>/Fcn17'
  //   Product: '<S274>/Product10'
  //   Product: '<S274>/Product8'
  //   Product: '<S274>/Product9'
  //   Sum: '<S274>/Sum2'
  //   Sum: '<S274>/Sum7'

  rtb_DirectLookupTablenD1 = std::cos(rtb_DirectLookupTablenD1_tmp_0 * std::cos
    (rtb_Switch8) + rtb_DirectLookupTablenD1_tmp_1);

  // Sqrt: '<S274>/Sqrt' incorporates:
  //   Constant: '<S274>/Constant3'
  //   Math: '<S274>/Math Function'
  //   Sum: '<S274>/Sum5'
  //
  //  About '<S274>/Math Function':
  //   Operator: magnitude^2

  rtb_DirectLookupTablenD1 = std::sqrt(1.0 - rtb_DirectLookupTablenD1 *
    rtb_DirectLookupTablenD1);

  // Outputs for Atomic SubSystem: '<S285>/position'
  // Sum: '<S274>/Sum8' incorporates:
  //   LookupNDDirect: '<S271>/Direct Lookup Table (n-D)'
  //   Sum: '<S293>/Sum8'
  //
  //  About '<S271>/Direct Lookup Table (n-D)':
  //   1-dimensional Direct Look-Up returning a Scalar,

  tmp = truck_adas_B.var_out_gb - truck_adas_B.var_out_c;

  // End of Outputs for SubSystem: '<S285>/position'

  // Switch: '<S274>/Switch1' incorporates:
  //   Constant: '<S274>/Constant5'
  //   Fcn: '<S274>/Fcn6'
  //   Gain: '<S274>/Gain4'
  //   Sum: '<S274>/Sum8'
  //   Sum: '<S274>/Sum9'

  if (tmp > 0.0) {
    // Product: '<S274>/Product7' incorporates:
    //   Constant: '<S274>/Constant2'
    //   Fcn: '<S274>/Fcn10'
    //   Fcn: '<S274>/Fcn7'
    //   LookupNDDirect: '<S271>/Direct Lookup Table (n-D)'
    //   Product: '<S274>/Product4'
    //   Sum: '<S274>/Sum1'
    //
    //  About '<S271>/Direct Lookup Table (n-D)':
    //   1-dimensional Direct Look-Up returning a Scalar,

    rtb_DirectLookupTablenD1 = std::sin(90.0 - truck_adas_B.var_out_gb) *
      rtb_Fcn9_i / std::sin(rtb_DirectLookupTablenD1);

    // Fcn: '<S274>/Fcn6' incorporates:
    //   Product: '<S274>/Product7'

    if (rtb_DirectLookupTablenD1 > 1.0) {
      rtb_DirectLookupTablenD1 = 1.0;
    } else {
      if (rtb_DirectLookupTablenD1 < -1.0) {
        rtb_DirectLookupTablenD1 = -1.0;
      }
    }

    rtb_Fcn9_i = 57.295779513082323 * std::asin(rtb_DirectLookupTablenD1);
  } else {
    // Product: '<S274>/Product7' incorporates:
    //   Fcn: '<S274>/Fcn10'
    //   Product: '<S274>/Product4'

    rtb_Switch9 = rtb_DirectLookupTablenD1_tmp * rtb_Fcn9_i / std::sin
      (rtb_DirectLookupTablenD1);

    // Fcn: '<S274>/Fcn6' incorporates:
    //   Product: '<S274>/Product7'

    if (rtb_Switch9 > 1.0) {
      rtb_Switch9 = 1.0;
    } else {
      if (rtb_Switch9 < -1.0) {
        rtb_Switch9 = -1.0;
      }
    }

    rtb_Fcn9_i = 180.0 - 57.295779513082323 * std::asin(rtb_Switch9);
  }

  // End of Switch: '<S274>/Switch1'

  // Sum: '<S274>/Sum10'
  rtb_Fcn9_i = IMU_Heading_531_CAN3 - rtb_Fcn9_i;

  // Abs: '<S274>/Abs'
  rtb_Fcn9_i = std::abs(rtb_Fcn9_i);

  // Switch: '<S274>/Switch' incorporates:
  //   Constant: '<S274>/Constant1'
  //   Constant: '<S274>/Constant6'

  if (rtb_Fcn9_i >= 30.0) {
    rtb_Fcn9_i = 1.0;
  } else {
    rtb_Fcn9_i = -1.0;
  }

  // End of Switch: '<S274>/Switch'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Sum: '<S275>/Sum' incorporates:
    //   Constant: '<S275>/Constant'
    //   UnitDelay: '<S275>/Unit Delay'

    truck_adas_B.Sum_g = 1.0 + truck_adas_DW.UnitDelay_DSTATE_f;

    // UnitDelay: '<S275>/Unit Delay1'
    truck_adas_B.UnitDelay1_i = truck_adas_DW.UnitDelay1_DSTATE_f;
  }

  // Switch: '<S275>/Switch'
  if (rtb_Fcn9_i > 0.0) {
    truck_adas_B.Switch_c = truck_adas_B.Sum_g;
  } else {
    truck_adas_B.Switch_c = truck_adas_B.UnitDelay1_i;
  }

  // End of Switch: '<S275>/Switch'
  // End of Outputs for SubSystem: '<S268>/position'

  // Switch: '<S266>/Switch48' incorporates:
  //   Constant: '<S266>/Constant48'

  if (!(rtb_Switch48 > 0.0)) {
    rtb_Switch48 = 50.0;
  }

  // End of Switch: '<S266>/Switch48'

  // Switch: '<S266>/Switch46' incorporates:
  //   Constant: '<S266>/Constant46'

  if (!(rtb_Gain1_d > 0.0)) {
    rtb_Gain1_d = 50.0;
  }

  // End of Switch: '<S266>/Switch46'

  // Switch: '<S266>/Switch44' incorporates:
  //   Constant: '<S266>/Constant44'

  if (!(rtb_Sum6 > 0.0)) {
    rtb_Sum6 = 50.0;
  }

  // End of Switch: '<S266>/Switch44'

  // Switch: '<S266>/Switch42' incorporates:
  //   Constant: '<S266>/Constant42'

  if (!(rtb_Switch1_m > 0.0)) {
    rtb_Switch1_m = 50.0;
  }

  // End of Switch: '<S266>/Switch42'

  // Switch: '<S266>/Switch40' incorporates:
  //   Constant: '<S266>/Constant40'

  if (!(rtb_Switch3_d > 0.0)) {
    rtb_Switch3_d = 50.0;
  }

  // End of Switch: '<S266>/Switch40'

  // Switch: '<S266>/Switch38' incorporates:
  //   Constant: '<S266>/Constant38'

  if (!(rtb_Switch10 > 0.0)) {
    rtb_Switch10 = 50.0;
  }

  // End of Switch: '<S266>/Switch38'

  // Switch: '<S266>/Switch36' incorporates:
  //   Constant: '<S266>/Constant36'

  if (!(rtb_Switch36_g > 0.0)) {
    rtb_Switch36_g = 50.0;
  }

  // End of Switch: '<S266>/Switch36'

  // Switch: '<S266>/Switch34' incorporates:
  //   Constant: '<S266>/Constant34'

  if (!(rtb_Switch34_k > 0.0)) {
    rtb_Switch34_k = 50.0;
  }

  // End of Switch: '<S266>/Switch34'

  // Switch: '<S266>/Switch32' incorporates:
  //   Constant: '<S266>/Constant32'

  if (!(rtb_Switch32_m > 0.0)) {
    rtb_Switch32_m = 50.0;
  }

  // End of Switch: '<S266>/Switch32'

  // Switch: '<S266>/Switch30' incorporates:
  //   Constant: '<S266>/Constant30'

  if (!(rtb_Switch30_e > 0.0)) {
    rtb_Switch30_e = 50.0;
  }

  // End of Switch: '<S266>/Switch30'

  // MinMax: '<S266>/Min1'
  if (rtb_Switch48 < rtb_Gain1_d) {
    rtb_Gain1_d = rtb_Switch48;
  }

  if (rtb_Gain1_d < rtb_Sum6) {
    rtb_Sum6 = rtb_Gain1_d;
  }

  if (rtb_Sum6 < rtb_Switch1_m) {
    rtb_Switch1_m = rtb_Sum6;
  }

  if (rtb_Switch1_m < rtb_Switch3_d) {
    rtb_Switch3_d = rtb_Switch1_m;
  }

  if (rtb_Switch3_d < rtb_Switch10) {
    rtb_Switch10 = rtb_Switch3_d;
  }

  if (rtb_Switch10 < rtb_Switch36_g) {
    rtb_Switch36_g = rtb_Switch10;
  }

  if (rtb_Switch36_g < rtb_Switch34_k) {
    rtb_Switch34_k = rtb_Switch36_g;
  }

  if (rtb_Switch34_k < rtb_Switch32_m) {
    rtb_Switch32_m = rtb_Switch34_k;
  }

  // Outputs for Atomic SubSystem: '<S269>/Obsvision '
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Delay: '<S277>/Delay'
    truck_adas_B.Delay_n = truck_adas_DW.Delay_DSTATE_l;
  }

  // Gain: '<S280>/Gain' incorporates:
  //   LookupNDDirect: '<S278>/Direct Lookup Table (n-D)'
  //
  //  About '<S278>/Direct Lookup Table (n-D)':
  //   1-dimensional Direct Look-Up returning a Scalar,

  rtb_Gain1_d = 0.017453292519943295 * truck_adas_B.var_out_i;

  // Gain: '<S280>/Gain1'
  rtb_DirectLookupTablenD1 = 0.017453292519943295 * truck_adas_B.Sum10;

  // Sum: '<S280>/Sum4' incorporates:
  //   Fcn: '<S280>/Fcn1'
  //   Fcn: '<S280>/Fcn2'
  //   Fcn: '<S280>/Fcn3'
  //   Fcn: '<S280>/Fcn4'
  //   Fcn: '<S280>/Fcn5'
  //   Gain: '<S280>/Gain2'
  //   Gain: '<S280>/Gain3'
  //   LookupNDDirect: '<S278>/Direct Lookup Table (n-D)1'
  //   Product: '<S280>/Product1'
  //   Product: '<S280>/Product2'
  //   Product: '<S280>/Product3'
  //   Sum: '<S280>/Sum3'
  //
  //  About '<S278>/Direct Lookup Table (n-D)1':
  //   1-dimensional Direct Look-Up returning a Scalar,

  rtb_DirectLookupTablenD1 = std::cos(0.017453292519943295 *
    truck_adas_B.var_out_gb - 0.017453292519943295 * truck_adas_B.Sum22) * (std::
    cos(rtb_Gain1_d) * std::cos(rtb_DirectLookupTablenD1)) + std::sin
    (rtb_Gain1_d) * std::sin(rtb_DirectLookupTablenD1);

  // Fcn: '<S280>/Fcn'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  // Product: '<S280>/Product' incorporates:
  //   Constant: '<S280>/R'
  //   Fcn: '<S280>/Fcn'

  truck_adas_B.Product_b = 6.371E+6 * std::acos(rtb_DirectLookupTablenD1);

  // End of Outputs for SubSystem: '<S269>/Obsvision '

  // MinMax: '<S266>/Min1'
  if (rtb_Switch32_m < rtb_Switch30_e) {
    rtb_Switch30_e = rtb_Switch32_m;
  }

  // Outputs for Atomic SubSystem: '<S269>/Obsvision '
  // Switch: '<S277>/Switch1' incorporates:
  //   Constant: '<S277>/Constant2'

  if (rtb_Switch30_e > 3.0) {
    rtb_Fcn9_i = 150.0;
  } else {
    rtb_Fcn9_i = Obj_distance_vision_534_CAN3;
  }

  // End of Switch: '<S277>/Switch1'

  // Switch: '<S277>/Switch' incorporates:
  //   Sum: '<S277>/Sum1'

  if (truck_adas_B.Product_b - truck_adas_B.Delay_n > 0.0) {
    rtb_Switch30_e = truck_adas_B.Delay_n;
  } else {
    rtb_Switch30_e = truck_adas_B.Product_b;
  }

  // End of Switch: '<S277>/Switch'

  // Switch: '<S277>/Switch2' incorporates:
  //   Constant: '<S277>/Constant'
  //   Constant: '<S277>/Constant1'
  //   RelationalOperator: '<S277>/Relational Operator'

  if (rtb_Switch30_e <= 3.0) {
    rtb_Gain1_d = truck_adas_B.Delay_n;
  } else {
    rtb_Gain1_d = 200.0;
  }

  // End of Switch: '<S277>/Switch2'

  // MinMax: '<S277>/Min'
  if ((rtb_Fcn9_i < rtb_Gain1_d) || rtIsNaN(rtb_Gain1_d)) {
    rtb_Gain1_d = rtb_Fcn9_i;
  }

  // End of MinMax: '<S277>/Min'
  // End of Outputs for SubSystem: '<S269>/Obsvision '

  // S-Function (IDS_Var_Out): '<S40>/var_out'
  truck_adas_B.var_out_h4= g_rte_InputSignals.RadarObjfiltering_T.minRadarObjDis;

  // Switch: '<S281>/Switch' incorporates:
  //   MinMax: '<S281>/Min'
  //   Sum: '<S281>/Sum'

  if (rtb_Gain1_d - truck_adas_B.var_out_h4 > 3.0) {
    // MinMax: '<S281>/Min'
    if ((rtb_Gain1_d < truck_adas_B.var_out_h4) || rtIsNaN
        (truck_adas_B.var_out_h4)) {
      rtb_Switch10 = rtb_Gain1_d;
    } else {
      rtb_Switch10 = truck_adas_B.var_out_h4;
    }

    // Switch: '<S281>/Switch1'
    if (!(rtb_Switch10 > 100.0)) {
      rtb_Gain1_d = truck_adas_B.var_out_h4;
    }

    // End of Switch: '<S281>/Switch1'
  } else {
    if ((!(rtb_Gain1_d < truck_adas_B.var_out_h4)) && (!rtIsNaN
         (truck_adas_B.var_out_h4))) {
      // MinMax: '<S281>/Min'
      rtb_Gain1_d = truck_adas_B.var_out_h4;
    }
  }

  // End of Switch: '<S281>/Switch'

  // Sum: '<S282>/Add'
  rtb_Fcn9_i = rtb_Gain1_d - truck_adas_B.VehMot_AccPed_vFltOld_mp;

  // Abs: '<S282>/Abs'
  rtb_DirectLookupTablenD1 = std::abs(rtb_Fcn9_i);
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Product: '<S282>/Divide' incorporates:
    //   Constant: '<S282>/Constant2'
    //   Constant: '<S282>/Constant4'

    truck_adas_B.Divide = 1.4;

    // Sum: '<S282>/Add3' incorporates:
    //   Constant: '<S282>/Constant4'

    truck_adas_B.Add3 = truck_adas_B.VehMot_AccPed_vFltOld_mp + 0.7;

    // Sum: '<S282>/Add2' incorporates:
    //   Constant: '<S282>/Constant4'

    truck_adas_B.Add2 = truck_adas_B.VehMot_AccPed_vFltOld_mp - 0.7;
  }

  // Switch: '<S282>/Switch2' incorporates:
  //   Constant: '<S282>/Constant3'
  //   Constant: '<S282>/Constant4'
  //   RelationalOperator: '<S282>/Relational Operator1'
  //   RelationalOperator: '<S282>/Relational Operator2'
  //   RelationalOperator: '<S282>/Relational Operator3'
  //   Switch: '<S282>/Switch1'
  //   Switch: '<S282>/Switch3'

  if (rtb_DirectLookupTablenD1 <= 0.7) {
    truck_adas_B.Switch2 = truck_adas_B.VehMot_AccPed_vFltOld_mp;
  } else if (rtb_DirectLookupTablenD1 > truck_adas_B.Divide) {
    // Switch: '<S282>/Switch3'
    truck_adas_B.Switch2 = rtb_Gain1_d;
  } else if (rtb_Fcn9_i > 0.0) {
    // Switch: '<S282>/Switch1' incorporates:
    //   Switch: '<S282>/Switch3'

    truck_adas_B.Switch2 = truck_adas_B.Add3;
  } else {
    // Switch: '<S282>/Switch3' incorporates:
    //   Switch: '<S282>/Switch1'

    truck_adas_B.Switch2 = truck_adas_B.Add2;
  }

  // End of Switch: '<S282>/Switch2'

  // S-Function (IDS_Var_Out): '<S148>/var_out'
  ADAS_vel_cur_520_CAN3= VelSpd_MCU_502_CAN3;
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Memory: '<S288>/Memory'
    truck_adas_B.Memory = truck_adas_DW.Memory_PreviousInput;

    // UnitDelay: '<S163>/Unit Delay1'
    rtb_UnitDelay1_n = truck_adas_DW.UnitDelay1_DSTATE_g;

    // Chart: '<S300>/VehStatCo_Stat_Stat' incorporates:
    //   Constant: '<S300>/AEB'
    //   Constant: '<S300>/APA_AEB'
    //   Constant: '<S300>/APA_Brake'
    //   Constant: '<S300>/APA_FCW'
    //   Constant: '<S300>/APA_RP'
    //   Constant: '<S300>/APA_Running'
    //   Constant: '<S300>/APA_START'
    //   Constant: '<S300>/Brake'
    //   Constant: '<S300>/FCW'
    //   Constant: '<S300>/RP'
    //   Constant: '<S300>/Running'
    //   Constant: '<S300>/START'
    //   Constant: '<S300>/Standby '

    if (truck_adas_DW.is_active_c2_truck_adas == 0U) {
      truck_adas_DW.is_active_c2_truck_adas = 1U;
      truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Standby0x01;
    } else {
      switch (truck_adas_DW.is_c2_truck_adas) {
       case truck_adas_IN_APA_RP0x08:
        if (Navigation_CMD_st_520_CAN3 == 2.0) {
          truck_adas_B.ADAS_Stat_st = 9U;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_APA_TF;
          truck_adas_DW.is_APA_TF = truck_adas_IN_APA_Start0x09;
        } else if (Navigation_CMD_st_520_CAN3 == 0.0) {
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Standby0x01;
        } else {
          truck_adas_B.ADAS_Stat_st = 8U;
        }
        break;

       case truck_adas_IN_APA_TF:
        if (Navigation_CMD_st_520_CAN3 == 0.0) {
          truck_adas_DW.is_APA_TF = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Standby0x01;
        } else if (truck_adas_B.Memory < 15.0) {
          truck_adas_B.ADAS_Stat_st = 12U;
          truck_adas_DW.is_APA_TF = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Fianl1;
          truck_adas_DW.is_Fianl1 = truck_adas_IN_APA_FCW0x12;
        } else {
          switch (truck_adas_DW.is_APA_TF) {
           case truck_adas_IN_APA_Brake0x11:
            if (rtb_UnitDelay1_n > 10.0) {
              truck_adas_B.ADAS_Stat_st = 9U;
              truck_adas_DW.is_APA_TF = truck_adas_IN_APA_Start0x09;
            } else {
              truck_adas_B.ADAS_Stat_st = 11U;
            }
            break;

           case truck_adas_IN_APA_Running0x10:
            if (rtb_UnitDelay1_n < 10.0) {
              truck_adas_DW.is_APA_TF = truck_adas_IN_APA_Brake0x11;
            } else if (-ADAS_vel_cur_520_CAN3 > -1.5) {
              truck_adas_B.ADAS_Stat_st = 9U;
              truck_adas_DW.is_APA_TF = truck_adas_IN_APA_Start0x09;
            } else {
              truck_adas_B.ADAS_Stat_st = 10U;
            }
            break;

           default:
            // case IN_APA_Start0x09:
            if (-ADAS_vel_cur_520_CAN3 < -1.5) {
              truck_adas_B.ADAS_Stat_st = 10U;
              truck_adas_DW.is_APA_TF = truck_adas_IN_APA_Running0x10;
            } else if (rtb_UnitDelay < 10.0) {
              truck_adas_B.ADAS_Stat_st = 11U;
              truck_adas_DW.is_APA_TF = truck_adas_IN_APA_Brake0x11;
            } else {
              truck_adas_B.ADAS_Stat_st = 9U;
            }
            break;
          }
        }
        break;

       case truck_adas_IN_Fianl:
        if (truck_adas_B.Switch2 > 8.0) {
          truck_adas_B.ADAS_Stat_st = 3U;
          truck_adas_DW.is_Fianl = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_TF;
          truck_adas_DW.is_TF = truck_adas_IN_Start0x03;
        } else if (Navigation_CMD_st_520_CAN3 == 0.0) {
          truck_adas_DW.is_Fianl = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Standby0x01;
        } else if (truck_adas_DW.is_Fianl == truck_adas_IN_AEB0x07) {
          if (truck_adas_B.Switch2 > 5.0) {
            truck_adas_B.ADAS_Stat_st = 6U;
            truck_adas_DW.is_Fianl = truck_adas_IN_FCW0x06;
          } else {
            truck_adas_B.ADAS_Stat_st = 7U;
          }
        } else {
          // case IN_FCW0x06:
          if (truck_adas_B.Switch2 < 5.0) {
            truck_adas_B.ADAS_Stat_st = 7U;
            truck_adas_DW.is_Fianl = truck_adas_IN_AEB0x07;
          } else {
            truck_adas_B.ADAS_Stat_st = 6U;
          }
        }
        break;

       case truck_adas_IN_Fianl1:
        if (truck_adas_B.Memory > 15.0) {
          truck_adas_B.ADAS_Stat_st = 9U;
          truck_adas_DW.is_Fianl1 = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_APA_TF;
          truck_adas_DW.is_APA_TF = truck_adas_IN_APA_Start0x09;
        } else if (Navigation_CMD_st_520_CAN3 == 0.0) {
          truck_adas_DW.is_Fianl1 = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Standby0x01;
        } else if (truck_adas_DW.is_Fianl1 == truck_adas_IN_APA_AEB0x07) {
          if (truck_adas_B.Memory > 10.0) {
            truck_adas_B.ADAS_Stat_st = 12U;
            truck_adas_DW.is_Fianl1 = truck_adas_IN_APA_FCW0x12;
          } else {
            truck_adas_B.ADAS_Stat_st = 13U;
          }
        } else {
          // case IN_APA_FCW0x12:
          if (truck_adas_B.Memory < 10.0) {
            truck_adas_B.ADAS_Stat_st = 13U;
            truck_adas_DW.is_Fianl1 = truck_adas_IN_APA_AEB0x07;
          } else {
            truck_adas_B.ADAS_Stat_st = 12U;
          }
        }
        break;

       case truck_adas_IN_RP0x02:
        if (Navigation_CMD_st_520_CAN3 == 1.0) {
          truck_adas_B.ADAS_Stat_st = 3U;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_TF;
          truck_adas_DW.is_TF = truck_adas_IN_Start0x03;
        } else if (Navigation_CMD_st_520_CAN3 == 0.0) {
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Standby0x01;
        } else {
          truck_adas_B.ADAS_Stat_st = 2U;
        }
        break;

       case truck_adas_IN_Standby0x01:
        if (Navigation_CMD_st_520_CAN3 == 1.0) {
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_RP0x02;
        } else if (Navigation_CMD_st_520_CAN3 == 2.0) {
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_APA_RP0x08;
        } else {
          truck_adas_B.ADAS_Stat_st = 1U;
        }
        break;

       default:
        // case IN_TF:
        if (Navigation_CMD_st_520_CAN3 == 0.0) {
          truck_adas_DW.is_TF = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Standby0x01;
        } else if (truck_adas_B.Switch2 < 8.0) {
          truck_adas_DW.is_TF = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c2_truck_adas = truck_adas_IN_Fianl;
          truck_adas_DW.is_Fianl = truck_adas_IN_FCW0x06;
        } else {
          switch (truck_adas_DW.is_TF) {
           case truck_adas_IN_Brake0x05:
            if (rtb_UnitDelay > 5.0) {
              truck_adas_B.ADAS_Stat_st = 3U;
              truck_adas_DW.is_TF = truck_adas_IN_Start0x03;
            } else {
              truck_adas_B.ADAS_Stat_st = 5U;
            }
            break;

           case truck_adas_IN_Running0x04:
            if (rtb_UnitDelay < 5.0) {
              truck_adas_DW.is_TF = truck_adas_IN_Brake0x05;
            } else if (ADAS_vel_cur_520_CAN3 < 0.2) {
              truck_adas_DW.is_TF = truck_adas_IN_Start0x03;
            } else {
              truck_adas_B.ADAS_Stat_st = 4U;
            }
            break;

           default:
            // case IN_Start0x03:
            if (ADAS_vel_cur_520_CAN3 > 0.2) {
              truck_adas_DW.is_TF = truck_adas_IN_Running0x04;
            } else if (rtb_UnitDelay < 5.0) {
              truck_adas_B.ADAS_Stat_st = 5U;
              truck_adas_DW.is_TF = truck_adas_IN_Brake0x05;
            } else {
              truck_adas_B.ADAS_Stat_st = 3U;
            }
            break;
          }
        }
        break;
      }
    }

    // End of Chart: '<S300>/VehStatCo_Stat_Stat'
  }

  // S-Function (IDS_Var_Out): '<S103>/var_out'
  truck_adas_B.var_out_m5= g_rte_InputSignals.rmgps.RM_IMU_latitude_AN;

  // S-Function (IDS_Var_Out): '<S105>/var_out'
  truck_adas_B.var_out_b= g_rte_InputSignals.rmgps.RM_IMU_longitude_AN;

  // Outputs for Atomic SubSystem: '<S163>/D5.2  RP'
  // Outputs for Atomic SubSystem: '<S302>/D5.2.1   deta_S'
  // Outputs for Atomic SubSystem: '<S311>/deta_s'
  // Gain: '<S313>/Gain'
  rtb_Fcn9_i = 0.017453292519943295 * truck_adas_B.var_out_c;

  // Gain: '<S313>/Gain1'
  rtb_Gain1_d = 0.017453292519943295 * truck_adas_B.var_out_m5;

  // Sum: '<S313>/Sum4' incorporates:
  //   Fcn: '<S313>/Fcn1'
  //   Fcn: '<S313>/Fcn2'
  //   Fcn: '<S313>/Fcn3'
  //   Fcn: '<S313>/Fcn4'
  //   Fcn: '<S313>/Fcn5'
  //   Gain: '<S313>/Gain2'
  //   Gain: '<S313>/Gain3'
  //   Product: '<S313>/Product1'
  //   Product: '<S313>/Product2'
  //   Product: '<S313>/Product3'
  //   Sum: '<S313>/Sum3'

  rtb_DirectLookupTablenD1 = std::cos(0.017453292519943295 *
    truck_adas_B.var_out_kzu - 0.017453292519943295 * truck_adas_B.var_out_b) *
    (std::cos(rtb_Fcn9_i) * std::cos(rtb_Gain1_d)) + std::sin(rtb_Fcn9_i) * std::
    sin(rtb_Gain1_d);

  // Fcn: '<S313>/Fcn'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  // Product: '<S313>/Product' incorporates:
  //   Constant: '<S313>/R'
  //   Fcn: '<S313>/Fcn'

  truck_adas_B.Product_i = 6.371E+6 * std::acos(rtb_DirectLookupTablenD1);

  // End of Outputs for SubSystem: '<S311>/deta_s'
  // End of Outputs for SubSystem: '<S302>/D5.2.1   deta_S'

  // Outputs for Atomic SubSystem: '<S302>/D5.2.2   judgement'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // If: '<S312>/If' incorporates:
    //   Constant: '<S314>/Constant'
    //   Inport: '<S315>/In1'
    //   Inport: '<S316>/In1'
    //   RelationalOperator: '<S314>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      // Outputs for IfAction SubSystem: '<S312>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S316>/Action Port'

      // Outputs for IfAction SubSystem: '<S312>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S315>/Action Port'

      truck_adas_B.Merge_d = (truck_adas_B.ADAS_Stat_st == 2);

      // End of Outputs for SubSystem: '<S312>/If Action Subsystem1'
      // End of Outputs for SubSystem: '<S312>/If Action Subsystem2'
    }

    // End of If: '<S312>/If'

    // UnitDelay: '<S312>/Unit Delay'
    truck_adas_B.UnitDelay_mc = truck_adas_DW.UnitDelay_DSTATE_bf;
  }

  // Switch: '<S312>/Switch'
  if (truck_adas_B.Merge_d > 0.0) {
    truck_adas_B.Switch_d = truck_adas_B.Product_i;
  } else {
    truck_adas_B.Switch_d = truck_adas_B.UnitDelay_mc;
  }

  // End of Switch: '<S312>/Switch'
  // End of Outputs for SubSystem: '<S302>/D5.2.2   judgement'
  // End of Outputs for SubSystem: '<S163>/D5.2  RP'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // If: '<S319>/If' incorporates:
    //   Constant: '<S319>/Constant2'
    //   Constant: '<S319>/Constant3'
    //   Constant: '<S330>/Constant'
    //   Inport: '<S332>/In1'
    //   Inport: '<S333>/In1'
    //   RelationalOperator: '<S330>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      rtAction = static_cast<int8_T>((truck_adas_B.ADAS_Stat_st != 3));
      truck_adas_DW.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = truck_adas_DW.If_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S319>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S332>/Action Port'

      truck_adas_B.Merge = 1.0;

      // End of Outputs for SubSystem: '<S319>/If Action Subsystem1'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S319>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S333>/Action Port'

      truck_adas_B.Merge = 0.0;

      // End of Outputs for SubSystem: '<S319>/If Action Subsystem2'
      break;
    }

    // End of If: '<S319>/If'

    // If: '<S318>/If' incorporates:
    //   Constant: '<S318>/Constant2'
    //   Constant: '<S318>/Constant3'
    //   Constant: '<S323>/Constant'
    //   Inport: '<S326>/In1'
    //   Inport: '<S327>/In1'
    //   RelationalOperator: '<S323>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      rtAction = static_cast<int8_T>((truck_adas_B.ADAS_Stat_st != 4));
      truck_adas_DW.If_ActiveSubsystem_i = rtAction;
    } else {
      rtAction = truck_adas_DW.If_ActiveSubsystem_i;
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S318>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S326>/Action Port'

      truck_adas_B.Merge_h = 1.0;

      // End of Outputs for SubSystem: '<S318>/If Action Subsystem1'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S318>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S327>/Action Port'

      truck_adas_B.Merge_h = 0.0;

      // End of Outputs for SubSystem: '<S318>/If Action Subsystem2'
      break;
    }

    // End of If: '<S318>/If'
  }

  // Switch: '<S319>/Switch' incorporates:
  //   Constant: '<S319>/NORMAl 2'

  if (truck_adas_B.Merge > 0.0) {
    // Switch: '<S331>/Switch3' incorporates:
    //   Constant: '<S331>/vel_st'
    //   Constant: '<S331>/vel_st1'
    //   Logic: '<S331>/Logical Operator'
    //   Switch: '<S331>/Switch'
    //   Switch: '<S331>/Switch1'

    if ((truck_adas_B.Switch2 > 5.0) && (truck_adas_B.Switch_d > 5.0)) {
      rtb_Sum6 = 2.0;
    } else {
      rtb_Sum6 = 0.0;
    }

    // End of Switch: '<S331>/Switch3'
  } else {
    rtb_Sum6 = 2.0;
  }

  // End of Switch: '<S319>/Switch'

  // S-Function (IDS_Var_Out): '<S42>/var_out'
  truck_adas_B.var_out_ir= g_rte_InputSignals.rmgps.RM_IMU_heading_TX;

  // Outputs for Atomic SubSystem: '<S318>/D5.3.4 Steerangle'
  // Outputs for Atomic SubSystem: '<S324>/D5.3.4.2 deta_oriatation'
  // Sum: '<S329>/Sum3' incorporates:
  //   Inport: '<S324>/RM_IMU_heading_TX'

  rtb_Fcn9_i = truck_adas_B.var_out_ir - IMU_Heading_531_CAN3;

  // Abs: '<S329>/Abs'
  rtb_Switch10 = std::abs(rtb_Fcn9_i);

  // Switch: '<S329>/Switch' incorporates:
  //   Constant: '<S329>/Constant1'

  if (!(rtb_Switch10 > 3.0)) {
    rtb_Fcn9_i = 0.0;
  }

  // End of Switch: '<S329>/Switch'

  // MinMax: '<S329>/Min'
  if (!(rtb_Fcn9_i < 45.0)) {
    rtb_Fcn9_i = 45.0;
  }

  // End of MinMax: '<S329>/Min'

  // MinMax: '<S329>/Max'
  if (rtb_Fcn9_i > -45.0) {
    rtb_UnitDelay = rtb_Fcn9_i;
  } else {
    rtb_UnitDelay = -45.0;
  }

  // End of MinMax: '<S329>/Max'
  // End of Outputs for SubSystem: '<S324>/D5.3.4.2 deta_oriatation'
  // End of Outputs for SubSystem: '<S318>/D5.3.4 Steerangle'

  // Outputs for Atomic SubSystem: '<S303>/ D5.3.3 Brake'
  // If: '<S317>/If' incorporates:
  //   Constant: '<S320>/Constant'
  //   Inport: '<S321>/In1'
  //   Inport: '<S322>/In1'
  //   RelationalOperator: '<S320>/Compare'

  if ((rtmIsMajorTimeStep(truck_adas_M) &&
       truck_adas_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (truck_adas_M)) {
    // Outputs for IfAction SubSystem: '<S317>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S322>/Action Port'

    // Outputs for IfAction SubSystem: '<S317>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S321>/Action Port'

    truck_adas_B.Merge_bv = (truck_adas_B.ADAS_Stat_st == 5);

    // End of Outputs for SubSystem: '<S317>/If Action Subsystem1'
    // End of Outputs for SubSystem: '<S317>/If Action Subsystem2'
  }

  // End of If: '<S317>/If'

  // Switch: '<S317>/Switch' incorporates:
  //   Constant: '<S317>/Vel_brake '

  if (truck_adas_B.Merge_bv > 0.0) {
    // Switch: '<S317>/vel_select4' incorporates:
    //   Constant: '<S317>/VelFPD'
    //   Constant: '<S317>/VelFPD_2'

    if (truck_adas_B.Switch_d > 5.0) {
      rtb_Fcn9_i = 1.5;
    } else {
      rtb_Fcn9_i = 0.0;
    }

    // End of Switch: '<S317>/vel_select4'
  } else {
    rtb_Fcn9_i = 0.5;
  }

  // End of Switch: '<S317>/Switch'
  // End of Outputs for SubSystem: '<S303>/ D5.3.3 Brake'

  // S-Function (IDS_Var_Out): '<S73>/var_out'
  truck_adas_B.var_out_lh= g_rte_InputSignals.imu.GPSTime_F4;

  // Outputs for Atomic SubSystem: '<S305>/D5.5.1 Accelation'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // UnitDelay: '<S337>/Unit Delay'
    truck_adas_B.UnitDelay_m = truck_adas_DW.UnitDelay_DSTATE_a;
  }

  // Sum: '<S337>/Sum1'
  Time_difference_530_CAN3 = truck_adas_B.var_out_lh - truck_adas_B.UnitDelay_m;

  // Gain: '<S337>/Gain1'
  rtb_Gain1_d = 0.27777777777777779 * ADAS_vel_cur_520_CAN3;

  // Sum: '<S337>/Sum' incorporates:
  //   Abs: '<S337>/Abs'
  //   Constant: '<S337>/Constant3'
  //   Gain: '<S337>/Gain'
  //   Math: '<S337>/Math Function'
  //   Product: '<S337>/Product'
  //   Product: '<S337>/Product1'
  //   Sum: '<S337>/Sum2'
  //
  //  About '<S337>/Math Function':
  //   Operator: magnitude^2

  rtb_DirectLookupTablenD1 = rtb_Gain1_d * rtb_Gain1_d / ((truck_adas_B.Switch2
    - 3.0) * -2.0) * std::abs(Time_difference_530_CAN3) + rtb_Gain1_d;

  // End of Outputs for SubSystem: '<S305>/D5.5.1 Accelation'

  // Outputs for Atomic SubSystem: '<S305>/D5.5.2 judgement '
  // If: '<S338>/If' incorporates:
  //   Constant: '<S339>/Constant'
  //   Inport: '<S340>/In1'
  //   Inport: '<S341>/In1'
  //   RelationalOperator: '<S339>/Compare'

  if ((rtmIsMajorTimeStep(truck_adas_M) &&
       truck_adas_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (truck_adas_M)) {
    // Outputs for IfAction SubSystem: '<S338>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S341>/Action Port'

    // Outputs for IfAction SubSystem: '<S338>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S340>/Action Port'

    truck_adas_B.Merge_f = (truck_adas_B.ADAS_Stat_st == 7);

    // End of Outputs for SubSystem: '<S338>/If Action Subsystem1'
    // End of Outputs for SubSystem: '<S338>/If Action Subsystem2'
  }

  // End of If: '<S338>/If'
  // End of Outputs for SubSystem: '<S305>/D5.5.2 judgement '
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // If: '<S348>/If' incorporates:
    //   Constant: '<S348>/Constant2'
    //   Constant: '<S348>/Constant3'
    //   Constant: '<S354>/Constant'
    //   Inport: '<S356>/In1'
    //   Inport: '<S357>/In1'
    //   RelationalOperator: '<S354>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      rtAction = static_cast<int8_T>((truck_adas_B.ADAS_Stat_st != 9));
      truck_adas_DW.If_ActiveSubsystem_o = rtAction;
    } else {
      rtAction = truck_adas_DW.If_ActiveSubsystem_o;
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S348>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S356>/Action Port'

      rtb_Merge = 1.0;

      // End of Outputs for SubSystem: '<S348>/If Action Subsystem1'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S348>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S357>/Action Port'

      rtb_Merge = 0.0;

      // End of Outputs for SubSystem: '<S348>/If Action Subsystem2'
      break;
    }

    // End of If: '<S348>/If'

    // Switch: '<S348>/Switch' incorporates:
    //   Constant: '<S348>/APA_st'

    if (rtb_Merge > 0.0) {
      // Switch: '<S355>/Switch3' incorporates:
      //   Constant: '<S355>/APA_vel_st'
      //   Constant: '<S355>/vel_st1'
      //   Logic: '<S355>/Logical Operator'
      //   Switch: '<S355>/Switch'
      //   Switch: '<S355>/Switch1'

      if ((truck_adas_B.Memory > 10.0) && (rtb_UnitDelay1_n > 7.0)) {
        truck_adas_B.Switch = -1.5;
      } else {
        truck_adas_B.Switch = 0.0;
      }

      // End of Switch: '<S355>/Switch3'
    } else {
      truck_adas_B.Switch = -1.5;
    }

    // End of Switch: '<S348>/Switch'

    // Product: '<S361>/Product4' incorporates:
    //   Constant: '<S361>/Constant1'
    //   Constant: '<S361>/acc_distance'
    //   Sum: '<S361>/Sum'

    truck_adas_B.Product4 = (rtb_UnitDelay1_n - 25.0) * 2.0;

    // Abs: '<S361>/Abs' incorporates:
    //   Constant: '<S361>/acc_distance'
    //   Sum: '<S361>/Sum'

    truck_adas_B.Abs = std::abs(rtb_UnitDelay1_n - 25.0);

    // If: '<S349>/If' incorporates:
    //   Constant: '<S349>/Constant2'
    //   Constant: '<S349>/Constant3'
    //   Constant: '<S358>/Constant'
    //   Inport: '<S359>/In1'
    //   Inport: '<S360>/In1'
    //   RelationalOperator: '<S358>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      rtAction = static_cast<int8_T>((truck_adas_B.ADAS_Stat_st != 10));
      truck_adas_DW.If_ActiveSubsystem_p = rtAction;
    } else {
      rtAction = truck_adas_DW.If_ActiveSubsystem_p;
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S349>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S359>/Action Port'

      truck_adas_B.Merge_c = 1.0;

      // End of Outputs for SubSystem: '<S349>/If Action Subsystem1'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S349>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S360>/Action Port'

      truck_adas_B.Merge_c = 0.0;

      // End of Outputs for SubSystem: '<S349>/If Action Subsystem2'
      break;
    }

    // End of If: '<S349>/If'

    // Outputs for Atomic SubSystem: '<S307>/ D5.7.3 Brake_APA'
    // Outputs for IfAction SubSystem: '<S347>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S353>/Action Port'

    // Outputs for IfAction SubSystem: '<S347>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S352>/Action Port'

    // If: '<S347>/If' incorporates:
    //   Constant: '<S351>/Constant'
    //   Inport: '<S352>/In1'
    //   Inport: '<S353>/In1'
    //   RelationalOperator: '<S351>/Compare'

    rtb_Merge = (truck_adas_B.ADAS_Stat_st == 11);

    // End of Outputs for SubSystem: '<S347>/If Action Subsystem1'
    // End of Outputs for SubSystem: '<S347>/If Action Subsystem2'

    // Switch: '<S347>/Switch' incorporates:
    //   Constant: '<S347>/VelFPD_1'

    if (rtb_Merge > 0.0) {
      // Switch: '<S347>/vel_select4' incorporates:
      //   Constant: '<S347>/VelFPD'
      //   Constant: '<S347>/VelFPD_2'

      if (rtb_UnitDelay1_n > 7.0) {
        truck_adas_B.Switch_f = -2.0;
      } else {
        truck_adas_B.Switch_f = 0.0;
      }

      // End of Switch: '<S347>/vel_select4'
    } else {
      truck_adas_B.Switch_f = -0.5;
    }

    // End of Switch: '<S347>/Switch'
    // End of Outputs for SubSystem: '<S307>/ D5.7.3 Brake_APA'

    // Outputs for Atomic SubSystem: '<S309>/D5.9.1 Accelation'
    // UnitDelay: '<S371>/Unit Delay'
    truck_adas_B.UnitDelay = truck_adas_DW.UnitDelay_DSTATE_l;

    // End of Outputs for SubSystem: '<S309>/D5.9.1 Accelation'
  }

  // Outputs for Atomic SubSystem: '<S309>/D5.9.1 Accelation'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Gain: '<S371>/Gain' incorporates:
    //   Constant: '<S371>/Constant3'
    //   Sum: '<S371>/Sum2'

    truck_adas_B.Gain = (truck_adas_B.Memory - 3.0) * -2.0;
  }

  // Gain: '<S371>/Gain2'
  rtb_Gain1_d = 0.27777777777777779 * ADAS_vel_cur_520_CAN3;

  // End of Outputs for SubSystem: '<S309>/D5.9.1 Accelation'

  // Outputs for Atomic SubSystem: '<S309>/D5.9.2 judgement '
  // If: '<S372>/If' incorporates:
  //   Constant: '<S373>/Constant'
  //   Inport: '<S374>/In1'
  //   Inport: '<S375>/In1'
  //   RelationalOperator: '<S373>/Compare'

  if ((rtmIsMajorTimeStep(truck_adas_M) &&
       truck_adas_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
      (truck_adas_M)) {
    // Outputs for IfAction SubSystem: '<S372>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S375>/Action Port'

    // Outputs for IfAction SubSystem: '<S372>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S374>/Action Port'

    truck_adas_B.Merge_b = (truck_adas_B.ADAS_Stat_st == 13);

    // End of Outputs for SubSystem: '<S372>/If Action Subsystem1'
    // End of Outputs for SubSystem: '<S372>/If Action Subsystem2'
  }

  // End of If: '<S372>/If'
  // End of Outputs for SubSystem: '<S309>/D5.9.2 judgement '

  // MultiPortSwitch: '<S301>/Multiport Switch1' incorporates:
  //   Constant: '<S301>/Constant'
  //   Constant: '<S301>/Constant1'

  switch (truck_adas_B.ADAS_Stat_st) {
   case 1:
    rtb_Fcn9_i = 0.0;
    break;

   case 2:
    rtb_Fcn9_i = rtb_Sum6;
    break;

   case 3:
    rtb_Fcn9_i = rtb_Sum6;
    break;

   case 4:
    // Switch: '<S318>/Switch' incorporates:
    //   Constant: '<S318>/Spd'

    if (truck_adas_B.Merge_h > 0.0) {
      // Gain: '<S328>/Gain1'
      rtb_Gain1_d = 0.27777777777777779 * ADAS_vel_cur_520_CAN3;

      // Math: '<S328>/Math Function3'
      //
      //  About '<S328>/Math Function3':
      //   Operator: magnitude^2

      rtb_Gain1_d *= rtb_Gain1_d;

      // Sqrt: '<S328>/Sqrt1' incorporates:
      //   Abs: '<S328>/Abs'
      //   Constant: '<S328>/Constant1'
      //   Constant: '<S328>/Constant4'
      //   Constant: '<S328>/acc_distance'
      //   Math: '<S328>/Math Function3'
      //   Product: '<S328>/Divide1'
      //   Product: '<S328>/Product4'
      //   Product: '<S328>/Product5'
      //   Product: '<S328>/Product6'
      //   Sum: '<S328>/Sum'
      //   Sum: '<S328>/Sum2'
      //   Sum: '<S328>/Sum3'
      //
      //  About '<S328>/Math Function3':
      //   Operator: magnitude^2

      rtb_Gain1_d = std::sqrt((truck_adas_ConstB.Spd2 - rtb_Gain1_d) /
        ((truck_adas_B.Switch_d - 25.0) * 2.0) * 2.0 * std::abs
        (truck_adas_B.Switch_d - 25.0) + rtb_Gain1_d);

      // MinMax: '<S328>/Min'
      if (!(rtb_Gain1_d < 7.0)) {
        rtb_Gain1_d = 7.0;
      }

      // End of MinMax: '<S328>/Min'

      // MinMax: '<S328>/Min1'
      if (rtb_Gain1_d > 0.0) {
        rtb_Fcn9_i = rtb_Gain1_d;
      } else {
        rtb_Fcn9_i = 0.0;
      }

      // End of MinMax: '<S328>/Min1'
    } else {
      rtb_Fcn9_i = 2.0;
    }

    // End of Switch: '<S318>/Switch'

    // Outputs for Atomic SubSystem: '<S318>/D5.3.running'
    // Switch: '<S325>/Switch2'
    if (rtb_Switch10 > 20.0) {
      // Switch: '<S325>/Switch1' incorporates:
      //   Gain: '<S325>/Gain'

      if (rtb_Switch10 > 30.0) {
        // Switch: '<S325>/Switch' incorporates:
        //   Gain: '<S325>/Gain1'
        //   Gain: '<S325>/Gain2'

        if (rtb_Switch10 > 40.0) {
          rtb_Fcn9_i *= 0.6;
        } else {
          rtb_Fcn9_i *= 0.75;
        }

        // End of Switch: '<S325>/Switch'
      } else {
        rtb_Fcn9_i *= 0.85;
      }

      // End of Switch: '<S325>/Switch1'
    }

    // End of Switch: '<S325>/Switch2'
    // End of Outputs for SubSystem: '<S318>/D5.3.running'
    break;

   case 5:
    break;

   case 6:
    // Outputs for Atomic SubSystem: '<S305>/D5.5.2 judgement '
    // Switch: '<S338>/Switch' incorporates:
    //   Constant: '<S338>/NORMAl 2'

    if (truck_adas_B.Merge_f > 0.0) {
      rtb_Fcn9_i = rtb_DirectLookupTablenD1;
    } else {
      rtb_Fcn9_i = 0.0;
    }

    // End of Outputs for SubSystem: '<S305>/D5.5.2 judgement '
    break;

   case 7:
    // Outputs for Atomic SubSystem: '<S305>/D5.5.2 judgement '
    // Switch: '<S338>/Switch' incorporates:
    //   Constant: '<S338>/NORMAl 2'

    if (truck_adas_B.Merge_f > 0.0) {
      rtb_Fcn9_i = rtb_DirectLookupTablenD1;
    } else {
      rtb_Fcn9_i = 0.0;
    }

    // End of Outputs for SubSystem: '<S305>/D5.5.2 judgement '
    break;

   case 8:
    rtb_Fcn9_i = 0.0;
    break;

   case 9:
    rtb_Fcn9_i = truck_adas_B.Switch;
    break;

   case 10:
    // Switch: '<S349>/Switch' incorporates:
    //   Constant: '<S349>/Spd_2'

    if (truck_adas_B.Merge_c > 0.0) {
      // Gain: '<S361>/Gain1'
      rtb_Gain1_d = 0.27777777777777779 * ADAS_vel_cur_520_CAN3;

      // Math: '<S361>/Math Function3'
      //
      //  About '<S361>/Math Function3':
      //   Operator: magnitude^2

      rtb_Gain1_d *= rtb_Gain1_d;

      // Sum: '<S361>/Sum3' incorporates:
      //   Constant: '<S361>/Constant4'
      //   Product: '<S361>/Divide1'
      //   Product: '<S361>/Product5'
      //   Product: '<S361>/Product6'
      //   Sum: '<S361>/Sum2'

      rtb_Gain1_d += (truck_adas_ConstB.Spd2_n - rtb_Gain1_d) /
        truck_adas_B.Product4 * 2.0 * truck_adas_B.Abs;

      // Sqrt: '<S361>/Sqrt1'
      rtb_Gain1_d = std::sqrt(rtb_Gain1_d);

      // Gain: '<S361>/Gain'
      rtb_Gain1_d = -rtb_Gain1_d;

      // MinMax: '<S361>/Min1'
      if (!(rtb_Gain1_d > -3.0)) {
        rtb_Gain1_d = -3.0;
      }

      // End of MinMax: '<S361>/Min1'

      // MinMax: '<S361>/Min'
      if (rtb_Gain1_d < 0.0) {
        rtb_Fcn9_i = rtb_Gain1_d;
      } else {
        rtb_Fcn9_i = 0.0;
      }

      // End of MinMax: '<S361>/Min'
    } else {
      rtb_Fcn9_i = -3.0;
    }

    // End of Switch: '<S349>/Switch'
    break;

   case 11:
    rtb_Fcn9_i = truck_adas_B.Switch_f;
    break;

   case 12:
    // Outputs for Atomic SubSystem: '<S309>/D5.9.2 judgement '
    // Switch: '<S372>/Switch' incorporates:
    //   Abs: '<S371>/Abs'
    //   Constant: '<S372>/NORMAl 2'
    //   Gain: '<S371>/Gain1'
    //   Math: '<S371>/Math Function'
    //   Product: '<S371>/Product'
    //   Product: '<S371>/Product1'
    //   Sum: '<S371>/Sum'
    //   Sum: '<S371>/Sum1'
    //
    //  About '<S371>/Math Function':
    //   Operator: magnitude^2

    if (truck_adas_B.Merge_b > 0.0) {
      // Outputs for Atomic SubSystem: '<S309>/D5.9.1 Accelation'
      rtb_Fcn9_i = -(rtb_Gain1_d * rtb_Gain1_d / truck_adas_B.Gain * std::abs
                     (truck_adas_B.var_out_lh - truck_adas_B.UnitDelay) +
                     rtb_Gain1_d);

      // End of Outputs for SubSystem: '<S309>/D5.9.1 Accelation'
    } else {
      rtb_Fcn9_i = 0.0;
    }

    // End of Outputs for SubSystem: '<S309>/D5.9.2 judgement '
    break;

   default:
    // Outputs for Atomic SubSystem: '<S309>/D5.9.2 judgement '
    // Switch: '<S372>/Switch' incorporates:
    //   Abs: '<S371>/Abs'
    //   Constant: '<S372>/NORMAl 2'
    //   Gain: '<S371>/Gain1'
    //   Math: '<S371>/Math Function'
    //   Product: '<S371>/Product'
    //   Product: '<S371>/Product1'
    //   Sum: '<S371>/Sum'
    //   Sum: '<S371>/Sum1'
    //
    //  About '<S371>/Math Function':
    //   Operator: magnitude^2

    if (truck_adas_B.Merge_b > 0.0) {
      // Outputs for Atomic SubSystem: '<S309>/D5.9.1 Accelation'
      rtb_Fcn9_i = -(rtb_Gain1_d * rtb_Gain1_d / truck_adas_B.Gain * std::abs
                     (truck_adas_B.var_out_lh - truck_adas_B.UnitDelay) +
                     rtb_Gain1_d);

      // End of Outputs for SubSystem: '<S309>/D5.9.1 Accelation'
    } else {
      rtb_Fcn9_i = 0.0;
    }

    // End of Outputs for SubSystem: '<S309>/D5.9.2 judgement '
    break;
  }

  // End of MultiPortSwitch: '<S301>/Multiport Switch1'

  // Gain: '<S160>/Gain' incorporates:
  //   Constant: '<S160>/Constant6'
  //   Product: '<S160>/Product3'

  Temp_3_537_CAN3 = rtb_Fcn9_i * 3.6 * 0.35;

  // S-Function (IDS_Var_Out): '<S46>/var_out'
  truck_adas_B.var_out_ot= g_rte_InputSignals.rmgps.RM_IMU_latitude_BE;

  // S-Function (IDS_Var_Out): '<S45>/var_out'
  truck_adas_B.var_out_d0= g_rte_InputSignals.rmgps.RM_IMU_longitude_BE;

  // Outputs for Atomic SubSystem: '<S306>/D5.6.1   deta_S'
  // Gain: '<S342>/Gain'
  rtb_Gain1_d = 0.017453292519943295 * truck_adas_B.var_out_c;

  // Gain: '<S342>/Gain1'
  rtb_DirectLookupTablenD1 = 0.017453292519943295 * truck_adas_B.var_out_ot;

  // Sum: '<S342>/Sum4' incorporates:
  //   Fcn: '<S342>/Fcn1'
  //   Fcn: '<S342>/Fcn2'
  //   Fcn: '<S342>/Fcn3'
  //   Fcn: '<S342>/Fcn4'
  //   Fcn: '<S342>/Fcn5'
  //   Gain: '<S342>/Gain2'
  //   Gain: '<S342>/Gain3'
  //   Product: '<S342>/Product1'
  //   Product: '<S342>/Product2'
  //   Product: '<S342>/Product3'
  //   Sum: '<S342>/Sum3'

  rtb_DirectLookupTablenD1 = std::cos(0.017453292519943295 *
    truck_adas_B.var_out_kzu - 0.017453292519943295 * truck_adas_B.var_out_d0) *
    (std::cos(rtb_Gain1_d) * std::cos(rtb_DirectLookupTablenD1)) + std::sin
    (rtb_Gain1_d) * std::sin(rtb_DirectLookupTablenD1);

  // Fcn: '<S342>/Fcn'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  // Product: '<S342>/Product' incorporates:
  //   Constant: '<S342>/R'
  //   Fcn: '<S342>/Fcn'

  truck_adas_B.Product = 6.371E+6 * std::acos(rtb_DirectLookupTablenD1);

  // End of Outputs for SubSystem: '<S306>/D5.6.1   deta_S'

  // Outputs for Atomic SubSystem: '<S306>/D5.6.2   judgement deta_S'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // If: '<S343>/If' incorporates:
    //   Constant: '<S344>/Constant'
    //   Inport: '<S345>/In1'
    //   Inport: '<S346>/In1'
    //   RelationalOperator: '<S344>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      // Outputs for IfAction SubSystem: '<S343>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S346>/Action Port'

      // Outputs for IfAction SubSystem: '<S343>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S345>/Action Port'

      truck_adas_B.Merge_j = (truck_adas_B.ADAS_Stat_st == 8);

      // End of Outputs for SubSystem: '<S343>/If Action Subsystem1'
      // End of Outputs for SubSystem: '<S343>/If Action Subsystem2'
    }

    // End of If: '<S343>/If'

    // UnitDelay: '<S343>/Unit Delay'
    truck_adas_B.UnitDelay_c = truck_adas_DW.UnitDelay_DSTATE_d;
  }

  // Switch: '<S343>/Switch'
  if (truck_adas_B.Merge_j > 0.0) {
    truck_adas_B.Switch_fk = truck_adas_B.Product;
  } else {
    truck_adas_B.Switch_fk = truck_adas_B.UnitDelay_c;
  }

  // End of Switch: '<S343>/Switch'
  // End of Outputs for SubSystem: '<S306>/D5.6.2   judgement deta_S'

  // MultiPortSwitch: '<S160>/Multiport Switch' incorporates:
  //   Constant: '<S160>/Constant7'

  switch (static_cast<int32_T>(Navigation_CMD_st_520_CAN3)) {
   case 0:
    Deta_530_CAN3 = 0.001;
    break;

   case 1:
    Deta_530_CAN3 = truck_adas_B.Switch_d;
    break;

   default:
    Deta_530_CAN3 = truck_adas_B.Switch_fk;
    break;
  }

  // End of MultiPortSwitch: '<S160>/Multiport Switch'

  // Outputs for Atomic SubSystem: '<S307>/D5.7.4 Steerangle_APA'
  // Outputs for Atomic SubSystem: '<S350>/D5.7.4.1 oriatation_APA '
  // Gain: '<S366>/Gain1'
  rtb_Gain1_d = 0.017453292519943295 * truck_adas_B.var_out_c;

  // Sum: '<S366>/Sum3' incorporates:
  //   Constant: '<S366>/Constant1'
  //   Constant: '<S366>/Constant6'
  //   Constant: '<S366>/Rj'
  //   Product: '<S366>/Product'
  //   Product: '<S366>/Product1'
  //   Sum: '<S366>/Sum9'

  rtb_DirectLookupTablenD1 = (90.0 - truck_adas_B.var_out_c) / 90.0 *
    truck_adas_ConstB.Sum4 + 6.356725E+6;

  // Gain: '<S366>/Gain' incorporates:
  //   Fcn: '<S366>/Fcn'
  //   Fcn: '<S366>/Fcn1'
  //   Gain: '<S366>/Gain2'
  //   Gain: '<S366>/Gain3'
  //   Gain: '<S366>/Gain4'
  //   Product: '<S366>/Product2'
  //   Product: '<S366>/Product3'
  //   Product: '<S366>/Product5'
  //   Product: '<S366>/Product6'
  //   Sum: '<S366>/Sum10'
  //   Sum: '<S366>/Sum11'

  rtb_Switch1_m = std::atan((0.017453292519943295 * truck_adas_B.var_out_d0 -
    0.017453292519943295 * truck_adas_B.var_out_kzu) * (rtb_DirectLookupTablenD1
    * std::cos(rtb_Gain1_d)) / ((0.017453292519943295 * truck_adas_B.var_out_ot
    - rtb_Gain1_d) * rtb_DirectLookupTablenD1)) * 57.295779513082323;

  // End of Outputs for SubSystem: '<S350>/D5.7.4.1 oriatation_APA '

  // Outputs for Atomic SubSystem: '<S350>/D5.7.4.2 deta_oriatation_APA  '
  // Switch: '<S363>/Switch' incorporates:
  //   Constant: '<S363>/Constant'
  //   Sum: '<S363>/Sum'

  if (IMU_Heading_531_CAN3 >= 350.0) {
    rtb_Switch30_e = 360.0 - IMU_Heading_531_CAN3;
  } else {
    rtb_Switch30_e = IMU_Heading_531_CAN3;
  }

  // End of Switch: '<S363>/Switch'

  // Sum: '<S363>/Sum3'
  rtb_UnitDelay1_n = rtb_Switch1_m - rtb_Switch30_e;

  // End of Outputs for SubSystem: '<S350>/D5.7.4.2 deta_oriatation_APA  '
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Atomic SubSystem: '<S350>/D5.7.4.3 FPD_steerangle_APA'
    // Chart: '<S364>/mode 2'
    if (truck_adas_DW.is_active_c12_truck_adas == 0U) {
      truck_adas_DW.is_active_c12_truck_adas = 1U;
      truck_adas_DW.is_c12_truck_adas = truck_adas_IN_start;
      truck_adas_DW.s = rtb_UnitDelay1_n;
    } else {
      switch (truck_adas_DW.is_c12_truck_adas) {
       case truck_adas_IN_A:
        truck_adas_DW.is_c12_truck_adas = truck_adas_IN_start;
        truck_adas_DW.s = rtb_UnitDelay1_n;
        break;

       case truck_adas_IN_Left:
        if (truck_adas_DW.is_Left == truck_adas_IN_L1) {
          if (truck_adas_DW.s > -10.0) {
            truck_adas_DW.is_Left = truck_adas_IN_L2;
          } else {
            truck_adas_B.SteerAngle_desire = -30.0;
          }
        } else {
          // case IN_L2:
          if (truck_adas_DW.s < -10.0) {
            truck_adas_B.SteerAngle_desire = -30.0;
            truck_adas_DW.is_Left = truck_adas_IN_L1;
          } else {
            truck_adas_B.SteerAngle_desire = 0.0;
          }
        }
        break;

       case truck_adas_IN_Right:
        if (truck_adas_DW.is_Right == truck_adas_IN_R1) {
          if (truck_adas_DW.s < 10.0) {
            truck_adas_DW.is_Right = truck_adas_IN_R2;
          } else {
            truck_adas_B.SteerAngle_desire = 30.0;
          }
        } else {
          // case IN_R2:
          if (truck_adas_DW.s > 10.0) {
            truck_adas_B.SteerAngle_desire = 30.0;
            truck_adas_DW.is_Right = truck_adas_IN_R1;
          } else {
            truck_adas_B.SteerAngle_desire = 0.0;
          }
        }
        break;

       default:
        // case IN_start:
        if ((Navigation_CMD_st_520_CAN3 > 1.0) && (truck_adas_DW.s > 70.0)) {
          truck_adas_B.SteerAngle_desire = 30.0;
          truck_adas_DW.is_c12_truck_adas = truck_adas_IN_Right;
          truck_adas_DW.is_Right = truck_adas_IN_R1;
        } else if ((Navigation_CMD_st_520_CAN3 > 1.0) && (truck_adas_DW.s <
                    -70.0)) {
          truck_adas_B.SteerAngle_desire = -30.0;
          truck_adas_DW.is_c12_truck_adas = truck_adas_IN_Left;
          truck_adas_DW.is_Left = truck_adas_IN_L1;
        } else {
          if ((Navigation_CMD_st_520_CAN3 > 1.0) && (truck_adas_DW.s > -70.0) &&
              (truck_adas_DW.s < 70.0)) {
            truck_adas_B.SteerAngle_desire = 0.0;
            truck_adas_DW.is_c12_truck_adas = truck_adas_IN_A;
          }
        }
        break;
      }
    }

    // End of Chart: '<S364>/mode 2'

    // MinMax: '<S364>/Min1'
    if (truck_adas_B.SteerAngle_desire < 40.0) {
      rtb_Merge = truck_adas_B.SteerAngle_desire;
    } else {
      rtb_Merge = 40.0;
    }

    // End of MinMax: '<S364>/Min1'

    // MinMax: '<S364>/Max1'
    if (rtb_Merge > -40.0) {
      rtb_Gain1_d = rtb_Merge;
    } else {
      rtb_Gain1_d = -40.0;
    }

    // End of MinMax: '<S364>/Max1'

    // Gain: '<S364>/Gain1'
    truck_adas_B.Gain1 = 20.0 * rtb_Gain1_d;

    // End of Outputs for SubSystem: '<S350>/D5.7.4.3 FPD_steerangle_APA'
  }

  // End of Outputs for SubSystem: '<S307>/D5.7.4 Steerangle_APA'

  // MultiPortSwitch: '<S160>/Multiport Switch1' incorporates:
  //   Constant: '<S160>/Constant8'

  switch (static_cast<int32_T>(Navigation_CMD_st_520_CAN3)) {
   case 0:
    Temp_2_537_CAN3 = 0.001;
    break;

   case 1:
    Temp_2_537_CAN3 = rtb_Switch10;
    break;

   default:
    Temp_2_537_CAN3 = rtb_UnitDelay1_n;
    break;
  }

  // End of MultiPortSwitch: '<S160>/Multiport Switch1'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // If: '<S304>/If' incorporates:
    //   Constant: '<S304>/Constant2'
    //   Constant: '<S304>/Constant3'
    //   Constant: '<S334>/Constant'
    //   Inport: '<S335>/In1'
    //   Inport: '<S336>/In1'
    //   RelationalOperator: '<S334>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      rtAction = static_cast<int8_T>((truck_adas_B.ADAS_Stat_st != 6));
      truck_adas_DW.If_ActiveSubsystem_f = rtAction;
    } else {
      rtAction = truck_adas_DW.If_ActiveSubsystem_f;
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S304>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S335>/Action Port'

      truck_adas_B.Merge_p = 1.0;

      // End of Outputs for SubSystem: '<S304>/If Action Subsystem1'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S304>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S336>/Action Port'

      truck_adas_B.Merge_p = 0.0;

      // End of Outputs for SubSystem: '<S304>/If Action Subsystem2'
      break;
    }

    // End of If: '<S304>/If'

    // If: '<S308>/If' incorporates:
    //   Constant: '<S308>/Constant2'
    //   Constant: '<S308>/Constant3'
    //   Constant: '<S368>/Constant'
    //   Inport: '<S369>/In1'
    //   Inport: '<S370>/In1'
    //   RelationalOperator: '<S368>/Compare'

    if (rtmIsMajorTimeStep(truck_adas_M)) {
      rtAction = static_cast<int8_T>((truck_adas_B.ADAS_Stat_st != 12));
      truck_adas_DW.If_ActiveSubsystem_m = rtAction;
    } else {
      rtAction = truck_adas_DW.If_ActiveSubsystem_m;
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S308>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S369>/Action Port'

      rtb_Merge = 1.0;

      // End of Outputs for SubSystem: '<S308>/If Action Subsystem1'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S308>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S370>/Action Port'

      rtb_Merge = 0.0;

      // End of Outputs for SubSystem: '<S308>/If Action Subsystem2'
      break;
    }

    // End of If: '<S308>/If'

    // Switch: '<S308>/Switch' incorporates:
    //   Constant: '<S308>/NORMAl 2'

    if (rtb_Merge > 0.0) {
      // Switch: '<S308>/Switch3' incorporates:
      //   Constant: '<S308>/NORMAl 4'
      //   Constant: '<S308>/Warning 3'
      //   Switch: '<S308>/Switch6'

      if (!(truck_adas_B.Memory > 18.0)) {
        truck_adas_B.Switch_h = 5.0;
      } else {
        truck_adas_B.Switch_h = 0.0;
      }

      // End of Switch: '<S308>/Switch3'
    } else {
      truck_adas_B.Switch_h = 0.0;
    }

    // End of Switch: '<S308>/Switch'
  }

  // Switch: '<S304>/Switch' incorporates:
  //   Constant: '<S304>/NORMAl 2'

  if (truck_adas_B.Merge_p > 0.0) {
    // Switch: '<S304>/Switch3' incorporates:
    //   Constant: '<S304>/NORMAl 4'
    //   Constant: '<S304>/Warning 3'
    //   Switch: '<S304>/Switch6'

    if (!(truck_adas_B.Switch2 > 18.0)) {
      rtb_DirectLookupTablenD1 = 5.0;
    } else {
      rtb_DirectLookupTablenD1 = 0.0;
    }

    // End of Switch: '<S304>/Switch3'
  } else {
    rtb_DirectLookupTablenD1 = 0.0;
  }

  // End of Switch: '<S304>/Switch'

  // MultiPortSwitch: '<S160>/Multiport Switch2'
  if (static_cast<int32_T>(Navigation_CMD_st_520_CAN3) == 1) {
    ADAS_work_st_512_CAN3 = rtb_DirectLookupTablenD1;
  } else {
    ADAS_work_st_512_CAN3 = truck_adas_B.Switch_h;
  }

  // End of MultiPortSwitch: '<S160>/Multiport Switch2'

  // MultiPortSwitch: '<S160>/Multiport Switch3' incorporates:
  //   Constant: '<S160>/Constant9'

  switch (static_cast<int32_T>(Navigation_CMD_st_520_CAN3)) {
   case 0:
    Obs_533_CAN3 = 0.001;
    break;

   case 1:
    Obs_533_CAN3 = truck_adas_B.Switch2;
    break;

   default:
    Obs_533_CAN3 = truck_adas_B.Memory;
    break;
  }

  // End of MultiPortSwitch: '<S160>/Multiport Switch3'

  // MultiPortSwitch: '<S160>/Multiport Switch4' incorporates:
  //   Constant: '<S160>/Constant10'
  //   Inport: '<S324>/RM_IMU_heading_TX'

  switch (static_cast<int32_T>(Navigation_CMD_st_520_CAN3)) {
   case 0:
    Temp_1_537_CAN3 = 0.001;
    break;

   case 1:
    // Outputs for Atomic SubSystem: '<S318>/D5.3.4 Steerangle'
    Temp_1_537_CAN3 = truck_adas_B.var_out_ir;

    // End of Outputs for SubSystem: '<S318>/D5.3.4 Steerangle'
    break;

   default:
    Temp_1_537_CAN3 = rtb_Switch1_m;
    break;
  }

  // End of MultiPortSwitch: '<S160>/Multiport Switch4'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Switch: '<S301>/Switch'
    truck_adas_B.Switch_m = (truck_adas_B.ADAS_Stat_st <= 8);
  }

  // MultiPortSwitch: '<S190>/Multiport Switch' incorporates:
  //   Constant: '<S190>/Constant'
  //   Gain: '<S190>/Gain'

  switch (static_cast<int32_T>(Navigation_CMD_st_520_CAN3)) {
   case 0:
    rtb_Gain1_d = 0.001;
    break;

   case 1:
    rtb_Gain1_d = ADAS_vel_cur_520_CAN3;
    break;

   default:
    rtb_Gain1_d = -ADAS_vel_cur_520_CAN3;
    break;
  }

  // End of MultiPortSwitch: '<S190>/Multiport Switch'

  // Sum: '<S190>/Sum4'
  rtb_Gain1_d = rtb_Fcn9_i - rtb_Gain1_d;

  // Gain: '<S224>/Filter Coefficient' incorporates:
  //   Gain: '<S215>/Derivative Gain'
  //   Integrator: '<S216>/Filter'
  //   Sum: '<S216>/SumD'

  truck_adas_B.FilterCoefficient = (0.0 * rtb_Gain1_d -
    truck_adas_X.Filter_CSTATE) * 100.0;

  // Switch: '<S160>/Switch' incorporates:
  //   Constant: '<S160>/Constant'
  //   Constant: '<S160>/Constant1'
  //   Constant: '<S160>/Constant2'
  //   Constant: '<S160>/Constant3'
  //   Constant: '<S160>/Constant4'
  //   Constant: '<S160>/Constant5'
  //   Integrator: '<S221>/Integrator'
  //   Product: '<S160>/Product'
  //   Product: '<S160>/Product1'
  //   Product: '<S160>/Product2'
  //   Sum: '<S230>/Sum'
  //   Switch: '<S160>/Switch1'
  //   Switch: '<S160>/Switch2'

  if (Navigation_CMD_st_520_CAN3 > 0.0) {
    rtb_Fcn9_i = ((rtb_Gain1_d + truck_adas_X.Integrator_CSTATE) +
                  truck_adas_B.FilterCoefficient) * 3.6;

    // MultiPortSwitch: '<S301>/Multiport Switch2' incorporates:
    //   Constant: '<S160>/Constant2'
    //   Constant: '<S301>/Constant4'
    //   Integrator: '<S221>/Integrator'
    //   Product: '<S160>/Product1'
    //   Sum: '<S230>/Sum'
    //   Switch: '<S301>/Switch1'

    if (static_cast<int32_T>(truck_adas_B.Switch_m) == 0) {
      rtb_Switch30_e = truck_adas_B.Gain1;
    } else if (rtb_Switch10 > 3.0) {
      // Outputs for Atomic SubSystem: '<S318>/D5.3.4 Steerangle'
      // Outputs for Atomic SubSystem: '<S324>/D5.3.4.2 deta_oriatation'
      // Switch: '<S301>/Switch1' incorporates:
      //   Gain: '<S329>/Gain'

      rtb_Switch30_e = 20.0 * rtb_UnitDelay;

      // End of Outputs for SubSystem: '<S324>/D5.3.4.2 deta_oriatation'
      // End of Outputs for SubSystem: '<S318>/D5.3.4 Steerangle'
    } else {
      rtb_Switch30_e = 0.0;
    }

    // End of MultiPortSwitch: '<S301>/Multiport Switch2'
    SteerAngle_desire_512_CAN3 = rtb_Switch30_e * 27.6;
    Temp_4_537_CAN3 = rtb_Sum6 * 3.6;
  } else {
    rtb_Fcn9_i = 0.01;
    SteerAngle_desire_512_CAN3 = 0.0001;
    Temp_4_537_CAN3 = 0.0;
  }

  // End of Switch: '<S160>/Switch'

  // Saturate: '<S160>/Saturation'
  if (rtb_Fcn9_i > 25.0) {
    VelSpd_desire_512_CAN3 = 25.0;
  } else if (rtb_Fcn9_i < -25.0) {
    VelSpd_desire_512_CAN3 = -25.0;
  } else {
    VelSpd_desire_512_CAN3 = rtb_Fcn9_i;
  }

  // End of Saturate: '<S160>/Saturation'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // DataTypeConversion: '<S160>/Data Type Conversion'
    ADAS_HeartBeat_512_CAN3 = rtb_DataTypeConversion;

    // DataTypeConversion: '<S160>/Data Type Conversion2'
    ADAS_Stat_st_533_CAN3 = truck_adas_B.ADAS_Stat_st;

    // Outputs for Atomic SubSystem: '<S180>/D3.1.2  VehAcs_IgnKey'
    // Inport: '<S185>/SwitchInput_T15_b'
    VehAcs_IgnKey_st_532_CAN3 = rtb_Switch;

    // End of Outputs for SubSystem: '<S180>/D3.1.2  VehAcs_IgnKey'
  }

  // Outputs for Atomic SubSystem: '<S180>/D3.1.3  VehAcs_Disp__WarnningLamp'
  // If: '<S186>/If' incorporates:
  //   Constant: '<S186>/Constant'
  //   Constant: '<S186>/Constant1'
  //   Constant: '<S187>/Constant'
  //   Inport: '<S188>/In1'
  //   Inport: '<S189>/In1'
  //   RelationalOperator: '<S187>/Compare'

  if (rtmIsMajorTimeStep(truck_adas_M)) {
    rtAction = static_cast<int8_T>(!(rtb_DirectLookupTablenD1 == 5.0));
    truck_adas_DW.If_ActiveSubsystem_im = rtAction;
  } else {
    rtAction = truck_adas_DW.If_ActiveSubsystem_im;
  }

  switch (rtAction) {
   case 0:
    // Outputs for IfAction SubSystem: '<S186>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S188>/Action Port'

    if (rtmIsMajorTimeStep(truck_adas_M) &&
        truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
      WarnningLamp_532_CAN3 = 1.0;
    }

    // End of Outputs for SubSystem: '<S186>/If Action Subsystem1'
    break;

   case 1:
    // Outputs for IfAction SubSystem: '<S186>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S189>/Action Port'

    if (rtmIsMajorTimeStep(truck_adas_M) &&
        truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
      WarnningLamp_532_CAN3 = 0.0;
    }

    // End of Outputs for SubSystem: '<S186>/If Action Subsystem2'
    break;
  }

  // End of If: '<S186>/If'
  // End of Outputs for SubSystem: '<S180>/D3.1.3  VehAcs_Disp__WarnningLamp'

  // Gain: '<S218>/Integral Gain'
  truck_adas_B.IntegralGain = 0.005 * rtb_Gain1_d;
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Chart: '<S182>/D3.3.1 VehStatCo_Stat_Stat' incorporates:
    //   Constant: '<S182>/VehStatCo_Stat_vCrankHi_C'
    //   Constant: '<S182>/VehStatCo_Stat_vCrankLo_C'
    //   Constant: '<S182>/VehStatCo_Stat_vStandby_C'
    //   Constant: '<S182>/Veh_FINISH'
    //   Constant: '<S182>/Veh_READY'
    //   Constant: '<S182>/Veh_RUNNING'
    //   Constant: '<S182>/Veh_STANDBY'
    //   Constant: '<S182>/Veh_START'
    //   Constant: '<S182>/Veh_STOPPING'

    if (truck_adas_DW.is_active_c10_truck_adas == 0U) {
      truck_adas_DW.is_active_c10_truck_adas = 1U;
      truck_adas_DW.is_c10_truck_adas = truck_adas_IN_STANDBY;
      truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_STANDBY);
    } else {
      switch (truck_adas_DW.is_c10_truck_adas) {
       case truck_adas_IN_AFTERRUN:
        if (VehAcs_IgnKey_st_532_CAN3 == 1.0) {
          truck_adas_B.VehStatCo_Stat_finish = 0.0;
          truck_adas_B.VehStatCo_Stat_stop = 0.0;
          truck_adas_DW.is_AFTERRUN = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c10_truck_adas = truck_adas_IN_DRIVE;
          truck_adas_DW.is_DRIVE = truck_a_IN_VehStatCo_Stat_ready;
          truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_READY);
        } else {
          switch (truck_adas_DW.is_AFTERRUN) {
           case truck__IN_VehStatCo_Stat_finish:
            break;

           default:
            // case IN_VehStatCo_Stat_stop:
            if (ADAS_vel_cur_520_CAN3 <= 1.0) {
              truck_adas_B.VehStatCo_Stat_stop = 0.0;
              truck_adas_DW.is_AFTERRUN = truck__IN_VehStatCo_Stat_finish;
              truck_adas_B.VehStatCo_Stat_finish = 1.0;
              truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_FINISH);
            }
            break;
          }
        }
        break;

       case truck_adas_IN_DRIVE:
        if (VehAcs_IgnKey_st_532_CAN3 == 0.0) {
          truck_adas_B.VehStatCo_Stat_run = false;
          truck_adas_B.VehStatCo_Stat_start = false;
          truck_adas_DW.is_DRIVE = truck_adas_IN_NO_ACTIVE_CHILD;
          truck_adas_DW.is_c10_truck_adas = truck_adas_IN_AFTERRUN;
          truck_adas_DW.is_AFTERRUN = truck_ad_IN_VehStatCo_Stat_stop;
          truck_adas_B.VehStatCo_Stat_stop = 1.0;
          truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_STOPPING);
        } else {
          switch (truck_adas_DW.is_DRIVE) {
           case truck_a_IN_VehStatCo_Stat_ready:
            if (ADAS_vel_cur_520_CAN3 > 0.1) {
              truck_adas_DW.is_DRIVE = truck_a_IN_VehStatCo_Stat_start;
              truck_adas_B.VehStatCo_Stat_start = true;
              truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_START);
            }
            break;

           case truck_ada_IN_VehStatCo_Stat_run:
            if (ADAS_vel_cur_520_CAN3 < 2.0) {
              truck_adas_B.VehStatCo_Stat_run = false;
              truck_adas_DW.is_DRIVE = truck_a_IN_VehStatCo_Stat_start;
              truck_adas_B.VehStatCo_Stat_start = true;
              truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_START);
            }
            break;

           default:
            // case IN_VehStatCo_Stat_start:
            if (ADAS_vel_cur_520_CAN3 < 0.1) {
              truck_adas_B.VehStatCo_Stat_start = false;
              truck_adas_DW.is_DRIVE = truck_a_IN_VehStatCo_Stat_ready;
              truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_READY);
            } else {
              if (ADAS_vel_cur_520_CAN3 > 2.0) {
                truck_adas_B.VehStatCo_Stat_start = false;
                truck_adas_DW.is_DRIVE = truck_ada_IN_VehStatCo_Stat_run;
                truck_adas_B.VehStatCo_Stat_run = true;
                truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>
                  (Veh_RUNNING);
              }
            }
            break;
          }
        }
        break;

       default:
        // case IN_STANDBY:
        if (VehAcs_IgnKey_st_532_CAN3 == 1.0) {
          truck_adas_DW.is_c10_truck_adas = truck_adas_IN_DRIVE;
          truck_adas_DW.is_DRIVE = truck_a_IN_VehStatCo_Stat_ready;
          truck_adas_B.VehStatCo_Stat_st = static_cast<uint8_T>(Veh_READY);
        }
        break;
      }
    }

    // End of Chart: '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  }

  // Outputs for Enabled SubSystem: '<S237>/Enabled Subsystem'
  truck_adas_EnabledSubsystem(truck_adas_M, truck_adas_B.VehStatCo_Stat_start,
    &truck_adas_B.Add_l, &truck_adas_DW.EnabledSubsystem);

  // End of Outputs for SubSystem: '<S237>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S237>/Enabled Subsystem1'
  truck_adas_EnabledSubsystem(truck_adas_M, truck_adas_B.VehStatCo_Stat_run,
    &truck_adas_B.Add_i, &truck_adas_DW.EnabledSubsystem1);

  // End of Outputs for SubSystem: '<S237>/Enabled Subsystem1'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Logic: '<S237>/Logical Operator'
    rtb_LogicalOperator = ((truck_adas_B.VehStatCo_Stat_finish != 0.0) ||
      (truck_adas_B.VehStatCo_Stat_stop != 0.0));
  }

  // Outputs for Enabled SubSystem: '<S237>/Enabled Subsystem2'
  truck_adas_EnabledSubsystem(truck_adas_M, rtb_LogicalOperator,
    &truck_adas_B.Add, &truck_adas_DW.EnabledSubsystem2);

  // End of Outputs for SubSystem: '<S237>/Enabled Subsystem2'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[2] == 0) {
    // Product: '<S237>/Product' incorporates:
    //   Constant: '<S237>/VehStatCo_Stat_DT'

    VehStatCo_Stat_tiCrank_532_CAN3 = truck_adas_B.Add_l * VehStatCo_Stat_DT;

    // Product: '<S237>/Product1' incorporates:
    //   Constant: '<S237>/VehStatCo_Stat_DT'

    VehStatCo_Stat_tiNrm_532_CAN3 = truck_adas_B.Add_i * VehStatCo_Stat_DT;

    // Product: '<S237>/Product2' incorporates:
    //   Constant: '<S237>/VehStatCo_Stat_DT'

    VehStatCo_Stat_tiAftRun_533_CAN3 = truck_adas_B.Add * VehStatCo_Stat_DT;
  }

  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // DataTypeConversion: '<S182>/Data Type Conversion'
    VehStatCo_Stat_st_532_CAN3 = truck_adas_B.VehStatCo_Stat_st;

    // Outputs for Atomic SubSystem: '<S183>/D 3.51VehDa_VehSpd_SpdCal'
    // UnitDelay: '<S248>/Unit Delay1'
    rtb_Gain1_d = truck_adas_DW.UnitDelay1_DSTATE_gs;

    // Switch: '<S248>/Switch2' incorporates:
    //   Constant: '<S245>/VehDa_VehSpd_velDfl_C'
    //   RelationalOperator: '<S248>/Relational Operator'
    //   RelationalOperator: '<S248>/Relational Operator1'
    //   Switch: '<S248>/Switch1'

    if (1.38 > rtb_Gain1_d) {
      // Sum: '<S248>/Sum1'
      rtb_DirectLookupTablenD1 = rtb_Gain1_d + truck_adas_ConstB.Product;

      // MinMax: '<S248>/MinMax'
      if (rtb_DirectLookupTablenD1 < 1.38) {
        truck_adas_B.Switch2_g = rtb_DirectLookupTablenD1;
      } else {
        truck_adas_B.Switch2_g = 1.38;
      }

      // End of MinMax: '<S248>/MinMax'
    } else if (rtb_Gain1_d > 1.38) {
      // Sum: '<S248>/Sum' incorporates:
      //   Switch: '<S248>/Switch1'

      rtb_Switch = rtb_Gain1_d - truck_adas_ConstB.Product_n;

      // MinMax: '<S248>/MinMax1' incorporates:
      //   Switch: '<S248>/Switch1'

      if ((1.38 > rtb_Switch) || rtIsNaN(rtb_Switch)) {
        truck_adas_B.Switch2_g = 1.38;
      } else {
        truck_adas_B.Switch2_g = rtb_Switch;
      }

      // End of MinMax: '<S248>/MinMax1'
    } else {
      // Switch: '<S248>/Switch1'
      truck_adas_B.Switch2_g = 1.38;
    }

    // End of Switch: '<S248>/Switch2'

    // UnitDelay: '<S248>/Unit Delay'
    truck_adas_B.UnitDelay_i = truck_adas_DW.UnitDelay_DSTATE_j;

    // End of Outputs for SubSystem: '<S183>/D 3.51VehDa_VehSpd_SpdCal'
  }

  // Outputs for Atomic SubSystem: '<S183>/D 3.51VehDa_VehSpd_SpdCal'
  // Switch: '<S248>/Switch' incorporates:
  //   Constant: '<S245>/VehDa_VehSpd_velMax_C'
  //   RelationalOperator: '<S245>/Relational Operator5'
  //   Switch: '<S245>/Switch2'

  if (truck_adas_B.UnitDelay_i) {
    truck_adas_B.Switch_k = truck_adas_B.Switch2_g;
  } else if (ADAS_vel_cur_520_CAN3 > 50.0) {
    // Switch: '<S245>/Switch2' incorporates:
    //   Constant: '<S245>/VehDa_VehSpd_velMaxDfl_C'

    truck_adas_B.Switch_k = 10.0;
  } else {
    truck_adas_B.Switch_k = ADAS_vel_cur_520_CAN3;
  }

  // End of Switch: '<S248>/Switch'

  // RelationalOperator: '<S245>/Relational Operator3' incorporates:
  //   Constant: '<S245>/VehDa_VehSpd_velThresPla_C'

  truck_adas_B.VehDa_VehSpd_stNPL_mp = (0.0 >= ADAS_vel_cur_520_CAN3);

  // End of Outputs for SubSystem: '<S183>/D 3.51VehDa_VehSpd_SpdCal'

  // Outputs for Atomic SubSystem: '<S183>/ D3.5.2 VehDa_VehSpd_SigFilter'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // UnitDelay: '<S241>/Unit Delay'
    truck_adas_B.UnitDelay_e = truck_adas_DW.UnitDelay_DSTATE_i;
  }

  // Outputs for Atomic SubSystem: '<S241>/VehDa_VehSpd_velPT1'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // UnitDelay: '<S244>/Unit Delay1'
    truck_adas_B.UnitDelay1_a = truck_adas_DW.UnitDelay1_DSTATE_m;
  }

  // Sum: '<S244>/Add1' incorporates:
  //   Product: '<S244>/Product1'
  //   Sum: '<S244>/Add'

  truck_adas_B.Add1 = (truck_adas_B.Switch_k - truck_adas_B.UnitDelay1_a) *
    truck_adas_ConstB.Divide2 + truck_adas_B.UnitDelay1_a;

  // End of Outputs for SubSystem: '<S241>/VehDa_VehSpd_velPT1'

  // RelationalOperator: '<S241>/Relational Operator' incorporates:
  //   Constant: '<S241>/VehDa_VehSpd_velMin_C'

  rtb_DataTypeConversion = (truck_adas_B.Add1 < 0.0);

  // Switch: '<S241>/Switch' incorporates:
  //   Constant: '<S241>/VehDa_VehSpd_velZero'

  if (rtb_DataTypeConversion) {
    VehDa_VehSpd_vel_532_CAN3 = 0.0;
  } else {
    VehDa_VehSpd_vel_532_CAN3 = truck_adas_B.Add1;
  }

  // End of Switch: '<S241>/Switch'

  // Outputs for Atomic SubSystem: '<S241>/VehDa_VehSpd_APT1'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // UnitDelay: '<S243>/Unit Delay1'
    truck_adas_B.UnitDelay1_p = truck_adas_DW.UnitDelay1_DSTATE_k;
  }

  // Sum: '<S243>/Add1' incorporates:
  //   Constant: '<S241>/VehDa_VehSpd_facKm2m'
  //   Product: '<S241>/Divide'
  //   Product: '<S241>/Product'
  //   Product: '<S243>/Product1'
  //   Sum: '<S241>/Subtract'
  //   Sum: '<S243>/Add'

  truck_adas_B.Add1_n = ((truck_adas_B.Switch_k - truck_adas_B.UnitDelay_e) *
    1000.0 / truck_adas_ConstB.Divide1 - truck_adas_B.UnitDelay1_p) *
    truck_adas_ConstB.Divide + truck_adas_B.UnitDelay1_p;

  // End of Outputs for SubSystem: '<S241>/VehDa_VehSpd_APT1'

  // Switch: '<S241>/Switch1' incorporates:
  //   Constant: '<S241>/VehDa_VehSpd_aZero'

  if (rtb_DataTypeConversion) {
    VehDa_VehSpd_a_532_CAN3 = 0.0;
  } else {
    VehDa_VehSpd_a_532_CAN3 = truck_adas_B.Add1_n;
  }

  // End of Switch: '<S241>/Switch1'
  // End of Outputs for SubSystem: '<S183>/ D3.5.2 VehDa_VehSpd_SigFilter'

  // S-Function (IDS_Var_Out): '<S48>/var_out'
  truck_adas_B.var_out_mj= g_rte_InputSignals.VisionObj[0].LonPos_B;

  // Abs: '<S283>/Abs'
  rtb_Switch = std::abs(truck_adas_B.var_out_mj);

  // S-Function (IDS_Var_Out): '<S49>/var_out'
  truck_adas_B.var_out_bu= g_rte_InputSignals.VisionObj[1].LatPos_B;

  // Abs: '<S283>/Abs1'
  rtb_Merge = std::abs(truck_adas_B.var_out_bu);

  // S-Function (IDS_Var_Out): '<S51>/var_out'
  truck_adas_B.var_out_m0= g_rte_InputSignals.VisionObj[2].LatPos_B;

  // Abs: '<S283>/Abs2'
  rtb_UnitDelay = std::abs(truck_adas_B.var_out_m0);

  // S-Function (IDS_Var_Out): '<S54>/var_out'
  truck_adas_B.var_out_bc= g_rte_InputSignals.VisionObj[3].LatPos_B;

  // Abs: '<S283>/Abs3'
  rtb_Switch30_e = std::abs(truck_adas_B.var_out_bc);

  // S-Function (IDS_Var_Out): '<S56>/var_out'
  truck_adas_B.var_out_aj= g_rte_InputSignals.VisionObj[4].LatPos_B;

  // Abs: '<S283>/Abs4'
  rtb_Switch32_m = std::abs(truck_adas_B.var_out_aj);

  // S-Function (IDS_Var_Out): '<S58>/var_out'
  truck_adas_B.var_out_kp= g_rte_InputSignals.VisionObj[5].LatPos_B;

  // Abs: '<S283>/Abs5'
  rtb_Switch34_k = std::abs(truck_adas_B.var_out_kp);

  // S-Function (IDS_Var_Out): '<S60>/var_out'
  truck_adas_B.var_out_gt= g_rte_InputSignals.VisionObj[6].LatPos_B;

  // Abs: '<S283>/Abs6'
  rtb_Switch36_g = std::abs(truck_adas_B.var_out_gt);

  // S-Function (IDS_Var_Out): '<S62>/var_out'
  truck_adas_B.var_out_mn= g_rte_InputSignals.VisionObj[7].LatPos_B;

  // Abs: '<S283>/Abs7'
  rtb_Switch48 = std::abs(truck_adas_B.var_out_mn);

  // S-Function (IDS_Var_Out): '<S65>/var_out'
  truck_adas_B.var_out_oc= g_rte_InputSignals.VisionObj[8].LatPos_B;

  // Abs: '<S283>/Abs8'
  rtb_Switch4_h = std::abs(truck_adas_B.var_out_oc);

  // S-Function (IDS_Var_Out): '<S67>/var_out'
  truck_adas_B.var_out_pr= g_rte_InputSignals.VisionObj[9].LatPos_B;

  // Abs: '<S283>/Abs9'
  rtb_Switch5 = std::abs(truck_adas_B.var_out_pr);

  // S-Function (IDS_Var_Out): '<S47>/var_out'
  truck_adas_B.var_out_ft= g_rte_InputSignals.VisionObj[0].LatPos_B;

  // S-Function (IDS_Var_Out): '<S59>/var_out'
  truck_adas_B.var_out_m0c= g_rte_InputSignals.VisionObj[5].LonPos_B;

  // S-Function (IDS_Var_Out): '<S61>/var_out'
  truck_adas_B.var_out_p5= g_rte_InputSignals.VisionObj[6].LonPos_B;

  // S-Function (IDS_Var_Out): '<S64>/var_out'
  truck_adas_B.var_out_pi= g_rte_InputSignals.VisionObj[7].LonPos_B;

  // S-Function (IDS_Var_Out): '<S66>/var_out'
  truck_adas_B.var_out_j= g_rte_InputSignals.VisionObj[8].LonPos_B;

  // S-Function (IDS_Var_Out): '<S68>/var_out'
  truck_adas_B.var_out_b4= g_rte_InputSignals.VisionObj[9].LonPos_B;

  // S-Function (IDS_Var_Out): '<S50>/var_out'
  truck_adas_B.var_out_l1= g_rte_InputSignals.VisionObj[1].LonPos_B;

  // S-Function (IDS_Var_Out): '<S53>/var_out'
  truck_adas_B.var_out_di= g_rte_InputSignals.VisionObj[2].LonPos_B;

  // S-Function (IDS_Var_Out): '<S55>/var_out'
  truck_adas_B.var_out_ct= g_rte_InputSignals.VisionObj[3].LonPos_B;

  // S-Function (IDS_Var_Out): '<S57>/var_out'
  truck_adas_B.var_out_dic= g_rte_InputSignals.VisionObj[4].LonPos_B;

  // Sqrt: '<S283>/Sqrt' incorporates:
  //   Math: '<S283>/Math Function'
  //   Math: '<S283>/Math Function1'
  //   Sum: '<S283>/Sum'
  //
  //  About '<S283>/Math Function':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function1':
  //   Operator: magnitude^2

  rtb_Fcn9_i = std::sqrt(rtb_Switch * rtb_Switch + truck_adas_B.var_out_ft *
    truck_adas_B.var_out_ft);

  // Switch: '<S283>/Switch4' incorporates:
  //   Constant: '<S283>/Constant5'

  if (!(rtb_Fcn9_i > 0.0)) {
    rtb_Fcn9_i = 200.0;
  }

  // End of Switch: '<S283>/Switch4'

  // Sqrt: '<S283>/Sqrt1' incorporates:
  //   Math: '<S283>/Math Function2'
  //   Math: '<S283>/Math Function3'
  //   Sum: '<S283>/Sum1'
  //
  //  About '<S283>/Math Function2':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function3':
  //   Operator: magnitude^2

  rtb_Gain1_d = std::sqrt(rtb_Merge * rtb_Merge + truck_adas_B.var_out_l1 *
    truck_adas_B.var_out_l1);

  // Switch: '<S283>/Switch5' incorporates:
  //   Constant: '<S283>/Constant6'

  if (!(rtb_Gain1_d > 0.0)) {
    rtb_Gain1_d = 200.0;
  }

  // End of Switch: '<S283>/Switch5'

  // Sqrt: '<S283>/Sqrt2' incorporates:
  //   Math: '<S283>/Math Function4'
  //   Math: '<S283>/Math Function5'
  //   Sum: '<S283>/Sum2'
  //
  //  About '<S283>/Math Function4':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function5':
  //   Operator: magnitude^2

  rtb_DirectLookupTablenD1 = std::sqrt(truck_adas_B.var_out_di *
    truck_adas_B.var_out_di + rtb_UnitDelay * rtb_UnitDelay);

  // Switch: '<S283>/Switch6' incorporates:
  //   Constant: '<S283>/Constant7'

  if (!(rtb_DirectLookupTablenD1 > 0.0)) {
    rtb_DirectLookupTablenD1 = 200.0;
  }

  // End of Switch: '<S283>/Switch6'

  // Sqrt: '<S283>/Sqrt3' incorporates:
  //   Math: '<S283>/Math Function6'
  //   Math: '<S283>/Math Function7'
  //   Sum: '<S283>/Sum3'
  //
  //  About '<S283>/Math Function6':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function7':
  //   Operator: magnitude^2

  rtb_Sum6 = std::sqrt(rtb_Switch30_e * rtb_Switch30_e + truck_adas_B.var_out_ct
                       * truck_adas_B.var_out_ct);

  // Switch: '<S283>/Switch7' incorporates:
  //   Constant: '<S283>/Constant8'

  if (!(rtb_Sum6 > 0.0)) {
    rtb_Sum6 = 200.0;
  }

  // End of Switch: '<S283>/Switch7'

  // Sqrt: '<S283>/Sqrt4' incorporates:
  //   Math: '<S283>/Math Function8'
  //   Math: '<S283>/Math Function9'
  //   Sum: '<S283>/Sum4'
  //
  //  About '<S283>/Math Function8':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function9':
  //   Operator: magnitude^2

  rtb_Switch8_n = std::sqrt(rtb_Switch32_m * rtb_Switch32_m +
    truck_adas_B.var_out_dic * truck_adas_B.var_out_dic);

  // Switch: '<S283>/Switch8' incorporates:
  //   Constant: '<S283>/Constant9'

  if (!(rtb_Switch8_n > 0.0)) {
    rtb_Switch8_n = 200.0;
  }

  // End of Switch: '<S283>/Switch8'

  // Sqrt: '<S283>/Sqrt5' incorporates:
  //   Math: '<S283>/Math Function10'
  //   Math: '<S283>/Math Function11'
  //   Sum: '<S283>/Sum5'
  //
  //  About '<S283>/Math Function10':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function11':
  //   Operator: magnitude^2

  rtb_Switch1_m = std::sqrt(rtb_Switch34_k * rtb_Switch34_k +
    truck_adas_B.var_out_m0c * truck_adas_B.var_out_m0c);

  // Switch: '<S283>/Switch1' incorporates:
  //   Constant: '<S283>/Constant1'

  if (!(rtb_Switch1_m > 0.0)) {
    rtb_Switch1_m = 200.0;
  }

  // End of Switch: '<S283>/Switch1'

  // Sqrt: '<S283>/Sqrt6' incorporates:
  //   Math: '<S283>/Math Function12'
  //   Math: '<S283>/Math Function13'
  //   Sum: '<S283>/Sum6'
  //
  //  About '<S283>/Math Function12':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function13':
  //   Operator: magnitude^2

  rtb_Switch2_m = std::sqrt(rtb_Switch36_g * rtb_Switch36_g +
    truck_adas_B.var_out_p5 * truck_adas_B.var_out_p5);

  // Switch: '<S283>/Switch2' incorporates:
  //   Constant: '<S283>/Constant2'

  if (!(rtb_Switch2_m > 0.0)) {
    rtb_Switch2_m = 200.0;
  }

  // End of Switch: '<S283>/Switch2'

  // Sqrt: '<S283>/Sqrt7' incorporates:
  //   Math: '<S283>/Math Function14'
  //   Math: '<S283>/Math Function15'
  //   Sum: '<S283>/Sum7'
  //
  //  About '<S283>/Math Function14':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function15':
  //   Operator: magnitude^2

  rtb_Switch3_d = std::sqrt(rtb_Switch48 * rtb_Switch48 +
    truck_adas_B.var_out_pi * truck_adas_B.var_out_pi);

  // Switch: '<S283>/Switch3' incorporates:
  //   Constant: '<S283>/Constant3'

  if (!(rtb_Switch3_d > 0.0)) {
    rtb_Switch3_d = 200.0;
  }

  // End of Switch: '<S283>/Switch3'

  // Sqrt: '<S283>/Sqrt8' incorporates:
  //   Math: '<S283>/Math Function16'
  //   Math: '<S283>/Math Function17'
  //   Sum: '<S283>/Sum8'
  //
  //  About '<S283>/Math Function16':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function17':
  //   Operator: magnitude^2

  rtb_Switch9 = std::sqrt(truck_adas_B.var_out_j * truck_adas_B.var_out_j +
    rtb_Switch4_h * rtb_Switch4_h);

  // Switch: '<S283>/Switch9' incorporates:
  //   Constant: '<S283>/Constant4'

  if (!(rtb_Switch9 > 0.0)) {
    rtb_Switch9 = 200.0;
  }

  // End of Switch: '<S283>/Switch9'

  // Sqrt: '<S283>/Sqrt9' incorporates:
  //   Math: '<S283>/Math Function18'
  //   Math: '<S283>/Math Function19'
  //   Sum: '<S283>/Sum9'
  //
  //  About '<S283>/Math Function18':
  //   Operator: magnitude^2
  //
  //  About '<S283>/Math Function19':
  //   Operator: magnitude^2

  rtb_Switch10 = std::sqrt(rtb_Switch5 * rtb_Switch5 + truck_adas_B.var_out_b4 *
    truck_adas_B.var_out_b4);

  // Switch: '<S283>/Switch10' incorporates:
  //   Constant: '<S283>/Constant10'

  if (!(rtb_Switch10 > 0.0)) {
    rtb_Switch10 = 200.0;
  }

  // End of Switch: '<S283>/Switch10'

  // MinMax: '<S283>/Min4'
  if (rtb_Fcn9_i < rtb_Gain1_d) {
    rtb_Gain1_d = rtb_Fcn9_i;
  }

  if (rtb_Gain1_d < rtb_DirectLookupTablenD1) {
    rtb_DirectLookupTablenD1 = rtb_Gain1_d;
  }

  if (rtb_DirectLookupTablenD1 < rtb_Sum6) {
    rtb_Sum6 = rtb_DirectLookupTablenD1;
  }

  if (rtb_Sum6 < rtb_Switch8_n) {
    rtb_Switch8_n = rtb_Sum6;
  }

  if (rtb_Switch8_n < rtb_Switch1_m) {
    rtb_Switch1_m = rtb_Switch8_n;
  }

  if (rtb_Switch1_m < rtb_Switch2_m) {
    rtb_Switch2_m = rtb_Switch1_m;
  }

  if (rtb_Switch2_m < rtb_Switch3_d) {
    rtb_Switch3_d = rtb_Switch2_m;
  }

  if (rtb_Switch3_d < rtb_Switch9) {
    rtb_Switch9 = rtb_Switch3_d;
  }

  if (rtb_Switch9 < rtb_Switch10) {
    rtb_Switch10 = rtb_Switch9;
  }

  // End of MinMax: '<S283>/Min4'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Fcn: '<S284>/Fcn1' incorporates:
    //   Fcn: '<S284>/Fcn2'
    //   Product: '<S284>/Product1'
    //   Product: '<S284>/Product2'
    //   Sum: '<S284>/Sum11'
    //   Sum: '<S284>/Sum12'
    //   UnitDelay: '<S284>/Unit Delay'
    //   UnitDelay: '<S284>/Unit Delay1'
    //   UnitDelay: '<S284>/Unit Delay2'
    //   UnitDelay: '<S284>/Unit Delay3'
    //   UnitDelay: '<S284>/Unit Delay4'

    truck_adas_B.A_d = std::atan((truck_adas_DW.UnitDelay_DSTATE_h -
      truck_adas_DW.UnitDelay1_DSTATE_gt) * std::cos
      (truck_adas_DW.UnitDelay2_DSTATE_a) / (truck_adas_DW.UnitDelay3_DSTATE_g -
      truck_adas_DW.UnitDelay4_DSTATE_k));
  }

  // Gain: '<S284>/Gain5' incorporates:
  //   Constant: '<S284>/R'
  //   Product: '<S284>/Product5'

  rtb_Fcn9_i = rtb_Switch10 / 6.371E+6 * 57.295779513082323;

  // Fcn: '<S284>/Fcn19' incorporates:
  //   Fcn: '<S284>/Fcn22'

  rtb_Switch9 = std::sin(rtb_Fcn9_i);

  // Sum: '<S284>/Sum18' incorporates:
  //   Fcn: '<S284>/Fcn11'
  //   Fcn: '<S284>/Fcn19'
  //   Product: '<S284>/Product11'
  //   Product: '<S284>/Product12'
  //   Product: '<S284>/Product13'

  rtb_DirectLookupTablenD1 = rtb_Switch6_c * rtb_Switch9 * truck_adas_B.A_d +
    rtb_Switch7 * std::cos(rtb_Fcn9_i);

  // Fcn: '<S284>/Fcn20'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  rtb_DirectLookupTablenD1 = std::acos(rtb_DirectLookupTablenD1);
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Fcn: '<S284>/Fcn23'
    truck_adas_B.Fcn23_h = std::sin(truck_adas_B.A_d);
  }

  // Sum: '<S284>/Sum10' incorporates:
  //   Constant: '<S284>/Constant11'
  //   Fcn: '<S284>/Fcn20'

  truck_adas_B.Sum10_o = 90.0 - rtb_DirectLookupTablenD1;

  // Product: '<S284>/Product14' incorporates:
  //   Fcn: '<S284>/Fcn20'
  //   Fcn: '<S284>/Fcn21'
  //   Product: '<S284>/Product15'

  rtb_DirectLookupTablenD1 = truck_adas_B.Fcn23_h * rtb_Switch9 / std::sin
    (rtb_DirectLookupTablenD1);

  // Fcn: '<S284>/Fcn24'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  // Sum: '<S284>/Sum22' incorporates:
  //   Fcn: '<S284>/Fcn24'

  truck_adas_B.Sum22_n = truck_adas_B.var_out_kzu + std::asin
    (rtb_DirectLookupTablenD1);

  // Outputs for Atomic SubSystem: '<S285>/position'
  // Fcn: '<S293>/Fcn9'
  rtb_Fcn9_i = std::sin(rtb_Switch8);

  // Fcn: '<S293>/Fcn12' incorporates:
  //   Fcn: '<S293>/Fcn17'
  //   Product: '<S293>/Product10'
  //   Sum: '<S293>/Sum7'

  rtb_Gain1_d = std::cos(rtb_DirectLookupTablenD1_tmp_0 * std::cos(rtb_Switch8)
    + rtb_DirectLookupTablenD1_tmp_1);

  // Sqrt: '<S293>/Sqrt' incorporates:
  //   Constant: '<S293>/Constant3'
  //   Math: '<S293>/Math Function'
  //   Sum: '<S293>/Sum5'
  //
  //  About '<S293>/Math Function':
  //   Operator: magnitude^2

  rtb_Gain1_d = std::sqrt(1.0 - rtb_Gain1_d * rtb_Gain1_d);

  // Switch: '<S293>/Switch1' incorporates:
  //   Constant: '<S293>/Constant5'
  //   Fcn: '<S293>/Fcn6'
  //   Gain: '<S293>/Gain4'
  //   Sum: '<S293>/Sum9'

  if (tmp > 0.0) {
    // Product: '<S293>/Product7' incorporates:
    //   Constant: '<S293>/Constant2'
    //   Fcn: '<S293>/Fcn10'
    //   Fcn: '<S293>/Fcn7'
    //   LookupNDDirect: '<S290>/Direct Lookup Table (n-D)'
    //   Product: '<S293>/Product4'
    //   Sum: '<S293>/Sum1'
    //
    //  About '<S290>/Direct Lookup Table (n-D)':
    //   1-dimensional Direct Look-Up returning a Scalar,

    rtb_DirectLookupTablenD1 = std::sin(90.0 - truck_adas_B.var_out_gb) *
      rtb_Fcn9_i / std::sin(rtb_Gain1_d);

    // Fcn: '<S293>/Fcn6' incorporates:
    //   Product: '<S293>/Product7'

    if (rtb_DirectLookupTablenD1 > 1.0) {
      rtb_DirectLookupTablenD1 = 1.0;
    } else {
      if (rtb_DirectLookupTablenD1 < -1.0) {
        rtb_DirectLookupTablenD1 = -1.0;
      }
    }

    rtb_Fcn9_i = 57.295779513082323 * std::asin(rtb_DirectLookupTablenD1);
  } else {
    // Product: '<S293>/Product7' incorporates:
    //   Fcn: '<S293>/Fcn10'
    //   Product: '<S293>/Product4'

    rtb_Switch9 = rtb_DirectLookupTablenD1_tmp * rtb_Fcn9_i / std::sin
      (rtb_Gain1_d);

    // Fcn: '<S293>/Fcn6' incorporates:
    //   Product: '<S293>/Product7'

    if (rtb_Switch9 > 1.0) {
      rtb_Switch9 = 1.0;
    } else {
      if (rtb_Switch9 < -1.0) {
        rtb_Switch9 = -1.0;
      }
    }

    rtb_Fcn9_i = 180.0 - 57.295779513082323 * std::asin(rtb_Switch9);
  }

  // End of Switch: '<S293>/Switch1'

  // Sum: '<S293>/Sum10'
  rtb_Fcn9_i = IMU_Heading_531_CAN3 - rtb_Fcn9_i;

  // Abs: '<S293>/Abs'
  rtb_Fcn9_i = std::abs(rtb_Fcn9_i);

  // Switch: '<S293>/Switch' incorporates:
  //   Constant: '<S293>/Constant1'
  //   Constant: '<S293>/Constant6'

  if (rtb_Fcn9_i >= 30.0) {
    rtb_Fcn9_i = 1.0;
  } else {
    rtb_Fcn9_i = -1.0;
  }

  // End of Switch: '<S293>/Switch'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Sum: '<S294>/Sum' incorporates:
    //   Constant: '<S294>/Constant'
    //   UnitDelay: '<S294>/Unit Delay'

    truck_adas_B.Sum = 1.0 + truck_adas_DW.UnitDelay_DSTATE_be;

    // UnitDelay: '<S294>/Unit Delay1'
    truck_adas_B.UnitDelay1 = truck_adas_DW.UnitDelay1_DSTATE_e;
  }

  // Switch: '<S294>/Switch'
  if (rtb_Fcn9_i > 0.0) {
    truck_adas_B.Switch_j = truck_adas_B.Sum;
  } else {
    truck_adas_B.Switch_j = truck_adas_B.UnitDelay1;
  }

  // End of Switch: '<S294>/Switch'
  // End of Outputs for SubSystem: '<S285>/position'

  // Outputs for Atomic SubSystem: '<S286>/OBS'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Delay: '<S296>/Delay'
    truck_adas_B.Delay = truck_adas_DW.Delay_DSTATE;
  }

  // Gain: '<S299>/Gain' incorporates:
  //   LookupNDDirect: '<S297>/Direct Lookup Table (n-D)'
  //
  //  About '<S297>/Direct Lookup Table (n-D)':
  //   1-dimensional Direct Look-Up returning a Scalar,

  rtb_Fcn9_i = 0.017453292519943295 * truck_adas_B.var_out_i;

  // Gain: '<S299>/Gain1'
  rtb_Gain1_d = 0.017453292519943295 * truck_adas_B.Sum10_o;

  // Sum: '<S299>/Sum4' incorporates:
  //   Fcn: '<S299>/Fcn1'
  //   Fcn: '<S299>/Fcn2'
  //   Fcn: '<S299>/Fcn3'
  //   Fcn: '<S299>/Fcn4'
  //   Fcn: '<S299>/Fcn5'
  //   Gain: '<S299>/Gain2'
  //   Gain: '<S299>/Gain3'
  //   LookupNDDirect: '<S297>/Direct Lookup Table (n-D)1'
  //   Product: '<S299>/Product1'
  //   Product: '<S299>/Product2'
  //   Product: '<S299>/Product3'
  //   Sum: '<S299>/Sum3'
  //
  //  About '<S297>/Direct Lookup Table (n-D)1':
  //   1-dimensional Direct Look-Up returning a Scalar,

  rtb_DirectLookupTablenD1 = std::cos(0.017453292519943295 *
    truck_adas_B.var_out_gb - 0.017453292519943295 * truck_adas_B.Sum22_n) *
    (std::cos(rtb_Fcn9_i) * std::cos(rtb_Gain1_d)) + std::sin(rtb_Fcn9_i) * std::
    sin(rtb_Gain1_d);

  // Fcn: '<S299>/Fcn'
  if (rtb_DirectLookupTablenD1 > 1.0) {
    rtb_DirectLookupTablenD1 = 1.0;
  } else {
    if (rtb_DirectLookupTablenD1 < -1.0) {
      rtb_DirectLookupTablenD1 = -1.0;
    }
  }

  // Product: '<S299>/Product' incorporates:
  //   Constant: '<S299>/R'
  //   Fcn: '<S299>/Fcn'

  truck_adas_B.Product_l = 6.371E+6 * std::acos(rtb_DirectLookupTablenD1);

  // End of Outputs for SubSystem: '<S286>/OBS'

  // Switch: '<S288>/Switch' incorporates:
  //   Abs: '<S288>/Abs'
  //   Switch: '<S283>/Switch48'

  if (std::abs(rtb_UnitDelay1_n) > 70.0) {
    // Outputs for Atomic SubSystem: '<S286>/OBS'
    // Switch: '<S296>/Switch' incorporates:
    //   Sum: '<S296>/Sum1'

    if (truck_adas_B.Product_l - truck_adas_B.Delay > 0.0) {
      tmp = truck_adas_B.Delay;
    } else {
      tmp = truck_adas_B.Product_l;
    }

    // End of Switch: '<S296>/Switch'

    // Switch: '<S296>/Switch2' incorporates:
    //   Constant: '<S296>/Constant'
    //   Constant: '<S296>/Constant1'
    //   RelationalOperator: '<S296>/Relational Operator'

    if (tmp <= 5.0) {
      truck_adas_B.Switch_b = rtb_Switch10;
    } else {
      truck_adas_B.Switch_b = 200.0;
    }

    // End of Switch: '<S296>/Switch2'
    // End of Outputs for SubSystem: '<S286>/OBS'
  } else {
    if (!(rtb_Switch32_m > 0.0)) {
      // Switch: '<S283>/Switch48' incorporates:
      //   Constant: '<S283>/Constant48'

      rtb_Switch32_m = 50.0;
    }

    // Switch: '<S283>/Switch46' incorporates:
    //   Constant: '<S283>/Constant46'

    if (!(rtb_Switch5 > 0.0)) {
      rtb_Switch5 = 50.0;
    }

    // End of Switch: '<S283>/Switch46'

    // Switch: '<S283>/Switch44' incorporates:
    //   Constant: '<S283>/Constant44'

    if (!(rtb_Switch4_h > 0.0)) {
      rtb_Switch4_h = 50.0;
    }

    // End of Switch: '<S283>/Switch44'

    // Switch: '<S283>/Switch42' incorporates:
    //   Constant: '<S283>/Constant42'

    if (!(rtb_Switch48 > 0.0)) {
      rtb_Switch48 = 50.0;
    }

    // End of Switch: '<S283>/Switch42'

    // Switch: '<S283>/Switch40' incorporates:
    //   Constant: '<S283>/Constant40'

    if (!(rtb_Switch36_g > 0.0)) {
      rtb_Switch36_g = 50.0;
    }

    // End of Switch: '<S283>/Switch40'

    // Switch: '<S283>/Switch38' incorporates:
    //   Constant: '<S283>/Constant38'

    if (!(rtb_Switch34_k > 0.0)) {
      rtb_Switch34_k = 50.0;
    }

    // End of Switch: '<S283>/Switch38'

    // Switch: '<S283>/Switch36' incorporates:
    //   Constant: '<S283>/Constant36'

    if (!(rtb_Switch30_e > 0.0)) {
      rtb_Switch30_e = 50.0;
    }

    // End of Switch: '<S283>/Switch36'

    // Switch: '<S283>/Switch34' incorporates:
    //   Constant: '<S283>/Constant34'

    if (!(rtb_UnitDelay > 0.0)) {
      rtb_UnitDelay = 50.0;
    }

    // End of Switch: '<S283>/Switch34'

    // Switch: '<S283>/Switch32' incorporates:
    //   Constant: '<S283>/Constant32'

    if (!(rtb_Merge > 0.0)) {
      rtb_Merge = 50.0;
    }

    // End of Switch: '<S283>/Switch32'

    // Switch: '<S283>/Switch30' incorporates:
    //   Constant: '<S283>/Constant30'

    if (!(rtb_Switch > 0.0)) {
      rtb_Switch = 50.0;
    }

    // End of Switch: '<S283>/Switch30'

    // MinMax: '<S283>/Min1'
    if (rtb_Switch32_m < rtb_Switch5) {
      rtb_Switch5 = rtb_Switch32_m;
    }

    if (rtb_Switch5 < rtb_Switch4_h) {
      rtb_Switch4_h = rtb_Switch5;
    }

    if (rtb_Switch4_h < rtb_Switch48) {
      rtb_Switch48 = rtb_Switch4_h;
    }

    if (rtb_Switch48 < rtb_Switch36_g) {
      rtb_Switch36_g = rtb_Switch48;
    }

    if (rtb_Switch36_g < rtb_Switch34_k) {
      rtb_Switch34_k = rtb_Switch36_g;
    }

    if (rtb_Switch34_k < rtb_Switch30_e) {
      rtb_Switch30_e = rtb_Switch34_k;
    }

    if (rtb_Switch30_e < rtb_UnitDelay) {
      rtb_UnitDelay = rtb_Switch30_e;
    }

    if (rtb_UnitDelay < rtb_Merge) {
      rtb_Merge = rtb_UnitDelay;
    }

    if (rtb_Merge < rtb_Switch) {
      rtb_Switch = rtb_Merge;
    }

    // End of MinMax: '<S283>/Min1'

    // Switch: '<S287>/Switch' incorporates:
    //   Constant: '<S287>/Constant'

    if (rtb_Switch > 5.0) {
      truck_adas_B.Switch_b = 150.0;
    } else {
      truck_adas_B.Switch_b = rtb_Switch10;
    }

    // End of Switch: '<S287>/Switch'
  }

  // End of Switch: '<S288>/Switch'

  // Switch: '<S301>/Switch2' incorporates:
  //   Constant: '<S301>/startup'

  if (truck_adas_B.Switch2 != 0.0) {
    // Switch: '<S301>/Switch4' incorporates:
    //   Constant: '<S301>/AEB'
    //   Constant: '<S301>/LFC'

    if (truck_adas_B.Switch2 > 15.0) {
      Driving_state_530_CAN3 = 2.0;
    } else {
      Driving_state_530_CAN3 = 3.0;
    }

    // End of Switch: '<S301>/Switch4'
  } else {
    Driving_state_530_CAN3 = 1.0;
  }

  // End of Switch: '<S301>/Switch2'
  if (rtmIsMajorTimeStep(truck_adas_M) &&
      truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Enabled SubSystem: '<S376>/updown time debouncing' incorporates:
    //   EnablePort: '<S380>/Enable'

    if (truck_adas_ConstB.RelationalOperator2) {
      // Chart: '<S380>/up//down time debouncing1'
      truck_adas_B.Dfp_xxx_mp_4 = false;
    }

    // End of Outputs for SubSystem: '<S376>/updown time debouncing'

    // Outputs for Enabled SubSystem: '<S376>/time debouncing' incorporates:
    //   EnablePort: '<S378>/Enable'

    if (truck_adas_ConstB.RelationalOperator) {
      // Chart: '<S378>/time debouncing1'
      truck_adas_B.Dfp_xxx_mp_4_d = false;
    }

    // End of Outputs for SubSystem: '<S376>/time debouncing'

    // Outputs for Enabled SubSystem: '<S376>/updown event debouncing' incorporates:
    //   EnablePort: '<S379>/Enable'

    if (truck_adas_ConstB.RelationalOperator3) {
      // Switch: '<S379>/Switch3' incorporates:
      //   Switch: '<S379>/Switch'

      truck_adas_B.Switch3 = false;
    }

    // End of Outputs for SubSystem: '<S376>/updown event debouncing'

    // Outputs for Enabled SubSystem: '<S376>/event  debouncing' incorporates:
    //   EnablePort: '<S377>/Enable'

    if (truck_adas_ConstB.RelationalOperator1) {
      // Switch: '<S377>/Switch3' incorporates:
      //   Switch: '<S377>/Switch'

      truck_adas_B.Switch3_k = false;
    }

    // End of Outputs for SubSystem: '<S376>/event  debouncing'

    // Switch: '<S376>/Switch2' incorporates:
    //   Logic: '<S376>/Logical Operator'

    Dfp_mp_532_CAN3 = (truck_adas_B.Dfp_xxx_mp_4 || truck_adas_B.Dfp_xxx_mp_4_d ||
                       truck_adas_B.Switch3 || truck_adas_B.Switch3_k);

    // S-Function (IDS_Var_Out): '<S2>/var_out'
    truck_adas_B.var_out_cp= g_rte_InputSignals.Lane[0].C0;

    // S-Function (IDS_Var_Out): '<S4>/var_out'
    truck_adas_B.var_out_fu= g_rte_InputSignals.ULTRadar.RLS_APA_Width_55;

    // S-Function (IDS_Var_Out): '<S5>/var_out'
    truck_adas_B.var_out_p4= g_rte_InputSignals.ULTRadar.RLS_APA_Distance2_55;

    // S-Function (IDS_Var_Out): '<S6>/var_out'
    truck_adas_B.var_out_a3= g_rte_InputSignals.ULTRadar.RLS_APA_Status_55;

    // S-Function (IDS_Var_Out): '<S7>/var_out'
    truck_adas_B.var_out_is= g_rte_InputSignals.ULTRadar.RRS_APA_Distance1_56;

    // S-Function (IDS_Var_Out): '<S8>/var_out'
    truck_adas_B.var_out_nk= g_rte_InputSignals.ULTRadar.RRS_APA_Peak_56;

    // S-Function (IDS_Var_Out): '<S9>/var_out'
    truck_adas_B.var_out_oq= g_rte_InputSignals.ULTRadar.RRS_APA_Width_56;

    // S-Function (IDS_Var_Out): '<S10>/var_out'
    truck_adas_B.var_out_ht= g_rte_InputSignals.ULTRadar.RRS_APA_Distance2_56;

    // S-Function (IDS_Var_Out): '<S11>/var_out'
    truck_adas_B.var_out_dd= g_rte_InputSignals.ULTRadar.RRS_APA_Status_56;

    // S-Function (IDS_Var_Out): '<S12>/var_out'
    truck_adas_B.var_out_fm= g_rte_InputSignals.ULTRadar.Temperature_57;

    // S-Function (IDS_Var_Out): '<S13>/var_out'
    truck_adas_B.var_out_cl= g_rte_InputSignals.ULTRadar.Emergrncy_brake_58;

    // S-Function (IDS_Var_Out): '<S14>/var_out'
    truck_adas_B.var_out_hpv= g_rte_InputSignals.Lane[0].Range;

    // S-Function (IDS_Var_Out): '<S16>/var_out'
    truck_adas_B.var_out_gtf= Voltage_502_CAN3;

    // S-Function (IDS_Var_Out): '<S17>/var_out'
    truck_adas_B.var_out_fw= MODE_select;

    // S-Function (IDS_Var_Out): '<S19>/var_out'
    truck_adas_B.var_out_hm= g_rte_InputSignals.RadarObj[3].LatPos;

    // S-Function (IDS_Var_Out): '<S20>/var_out'
    truck_adas_B.var_out_jd= g_rte_InputSignals.RadarObj[4].LonPos;

    // S-Function (IDS_Var_Out): '<S21>/var_out'
    truck_adas_B.var_out_mjd= g_rte_InputSignals.RadarObj[4].LatPos;

    // S-Function (IDS_Var_Out): '<S22>/var_out'
    truck_adas_B.var_out_mg= g_rte_InputSignals.RadarObj[3].LonPos;

    // S-Function (IDS_Var_Out): '<S23>/var_out'
    truck_adas_B.var_out_ma= g_rte_InputSignals.RadarObj[2].LonPos;

    // S-Function (IDS_Var_Out): '<S24>/var_out'
    truck_adas_B.var_out_jg= g_rte_InputSignals.RadarObj[2].LatPos;

    // S-Function (IDS_Var_Out): '<S25>/var_out'
    Radar_LatPos_534_CAN3= g_rte_InputSignals.RadarObj[0].LatPos;

    // S-Function (IDS_Var_Out): '<S26>/var_out'
    truck_adas_B.var_out_dik= g_rte_InputSignals.RadarObj[5].LonPos;

    // S-Function (IDS_Var_Out): '<S27>/var_out'
    truck_adas_B.var_out_bu5= g_rte_InputSignals.RadarObj[5].LatPos;

    // S-Function (IDS_Var_Out): '<S28>/var_out'
    truck_adas_B.var_out_lz= g_rte_InputSignals.RadarObj[6].LonPos;

    // S-Function (IDS_Var_Out): '<S29>/var_out'
    truck_adas_B.var_out_gf= g_rte_InputSignals.RadarObj[6].LatPos;

    // S-Function (IDS_Var_Out): '<S30>/var_out'
    truck_adas_B.var_out_ii= g_rte_InputSignals.RadarObj[7].LonPos;

    // S-Function (IDS_Var_Out): '<S31>/var_out'
    truck_adas_B.var_out_i1= g_rte_InputSignals.RadarObj[7].LatPos;

    // S-Function (IDS_Var_Out): '<S32>/var_out'
    truck_adas_B.var_out_c2= g_rte_InputSignals.RadarObj[8].LonPos;

    // S-Function (IDS_Var_Out): '<S33>/var_out'
    truck_adas_B.var_out_fuw= g_rte_InputSignals.RadarObj[8].LatPos;

    // S-Function (IDS_Var_Out): '<S34>/var_out'
    truck_adas_B.var_out_fy= g_rte_InputSignals.RadarObj[9].LonPos;

    // S-Function (IDS_Var_Out): '<S35>/var_out'
    truck_adas_B.var_out_gn= g_rte_InputSignals.RadarObj[9].LatPos;

    // S-Function (IDS_Var_Out): '<S37>/var_out'
    truck_adas_B.var_out_bi= Free_running_CMD_st_502_CAN3;

    // S-Function (IDS_Var_Out): '<S38>/var_out'
    truck_adas_B.var_out_pe= Track_CMD_st_502_CAN3;

    // S-Function (IDS_Var_Out): '<S39>/var_out'
    truck_adas_B.var_out_cc= FPD_CMD_502_CAN3;

    // S-Function (IDS_Var_Out): '<S41>/var_out'
    truck_adas_B.var_out_jw= g_rte_InputSignals.rmgps.RM_IMU_heading_AN;

    // S-Function (IDS_Var_Out): '<S44>/var_out'
    truck_adas_B.var_out_lzi= g_rte_InputSignals.RadarObj[1].LonPos;

    // S-Function (IDS_Var_Out): '<S52>/var_out'
    truck_adas_B.var_out_lj= g_rte_InputSignals.RadarObj[1].LatPos;

    // S-Function (IDS_Var_Out): '<S69>/var_out'
    truck_adas_B.var_out_gbu= g_rte_InputSignals.imu.Pitch_F1;

    // S-Function (IDS_Var_Out): '<S70>/var_out'
    truck_adas_B.var_out_mf= g_rte_InputSignals.imu.Rolling_counter_F4;

    // S-Function (IDS_Var_Out): '<S71>/var_out'
    truck_adas_B.var_out_ay= g_rte_InputSignals.gps.speed;

    // S-Function (IDS_Var_Out): '<S72>/var_out'
    truck_adas_B.var_out_b4c= g_rte_InputSignals.imu.GPSWeek_F4;

    // S-Function (IDS_Var_Out): '<S74>/var_out'
    truck_adas_B.var_out_bv= g_rte_InputSignals.imu.Status1_F4;

    // S-Function (IDS_Var_Out): '<S75>/var_out'
    truck_adas_B.var_out_hy= g_rte_InputSignals.imu.Status2_F4;

    // S-Function (IDS_Var_Out): '<S78>/var_out'
    truck_adas_B.var_out_nq= g_rte_InputSignals.RadarObj[0].Angle;

    // S-Function (IDS_Var_Out): '<S79>/var_out'
    VisionObj_LonVel_521_CAN3= g_rte_InputSignals.VisionObj[0].LonVel;

    // S-Function (IDS_Var_Out): '<S80>/var_out'
    VisionObj_Width_521_CAN3= g_rte_InputSignals.VisionObj[0].Width;

    // S-Function (IDS_Var_Out): '<S81>/var_out'
    Vision_Length_521_CAN3= g_rte_InputSignals.VisionObj[0].Length;

    // S-Function (IDS_Var_Out): '<S82>/var_out'
    truck_adas_B.var_out_nw= g_rte_InputSignals.Lane[0].Start;

    // S-Function (IDS_Var_Out): '<S83>/var_out'
    truck_adas_B.var_out_b2= g_rte_InputSignals.Lane[1].C0;

    // S-Function (IDS_Var_Out): '<S84>/var_out'
    truck_adas_B.var_out_an= g_rte_InputSignals.imu.Ve_F3;

    // S-Function (IDS_Var_Out): '<S85>/var_out'
    truck_adas_B.var_out_dw= g_rte_InputSignals.imu.Vn_F3;

    // S-Function (IDS_Var_Out): '<S86>/var_out'
    truck_adas_B.var_out_iw= g_rte_InputSignals.imu.Vu_F3;

    // S-Function (IDS_Var_Out): '<S87>/var_out'
    truck_adas_B.var_out_oe= g_rte_InputSignals.imu.Altitude_F5;

    // S-Function (IDS_Var_Out): '<S88>/var_out'
    truck_adas_B.var_out_n5= g_rte_InputSignals.imu.Baseline_F5;

    // S-Function (IDS_Var_Out): '<S89>/var_out'
    truck_adas_B.var_out_f0= g_rte_InputSignals.imu.NSV1_F5;

    // S-Function (IDS_Var_Out): '<S90>/var_out'
    truck_adas_B.var_out_d3= g_rte_InputSignals.imu.NSV2_F5;

    // S-Function (IDS_Var_Out): '<S92>/var_out'
    truck_adas_B.var_out_it= g_rte_InputSignals.Lane[2].C0;

    // S-Function (IDS_Var_Out): '<S93>/var_out'
    truck_adas_B.var_out_ayj= g_rte_InputSignals.gps.course;

    // S-Function (IDS_Var_Out): '<S94>/var_out'
    truck_adas_B.var_out_ol= g_rte_InputSignals.Lane[3].C0;

    // S-Function (IDS_Var_Out): '<S95>/var_out'
    truck_adas_B.var_out_mfk= g_rte_InputSignals.Lane[0].C1;

    // S-Function (IDS_Var_Out): '<S96>/var_out'
    truck_adas_B.var_out_je= FPD_CMD_502_CAN3;

    // S-Function (IDS_Var_Out): '<S97>/var_out'
    truck_adas_B.var_out_cg= Vel_No_502_CAN3;

    // S-Function (IDS_Var_Out): '<S98>/var_out'
    truck_adas_B.var_out_oeu= Parking_No_502_CAN3;

    // S-Function (IDS_Var_Out): '<S99>/var_out'
    truck_adas_B.var_out_p5p= Longitude_503_CAN3;

    // S-Function (IDS_Var_Out): '<S100>/var_out'
    truck_adas_B.var_out_iv= Lattitude_503_CAN3;

    // S-Function (IDS_Var_Out): '<S104>/var_out'
    truck_adas_B.var_out_ht1= g_rte_InputSignals.imu. Roll_F1;

    // S-Function (IDS_Var_Out): '<S106>/var_out'
    truck_adas_B.var_out_jo= g_rte_InputSignals.VisionObj[0].Obsttc;

    // S-Function (IDS_Var_Out): '<S115>/var_out'
    truck_adas_B.var_out_bg= g_rte_InputSignals.gps.latitude;

    // S-Function (IDS_Var_Out): '<S126>/var_out'
    truck_adas_B.var_out_in= g_rte_InputSignals.gps.longitude;

    // S-Function (IDS_Var_Out): '<S127>/var_out'
    truck_adas_B.var_out_ddt= g_rte_InputSignals.Lane[0].C2;

    // S-Function (IDS_Var_Out): '<S128>/var_out'
    Radar_LonPos_534_CAN3= g_rte_InputSignals.RadarObj[0].LonPos;

    // S-Function (IDS_Var_Out): '<S129>/var_out'
    FLC_UPA_Distance_51_535_CAN3=
      g_rte_InputSignals.ULTRadar.FLC_UPA_Distance_51;

    // S-Function (IDS_Var_Out): '<S130>/var_out'
    FLC_UPA_Status_51_535_CAN3= g_rte_InputSignals.ULTRadar.FLC_UPA_Status_51;

    // S-Function (IDS_Var_Out): '<S131>/var_out'
    FLM_UPA_Distance_51_535_CAN3=
      g_rte_InputSignals.ULTRadar.FLM_UPA_Distance_51;

    // S-Function (IDS_Var_Out): '<S132>/var_out'
    FLM_UPA_Status_51_535_CAN3= g_rte_InputSignals.ULTRadar.FLM_UPA_Status_51;

    // S-Function (IDS_Var_Out): '<S133>/var_out'
    FRC_UPA_Distance_51_535_CAN3=
      g_rte_InputSignals.ULTRadar.FRC_UPA_Distance_51;

    // S-Function (IDS_Var_Out): '<S134>/var_out'
    FRC_UPA_Status_51_535_CAN3= g_rte_InputSignals.ULTRadar.FRC_UPA_Status_51;

    // S-Function (IDS_Var_Out): '<S135>/var_out'
    FRM_UPA_Distance_51_535_CAN3=
      g_rte_InputSignals.ULTRadar.FRM_UPA_Distance_51;

    // S-Function (IDS_Var_Out): '<S136>/var_out'
    FRM_UPA_Status_51_535_CAN3= g_rte_InputSignals.ULTRadar.FRM_UPA_Status_51;

    // S-Function (IDS_Var_Out): '<S137>/var_out'
    truck_adas_B.var_out_d0r= Steerangle_MCU_502_CAN3;

    // S-Function (IDS_Var_Out): '<S138>/var_out'
    truck_adas_B.var_out_ok= g_rte_InputSignals.ULTRadar.RLC_UPA_Distance_52;

    // S-Function (IDS_Var_Out): '<S139>/var_out'
    truck_adas_B.var_out_ba= g_rte_InputSignals.ULTRadar.RLC_UPA_Status_52;

    // S-Function (IDS_Var_Out): '<S140>/var_out'
    truck_adas_B.var_out_li= g_rte_InputSignals.ULTRadar.RLM_UPA_Distance_52;

    // S-Function (IDS_Var_Out): '<S141>/var_out'
    truck_adas_B.var_out_pb= g_rte_InputSignals.ULTRadar.RLM_UPA_Status_52;

    // S-Function (IDS_Var_Out): '<S142>/var_out'
    truck_adas_B.var_out_bj= g_rte_InputSignals.ULTRadar.RRM_UPA_Distance_52;

    // S-Function (IDS_Var_Out): '<S143>/var_out'
    truck_adas_B.var_out_dv= g_rte_InputSignals.ULTRadar.RRM_UPA_Status_52;

    // S-Function (IDS_Var_Out): '<S144>/var_out'
    truck_adas_B.var_out_id= g_rte_InputSignals.ULTRadar.RRC_UPA_Distance_52;

    // S-Function (IDS_Var_Out): '<S145>/var_out'
    truck_adas_B.var_out_fj= g_rte_InputSignals.ULTRadar.RRC_UPA_Status_52;

    // S-Function (IDS_Var_Out): '<S146>/var_out'
    truck_adas_B.var_out_ll= g_rte_InputSignals.ULTRadar.FRS_APA_Distance1_53;

    // S-Function (IDS_Var_Out): '<S147>/var_out'
    truck_adas_B.var_out_ml= g_rte_InputSignals.ULTRadar.FRS_APA_Peak_53;

    // S-Function (IDS_Var_Out): '<S149>/var_out'
    truck_adas_B.var_out_az= g_rte_InputSignals.ULTRadar.FRS_APA_Width_53;

    // S-Function (IDS_Var_Out): '<S150>/var_out'
    truck_adas_B.var_out_dj= g_rte_InputSignals.ULTRadar.FRS_APA_Distance2_53;

    // S-Function (IDS_Var_Out): '<S151>/var_out'
    truck_adas_B.var_out_fh= g_rte_InputSignals.ULTRadar.FRS_APA_Status_53;

    // S-Function (IDS_Var_Out): '<S152>/var_out'
    truck_adas_B.var_out_mh= g_rte_InputSignals.ULTRadar.FLS_APA_Distance1_54;

    // S-Function (IDS_Var_Out): '<S153>/var_out'
    truck_adas_B.var_out_oy= g_rte_InputSignals.ULTRadar.FLS_APA_Peak_54;

    // S-Function (IDS_Var_Out): '<S154>/var_out'
    truck_adas_B.var_out_fhv= g_rte_InputSignals.ULTRadar.FLS_APA_Width_54;

    // S-Function (IDS_Var_Out): '<S155>/var_out'
    truck_adas_B.var_out_nqm= g_rte_InputSignals.ULTRadar.FLS_APA_Distance2_54;

    // S-Function (IDS_Var_Out): '<S156>/var_out'
    truck_adas_B.var_out_ji= g_rte_InputSignals.ULTRadar.FLS_APA_Status_54;

    // S-Function (IDS_Var_Out): '<S157>/var_out'
    truck_adas_B.var_out_jm= g_rte_InputSignals.ULTRadar.RLS_APA_Distance1_55;

    // S-Function (IDS_Var_Out): '<S158>/var_out'
    truck_adas_B.var_out_nz= g_rte_InputSignals.ULTRadar.RLS_APA_Peak_55;
  }

  if (rtmIsMajorTimeStep(truck_adas_M)) {
    if (rtmIsMajorTimeStep(truck_adas_M) &&
        truck_adas_M->Timing.TaskCounters.TID[1] == 0) {
      // Update for UnitDelay: '<S163>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE = truck_adas_B.Switch_d;

      // Update for UnitDelay: '<S282>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_b = truck_adas_B.Switch2;

      // Update for UnitDelay: '<S267>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_e = truck_adas_B.Sum22;

      // Update for UnitDelay: '<S267>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE = truck_adas_B.var_out_kzu;

      // Update for UnitDelay: '<S267>/Unit Delay2'
      truck_adas_DW.UnitDelay2_DSTATE = truck_adas_B.Sum10;

      // Update for UnitDelay: '<S267>/Unit Delay3'
      truck_adas_DW.UnitDelay3_DSTATE = truck_adas_B.Sum10;

      // Update for UnitDelay: '<S267>/Unit Delay4'
      truck_adas_DW.UnitDelay4_DSTATE = truck_adas_B.var_out_c;

      // Update for Atomic SubSystem: '<S268>/position'
      // Update for UnitDelay: '<S275>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_f = truck_adas_B.Sum_g;

      // Update for UnitDelay: '<S275>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE_f = truck_adas_B.Sum_g;

      // End of Update for SubSystem: '<S268>/position'

      // Update for Atomic SubSystem: '<S269>/Obsvision '
      // Update for Delay: '<S277>/Delay'
      truck_adas_DW.Delay_DSTATE_l = truck_adas_B.Product_b;

      // End of Update for SubSystem: '<S269>/Obsvision '

      // Update for Memory: '<S288>/Memory'
      truck_adas_DW.Memory_PreviousInput = truck_adas_B.Switch_b;

      // Update for UnitDelay: '<S163>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE_g = truck_adas_B.Switch_fk;

      // Update for Atomic SubSystem: '<S163>/D5.2  RP'
      // Update for Atomic SubSystem: '<S302>/D5.2.2   judgement'
      // Update for UnitDelay: '<S312>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_bf = truck_adas_B.Product_i;

      // End of Update for SubSystem: '<S302>/D5.2.2   judgement'
      // End of Update for SubSystem: '<S163>/D5.2  RP'

      // Update for Atomic SubSystem: '<S305>/D5.5.1 Accelation'
      // Update for UnitDelay: '<S337>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_a = truck_adas_B.var_out_lh;

      // End of Update for SubSystem: '<S305>/D5.5.1 Accelation'

      // Update for Atomic SubSystem: '<S309>/D5.9.1 Accelation'
      // Update for UnitDelay: '<S371>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_l = truck_adas_B.var_out_lh;

      // End of Update for SubSystem: '<S309>/D5.9.1 Accelation'

      // Update for Atomic SubSystem: '<S306>/D5.6.2   judgement deta_S'
      // Update for UnitDelay: '<S343>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_d = truck_adas_B.Product;

      // End of Update for SubSystem: '<S306>/D5.6.2   judgement deta_S'

      // Update for Atomic SubSystem: '<S183>/D 3.51VehDa_VehSpd_SpdCal'
      // Update for UnitDelay: '<S248>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE_gs = truck_adas_B.Switch_k;

      // Update for UnitDelay: '<S248>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_j = truck_adas_B.VehDa_VehSpd_stNPL_mp;

      // End of Update for SubSystem: '<S183>/D 3.51VehDa_VehSpd_SpdCal'

      // Update for Atomic SubSystem: '<S183>/ D3.5.2 VehDa_VehSpd_SigFilter'
      // Update for UnitDelay: '<S241>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_i = truck_adas_B.Switch_k;

      // Update for Atomic SubSystem: '<S241>/VehDa_VehSpd_velPT1'
      // Update for UnitDelay: '<S244>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE_m = truck_adas_B.Add1;

      // End of Update for SubSystem: '<S241>/VehDa_VehSpd_velPT1'

      // Update for Atomic SubSystem: '<S241>/VehDa_VehSpd_APT1'
      // Update for UnitDelay: '<S243>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE_k = truck_adas_B.Add1_n;

      // End of Update for SubSystem: '<S241>/VehDa_VehSpd_APT1'
      // End of Update for SubSystem: '<S183>/ D3.5.2 VehDa_VehSpd_SigFilter'

      // Update for UnitDelay: '<S284>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_h = truck_adas_B.Sum22_n;

      // Update for UnitDelay: '<S284>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE_gt = truck_adas_B.var_out_kzu;

      // Update for UnitDelay: '<S284>/Unit Delay2'
      truck_adas_DW.UnitDelay2_DSTATE_a = truck_adas_B.Sum10_o;

      // Update for UnitDelay: '<S284>/Unit Delay3'
      truck_adas_DW.UnitDelay3_DSTATE_g = truck_adas_B.Sum10_o;

      // Update for UnitDelay: '<S284>/Unit Delay4'
      truck_adas_DW.UnitDelay4_DSTATE_k = truck_adas_B.var_out_c;

      // Update for Atomic SubSystem: '<S285>/position'
      // Update for UnitDelay: '<S294>/Unit Delay'
      truck_adas_DW.UnitDelay_DSTATE_be = truck_adas_B.Sum;

      // Update for UnitDelay: '<S294>/Unit Delay1'
      truck_adas_DW.UnitDelay1_DSTATE_e = truck_adas_B.Sum;

      // End of Update for SubSystem: '<S285>/position'

      // Update for Atomic SubSystem: '<S286>/OBS'
      // Update for Delay: '<S296>/Delay'
      truck_adas_DW.Delay_DSTATE = truck_adas_B.Product_l;

      // End of Update for SubSystem: '<S286>/OBS'
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(truck_adas_M)) {
    rt_ertODEUpdateContinuousStates(&truck_adas_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++truck_adas_M->Timing.clockTick0;
    truck_adas_M->Timing.t[0] = rtsiGetSolverStopTime(&truck_adas_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      truck_adas_M->Timing.clockTick1++;
    }

    rate_scheduler();
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void truck_adas_derivatives(void)
{
  XDot_truck_adas_T *_rtXdot;
  _rtXdot = ((XDot_truck_adas_T *) truck_adas_M->derivs);

  // Derivatives for Integrator: '<S221>/Integrator'
  _rtXdot->Integrator_CSTATE = truck_adas_B.IntegralGain;

  // Derivatives for Integrator: '<S216>/Filter'
  _rtXdot->Filter_CSTATE = truck_adas_B.FilterCoefficient;
}

// Model initialize function
void truck_adas_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize real-time model
  (void) memset((void *)truck_adas_M, 0,
                sizeof(RT_MODEL_truck_adas_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&truck_adas_M->solverInfo,
                          &truck_adas_M->Timing.simTimeStep);
    rtsiSetTPtr(&truck_adas_M->solverInfo, &rtmGetTPtr(truck_adas_M));
    rtsiSetStepSizePtr(&truck_adas_M->solverInfo,
                       &truck_adas_M->Timing.stepSize0);
    rtsiSetdXPtr(&truck_adas_M->solverInfo, &truck_adas_M->derivs);
    rtsiSetContStatesPtr(&truck_adas_M->solverInfo, (real_T **)
                         &truck_adas_M->contStates);
    rtsiSetNumContStatesPtr(&truck_adas_M->solverInfo,
      &truck_adas_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&truck_adas_M->solverInfo,
      &truck_adas_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&truck_adas_M->solverInfo,
      &truck_adas_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&truck_adas_M->solverInfo,
      &truck_adas_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&truck_adas_M->solverInfo, (&rtmGetErrorStatus
      (truck_adas_M)));
    rtsiSetRTModelPtr(&truck_adas_M->solverInfo, truck_adas_M);
  }

  rtsiSetSimTimeStep(&truck_adas_M->solverInfo, MAJOR_TIME_STEP);
  truck_adas_M->intgData.y = truck_adas_M->odeY;
  truck_adas_M->intgData.f[0] = truck_adas_M->odeF[0];
  truck_adas_M->intgData.f[1] = truck_adas_M->odeF[1];
  truck_adas_M->intgData.f[2] = truck_adas_M->odeF[2];
  truck_adas_M->contStates = ((X_truck_adas_T *) &truck_adas_X);
  rtsiSetSolverData(&truck_adas_M->solverInfo, (void *)&truck_adas_M->intgData);
  rtsiSetSolverName(&truck_adas_M->solverInfo,"ode3");
  rtmSetTPtr(truck_adas_M, &truck_adas_M->Timing.tArray[0]);
  truck_adas_M->Timing.stepSize0 = 0.05;

  // block I/O
  (void) memset(((void *) &truck_adas_B), 0,
                sizeof(B_truck_adas_T));

  // states (continuous)
  {
    (void) memset((void *)&truck_adas_X, 0,
                  sizeof(X_truck_adas_T));
  }

  // states (dwork)
  (void) memset((void *)&truck_adas_DW, 0,
                sizeof(DW_truck_adas_T));

  // Start for If: '<S319>/If'
  truck_adas_DW.If_ActiveSubsystem = -1;

  // Start for If: '<S318>/If'
  truck_adas_DW.If_ActiveSubsystem_i = -1;

  // Start for If: '<S348>/If'
  truck_adas_DW.If_ActiveSubsystem_o = -1;

  // Start for If: '<S349>/If'
  truck_adas_DW.If_ActiveSubsystem_p = -1;

  // Start for If: '<S304>/If'
  truck_adas_DW.If_ActiveSubsystem_f = -1;

  // Start for If: '<S308>/If'
  truck_adas_DW.If_ActiveSubsystem_m = -1;

  // Start for Atomic SubSystem: '<S180>/D3.1.3  VehAcs_Disp__WarnningLamp'
  // Start for If: '<S186>/If'
  truck_adas_DW.If_ActiveSubsystem_im = -1;

  // End of Start for SubSystem: '<S180>/D3.1.3  VehAcs_Disp__WarnningLamp'

  // InitializeConditions for Integrator: '<S221>/Integrator'
  truck_adas_X.Integrator_CSTATE = 0.0;

  // InitializeConditions for Integrator: '<S216>/Filter'
  truck_adas_X.Filter_CSTATE = 0.0;

  // SystemInitialize for Chart: '<S300>/VehStatCo_Stat_Stat'
  truck_adas_DW.is_APA_TF = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_Fianl = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_Fianl1 = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_TF = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_active_c2_truck_adas = 0U;
  truck_adas_DW.is_c2_truck_adas = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_B.ADAS_Stat_st = 0U;

  // SystemInitialize for Atomic SubSystem: '<S305>/D5.5.1 Accelation'
  // InitializeConditions for UnitDelay: '<S337>/Unit Delay'
  truck_adas_DW.UnitDelay_DSTATE_a = 1.0;

  // End of SystemInitialize for SubSystem: '<S305>/D5.5.1 Accelation'

  // SystemInitialize for Atomic SubSystem: '<S309>/D5.9.1 Accelation'
  // InitializeConditions for UnitDelay: '<S371>/Unit Delay'
  truck_adas_DW.UnitDelay_DSTATE_l = 1.0;

  // End of SystemInitialize for SubSystem: '<S309>/D5.9.1 Accelation'

  // SystemInitialize for Atomic SubSystem: '<S307>/D5.7.4 Steerangle_APA'
  // SystemInitialize for Atomic SubSystem: '<S350>/D5.7.4.3 FPD_steerangle_APA' 
  // SystemInitialize for Chart: '<S364>/mode 2'
  truck_adas_DW.is_Left = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_Right = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_active_c12_truck_adas = 0U;
  truck_adas_DW.is_c12_truck_adas = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.s = 0.0;
  truck_adas_B.SteerAngle_desire = 0.0;

  // End of SystemInitialize for SubSystem: '<S350>/D5.7.4.3 FPD_steerangle_APA' 
  // End of SystemInitialize for SubSystem: '<S307>/D5.7.4 Steerangle_APA'

  // SystemInitialize for Chart: '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  truck_adas_DW.is_AFTERRUN = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_DRIVE = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_DW.is_active_c10_truck_adas = 0U;
  truck_adas_DW.is_c10_truck_adas = truck_adas_IN_NO_ACTIVE_CHILD;
  truck_adas_B.VehStatCo_Stat_st = 0U;
  truck_adas_B.VehStatCo_Stat_start = false;
  truck_adas_B.VehStatCo_Stat_run = false;
  truck_adas_B.VehStatCo_Stat_finish = 0.0;
  truck_adas_B.VehStatCo_Stat_stop = 0.0;

  // SystemInitialize for Enabled SubSystem: '<S237>/Enabled Subsystem'
  truck_ada_EnabledSubsystem_Init(&truck_adas_DW.EnabledSubsystem);

  // End of SystemInitialize for SubSystem: '<S237>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S237>/Enabled Subsystem1'
  truck_ada_EnabledSubsystem_Init(&truck_adas_DW.EnabledSubsystem1);

  // End of SystemInitialize for SubSystem: '<S237>/Enabled Subsystem1'

  // SystemInitialize for Enabled SubSystem: '<S237>/Enabled Subsystem2'
  truck_ada_EnabledSubsystem_Init(&truck_adas_DW.EnabledSubsystem2);

  // End of SystemInitialize for SubSystem: '<S237>/Enabled Subsystem2'

  // SystemInitialize for Enabled SubSystem: '<S376>/updown time debouncing'
  // SystemInitialize for Chart: '<S380>/up//down time debouncing1'
  truck_adas_B.Dfp_xxx_mp_4 = false;

  // End of SystemInitialize for SubSystem: '<S376>/updown time debouncing'

  // SystemInitialize for Enabled SubSystem: '<S376>/time debouncing'
  // SystemInitialize for Chart: '<S378>/time debouncing1'
  truck_adas_B.Dfp_xxx_mp_4_d = false;

  // End of SystemInitialize for SubSystem: '<S376>/time debouncing'
}

// Model terminate function
void truck_adas_terminate(void)
{
  // (no terminate code required)
}

//
// File trailer for generated code.
//
// [EOF]
//
