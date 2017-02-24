#ifndef __c6_EKF_SIL_02_h__
#define __c6_EKF_SIL_02_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_EKF_SIL_02InstanceStruct
#define typedef_SFc6_EKF_SIL_02InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_EKF_SIL_02;
  real_T (*c6_X_a)[20];
  real_T (*c6_Phi)[324];
  real_T *c6_n;
  real_T *c6_t_Kalman;
  real_T (*c6_p)[3];
  real_T (*c6_M)[9];
  real_T (*c6_V)[6];
} SFc6_EKF_SIL_02InstanceStruct;

#endif                                 /*typedef_SFc6_EKF_SIL_02InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_EKF_SIL_02_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_EKF_SIL_02_get_check_sum(mxArray *plhs[]);
extern void c6_EKF_SIL_02_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
