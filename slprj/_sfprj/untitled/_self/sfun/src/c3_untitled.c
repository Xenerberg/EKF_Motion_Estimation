/* Include files */

#include <stddef.h>
#include "blas.h"
#include "untitled_sfun.h"
#include "c3_untitled.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_State_on                 ((uint8_T)1U)
#define c3_IN_State_trigg              ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void c3_durationReferenceTimeUpdater(SFc3_untitledInstanceStruct
  *chartInstance);
static void initialize_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void initialize_params_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance);
static void enable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void disable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c3_untitled(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_untitled
  (SFc3_untitledInstanceStruct *chartInstance);
static void finalize_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void sf_gateway_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void mdl_start_c3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static void initSimStructsc3_untitled(SFc3_untitledInstanceStruct *chartInstance);
static real_T c3_randn(SFc3_untitledInstanceStruct *chartInstance);
static void c3_genrandu(SFc3_untitledInstanceStruct *chartInstance, uint32_T
  c3_s, uint32_T *c3_e_state, real_T *c3_r);
static void c3_eml_rand_shr3cong(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[2], uint32_T c3_f_state[2], real_T *c3_r);
static real_T c3_abs(SFc3_untitledInstanceStruct *chartInstance, real_T c3_x);
static real_T c3_exp(SFc3_untitledInstanceStruct *chartInstance, real_T c3_x);
static void c3_eml_rand_mt19937ar(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[625]);
static void c3_twister_state_vector(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625]);
static void c3_b_eml_rand_mt19937ar(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[625], uint32_T c3_f_state[625], real_T *c3_r);
static void c3_assert_valid_state(SFc3_untitledInstanceStruct *chartInstance);
static void c3_genrand_uint32_vector(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_mt[625], uint32_T c3_b_mt[625], uint32_T c3_u[2]);
static void c3_b_genrandu(SFc3_untitledInstanceStruct *chartInstance, uint32_T
  c3_mt[625], uint32_T c3_b_mt[625], real_T *c3_r);
static void c3_error(SFc3_untitledInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_b_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier);
static boolean_T c3_c_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint32_T c3_d_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_b_event_trigEventCounter, const char_T *c3_identifier);
static uint32_T c3_e_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_b_tp_State_on, const char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint32_T c3_i_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_c_method, const char_T *c3_identifier, boolean_T *c3_svPtr);
static uint32_T c3_j_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  *c3_svPtr);
static void c3_k_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_e_state, const char_T *c3_identifier, boolean_T *c3_svPtr,
  uint32_T c3_y[625]);
static void c3_l_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  *c3_svPtr, uint32_T c3_y[625]);
static void c3_m_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_e_state, const char_T *c3_identifier, boolean_T *c3_svPtr,
  uint32_T c3_y[2]);
static void c3_n_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  *c3_svPtr, uint32_T c3_y[2]);
static const mxArray *c3_o_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_p_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_untitledInstanceStruct
  *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_untitledInstanceStruct
  *chartInstance);
static real_T c3_b_eml_rand_shr3cong(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[2]);
static void c3_b_exp(SFc3_untitledInstanceStruct *chartInstance, real_T *c3_x);
static void c3_b_twister_state_vector(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_mt[625], real_T c3_seed);
static real_T c3_c_eml_rand_mt19937ar(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[625]);
static void c3_b_genrand_uint32_vector(SFc3_untitledInstanceStruct
  *chartInstance, uint32_T c3_mt[625], uint32_T c3_u[2]);
static real_T c3_c_genrandu(SFc3_untitledInstanceStruct *chartInstance, uint32_T
  c3_mt[625]);
