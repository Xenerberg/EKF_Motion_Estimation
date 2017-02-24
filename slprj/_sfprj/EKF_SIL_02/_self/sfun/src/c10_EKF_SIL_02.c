/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EKF_SIL_02_sfun.h"
#include "c10_EKF_SIL_02.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EKF_SIL_02_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c10_debug_family_names[14] = { "q_star", "ita_star",
  "Ita_Tensor", "Q_Tensor", "T", "S_cam", "S_robot", "nargin", "nargout",
  "q_nominal", "ita_nominal", "cov_r", "cov_nu", "S" };

static const char * c10_b_debug_family_names[4] = { "nargin", "nargout", "v",
  "SkewSymmetricTensor" };

static const char * c10_c_debug_family_names[8] = { "q_v", "q_0", "cross_q_v",
  "nargin", "nargout", "q", "flag", "CrossTensor" };

/* Function Declarations */
static void initialize_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);
static void initialize_params_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);
static void enable_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static void disable_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_EKF_SIL_02
  (SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_EKF_SIL_02
  (SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static void set_sim_state_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_st);
static void finalize_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);
static void sf_gateway_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);
static void mdl_start_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);
static void c10_chartstep_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);
static void initSimStructsc10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);
static void c10_fn_CrossTensor(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  real_T c10_q[4], real_T c10_flag, real_T c10_CrossTensor[16]);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_b_S, const char_T *c10_identifier, real_T c10_y[144]);
static void c10_b_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[144]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_c_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_d_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[36]);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_e_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[12]);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_f_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[16]);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_g_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[4]);
static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_h_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[9]);
static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_i_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[3]);
static void c10_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static void c10_eml_scalar_eg(SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static void c10_threshold(SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static void c10_b_eml_scalar_eg(SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_j_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_k_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_EKF_SIL_02, const char_T
  *c10_identifier);
static uint8_T c10_l_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_EKF_SIL_02InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc10_EKF_SIL_02(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_EKF_SIL_02 = 0U;
}

static void initialize_params_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_EKF_SIL_02
  (SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_EKF_SIL_02
  (SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  const mxArray *c10_b_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_u;
  const mxArray *c10_c_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(2, 1), false);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", *chartInstance->c10_S, 0, 0U, 1U,
    0U, 2, 12, 12), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_hoistedGlobal = chartInstance->c10_is_active_c10_EKF_SIL_02;
  c10_u = c10_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv0[144];
  int32_T c10_i0;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("S", c10_u, 0)),
                       "S", c10_dv0);
  for (c10_i0 = 0; c10_i0 < 144; c10_i0++) {
    (*chartInstance->c10_S)[c10_i0] = c10_dv0[c10_i0];
  }

  chartInstance->c10_is_active_c10_EKF_SIL_02 = c10_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c10_EKF_SIL_02", c10_u,
       1)), "is_active_c10_EKF_SIL_02");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_EKF_SIL_02(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  int32_T c10_i1;
  int32_T c10_i2;
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  for (c10_i1 = 0; c10_i1 < 16; c10_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_cov_nu)[c10_i1], 3U, 1U, 0U,
                          chartInstance->c10_sfEvent, false);
  }

  for (c10_i2 = 0; c10_i2 < 9; c10_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_cov_r)[c10_i2], 2U, 1U, 0U,
                          chartInstance->c10_sfEvent, false);
  }

  for (c10_i3 = 0; c10_i3 < 4; c10_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_ita_nominal)[c10_i3], 1U, 1U, 0U,
                          chartInstance->c10_sfEvent, false);
  }

  for (c10_i4 = 0; c10_i4 < 4; c10_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_q_nominal)[c10_i4], 0U, 1U, 0U,
                          chartInstance->c10_sfEvent, false);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;
  c10_chartstep_c10_EKF_SIL_02(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EKF_SIL_02MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c10_i5 = 0; c10_i5 < 144; c10_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_S)[c10_i5], 4U, 1U, 0U,
                          chartInstance->c10_sfEvent, false);
  }
}

