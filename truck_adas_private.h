//
// File: truck_adas_private.h
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
#ifndef RTW_HEADER_truck_adas_private_h_
#define RTW_HEADER_truck_adas_private_h_
#include "rtwtypes.h"
#include "truck_adas.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

// Imported (extern) block signals
extern real_T Navigation_CMD_st_520_CAN3;// '<S3>/var_out'
extern real_T Obj_distance_vision_534_CAN3;// '<S266>/Min4'
extern real_T IMU_Heading_531_CAN3;    // '<S63>/var_out'
extern real_T ADAS_vel_cur_520_CAN3;   // '<S148>/var_out'
extern real_T Temp_3_537_CAN3;         // '<S160>/Gain'
extern real_T Deta_530_CAN3;           // '<S160>/Multiport Switch'
extern real_T Temp_2_537_CAN3;         // '<S160>/Multiport Switch1'
extern real_T ADAS_work_st_512_CAN3;   // '<S160>/Multiport Switch2'
extern real_T Obs_533_CAN3;            // '<S160>/Multiport Switch3'
extern real_T Temp_1_537_CAN3;         // '<S160>/Multiport Switch4'
extern real_T VelSpd_desire_512_CAN3;  // '<S160>/Saturation'
extern real_T SteerAngle_desire_512_CAN3;// '<S160>/Switch1'
extern real_T Temp_4_537_CAN3;         // '<S160>/Switch2'
extern real_T ADAS_HeartBeat_512_CAN3; // '<S160>/Data Type Conversion'
extern real_T ADAS_Stat_st_533_CAN3;   // '<S160>/Data Type Conversion2'
extern real_T VehStatCo_Stat_tiCrank_532_CAN3;// '<S237>/Product'
extern real_T VehStatCo_Stat_tiNrm_532_CAN3;// '<S237>/Product1'
extern real_T VehStatCo_Stat_tiAftRun_533_CAN3;// '<S237>/Product2'
extern real_T VehStatCo_Stat_st_532_CAN3;// '<S182>/Data Type Conversion'
extern real_T Driving_state_530_CAN3;  // '<S301>/Switch2'
extern real_T Dfp_mp_532_CAN3;         // '<S376>/Switch2'
extern real_T Radar_LatPos_534_CAN3;   // '<S25>/var_out'
extern real_T VisionObj_LonVel_521_CAN3;// '<S79>/var_out'
extern real_T VisionObj_Width_521_CAN3;// '<S80>/var_out'
extern real_T Vision_Length_521_CAN3;  // '<S81>/var_out'
extern real_T Radar_LonPos_534_CAN3;   // '<S128>/var_out'
extern real_T FLC_UPA_Distance_51_535_CAN3;// '<S129>/var_out'
extern real_T FLC_UPA_Status_51_535_CAN3;// '<S130>/var_out'
extern real_T FLM_UPA_Distance_51_535_CAN3;// '<S131>/var_out'
extern real_T FLM_UPA_Status_51_535_CAN3;// '<S132>/var_out'
extern real_T FRC_UPA_Distance_51_535_CAN3;// '<S133>/var_out'
extern real_T FRC_UPA_Status_51_535_CAN3;// '<S134>/var_out'
extern real_T FRM_UPA_Distance_51_535_CAN3;// '<S135>/var_out'
extern real_T FRM_UPA_Status_51_535_CAN3;// '<S136>/var_out'
extern real_T Time_difference_530_CAN3;// '<S337>/Sum1'
extern real_T VehDa_VehSpd_vel_532_CAN3;// '<S241>/Switch'
extern real_T VehDa_VehSpd_a_532_CAN3; // '<S241>/Switch1'
extern real_T WarnningLamp_532_CAN3;   // '<S186>/Merge'
extern real_T VehAcs_IgnKey_st_532_CAN3;// '<S185>/SwitchInput_T15_b'

#include "in_out_signal.h"

extern void truck_ada_EnabledSubsystem_Init(DW_EnabledSubsystem_truck_ada_T
  *localDW);
extern void truck_ad_EnabledSubsystem_Reset(DW_EnabledSubsystem_truck_ada_T
  *localDW);
extern void truck__EnabledSubsystem_Disable(DW_EnabledSubsystem_truck_ada_T
  *localDW);
extern void truck_adas_EnabledSubsystem(RT_MODEL_truck_adas_T * const
  truck_adas_M, boolean_T rtu_Enable, real_T *rty_Out1,
  DW_EnabledSubsystem_truck_ada_T *localDW);

// private model entry point functions
extern void truck_adas_derivatives(void);

#endif                                 // RTW_HEADER_truck_adas_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