static void init_dsm_address_info(SFc3_untitledInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void c3_durationReferenceTimeUpdater(SFc3_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_untitled(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_method_not_empty = false;
  chartInstance->c3_state_not_empty = false;
  chartInstance->c3_b_method_not_empty = false;
  chartInstance->c3_b_state_not_empty = false;
  chartInstance->c3_c_state_not_empty = false;
  chartInstance->c3_d_state_not_empty = false;
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_State_on = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_State_trigg = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_is_active_c3_untitled = 0U;
  chartInstance->c3_is_c3_untitled = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_event_trigEventCounter = 0U;
  *chartInstance->c3_event_trig = false;
}

static void initialize_params_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_untitled == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_untitled == c3_IN_State_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_untitled == c3_IN_State_trigg) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_untitled(SFc3_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  uint32_T c3_hoistedGlobal;
  uint32_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint32_T c3_b_hoistedGlobal;
  uint32_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint32_T c3_c_hoistedGlobal;
  uint32_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  boolean_T c3_d_hoistedGlobal;
  boolean_T c3_d_u;
  const mxArray *c3_h_y = NULL;
  uint32_T c3_e_hoistedGlobal;
  uint32_T c3_e_u;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_k_y = NULL;
  uint32_T c3_h_hoistedGlobal;
  uint32_T c3_h_u;
  const mxArray *c3_l_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(11, 1), false);
  c3_hoistedGlobal = chartInstance->c3_b_method;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  if (!chartInstance->c3_b_method_not_empty) {
    sf_mex_assign(&c3_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_method;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  if (!chartInstance->c3_b_method_not_empty) {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_b_state;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  if (!chartInstance->c3_b_method_not_empty) {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_e_y = NULL;
  if (!chartInstance->c3_d_state_not_empty) {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", chartInstance->c3_d_state, 7, 0U,
      1U, 0U, 1, 625), false);
  }

  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_f_y = NULL;
  if (!chartInstance->c3_c_state_not_empty) {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", chartInstance->c3_c_state, 7, 0U,
      1U, 0U, 1, 2), false);
  }

  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_g_y = NULL;
  if (!chartInstance->c3_c_state_not_empty) {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", chartInstance->c3_state, 7, 0U, 1U,
      0U, 1, 2), false);
  }

  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_d_hoistedGlobal = *chartInstance->c3_event_trig;
  c3_d_u = c3_d_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_e_hoistedGlobal = chartInstance->c3_event_trigEventCounter;
  c3_e_u = c3_e_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_active_c3_untitled;
  c3_f_u = c3_f_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_c3_untitled;
  c3_g_u = c3_g_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_h_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_h_u = c3_h_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_h_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_untitled(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  uint32_T c3_uv0[625];
  int32_T c3_i0;
  uint32_T c3_uv1[2];
  int32_T c3_i1;
  uint32_T c3_uv2[2];
  int32_T c3_i2;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_b_method = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("method", c3_u, 0)), "method",
    &chartInstance->c3_b_method_not_empty);
  chartInstance->c3_method = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("method", c3_u, 1)), "method",
    &chartInstance->c3_method_not_empty);
  chartInstance->c3_b_state = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("state", c3_u, 2)), "state",
    &chartInstance->c3_b_state_not_empty);
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("state", c3_u,
    3)), "state", &chartInstance->c3_d_state_not_empty, c3_uv0);
  for (c3_i0 = 0; c3_i0 < 625; c3_i0++) {
    chartInstance->c3_d_state[c3_i0] = c3_uv0[c3_i0];
  }

  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("state", c3_u,
    4)), "state", &chartInstance->c3_c_state_not_empty, c3_uv1);
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    chartInstance->c3_c_state[c3_i1] = c3_uv1[c3_i1];
  }

  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("state", c3_u,
    5)), "state", &chartInstance->c3_state_not_empty, c3_uv2);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    chartInstance->c3_state[c3_i2] = c3_uv2[c3_i2];
  }

  *chartInstance->c3_event_trig = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("event_trig", c3_u, 6)), "event_trig");
  chartInstance->c3_event_trigEventCounter = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("event_trigEventCounter", c3_u, 7)),
    "event_trigEventCounter");
  chartInstance->c3_is_active_c3_untitled = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c3_untitled", c3_u, 8)),
    "is_active_c3_untitled");
  chartInstance->c3_is_c3_untitled = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c3_untitled", c3_u, 9)), "is_c3_untitled");
  chartInstance->c3_temporalCounter_i1 = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("temporalCounter_i1", c3_u, 10)),
    "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 11)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_untitled(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_untitled
  (SFc3_untitledInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_untitled == c3_IN_State_on) {
      chartInstance->c3_tp_State_on = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_State_on = 0U;
    }

    if (chartInstance->c3_is_c3_untitled == c3_IN_State_trigg) {
      chartInstance->c3_tp_State_trigg = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_State_trigg = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_hoistedGlobal;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_A;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_y;
  int8_T c3_temp;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  c3_set_sim_state_side_effects_c3_untitled(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  c3_durationReferenceTimeUpdater(chartInstance);
  if (chartInstance->c3_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c3_temporalCounter_i1++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_untitled == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_untitled = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_untitled = c3_IN_State_on;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i1 = 0U;
    chartInstance->c3_tp_State_on = 1U;
  } else {
    switch (chartInstance->c3_is_c3_untitled) {
     case c3_IN_State_on:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_b_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
      c3_x = c3_randn(chartInstance) * 0.01 * 100.0;
      c3_b_x = c3_x;
      c3_b_x = muDoubleScalarRound(c3_b_x);
      c3_A = c3_b_x;
      c3_c_x = c3_A;
      c3_d_x = c3_c_x;
      c3_y = c3_d_x / 100.0;
      c3_temp = (int8_T)(c3_hoistedGlobal >= (uint32_T)muDoubleScalarCeil((0.1 +
        c3_y) / 0.001 - 1.0000000000000001E-11));
      c3_out = CV_EML_IF(1, 0, 0, c3_temp);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_State_on = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_untitled = c3_IN_State_trigg;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_State_trigg = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        chartInstance->c3_event_trigEventCounter++;
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_State_trigg:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_c_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_b_out = CV_EML_IF(2, 0, 0, chartInstance->c3_temporalCounter_i1 >= 10U);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_State_trigg = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_untitled = c3_IN_State_on;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_State_on = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_c3_untitled = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_event_trigEventCounter > 0U) {
    *chartInstance->c3_event_trig = !*chartInstance->c3_event_trig;
    chartInstance->c3_event_trigEventCounter--;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitledMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc3_untitled(SFc3_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_randn(SFc3_untitledInstanceStruct *chartInstance)
{
  real_T c3_r;
  int32_T c3_i3;
  uint32_T c3_hoistedGlobal;
  uint32_T c3_e_state;
  uint32_T c3_f_state;
  uint32_T c3_g_state;
  uint32_T c3_h_state;
  real_T c3_b_r;
  uint32_T c3_i_state;
  real_T c3_c_r;
  real_T c3_t;
  uint32_T c3_j_state;
  real_T c3_b_t;
  real_T c3_d0;
  int32_T c3_i4;
  real_T c3_d1;
  uint32_T c3_uv3[625];
  int32_T c3_i5;
  real_T c3_d2;
  uint32_T c3_b_hoistedGlobal;
  uint32_T c3_k_state;
  uint32_T c3_u0;
  uint32_T c3_l_state;
  uint32_T c3_m_state;
  real_T c3_d_r;
  uint32_T c3_n_state;
  real_T c3_e_r;
  real_T c3_c_t;
  uint32_T c3_o_state;
  real_T c3_d_t;
  real_T c3_d3;
  real_T c3_d4;
  if (!chartInstance->c3_method_not_empty) {
    chartInstance->c3_method = 0U;
    chartInstance->c3_method_not_empty = true;
    for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
      chartInstance->c3_state[c3_i3] = 362436069U + (uint32_T)(-362436069 *
        c3_i3);
    }

    if ((real_T)chartInstance->c3_state[1] == 0.0) {
      chartInstance->c3_state[1] = 521288629U;
    }

    chartInstance->c3_state_not_empty = true;
  }

  if (chartInstance->c3_method == 0U) {
    if (!chartInstance->c3_b_method_not_empty) {
      chartInstance->c3_b_method = 7U;
      chartInstance->c3_b_method_not_empty = true;
    }

    if (chartInstance->c3_b_method == 4U) {
      if (!chartInstance->c3_b_state_not_empty) {
        chartInstance->c3_b_state = 1144108930U;
        chartInstance->c3_b_state_not_empty = true;
      }

      c3_hoistedGlobal = chartInstance->c3_b_state;
      c3_e_state = c3_hoistedGlobal;
      c3_f_state = c3_e_state;
      c3_g_state = c3_f_state;
      c3_h_state = c3_g_state;
      do {
        c3_genrandu(chartInstance, c3_h_state, &c3_i_state, &c3_b_r);
        c3_h_state = c3_i_state;
        c3_c_r = c3_b_r;
        c3_genrandu(chartInstance, c3_h_state, &c3_j_state, &c3_t);
        c3_h_state = c3_j_state;
        c3_b_t = c3_t;
        c3_c_r = 2.0 * c3_c_r - 1.0;
        c3_b_t = 2.0 * c3_b_t - 1.0;
        c3_b_t = c3_b_t * c3_b_t + c3_c_r * c3_c_r;
      } while (!(c3_b_t <= 1.0));

      c3_c_r *= muDoubleScalarSqrt(-2.0 * muDoubleScalarLog(c3_b_t) / c3_b_t);
      c3_f_state = c3_h_state;
      c3_d0 = c3_c_r;
      chartInstance->c3_b_state = c3_f_state;
      c3_r = c3_d0;
    } else if (chartInstance->c3_b_method == 5U) {
      if (!chartInstance->c3_c_state_not_empty) {
        for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
          chartInstance->c3_c_state[c3_i4] = 362436069U + 158852560U * (uint32_T)
            c3_i4;
        }

        chartInstance->c3_c_state_not_empty = true;
      }

      c3_d1 = c3_b_eml_rand_shr3cong(chartInstance, chartInstance->c3_c_state);
      c3_r = c3_d1;
    } else {
      if (!chartInstance->c3_d_state_not_empty) {
        c3_eml_rand_mt19937ar(chartInstance, c3_uv3);
        for (c3_i5 = 0; c3_i5 < 625; c3_i5++) {
          chartInstance->c3_d_state[c3_i5] = c3_uv3[c3_i5];
        }

        chartInstance->c3_d_state_not_empty = true;
      }

      c3_d2 = c3_c_eml_rand_mt19937ar(chartInstance, chartInstance->c3_d_state);
      c3_r = c3_d2;
    }
  } else {
    c3_b_hoistedGlobal = chartInstance->c3_method;
    if (c3_b_hoistedGlobal == 4U) {
      c3_k_state = chartInstance->c3_state[0];
      c3_u0 = c3_k_state;
      c3_l_state = c3_u0;
      c3_m_state = c3_l_state;
      do {
        c3_genrandu(chartInstance, c3_m_state, &c3_n_state, &c3_d_r);
        c3_m_state = c3_n_state;
        c3_e_r = c3_d_r;
        c3_genrandu(chartInstance, c3_m_state, &c3_o_state, &c3_c_t);
        c3_m_state = c3_o_state;
        c3_d_t = c3_c_t;
        c3_e_r = 2.0 * c3_e_r - 1.0;
        c3_d_t = 2.0 * c3_d_t - 1.0;
        c3_d_t = c3_d_t * c3_d_t + c3_e_r * c3_e_r;
      } while (!(c3_d_t <= 1.0));

      c3_e_r *= muDoubleScalarSqrt(-2.0 * muDoubleScalarLog(c3_d_t) / c3_d_t);
      c3_u0 = c3_m_state;
      c3_d3 = c3_e_r;
      chartInstance->c3_state[0] = c3_u0;
      c3_r = c3_d3;
    } else {
      c3_d4 = c3_b_eml_rand_shr3cong(chartInstance, chartInstance->c3_state);
      c3_r = c3_d4;
    }
  }

  return c3_r;
}

static void c3_genrandu(SFc3_untitledInstanceStruct *chartInstance, uint32_T
  c3_s, uint32_T *c3_e_state, real_T *c3_r)
{
  uint32_T c3_u1;
  uint32_T c3_hi;
  uint32_T c3_lo;
  uint32_T c3_test1;
  uint32_T c3_test2;
  (void)chartInstance;
  c3_u1 = 127773U;
  if (c3_u1 == 0U) {
    c3_hi = MAX_uint32_T;
  } else {
    c3_hi = c3_s / c3_u1;
  }

  c3_lo = c3_s - c3_hi * 127773U;
  c3_test1 = 16807U * c3_lo;
  c3_test2 = 2836U * c3_hi;
  if (c3_test1 < c3_test2) {
    *c3_e_state = (c3_test1 - c3_test2) + 2147483647U;
  } else {
    *c3_e_state = c3_test1 - c3_test2;
  }

  *c3_r = (real_T)*c3_e_state * 4.6566128752457969E-10;
}

static void c3_eml_rand_shr3cong(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[2], uint32_T c3_f_state[2], real_T *c3_r)
{
  int32_T c3_i6;
  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_f_state[c3_i6] = c3_e_state[c3_i6];
  }

  *c3_r = c3_b_eml_rand_shr3cong(chartInstance, c3_f_state);
}

static real_T c3_abs(SFc3_untitledInstanceStruct *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  real_T c3_c_x;
  (void)chartInstance;
  c3_b_x = c3_x;
  c3_c_x = c3_b_x;
  return muDoubleScalarAbs(c3_c_x);
}

static real_T c3_exp(SFc3_untitledInstanceStruct *chartInstance, real_T c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_exp(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_eml_rand_mt19937ar(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[625])
{
  int32_T c3_i7;
  for (c3_i7 = 0; c3_i7 < 625; c3_i7++) {
    c3_e_state[c3_i7] = 0U;
  }

  c3_b_twister_state_vector(chartInstance, c3_e_state, 5489.0);
}

static void c3_twister_state_vector(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625])
{
  int32_T c3_i8;
  for (c3_i8 = 0; c3_i8 < 625; c3_i8++) {
    c3_b_mt[c3_i8] = c3_mt[c3_i8];
  }

  c3_b_twister_state_vector(chartInstance, c3_b_mt, c3_seed);
}

static void c3_b_eml_rand_mt19937ar(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[625], uint32_T c3_f_state[625], real_T *c3_r)
{
  int32_T c3_i9;
  for (c3_i9 = 0; c3_i9 < 625; c3_i9++) {
    c3_f_state[c3_i9] = c3_e_state[c3_i9];
  }

  *c3_r = c3_c_eml_rand_mt19937ar(chartInstance, c3_f_state);
}

static void c3_assert_valid_state(SFc3_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_genrand_uint32_vector(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_mt[625], uint32_T c3_b_mt[625], uint32_T c3_u[2])
{
  int32_T c3_i10;
  for (c3_i10 = 0; c3_i10 < 625; c3_i10++) {
    c3_b_mt[c3_i10] = c3_mt[c3_i10];
  }

  c3_b_genrand_uint32_vector(chartInstance, c3_b_mt, c3_u);
}

static void c3_b_genrandu(SFc3_untitledInstanceStruct *chartInstance, uint32_T
  c3_mt[625], uint32_T c3_b_mt[625], real_T *c3_r)
{
  int32_T c3_i11;
  for (c3_i11 = 0; c3_i11 < 625; c3_i11++) {
    c3_b_mt[c3_i11] = c3_mt[c3_i11];
  }

  *c3_r = c3_c_genrandu(chartInstance, c3_b_mt);
}

static void c3_error(SFc3_untitledInstanceStruct *chartInstance)
{
  const mxArray *c3_y = NULL;
  static char_T c3_u[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c3_y));
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d5;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d5, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d5;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_b_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_sf_internal_predicateOutput, const char_T
  *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  return c3_y;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint32_T c3_d_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_b_event_trigEventCounter, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_event_trigEventCounter), &c3_thisId);
  sf_mex_destroy(&c3_b_event_trigEventCounter);
  return c3_y;
}

static uint32_T c3_e_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u2, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_event_trigEventCounter;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint32_T c3_y;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_b_event_trigEventCounter = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_event_trigEventCounter), &c3_thisId);
  sf_mex_destroy(&c3_b_event_trigEventCounter);
  *(uint32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i12;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i12, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i12;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_b_tp_State_on, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_State_on),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_State_on);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u3, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_State_on;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)chartInstanceVoid;
  c3_b_tp_State_on = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_State_on),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_State_on);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint32_T c3_i_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_c_method, const char_T *c3_identifier, boolean_T *c3_svPtr)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_method),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_c_method);
  return c3_y;
}