static void mdl_start_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c10_chartstep_c10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  int32_T c10_i6;
  real_T c10_b_q_nominal[4];
  int32_T c10_i7;
  real_T c10_b_ita_nominal[4];
  int32_T c10_i8;
  real_T c10_b_cov_r[9];
  int32_T c10_i9;
  real_T c10_b_cov_nu[16];
  uint32_T c10_debug_family_var_map[14];
  real_T c10_q_star[4];
  real_T c10_ita_star[4];
  real_T c10_Ita_Tensor[16];
  real_T c10_Q_Tensor[16];
  real_T c10_T[12];
  real_T c10_S_cam[36];
  real_T c10_S_robot[36];
  real_T c10_nargin = 4.0;
  real_T c10_nargout = 1.0;
  real_T c10_b_S[144];
  int32_T c10_i10;
  int32_T c10_i11;
  int32_T c10_i12;
  real_T c10_b_ita_star[4];
  real_T c10_dv1[16];
  int32_T c10_i13;
  int32_T c10_i14;
  real_T c10_b_q_star[4];
  real_T c10_dv2[16];
  int32_T c10_i15;
  int32_T c10_i16;
  real_T c10_b[16];
  int32_T c10_i17;
  int32_T c10_i18;
  int32_T c10_i19;
  int32_T c10_i20;
  real_T c10_y[12];
  int32_T c10_i21;
  int32_T c10_i22;
  static real_T c10_a[12] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0 };

  int32_T c10_i23;
  int32_T c10_i24;
  int32_T c10_i25;
  int32_T c10_i26;
  real_T c10_C[12];
  int32_T c10_i27;
  int32_T c10_i28;
  int32_T c10_i29;
  int32_T c10_i30;
  int32_T c10_i31;
  int32_T c10_i32;
  int32_T c10_i33;
  int32_T c10_i34;
  int32_T c10_i35;
  int32_T c10_i36;
  int32_T c10_i37;
  int32_T c10_i38;
  int32_T c10_i39;
  int32_T c10_i40;
  int32_T c10_i41;
  int32_T c10_i42;
  int32_T c10_i43;
  int32_T c10_i44;
  int32_T c10_i45;
  int32_T c10_i46;
  int32_T c10_i47;
  real_T c10_b_b[12];
  int32_T c10_i48;
  int32_T c10_i49;
  int32_T c10_i50;
  int32_T c10_i51;
  real_T c10_b_y[9];
  int32_T c10_i52;
  int32_T c10_i53;
  int32_T c10_i54;
  int32_T c10_i55;
  int32_T c10_i56;
  int32_T c10_i57;
  int32_T c10_i58;
  int32_T c10_i59;
  int32_T c10_i60;
  int32_T c10_i61;
  int32_T c10_i62;
  int32_T c10_i63;
  int32_T c10_i64;
  int32_T c10_i65;
  int32_T c10_i66;
  int32_T c10_i67;
  int32_T c10_i68;
  static real_T c10_dv3[36] = { 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001 };

  int32_T c10_i69;
  int32_T c10_i70;
  int32_T c10_i71;
  int32_T c10_i72;
  int32_T c10_i73;
  int32_T c10_i74;
  int32_T c10_i75;
  int32_T c10_i76;
  int32_T c10_i77;
  int32_T c10_i78;
  int32_T c10_i79;
  int32_T c10_i80;
  int32_T c10_i81;
  int32_T c10_i82;
  int32_T c10_i83;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  for (c10_i6 = 0; c10_i6 < 4; c10_i6++) {
    c10_b_q_nominal[c10_i6] = (*chartInstance->c10_q_nominal)[c10_i6];
  }

  for (c10_i7 = 0; c10_i7 < 4; c10_i7++) {
    c10_b_ita_nominal[c10_i7] = (*chartInstance->c10_ita_nominal)[c10_i7];
  }

  for (c10_i8 = 0; c10_i8 < 9; c10_i8++) {
    c10_b_cov_r[c10_i8] = (*chartInstance->c10_cov_r)[c10_i8];
  }

  for (c10_i9 = 0; c10_i9 < 16; c10_i9++) {
    c10_b_cov_nu[c10_i9] = (*chartInstance->c10_cov_nu)[c10_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_q_star, 0U, c10_d_sf_marshallOut,
    c10_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_ita_star, 1U, c10_d_sf_marshallOut,
    c10_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_Ita_Tensor, 2U, c10_b_sf_marshallOut,
    c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_Q_Tensor, 3U, c10_b_sf_marshallOut,
    c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_T, 4U, c10_h_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_S_cam, 5U, c10_g_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_S_robot, 6U, c10_g_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 7U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 8U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_b_q_nominal, 9U, c10_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_b_ita_nominal, 10U, c10_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_b_cov_r, 11U, c10_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_b_cov_nu, 12U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b_S, 13U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
  for (c10_i10 = 0; c10_i10 < 3; c10_i10++) {
    c10_q_star[c10_i10] = -c10_b_q_nominal[c10_i10];
  }

  c10_q_star[3] = c10_b_q_nominal[3];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 13);
  for (c10_i11 = 0; c10_i11 < 3; c10_i11++) {
    c10_ita_star[c10_i11] = -c10_b_ita_nominal[c10_i11];
  }

  c10_ita_star[3] = c10_b_ita_nominal[3];
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 14);
  for (c10_i12 = 0; c10_i12 < 4; c10_i12++) {
    c10_b_ita_star[c10_i12] = c10_ita_star[c10_i12];
  }

  c10_fn_CrossTensor(chartInstance, c10_b_ita_star, 0.0, c10_dv1);
  for (c10_i13 = 0; c10_i13 < 16; c10_i13++) {
    c10_Ita_Tensor[c10_i13] = c10_dv1[c10_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 15);
  for (c10_i14 = 0; c10_i14 < 4; c10_i14++) {
    c10_b_q_star[c10_i14] = c10_q_star[c10_i14];
  }

  c10_fn_CrossTensor(chartInstance, c10_b_q_star, 1.0, c10_dv2);
  for (c10_i15 = 0; c10_i15 < 16; c10_i15++) {
    c10_Q_Tensor[c10_i15] = c10_dv2[c10_i15];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 16);
  for (c10_i16 = 0; c10_i16 < 16; c10_i16++) {
    c10_b[c10_i16] = c10_Ita_Tensor[c10_i16];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  c10_threshold(chartInstance);
  for (c10_i17 = 0; c10_i17 < 3; c10_i17++) {
    c10_i18 = 0;
    c10_i19 = 0;
    for (c10_i20 = 0; c10_i20 < 4; c10_i20++) {
      c10_y[c10_i18 + c10_i17] = 0.0;
      c10_i21 = 0;
      for (c10_i22 = 0; c10_i22 < 4; c10_i22++) {
        c10_y[c10_i18 + c10_i17] += c10_a[c10_i21 + c10_i17] * c10_b[c10_i22 +
          c10_i19];
        c10_i21 += 3;
      }

      c10_i18 += 3;
      c10_i19 += 4;
    }
  }

  for (c10_i23 = 0; c10_i23 < 16; c10_i23++) {
    c10_b[c10_i23] = c10_Q_Tensor[c10_i23];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i24 = 0; c10_i24 < 12; c10_i24++) {
    c10_T[c10_i24] = 0.0;
  }

  for (c10_i25 = 0; c10_i25 < 12; c10_i25++) {
    c10_T[c10_i25] = 0.0;
  }

  for (c10_i26 = 0; c10_i26 < 12; c10_i26++) {
    c10_C[c10_i26] = c10_T[c10_i26];
  }

  for (c10_i27 = 0; c10_i27 < 12; c10_i27++) {
    c10_T[c10_i27] = c10_C[c10_i27];
  }

  c10_threshold(chartInstance);
  for (c10_i28 = 0; c10_i28 < 12; c10_i28++) {
    c10_C[c10_i28] = c10_T[c10_i28];
  }

  for (c10_i29 = 0; c10_i29 < 12; c10_i29++) {
    c10_T[c10_i29] = c10_C[c10_i29];
  }

  for (c10_i30 = 0; c10_i30 < 3; c10_i30++) {
    c10_i31 = 0;
    c10_i32 = 0;
    for (c10_i33 = 0; c10_i33 < 4; c10_i33++) {
      c10_T[c10_i31 + c10_i30] = 0.0;
      c10_i34 = 0;
      for (c10_i35 = 0; c10_i35 < 4; c10_i35++) {
        c10_T[c10_i31 + c10_i30] += c10_y[c10_i34 + c10_i30] * c10_b[c10_i35 +
          c10_i32];
        c10_i34 += 3;
      }

      c10_i31 += 3;
      c10_i32 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 17);
  for (c10_i36 = 0; c10_i36 < 12; c10_i36++) {
    c10_C[c10_i36] = c10_T[c10_i36];
  }

  for (c10_i37 = 0; c10_i37 < 16; c10_i37++) {
    c10_b[c10_i37] = c10_b_cov_nu[c10_i37];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  c10_threshold(chartInstance);
  for (c10_i38 = 0; c10_i38 < 3; c10_i38++) {
    c10_i39 = 0;
    c10_i40 = 0;
    for (c10_i41 = 0; c10_i41 < 4; c10_i41++) {
      c10_y[c10_i39 + c10_i38] = 0.0;
      c10_i42 = 0;
      for (c10_i43 = 0; c10_i43 < 4; c10_i43++) {
        c10_y[c10_i39 + c10_i38] += c10_C[c10_i42 + c10_i38] * c10_b[c10_i43 +
          c10_i40];
        c10_i42 += 3;
      }

      c10_i39 += 3;
      c10_i40 += 4;
    }
  }

  c10_i44 = 0;
  for (c10_i45 = 0; c10_i45 < 3; c10_i45++) {
    c10_i46 = 0;
    for (c10_i47 = 0; c10_i47 < 4; c10_i47++) {
      c10_b_b[c10_i47 + c10_i44] = c10_T[c10_i46 + c10_i45];
      c10_i46 += 3;
    }

    c10_i44 += 4;
  }

  c10_b_eml_scalar_eg(chartInstance);
  c10_b_eml_scalar_eg(chartInstance);
  c10_threshold(chartInstance);
  for (c10_i48 = 0; c10_i48 < 3; c10_i48++) {
    c10_i49 = 0;
    c10_i50 = 0;
    for (c10_i51 = 0; c10_i51 < 3; c10_i51++) {
      c10_b_y[c10_i49 + c10_i48] = 0.0;
      c10_i52 = 0;
      for (c10_i53 = 0; c10_i53 < 4; c10_i53++) {
        c10_b_y[c10_i49 + c10_i48] += c10_y[c10_i52 + c10_i48] * c10_b_b[c10_i53
          + c10_i50];
        c10_i52 += 3;
      }

      c10_i49 += 3;
      c10_i50 += 4;
    }
  }

  c10_i54 = 0;
  c10_i55 = 0;
  for (c10_i56 = 0; c10_i56 < 3; c10_i56++) {
    for (c10_i57 = 0; c10_i57 < 3; c10_i57++) {
      c10_S_cam[c10_i57 + c10_i54] = c10_b_cov_r[c10_i57 + c10_i55];
    }

    c10_i54 += 6;
    c10_i55 += 3;
  }

  c10_i58 = 0;
  for (c10_i59 = 0; c10_i59 < 3; c10_i59++) {
    for (c10_i60 = 0; c10_i60 < 3; c10_i60++) {
      c10_S_cam[(c10_i60 + c10_i58) + 18] = 0.0;
    }

    c10_i58 += 6;
  }

  c10_i61 = 0;
  for (c10_i62 = 0; c10_i62 < 3; c10_i62++) {
    for (c10_i63 = 0; c10_i63 < 3; c10_i63++) {
      c10_S_cam[(c10_i63 + c10_i61) + 3] = 0.0;
    }

    c10_i61 += 6;
  }

  c10_i64 = 0;
  c10_i65 = 0;
  for (c10_i66 = 0; c10_i66 < 3; c10_i66++) {
    for (c10_i67 = 0; c10_i67 < 3; c10_i67++) {
      c10_S_cam[(c10_i67 + c10_i64) + 21] = c10_b_y[c10_i67 + c10_i65];
    }

    c10_i64 += 6;
    c10_i65 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 18);
  for (c10_i68 = 0; c10_i68 < 36; c10_i68++) {
    c10_S_robot[c10_i68] = c10_dv3[c10_i68];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 19);
  c10_i69 = 0;
  c10_i70 = 0;
  for (c10_i71 = 0; c10_i71 < 6; c10_i71++) {
    for (c10_i72 = 0; c10_i72 < 6; c10_i72++) {
      c10_b_S[c10_i72 + c10_i69] = c10_S_cam[c10_i72 + c10_i70];
    }

    c10_i69 += 12;
    c10_i70 += 6;
  }

  c10_i73 = 0;
  for (c10_i74 = 0; c10_i74 < 6; c10_i74++) {
    for (c10_i75 = 0; c10_i75 < 6; c10_i75++) {
      c10_b_S[(c10_i75 + c10_i73) + 72] = 0.0;
    }

    c10_i73 += 12;
  }

  c10_i76 = 0;
  for (c10_i77 = 0; c10_i77 < 6; c10_i77++) {
    for (c10_i78 = 0; c10_i78 < 6; c10_i78++) {
      c10_b_S[(c10_i78 + c10_i76) + 6] = 0.0;
    }

    c10_i76 += 12;
  }

  c10_i79 = 0;
  c10_i80 = 0;
  for (c10_i81 = 0; c10_i81 < 6; c10_i81++) {
    for (c10_i82 = 0; c10_i82 < 6; c10_i82++) {
      c10_b_S[(c10_i82 + c10_i79) + 78] = c10_S_robot[c10_i82 + c10_i80];
    }

    c10_i79 += 12;
    c10_i80 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i83 = 0; c10_i83 < 144; c10_i83++) {
    (*chartInstance->c10_S)[c10_i83] = c10_b_S[c10_i83];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
}

static void initSimStructsc10_EKF_SIL_02(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c10_fn_CrossTensor(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  real_T c10_q[4], real_T c10_flag, real_T c10_CrossTensor[16])
{
  uint32_T c10_debug_family_var_map[8];
  real_T c10_q_v[3];
  real_T c10_q_0;
  real_T c10_cross_q_v[9];
  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i84;
  int32_T c10_i85;
  int32_T c10_i86;
  real_T c10_v[3];
  uint32_T c10_b_debug_family_var_map[4];
  real_T c10_b_nargin = 1.0;
  real_T c10_b_nargout = 1.0;
  int32_T c10_i87;
  real_T c10_a;
  int32_T c10_i88;
  static real_T c10_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c10_y[9];
  int32_T c10_i89;
  int32_T c10_i90;
  int32_T c10_i91;
  int32_T c10_i92;
  int32_T c10_i93;
  int32_T c10_i94;
  int32_T c10_i95;
  real_T c10_b_a;
  int32_T c10_i96;
  int32_T c10_i97;
  int32_T c10_i98;
  int32_T c10_i99;
  int32_T c10_i100;
  int32_T c10_i101;
  int32_T c10_i102;
  int32_T c10_i103;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c10_c_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_q_v, 0U, c10_i_sf_marshallOut,
    c10_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_q_0, 1U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_cross_q_v, 2U, c10_c_sf_marshallOut,
    c10_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 3U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 4U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_q, 5U, c10_d_sf_marshallOut,
    c10_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_flag, 6U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_CrossTensor, 7U, c10_b_sf_marshallOut,
    c10_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  for (c10_i84 = 0; c10_i84 < 16; c10_i84++) {
    c10_CrossTensor[c10_i84] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 5);
  for (c10_i85 = 0; c10_i85 < 3; c10_i85++) {
    c10_q_v[c10_i85] = c10_q[c10_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  c10_q_0 = c10_q[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  for (c10_i86 = 0; c10_i86 < 3; c10_i86++) {
    c10_v[c10_i86] = c10_q_v[c10_i86];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c10_b_debug_family_names,
    c10_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U, c10_f_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_v, 2U, c10_i_sf_marshallOut,
    c10_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_cross_q_v, 3U, c10_c_sf_marshallOut,
    c10_g_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 2);
  for (c10_i87 = 0; c10_i87 < 9; c10_i87++) {
    c10_cross_q_v[c10_i87] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 3);
  c10_cross_q_v[0] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 4);
  c10_cross_q_v[4] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 5);
  c10_cross_q_v[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 6);
  c10_cross_q_v[3] = -c10_v[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 7);
  c10_cross_q_v[6] = c10_v[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 8);
  c10_cross_q_v[7] = -c10_v[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 9);
  c10_cross_q_v[1] = c10_v[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 10);
  c10_cross_q_v[2] = -c10_v[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, 11);
  c10_cross_q_v[5] = c10_v[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  switch ((int32_T)_SFD_INTEGER_CHECK("flag", c10_flag)) {
   case 0:
    CV_SCRIPT_SWITCH(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
    c10_a = c10_q_0;
    for (c10_i88 = 0; c10_i88 < 9; c10_i88++) {
      c10_y[c10_i88] = c10_a * c10_b[c10_i88];
    }

    c10_i89 = 0;
    c10_i90 = 0;
    for (c10_i91 = 0; c10_i91 < 3; c10_i91++) {
      for (c10_i92 = 0; c10_i92 < 3; c10_i92++) {
        c10_CrossTensor[c10_i92 + c10_i89] = -c10_cross_q_v[c10_i92 + c10_i90] +
          c10_y[c10_i92 + c10_i90];
      }

      c10_i89 += 4;
      c10_i90 += 3;
    }

    for (c10_i93 = 0; c10_i93 < 3; c10_i93++) {
      c10_CrossTensor[c10_i93 + 12] = c10_q_v[c10_i93];
    }

    c10_i94 = 0;
    for (c10_i95 = 0; c10_i95 < 3; c10_i95++) {
      c10_CrossTensor[c10_i94 + 3] = -c10_q_v[c10_i95];
      c10_i94 += 4;
    }

    c10_CrossTensor[15] = c10_q_0;
    break;

   case 1:
    CV_SCRIPT_SWITCH(0, 0, 2);
    _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 12);
    c10_b_a = c10_q_0;
    for (c10_i96 = 0; c10_i96 < 9; c10_i96++) {
      c10_y[c10_i96] = c10_b_a * c10_b[c10_i96];
    }

    c10_i97 = 0;
    c10_i98 = 0;
    for (c10_i99 = 0; c10_i99 < 3; c10_i99++) {
      for (c10_i100 = 0; c10_i100 < 3; c10_i100++) {
        c10_CrossTensor[c10_i100 + c10_i97] = c10_cross_q_v[c10_i100 + c10_i98]
          + c10_y[c10_i100 + c10_i98];
      }

      c10_i97 += 4;
      c10_i98 += 3;
    }

    for (c10_i101 = 0; c10_i101 < 3; c10_i101++) {
      c10_CrossTensor[c10_i101 + 12] = c10_q_v[c10_i101];
    }

    c10_i102 = 0;
    for (c10_i103 = 0; c10_i103 < 3; c10_i103++) {
      c10_CrossTensor[c10_i102 + 3] = -c10_q_v[c10_i103];
      c10_i102 += 4;
    }

    c10_CrossTensor[15] = c10_q_0;
    break;

   default:
    CV_SCRIPT_SWITCH(0, 0, 0);
    break;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c10_chartNumber, c10_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\users\\ana\\documents\\matlab\\Model_02_Simulink-Aghili--2007-\\fn_CrossTensor.m"));
  _SFD_SCRIPT_TRANSLATION(c10_chartNumber, c10_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\users\\ana\\documents\\matlab\\Model_02_Simulink-Aghili--2007-\\fn_VectorToSkewSymmetricTensor.m"));
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i104;
  int32_T c10_i105;
  int32_T c10_i106;
  real_T c10_u[144];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i104 = 0;
  for (c10_i105 = 0; c10_i105 < 12; c10_i105++) {
    for (c10_i106 = 0; c10_i106 < 12; c10_i106++) {
      c10_u[c10_i106 + c10_i104] = (*(real_T (*)[144])c10_inData)[c10_i106 +
        c10_i104];
    }

    c10_i104 += 12;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 12, 12),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_b_S, const char_T *c10_identifier, real_T c10_y[144])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_S), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_b_S);
}

static void c10_b_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[144])
{
  real_T c10_dv4[144];
  int32_T c10_i107;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv4, 1, 0, 0U, 1, 0U, 2, 12,
                12);
  for (c10_i107 = 0; c10_i107 < 144; c10_i107++) {
    c10_y[c10_i107] = c10_dv4[c10_i107];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_S;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[144];
  int32_T c10_i108;
  int32_T c10_i109;
  int32_T c10_i110;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_b_S = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_S), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_b_S);
  c10_i108 = 0;
  for (c10_i109 = 0; c10_i109 < 12; c10_i109++) {
    for (c10_i110 = 0; c10_i110 < 12; c10_i110++) {
      (*(real_T (*)[144])c10_outData)[c10_i110 + c10_i108] = c10_y[c10_i110 +
        c10_i108];
    }

    c10_i108 += 12;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i111;
  int32_T c10_i112;
  int32_T c10_i113;
  real_T c10_u[16];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i111 = 0;
  for (c10_i112 = 0; c10_i112 < 4; c10_i112++) {
    for (c10_i113 = 0; c10_i113 < 4; c10_i113++) {
      c10_u[c10_i113 + c10_i111] = (*(real_T (*)[16])c10_inData)[c10_i113 +
        c10_i111];
    }

    c10_i111 += 4;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i114;
  int32_T c10_i115;
  int32_T c10_i116;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i114 = 0;
  for (c10_i115 = 0; c10_i115 < 3; c10_i115++) {
    for (c10_i116 = 0; c10_i116 < 3; c10_i116++) {
      c10_u[c10_i116 + c10_i114] = (*(real_T (*)[9])c10_inData)[c10_i116 +
        c10_i114];
    }

    c10_i114 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i117;
  real_T c10_u[4];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i117 = 0; c10_i117 < 4; c10_i117++) {
    c10_u[c10_i117] = (*(real_T (*)[4])c10_inData)[c10_i117];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i118;
  real_T c10_u[4];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i118 = 0; c10_i118 < 4; c10_i118++) {
    c10_u[c10_i118] = (*(real_T (*)[4])c10_inData)[c10_i118];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 4, 1), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_c_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i119;
  int32_T c10_i120;
  int32_T c10_i121;
  real_T c10_u[36];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i119 = 0;
  for (c10_i120 = 0; c10_i120 < 6; c10_i120++) {
    for (c10_i121 = 0; c10_i121 < 6; c10_i121++) {
      c10_u[c10_i121 + c10_i119] = (*(real_T (*)[36])c10_inData)[c10_i121 +
        c10_i119];
    }

    c10_i119 += 6;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_d_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[36])
{
  real_T c10_dv5[36];
  int32_T c10_i122;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv5, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c10_i122 = 0; c10_i122 < 36; c10_i122++) {
    c10_y[c10_i122] = c10_dv5[c10_i122];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_S_robot;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[36];
  int32_T c10_i123;
  int32_T c10_i124;
  int32_T c10_i125;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_S_robot = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_S_robot), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_S_robot);
  c10_i123 = 0;
  for (c10_i124 = 0; c10_i124 < 6; c10_i124++) {
    for (c10_i125 = 0; c10_i125 < 6; c10_i125++) {
      (*(real_T (*)[36])c10_outData)[c10_i125 + c10_i123] = c10_y[c10_i125 +
        c10_i123];
    }

    c10_i123 += 6;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i126;
  int32_T c10_i127;
  int32_T c10_i128;
  real_T c10_u[12];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i126 = 0;
  for (c10_i127 = 0; c10_i127 < 4; c10_i127++) {
    for (c10_i128 = 0; c10_i128 < 3; c10_i128++) {
      c10_u[c10_i128 + c10_i126] = (*(real_T (*)[12])c10_inData)[c10_i128 +
        c10_i126];
    }

    c10_i126 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 4), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_e_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[12])
{
  real_T c10_dv6[12];
  int32_T c10_i129;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv6, 1, 0, 0U, 1, 0U, 2, 3,
                4);
  for (c10_i129 = 0; c10_i129 < 12; c10_i129++) {
    c10_y[c10_i129] = c10_dv6[c10_i129];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_T;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[12];
  int32_T c10_i130;
  int32_T c10_i131;
  int32_T c10_i132;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_T = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_T), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_T);
  c10_i130 = 0;
  for (c10_i131 = 0; c10_i131 < 4; c10_i131++) {
    for (c10_i132 = 0; c10_i132 < 3; c10_i132++) {
      (*(real_T (*)[12])c10_outData)[c10_i132 + c10_i130] = c10_y[c10_i132 +
        c10_i130];
    }

    c10_i130 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static void c10_f_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[16])
{
  real_T c10_dv7[16];
  int32_T c10_i133;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv7, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c10_i133 = 0; c10_i133 < 16; c10_i133++) {
    c10_y[c10_i133] = c10_dv7[c10_i133];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_Q_Tensor;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[16];
  int32_T c10_i134;
  int32_T c10_i135;
  int32_T c10_i136;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_Q_Tensor = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_Q_Tensor), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_Q_Tensor);
  c10_i134 = 0;
  for (c10_i135 = 0; c10_i135 < 4; c10_i135++) {
    for (c10_i136 = 0; c10_i136 < 4; c10_i136++) {
      (*(real_T (*)[16])c10_outData)[c10_i136 + c10_i134] = c10_y[c10_i136 +
        c10_i134];
    }

    c10_i134 += 4;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static void c10_g_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[4])
{
  real_T c10_dv8[4];
  int32_T c10_i137;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv8, 1, 0, 0U, 1, 0U, 1, 4);
  for (c10_i137 = 0; c10_i137 < 4; c10_i137++) {
    c10_y[c10_i137] = c10_dv8[c10_i137];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_ita_star;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[4];
  int32_T c10_i138;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_ita_star = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_ita_star), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_ita_star);
  for (c10_i138 = 0; c10_i138 < 4; c10_i138++) {
    (*(real_T (*)[4])c10_outData)[c10_i138] = c10_y[c10_i138];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static void c10_h_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[9])
{
  real_T c10_dv9[9];
  int32_T c10_i139;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv9, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c10_i139 = 0; c10_i139 < 9; c10_i139++) {
    c10_y[c10_i139] = c10_dv9[c10_i139];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_SkewSymmetricTensor;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[9];
  int32_T c10_i140;
  int32_T c10_i141;
  int32_T c10_i142;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_SkewSymmetricTensor = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_SkewSymmetricTensor),
    &c10_thisId, c10_y);
  sf_mex_destroy(&c10_SkewSymmetricTensor);
  c10_i140 = 0;
  for (c10_i141 = 0; c10_i141 < 3; c10_i141++) {
    for (c10_i142 = 0; c10_i142 < 3; c10_i142++) {
      (*(real_T (*)[9])c10_outData)[c10_i142 + c10_i140] = c10_y[c10_i142 +
        c10_i140];
    }

    c10_i140 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i143;
  real_T c10_u[3];
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i143 = 0; c10_i143 < 3; c10_i143++) {
    c10_u[c10_i143] = (*(real_T (*)[3])c10_inData)[c10_i143];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_i_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[3])
{
  real_T c10_dv10[3];
  int32_T c10_i144;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv10, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i144 = 0; c10_i144 < 3; c10_i144++) {
    c10_y[c10_i144] = c10_dv10[c10_i144];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_v;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[3];
  int32_T c10_i145;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_v = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_v), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_v);
  for (c10_i145 = 0; c10_i145 < 3; c10_i145++) {
    (*(real_T (*)[3])c10_outData)[c10_i145] = c10_y[c10_i145];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_EKF_SIL_02_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 2, 1),
                false);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("fn_CrossTensor"), "name",
                  "name", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[E]C:/users/ana/documents/matlab/Model_02_Simulink-Aghili--2007-/fn_CrossTensor.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1465418202U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[E]C:/users/ana/documents/matlab/Model_02_Simulink-Aghili--2007-/fn_CrossTensor.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "fn_VectorToSkewSymmetricTensor"), "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[E]C:/users/ana/documents/matlab/Model_02_Simulink-Aghili--2007-/fn_VectorToSkewSymmetricTensor.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1465418202U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
}

