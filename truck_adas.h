//
// File: truck_adas.h
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
#ifndef RTW_HEADER_truck_adas_h_
#define RTW_HEADER_truck_adas_h_
#include <cmath>
#include <string.h>
#ifndef truck_adas_COMMON_INCLUDES_
# define truck_adas_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 // truck_adas_COMMON_INCLUDES_

#include "truck_adas_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block states (default storage) for system '<S237>/Enabled Subsystem'
typedef struct {
  real_T UnitDelay_DSTATE;             // '<S238>/Unit Delay'
  boolean_T EnabledSubsystem_MODE;     // '<S237>/Enabled Subsystem'
} DW_EnabledSubsystem_truck_ada_T;

// Block signals (default storage)
typedef struct {
  real_T var_out;                      // '<S91>/var_out'
  real_T var_out_k;                    // '<S15>/var_out'
  real_T VehMot_AccPed_vFltOld_mp;     // '<S282>/Unit Delay'
  real_T var_out_h;                    // '<S18>/var_out'
  real_T A;                            // '<S267>/Fcn1'
  real_T var_out_m;                    // '<S36>/var_out'
  real_T var_out_o;                    // '<S43>/var_out'
  real_T var_out_ku;                   // '<S107>/var_out'
  real_T var_out_f;                    // '<S108>/var_out'
  real_T var_out_g;                    // '<S110>/var_out'
  real_T var_out_d;                    // '<S109>/var_out'
  real_T var_out_a;                    // '<S111>/var_out'
  real_T var_out_op;                   // '<S112>/var_out'
  real_T var_out_my;                   // '<S113>/var_out'
  real_T var_out_p;                    // '<S114>/var_out'
  real_T var_out_hp;                   // '<S116>/var_out'
  real_T var_out_dc;                   // '<S117>/var_out'
  real_T var_out_gc;                   // '<S118>/var_out'
  real_T var_out_kc;                   // '<S119>/var_out'
  real_T var_out_l;                    // '<S120>/var_out'
  real_T var_out_e;                    // '<S121>/var_out'
  real_T var_out_dn;                   // '<S123>/var_out'
  real_T var_out_n;                    // '<S122>/var_out'
  real_T var_out_kz;                   // '<S124>/var_out'
  real_T var_out_l3;                   // '<S125>/var_out'
  real_T var_out_c;                    // '<S76>/var_out'
  real_T Sum10;                        // '<S267>/Sum10'
  real_T var_out_kzu;                  // '<S77>/var_out'
  real_T Fcn23;                        // '<S267>/Fcn23'
  real_T Sum22;                        // '<S267>/Sum22'
  real_T var_out_i;                    // '<S102>/var_out'
  real_T var_out_gb;                   // '<S101>/var_out'
  real_T var_out_h4;                   // '<S40>/var_out'
  real_T Divide;                       // '<S282>/Divide'
  real_T Add3;                         // '<S282>/Add3'
  real_T Add2;                         // '<S282>/Add2'
  real_T Switch2;                      // '<S282>/Switch2'
  real_T Memory;                       // '<S288>/Memory'
  real_T var_out_m5;                   // '<S103>/var_out'
  real_T var_out_b;                    // '<S105>/var_out'
  real_T Merge;                        // '<S319>/Merge'
  real_T Merge_h;                      // '<S318>/Merge'
  real_T var_out_ir;                   // '<S42>/var_out'
  real_T var_out_lh;                   // '<S73>/var_out'
  real_T Switch;                       // '<S348>/Switch'
  real_T Product4;                     // '<S361>/Product4'
  real_T Abs;                          // '<S361>/Abs'
  real_T Merge_c;                      // '<S349>/Merge'
  real_T var_out_ot;                   // '<S46>/var_out'
  real_T var_out_d0;                   // '<S45>/var_out'
  real_T Merge_p;                      // '<S304>/Merge'
  real_T Switch_h;                     // '<S308>/Switch'
  real_T Switch_m;                     // '<S301>/Switch'
  real_T FilterCoefficient;            // '<S224>/Filter Coefficient'
  real_T IntegralGain;                 // '<S218>/Integral Gain'
  real_T var_out_mj;                   // '<S48>/var_out'
  real_T var_out_bu;                   // '<S49>/var_out'
  real_T var_out_m0;                   // '<S51>/var_out'
  real_T var_out_bc;                   // '<S54>/var_out'
  real_T var_out_aj;                   // '<S56>/var_out'
  real_T var_out_kp;                   // '<S58>/var_out'
  real_T var_out_gt;                   // '<S60>/var_out'
  real_T var_out_mn;                   // '<S62>/var_out'
  real_T var_out_oc;                   // '<S65>/var_out'
  real_T var_out_pr;                   // '<S67>/var_out'
  real_T var_out_ft;                   // '<S47>/var_out'
  real_T var_out_m0c;                  // '<S59>/var_out'
  real_T var_out_p5;                   // '<S61>/var_out'
  real_T var_out_pi;                   // '<S64>/var_out'
  real_T var_out_j;                    // '<S66>/var_out'
  real_T var_out_b4;                   // '<S68>/var_out'
  real_T var_out_l1;                   // '<S50>/var_out'
  real_T var_out_di;                   // '<S53>/var_out'
  real_T var_out_ct;                   // '<S55>/var_out'
  real_T var_out_dic;                  // '<S57>/var_out'
  real_T A_d;                          // '<S284>/Fcn1'
  real_T Fcn23_h;                      // '<S284>/Fcn23'
  real_T Sum10_o;                      // '<S284>/Sum10'
  real_T Sum22_n;                      // '<S284>/Sum22'
  real_T Switch_b;                     // '<S288>/Switch'
  real_T var_out_cp;                   // '<S2>/var_out'
  real_T var_out_fu;                   // '<S4>/var_out'
  real_T var_out_p4;                   // '<S5>/var_out'
  real_T var_out_a3;                   // '<S6>/var_out'
  real_T var_out_is;                   // '<S7>/var_out'
  real_T var_out_nk;                   // '<S8>/var_out'
  real_T var_out_oq;                   // '<S9>/var_out'
  real_T var_out_ht;                   // '<S10>/var_out'
  real_T var_out_dd;                   // '<S11>/var_out'
  real_T var_out_fm;                   // '<S12>/var_out'
  real_T var_out_cl;                   // '<S13>/var_out'
  real_T var_out_hpv;                  // '<S14>/var_out'
  real_T var_out_gtf;                  // '<S16>/var_out'
  real_T var_out_fw;                   // '<S17>/var_out'
  real_T var_out_hm;                   // '<S19>/var_out'
  real_T var_out_jd;                   // '<S20>/var_out'
  real_T var_out_mjd;                  // '<S21>/var_out'
  real_T var_out_mg;                   // '<S22>/var_out'
  real_T var_out_ma;                   // '<S23>/var_out'
  real_T var_out_jg;                   // '<S24>/var_out'
  real_T var_out_dik;                  // '<S26>/var_out'
  real_T var_out_bu5;                  // '<S27>/var_out'
  real_T var_out_lz;                   // '<S28>/var_out'
  real_T var_out_gf;                   // '<S29>/var_out'
  real_T var_out_ii;                   // '<S30>/var_out'
  real_T var_out_i1;                   // '<S31>/var_out'
  real_T var_out_c2;                   // '<S32>/var_out'
  real_T var_out_fuw;                  // '<S33>/var_out'
  real_T var_out_fy;                   // '<S34>/var_out'
  real_T var_out_gn;                   // '<S35>/var_out'
  real_T var_out_bi;                   // '<S37>/var_out'
  real_T var_out_pe;                   // '<S38>/var_out'
  real_T var_out_cc;                   // '<S39>/var_out'
  real_T var_out_jw;                   // '<S41>/var_out'
  real_T var_out_lzi;                  // '<S44>/var_out'
  real_T var_out_lj;                   // '<S52>/var_out'
  real_T var_out_gbu;                  // '<S69>/var_out'
  real_T var_out_mf;                   // '<S70>/var_out'
  real_T var_out_ay;                   // '<S71>/var_out'
  real_T var_out_b4c;                  // '<S72>/var_out'
  real_T var_out_bv;                   // '<S74>/var_out'
  real_T var_out_hy;                   // '<S75>/var_out'
  real_T var_out_nq;                   // '<S78>/var_out'
  real_T var_out_nw;                   // '<S82>/var_out'
  real_T var_out_b2;                   // '<S83>/var_out'
  real_T var_out_an;                   // '<S84>/var_out'
  real_T var_out_dw;                   // '<S85>/var_out'
  real_T var_out_iw;                   // '<S86>/var_out'
  real_T var_out_oe;                   // '<S87>/var_out'
  real_T var_out_n5;                   // '<S88>/var_out'
  real_T var_out_f0;                   // '<S89>/var_out'
  real_T var_out_d3;                   // '<S90>/var_out'
  real_T var_out_it;                   // '<S92>/var_out'
  real_T var_out_ayj;                  // '<S93>/var_out'
  real_T var_out_ol;                   // '<S94>/var_out'
  real_T var_out_mfk;                  // '<S95>/var_out'
  real_T var_out_je;                   // '<S96>/var_out'
  real_T var_out_cg;                   // '<S97>/var_out'
  real_T var_out_oeu;                  // '<S98>/var_out'
  real_T var_out_p5p;                  // '<S99>/var_out'
  real_T var_out_iv;                   // '<S100>/var_out'
  real_T var_out_ht1;                  // '<S104>/var_out'
  real_T var_out_jo;                   // '<S106>/var_out'
  real_T var_out_bg;                   // '<S115>/var_out'
  real_T var_out_in;                   // '<S126>/var_out'
  real_T var_out_ddt;                  // '<S127>/var_out'
  real_T var_out_d0r;                  // '<S137>/var_out'
  real_T var_out_ok;                   // '<S138>/var_out'
  real_T var_out_ba;                   // '<S139>/var_out'
  real_T var_out_li;                   // '<S140>/var_out'
  real_T var_out_pb;                   // '<S141>/var_out'
  real_T var_out_bj;                   // '<S142>/var_out'
  real_T var_out_dv;                   // '<S143>/var_out'
  real_T var_out_id;                   // '<S144>/var_out'
  real_T var_out_fj;                   // '<S145>/var_out'
  real_T var_out_ll;                   // '<S146>/var_out'
  real_T var_out_ml;                   // '<S147>/var_out'
  real_T var_out_az;                   // '<S149>/var_out'
  real_T var_out_dj;                   // '<S150>/var_out'
  real_T var_out_fh;                   // '<S151>/var_out'
  real_T var_out_mh;                   // '<S152>/var_out'
  real_T var_out_oy;                   // '<S153>/var_out'
  real_T var_out_fhv;                  // '<S154>/var_out'
  real_T var_out_nqm;                  // '<S155>/var_out'
  real_T var_out_ji;                   // '<S156>/var_out'
  real_T var_out_jm;                   // '<S157>/var_out'
  real_T var_out_nz;                   // '<S158>/var_out'
  real_T Merge_b;                      // '<S372>/Merge'
  real_T UnitDelay;                    // '<S371>/Unit Delay'
  real_T Gain;                         // '<S371>/Gain'
  real_T Gain1;                        // '<S364>/Gain1'
  real_T SteerAngle_desire;            // '<S364>/mode 2'
  real_T Switch_f;                     // '<S347>/Switch'
  real_T Merge_j;                      // '<S343>/Merge'
  real_T UnitDelay_c;                  // '<S343>/Unit Delay'
  real_T Switch_fk;                    // '<S343>/Switch'
  real_T Product;                      // '<S342>/Product'
  real_T Merge_f;                      // '<S338>/Merge'
  real_T UnitDelay_m;                  // '<S337>/Unit Delay'
  real_T Merge_bv;                     // '<S317>/Merge'
  real_T Merge_d;                      // '<S312>/Merge'
  real_T UnitDelay_mc;                 // '<S312>/Unit Delay'
  real_T Switch_d;                     // '<S312>/Switch'
  real_T Product_i;                    // '<S313>/Product'
  real_T Delay;                        // '<S296>/Delay'
  real_T Product_l;                    // '<S299>/Product'
  real_T Sum;                          // '<S294>/Sum'
  real_T UnitDelay1;                   // '<S294>/Unit Delay1'
  real_T Switch_j;                     // '<S294>/Switch'
  real_T Delay_n;                      // '<S277>/Delay'
  real_T Product_b;                    // '<S280>/Product'
  real_T Sum_g;                        // '<S275>/Sum'
  real_T UnitDelay1_i;                 // '<S275>/Unit Delay1'
  real_T Switch_c;                     // '<S275>/Switch'
  real_T Switch2_g;                    // '<S248>/Switch2'
  real_T Switch_k;                     // '<S248>/Switch'
  real_T UnitDelay_e;                  // '<S241>/Unit Delay'
  real_T UnitDelay1_a;                 // '<S244>/Unit Delay1'
  real_T Add1;                         // '<S244>/Add1'
  real_T UnitDelay1_p;                 // '<S243>/Unit Delay1'
  real_T Add1_n;                       // '<S243>/Add1'
  real_T Add;                          // '<S240>/Add'
  real_T Add_i;                        // '<S239>/Add'
  real_T Add_l;                        // '<S238>/Add'
  real_T VehStatCo_Stat_finish;        // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  real_T VehStatCo_Stat_stop;          // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  uint8_T ADAS_Stat_st;                // '<S300>/VehStatCo_Stat_Stat'
  uint8_T VehStatCo_Stat_st;           // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  boolean_T Dfp_xxx_mp_4;              // '<S380>/up//down time debouncing1'
  boolean_T Switch3;                   // '<S379>/Switch3'
  boolean_T Dfp_xxx_mp_4_d;            // '<S378>/time debouncing1'
  boolean_T Switch3_k;                 // '<S377>/Switch3'
  boolean_T UnitDelay_i;               // '<S248>/Unit Delay'
  boolean_T VehDa_VehSpd_stNPL_mp;     // '<S245>/Relational Operator3'
  boolean_T VehStatCo_Stat_start;      // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  boolean_T VehStatCo_Stat_run;        // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
} B_truck_adas_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE;             // '<S163>/Unit Delay'
  real_T UnitDelay_DSTATE_b;           // '<S282>/Unit Delay'
  real_T UnitDelay_DSTATE_e;           // '<S267>/Unit Delay'
  real_T UnitDelay1_DSTATE;            // '<S267>/Unit Delay1'
  real_T UnitDelay2_DSTATE;            // '<S267>/Unit Delay2'
  real_T UnitDelay3_DSTATE;            // '<S267>/Unit Delay3'
  real_T UnitDelay4_DSTATE;            // '<S267>/Unit Delay4'
  real_T UnitDelay1_DSTATE_g;          // '<S163>/Unit Delay1'
  real_T UnitDelay_DSTATE_h;           // '<S284>/Unit Delay'
  real_T UnitDelay1_DSTATE_gt;         // '<S284>/Unit Delay1'
  real_T UnitDelay2_DSTATE_a;          // '<S284>/Unit Delay2'
  real_T UnitDelay3_DSTATE_g;          // '<S284>/Unit Delay3'
  real_T UnitDelay4_DSTATE_k;          // '<S284>/Unit Delay4'
  real_T UnitDelay_DSTATE_l;           // '<S371>/Unit Delay'
  real_T UnitDelay_DSTATE_d;           // '<S343>/Unit Delay'
  real_T UnitDelay_DSTATE_a;           // '<S337>/Unit Delay'
  real_T UnitDelay_DSTATE_bf;          // '<S312>/Unit Delay'
  real_T Delay_DSTATE;                 // '<S296>/Delay'
  real_T UnitDelay_DSTATE_be;          // '<S294>/Unit Delay'
  real_T UnitDelay1_DSTATE_e;          // '<S294>/Unit Delay1'
  real_T Delay_DSTATE_l;               // '<S277>/Delay'
  real_T UnitDelay_DSTATE_f;           // '<S275>/Unit Delay'
  real_T UnitDelay1_DSTATE_f;          // '<S275>/Unit Delay1'
  real_T UnitDelay1_DSTATE_gs;         // '<S248>/Unit Delay1'
  real_T UnitDelay_DSTATE_i;           // '<S241>/Unit Delay'
  real_T UnitDelay1_DSTATE_m;          // '<S244>/Unit Delay1'
  real_T UnitDelay1_DSTATE_k;          // '<S243>/Unit Delay1'
  real_T Memory_PreviousInput;         // '<S288>/Memory'
  real_T s;                            // '<S364>/mode 2'
  boolean_T UnitDelay_DSTATE_j;        // '<S248>/Unit Delay'
  int8_T If_ActiveSubsystem;           // '<S319>/If'
  int8_T If_ActiveSubsystem_i;         // '<S318>/If'
  int8_T If_ActiveSubsystem_o;         // '<S348>/If'
  int8_T If_ActiveSubsystem_p;         // '<S349>/If'
  int8_T If_ActiveSubsystem_f;         // '<S304>/If'
  int8_T If_ActiveSubsystem_m;         // '<S308>/If'
  int8_T If_ActiveSubsystem_im;        // '<S186>/If'
  uint8_T is_active_c12_truck_adas;    // '<S364>/mode 2'
  uint8_T is_c12_truck_adas;           // '<S364>/mode 2'
  uint8_T is_Right;                    // '<S364>/mode 2'
  uint8_T is_Left;                     // '<S364>/mode 2'
  uint8_T is_active_c2_truck_adas;     // '<S300>/VehStatCo_Stat_Stat'
  uint8_T is_c2_truck_adas;            // '<S300>/VehStatCo_Stat_Stat'
  uint8_T is_APA_TF;                   // '<S300>/VehStatCo_Stat_Stat'
  uint8_T is_TF;                       // '<S300>/VehStatCo_Stat_Stat'
  uint8_T is_Fianl1;                   // '<S300>/VehStatCo_Stat_Stat'
  uint8_T is_Fianl;                    // '<S300>/VehStatCo_Stat_Stat'
  uint8_T is_active_c10_truck_adas;    // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  uint8_T is_c10_truck_adas;           // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  uint8_T is_DRIVE;                    // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  uint8_T is_AFTERRUN;                 // '<S182>/D3.3.1 VehStatCo_Stat_Stat'
  DW_EnabledSubsystem_truck_ada_T EnabledSubsystem2;// '<S237>/Enabled Subsystem2' 
  DW_EnabledSubsystem_truck_ada_T EnabledSubsystem1;// '<S237>/Enabled Subsystem1' 
  DW_EnabledSubsystem_truck_ada_T EnabledSubsystem;// '<S237>/Enabled Subsystem' 
} DW_truck_adas_T;

