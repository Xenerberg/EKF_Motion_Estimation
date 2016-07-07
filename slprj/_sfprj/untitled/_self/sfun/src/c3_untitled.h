#ifndef __c3_untitled_h__
#define __c3_untitled_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_untitledInstanceStruct
#define typedef_SFc3_untitledInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c3_event_trigEventCounter;
  int32_T c3_sfEvent;
  uint8_T c3_tp_State_on;
  uint8_T c3_tp_State_trigg;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_untitled;
  uint8_T c3_is_c3_untitled;
  uint32_T c3_method;
  boolean_T c3_method_not_empty;
  uint32_T c3_state[2];
  boolean_T c3_state_not_empty;
  uint32_T c3_b_method;
  boolean_T c3_b_method_not_empty;
  uint32_T c3_b_state;
  boolean_T c3_b_state_not_empty;
  uint32_T c3_c_state[2];
  boolean_T c3_c_state_not_empty;
  uint32_T c3_d_state[625];
  boolean_T c3_d_state_not_empty;
  uint32_T c3_temporalCounter_i1;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  boolean_T *c3_event_trig;
} SFc3_untitledInstanceStruct;

#endif                                 /*typedef_SFc3_untitledInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_untitled_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_untitled_get_check_sum(mxArray *plhs[]);
extern void c3_untitled_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