static const mxArray *c10_emlrt_marshallOut(const char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), false);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), false);
  return c10_y;
}

static void c10_eml_scalar_eg(SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_threshold(SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_b_eml_scalar_eg(SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_j_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i146;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i146, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i146;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_k_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_EKF_SIL_02, const char_T
  *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_EKF_SIL_02), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_EKF_SIL_02);
  return c10_y;
}

static uint8_T c10_l_emlrt_marshallIn(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc10_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  chartInstance->c10_q_nominal = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c10_S = (real_T (*)[144])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c10_ita_nominal = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c10_cov_r = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c10_cov_nu = (real_T (*)[16])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c10_EKF_SIL_02_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3553981236U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3690731175U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2432783227U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2579148101U);
}

mxArray* sf_c10_EKF_SIL_02_get_post_codegen_info(void);
mxArray *sf_c10_EKF_SIL_02_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4UXLQ1ovOSRYmot7CkoU7F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(12);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c10_EKF_SIL_02_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_EKF_SIL_02_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_EKF_SIL_02_jit_fallback_info(void)
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

mxArray *sf_c10_EKF_SIL_02_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c10_EKF_SIL_02_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c10_EKF_SIL_02(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"S\",},{M[8],M[0],T\"is_active_c10_EKF_SIL_02\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_EKF_SIL_02_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_EKF_SIL_02InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_EKF_SIL_02InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EKF_SIL_02MachineNumber_,
           10,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_EKF_SIL_02MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_EKF_SIL_02MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _EKF_SIL_02MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"q_nominal");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ita_nominal");
          _SFD_SET_DATA_PROPS(2,1,1,0,"cov_r");
          _SFD_SET_DATA_PROPS(3,1,1,0,"cov_nu");
          _SFD_SET_DATA_PROPS(4,2,0,1,"S");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",383,-1,829);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,1,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"fn_CrossTensor",59,-1,457);

        {
          static int caseStart[] = { 423, 254, 339 };

          static int caseExprEnd[] = { 432, 260, 345 };

          _SFD_CV_INIT_SCRIPT_SWITCH(0,0,232,245,453,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"fn_VectorToSkewSymmetricTensor",0,-1,433);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12;
          dimVector[1]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _EKF_SIL_02MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_EKF_SIL_02InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_EKF_SIL_02InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c10_q_nominal);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c10_S);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c10_ita_nominal);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c10_cov_r);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c10_cov_nu);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s8Riu2MwK0tBk866tRmgl8G";
}