// Continuous states (default storage)
typedef struct {
  real_T Integrator_CSTATE;            // '<S221>/Integrator'
  real_T Filter_CSTATE;                // '<S216>/Filter'
} X_truck_adas_T;

// State derivatives (default storage)
typedef struct {
  real_T Integrator_CSTATE;            // '<S221>/Integrator'
  real_T Filter_CSTATE;                // '<S216>/Filter'
} XDot_truck_adas_T;

// State disabled
typedef struct {
  boolean_T Integrator_CSTATE;         // '<S221>/Integrator'
  boolean_T Filter_CSTATE;             // '<S216>/Filter'
} XDis_truck_adas_T;

// Invariant block signals (default storage)
typedef const struct tag_ConstB_truck_adas_T {
  real_T Spd2;                         // '<S328>/Math Function2'
  real_T Spd2_n;                       // '<S361>/Math Function2'
  real_T Sum4;                         // '<S366>/Sum4'
  real_T Product1;                     // '<S246>/Product1'
  real_T Product;                      // '<S246>/Product'
  real_T Product1_n;                   // '<S247>/Product1'
  real_T Product_n;                    // '<S247>/Product'
  real_T Divide1;                      // '<S241>/Divide1'
  real_T Switch1;                      // '<S244>/Switch1'
  real_T Divide2;                      // '<S244>/Divide2'
  real_T Switch1_p;                    // '<S243>/Switch1'
  real_T Divide;                       // '<S243>/Divide'
  boolean_T RelationalOperator2;       // '<S376>/Relational Operator2'
  boolean_T RelationalOperator;        // '<S376>/Relational Operator'
  boolean_T RelationalOperator3;       // '<S376>/Relational Operator3'
  boolean_T RelationalOperator1;       // '<S376>/Relational Operator1'
  boolean_T RelationalOperator_l;      // '<S379>/Relational Operator'
  boolean_T RelationalOperator_m;      // '<S377>/Relational Operator'
  boolean_T RelationalOperator_a;      // '<S244>/Relational Operator'
  boolean_T RelationalOperator_b;      // '<S243>/Relational Operator'
} ConstB_truck_adas_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Real-time Model Data Structure
struct tag_RTM_truck_adas_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_truck_adas_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

