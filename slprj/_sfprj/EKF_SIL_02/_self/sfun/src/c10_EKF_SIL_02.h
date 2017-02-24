#ifndef __c10_EKF_SIL_02_h__
#define __c10_EKF_SIL_02_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_EKF_SIL_02InstanceStruct
#define typedef_SFc10_EKF_SIL_02InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  boolean_T c10_isStable;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_EKF_SIL_02;
  real_T (*c10_q_nominal)[4];
  real_T (*c10_S)[144];
  real_T (*c10_ita_nominal)[4];
  real_T (*c10_cov_r)[9];
  real_T (*c10_cov_nu)[16];
} SFc10_EKF_SIL_02InstanceStruct;

#endif                                 /*typedef_SFc10_EKF_SIL_02InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_EKF_SIL_02_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_EKF_SIL_02_get_check_sum(mxArray *plhs[]);
extern void c10_EKF_SIL_02_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