static void sf_opaque_initialize_c10_EKF_SIL_02(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_EKF_SIL_02InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*)
    chartInstanceVar);
  initialize_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_EKF_SIL_02(void *chartInstanceVar)
{
  enable_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_EKF_SIL_02(void *chartInstanceVar)
{
  disable_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_EKF_SIL_02(void *chartInstanceVar)
{
  sf_gateway_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c10_EKF_SIL_02(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_EKF_SIL_02(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c10_EKF_SIL_02(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_EKF_SIL_02InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EKF_SIL_02_optimization_info();
    }

    finalize_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_EKF_SIL_02(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c10_EKF_SIL_02((SFc10_EKF_SIL_02InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_EKF_SIL_02(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EKF_SIL_02_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1295852926U));
  ssSetChecksum1(S,(2891353769U));
  ssSetChecksum2(S,(2243459992U));
  ssSetChecksum3(S,(187757315U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_EKF_SIL_02(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_EKF_SIL_02(SimStruct *S)
{
  SFc10_EKF_SIL_02InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_EKF_SIL_02InstanceStruct *)utMalloc(sizeof
    (SFc10_EKF_SIL_02InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_EKF_SIL_02InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c10_EKF_SIL_02;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c10_EKF_SIL_02;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c10_EKF_SIL_02;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_EKF_SIL_02;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_EKF_SIL_02;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c10_EKF_SIL_02;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c10_EKF_SIL_02;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_EKF_SIL_02;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_EKF_SIL_02;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_EKF_SIL_02;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_EKF_SIL_02;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->isEnhancedMooreMachine = 0;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->fCheckOverflow = sf_runtime_overflow_check_is_on(S);
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
}

void c10_EKF_SIL_02_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_EKF_SIL_02(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_EKF_SIL_02(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_EKF_SIL_02(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_EKF_SIL_02_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