// Block signals (default storage)
extern B_truck_adas_T truck_adas_B;

// Continuous states (default storage)
extern X_truck_adas_T truck_adas_X;

// Block states (default storage)
extern DW_truck_adas_T truck_adas_DW;
extern const ConstB_truck_adas_T truck_adas_ConstB;// constant block i/o

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void truck_adas_initialize(void);
  extern void truck_adas_step(void);
  extern void truck_adas_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_truck_adas_T *const truck_adas_M;

#ifdef __cplusplus

}
#endif

// Exported data declaration

// Declaration for custom storage class: Global
extern real_T VehStatCo_Stat_DT;
extern real_T Veh_FINISH;
extern real_T Veh_READY;
extern real_T Veh_RUNNING;
extern real_T Veh_STANDBY;
extern real_T Veh_START;
extern real_T Veh_STOPPING;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S184>/Constant2' : Unused code path elimination
//  Block '<S184>/Constant3' : Unused code path elimination
//  Block '<S184>/Divide1' : Unused code path elimination
//  Block '<S184>/Product' : Unused code path elimination
//  Block '<S184>/Relational Operator2' : Unused code path elimination
//  Block '<S184>/Relational Operator3' : Unused code path elimination
//  Block '<S184>/VehAcs_Batt_vSRCMax_C' : Unused code path elimination
//  Block '<S184>/VehAcs_Batt_vSRCMin_C' : Unused code path elimination
//  Block '<S186>/Scope' : Unused code path elimination
//  Block '<S263>/Constant1' : Unused code path elimination
//  Block '<S263>/Constant10' : Unused code path elimination
//  Block '<S263>/Constant2' : Unused code path elimination
//  Block '<S263>/Constant3' : Unused code path elimination
//  Block '<S263>/Constant4' : Unused code path elimination
//  Block '<S263>/Constant5' : Unused code path elimination
//  Block '<S263>/Constant6' : Unused code path elimination
//  Block '<S263>/Constant7' : Unused code path elimination
//  Block '<S263>/Constant8' : Unused code path elimination
//  Block '<S263>/Constant9' : Unused code path elimination
//  Block '<S263>/Math Function' : Unused code path elimination
//  Block '<S263>/Math Function1' : Unused code path elimination
//  Block '<S263>/Math Function10' : Unused code path elimination
//  Block '<S263>/Math Function11' : Unused code path elimination
//  Block '<S263>/Math Function12' : Unused code path elimination
//  Block '<S263>/Math Function13' : Unused code path elimination
//  Block '<S263>/Math Function14' : Unused code path elimination
//  Block '<S263>/Math Function15' : Unused code path elimination
//  Block '<S263>/Math Function16' : Unused code path elimination
//  Block '<S263>/Math Function17' : Unused code path elimination
//  Block '<S263>/Math Function18' : Unused code path elimination
//  Block '<S263>/Math Function19' : Unused code path elimination
//  Block '<S263>/Math Function2' : Unused code path elimination
//  Block '<S263>/Math Function3' : Unused code path elimination
//  Block '<S263>/Math Function4' : Unused code path elimination
//  Block '<S263>/Math Function5' : Unused code path elimination
//  Block '<S263>/Math Function6' : Unused code path elimination
//  Block '<S263>/Math Function7' : Unused code path elimination
//  Block '<S263>/Math Function8' : Unused code path elimination
//  Block '<S263>/Math Function9' : Unused code path elimination
//  Block '<S263>/Min4' : Unused code path elimination
//  Block '<S263>/Sqrt' : Unused code path elimination
//  Block '<S263>/Sqrt1' : Unused code path elimination
//  Block '<S263>/Sqrt2' : Unused code path elimination
//  Block '<S263>/Sqrt3' : Unused code path elimination
//  Block '<S263>/Sqrt4' : Unused code path elimination
//  Block '<S263>/Sqrt5' : Unused code path elimination
//  Block '<S263>/Sqrt6' : Unused code path elimination
//  Block '<S263>/Sqrt7' : Unused code path elimination
//  Block '<S263>/Sqrt8' : Unused code path elimination
//  Block '<S263>/Sqrt9' : Unused code path elimination
//  Block '<S263>/Sum' : Unused code path elimination
//  Block '<S263>/Sum1' : Unused code path elimination
//  Block '<S263>/Sum2' : Unused code path elimination
//  Block '<S263>/Sum3' : Unused code path elimination
//  Block '<S263>/Sum4' : Unused code path elimination
//  Block '<S263>/Sum5' : Unused code path elimination
//  Block '<S263>/Sum6' : Unused code path elimination
//  Block '<S263>/Sum7' : Unused code path elimination
//  Block '<S263>/Sum8' : Unused code path elimination
//  Block '<S263>/Sum9' : Unused code path elimination
//  Block '<S263>/Switch1' : Unused code path elimination
//  Block '<S263>/Switch10' : Unused code path elimination
//  Block '<S263>/Switch2' : Unused code path elimination
//  Block '<S263>/Switch3' : Unused code path elimination
//  Block '<S263>/Switch4' : Unused code path elimination
//  Block '<S263>/Switch5' : Unused code path elimination
//  Block '<S263>/Switch6' : Unused code path elimination
//  Block '<S263>/Switch7' : Unused code path elimination
//  Block '<S263>/Switch8' : Unused code path elimination
//  Block '<S263>/Switch9' : Unused code path elimination
//  Block '<S299>/Sum8' : Unused code path elimination
//  Block '<S365>/Constant2' : Unused code path elimination
//  Block '<S365>/Constant3' : Unused code path elimination
//  Block '<S365>/Constant4' : Unused code path elimination
//  Block '<S365>/Constant5' : Unused code path elimination
//  Block '<S365>/Fcn10' : Unused code path elimination
//  Block '<S365>/Fcn12' : Unused code path elimination
//  Block '<S365>/Fcn13' : Unused code path elimination
//  Block '<S365>/Fcn14' : Unused code path elimination
//  Block '<S365>/Fcn15' : Unused code path elimination
//  Block '<S365>/Fcn16' : Unused code path elimination
//  Block '<S365>/Fcn17' : Unused code path elimination
//  Block '<S365>/Fcn6' : Unused code path elimination
//  Block '<S365>/Fcn7' : Unused code path elimination
//  Block '<S365>/Fcn9' : Unused code path elimination
//  Block '<S365>/Gain' : Unused code path elimination
//  Block '<S365>/Math Function' : Unused code path elimination
//  Block '<S365>/Product10' : Unused code path elimination
//  Block '<S365>/Product4' : Unused code path elimination
//  Block '<S365>/Product7' : Unused code path elimination
//  Block '<S365>/Product8' : Unused code path elimination
//  Block '<S365>/Product9' : Unused code path elimination
//  Block '<S365>/Sqrt' : Unused code path elimination
//  Block '<S365>/Sum1' : Unused code path elimination
//  Block '<S365>/Sum2' : Unused code path elimination
//  Block '<S365>/Sum5' : Unused code path elimination
//  Block '<S365>/Sum6' : Unused code path elimination
//  Block '<S365>/Sum7' : Unused code path elimination
//  Block '<S365>/Sum8' : Unused code path elimination
//  Block '<S365>/Sum9' : Unused code path elimination
//  Block '<S365>/Switch1' : Unused code path elimination
//  Block '<S377>/Switch1' : Unused code path elimination
//  Block '<S377>/Switch2' : Unused code path elimination
//  Block '<S379>/Switch1' : Unused code path elimination
//  Block '<S379>/Switch2' : Unused code path elimination
//  Block '<S160>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S226>/Proportional Gain' : Eliminated nontunable gain of 1
//  Block '<S376>/Data Type Conversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'truck_adas'
//  '<S1>'   : 'truck_adas/TRUCK_ADAS'
//  '<S2>'   : 'truck_adas/variable_out1'
//  '<S3>'   : 'truck_adas/variable_out10'
//  '<S4>'   : 'truck_adas/variable_out100'
//  '<S5>'   : 'truck_adas/variable_out101'
//  '<S6>'   : 'truck_adas/variable_out102'
//  '<S7>'   : 'truck_adas/variable_out103'
//  '<S8>'   : 'truck_adas/variable_out104'
//  '<S9>'   : 'truck_adas/variable_out105'
//  '<S10>'  : 'truck_adas/variable_out106'
//  '<S11>'  : 'truck_adas/variable_out107'
//  '<S12>'  : 'truck_adas/variable_out108'
//  '<S13>'  : 'truck_adas/variable_out109'
//  '<S14>'  : 'truck_adas/variable_out11'
//  '<S15>'  : 'truck_adas/variable_out110'
//  '<S16>'  : 'truck_adas/variable_out111'
//  '<S17>'  : 'truck_adas/variable_out112'
//  '<S18>'  : 'truck_adas/variable_out113'
//  '<S19>'  : 'truck_adas/variable_out114'
//  '<S20>'  : 'truck_adas/variable_out115'
//  '<S21>'  : 'truck_adas/variable_out116'
//  '<S22>'  : 'truck_adas/variable_out117'
//  '<S23>'  : 'truck_adas/variable_out118'
//  '<S24>'  : 'truck_adas/variable_out119'
//  '<S25>'  : 'truck_adas/variable_out12'
//  '<S26>'  : 'truck_adas/variable_out120'
//  '<S27>'  : 'truck_adas/variable_out121'
//  '<S28>'  : 'truck_adas/variable_out122'
//  '<S29>'  : 'truck_adas/variable_out123'
//  '<S30>'  : 'truck_adas/variable_out124'
//  '<S31>'  : 'truck_adas/variable_out125'
//  '<S32>'  : 'truck_adas/variable_out126'
//  '<S33>'  : 'truck_adas/variable_out127'
//  '<S34>'  : 'truck_adas/variable_out128'
//  '<S35>'  : 'truck_adas/variable_out129'
//  '<S36>'  : 'truck_adas/variable_out13'
//  '<S37>'  : 'truck_adas/variable_out130'
//  '<S38>'  : 'truck_adas/variable_out131'
//  '<S39>'  : 'truck_adas/variable_out132'
//  '<S40>'  : 'truck_adas/variable_out133'
//  '<S41>'  : 'truck_adas/variable_out134'
//  '<S42>'  : 'truck_adas/variable_out135'
//  '<S43>'  : 'truck_adas/variable_out14'
//  '<S44>'  : 'truck_adas/variable_out15'
//  '<S45>'  : 'truck_adas/variable_out153'
//  '<S46>'  : 'truck_adas/variable_out154'
//  '<S47>'  : 'truck_adas/variable_out155'
//  '<S48>'  : 'truck_adas/variable_out156'
//  '<S49>'  : 'truck_adas/variable_out157'
//  '<S50>'  : 'truck_adas/variable_out158'
//  '<S51>'  : 'truck_adas/variable_out159'
//  '<S52>'  : 'truck_adas/variable_out16'
//  '<S53>'  : 'truck_adas/variable_out160'
//  '<S54>'  : 'truck_adas/variable_out161'
//  '<S55>'  : 'truck_adas/variable_out162'
//  '<S56>'  : 'truck_adas/variable_out163'
//  '<S57>'  : 'truck_adas/variable_out164'
//  '<S58>'  : 'truck_adas/variable_out165'
//  '<S59>'  : 'truck_adas/variable_out166'
//  '<S60>'  : 'truck_adas/variable_out167'
//  '<S61>'  : 'truck_adas/variable_out168'
//  '<S62>'  : 'truck_adas/variable_out169'
//  '<S63>'  : 'truck_adas/variable_out17'
//  '<S64>'  : 'truck_adas/variable_out170'
//  '<S65>'  : 'truck_adas/variable_out171'
//  '<S66>'  : 'truck_adas/variable_out172'
//  '<S67>'  : 'truck_adas/variable_out173'
//  '<S68>'  : 'truck_adas/variable_out174'
//  '<S69>'  : 'truck_adas/variable_out18'
//  '<S70>'  : 'truck_adas/variable_out19'
//  '<S71>'  : 'truck_adas/variable_out2'
//  '<S72>'  : 'truck_adas/variable_out20'
//  '<S73>'  : 'truck_adas/variable_out21'
//  '<S74>'  : 'truck_adas/variable_out22'
//  '<S75>'  : 'truck_adas/variable_out23'
//  '<S76>'  : 'truck_adas/variable_out24'
//  '<S77>'  : 'truck_adas/variable_out25'
//  '<S78>'  : 'truck_adas/variable_out26'
//  '<S79>'  : 'truck_adas/variable_out27'
//  '<S80>'  : 'truck_adas/variable_out28'
//  '<S81>'  : 'truck_adas/variable_out29'
//  '<S82>'  : 'truck_adas/variable_out3'
//  '<S83>'  : 'truck_adas/variable_out30'
//  '<S84>'  : 'truck_adas/variable_out31'
//  '<S85>'  : 'truck_adas/variable_out32'
//  '<S86>'  : 'truck_adas/variable_out33'
//  '<S87>'  : 'truck_adas/variable_out34'
//  '<S88>'  : 'truck_adas/variable_out35'
//  '<S89>'  : 'truck_adas/variable_out36'
//  '<S90>'  : 'truck_adas/variable_out37'
//  '<S91>'  : 'truck_adas/variable_out38'
//  '<S92>'  : 'truck_adas/variable_out39'
//  '<S93>'  : 'truck_adas/variable_out4'
//  '<S94>'  : 'truck_adas/variable_out40'
//  '<S95>'  : 'truck_adas/variable_out41'
//  '<S96>'  : 'truck_adas/variable_out42'
//  '<S97>'  : 'truck_adas/variable_out43'
//  '<S98>'  : 'truck_adas/variable_out44'
//  '<S99>'  : 'truck_adas/variable_out45'
//  '<S100>' : 'truck_adas/variable_out46'
//  '<S101>' : 'truck_adas/variable_out47'
//  '<S102>' : 'truck_adas/variable_out48'
//  '<S103>' : 'truck_adas/variable_out49'
//  '<S104>' : 'truck_adas/variable_out5'
//  '<S105>' : 'truck_adas/variable_out50'
//  '<S106>' : 'truck_adas/variable_out51'
//  '<S107>' : 'truck_adas/variable_out52'
//  '<S108>' : 'truck_adas/variable_out53'
//  '<S109>' : 'truck_adas/variable_out54'
//  '<S110>' : 'truck_adas/variable_out55'
//  '<S111>' : 'truck_adas/variable_out56'
//  '<S112>' : 'truck_adas/variable_out57'
//  '<S113>' : 'truck_adas/variable_out58'
//  '<S114>' : 'truck_adas/variable_out59'
//  '<S115>' : 'truck_adas/variable_out6'
//  '<S116>' : 'truck_adas/variable_out60'
//  '<S117>' : 'truck_adas/variable_out61'
//  '<S118>' : 'truck_adas/variable_out62'
//  '<S119>' : 'truck_adas/variable_out63'
//  '<S120>' : 'truck_adas/variable_out64'
//  '<S121>' : 'truck_adas/variable_out65'
//  '<S122>' : 'truck_adas/variable_out66'
//  '<S123>' : 'truck_adas/variable_out67'
//  '<S124>' : 'truck_adas/variable_out68'
//  '<S125>' : 'truck_adas/variable_out69'
//  '<S126>' : 'truck_adas/variable_out7'
//  '<S127>' : 'truck_adas/variable_out70'
//  '<S128>' : 'truck_adas/variable_out71'
//  '<S129>' : 'truck_adas/variable_out72'
//  '<S130>' : 'truck_adas/variable_out73'
//  '<S131>' : 'truck_adas/variable_out74'
//  '<S132>' : 'truck_adas/variable_out75'
//  '<S133>' : 'truck_adas/variable_out76'
//  '<S134>' : 'truck_adas/variable_out77'
//  '<S135>' : 'truck_adas/variable_out78'
//  '<S136>' : 'truck_adas/variable_out79'
//  '<S137>' : 'truck_adas/variable_out8'
//  '<S138>' : 'truck_adas/variable_out80'
//  '<S139>' : 'truck_adas/variable_out81'
//  '<S140>' : 'truck_adas/variable_out82'
//  '<S141>' : 'truck_adas/variable_out83'
//  '<S142>' : 'truck_adas/variable_out84'
//  '<S143>' : 'truck_adas/variable_out85'
//  '<S144>' : 'truck_adas/variable_out86'
//  '<S145>' : 'truck_adas/variable_out87'
//  '<S146>' : 'truck_adas/variable_out88'
//  '<S147>' : 'truck_adas/variable_out89'
//  '<S148>' : 'truck_adas/variable_out9'
//  '<S149>' : 'truck_adas/variable_out90'
//  '<S150>' : 'truck_adas/variable_out91'
//  '<S151>' : 'truck_adas/variable_out92'
//  '<S152>' : 'truck_adas/variable_out93'
//  '<S153>' : 'truck_adas/variable_out94'
//  '<S154>' : 'truck_adas/variable_out95'
//  '<S155>' : 'truck_adas/variable_out96'
//  '<S156>' : 'truck_adas/variable_out97'
//  '<S157>' : 'truck_adas/variable_out98'
//  '<S158>' : 'truck_adas/variable_out99'
//  '<S159>' : 'truck_adas/TRUCK_ADAS/D1_INPUT'
//  '<S160>' : 'truck_adas/TRUCK_ADAS/D2_OUTPUT'
//  '<S161>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle'
//  '<S162>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception'
//  '<S163>' : 'truck_adas/TRUCK_ADAS/D5_ADAS'
//  '<S164>' : 'truck_adas/TRUCK_ADAS/D6 DSM'
//  '<S165>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/Back_vision'
//  '<S166>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D 1.6  GPS_signals'
//  '<S167>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.1 IMU_Signals'
//  '<S168>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.2 MCU_Signals'
//  '<S169>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.3  VisionObj_Signals'
//  '<S170>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.4 visionLane_Signals'
//  '<S171>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.5 Radar_singnals'
//  '<S172>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.7  Ultrasonic radar'
//  '<S173>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.8 IMU_Transport'
//  '<S174>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.7  Ultrasonic radar/FLS_APA'
//  '<S175>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.7  Ultrasonic radar/FRS_APA'
//  '<S176>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.7  Ultrasonic radar/Front_UPA '
//  '<S177>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.7  Ultrasonic radar/RLS_APA '
//  '<S178>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.7  Ultrasonic radar/RRS_APA'
//  '<S179>' : 'truck_adas/TRUCK_ADAS/D1_INPUT/D1.7  Ultrasonic radar/Rear_UPA '
//  '<S180>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.1 VehAcs'
//  '<S181>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion'
//  '<S182>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.3 Vehicle_Coordinator'
//  '<S183>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa '
//  '<S184>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.1 VehAcs/D3.1.1 VehAcs_Batt '
//  '<S185>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.1 VehAcs/D3.1.2  VehAcs_IgnKey'
//  '<S186>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.1 VehAcs/D3.1.3  VehAcs_Disp__WarnningLamp'
//  '<S187>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.1 VehAcs/D3.1.3  VehAcs_Disp__WarnningLamp/Compare To Constant'
//  '<S188>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.1 VehAcs/D3.1.3  VehAcs_Disp__WarnningLamp/If Action Subsystem1'
//  '<S189>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.1 VehAcs/D3.1.3  VehAcs_Disp__WarnningLamp/If Action Subsystem2'
//  '<S190>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral'
//  '<S191>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1'
//  '<S192>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Anti-windup'
//  '<S193>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/D Gain'
//  '<S194>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Filter'
//  '<S195>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Filter ICs'
//  '<S196>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/I Gain'
//  '<S197>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Ideal P Gain'
//  '<S198>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Ideal P Gain Fdbk'
//  '<S199>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Integrator'
//  '<S200>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Integrator ICs'
//  '<S201>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/N Copy'
//  '<S202>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/N Gain'
//  '<S203>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/P Copy'
//  '<S204>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Parallel P Gain'
//  '<S205>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Reset Signal'
//  '<S206>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Saturation'
//  '<S207>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Saturation Fdbk'
//  '<S208>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Sum'
//  '<S209>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Sum Fdbk'
//  '<S210>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Tracking Mode'
//  '<S211>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Tracking Mode Sum'
//  '<S212>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/postSat Signal'
//  '<S213>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/preSat Signal'
//  '<S214>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Anti-windup/Passthrough'
//  '<S215>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/D Gain/Internal Parameters'
//  '<S216>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Filter/Cont. Filter'
//  '<S217>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S218>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/I Gain/Internal Parameters'
//  '<S219>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Ideal P Gain/Passthrough'
//  '<S220>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S221>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Integrator/Continuous'
//  '<S222>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Integrator ICs/Internal IC'
//  '<S223>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/N Copy/Disabled'
//  '<S224>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/N Gain/Internal Parameters'
//  '<S225>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/P Copy/Disabled'
//  '<S226>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S227>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Reset Signal/Disabled'
//  '<S228>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Saturation/Passthrough'
//  '<S229>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Saturation Fdbk/Disabled'
//  '<S230>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Sum/Sum_PID'
//  '<S231>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Sum Fdbk/Disabled'
//  '<S232>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Tracking Mode/Disabled'
//  '<S233>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S234>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/postSat Signal/Forward_Path'
//  '<S235>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.2 Veh_Motion/PIDContral/PID Controller1/preSat Signal/Forward_Path'
//  '<S236>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.3 Vehicle_Coordinator/D3.3.1 VehStatCo_Stat_Stat'
//  '<S237>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.3 Vehicle_Coordinator/D3.3.2 VehStatCo_Stat_counter'
//  '<S238>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.3 Vehicle_Coordinator/D3.3.2 VehStatCo_Stat_counter/Enabled Subsystem'
//  '<S239>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.3 Vehicle_Coordinator/D3.3.2 VehStatCo_Stat_counter/Enabled Subsystem1'
//  '<S240>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.3 Vehicle_Coordinator/D3.3.2 VehStatCo_Stat_counter/Enabled Subsystem2'
//  '<S241>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa / D3.5.2 VehDa_VehSpd_SigFilter'
//  '<S242>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa /D 3.51VehDa_VehSpd_SpdCal'
//  '<S243>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa / D3.5.2 VehDa_VehSpd_SigFilter/VehDa_VehSpd_APT1'
//  '<S244>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa / D3.5.2 VehDa_VehSpd_SigFilter/VehDa_VehSpd_velPT1'
//  '<S245>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa /D 3.51VehDa_VehSpd_SpdCal/VehDa_VehSpd_ErrDet'
//  '<S246>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa /D 3.51VehDa_VehSpd_SpdCal/VehDa_VehSpd_ErrDet/DT_Convert'
//  '<S247>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa /D 3.51VehDa_VehSpd_SpdCal/VehDa_VehSpd_ErrDet/DT_Convert1'
//  '<S248>' : 'truck_adas/TRUCK_ADAS/D3 Vehicle/D3.5 VehDa /D 3.51VehDa_VehSpd_SpdCal/VehDa_VehSpd_ErrDet/Double Ramp'
//  '<S249>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information '
//  '<S250>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection '
//  '<S251>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.3 Dynamic object synthesis detection '
//  '<S252>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.1 	Vision'
//  '<S253>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.2   Radar'
//  '<S254>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.3  IMU_and GPS'
//  '<S255>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.4  Lidar'
//  '<S256>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.1 	Vision/Vision_Lane'
//  '<S257>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.1 	Vision/Vision_Signals'
//  '<S258>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.3  IMU_and GPS/GPS_signals'
//  '<S259>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.1  Fusion of multi-sensor information /D4.1.3  IMU_and GPS/IMU_Signals'
//  '<S260>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.1  Vision_Obj_distance'
//  '<S261>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs'
//  '<S262>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.3  fusion_diatance'
//  '<S263>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.4 Radar_diatance'
//  '<S264>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.5  Vision_Obj_distance_APA'
//  '<S265>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs'
//  '<S266>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.1  Vision_Obj_distance/Obj_dis_vision'
//  '<S267>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.1  Vision_Obj_distance/Obj_position'
//  '<S268>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/ '
//  '<S269>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/D4.2.2.2 Obs_vision'
//  '<S270>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/ /position'
//  '<S271>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/ /position/RPM_Lookuptable'
//  '<S272>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/ /position/Subsystem'
//  '<S273>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/ /position/deta_Lm'
//  '<S274>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/ /position/deta_Lm/Subsystem'
//  '<S275>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/ /position/deta_Lm/counter_i'
//  '<S276>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/D4.2.2.2 Obs_vision/Obsvision '
//  '<S277>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/D4.2.2.2 Obs_vision/Obsvision /Obs_dis'
//  '<S278>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/D4.2.2.2 Obs_vision/Obsvision /RPM_Lookuptable'
//  '<S279>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/D4.2.2.2 Obs_vision/Obsvision /Subsystem'
//  '<S280>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.2 obs/D4.2.2.2 Obs_vision/Obsvision /deta_Sm'
//  '<S281>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.3  fusion_diatance/D4.2.3.1 fusion_obj_distance'
//  '<S282>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.3  fusion_diatance/D4.2.3.2 Obj_distance_Flt'
//  '<S283>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.5  Vision_Obj_distance_APA/D4.2.5.1 Obj_dis_vision'
//  '<S284>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.5  Vision_Obj_distance_APA/D4.2.5.2  Obj_position'
//  '<S285>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/ '
//  '<S286>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem'
//  '<S287>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem1'
//  '<S288>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem2'
//  '<S289>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/ /position'
//  '<S290>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/ /position/RPM_Lookuptable'
//  '<S291>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/ /position/Subsystem'
//  '<S292>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/ /position/deta_Lm'
//  '<S293>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/ /position/deta_Lm/Subsystem'
//  '<S294>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/ /position/deta_Lm/counter_i'
//  '<S295>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem/OBS'
//  '<S296>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem/OBS/Obs_dis'
//  '<S297>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem/OBS/RPM_Lookuptable'
//  '<S298>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem/OBS/Subsystem'
//  '<S299>' : 'truck_adas/TRUCK_ADAS/D4  Fusion perception/D4.2  Static object synthesis detection /D4.2.6 Disobs/Subsystem/OBS/deta_Sm'
//  '<S300>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.1  ADAS_Co'
//  '<S301>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.10 Driving'
//  '<S302>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.2  RP'
//  '<S303>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF'
//  '<S304>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.4 FCW'
//  '<S305>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.5   AEB'
//  '<S306>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.6 RP_APA'
//  '<S307>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA'
//  '<S308>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.8  FCW_APA'
//  '<S309>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.9   APA_AEB'
//  '<S310>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.1  ADAS_Co/VehStatCo_Stat_Stat'
//  '<S311>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.2  RP/D5.2.1   deta_S'
//  '<S312>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.2  RP/D5.2.2   judgement'
//  '<S313>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.2  RP/D5.2.1   deta_S/deta_s'
//  '<S314>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.2  RP/D5.2.2   judgement/Compare To Constant2'
//  '<S315>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.2  RP/D5.2.2   judgement/If Action Subsystem1'
//  '<S316>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.2  RP/D5.2.2   judgement/If Action Subsystem2'
//  '<S317>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/ D5.3.3 Brake'
//  '<S318>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning'
//  '<S319>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D5.3.1 vel_start'
//  '<S320>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/ D5.3.3 Brake/Compare To Constant2'
//  '<S321>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/ D5.3.3 Brake/If Action Subsystem1'
//  '<S322>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/ D5.3.3 Brake/If Action Subsystem2'
//  '<S323>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning/Compare To Constant2'
//  '<S324>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning/D5.3.4 Steerangle'
//  '<S325>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning/D5.3.running'
//  '<S326>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning/If Action Subsystem1'
//  '<S327>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning/If Action Subsystem2'
//  '<S328>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning/vel_running'
//  '<S329>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D 5.3.2 Runnning/D5.3.4 Steerangle/D5.3.4.2 deta_oriatation'
//  '<S330>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D5.3.1 vel_start/Compare To Constant2'
//  '<S331>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D5.3.1 vel_start/D5.3.1.1  vel_start'
//  '<S332>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D5.3.1 vel_start/If Action Subsystem1'
//  '<S333>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.3  TF/D5.3.1 vel_start/If Action Subsystem2'
//  '<S334>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.4 FCW/Compare To Constant1'
//  '<S335>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.4 FCW/If Action Subsystem1'
//  '<S336>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.4 FCW/If Action Subsystem2'
//  '<S337>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.5   AEB/D5.5.1 Accelation'
//  '<S338>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.5   AEB/D5.5.2 judgement '
//  '<S339>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.5   AEB/D5.5.2 judgement /Compare To Constant1'
//  '<S340>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.5   AEB/D5.5.2 judgement /If Action Subsystem1'
//  '<S341>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.5   AEB/D5.5.2 judgement /If Action Subsystem2'
//  '<S342>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.6 RP_APA/D5.6.1   deta_S'
//  '<S343>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.6 RP_APA/D5.6.2   judgement deta_S'
//  '<S344>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.6 RP_APA/D5.6.2   judgement deta_S/Compare To Constant2'
//  '<S345>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.6 RP_APA/D5.6.2   judgement deta_S/If Action Subsystem1'
//  '<S346>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.6 RP_APA/D5.6.2   judgement deta_S/If Action Subsystem2'
//  '<S347>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/ D5.7.3 Brake_APA'
//  '<S348>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.1 start'
//  '<S349>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.2 Runnning_APA'
//  '<S350>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.4 Steerangle_APA'
//  '<S351>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/ D5.7.3 Brake_APA/Compare To Constant2'
//  '<S352>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/ D5.7.3 Brake_APA/If Action Subsystem1'
//  '<S353>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/ D5.7.3 Brake_APA/If Action Subsystem2'
//  '<S354>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.1 start/Compare To Constant2'
//  '<S355>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.1 start/D5.3.1.1  vel_start'
//  '<S356>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.1 start/If Action Subsystem1'
//  '<S357>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.1 start/If Action Subsystem2'
//  '<S358>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.2 Runnning_APA/Compare To Constant2'
//  '<S359>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.2 Runnning_APA/If Action Subsystem1'
//  '<S360>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.2 Runnning_APA/If Action Subsystem2'
//  '<S361>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.2 Runnning_APA/vel_running1'
//  '<S362>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.4 Steerangle_APA/D5.7.4.1 oriatation_APA '
//  '<S363>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.4 Steerangle_APA/D5.7.4.2 deta_oriatation_APA  '
//  '<S364>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.4 Steerangle_APA/D5.7.4.3 FPD_steerangle_APA'
//  '<S365>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.4 Steerangle_APA/D5.7.4.1 oriatation_APA /angle_nest'
//  '<S366>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.4 Steerangle_APA/D5.7.4.1 oriatation_APA /oriatation '
//  '<S367>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.7  TF_APA/D5.7.4 Steerangle_APA/D5.7.4.3 FPD_steerangle_APA/mode 2'
//  '<S368>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.8  FCW_APA/Compare To Constant1'
//  '<S369>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.8  FCW_APA/If Action Subsystem1'
//  '<S370>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.8  FCW_APA/If Action Subsystem2'
//  '<S371>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.9   APA_AEB/D5.9.1 Accelation'
//  '<S372>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.9   APA_AEB/D5.9.2 judgement '
//  '<S373>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.9   APA_AEB/D5.9.2 judgement /Compare To Constant1'
//  '<S374>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.9   APA_AEB/D5.9.2 judgement /If Action Subsystem1'
//  '<S375>' : 'truck_adas/TRUCK_ADAS/D5_ADAS/D5.9   APA_AEB/D5.9.2 judgement /If Action Subsystem2'
//  '<S376>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing'
//  '<S377>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/event  debouncing'
//  '<S378>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/time debouncing'
//  '<S379>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/updown event debouncing'
//  '<S380>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/updown time debouncing'
//  '<S381>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/event  debouncing/event debouncing1'
//  '<S382>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/event  debouncing/event debouncing2'
//  '<S383>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/time debouncing/time debouncing1'
//  '<S384>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/updown event debouncing/updown event debouncing1'
//  '<S385>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/updown event debouncing/updown event debouncing12'
//  '<S386>' : 'truck_adas/TRUCK_ADAS/D6 DSM/debouncing/updown time debouncing/up//down time debouncing1'

#endif                                 // RTW_HEADER_truck_adas_h_

//
// File trailer for generated code.
//
// [EOF]
//
