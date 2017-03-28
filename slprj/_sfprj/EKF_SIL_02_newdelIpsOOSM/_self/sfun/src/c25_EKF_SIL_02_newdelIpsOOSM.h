#ifndef __c25_EKF_SIL_02_newdelIpsOOSM_h__
#define __c25_EKF_SIL_02_newdelIpsOOSM_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
#define typedef_SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c25_sfEvent;
  boolean_T c25_isStable;
  boolean_T c25_doneDoubleBufferReInit;
  uint8_T c25_is_active_c25_EKF_SIL_02_newdelIpsOOSM;
  real_T (*c25_Sk_data)[144];
  int32_T (*c25_Sk_sizes)[2];
  real_T (*c25_U1)[324];
  real_T (*c25_del_x_data)[12];
  int32_T *c25_del_x_sizes;
  real_T (*c25_UF)[324];
  real_T (*c25_Pd)[324];
  real_T (*c25_U)[324];
  real_T (*c25_xd)[18];
  real_T (*c25_Pd1)[324];
  real_T (*c25_H_data)[216];
  int32_T (*c25_H_sizes)[2];
  real_T (*c25_x_d)[18];
  real_T (*c25_K_data)[216];
  int32_T (*c25_K_sizes)[2];
  real_T (*c25_Phi)[324];
} SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct;

#endif                                 /*typedef_SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c25_EKF_SIL_02_newdelIpsOOSM_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c25_EKF_SIL_02_newdelIpsOOSM_get_check_sum(mxArray *plhs[]);
extern void c25_EKF_SIL_02_newdelIpsOOSM_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