static uint32_T c3_j_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  *c3_svPtr)
{
  uint32_T c3_y;
  uint32_T c3_u4;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u4, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u4;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_k_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_e_state, const char_T *c3_identifier, boolean_T *c3_svPtr,
  uint32_T c3_y[625])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_e_state), &c3_thisId,
                        c3_svPtr, c3_y);
  sf_mex_destroy(&c3_e_state);
}

static void c3_l_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  *c3_svPtr, uint32_T c3_y[625])
{
  uint32_T c3_uv4[625];
  int32_T c3_i13;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv4, 1, 7, 0U, 1, 0U, 1, 625);
    for (c3_i13 = 0; c3_i13 < 625; c3_i13++) {
      c3_y[c3_i13] = c3_uv4[c3_i13];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_m_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_e_state, const char_T *c3_identifier, boolean_T *c3_svPtr,
  uint32_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_e_state), &c3_thisId,
                        c3_svPtr, c3_y);
  sf_mex_destroy(&c3_e_state);
}

static void c3_n_emlrt_marshallIn(SFc3_untitledInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T
  *c3_svPtr, uint32_T c3_y[2])
{
  uint32_T c3_uv5[2];
  int32_T c3_i14;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv5, 1, 7, 0U, 1, 0U, 1, 2);
    for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
      c3_y[c3_i14] = c3_uv5[c3_i14];
    }
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_o_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_p_emlrt_marshallIn(SFc3_untitledInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc3_untitledInstanceStruct
  *chartInstance, int32_T c3_ssid)
{
  (void)chartInstance;
  (void)c3_ssid;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c3_b_eml_rand_shr3cong(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[2])
{
  uint32_T c3_icng;
  uint32_T c3_jsr;
  uint32_T c3_b_icng;
  uint32_T c3_b_jsr;
  uint32_T c3_c_jsr;
  uint32_T c3_c_icng;
  uint32_T c3_ui;
  uint32_T c3_b_ui;
  uint32_T c3_j;
  uint32_T c3_jp1;
  int32_T c3_i;
  static real_T c3_dv0[65] = { 0.340945, 0.4573146, 0.5397793, 0.6062427,
    0.6631691, 0.7136975, 0.7596125, 0.8020356, 0.8417227, 0.8792102, 0.9148948,
    0.9490791, 0.9820005, 1.0138492, 1.044781, 1.0749254, 1.1043917, 1.1332738,
    1.161653, 1.189601, 1.2171815, 1.2444516, 1.2714635, 1.298265, 1.3249008,
    1.3514125, 1.3778399, 1.4042211, 1.4305929, 1.4569915, 1.4834527, 1.5100122,
    1.5367061, 1.5635712, 1.5906454, 1.617968, 1.6455802, 1.6735255, 1.7018503,
    1.7306045, 1.7598422, 1.7896223, 1.8200099, 1.851077, 1.8829044, 1.9155831,
    1.9492166, 1.9839239, 2.0198431, 2.0571356, 2.095993, 2.136645, 2.1793713,
    2.2245175, 2.2725186, 2.3239338, 2.3795008, 2.4402218, 2.5075117, 2.5834658,
    2.6713916, 2.7769942, 2.7769942, 2.7769942, 2.7769942 };

  real_T c3_b_r;
  real_T c3_c_r;
  real_T c3_A;
  real_T c3_B;
  real_T c3_x;
  real_T c3_y;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  uint32_T c3_d_icng;
  uint32_T c3_d_jsr;
  uint32_T c3_e_jsr;
  uint32_T c3_e_icng;
  uint32_T c3_c_ui;
  real_T c3_c_y;
  real_T c3_s;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_f_x;
  real_T c3_d_y;
  real_T c3_g_x;
  real_T c3_e_y;
  real_T c3_f_y;
  uint32_T c3_f_icng;
  uint32_T c3_f_jsr;
  uint32_T c3_g_jsr;
  uint32_T c3_g_icng;
  uint32_T c3_d_ui;
  real_T c3_c_A;
  real_T c3_h_x;
  real_T c3_i_x;
  uint32_T c3_h_icng;
  uint32_T c3_h_jsr;
  uint32_T c3_i_jsr;
  uint32_T c3_i_icng;
  uint32_T c3_e_ui;
  c3_icng = c3_e_state[0];
  c3_jsr = c3_e_state[1];
  c3_b_icng = c3_icng;
  c3_b_jsr = c3_jsr;
  c3_c_jsr = c3_b_jsr;
  c3_c_icng = c3_b_icng;
  c3_c_icng = 69069U * c3_c_icng + 1234567U;
  c3_c_jsr ^= c3_c_jsr << 13;
  c3_c_jsr ^= c3_c_jsr >> 17;
  c3_c_jsr ^= c3_c_jsr << 5;
  c3_ui = c3_c_icng + c3_c_jsr;
  c3_icng = c3_c_icng;
  c3_jsr = c3_c_jsr;
  c3_b_ui = c3_ui;
  c3_j = (c3_b_ui & 63U) + 1U;
  c3_j;
  c3_jp1 = c3_j + 1U;
  c3_i = (int32_T)c3_b_ui;
  c3_b_r = (real_T)c3_i * 4.6566128730773926E-10 * c3_dv0[(int32_T)c3_jp1 - 1];
  if (c3_abs(chartInstance, c3_b_r) <= c3_dv0[(int32_T)c3_j - 1]) {
    c3_c_r = c3_b_r;
  } else {
    c3_A = c3_abs(chartInstance, c3_b_r) - c3_dv0[(int32_T)c3_j - 1];
    c3_B = c3_dv0[(int32_T)c3_jp1 - 1] - c3_dv0[(int32_T)c3_j - 1];
    c3_x = c3_A;
    c3_y = c3_B;
    c3_b_x = c3_x;
    c3_b_y = c3_y;
    c3_c_x = c3_b_x / c3_b_y;
    c3_d_icng = c3_icng;
    c3_d_jsr = c3_jsr;
    c3_e_jsr = c3_d_jsr;
    c3_e_icng = c3_d_icng;
    c3_e_icng = 69069U * c3_e_icng + 1234567U;
    c3_e_jsr ^= c3_e_jsr << 13;
    c3_e_jsr ^= c3_e_jsr >> 17;
    c3_e_jsr ^= c3_e_jsr << 5;
    c3_c_ui = c3_e_icng + c3_e_jsr;
    c3_icng = c3_e_icng;
    c3_jsr = c3_e_jsr;
    c3_b_ui = c3_c_ui;
    c3_i = (int32_T)c3_b_ui;
    c3_c_y = 0.5 + (real_T)c3_i * 2.328306436538696E-10;
    c3_s = c3_c_x + c3_c_y;
    if (c3_s > 1.301198) {
      if (c3_b_r < 0.0) {
        c3_c_r = 0.4878992 * c3_c_x - 0.4878992;
      } else {
        c3_c_r = 0.4878992 - 0.4878992 * c3_c_x;
      }
    } else if (c3_s <= 0.9689279) {
      c3_c_r = c3_b_r;
    } else {
      c3_c_x = 0.4878992 - 0.4878992 * c3_c_x;
      if (c3_c_y > 12.67706 - 12.37586 * muDoubleScalarExp(-0.5 * c3_c_x *
           c3_c_x)) {
        if (c3_b_r < 0.0) {
          c3_c_r = -c3_c_x;
        } else {
          c3_c_r = c3_c_x;
        }
      } else {
        c3_d_x = -0.5 * c3_dv0[(int32_T)c3_jp1 - 1] * c3_dv0[(int32_T)c3_jp1 - 1];
        c3_e_x = c3_d_x;
        c3_e_x = muDoubleScalarExp(c3_e_x);
        c3_b_A = c3_c_y * 0.01958303;
        c3_b_B = c3_dv0[(int32_T)c3_jp1 - 1];
        c3_f_x = c3_b_A;
        c3_d_y = c3_b_B;
        c3_g_x = c3_f_x;
        c3_e_y = c3_d_y;
        c3_f_y = c3_g_x / c3_e_y;
        if (c3_e_x + c3_f_y <= muDoubleScalarExp(-0.5 * c3_b_r * c3_b_r)) {
          c3_c_r = c3_b_r;
        } else {
          do {
            c3_f_icng = c3_icng;
            c3_f_jsr = c3_jsr;
            c3_g_jsr = c3_f_jsr;
            c3_g_icng = c3_f_icng;
            c3_g_icng = 69069U * c3_g_icng + 1234567U;
            c3_g_jsr ^= c3_g_jsr << 13;
            c3_g_jsr ^= c3_g_jsr >> 17;
            c3_g_jsr ^= c3_g_jsr << 5;
            c3_d_ui = c3_g_icng + c3_g_jsr;
            c3_icng = c3_g_icng;
            c3_jsr = c3_g_jsr;
            c3_b_ui = c3_d_ui;
            c3_i = (int32_T)c3_b_ui;
            c3_c_A = muDoubleScalarLog(0.5 + (real_T)c3_i *
              2.328306436538696E-10);
            c3_h_x = c3_c_A;
            c3_i_x = c3_h_x;
            c3_c_x = c3_i_x / 2.776994;
            c3_h_icng = c3_icng;
            c3_h_jsr = c3_jsr;
            c3_i_jsr = c3_h_jsr;
            c3_i_icng = c3_h_icng;
            c3_i_icng = 69069U * c3_i_icng + 1234567U;
            c3_i_jsr ^= c3_i_jsr << 13;
            c3_i_jsr ^= c3_i_jsr >> 17;
            c3_i_jsr ^= c3_i_jsr << 5;
            c3_e_ui = c3_i_icng + c3_i_jsr;
            c3_icng = c3_i_icng;
            c3_jsr = c3_i_jsr;
            c3_b_ui = c3_e_ui;
            c3_i = (int32_T)c3_b_ui;
          } while (!(-2.0 * muDoubleScalarLog(0.5 + (real_T)c3_i *
                     2.328306436538696E-10) > c3_c_x * c3_c_x));

          if (c3_b_r < 0.0) {
            c3_c_r = c3_c_x - 2.776994;
          } else {
            c3_c_r = 2.776994 - c3_c_x;
          }
        }
      }
    }
  }

  c3_e_state[0] = c3_icng;
  c3_e_state[1] = c3_jsr;
  return c3_c_r;
}

static void c3_b_exp(SFc3_untitledInstanceStruct *chartInstance, real_T *c3_x)
{
  (void)chartInstance;
  *c3_x = muDoubleScalarExp(*c3_x);
}

static void c3_b_twister_state_vector(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_mt[625], real_T c3_seed)
{
  real_T c3_d6;
  uint32_T c3_u5;
  uint32_T c3_r;
  int32_T c3_mti;
  real_T c3_b_mti;
  real_T c3_d7;
  uint32_T c3_u6;
  (void)chartInstance;
  c3_d6 = c3_seed;
  if (c3_d6 < 4.294967296E+9) {
    if (c3_d6 >= 0.0) {
      c3_u5 = (uint32_T)c3_d6;
    } else {
      c3_u5 = 0U;
    }
  } else if (c3_d6 >= 4.294967296E+9) {
    c3_u5 = MAX_uint32_T;
  } else {
    c3_u5 = 0U;
  }

  c3_r = c3_u5;
  c3_mt[0] = c3_r;
  for (c3_mti = 0; c3_mti < 623; c3_mti++) {
    c3_b_mti = 2.0 + (real_T)c3_mti;
    c3_d7 = muDoubleScalarRound(c3_b_mti - 1.0);
    if (c3_d7 < 4.294967296E+9) {
      if (c3_d7 >= 0.0) {
        c3_u6 = (uint32_T)c3_d7;
      } else {
        c3_u6 = 0U;
      }
    } else if (c3_d7 >= 4.294967296E+9) {
      c3_u6 = MAX_uint32_T;
    } else {
      c3_u6 = 0U;
    }

    c3_r = (c3_r ^ c3_r >> 30U) * 1812433253U + c3_u6;
    c3_mt[(int32_T)c3_b_mti - 1] = c3_r;
  }

  c3_mt[624] = 624U;
}

static real_T c3_c_eml_rand_mt19937ar(SFc3_untitledInstanceStruct *chartInstance,
  uint32_T c3_e_state[625])
{
  uint32_T c3_u32[2];
  uint32_T c3_i;
  uint32_T c3_ip1;
  real_T c3_u;
  static real_T c3_dv1[257] = { 0.0, 0.215241895984875, 0.286174591792068,
    0.335737519214422, 0.375121332878378, 0.408389134611989, 0.43751840220787,
    0.46363433679088, 0.487443966139235, 0.50942332960209, 0.529909720661557,
    0.549151702327164, 0.567338257053817, 0.584616766106378, 0.601104617755991,
    0.61689699000775, 0.63207223638606, 0.646695714894993, 0.660822574244419,
    0.674499822837293, 0.687767892795788, 0.700661841106814, 0.713212285190975,
    0.725446140909999, 0.737387211434295, 0.749056662017815, 0.760473406430107,
    0.771654424224568, 0.782615023307232, 0.793369058840623, 0.80392911698997,
    0.814306670135215, 0.824512208752291, 0.834555354086381, 0.844444954909153,
    0.854189171008163, 0.863795545553308, 0.87327106808886, 0.882622229585165,
    0.891855070732941, 0.900975224461221, 0.909987953496718, 0.91889818364959,
    0.927710533401999, 0.936429340286575, 0.945058684468165, 0.953602409881086,
    0.96206414322304, 0.970447311064224, 0.978755155294224, 0.986990747099062,
    0.99515699963509, 1.00325667954467, 1.01129241744, 1.01926671746548,
    1.02718196603564, 1.03504043983344, 1.04284431314415, 1.05059566459093,
    1.05829648333067, 1.06594867476212, 1.07355406579244, 1.0811144097034,
    1.08863139065398, 1.09610662785202, 1.10354167942464, 1.11093804601357,
    1.11829717411934, 1.12562045921553, 1.13290924865253, 1.14016484436815,
    1.14738850542085, 1.15458145035993, 1.16174485944561, 1.16887987673083,
    1.17598761201545, 1.18306914268269, 1.19012551542669, 1.19715774787944,
    1.20416683014438, 1.2111537262437, 1.21811937548548, 1.22506469375653,
    1.23199057474614, 1.23889789110569, 1.24578749554863, 1.2526602218949,
    1.25951688606371, 1.26635828701823, 1.27318520766536, 1.27999841571382,
    1.28679866449324, 1.29358669373695, 1.30036323033084, 1.30712898903073,
    1.31388467315022, 1.32063097522106, 1.32736857762793, 1.33409815321936,
    1.3408203658964, 1.34753587118059, 1.35424531676263, 1.36094934303328,
    1.36764858359748, 1.37434366577317, 1.38103521107586, 1.38772383568998,
    1.39441015092814, 1.40109476367925, 1.4077782768464, 1.41446128977547,
    1.42114439867531, 1.42782819703026, 1.43451327600589, 1.44120022484872,
    1.44788963128058, 1.45458208188841, 1.46127816251028, 1.46797845861808,
    1.47468355569786, 1.48139403962819, 1.48811049705745, 1.49483351578049,
    1.50156368511546, 1.50830159628131, 1.51504784277671, 1.521803020761,
    1.52856772943771, 1.53534257144151, 1.542128153229, 1.54892508547417,
    1.55573398346918, 1.56255546753104, 1.56939016341512, 1.57623870273591,
    1.58310172339603, 1.58997987002419, 1.59687379442279, 1.60378415602609,
    1.61071162236983, 1.61765686957301, 1.62462058283303, 1.63160345693487,
    1.63860619677555, 1.64562951790478, 1.65267414708306, 1.65974082285818,
    1.66683029616166, 1.67394333092612, 1.68108070472517, 1.68824320943719,
    1.69543165193456, 1.70264685479992, 1.7098896570713, 1.71716091501782,
    1.72446150294804, 1.73179231405296, 1.73915426128591, 1.74654827828172,
    1.75397532031767, 1.76143636531891, 1.76893241491127, 1.77646449552452,
    1.78403365954944, 1.79164098655216, 1.79928758454972, 1.80697459135082,
    1.81470317596628, 1.82247454009388, 1.83028991968276, 1.83815058658281,
    1.84605785028518, 1.8540130597602, 1.86201760539967, 1.87007292107127,
    1.878180486293, 1.88634182853678, 1.8945585256707, 1.90283220855043,
    1.91116456377125, 1.91955733659319, 1.92801233405266, 1.93653142827569,
    1.94511656000868, 1.95376974238465, 1.96249306494436, 1.97128869793366,
    1.98015889690048, 1.98910600761744, 1.99813247135842, 2.00724083056053,
    2.0164337349062, 2.02571394786385, 2.03508435372962, 2.04454796521753,
    2.05410793165065, 2.06376754781173, 2.07353026351874, 2.0833996939983,
    2.09337963113879, 2.10347405571488, 2.11368715068665, 2.12402331568952,
    2.13448718284602, 2.14508363404789, 2.15581781987674, 2.16669518035431,
    2.17772146774029, 2.18890277162636, 2.20024554661128, 2.21175664288416,
    2.22344334009251, 2.23531338492992, 2.24737503294739, 2.25963709517379,
    2.27210899022838, 2.28480080272449, 2.29772334890286, 2.31088825060137,
    2.32430801887113, 2.33799614879653, 2.35196722737914, 2.36623705671729,
    2.38082279517208, 2.39574311978193, 2.41101841390112, 2.42667098493715,
    2.44272531820036, 2.4592083743347, 2.47614993967052, 2.49358304127105,
    2.51154444162669, 2.53007523215985, 2.54922155032478, 2.56903545268184,
    2.58957598670829, 2.61091051848882, 2.63311639363158, 2.65628303757674,
    2.68051464328574, 2.70593365612306, 2.73268535904401, 2.76094400527999,
    2.79092117400193, 2.82287739682644, 2.85713873087322, 2.89412105361341,
    2.93436686720889, 2.97860327988184, 3.02783779176959, 3.08352613200214,
    3.147889289518, 3.2245750520478, 3.32024473383983, 3.44927829856143,
    3.65415288536101, 3.91075795952492 };

  real_T c3_b_r;
  real_T c3_b_u;
  real_T c3_d8;
  static real_T c3_dv2[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  real_T c3_c_u;
  real_T c3_x;
  real_T c3_d_u;
  int32_T exitg1;
  do {
    exitg1 = 0;
    c3_b_genrand_uint32_vector(chartInstance, c3_e_state, c3_u32);
    c3_i = (c3_u32[1] >> 24U) + 1U;
    c3_ip1 = c3_i + 1U;
    c3_u = ((real_T)(c3_u32[0] >> 3U) * 1.6777216E+7 + (real_T)(c3_u32[1] &
             16777215U)) * 2.2204460492503131E-16 - 1.0;
    c3_b_r = c3_u * c3_dv1[(int32_T)c3_ip1 - 1];
    if (c3_abs(chartInstance, c3_b_r) <= c3_dv1[(int32_T)c3_i - 1]) {
      exitg1 = 1;
    } else if ((real_T)c3_i < 256.0) {
      c3_b_u = c3_c_genrandu(chartInstance, c3_e_state);
      c3_u = c3_b_u;
      c3_d8 = -0.5 * c3_b_r * c3_b_r;
      c3_b_exp(chartInstance, &c3_d8);
      if (c3_dv2[(int32_T)c3_ip1 - 1] + c3_u * (c3_dv2[(int32_T)c3_i - 1] -
           c3_dv2[(int32_T)c3_ip1 - 1]) < c3_d8) {
        exitg1 = 1;
      }
    } else {
      do {
        c3_c_u = c3_c_genrandu(chartInstance, c3_e_state);
        c3_u = c3_c_u;
        c3_x = muDoubleScalarLog(c3_u) * 0.273661237329758;
        c3_d_u = c3_c_genrandu(chartInstance, c3_e_state);
        c3_u = c3_d_u;
      } while (!(-2.0 * muDoubleScalarLog(c3_u) > c3_x * c3_x));

      if (c3_b_r < 0.0) {
        c3_b_r = c3_x - 3.65415288536101;
      } else {
        c3_b_r = 3.65415288536101 - c3_x;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c3_b_r;
}

static void c3_b_genrand_uint32_vector(SFc3_untitledInstanceStruct
  *chartInstance, uint32_T c3_mt[625], uint32_T c3_u[2])
{
  int32_T c3_i15;
  int32_T c3_j;
  real_T c3_b_j;
  uint32_T c3_mti;
  int32_T c3_kk;
  real_T c3_b_kk;
  uint32_T c3_y;
  uint32_T c3_b_y;
  uint32_T c3_c_y;
  int32_T c3_c_kk;
  uint32_T c3_d_y;
  uint32_T c3_e_y;
  uint32_T c3_f_y;
  uint32_T c3_g_y;
  (void)chartInstance;
  for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
    c3_u[c3_i15] = 0U;
  }

  for (c3_j = 0; c3_j < 2; c3_j++) {
    c3_b_j = 1.0 + (real_T)c3_j;
    c3_mti = c3_mt[624] + 1U;
    if ((real_T)c3_mti >= 625.0) {
      for (c3_kk = 0; c3_kk < 227; c3_kk++) {
        c3_b_kk = 1.0 + (real_T)c3_kk;
        c3_y = (c3_mt[(int32_T)c3_b_kk - 1] & 2147483648U) | (c3_mt[(int32_T)
          (c3_b_kk + 1.0) - 1] & 2147483647U);
        c3_b_y = c3_y;
        c3_c_y = c3_b_y;
        if ((real_T)(c3_c_y & 1U) == 0.0) {
          c3_c_y >>= 1U;
        } else {
          c3_c_y = c3_c_y >> 1U ^ 2567483615U;
        }

        c3_mt[(int32_T)c3_b_kk - 1] = c3_mt[(int32_T)(c3_b_kk + 397.0) - 1] ^
          c3_c_y;
      }

      for (c3_c_kk = 0; c3_c_kk < 396; c3_c_kk++) {
        c3_b_kk = 228.0 + (real_T)c3_c_kk;
        c3_y = (c3_mt[(int32_T)c3_b_kk - 1] & 2147483648U) | (c3_mt[(int32_T)
          (c3_b_kk + 1.0) - 1] & 2147483647U);
        c3_d_y = c3_y;
        c3_e_y = c3_d_y;
        if ((real_T)(c3_e_y & 1U) == 0.0) {
          c3_e_y >>= 1U;
        } else {
          c3_e_y = c3_e_y >> 1U ^ 2567483615U;
        }

        c3_mt[(int32_T)c3_b_kk - 1] = c3_mt[(int32_T)((c3_b_kk + 1.0) - 228.0) -
          1] ^ c3_e_y;
      }

      c3_y = (c3_mt[623] & 2147483648U) | (c3_mt[0] & 2147483647U);
      c3_f_y = c3_y;
      c3_g_y = c3_f_y;
      if ((real_T)(c3_g_y & 1U) == 0.0) {
        c3_g_y >>= 1U;
      } else {
        c3_g_y = c3_g_y >> 1U ^ 2567483615U;
      }

      c3_mt[623] = c3_mt[396] ^ c3_g_y;
      c3_mti = 1U;
    }

    c3_y = c3_mt[(int32_T)c3_mti - 1];
    c3_mt[624] = c3_mti;
    c3_y ^= c3_y >> 11U;
    c3_y ^= c3_y << 7U & 2636928640U;
    c3_y ^= c3_y << 15U & 4022730752U;
    c3_y ^= c3_y >> 18U;
    c3_u[(int32_T)c3_b_j - 1] = c3_y;
  }
}

static real_T c3_c_genrandu(SFc3_untitledInstanceStruct *chartInstance, uint32_T
  c3_mt[625])
{
  real_T c3_r;
  uint32_T c3_u[2];
  boolean_T c3_b1;
  boolean_T c3_isvalid;
  int32_T c3_k;
  int32_T c3_a;
  boolean_T guard1 = false;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    c3_b_genrand_uint32_vector(chartInstance, c3_mt, c3_u);
    c3_u[0] >>= 5U;
    c3_u[1] >>= 6U;
    c3_r = 1.1102230246251565E-16 * ((real_T)c3_u[0] * 6.7108864E+7 + (real_T)
      c3_u[1]);
    if (c3_r == 0.0) {
      guard1 = false;
      if ((real_T)c3_mt[624] >= 1.0) {
        if ((real_T)c3_mt[624] < 625.0) {
          c3_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c3_b1 = false;
      }

      c3_isvalid = c3_b1;
      if (c3_isvalid) {
        c3_isvalid = false;
        c3_k = 0;
        exitg2 = false;
        while ((exitg2 == false) && (c3_k + 1 < 625)) {
          if ((real_T)c3_mt[c3_k] == 0.0) {
            c3_a = c3_k + 1;
            c3_k = c3_a;
          } else {
            c3_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c3_isvalid) {
        c3_error(chartInstance);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c3_r;
}

static void init_dsm_address_info(SFc3_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_untitledInstanceStruct *chartInstance)
{
  chartInstance->c3_event_trig = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1037433714U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(483521426U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2707230470U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1554836379U);
}

mxArray* sf_c3_untitled_get_post_codegen_info(void);
mxArray *sf_c3_untitled_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("iCCiYhDpwfh9nWvzL07MPD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_untitled_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_untitled_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_untitled_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_untitled_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_untitled_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[523 529],M[1],T\"/opt/matlab/v34/toolbox/eml/lib/matlab/randfun/private/eml_rand.m\"}}},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[649 655],M[1],T\"/opt/matlab/v34/toolbox/eml/lib/matlab/randfun/private/eml_randn.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/opt/matlab/v34/toolbox/eml/lib/matlab/randfun/private/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"/opt/matlab/v34/toolbox/eml/lib/matlab/randfun/private/eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/opt/matlab/v34/toolbox/eml/lib/matlab/randfun/private/eml_rand_shr3cong_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[656 661],M[1],T\"/opt/matlab/v34/toolbox/eml/lib/matlab/randfun/private/eml_randn.m\"}}},{M[6],M[7],T\"event_trig\",},{M[7],M[7],T\"event_trigEventCounter\",},{M[8],M[0],T\"is_active_c3_untitled\",},{M[9],M[0],T\"is_c3_untitled\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[1 3],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_untitledInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_untitledInstanceStruct *chartInstance = (SFc3_untitledInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitledMachineNumber_,
           3,
           2,
           3,
           0,
           0,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_untitledMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_untitledMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _untitledMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_EVENT_SCOPE(0,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,48,0,47);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,16,0,16);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _untitledMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_untitledInstanceStruct *chartInstance = (SFc3_untitledInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        (void)chartInstance;
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sqSpBEcb0fXhsTWjrlzqeKG";
}

static void sf_opaque_initialize_c3_untitled(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_untitledInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
  initialize_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_untitled(void *chartInstanceVar)
{
  enable_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_untitled(void *chartInstanceVar)
{
  disable_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_untitled(void *chartInstanceVar)
{
  sf_gateway_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_untitled(SimStruct* S)
{
  return get_sim_state_c3_untitled((SFc3_untitledInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_untitled(SimStruct* S, const mxArray *st)
{
  set_sim_state_c3_untitled((SFc3_untitledInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_untitled(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled_optimization_info();
    }

    finalize_c3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_untitled((SFc3_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_untitled(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_untitled((SFc3_untitledInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_untitled(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3410406461U));
  ssSetChecksum1(S,(507992552U));
  ssSetChecksum2(S,(1900543739U));
  ssSetChecksum3(S,(1902158028U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_untitled(SimStruct *S)
{
  SFc3_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc3_untitledInstanceStruct *)utMalloc(sizeof
    (SFc3_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_untitledInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_untitled;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_untitled;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_untitled;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_untitled(chartInstance);
}

void c3_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
