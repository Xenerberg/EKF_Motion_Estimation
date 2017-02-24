/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EKF_SIL_02_sfun.h"
#include "c6_EKF_SIL_02.h"
#include <math.h>
#include "mwmathutil.h"
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
static const char * c6_debug_family_names[14] = { "Phi_t", "Phi_r", "Phi_rho_c",
  "Phi_ieps", "Phi_robot", "nargin", "nargout", "X_a", "n", "t_Kalman", "p", "M",
  "V", "Phi" };

static const char * c6_b_debug_family_names[4] = { "nargin", "nargout", "v",
  "SkewSymmetricTensor" };

static const char * c6_c_debug_family_names[7] = { "Phi_t12", "Phi_t22",
  "nargin", "nargout", "n", "t_delta", "Phi_t" };

static const char * c6_d_debug_family_names[5] = { "nargin", "nargout", "p",
  "omega", "M" };

static const char * c6_e_debug_family_names[9] = { "omega", "M", "A", "nargin",
  "nargout", "X_a", "p", "t_Kalman", "Phi_r" };

/* Function Declarations */
static void initialize_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance);
static void initialize_params_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance);
static void enable_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void disable_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *
  chartInstance);
static void set_sim_state_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void sf_gateway_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance);
static void mdl_start_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void initSimStructsc6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance);
static void c6_fn_VectorToSkewSymmetricTensor(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, real_T c6_v[3], real_T c6_SkewSymmetricTensor[9]);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_b_Phi, const char_T *c6_identifier, real_T c6_y[324]);
static void c6_b_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[324]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[36]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_e_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[9]);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_f_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3]);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_g_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[20]);
static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static void c6_eml_scalar_eg(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_dimagree(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_eye(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_I[9]);
static void c6_eml_switch_helper(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_expm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_A[36],
                    real_T c6_F[36]);
static void c6_PadeApproximantOfDegree(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, real_T c6_A[36], real_T c6_m, real_T c6_F[36]);
static void c6_b_eml_scalar_eg(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_threshold(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_realmin(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_eps(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_eml_matlab_zgetrf(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  real_T c6_A[36], real_T c6_b_A[36], int32_T c6_ipiv[6], int32_T *c6_info);
static int32_T c6_eml_ixamax(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  int32_T c6_b_n, real_T c6_x[36], int32_T c6_ix0);
static void c6_check_forloop_overflow_error(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, boolean_T c6_overflow);
static void c6_b_eml_switch_helper(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_eml_xgeru(SFc6_EKF_SIL_02InstanceStruct *chartInstance, int32_T
  c6_m, int32_T c6_b_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0, real_T
  c6_A[36], int32_T c6_ia0, real_T c6_b_A[36]);
static void c6_eml_warning(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36], real_T c6_b_B[36]);
static void c6_below_threshold(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_c_eml_switch_helper(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_scalarEg(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_b_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36], real_T c6_b_B[36]);
static real_T c6_rdivide(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_x, real_T c6_y);
static void c6_log2(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_x,
                    real_T *c6_f, real_T *c6_e);
static real_T c6_pow2(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_a);
static void c6_b_expm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_A
                      [9], real_T c6_F[9]);
static void c6_b_PadeApproximantOfDegree(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, real_T c6_A[9], real_T c6_m, real_T c6_F[9]);
static void c6_c_eml_scalar_eg(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void c6_mldivide(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[9], real_T c6_B[9], real_T c6_Y[9]);
static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_h_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_i_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_EKF_SIL_02, const char_T
  *c6_identifier);
static uint8_T c6_j_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_eml_matlab_zgetrf(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  real_T c6_A[36], int32_T c6_ipiv[6], int32_T *c6_info);
static void c6_b_eml_xgeru(SFc6_EKF_SIL_02InstanceStruct *chartInstance, int32_T
  c6_m, int32_T c6_b_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0, real_T
  c6_A[36], int32_T c6_ia0);
static void c6_c_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36]);
static void c6_d_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36]);
static void init_dsm_address_info(SFc6_EKF_SIL_02InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc6_EKF_SIL_02(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_EKF_SIL_02 = 0U;
}

static void initialize_params_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *
  chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_u;
  const mxArray *c6_c_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", *chartInstance->c6_Phi, 0, 0U, 1U,
    0U, 2, 18, 18), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_EKF_SIL_02;
  c6_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[324];
  int32_T c6_i0;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("Phi", c6_u, 0)),
                      "Phi", c6_dv0);
  for (c6_i0 = 0; c6_i0 < 324; c6_i0++) {
    (*chartInstance->c6_Phi)[c6_i0] = c6_dv0[c6_i0];
  }

  chartInstance->c6_is_active_c6_EKF_SIL_02 = c6_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c6_EKF_SIL_02", c6_u, 1)),
     "is_active_c6_EKF_SIL_02");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_EKF_SIL_02(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  int32_T c6_i5;
  real_T c6_b_X_a[20];
  real_T c6_b_n;
  real_T c6_b_t_Kalman;
  int32_T c6_i6;
  real_T c6_b_p[3];
  int32_T c6_i7;
  real_T c6_b_M[9];
  int32_T c6_i8;
  real_T c6_b_V[6];
  uint32_T c6_debug_family_var_map[14];
  real_T c6_Phi_t[36];
  real_T c6_Phi_r[36];
  real_T c6_Phi_rho_c[9];
  real_T c6_Phi_ieps[9];
  real_T c6_Phi_robot[36];
  real_T c6_nargin = 6.0;
  real_T c6_nargout = 1.0;
  real_T c6_b_Phi[324];
  real_T c6_c_n;
  real_T c6_t_delta;
  uint32_T c6_b_debug_family_var_map[7];
  real_T c6_Phi_t12[9];
  real_T c6_Phi_t22[9];
  real_T c6_b_nargin = 2.0;
  real_T c6_b_nargout = 1.0;
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_c_a;
  real_T c6_ak;
  real_T c6_d_a;
  real_T c6_c;
  real_T c6_dv1[3];
  real_T c6_b[9];
  int32_T c6_i9;
  real_T c6_b_b;
  int32_T c6_i10;
  real_T c6_dv2[9];
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  static real_T c6_dv3[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  real_T c6_c_X_a[20];
  int32_T c6_i28;
  real_T c6_c_p[3];
  real_T c6_c_t_Kalman;
  uint32_T c6_c_debug_family_var_map[9];
  real_T c6_omega[3];
  real_T c6_c_M[9];
  real_T c6_A[36];
  real_T c6_c_nargin = 3.0;
  real_T c6_c_nargout = 1.0;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  real_T c6_d_p[3];
  int32_T c6_i32;
  real_T c6_b_omega[3];
  uint32_T c6_d_debug_family_var_map[5];
  real_T c6_d_nargin = 2.0;
  real_T c6_d_nargout = 1.0;
  int32_T c6_i33;
  real_T c6_c_omega[3];
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  int32_T c6_i41;
  static real_T c6_dv4[9] = { 0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5 };

  int32_T c6_i42;
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  int32_T c6_i47;
  int32_T c6_i48;
  int32_T c6_i49;
  real_T c6_e_a[36];
  real_T c6_c_b;
  int32_T c6_i50;
  int32_T c6_i51;
  real_T c6_f_a[36];
  real_T c6_dv5[36];
  int32_T c6_i52;
  int32_T c6_i53;
  real_T c6_c_V[3];
  int32_T c6_i54;
  real_T c6_dv6[9];
  real_T c6_dv7[9];
  int32_T c6_i55;
  real_T c6_dv8[9];
  int32_T c6_i56;
  int32_T c6_i57;
  int32_T c6_i58;
  int32_T c6_i59;
  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  int32_T c6_i63;
  int32_T c6_i64;
  int32_T c6_i65;
  int32_T c6_i66;
  int32_T c6_i67;
  int32_T c6_i68;
  int32_T c6_i69;
  int32_T c6_i70;
  int32_T c6_i71;
  int32_T c6_i72;
  int32_T c6_i73;
  int32_T c6_i74;
  int32_T c6_i75;
  int32_T c6_i76;
  int32_T c6_i77;
  int32_T c6_i78;
  int32_T c6_i79;
  int32_T c6_i80;
  int32_T c6_i81;
  int32_T c6_i82;
  int32_T c6_i83;
  int32_T c6_i84;
  int32_T c6_i85;
  int32_T c6_i86;
  int32_T c6_i87;
  int32_T c6_i88;
  int32_T c6_i89;
  int32_T c6_i90;
  int32_T c6_i91;
  int32_T c6_i92;
  int32_T c6_i93;
  int32_T c6_i94;
  int32_T c6_i95;
  int32_T c6_i96;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  for (c6_i1 = 0; c6_i1 < 6; c6_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_V)[c6_i1], 5U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }

  for (c6_i2 = 0; c6_i2 < 9; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_M)[c6_i2], 4U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }

  for (c6_i3 = 0; c6_i3 < 3; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_p)[c6_i3], 3U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_t_Kalman, 2U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_n, 1U, 1U, 0U,
                        chartInstance->c6_sfEvent, false);
  for (c6_i4 = 0; c6_i4 < 20; c6_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_X_a)[c6_i4], 0U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *chartInstance->c6_n;
  c6_b_hoistedGlobal = *chartInstance->c6_t_Kalman;
  for (c6_i5 = 0; c6_i5 < 20; c6_i5++) {
    c6_b_X_a[c6_i5] = (*chartInstance->c6_X_a)[c6_i5];
  }

  c6_b_n = c6_hoistedGlobal;
  c6_b_t_Kalman = c6_b_hoistedGlobal;
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_b_p[c6_i6] = (*chartInstance->c6_p)[c6_i6];
  }

  for (c6_i7 = 0; c6_i7 < 9; c6_i7++) {
    c6_b_M[c6_i7] = (*chartInstance->c6_M)[c6_i7];
  }

  for (c6_i8 = 0; c6_i8 < 6; c6_i8++) {
    c6_b_V[c6_i8] = (*chartInstance->c6_V)[c6_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_t, 0U, c6_g_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_r, 1U, c6_g_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_rho_c, 2U, c6_c_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_ieps, 3U, c6_c_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_robot, 4U, c6_g_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 5U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 6U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_X_a, 7U, c6_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_n, 8U, c6_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_b_t_Kalman, 9U, c6_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_p, 10U, c6_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_M, 11U, c6_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_V, 12U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_Phi, 13U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_c_n = c6_b_n;
  c6_t_delta = c6_b_t_Kalman;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c6_c_debug_family_names,
    c6_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_t12, 0U, c6_c_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_t22, 1U, c6_c_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 2U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 3U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_n, 4U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_t_delta, 5U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_t, 6U, c6_g_sf_marshallOut,
    c6_c_sf_marshallIn);
  CV_EML_FCN(0, 4);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 73);
  c6_a = c6_t_delta;
  c6_b_a = c6_a;
  c6_c_a = c6_b_a;
  c6_eml_scalar_eg(chartInstance);
  c6_dimagree(chartInstance);
  c6_ak = c6_c_a;
  c6_d_a = c6_ak;
  c6_eml_scalar_eg(chartInstance);
  c6_c = c6_d_a * c6_d_a;
  c6_Phi_t12[0] = c6_t_delta;
  c6_Phi_t12[3] = c6_c_n * c6_c;
  c6_Phi_t12[6] = 0.0;
  c6_Phi_t12[1] = 0.0;
  c6_Phi_t12[4] = c6_t_delta;
  c6_Phi_t12[7] = 0.0;
  c6_Phi_t12[2] = 0.0;
  c6_Phi_t12[5] = 0.0;
  c6_Phi_t12[8] = c6_t_delta;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 74);
  c6_dv1[0] = 0.0;
  c6_dv1[1] = 0.0;
  c6_dv1[2] = c6_c_n;
  c6_fn_VectorToSkewSymmetricTensor(chartInstance, c6_dv1, c6_b);
  for (c6_i9 = 0; c6_i9 < 9; c6_i9++) {
    c6_b[c6_i9] *= 2.0;
  }

  c6_b_b = c6_t_delta;
  for (c6_i10 = 0; c6_i10 < 9; c6_i10++) {
    c6_b[c6_i10] *= c6_b_b;
  }

  c6_eye(chartInstance, c6_dv2);
  for (c6_i11 = 0; c6_i11 < 9; c6_i11++) {
    c6_Phi_t22[c6_i11] = c6_dv2[c6_i11] - c6_b[c6_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 76);
  c6_i12 = 0;
  c6_i13 = 0;
  for (c6_i14 = 0; c6_i14 < 3; c6_i14++) {
    for (c6_i15 = 0; c6_i15 < 3; c6_i15++) {
      c6_Phi_t[c6_i15 + c6_i12] = c6_dv3[c6_i15 + c6_i13];
    }

    c6_i12 += 6;
    c6_i13 += 3;
  }

  c6_i16 = 0;
  c6_i17 = 0;
  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    for (c6_i19 = 0; c6_i19 < 3; c6_i19++) {
      c6_Phi_t[(c6_i19 + c6_i16) + 18] = c6_Phi_t12[c6_i19 + c6_i17];
    }

    c6_i16 += 6;
    c6_i17 += 3;
  }

  c6_i20 = 0;
  for (c6_i21 = 0; c6_i21 < 3; c6_i21++) {
    for (c6_i22 = 0; c6_i22 < 3; c6_i22++) {
      c6_Phi_t[(c6_i22 + c6_i20) + 3] = 0.0;
    }

    c6_i20 += 6;
  }

  c6_i23 = 0;
  c6_i24 = 0;
  for (c6_i25 = 0; c6_i25 < 3; c6_i25++) {
    for (c6_i26 = 0; c6_i26 < 3; c6_i26++) {
      c6_Phi_t[(c6_i26 + c6_i23) + 21] = c6_Phi_t22[c6_i26 + c6_i24];
    }

    c6_i23 += 6;
    c6_i24 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -76);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i27 = 0; c6_i27 < 20; c6_i27++) {
    c6_c_X_a[c6_i27] = c6_b_X_a[c6_i27];
  }

  for (c6_i28 = 0; c6_i28 < 3; c6_i28++) {
    c6_c_p[c6_i28] = c6_b_p[c6_i28];
  }

  c6_c_t_Kalman = c6_b_t_Kalman;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_e_debug_family_names,
    c6_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_omega, 0U, c6_d_sf_marshallOut,
    c6_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_c_M, 1U, c6_c_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_A, 2U, c6_g_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 3U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 4U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_c_X_a, 5U, c6_f_sf_marshallOut,
    c6_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_c_p, 6U, c6_d_sf_marshallOut,
    c6_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_t_Kalman, 7U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Phi_r, 8U, c6_g_sf_marshallOut,
    c6_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 26);
  for (c6_i29 = 0; c6_i29 < 36; c6_i29++) {
    c6_Phi_r[c6_i29] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 27);
  for (c6_i30 = 0; c6_i30 < 3; c6_i30++) {
    c6_omega[c6_i30] = c6_c_X_a[c6_i30 + 4];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 28);
  for (c6_i31 = 0; c6_i31 < 3; c6_i31++) {
    c6_d_p[c6_i31] = c6_c_p[c6_i31];
  }

  for (c6_i32 = 0; c6_i32 < 3; c6_i32++) {
    c6_b_omega[c6_i32] = c6_omega[c6_i32];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_d_debug_family_names,
    c6_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_d_p, 2U, c6_d_sf_marshallOut,
    c6_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_omega, 3U, c6_d_sf_marshallOut,
    c6_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_c_M, 4U, c6_c_sf_marshallOut,
    c6_d_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 51);
  c6_c_M[0] = 0.0;
  c6_c_M[3] = c6_d_p[0] * c6_b_omega[2];
  c6_c_M[6] = c6_d_p[0] * c6_b_omega[1];
  c6_c_M[1] = c6_d_p[1] * c6_b_omega[2];
  c6_c_M[4] = 0.0;
  c6_c_M[7] = c6_d_p[1] * c6_b_omega[0];
  c6_c_M[2] = c6_d_p[2] * c6_b_omega[1];
  c6_c_M[5] = c6_d_p[2] * c6_b_omega[0];
  c6_c_M[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -51);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 30);
  for (c6_i33 = 0; c6_i33 < 3; c6_i33++) {
    c6_c_omega[c6_i33] = c6_omega[c6_i33];
  }

  c6_fn_VectorToSkewSymmetricTensor(chartInstance, c6_c_omega, c6_dv2);
  c6_i34 = 0;
  c6_i35 = 0;
  for (c6_i36 = 0; c6_i36 < 3; c6_i36++) {
    for (c6_i37 = 0; c6_i37 < 3; c6_i37++) {
      c6_A[c6_i37 + c6_i34] = -c6_dv2[c6_i37 + c6_i35];
    }

    c6_i34 += 6;
    c6_i35 += 3;
  }

  c6_i38 = 0;
  c6_i39 = 0;
  for (c6_i40 = 0; c6_i40 < 3; c6_i40++) {
    for (c6_i41 = 0; c6_i41 < 3; c6_i41++) {
      c6_A[(c6_i41 + c6_i38) + 18] = c6_dv4[c6_i41 + c6_i39];
    }

    c6_i38 += 6;
    c6_i39 += 3;
  }

  c6_i42 = 0;
  for (c6_i43 = 0; c6_i43 < 3; c6_i43++) {
    for (c6_i44 = 0; c6_i44 < 3; c6_i44++) {
      c6_A[(c6_i44 + c6_i42) + 3] = 0.0;
    }

    c6_i42 += 6;
  }

  c6_i45 = 0;
  c6_i46 = 0;
  for (c6_i47 = 0; c6_i47 < 3; c6_i47++) {
    for (c6_i48 = 0; c6_i48 < 3; c6_i48++) {
      c6_A[(c6_i48 + c6_i45) + 21] = c6_c_M[c6_i48 + c6_i46];
    }

    c6_i45 += 6;
    c6_i46 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 31);
  for (c6_i49 = 0; c6_i49 < 36; c6_i49++) {
    c6_e_a[c6_i49] = c6_A[c6_i49];
  }

  c6_c_b = c6_c_t_Kalman;
  for (c6_i50 = 0; c6_i50 < 36; c6_i50++) {
    c6_e_a[c6_i50] *= c6_c_b;
  }

  for (c6_i51 = 0; c6_i51 < 36; c6_i51++) {
    c6_f_a[c6_i51] = c6_e_a[c6_i51];
  }

  c6_expm(chartInstance, c6_f_a, c6_dv5);
  for (c6_i52 = 0; c6_i52 < 36; c6_i52++) {
    c6_Phi_r[c6_i52] = c6_dv5[c6_i52];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i53 = 0; c6_i53 < 3; c6_i53++) {
    c6_c_V[c6_i53] = c6_b_V[c6_i53 + 3];
  }

  c6_fn_VectorToSkewSymmetricTensor(chartInstance, c6_c_V, c6_dv2);
  for (c6_i54 = 0; c6_i54 < 9; c6_i54++) {
    c6_dv6[c6_i54] = c6_dv2[c6_i54];
  }

  c6_b_expm(chartInstance, c6_dv6, c6_dv7);
  for (c6_i55 = 0; c6_i55 < 9; c6_i55++) {
    c6_Phi_rho_c[c6_i55] = c6_dv7[c6_i55];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  c6_eye(chartInstance, c6_dv8);
  for (c6_i56 = 0; c6_i56 < 9; c6_i56++) {
    c6_Phi_ieps[c6_i56] = c6_dv8[c6_i56];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  c6_i57 = 0;
  c6_i58 = 0;
  for (c6_i59 = 0; c6_i59 < 3; c6_i59++) {
    for (c6_i60 = 0; c6_i60 < 3; c6_i60++) {
      c6_Phi_robot[c6_i60 + c6_i57] = c6_Phi_rho_c[c6_i60 + c6_i58];
    }

    c6_i57 += 6;
    c6_i58 += 3;
  }

  c6_i61 = 0;
  for (c6_i62 = 0; c6_i62 < 3; c6_i62++) {
    for (c6_i63 = 0; c6_i63 < 3; c6_i63++) {
      c6_Phi_robot[(c6_i63 + c6_i61) + 18] = 0.0;
    }

    c6_i61 += 6;
  }

  c6_i64 = 0;
  for (c6_i65 = 0; c6_i65 < 3; c6_i65++) {
    for (c6_i66 = 0; c6_i66 < 3; c6_i66++) {
      c6_Phi_robot[(c6_i66 + c6_i64) + 3] = 0.0;
    }

    c6_i64 += 6;
  }

  c6_i67 = 0;
  c6_i68 = 0;
  for (c6_i69 = 0; c6_i69 < 3; c6_i69++) {
    for (c6_i70 = 0; c6_i70 < 3; c6_i70++) {
      c6_Phi_robot[(c6_i70 + c6_i67) + 21] = c6_Phi_ieps[c6_i70 + c6_i68];
    }

    c6_i67 += 6;
    c6_i68 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
  c6_i71 = 0;
  c6_i72 = 0;
  for (c6_i73 = 0; c6_i73 < 6; c6_i73++) {
    for (c6_i74 = 0; c6_i74 < 6; c6_i74++) {
      c6_b_Phi[c6_i74 + c6_i71] = c6_Phi_r[c6_i74 + c6_i72];
    }

    c6_i71 += 18;
    c6_i72 += 6;
  }

  c6_i75 = 0;
  for (c6_i76 = 0; c6_i76 < 12; c6_i76++) {
    for (c6_i77 = 0; c6_i77 < 6; c6_i77++) {
      c6_b_Phi[(c6_i77 + c6_i75) + 108] = 0.0;
    }

    c6_i75 += 18;
  }

  c6_i78 = 0;
  for (c6_i79 = 0; c6_i79 < 6; c6_i79++) {
    for (c6_i80 = 0; c6_i80 < 6; c6_i80++) {
      c6_b_Phi[(c6_i80 + c6_i78) + 6] = 0.0;
    }

    c6_i78 += 18;
  }

  c6_i81 = 0;
  c6_i82 = 0;
  for (c6_i83 = 0; c6_i83 < 6; c6_i83++) {
    for (c6_i84 = 0; c6_i84 < 6; c6_i84++) {
      c6_b_Phi[(c6_i84 + c6_i81) + 114] = c6_Phi_t[c6_i84 + c6_i82];
    }

    c6_i81 += 18;
    c6_i82 += 6;
  }

  c6_i85 = 0;
  for (c6_i86 = 0; c6_i86 < 6; c6_i86++) {
    for (c6_i87 = 0; c6_i87 < 6; c6_i87++) {
      c6_b_Phi[(c6_i87 + c6_i85) + 222] = 0.0;
    }

    c6_i85 += 18;
  }

  c6_i88 = 0;
  for (c6_i89 = 0; c6_i89 < 12; c6_i89++) {
    for (c6_i90 = 0; c6_i90 < 6; c6_i90++) {
      c6_b_Phi[(c6_i90 + c6_i88) + 12] = 0.0;
    }

    c6_i88 += 18;
  }

  c6_i91 = 0;
  c6_i92 = 0;
  for (c6_i93 = 0; c6_i93 < 6; c6_i93++) {
    for (c6_i94 = 0; c6_i94 < 6; c6_i94++) {
      c6_b_Phi[(c6_i94 + c6_i91) + 228] = c6_Phi_robot[c6_i94 + c6_i92];
    }

    c6_i91 += 18;
    c6_i92 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i95 = 0; c6_i95 < 324; c6_i95++) {
    (*chartInstance->c6_Phi)[c6_i95] = c6_b_Phi[c6_i95];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EKF_SIL_02MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i96 = 0; c6_i96 < 324; c6_i96++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_Phi)[c6_i96], 6U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }
}

static void mdl_start_c6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc6_EKF_SIL_02(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c6_fn_VectorToSkewSymmetricTensor(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, real_T c6_v[3], real_T c6_SkewSymmetricTensor[9])
{
  uint32_T c6_debug_family_var_map[4];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i97;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c6_b_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_e_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_v, 2U, c6_d_sf_marshallOut,
    c6_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_SkewSymmetricTensor, 3U,
    c6_c_sf_marshallOut, c6_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 2);
  for (c6_i97 = 0; c6_i97 < 9; c6_i97++) {
    c6_SkewSymmetricTensor[c6_i97] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_SkewSymmetricTensor[0] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_SkewSymmetricTensor[4] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_SkewSymmetricTensor[8] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_SkewSymmetricTensor[3] = -c6_v[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_SkewSymmetricTensor[6] = c6_v[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_SkewSymmetricTensor[7] = -c6_v[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_SkewSymmetricTensor[1] = c6_v[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_SkewSymmetricTensor[2] = -c6_v[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  c6_SkewSymmetricTensor[5] = c6_v[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, c6_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Ana\\Documents\\MATLAB\\Model_02_Simulink-Aghili--2007-\\fn_VectorToSkewSymmetricTensor.m"));
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i98;
  int32_T c6_i99;
  int32_T c6_i100;
  real_T c6_u[324];
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i98 = 0;
  for (c6_i99 = 0; c6_i99 < 18; c6_i99++) {
    for (c6_i100 = 0; c6_i100 < 18; c6_i100++) {
      c6_u[c6_i100 + c6_i98] = (*(real_T (*)[324])c6_inData)[c6_i100 + c6_i98];
    }

    c6_i98 += 18;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 18, 18), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_b_Phi, const char_T *c6_identifier, real_T c6_y[324])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Phi), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_Phi);
}

static void c6_b_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[324])
{
  real_T c6_dv9[324];
  int32_T c6_i101;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv9, 1, 0, 0U, 1, 0U, 2, 18,
                18);
  for (c6_i101 = 0; c6_i101 < 324; c6_i101++) {
    c6_y[c6_i101] = c6_dv9[c6_i101];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_Phi;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[324];
  int32_T c6_i102;
  int32_T c6_i103;
  int32_T c6_i104;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_b_Phi = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Phi), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_Phi);
  c6_i102 = 0;
  for (c6_i103 = 0; c6_i103 < 18; c6_i103++) {
    for (c6_i104 = 0; c6_i104 < 18; c6_i104++) {
      (*(real_T (*)[324])c6_outData)[c6_i104 + c6_i102] = c6_y[c6_i104 + c6_i102];
    }

    c6_i102 += 18;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i105;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i105 = 0; c6_i105 < 6; c6_i105++) {
    c6_u[c6_i105] = (*(real_T (*)[6])c6_inData)[c6_i105];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i106;
  int32_T c6_i107;
  int32_T c6_i108;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i106 = 0;
  for (c6_i107 = 0; c6_i107 < 3; c6_i107++) {
    for (c6_i108 = 0; c6_i108 < 3; c6_i108++) {
      c6_u[c6_i108 + c6_i106] = (*(real_T (*)[9])c6_inData)[c6_i108 + c6_i106];
    }

    c6_i106 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i109;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i109 = 0; c6_i109 < 3; c6_i109++) {
    c6_u[c6_i109] = (*(real_T (*)[3])c6_inData)[c6_i109];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i110;
  real_T c6_u[20];
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i110 = 0; c6_i110 < 20; c6_i110++) {
    c6_u[c6_i110] = (*(real_T (*)[20])c6_inData)[c6_i110];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 20), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i111;
  int32_T c6_i112;
  int32_T c6_i113;
  real_T c6_u[36];
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i111 = 0;
  for (c6_i112 = 0; c6_i112 < 6; c6_i112++) {
    for (c6_i113 = 0; c6_i113 < 6; c6_i113++) {
      c6_u[c6_i113 + c6_i111] = (*(real_T (*)[36])c6_inData)[c6_i113 + c6_i111];
    }

    c6_i111 += 6;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[36])
{
  real_T c6_dv10[36];
  int32_T c6_i114;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv10, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c6_i114 = 0; c6_i114 < 36; c6_i114++) {
    c6_y[c6_i114] = c6_dv10[c6_i114];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Phi_robot;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[36];
  int32_T c6_i115;
  int32_T c6_i116;
  int32_T c6_i117;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_Phi_robot = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Phi_robot), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_Phi_robot);
  c6_i115 = 0;
  for (c6_i116 = 0; c6_i116 < 6; c6_i116++) {
    for (c6_i117 = 0; c6_i117 < 6; c6_i117++) {
      (*(real_T (*)[36])c6_outData)[c6_i117 + c6_i115] = c6_y[c6_i117 + c6_i115];
    }

    c6_i115 += 6;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static void c6_e_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[9])
{
  real_T c6_dv11[9];
  int32_T c6_i118;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv11, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c6_i118 = 0; c6_i118 < 9; c6_i118++) {
    c6_y[c6_i118] = c6_dv11[c6_i118];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Phi_ieps;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[9];
  int32_T c6_i119;
  int32_T c6_i120;
  int32_T c6_i121;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_Phi_ieps = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Phi_ieps), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Phi_ieps);
  c6_i119 = 0;
  for (c6_i120 = 0; c6_i120 < 3; c6_i120++) {
    for (c6_i121 = 0; c6_i121 < 3; c6_i121++) {
      (*(real_T (*)[9])c6_outData)[c6_i121 + c6_i119] = c6_y[c6_i121 + c6_i119];
    }

    c6_i119 += 3;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static void c6_f_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3])
{
  real_T c6_dv12[3];
  int32_T c6_i122;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv12, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i122 = 0; c6_i122 < 3; c6_i122++) {
    c6_y[c6_i122] = c6_dv12[c6_i122];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_v;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i123;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_v = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_v), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_v);
  for (c6_i123 = 0; c6_i123 < 3; c6_i123++) {
    (*(real_T (*)[3])c6_outData)[c6_i123] = c6_y[c6_i123];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static void c6_g_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[20])
{
  real_T c6_dv13[20];
  int32_T c6_i124;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv13, 1, 0, 0U, 1, 0U, 1, 20);
  for (c6_i124 = 0; c6_i124 < 20; c6_i124++) {
    c6_y[c6_i124] = c6_dv13[c6_i124];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_X_a;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[20];
  int32_T c6_i125;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_b_X_a = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_X_a), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_X_a);
  for (c6_i125 = 0; c6_i125 < 20; c6_i125++) {
    (*(real_T (*)[20])c6_outData)[c6_i125] = c6_y[c6_i125];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_EKF_SIL_02_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "fn_VectorToSkewSymmetricTensor"), "name", "name", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[E]C:/Users/Ana/Documents/MATLAB/Model_02_Simulink-Aghili--2007-/fn_VectorToSkewSymmetricTensor.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1465418202U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static void c6_eml_scalar_eg(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_dimagree(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_eye(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_I[9])
{
  int32_T c6_i126;
  int32_T c6_k;
  int32_T c6_b_k;
  for (c6_i126 = 0; c6_i126 < 9; c6_i126++) {
    c6_I[c6_i126] = 0.0;
  }

  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 4; c6_k++) {
    c6_b_k = c6_k;
    c6_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)) -
      1] = 1.0;
  }
}

static void c6_eml_switch_helper(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_expm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_A[36],
                    real_T c6_F[36])
{
  real_T c6_normA;
  int32_T c6_j;
  real_T c6_b_j;
  real_T c6_s;
  int32_T c6_i;
  real_T c6_b_i;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_y;
  real_T c6_c_x;
  boolean_T c6_b;
  int32_T c6_c_i;
  real_T c6_d_i;
  static real_T c6_theta[5] = { 0.01495585217958292, 0.253939833006323,
    0.95041789961629319, 2.097847961257068, 5.3719203511481517 };

  int32_T c6_i127;
  real_T c6_b_A[36];
  static real_T c6_dv14[5] = { 3.0, 5.0, 7.0, 9.0, 13.0 };

  real_T c6_b_s;
  real_T c6_t;
  real_T c6_b_t;
  real_T c6_c_s;
  real_T c6_b_y;
  real_T c6_c_y;
  int32_T c6_i128;
  int32_T c6_i129;
  real_T c6_c_A[36];
  real_T c6_d_s;
  int32_T c6_i130;
  int32_T c6_c_j;
  int32_T c6_i131;
  real_T c6_d_A[36];
  int32_T c6_i132;
  int32_T c6_i133;
  int32_T c6_i134;
  int32_T c6_i135;
  int32_T c6_i136;
  boolean_T exitg1;
  boolean_T exitg2;
  c6_normA = 0.0;
  c6_j = 0;
  exitg2 = false;
  while ((exitg2 == false) && (c6_j < 6)) {
    c6_b_j = 1.0 + (real_T)c6_j;
    c6_s = 0.0;
    for (c6_i = 0; c6_i < 6; c6_i++) {
      c6_b_i = 1.0 + (real_T)c6_i;
      c6_x = c6_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", c6_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c6_b_j), 1, 6, 2, 0) - 1)) - 1];
      c6_b_x = c6_x;
      c6_y = muDoubleScalarAbs(c6_b_x);
      c6_s += c6_y;
    }

    c6_c_x = c6_s;
    c6_b = muDoubleScalarIsNaN(c6_c_x);
    if (c6_b) {
      c6_normA = rtNaN;
      exitg2 = true;
    } else {
      if (c6_s > c6_normA) {
        c6_normA = c6_s;
      }

      c6_j++;
    }
  }

  if (c6_normA <= 5.3719203511481517) {
    c6_c_i = 0;
    exitg1 = false;
    while ((exitg1 == false) && (c6_c_i < 5)) {
      c6_d_i = 1.0 + (real_T)c6_c_i;
      if (c6_normA <= c6_theta[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c6_d_i), 1, 5, 1, 0) - 1]) {
        for (c6_i127 = 0; c6_i127 < 36; c6_i127++) {
          c6_b_A[c6_i127] = c6_A[c6_i127];
        }

        c6_PadeApproximantOfDegree(chartInstance, c6_b_A,
          c6_dv14[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c6_d_i), 1, 5, 1, 0) - 1], c6_F);
        exitg1 = true;
      } else {
        c6_c_i++;
      }
    }
  } else {
    c6_log2(chartInstance, c6_normA / 5.3719203511481517, &c6_t, &c6_b_s);
    c6_b_t = c6_t;
    c6_c_s = c6_b_s;
    if (c6_b_t == 0.5) {
      c6_c_s--;
    }

    c6_b_y = c6_pow2(chartInstance, c6_c_s);
    c6_c_y = c6_b_y;
    for (c6_i128 = 0; c6_i128 < 36; c6_i128++) {
      c6_A[c6_i128] /= c6_c_y;
    }

    for (c6_i129 = 0; c6_i129 < 36; c6_i129++) {
      c6_c_A[c6_i129] = c6_A[c6_i129];
    }

    c6_PadeApproximantOfDegree(chartInstance, c6_c_A, 13.0, c6_F);
    c6_d_s = c6_c_s;
    c6_i130 = (int32_T)c6_d_s;
    _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c6_d_s, mxDOUBLE_CLASS, c6_i130);
    for (c6_c_j = 0; c6_c_j < c6_i130; c6_c_j++) {
      c6_b_eml_scalar_eg(chartInstance);
      c6_b_eml_scalar_eg(chartInstance);
      c6_threshold(chartInstance);
      for (c6_i131 = 0; c6_i131 < 36; c6_i131++) {
        c6_d_A[c6_i131] = c6_F[c6_i131];
      }

      for (c6_i132 = 0; c6_i132 < 6; c6_i132++) {
        c6_i133 = 0;
        for (c6_i134 = 0; c6_i134 < 6; c6_i134++) {
          c6_F[c6_i133 + c6_i132] = 0.0;
          c6_i135 = 0;
          for (c6_i136 = 0; c6_i136 < 6; c6_i136++) {
            c6_F[c6_i133 + c6_i132] += c6_d_A[c6_i135 + c6_i132] *
              c6_d_A[c6_i136 + c6_i133];
            c6_i135 += 6;
          }

          c6_i133 += 6;
        }
      }
    }
  }
}

static void c6_PadeApproximantOfDegree(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, real_T c6_A[36], real_T c6_m, real_T c6_F[36])
{
  int32_T c6_i137;
  int32_T c6_i138;
  int32_T c6_i139;
  real_T c6_A2[36];
  int32_T c6_i140;
  int32_T c6_i141;
  int32_T c6_i142;
  int32_T c6_k;
  real_T c6_b_k;
  int32_T c6_i143;
  real_T c6_y[36];
  int32_T c6_i144;
  int32_T c6_i145;
  int32_T c6_i146;
  int32_T c6_i147;
  int32_T c6_i148;
  int32_T c6_i149;
  real_T c6_b_V[36];
  real_T c6_d;
  int32_T c6_i150;
  int32_T c6_i151;
  int32_T c6_i152;
  real_T c6_A3[36];
  int32_T c6_i153;
  int32_T c6_i154;
  int32_T c6_i155;
  int32_T c6_i156;
  int32_T c6_c_k;
  int32_T c6_i157;
  int32_T c6_i158;
  int32_T c6_i159;
  int32_T c6_i160;
  int32_T c6_i161;
  int32_T c6_i162;
  int32_T c6_i163;
  int32_T c6_i164;
  int32_T c6_i165;
  int32_T c6_i166;
  int32_T c6_i167;
  int32_T c6_i168;
  real_T c6_A4[36];
  int32_T c6_i169;
  int32_T c6_i170;
  int32_T c6_i171;
  int32_T c6_i172;
  real_T c6_b_y[36];
  int32_T c6_i173;
  int32_T c6_d_k;
  int32_T c6_i174;
  int32_T c6_i175;
  int32_T c6_i176;
  int32_T c6_i177;
  int32_T c6_i178;
  int32_T c6_i179;
  int32_T c6_i180;
  int32_T c6_i181;
  int32_T c6_i182;
  int32_T c6_i183;
  int32_T c6_i184;
  int32_T c6_i185;
  int32_T c6_i186;
  int32_T c6_i187;
  int32_T c6_i188;
  int32_T c6_i189;
  int32_T c6_i190;
  int32_T c6_i191;
  real_T c6_c_y[36];
  int32_T c6_i192;
  int32_T c6_e_k;
  int32_T c6_i193;
  int32_T c6_i194;
  int32_T c6_i195;
  int32_T c6_i196;
  int32_T c6_i197;
  int32_T c6_i198;
  int32_T c6_i199;
  int32_T c6_i200;
  int32_T c6_i201;
  int32_T c6_i202;
  int32_T c6_i203;
  int32_T c6_i204;
  int32_T c6_i205;
  int32_T c6_i206;
  int32_T c6_i207;
  int32_T c6_f_k;
  int32_T c6_i208;
  int32_T c6_i209;
  int32_T c6_i210;
  int32_T c6_i211;
  int32_T c6_i212;
  int32_T c6_i213;
  int32_T c6_i214;
  int32_T c6_i215;
  int32_T c6_i216;
  int32_T c6_i217;
  int32_T c6_i218;
  int32_T c6_i219;
  int32_T c6_i220;
  int32_T c6_i221;
  int32_T c6_i222;
  int32_T c6_i223;
  int32_T c6_i224;
  int32_T c6_i225;
  int32_T c6_i226;
  int32_T c6_i227;
  int32_T c6_i228;
  int32_T c6_i229;
  int32_T c6_i230;
  int32_T c6_i231;
  int32_T c6_i232;
  int32_T c6_i233;
  int32_T c6_i234;
  int32_T c6_g_k;
  int32_T c6_h_k;
  int32_T c6_info;
  int32_T c6_ipiv[6];
  int32_T c6_b_info;
  int32_T c6_c_info;
  int32_T c6_d_info;
  int32_T c6_xi;
  int32_T c6_b_xi;
  int32_T c6_ip;
  int32_T c6_xj;
  int32_T c6_b_xj;
  real_T c6_temp;
  int32_T c6_i235;
  real_T c6_c_V[36];
  int32_T c6_i236;
  real_T c6_d_V[36];
  int32_T c6_i_k;
  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  c6_threshold(chartInstance);
  for (c6_i137 = 0; c6_i137 < 6; c6_i137++) {
    c6_i138 = 0;
    for (c6_i139 = 0; c6_i139 < 6; c6_i139++) {
      c6_A2[c6_i138 + c6_i137] = 0.0;
      c6_i140 = 0;
      for (c6_i141 = 0; c6_i141 < 6; c6_i141++) {
        c6_A2[c6_i138 + c6_i137] += c6_A[c6_i140 + c6_i137] * c6_A[c6_i141 +
          c6_i138];
        c6_i140 += 6;
      }

      c6_i138 += 6;
    }
  }

  if (c6_m == 3.0) {
    for (c6_i142 = 0; c6_i142 < 36; c6_i142++) {
      c6_F[c6_i142] = c6_A2[c6_i142];
    }

    for (c6_k = 0; c6_k < 6; c6_k++) {
      c6_b_k = 1.0 + (real_T)c6_k;
      c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] =
        c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1]
        + 60.0;
    }

    c6_b_eml_scalar_eg(chartInstance);
    c6_b_eml_scalar_eg(chartInstance);
    c6_threshold(chartInstance);
    for (c6_i143 = 0; c6_i143 < 36; c6_i143++) {
      c6_y[c6_i143] = c6_F[c6_i143];
    }

    for (c6_i144 = 0; c6_i144 < 6; c6_i144++) {
      c6_i145 = 0;
      for (c6_i146 = 0; c6_i146 < 6; c6_i146++) {
        c6_F[c6_i145 + c6_i144] = 0.0;
        c6_i147 = 0;
        for (c6_i148 = 0; c6_i148 < 6; c6_i148++) {
          c6_F[c6_i145 + c6_i144] += c6_A[c6_i147 + c6_i144] * c6_y[c6_i148 +
            c6_i145];
          c6_i147 += 6;
        }

        c6_i145 += 6;
      }
    }

    for (c6_i149 = 0; c6_i149 < 36; c6_i149++) {
      c6_b_V[c6_i149] = 12.0 * c6_A2[c6_i149];
    }

    c6_d = 120.0;
  } else {
    c6_b_eml_scalar_eg(chartInstance);
    c6_b_eml_scalar_eg(chartInstance);
    c6_threshold(chartInstance);
    for (c6_i150 = 0; c6_i150 < 6; c6_i150++) {
      c6_i151 = 0;
      for (c6_i152 = 0; c6_i152 < 6; c6_i152++) {
        c6_A3[c6_i151 + c6_i150] = 0.0;
        c6_i153 = 0;
        for (c6_i154 = 0; c6_i154 < 6; c6_i154++) {
          c6_A3[c6_i151 + c6_i150] += c6_A2[c6_i153 + c6_i150] * c6_A2[c6_i154 +
            c6_i151];
          c6_i153 += 6;
        }

        c6_i151 += 6;
      }
    }

    if (c6_m == 5.0) {
      for (c6_i155 = 0; c6_i155 < 36; c6_i155++) {
        c6_F[c6_i155] = 420.0 * c6_A2[c6_i155];
      }

      for (c6_i156 = 0; c6_i156 < 36; c6_i156++) {
        c6_F[c6_i156] += c6_A3[c6_i156];
      }

      for (c6_c_k = 0; c6_c_k < 6; c6_c_k++) {
        c6_b_k = 1.0 + (real_T)c6_c_k;
        c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] =
          c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1]
          + 15120.0;
      }

      c6_b_eml_scalar_eg(chartInstance);
      c6_b_eml_scalar_eg(chartInstance);
      c6_threshold(chartInstance);
      for (c6_i157 = 0; c6_i157 < 36; c6_i157++) {
        c6_y[c6_i157] = c6_F[c6_i157];
      }

      for (c6_i158 = 0; c6_i158 < 6; c6_i158++) {
        c6_i159 = 0;
        for (c6_i160 = 0; c6_i160 < 6; c6_i160++) {
          c6_F[c6_i159 + c6_i158] = 0.0;
          c6_i161 = 0;
          for (c6_i162 = 0; c6_i162 < 6; c6_i162++) {
            c6_F[c6_i159 + c6_i158] += c6_A[c6_i161 + c6_i158] * c6_y[c6_i162 +
              c6_i159];
            c6_i161 += 6;
          }

          c6_i159 += 6;
        }
      }

      for (c6_i163 = 0; c6_i163 < 36; c6_i163++) {
        c6_A3[c6_i163] *= 30.0;
      }

      for (c6_i164 = 0; c6_i164 < 36; c6_i164++) {
        c6_A2[c6_i164] *= 3360.0;
      }

      for (c6_i165 = 0; c6_i165 < 36; c6_i165++) {
        c6_b_V[c6_i165] = c6_A3[c6_i165] + c6_A2[c6_i165];
      }

      c6_d = 30240.0;
    } else {
      c6_b_eml_scalar_eg(chartInstance);
      c6_b_eml_scalar_eg(chartInstance);
      c6_threshold(chartInstance);
      for (c6_i166 = 0; c6_i166 < 6; c6_i166++) {
        c6_i167 = 0;
        for (c6_i168 = 0; c6_i168 < 6; c6_i168++) {
          c6_A4[c6_i167 + c6_i166] = 0.0;
          c6_i169 = 0;
          for (c6_i170 = 0; c6_i170 < 6; c6_i170++) {
            c6_A4[c6_i167 + c6_i166] += c6_A3[c6_i169 + c6_i166] * c6_A2[c6_i170
              + c6_i167];
            c6_i169 += 6;
          }

          c6_i167 += 6;
        }
      }

      if (c6_m == 7.0) {
        for (c6_i171 = 0; c6_i171 < 36; c6_i171++) {
          c6_F[c6_i171] = 1512.0 * c6_A3[c6_i171];
        }

        for (c6_i172 = 0; c6_i172 < 36; c6_i172++) {
          c6_b_y[c6_i172] = 277200.0 * c6_A2[c6_i172];
        }

        for (c6_i173 = 0; c6_i173 < 36; c6_i173++) {
          c6_F[c6_i173] = (c6_A4[c6_i173] + c6_F[c6_i173]) + c6_b_y[c6_i173];
        }

        for (c6_d_k = 0; c6_d_k < 6; c6_d_k++) {
          c6_b_k = 1.0 + (real_T)c6_d_k;
          c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1]
            = c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", c6_b_k), 1, 6, 1, 0) + 6 *
                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] + 8.64864E+6;
        }

        c6_b_eml_scalar_eg(chartInstance);
        c6_b_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i174 = 0; c6_i174 < 36; c6_i174++) {
          c6_y[c6_i174] = c6_F[c6_i174];
        }

        for (c6_i175 = 0; c6_i175 < 6; c6_i175++) {
          c6_i176 = 0;
          for (c6_i177 = 0; c6_i177 < 6; c6_i177++) {
            c6_F[c6_i176 + c6_i175] = 0.0;
            c6_i178 = 0;
            for (c6_i179 = 0; c6_i179 < 6; c6_i179++) {
              c6_F[c6_i176 + c6_i175] += c6_A[c6_i178 + c6_i175] * c6_y[c6_i179
                + c6_i176];
              c6_i178 += 6;
            }

            c6_i176 += 6;
          }
        }

        for (c6_i180 = 0; c6_i180 < 36; c6_i180++) {
          c6_A4[c6_i180] *= 56.0;
        }

        for (c6_i181 = 0; c6_i181 < 36; c6_i181++) {
          c6_A3[c6_i181] *= 25200.0;
        }

        for (c6_i182 = 0; c6_i182 < 36; c6_i182++) {
          c6_A2[c6_i182] *= 1.99584E+6;
        }

        for (c6_i183 = 0; c6_i183 < 36; c6_i183++) {
          c6_b_V[c6_i183] = (c6_A4[c6_i183] + c6_A3[c6_i183]) + c6_A2[c6_i183];
        }

        c6_d = 1.729728E+7;
      } else if (c6_m == 9.0) {
        c6_b_eml_scalar_eg(chartInstance);
        c6_b_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i184 = 0; c6_i184 < 6; c6_i184++) {
          c6_i185 = 0;
          for (c6_i186 = 0; c6_i186 < 6; c6_i186++) {
            c6_b_V[c6_i185 + c6_i184] = 0.0;
            c6_i187 = 0;
            for (c6_i188 = 0; c6_i188 < 6; c6_i188++) {
              c6_b_V[c6_i185 + c6_i184] += c6_A4[c6_i187 + c6_i184] *
                c6_A2[c6_i188 + c6_i185];
              c6_i187 += 6;
            }

            c6_i185 += 6;
          }
        }

        for (c6_i189 = 0; c6_i189 < 36; c6_i189++) {
          c6_F[c6_i189] = 3960.0 * c6_A4[c6_i189];
        }

        for (c6_i190 = 0; c6_i190 < 36; c6_i190++) {
          c6_b_y[c6_i190] = 2.16216E+6 * c6_A3[c6_i190];
        }

        for (c6_i191 = 0; c6_i191 < 36; c6_i191++) {
          c6_c_y[c6_i191] = 3.027024E+8 * c6_A2[c6_i191];
        }

        for (c6_i192 = 0; c6_i192 < 36; c6_i192++) {
          c6_F[c6_i192] = ((c6_b_V[c6_i192] + c6_F[c6_i192]) + c6_b_y[c6_i192])
            + c6_c_y[c6_i192];
        }

        for (c6_e_k = 0; c6_e_k < 6; c6_e_k++) {
          c6_b_k = 1.0 + (real_T)c6_e_k;
          c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1]
            = c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", c6_b_k), 1, 6, 1, 0) + 6 *
                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] + 8.8216128E+9;
        }

        c6_b_eml_scalar_eg(chartInstance);
        c6_b_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i193 = 0; c6_i193 < 36; c6_i193++) {
          c6_y[c6_i193] = c6_F[c6_i193];
        }

        for (c6_i194 = 0; c6_i194 < 6; c6_i194++) {
          c6_i195 = 0;
          for (c6_i196 = 0; c6_i196 < 6; c6_i196++) {
            c6_F[c6_i195 + c6_i194] = 0.0;
            c6_i197 = 0;
            for (c6_i198 = 0; c6_i198 < 6; c6_i198++) {
              c6_F[c6_i195 + c6_i194] += c6_A[c6_i197 + c6_i194] * c6_y[c6_i198
                + c6_i195];
              c6_i197 += 6;
            }

            c6_i195 += 6;
          }
        }

        for (c6_i199 = 0; c6_i199 < 36; c6_i199++) {
          c6_b_V[c6_i199] *= 90.0;
        }

        for (c6_i200 = 0; c6_i200 < 36; c6_i200++) {
          c6_A4[c6_i200] *= 110880.0;
        }

        for (c6_i201 = 0; c6_i201 < 36; c6_i201++) {
          c6_A3[c6_i201] *= 3.027024E+7;
        }

        for (c6_i202 = 0; c6_i202 < 36; c6_i202++) {
          c6_A2[c6_i202] *= 2.0756736E+9;
        }

        for (c6_i203 = 0; c6_i203 < 36; c6_i203++) {
          c6_b_V[c6_i203] = ((c6_b_V[c6_i203] + c6_A4[c6_i203]) + c6_A3[c6_i203])
            + c6_A2[c6_i203];
        }

        c6_d = 1.76432256E+10;
      } else {
        for (c6_i204 = 0; c6_i204 < 36; c6_i204++) {
          c6_F[c6_i204] = 3.352212864E+10 * c6_A4[c6_i204];
        }

        for (c6_i205 = 0; c6_i205 < 36; c6_i205++) {
          c6_b_y[c6_i205] = 1.05594705216E+13 * c6_A3[c6_i205];
        }

        for (c6_i206 = 0; c6_i206 < 36; c6_i206++) {
          c6_c_y[c6_i206] = 1.1873537964288E+15 * c6_A2[c6_i206];
        }

        for (c6_i207 = 0; c6_i207 < 36; c6_i207++) {
          c6_F[c6_i207] = (c6_F[c6_i207] + c6_b_y[c6_i207]) + c6_c_y[c6_i207];
        }

        for (c6_f_k = 0; c6_f_k < 6; c6_f_k++) {
          c6_b_k = 1.0 + (real_T)c6_f_k;
          c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1]
            = c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", c6_b_k), 1, 6, 1, 0) + 6 *
                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] + 3.238237626624E+16;
        }

        for (c6_i208 = 0; c6_i208 < 36; c6_i208++) {
          c6_b_y[c6_i208] = 16380.0 * c6_A3[c6_i208];
        }

        for (c6_i209 = 0; c6_i209 < 36; c6_i209++) {
          c6_c_y[c6_i209] = 4.08408E+7 * c6_A2[c6_i209];
        }

        for (c6_i210 = 0; c6_i210 < 36; c6_i210++) {
          c6_b_y[c6_i210] = (c6_A4[c6_i210] + c6_b_y[c6_i210]) + c6_c_y[c6_i210];
        }

        c6_b_eml_scalar_eg(chartInstance);
        c6_b_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i211 = 0; c6_i211 < 6; c6_i211++) {
          c6_i212 = 0;
          for (c6_i213 = 0; c6_i213 < 6; c6_i213++) {
            c6_c_y[c6_i212 + c6_i211] = 0.0;
            c6_i214 = 0;
            for (c6_i215 = 0; c6_i215 < 6; c6_i215++) {
              c6_c_y[c6_i212 + c6_i211] += c6_A4[c6_i214 + c6_i211] *
                c6_b_y[c6_i215 + c6_i212];
              c6_i214 += 6;
            }

            c6_i212 += 6;
          }
        }

        for (c6_i216 = 0; c6_i216 < 36; c6_i216++) {
          c6_c_y[c6_i216] += c6_F[c6_i216];
        }

        c6_b_eml_scalar_eg(chartInstance);
        c6_b_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i217 = 0; c6_i217 < 6; c6_i217++) {
          c6_i218 = 0;
          for (c6_i219 = 0; c6_i219 < 6; c6_i219++) {
            c6_F[c6_i218 + c6_i217] = 0.0;
            c6_i220 = 0;
            for (c6_i221 = 0; c6_i221 < 6; c6_i221++) {
              c6_F[c6_i218 + c6_i217] += c6_A[c6_i220 + c6_i217] *
                c6_c_y[c6_i221 + c6_i218];
              c6_i220 += 6;
            }

            c6_i218 += 6;
          }
        }

        for (c6_i222 = 0; c6_i222 < 36; c6_i222++) {
          c6_b_y[c6_i222] = 182.0 * c6_A4[c6_i222];
        }

        for (c6_i223 = 0; c6_i223 < 36; c6_i223++) {
          c6_c_y[c6_i223] = 960960.0 * c6_A3[c6_i223];
        }

        for (c6_i224 = 0; c6_i224 < 36; c6_i224++) {
          c6_y[c6_i224] = 1.32324192E+9 * c6_A2[c6_i224];
        }

        for (c6_i225 = 0; c6_i225 < 36; c6_i225++) {
          c6_b_y[c6_i225] = (c6_b_y[c6_i225] + c6_c_y[c6_i225]) + c6_y[c6_i225];
        }

        c6_b_eml_scalar_eg(chartInstance);
        c6_b_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i226 = 0; c6_i226 < 6; c6_i226++) {
          c6_i227 = 0;
          for (c6_i228 = 0; c6_i228 < 6; c6_i228++) {
            c6_b_V[c6_i227 + c6_i226] = 0.0;
            c6_i229 = 0;
            for (c6_i230 = 0; c6_i230 < 6; c6_i230++) {
              c6_b_V[c6_i227 + c6_i226] += c6_A4[c6_i229 + c6_i226] *
                c6_b_y[c6_i230 + c6_i227];
              c6_i229 += 6;
            }

            c6_i227 += 6;
          }
        }

        for (c6_i231 = 0; c6_i231 < 36; c6_i231++) {
          c6_A4[c6_i231] *= 6.704425728E+11;
        }

        for (c6_i232 = 0; c6_i232 < 36; c6_i232++) {
          c6_A3[c6_i232] *= 1.29060195264E+14;
        }

        for (c6_i233 = 0; c6_i233 < 36; c6_i233++) {
          c6_A2[c6_i233] *= 7.7717703038976E+15;
        }

        for (c6_i234 = 0; c6_i234 < 36; c6_i234++) {
          c6_b_V[c6_i234] = ((c6_b_V[c6_i234] + c6_A4[c6_i234]) + c6_A3[c6_i234])
            + c6_A2[c6_i234];
        }

        c6_d = 6.476475253248E+16;
      }
    }
  }

  for (c6_g_k = 0; c6_g_k < 6; c6_g_k++) {
    c6_b_k = 1.0 + (real_T)c6_g_k;
    c6_b_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] =
      c6_b_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c6_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1]
      + c6_d;
  }

  for (c6_h_k = 0; c6_h_k < 36; c6_h_k++) {
    c6_b_k = 1.0 + (real_T)c6_h_k;
    c6_b_V[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_b_k), 1, 36, 1, 0) - 1] = c6_b_V[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 36, 1, 0) - 1] -
      c6_F[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_b_k), 1, 36, 1, 0) - 1];
    c6_F[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_k),
      1, 36, 1, 0) - 1] = 2.0 * c6_F[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c6_b_k), 1, 36, 1, 0) - 1];
  }

  c6_b_eml_matlab_zgetrf(chartInstance, c6_b_V, c6_ipiv, &c6_info);
  c6_b_info = c6_info;
  c6_c_info = c6_b_info;
  c6_d_info = c6_c_info;
  if (c6_d_info > 0) {
    c6_eml_warning(chartInstance);
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_eml_switch_helper(chartInstance);
  for (c6_xi = 1; c6_xi < 6; c6_xi++) {
    c6_b_xi = c6_xi;
    if (c6_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_xi), 1, 6, 1, 0) - 1] != c6_b_xi) {
      c6_ip = c6_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_b_xi), 1, 6, 1, 0) - 1];
      c6_eml_switch_helper(chartInstance);
      for (c6_xj = 1; c6_xj < 7; c6_xj++) {
        c6_b_xj = c6_xj;
        c6_temp = c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_xi), 1, 6, 1, 0) + 6 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_xj), 1, 6, 2, 0) - 1)) - 1];
        c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_xi), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_xj), 1, 6, 2, 0)
               - 1)) - 1] = c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_ip), 1, 6, 1, 0) + 6 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_xj), 1, 6, 2, 0) - 1)) - 1];
        c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_ip), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_xj), 1, 6, 2, 0)
               - 1)) - 1] = c6_temp;
      }
    }
  }

  for (c6_i235 = 0; c6_i235 < 36; c6_i235++) {
    c6_c_V[c6_i235] = c6_b_V[c6_i235];
  }

  c6_c_eml_xtrsm(chartInstance, c6_c_V, c6_F);
  for (c6_i236 = 0; c6_i236 < 36; c6_i236++) {
    c6_d_V[c6_i236] = c6_b_V[c6_i236];
  }

  c6_d_eml_xtrsm(chartInstance, c6_d_V, c6_F);
  for (c6_i_k = 0; c6_i_k < 6; c6_i_k++) {
    c6_b_k = 1.0 + (real_T)c6_i_k;
    c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_k),
           1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] = c6_F
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_k),
         1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c6_b_k), 1, 6, 2, 0) - 1)) - 1] + 1.0;
  }
}

static void c6_b_eml_scalar_eg(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_threshold(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_realmin(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_eps(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_eml_matlab_zgetrf(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  real_T c6_A[36], real_T c6_b_A[36], int32_T c6_ipiv[6], int32_T *c6_info)
{
  int32_T c6_i237;
  for (c6_i237 = 0; c6_i237 < 36; c6_i237++) {
    c6_b_A[c6_i237] = c6_A[c6_i237];
  }

  c6_b_eml_matlab_zgetrf(chartInstance, c6_b_A, c6_ipiv, c6_info);
}

static int32_T c6_eml_ixamax(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  int32_T c6_b_n, real_T c6_x[36], int32_T c6_ix0)
{
  int32_T c6_idxmax;
  int32_T c6_c_n;
  int32_T c6_b_ix0;
  int32_T c6_d_n;
  int32_T c6_c_ix0;
  int32_T c6_ix;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_y;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_b_y;
  real_T c6_smax;
  int32_T c6_e_n;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_a;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_c_y;
  real_T c6_j_x;
  real_T c6_k_x;
  real_T c6_d_y;
  real_T c6_s;
  c6_c_n = c6_b_n;
  c6_b_ix0 = c6_ix0;
  c6_d_n = c6_c_n;
  c6_c_ix0 = c6_b_ix0;
  if (c6_d_n < 1) {
    c6_idxmax = 0;
  } else {
    c6_idxmax = 1;
    if (c6_d_n > 1) {
      c6_ix = c6_c_ix0;
      c6_b_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_ix), 1, 36, 1, 0) - 1];
      c6_c_x = c6_b_x;
      c6_d_x = c6_c_x;
      c6_y = muDoubleScalarAbs(c6_d_x);
      c6_e_x = 0.0;
      c6_f_x = c6_e_x;
      c6_b_y = muDoubleScalarAbs(c6_f_x);
      c6_smax = c6_y + c6_b_y;
      c6_e_n = c6_d_n;
      c6_b = c6_e_n;
      c6_b_b = c6_b;
      if (2 > c6_b_b) {
        c6_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_overflow = (c6_b_b > 2147483646);
      }

      if (c6_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_overflow);
      }

      for (c6_k = 2; c6_k <= c6_e_n; c6_k++) {
        c6_b_k = c6_k;
        c6_a = c6_ix + 1;
        c6_ix = c6_a;
        c6_g_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_ix), 1, 36, 1, 0) - 1];
        c6_h_x = c6_g_x;
        c6_i_x = c6_h_x;
        c6_c_y = muDoubleScalarAbs(c6_i_x);
        c6_j_x = 0.0;
        c6_k_x = c6_j_x;
        c6_d_y = muDoubleScalarAbs(c6_k_x);
        c6_s = c6_c_y + c6_d_y;
        if (c6_s > c6_smax) {
          c6_idxmax = c6_b_k;
          c6_smax = c6_s;
        }
      }
    }
  }

  return c6_idxmax;
}

static void c6_check_forloop_overflow_error(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, boolean_T c6_overflow)
{
  const mxArray *c6_y = NULL;
  static char_T c6_u[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c6_b_y = NULL;
  static char_T c6_b_u[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  if (!c6_overflow) {
  } else {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c6_y, 14, c6_b_y));
  }
}

static void c6_b_eml_switch_helper(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_eml_xgeru(SFc6_EKF_SIL_02InstanceStruct *chartInstance, int32_T
  c6_m, int32_T c6_b_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0, real_T
  c6_A[36], int32_T c6_ia0, real_T c6_b_A[36])
{
  int32_T c6_i238;
  for (c6_i238 = 0; c6_i238 < 36; c6_i238++) {
    c6_b_A[c6_i238] = c6_A[c6_i238];
  }

  c6_b_eml_xgeru(chartInstance, c6_m, c6_b_n, c6_alpha1, c6_ix0, c6_iy0, c6_b_A,
                 c6_ia0);
}

static void c6_eml_warning(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  const mxArray *c6_y = NULL;
  static char_T c6_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c6_y));
}

static void c6_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36], real_T c6_b_B[36])
{
  int32_T c6_i239;
  int32_T c6_i240;
  real_T c6_b_A[36];
  for (c6_i239 = 0; c6_i239 < 36; c6_i239++) {
    c6_b_B[c6_i239] = c6_B[c6_i239];
  }

  for (c6_i240 = 0; c6_i240 < 36; c6_i240++) {
    c6_b_A[c6_i240] = c6_A[c6_i240];
  }

  c6_c_eml_xtrsm(chartInstance, c6_b_A, c6_b_B);
}

static void c6_below_threshold(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  c6_c_eml_switch_helper(chartInstance);
}

static void c6_c_eml_switch_helper(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_scalarEg(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_b_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36], real_T c6_b_B[36])
{
  int32_T c6_i241;
  int32_T c6_i242;
  real_T c6_b_A[36];
  for (c6_i241 = 0; c6_i241 < 36; c6_i241++) {
    c6_b_B[c6_i241] = c6_B[c6_i241];
  }

  for (c6_i242 = 0; c6_i242 < 36; c6_i242++) {
    c6_b_A[c6_i242] = c6_A[c6_i242];
  }

  c6_d_eml_xtrsm(chartInstance, c6_b_A, c6_b_B);
}

static real_T c6_rdivide(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_x, real_T c6_y)
{
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_c_y;
  (void)chartInstance;
  c6_b_x = c6_x;
  c6_b_y = c6_y;
  c6_c_x = c6_b_x;
  c6_c_y = c6_b_y;
  return c6_c_x / c6_c_y;
}

static void c6_log2(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_x,
                    real_T *c6_f, real_T *c6_e)
{
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  boolean_T c6_b;
  boolean_T c6_b0;
  real_T c6_e_x;
  boolean_T c6_b_b;
  boolean_T c6_b1;
  boolean_T c6_c_b;
  int32_T c6_eint;
  real_T c6_fdbl;
  int32_T c6_b_eint;
  real_T c6_b_fdbl;
  int32_T c6_c_eint;
  real_T c6_d1;
  real_T c6_d2;
  (void)chartInstance;
  c6_b_x = c6_x;
  c6_c_x = c6_b_x;
  c6_d_x = c6_c_x;
  c6_b = muDoubleScalarIsInf(c6_d_x);
  c6_b0 = !c6_b;
  c6_e_x = c6_c_x;
  c6_b_b = muDoubleScalarIsNaN(c6_e_x);
  c6_b1 = !c6_b_b;
  c6_c_b = (c6_b0 && c6_b1);
  if (c6_c_b) {
    c6_fdbl = frexp(c6_b_x, &c6_eint);
    c6_b_eint = c6_eint;
    c6_b_fdbl = c6_fdbl;
    c6_c_eint = c6_b_eint;
    c6_d1 = c6_b_fdbl;
    c6_d2 = (real_T)c6_c_eint;
  } else {
    c6_d1 = c6_b_x;
    c6_d2 = 0.0;
  }

  *c6_f = c6_d1;
  *c6_e = c6_d2;
}

static real_T c6_pow2(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_a)
{
  real_T c6_b_a;
  real_T c6_b;
  real_T c6_b_b;
  real_T c6_bk;
  real_T c6_c_b;
  real_T c6_br;
  c6_b_a = c6_a;
  c6_b = c6_b_a;
  c6_b_b = c6_b;
  c6_eml_scalar_eg(chartInstance);
  c6_dimagree(chartInstance);
  c6_bk = c6_b_b;
  c6_c_b = c6_bk;
  c6_eml_scalar_eg(chartInstance);
  c6_br = c6_c_b;
  return muDoubleScalarPower(2.0, c6_br);
}

static void c6_b_expm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T c6_A
                      [9], real_T c6_F[9])
{
  real_T c6_normA;
  int32_T c6_j;
  real_T c6_b_j;
  real_T c6_s;
  int32_T c6_i;
  real_T c6_b_i;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_y;
  real_T c6_c_x;
  boolean_T c6_b;
  int32_T c6_c_i;
  real_T c6_d_i;
  static real_T c6_theta[5] = { 0.01495585217958292, 0.253939833006323,
    0.95041789961629319, 2.097847961257068, 5.3719203511481517 };

  int32_T c6_i243;
  real_T c6_b_A[9];
  static real_T c6_dv15[5] = { 3.0, 5.0, 7.0, 9.0, 13.0 };

  real_T c6_b_s;
  real_T c6_t;
  real_T c6_b_t;
  real_T c6_c_s;
  real_T c6_b_y;
  real_T c6_c_y;
  int32_T c6_i244;
  int32_T c6_i245;
  real_T c6_c_A[9];
  real_T c6_d_s;
  int32_T c6_i246;
  int32_T c6_c_j;
  int32_T c6_i247;
  real_T c6_d_A[9];
  int32_T c6_i248;
  int32_T c6_i249;
  int32_T c6_i250;
  int32_T c6_i251;
  int32_T c6_i252;
  boolean_T exitg1;
  boolean_T exitg2;
  c6_normA = 0.0;
  c6_j = 0;
  exitg2 = false;
  while ((exitg2 == false) && (c6_j < 3)) {
    c6_b_j = 1.0 + (real_T)c6_j;
    c6_s = 0.0;
    for (c6_i = 0; c6_i < 3; c6_i++) {
      c6_b_i = 1.0 + (real_T)c6_i;
      c6_x = c6_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", c6_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c6_b_j), 1, 3, 2, 0) - 1)) - 1];
      c6_b_x = c6_x;
      c6_y = muDoubleScalarAbs(c6_b_x);
      c6_s += c6_y;
    }

    c6_c_x = c6_s;
    c6_b = muDoubleScalarIsNaN(c6_c_x);
    if (c6_b) {
      c6_normA = rtNaN;
      exitg2 = true;
    } else {
      if (c6_s > c6_normA) {
        c6_normA = c6_s;
      }

      c6_j++;
    }
  }

  if (c6_normA <= 5.3719203511481517) {
    c6_c_i = 0;
    exitg1 = false;
    while ((exitg1 == false) && (c6_c_i < 5)) {
      c6_d_i = 1.0 + (real_T)c6_c_i;
      if (c6_normA <= c6_theta[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c6_d_i), 1, 5, 1, 0) - 1]) {
        for (c6_i243 = 0; c6_i243 < 9; c6_i243++) {
          c6_b_A[c6_i243] = c6_A[c6_i243];
        }

        c6_b_PadeApproximantOfDegree(chartInstance, c6_b_A,
          c6_dv15[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c6_d_i), 1, 5, 1, 0) - 1], c6_F);
        exitg1 = true;
      } else {
        c6_c_i++;
      }
    }
  } else {
    c6_log2(chartInstance, c6_normA / 5.3719203511481517, &c6_t, &c6_b_s);
    c6_b_t = c6_t;
    c6_c_s = c6_b_s;
    if (c6_b_t == 0.5) {
      c6_c_s--;
    }

    c6_b_y = c6_pow2(chartInstance, c6_c_s);
    c6_c_y = c6_b_y;
    for (c6_i244 = 0; c6_i244 < 9; c6_i244++) {
      c6_A[c6_i244] /= c6_c_y;
    }

    for (c6_i245 = 0; c6_i245 < 9; c6_i245++) {
      c6_c_A[c6_i245] = c6_A[c6_i245];
    }

    c6_b_PadeApproximantOfDegree(chartInstance, c6_c_A, 13.0, c6_F);
    c6_d_s = c6_c_s;
    c6_i246 = (int32_T)c6_d_s;
    _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c6_d_s, mxDOUBLE_CLASS, c6_i246);
    for (c6_c_j = 0; c6_c_j < c6_i246; c6_c_j++) {
      c6_c_eml_scalar_eg(chartInstance);
      c6_c_eml_scalar_eg(chartInstance);
      c6_threshold(chartInstance);
      for (c6_i247 = 0; c6_i247 < 9; c6_i247++) {
        c6_d_A[c6_i247] = c6_F[c6_i247];
      }

      for (c6_i248 = 0; c6_i248 < 3; c6_i248++) {
        c6_i249 = 0;
        for (c6_i250 = 0; c6_i250 < 3; c6_i250++) {
          c6_F[c6_i249 + c6_i248] = 0.0;
          c6_i251 = 0;
          for (c6_i252 = 0; c6_i252 < 3; c6_i252++) {
            c6_F[c6_i249 + c6_i248] += c6_d_A[c6_i251 + c6_i248] *
              c6_d_A[c6_i252 + c6_i249];
            c6_i251 += 3;
          }

          c6_i249 += 3;
        }
      }
    }
  }
}

static void c6_b_PadeApproximantOfDegree(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, real_T c6_A[9], real_T c6_m, real_T c6_F[9])
{
  int32_T c6_i253;
  int32_T c6_i254;
  int32_T c6_i255;
  real_T c6_A2[9];
  int32_T c6_i256;
  int32_T c6_i257;
  int32_T c6_i258;
  real_T c6_U[9];
  int32_T c6_k;
  real_T c6_b_k;
  int32_T c6_i259;
  real_T c6_y[9];
  int32_T c6_i260;
  int32_T c6_i261;
  int32_T c6_i262;
  int32_T c6_i263;
  int32_T c6_i264;
  int32_T c6_i265;
  real_T c6_b_V[9];
  real_T c6_d;
  int32_T c6_i266;
  int32_T c6_i267;
  int32_T c6_i268;
  real_T c6_A3[9];
  int32_T c6_i269;
  int32_T c6_i270;
  int32_T c6_i271;
  int32_T c6_i272;
  int32_T c6_c_k;
  int32_T c6_i273;
  int32_T c6_i274;
  int32_T c6_i275;
  int32_T c6_i276;
  int32_T c6_i277;
  int32_T c6_i278;
  int32_T c6_i279;
  int32_T c6_i280;
  int32_T c6_i281;
  int32_T c6_i282;
  int32_T c6_i283;
  int32_T c6_i284;
  real_T c6_A4[9];
  int32_T c6_i285;
  int32_T c6_i286;
  int32_T c6_i287;
  int32_T c6_i288;
  real_T c6_b_y[9];
  int32_T c6_i289;
  int32_T c6_d_k;
  int32_T c6_i290;
  int32_T c6_i291;
  int32_T c6_i292;
  int32_T c6_i293;
  int32_T c6_i294;
  int32_T c6_i295;
  int32_T c6_i296;
  int32_T c6_i297;
  int32_T c6_i298;
  int32_T c6_i299;
  int32_T c6_i300;
  int32_T c6_i301;
  int32_T c6_i302;
  int32_T c6_i303;
  int32_T c6_i304;
  int32_T c6_i305;
  int32_T c6_i306;
  int32_T c6_i307;
  real_T c6_c_y[9];
  int32_T c6_i308;
  int32_T c6_e_k;
  int32_T c6_i309;
  int32_T c6_i310;
  int32_T c6_i311;
  int32_T c6_i312;
  int32_T c6_i313;
  int32_T c6_i314;
  int32_T c6_i315;
  int32_T c6_i316;
  int32_T c6_i317;
  int32_T c6_i318;
  int32_T c6_i319;
  int32_T c6_i320;
  int32_T c6_i321;
  int32_T c6_i322;
  int32_T c6_i323;
  int32_T c6_f_k;
  int32_T c6_i324;
  int32_T c6_i325;
  int32_T c6_i326;
  int32_T c6_i327;
  int32_T c6_i328;
  int32_T c6_i329;
  int32_T c6_i330;
  int32_T c6_i331;
  int32_T c6_i332;
  int32_T c6_i333;
  int32_T c6_i334;
  int32_T c6_i335;
  int32_T c6_i336;
  int32_T c6_i337;
  int32_T c6_i338;
  int32_T c6_i339;
  int32_T c6_i340;
  int32_T c6_i341;
  int32_T c6_i342;
  int32_T c6_i343;
  int32_T c6_i344;
  int32_T c6_i345;
  int32_T c6_i346;
  int32_T c6_i347;
  int32_T c6_i348;
  int32_T c6_i349;
  int32_T c6_i350;
  int32_T c6_g_k;
  int32_T c6_h_k;
  int32_T c6_i351;
  real_T c6_c_V[9];
  int32_T c6_i352;
  real_T c6_b_U[9];
  int32_T c6_i_k;
  c6_c_eml_scalar_eg(chartInstance);
  c6_c_eml_scalar_eg(chartInstance);
  c6_threshold(chartInstance);
  for (c6_i253 = 0; c6_i253 < 3; c6_i253++) {
    c6_i254 = 0;
    for (c6_i255 = 0; c6_i255 < 3; c6_i255++) {
      c6_A2[c6_i254 + c6_i253] = 0.0;
      c6_i256 = 0;
      for (c6_i257 = 0; c6_i257 < 3; c6_i257++) {
        c6_A2[c6_i254 + c6_i253] += c6_A[c6_i256 + c6_i253] * c6_A[c6_i257 +
          c6_i254];
        c6_i256 += 3;
      }

      c6_i254 += 3;
    }
  }

  if (c6_m == 3.0) {
    for (c6_i258 = 0; c6_i258 < 9; c6_i258++) {
      c6_U[c6_i258] = c6_A2[c6_i258];
    }

    for (c6_k = 0; c6_k < 3; c6_k++) {
      c6_b_k = 1.0 + (real_T)c6_k;
      c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] =
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1]
        + 60.0;
    }

    c6_c_eml_scalar_eg(chartInstance);
    c6_c_eml_scalar_eg(chartInstance);
    c6_threshold(chartInstance);
    for (c6_i259 = 0; c6_i259 < 9; c6_i259++) {
      c6_y[c6_i259] = c6_U[c6_i259];
    }

    for (c6_i260 = 0; c6_i260 < 3; c6_i260++) {
      c6_i261 = 0;
      for (c6_i262 = 0; c6_i262 < 3; c6_i262++) {
        c6_U[c6_i261 + c6_i260] = 0.0;
        c6_i263 = 0;
        for (c6_i264 = 0; c6_i264 < 3; c6_i264++) {
          c6_U[c6_i261 + c6_i260] += c6_A[c6_i263 + c6_i260] * c6_y[c6_i264 +
            c6_i261];
          c6_i263 += 3;
        }

        c6_i261 += 3;
      }
    }

    for (c6_i265 = 0; c6_i265 < 9; c6_i265++) {
      c6_b_V[c6_i265] = 12.0 * c6_A2[c6_i265];
    }

    c6_d = 120.0;
  } else {
    c6_c_eml_scalar_eg(chartInstance);
    c6_c_eml_scalar_eg(chartInstance);
    c6_threshold(chartInstance);
    for (c6_i266 = 0; c6_i266 < 3; c6_i266++) {
      c6_i267 = 0;
      for (c6_i268 = 0; c6_i268 < 3; c6_i268++) {
        c6_A3[c6_i267 + c6_i266] = 0.0;
        c6_i269 = 0;
        for (c6_i270 = 0; c6_i270 < 3; c6_i270++) {
          c6_A3[c6_i267 + c6_i266] += c6_A2[c6_i269 + c6_i266] * c6_A2[c6_i270 +
            c6_i267];
          c6_i269 += 3;
        }

        c6_i267 += 3;
      }
    }

    if (c6_m == 5.0) {
      for (c6_i271 = 0; c6_i271 < 9; c6_i271++) {
        c6_U[c6_i271] = 420.0 * c6_A2[c6_i271];
      }

      for (c6_i272 = 0; c6_i272 < 9; c6_i272++) {
        c6_U[c6_i272] += c6_A3[c6_i272];
      }

      for (c6_c_k = 0; c6_c_k < 3; c6_c_k++) {
        c6_b_k = 1.0 + (real_T)c6_c_k;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] =
          c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1]
          + 15120.0;
      }

      c6_c_eml_scalar_eg(chartInstance);
      c6_c_eml_scalar_eg(chartInstance);
      c6_threshold(chartInstance);
      for (c6_i273 = 0; c6_i273 < 9; c6_i273++) {
        c6_y[c6_i273] = c6_U[c6_i273];
      }

      for (c6_i274 = 0; c6_i274 < 3; c6_i274++) {
        c6_i275 = 0;
        for (c6_i276 = 0; c6_i276 < 3; c6_i276++) {
          c6_U[c6_i275 + c6_i274] = 0.0;
          c6_i277 = 0;
          for (c6_i278 = 0; c6_i278 < 3; c6_i278++) {
            c6_U[c6_i275 + c6_i274] += c6_A[c6_i277 + c6_i274] * c6_y[c6_i278 +
              c6_i275];
            c6_i277 += 3;
          }

          c6_i275 += 3;
        }
      }

      for (c6_i279 = 0; c6_i279 < 9; c6_i279++) {
        c6_A3[c6_i279] *= 30.0;
      }

      for (c6_i280 = 0; c6_i280 < 9; c6_i280++) {
        c6_A2[c6_i280] *= 3360.0;
      }

      for (c6_i281 = 0; c6_i281 < 9; c6_i281++) {
        c6_b_V[c6_i281] = c6_A3[c6_i281] + c6_A2[c6_i281];
      }

      c6_d = 30240.0;
    } else {
      c6_c_eml_scalar_eg(chartInstance);
      c6_c_eml_scalar_eg(chartInstance);
      c6_threshold(chartInstance);
      for (c6_i282 = 0; c6_i282 < 3; c6_i282++) {
        c6_i283 = 0;
        for (c6_i284 = 0; c6_i284 < 3; c6_i284++) {
          c6_A4[c6_i283 + c6_i282] = 0.0;
          c6_i285 = 0;
          for (c6_i286 = 0; c6_i286 < 3; c6_i286++) {
            c6_A4[c6_i283 + c6_i282] += c6_A3[c6_i285 + c6_i282] * c6_A2[c6_i286
              + c6_i283];
            c6_i285 += 3;
          }

          c6_i283 += 3;
        }
      }

      if (c6_m == 7.0) {
        for (c6_i287 = 0; c6_i287 < 9; c6_i287++) {
          c6_U[c6_i287] = 1512.0 * c6_A3[c6_i287];
        }

        for (c6_i288 = 0; c6_i288 < 9; c6_i288++) {
          c6_b_y[c6_i288] = 277200.0 * c6_A2[c6_i288];
        }

        for (c6_i289 = 0; c6_i289 < 9; c6_i289++) {
          c6_U[c6_i289] = (c6_A4[c6_i289] + c6_U[c6_i289]) + c6_b_y[c6_i289];
        }

        for (c6_d_k = 0; c6_d_k < 3; c6_d_k++) {
          c6_b_k = 1.0 + (real_T)c6_d_k;
          c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1]
            = c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", c6_b_k), 1, 3, 1, 0) + 3 *
                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] + 8.64864E+6;
        }

        c6_c_eml_scalar_eg(chartInstance);
        c6_c_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i290 = 0; c6_i290 < 9; c6_i290++) {
          c6_y[c6_i290] = c6_U[c6_i290];
        }

        for (c6_i291 = 0; c6_i291 < 3; c6_i291++) {
          c6_i292 = 0;
          for (c6_i293 = 0; c6_i293 < 3; c6_i293++) {
            c6_U[c6_i292 + c6_i291] = 0.0;
            c6_i294 = 0;
            for (c6_i295 = 0; c6_i295 < 3; c6_i295++) {
              c6_U[c6_i292 + c6_i291] += c6_A[c6_i294 + c6_i291] * c6_y[c6_i295
                + c6_i292];
              c6_i294 += 3;
            }

            c6_i292 += 3;
          }
        }

        for (c6_i296 = 0; c6_i296 < 9; c6_i296++) {
          c6_A4[c6_i296] *= 56.0;
        }

        for (c6_i297 = 0; c6_i297 < 9; c6_i297++) {
          c6_A3[c6_i297] *= 25200.0;
        }

        for (c6_i298 = 0; c6_i298 < 9; c6_i298++) {
          c6_A2[c6_i298] *= 1.99584E+6;
        }

        for (c6_i299 = 0; c6_i299 < 9; c6_i299++) {
          c6_b_V[c6_i299] = (c6_A4[c6_i299] + c6_A3[c6_i299]) + c6_A2[c6_i299];
        }

        c6_d = 1.729728E+7;
      } else if (c6_m == 9.0) {
        c6_c_eml_scalar_eg(chartInstance);
        c6_c_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i300 = 0; c6_i300 < 3; c6_i300++) {
          c6_i301 = 0;
          for (c6_i302 = 0; c6_i302 < 3; c6_i302++) {
            c6_b_V[c6_i301 + c6_i300] = 0.0;
            c6_i303 = 0;
            for (c6_i304 = 0; c6_i304 < 3; c6_i304++) {
              c6_b_V[c6_i301 + c6_i300] += c6_A4[c6_i303 + c6_i300] *
                c6_A2[c6_i304 + c6_i301];
              c6_i303 += 3;
            }

            c6_i301 += 3;
          }
        }

        for (c6_i305 = 0; c6_i305 < 9; c6_i305++) {
          c6_U[c6_i305] = 3960.0 * c6_A4[c6_i305];
        }

        for (c6_i306 = 0; c6_i306 < 9; c6_i306++) {
          c6_b_y[c6_i306] = 2.16216E+6 * c6_A3[c6_i306];
        }

        for (c6_i307 = 0; c6_i307 < 9; c6_i307++) {
          c6_c_y[c6_i307] = 3.027024E+8 * c6_A2[c6_i307];
        }

        for (c6_i308 = 0; c6_i308 < 9; c6_i308++) {
          c6_U[c6_i308] = ((c6_b_V[c6_i308] + c6_U[c6_i308]) + c6_b_y[c6_i308])
            + c6_c_y[c6_i308];
        }

        for (c6_e_k = 0; c6_e_k < 3; c6_e_k++) {
          c6_b_k = 1.0 + (real_T)c6_e_k;
          c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1]
            = c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", c6_b_k), 1, 3, 1, 0) + 3 *
                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] + 8.8216128E+9;
        }

        c6_c_eml_scalar_eg(chartInstance);
        c6_c_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i309 = 0; c6_i309 < 9; c6_i309++) {
          c6_y[c6_i309] = c6_U[c6_i309];
        }

        for (c6_i310 = 0; c6_i310 < 3; c6_i310++) {
          c6_i311 = 0;
          for (c6_i312 = 0; c6_i312 < 3; c6_i312++) {
            c6_U[c6_i311 + c6_i310] = 0.0;
            c6_i313 = 0;
            for (c6_i314 = 0; c6_i314 < 3; c6_i314++) {
              c6_U[c6_i311 + c6_i310] += c6_A[c6_i313 + c6_i310] * c6_y[c6_i314
                + c6_i311];
              c6_i313 += 3;
            }

            c6_i311 += 3;
          }
        }

        for (c6_i315 = 0; c6_i315 < 9; c6_i315++) {
          c6_b_V[c6_i315] *= 90.0;
        }

        for (c6_i316 = 0; c6_i316 < 9; c6_i316++) {
          c6_A4[c6_i316] *= 110880.0;
        }

        for (c6_i317 = 0; c6_i317 < 9; c6_i317++) {
          c6_A3[c6_i317] *= 3.027024E+7;
        }

        for (c6_i318 = 0; c6_i318 < 9; c6_i318++) {
          c6_A2[c6_i318] *= 2.0756736E+9;
        }

        for (c6_i319 = 0; c6_i319 < 9; c6_i319++) {
          c6_b_V[c6_i319] = ((c6_b_V[c6_i319] + c6_A4[c6_i319]) + c6_A3[c6_i319])
            + c6_A2[c6_i319];
        }

        c6_d = 1.76432256E+10;
      } else {
        for (c6_i320 = 0; c6_i320 < 9; c6_i320++) {
          c6_U[c6_i320] = 3.352212864E+10 * c6_A4[c6_i320];
        }

        for (c6_i321 = 0; c6_i321 < 9; c6_i321++) {
          c6_b_y[c6_i321] = 1.05594705216E+13 * c6_A3[c6_i321];
        }

        for (c6_i322 = 0; c6_i322 < 9; c6_i322++) {
          c6_c_y[c6_i322] = 1.1873537964288E+15 * c6_A2[c6_i322];
        }

        for (c6_i323 = 0; c6_i323 < 9; c6_i323++) {
          c6_U[c6_i323] = (c6_U[c6_i323] + c6_b_y[c6_i323]) + c6_c_y[c6_i323];
        }

        for (c6_f_k = 0; c6_f_k < 3; c6_f_k++) {
          c6_b_k = 1.0 + (real_T)c6_f_k;
          c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1]
            = c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", c6_b_k), 1, 3, 1, 0) + 3 *
                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] + 3.238237626624E+16;
        }

        for (c6_i324 = 0; c6_i324 < 9; c6_i324++) {
          c6_b_y[c6_i324] = 16380.0 * c6_A3[c6_i324];
        }

        for (c6_i325 = 0; c6_i325 < 9; c6_i325++) {
          c6_c_y[c6_i325] = 4.08408E+7 * c6_A2[c6_i325];
        }

        for (c6_i326 = 0; c6_i326 < 9; c6_i326++) {
          c6_b_y[c6_i326] = (c6_A4[c6_i326] + c6_b_y[c6_i326]) + c6_c_y[c6_i326];
        }

        c6_c_eml_scalar_eg(chartInstance);
        c6_c_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i327 = 0; c6_i327 < 3; c6_i327++) {
          c6_i328 = 0;
          for (c6_i329 = 0; c6_i329 < 3; c6_i329++) {
            c6_c_y[c6_i328 + c6_i327] = 0.0;
            c6_i330 = 0;
            for (c6_i331 = 0; c6_i331 < 3; c6_i331++) {
              c6_c_y[c6_i328 + c6_i327] += c6_A4[c6_i330 + c6_i327] *
                c6_b_y[c6_i331 + c6_i328];
              c6_i330 += 3;
            }

            c6_i328 += 3;
          }
        }

        for (c6_i332 = 0; c6_i332 < 9; c6_i332++) {
          c6_c_y[c6_i332] += c6_U[c6_i332];
        }

        c6_c_eml_scalar_eg(chartInstance);
        c6_c_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i333 = 0; c6_i333 < 3; c6_i333++) {
          c6_i334 = 0;
          for (c6_i335 = 0; c6_i335 < 3; c6_i335++) {
            c6_U[c6_i334 + c6_i333] = 0.0;
            c6_i336 = 0;
            for (c6_i337 = 0; c6_i337 < 3; c6_i337++) {
              c6_U[c6_i334 + c6_i333] += c6_A[c6_i336 + c6_i333] *
                c6_c_y[c6_i337 + c6_i334];
              c6_i336 += 3;
            }

            c6_i334 += 3;
          }
        }

        for (c6_i338 = 0; c6_i338 < 9; c6_i338++) {
          c6_b_y[c6_i338] = 182.0 * c6_A4[c6_i338];
        }

        for (c6_i339 = 0; c6_i339 < 9; c6_i339++) {
          c6_c_y[c6_i339] = 960960.0 * c6_A3[c6_i339];
        }

        for (c6_i340 = 0; c6_i340 < 9; c6_i340++) {
          c6_y[c6_i340] = 1.32324192E+9 * c6_A2[c6_i340];
        }

        for (c6_i341 = 0; c6_i341 < 9; c6_i341++) {
          c6_b_y[c6_i341] = (c6_b_y[c6_i341] + c6_c_y[c6_i341]) + c6_y[c6_i341];
        }

        c6_c_eml_scalar_eg(chartInstance);
        c6_c_eml_scalar_eg(chartInstance);
        c6_threshold(chartInstance);
        for (c6_i342 = 0; c6_i342 < 3; c6_i342++) {
          c6_i343 = 0;
          for (c6_i344 = 0; c6_i344 < 3; c6_i344++) {
            c6_b_V[c6_i343 + c6_i342] = 0.0;
            c6_i345 = 0;
            for (c6_i346 = 0; c6_i346 < 3; c6_i346++) {
              c6_b_V[c6_i343 + c6_i342] += c6_A4[c6_i345 + c6_i342] *
                c6_b_y[c6_i346 + c6_i343];
              c6_i345 += 3;
            }

            c6_i343 += 3;
          }
        }

        for (c6_i347 = 0; c6_i347 < 9; c6_i347++) {
          c6_A4[c6_i347] *= 6.704425728E+11;
        }

        for (c6_i348 = 0; c6_i348 < 9; c6_i348++) {
          c6_A3[c6_i348] *= 1.29060195264E+14;
        }

        for (c6_i349 = 0; c6_i349 < 9; c6_i349++) {
          c6_A2[c6_i349] *= 7.7717703038976E+15;
        }

        for (c6_i350 = 0; c6_i350 < 9; c6_i350++) {
          c6_b_V[c6_i350] = ((c6_b_V[c6_i350] + c6_A4[c6_i350]) + c6_A3[c6_i350])
            + c6_A2[c6_i350];
        }

        c6_d = 6.476475253248E+16;
      }
    }
  }

  for (c6_g_k = 0; c6_g_k < 3; c6_g_k++) {
    c6_b_k = 1.0 + (real_T)c6_g_k;
    c6_b_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] =
      c6_b_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c6_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1]
      + c6_d;
  }

  for (c6_h_k = 0; c6_h_k < 9; c6_h_k++) {
    c6_b_k = 1.0 + (real_T)c6_h_k;
    c6_b_V[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_b_k), 1, 9, 1, 0) - 1] = c6_b_V[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", c6_b_k), 1, 9, 1, 0) - 1] -
      c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_b_k), 1, 9, 1, 0) - 1];
    c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_k),
      1, 9, 1, 0) - 1] = 2.0 * c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c6_b_k), 1, 9, 1, 0) - 1];
  }

  for (c6_i351 = 0; c6_i351 < 9; c6_i351++) {
    c6_c_V[c6_i351] = c6_b_V[c6_i351];
  }

  for (c6_i352 = 0; c6_i352 < 9; c6_i352++) {
    c6_b_U[c6_i352] = c6_U[c6_i352];
  }

  c6_mldivide(chartInstance, c6_c_V, c6_b_U, c6_F);
  for (c6_i_k = 0; c6_i_k < 3; c6_i_k++) {
    c6_b_k = 1.0 + (real_T)c6_i_k;
    c6_F[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_k),
           1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] = c6_F
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_b_k),
         1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c6_b_k), 1, 3, 2, 0) - 1)) - 1] + 1.0;
  }
}

static void c6_c_eml_scalar_eg(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_mldivide(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[9], real_T c6_B[9], real_T c6_Y[9])
{
  int32_T c6_i353;
  real_T c6_b_A[9];
  int32_T c6_r1;
  int32_T c6_r2;
  int32_T c6_r3;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_y;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_b_y;
  real_T c6_maxval;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_c_y;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_d_y;
  real_T c6_a21;
  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_e_y;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_f_y;
  real_T c6_d;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_g_y;
  real_T c6_w_x;
  real_T c6_x_x;
  real_T c6_h_y;
  real_T c6_b_d;
  real_T c6_y_x;
  real_T c6_ab_x;
  real_T c6_bb_x;
  real_T c6_cb_x;
  real_T c6_i_y;
  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_j_y;
  real_T c6_c_d;
  int32_T c6_rtemp;
  int32_T c6_k;
  int32_T c6_b_k;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  for (c6_i353 = 0; c6_i353 < 9; c6_i353++) {
    c6_b_A[c6_i353] = c6_A[c6_i353];
  }

  c6_r1 = 1;
  c6_r2 = 2;
  c6_r3 = 3;
  c6_x = c6_b_A[0];
  c6_b_x = c6_x;
  c6_c_x = c6_b_x;
  c6_d_x = c6_c_x;
  c6_y = muDoubleScalarAbs(c6_d_x);
  c6_e_x = 0.0;
  c6_f_x = c6_e_x;
  c6_b_y = muDoubleScalarAbs(c6_f_x);
  c6_maxval = c6_y + c6_b_y;
  c6_g_x = c6_b_A[1];
  c6_h_x = c6_g_x;
  c6_i_x = c6_h_x;
  c6_j_x = c6_i_x;
  c6_c_y = muDoubleScalarAbs(c6_j_x);
  c6_k_x = 0.0;
  c6_l_x = c6_k_x;
  c6_d_y = muDoubleScalarAbs(c6_l_x);
  c6_a21 = c6_c_y + c6_d_y;
  if (c6_a21 > c6_maxval) {
    c6_maxval = c6_a21;
    c6_r1 = 2;
    c6_r2 = 1;
  }

  c6_m_x = c6_b_A[2];
  c6_n_x = c6_m_x;
  c6_o_x = c6_n_x;
  c6_p_x = c6_o_x;
  c6_e_y = muDoubleScalarAbs(c6_p_x);
  c6_q_x = 0.0;
  c6_r_x = c6_q_x;
  c6_f_y = muDoubleScalarAbs(c6_r_x);
  c6_d = c6_e_y + c6_f_y;
  if (c6_d > c6_maxval) {
    c6_r1 = 3;
    c6_r2 = 2;
    c6_r3 = 1;
  }

  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r2), 1, 3, 1, 0) - 1] = c6_rdivide(chartInstance,
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r2), 1, 3, 1, 0) - 1], c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r1), 1, 3, 1, 0) - 1]);
  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r3), 1, 3, 1, 0) - 1] = c6_rdivide(chartInstance,
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r3), 1, 3, 1, 0) - 1], c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r1), 1, 3, 1, 0) - 1]);
  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r2), 1, 3, 1, 0) + 2] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c6_r2), 1, 3, 1, 0) + 2] -
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r2), 1, 3, 1, 0) - 1] * c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r1), 1, 3, 1, 0) + 2];
  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r3), 1, 3, 1, 0) + 2] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c6_r3), 1, 3, 1, 0) + 2] -
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r3), 1, 3, 1, 0) - 1] * c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r1), 1, 3, 1, 0) + 2];
  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r2), 1, 3, 1, 0) + 5] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c6_r2), 1, 3, 1, 0) + 5] -
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r2), 1, 3, 1, 0) - 1] * c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r1), 1, 3, 1, 0) + 5];
  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r3), 1, 3, 1, 0) + 5] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c6_r3), 1, 3, 1, 0) + 5] -
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r3), 1, 3, 1, 0) - 1] * c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r1), 1, 3, 1, 0) + 5];
  c6_s_x = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r3), 1, 3, 1, 0) + 2];
  c6_t_x = c6_s_x;
  c6_u_x = c6_t_x;
  c6_v_x = c6_u_x;
  c6_g_y = muDoubleScalarAbs(c6_v_x);
  c6_w_x = 0.0;
  c6_x_x = c6_w_x;
  c6_h_y = muDoubleScalarAbs(c6_x_x);
  c6_b_d = c6_g_y + c6_h_y;
  c6_y_x = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r2), 1, 3, 1, 0) + 2];
  c6_ab_x = c6_y_x;
  c6_bb_x = c6_ab_x;
  c6_cb_x = c6_bb_x;
  c6_i_y = muDoubleScalarAbs(c6_cb_x);
  c6_db_x = 0.0;
  c6_eb_x = c6_db_x;
  c6_j_y = muDoubleScalarAbs(c6_eb_x);
  c6_c_d = c6_i_y + c6_j_y;
  if (c6_b_d > c6_c_d) {
    c6_rtemp = c6_r2;
    c6_r2 = c6_r3;
    c6_r3 = c6_rtemp;
  }

  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r3), 1, 3, 1, 0) + 2] = c6_rdivide(chartInstance,
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r3), 1, 3, 1, 0) + 2], c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r2), 1, 3, 1, 0) + 2]);
  c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c6_r3), 1, 3, 1, 0) + 5] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c6_r3), 1, 3, 1, 0) + 5] -
    c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c6_r3), 1, 3, 1, 0) + 2] * c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r2), 1, 3, 1, 0) + 5];
  guard1 = false;
  guard2 = false;
  if (c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_r1), 1, 3, 1, 0) - 1] == 0.0) {
    guard2 = true;
  } else if (c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c6_r2), 1, 3, 1, 0) + 2] == 0.0) {
    guard2 = true;
  } else {
    if (c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_r3), 1, 3, 1, 0) + 5] == 0.0) {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c6_eml_warning(chartInstance);
  }

  c6_c_eml_scalar_eg(chartInstance);
  c6_eml_switch_helper(chartInstance);
  for (c6_k = 1; c6_k < 4; c6_k++) {
    c6_b_k = c6_k;
    c6_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_B
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c6_r1), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)) - 1];
    c6_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r2), 1, 3, 1, 0) + 3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 3, 2, 0) - 1)) - 1] - c6_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)] *
      c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_r2), 1, 3, 1, 0) - 1];
    c6_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = (c6_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r3), 1, 3, 1, 0) + 3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 3, 2, 0) - 1)) - 1] - c6_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)] *
      c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_r3), 1, 3, 1, 0) - 1]) - c6_Y[1 + 3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
         c6_b_k), 1, 3, 2, 0) - 1)] * c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r3), 1, 3, 1, 0) + 2];
    c6_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_rdivide(chartInstance, c6_Y[2 + 3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 3, 2, 0) - 1)], c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r3), 1, 3, 1, 0) + 5]);
    c6_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_Y[3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
         c6_b_k), 1, 3, 2, 0) - 1)] - c6_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)] *
      c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_r1), 1, 3, 1, 0) + 5];
    c6_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_Y[1 + 3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
         c6_b_k), 1, 3, 2, 0) - 1)] - c6_Y[2 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)] *
      c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_r2), 1, 3, 1, 0) + 5];
    c6_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_rdivide(chartInstance, c6_Y[1 + 3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 3, 2, 0) - 1)], c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r2), 1, 3, 1, 0) + 2]);
    c6_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_Y[3 *
      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
         c6_b_k), 1, 3, 2, 0) - 1)] - c6_Y[1 + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 2, 0) - 1)] *
      c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_r1), 1, 3, 1, 0) + 2];
    c6_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_k), 1, 3, 2, 0) - 1)] = c6_rdivide(chartInstance,
      c6_Y[3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 3, 2, 0) - 1)], c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_r1), 1, 3, 1, 0) - 1]);
  }
}

static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_h_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i354;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i354, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i354;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_i_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_EKF_SIL_02, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_EKF_SIL_02), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_EKF_SIL_02);
  return c6_y;
}

static uint8_T c6_j_emlrt_marshallIn(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_eml_matlab_zgetrf(SFc6_EKF_SIL_02InstanceStruct *chartInstance,
  real_T c6_A[36], int32_T c6_ipiv[6], int32_T *c6_info)
{
  int32_T c6_i355;
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_a;
  int32_T c6_b_a;
  int32_T c6_jm1;
  int32_T c6_b;
  int32_T c6_b_b;
  int32_T c6_mmj;
  int32_T c6_c_a;
  int32_T c6_d_a;
  int32_T c6_c;
  int32_T c6_c_b;
  int32_T c6_d_b;
  int32_T c6_jj;
  int32_T c6_e_a;
  int32_T c6_f_a;
  int32_T c6_jp1j;
  int32_T c6_g_a;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i356;
  real_T c6_b_A[36];
  int32_T c6_i_a;
  int32_T c6_j_a;
  int32_T c6_jpiv_offset;
  int32_T c6_k_a;
  int32_T c6_e_b;
  int32_T c6_l_a;
  int32_T c6_f_b;
  int32_T c6_jpiv;
  int32_T c6_m_a;
  int32_T c6_g_b;
  int32_T c6_n_a;
  int32_T c6_h_b;
  int32_T c6_c_c;
  int32_T c6_i_b;
  int32_T c6_j_b;
  int32_T c6_jrow;
  int32_T c6_o_a;
  int32_T c6_k_b;
  int32_T c6_p_a;
  int32_T c6_l_b;
  int32_T c6_jprow;
  int32_T c6_ix0;
  int32_T c6_iy0;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_temp;
  int32_T c6_q_a;
  int32_T c6_r_a;
  int32_T c6_b_jp1j;
  int32_T c6_s_a;
  int32_T c6_t_a;
  int32_T c6_d_c;
  int32_T c6_u_a;
  int32_T c6_m_b;
  int32_T c6_v_a;
  int32_T c6_n_b;
  int32_T c6_i357;
  int32_T c6_w_a;
  int32_T c6_o_b;
  int32_T c6_x_a;
  int32_T c6_p_b;
  boolean_T c6_overflow;
  int32_T c6_i;
  int32_T c6_b_i;
  real_T c6_x;
  real_T c6_y;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_z;
  int32_T c6_q_b;
  int32_T c6_r_b;
  int32_T c6_e_c;
  int32_T c6_y_a;
  int32_T c6_ab_a;
  int32_T c6_f_c;
  int32_T c6_bb_a;
  int32_T c6_cb_a;
  int32_T c6_g_c;
  c6_realmin(chartInstance);
  c6_eps(chartInstance);
  for (c6_i355 = 0; c6_i355 < 6; c6_i355++) {
    c6_ipiv[c6_i355] = 1 + c6_i355;
  }

  *c6_info = 0;
  c6_eml_switch_helper(chartInstance);
  for (c6_j = 1; c6_j < 6; c6_j++) {
    c6_b_j = c6_j;
    c6_a = c6_b_j;
    c6_b_a = c6_a - 1;
    c6_jm1 = c6_b_a;
    c6_b = c6_b_j;
    c6_b_b = c6_b;
    c6_mmj = 6 - c6_b_b;
    c6_c_a = c6_jm1;
    c6_d_a = c6_c_a;
    c6_c = c6_d_a * 7;
    c6_c_b = c6_c;
    c6_d_b = c6_c_b + 1;
    c6_jj = c6_d_b;
    c6_e_a = c6_jj;
    c6_f_a = c6_e_a + 1;
    c6_jp1j = c6_f_a;
    c6_g_a = c6_mmj;
    c6_h_a = c6_g_a;
    c6_b_c = c6_h_a;
    for (c6_i356 = 0; c6_i356 < 36; c6_i356++) {
      c6_b_A[c6_i356] = c6_A[c6_i356];
    }

    c6_i_a = c6_eml_ixamax(chartInstance, c6_b_c + 1, c6_b_A, c6_jj);
    c6_j_a = c6_i_a - 1;
    c6_jpiv_offset = c6_j_a;
    c6_k_a = c6_jj;
    c6_e_b = c6_jpiv_offset;
    c6_l_a = c6_k_a;
    c6_f_b = c6_e_b;
    c6_jpiv = c6_l_a + c6_f_b;
    if (c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c6_jpiv_offset != 0) {
        c6_m_a = c6_b_j;
        c6_g_b = c6_jpiv_offset;
        c6_n_a = c6_m_a;
        c6_h_b = c6_g_b;
        c6_c_c = c6_n_a + c6_h_b;
        c6_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_j), 1, 6, 1, 0) - 1] = c6_c_c;
        c6_i_b = c6_jm1;
        c6_j_b = c6_i_b + 1;
        c6_jrow = c6_j_b;
        c6_o_a = c6_jrow;
        c6_k_b = c6_jpiv_offset;
        c6_p_a = c6_o_a;
        c6_l_b = c6_k_b;
        c6_jprow = c6_p_a + c6_l_b;
        c6_ix0 = c6_jrow;
        c6_iy0 = c6_jprow;
        c6_b_ix0 = c6_ix0;
        c6_b_iy0 = c6_iy0;
        c6_b_eml_switch_helper(chartInstance);
        c6_c_ix0 = c6_b_ix0;
        c6_c_iy0 = c6_b_iy0;
        c6_ix = c6_c_ix0;
        c6_iy = c6_c_iy0;
        c6_eml_switch_helper(chartInstance);
        for (c6_k = 1; c6_k < 7; c6_k++) {
          c6_temp = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_ix), 1, 36, 1, 0) - 1];
          c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_ix), 1, 36, 1, 0) - 1] = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK
            ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 36, 1, 0) -
            1];
          c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_iy), 1, 36, 1, 0) - 1] = c6_temp;
          c6_q_a = c6_ix + 6;
          c6_ix = c6_q_a;
          c6_r_a = c6_iy + 6;
          c6_iy = c6_r_a;
        }
      }

      c6_b_jp1j = c6_jp1j;
      c6_s_a = c6_mmj;
      c6_t_a = c6_s_a;
      c6_d_c = c6_t_a;
      c6_u_a = c6_jp1j;
      c6_m_b = c6_d_c - 1;
      c6_v_a = c6_u_a;
      c6_n_b = c6_m_b;
      c6_i357 = c6_v_a + c6_n_b;
      c6_w_a = c6_b_jp1j;
      c6_o_b = c6_i357;
      c6_x_a = c6_w_a;
      c6_p_b = c6_o_b;
      if (c6_x_a > c6_p_b) {
        c6_overflow = false;
      } else {
        c6_eml_switch_helper(chartInstance);
        c6_eml_switch_helper(chartInstance);
        c6_overflow = (c6_p_b > 2147483646);
      }

      if (c6_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_overflow);
      }

      for (c6_i = c6_b_jp1j; c6_i <= c6_i357; c6_i++) {
        c6_b_i = c6_i;
        c6_x = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_b_i), 1, 36, 1, 0) - 1];
        c6_y = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_jj), 1, 36, 1, 0) - 1];
        c6_b_x = c6_x;
        c6_b_y = c6_y;
        c6_z = c6_b_x / c6_b_y;
        c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_i), 1, 36, 1, 0) - 1] = c6_z;
      }
    } else {
      *c6_info = c6_b_j;
    }

    c6_q_b = c6_b_j;
    c6_r_b = c6_q_b;
    c6_e_c = 6 - c6_r_b;
    c6_y_a = c6_jj;
    c6_ab_a = c6_y_a;
    c6_f_c = c6_ab_a;
    c6_bb_a = c6_jj;
    c6_cb_a = c6_bb_a;
    c6_g_c = c6_cb_a;
    c6_b_eml_xgeru(chartInstance, c6_mmj, c6_e_c, -1.0, c6_jp1j, c6_f_c + 6,
                   c6_A, c6_g_c + 7);
  }

  if (*c6_info == 0) {
    if (!(c6_A[35] != 0.0)) {
      *c6_info = 6;
    }
  }
}

static void c6_b_eml_xgeru(SFc6_EKF_SIL_02InstanceStruct *chartInstance, int32_T
  c6_m, int32_T c6_b_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0, real_T
  c6_A[36], int32_T c6_ia0)
{
  int32_T c6_b_m;
  int32_T c6_c_n;
  real_T c6_b_alpha1;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_b_ia0;
  int32_T c6_c_m;
  int32_T c6_d_n;
  real_T c6_c_alpha1;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_c_ia0;
  int32_T c6_d_m;
  int32_T c6_e_n;
  real_T c6_d_alpha1;
  int32_T c6_d_ix0;
  int32_T c6_d_iy0;
  int32_T c6_d_ia0;
  int32_T c6_e_m;
  int32_T c6_f_n;
  real_T c6_e_alpha1;
  int32_T c6_e_ix0;
  int32_T c6_e_iy0;
  int32_T c6_e_ia0;
  int32_T c6_ixstart;
  int32_T c6_a;
  int32_T c6_jA;
  int32_T c6_jy;
  int32_T c6_g_n;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_j;
  real_T c6_yjy;
  real_T c6_temp;
  int32_T c6_ix;
  int32_T c6_c_b;
  int32_T c6_i358;
  int32_T c6_b_a;
  int32_T c6_d_b;
  int32_T c6_i359;
  int32_T c6_c_a;
  int32_T c6_e_b;
  int32_T c6_d_a;
  int32_T c6_f_b;
  boolean_T c6_b_overflow;
  int32_T c6_ijA;
  int32_T c6_b_ijA;
  int32_T c6_e_a;
  int32_T c6_f_a;
  int32_T c6_g_a;
  c6_b_m = c6_m;
  c6_c_n = c6_b_n;
  c6_b_alpha1 = c6_alpha1;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_b_ia0 = c6_ia0;
  c6_c_m = c6_b_m;
  c6_d_n = c6_c_n;
  c6_c_alpha1 = c6_b_alpha1;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_c_ia0 = c6_b_ia0;
  c6_d_m = c6_c_m;
  c6_e_n = c6_d_n;
  c6_d_alpha1 = c6_c_alpha1;
  c6_d_ix0 = c6_c_ix0;
  c6_d_iy0 = c6_c_iy0;
  c6_d_ia0 = c6_c_ia0;
  c6_e_m = c6_d_m;
  c6_f_n = c6_e_n;
  c6_e_alpha1 = c6_d_alpha1;
  c6_e_ix0 = c6_d_ix0;
  c6_e_iy0 = c6_d_iy0;
  c6_e_ia0 = c6_d_ia0;
  if (c6_e_alpha1 == 0.0) {
  } else {
    c6_ixstart = c6_e_ix0;
    c6_a = c6_e_ia0 - 1;
    c6_jA = c6_a;
    c6_jy = c6_e_iy0;
    c6_g_n = c6_f_n;
    c6_b = c6_g_n;
    c6_b_b = c6_b;
    if (1 > c6_b_b) {
      c6_overflow = false;
    } else {
      c6_eml_switch_helper(chartInstance);
      c6_eml_switch_helper(chartInstance);
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_j = 1; c6_j <= c6_g_n; c6_j++) {
      c6_yjy = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_jy), 1, 36, 1, 0) - 1];
      if (c6_yjy != 0.0) {
        c6_temp = c6_yjy * c6_e_alpha1;
        c6_ix = c6_ixstart;
        c6_c_b = c6_jA + 1;
        c6_i358 = c6_c_b;
        c6_b_a = c6_e_m;
        c6_d_b = c6_jA;
        c6_i359 = c6_b_a + c6_d_b;
        c6_c_a = c6_i358;
        c6_e_b = c6_i359;
        c6_d_a = c6_c_a;
        c6_f_b = c6_e_b;
        if (c6_d_a > c6_f_b) {
          c6_b_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_b_overflow = (c6_f_b > 2147483646);
        }

        if (c6_b_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_b_overflow);
        }

        for (c6_ijA = c6_i358; c6_ijA <= c6_i359; c6_ijA++) {
          c6_b_ijA = c6_ijA;
          c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ijA), 1, 36, 1, 0) - 1] =
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ijA), 1, 36, 1, 0) - 1] +
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_ix), 1, 36, 1, 0) - 1] * c6_temp;
          c6_e_a = c6_ix + 1;
          c6_ix = c6_e_a;
        }
      }

      c6_f_a = c6_jy + 6;
      c6_jy = c6_f_a;
      c6_g_a = c6_jA + 6;
      c6_jA = c6_g_a;
    }
  }
}

static void c6_c_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36])
{
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_jBcol;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_kAcol;
  int32_T c6_i360;
  int32_T c6_a;
  int32_T c6_b_a;
  boolean_T c6_overflow;
  int32_T c6_i;
  int32_T c6_b_i;
  c6_below_threshold(chartInstance);
  c6_scalarEg(chartInstance);
  c6_eml_switch_helper(chartInstance);
  for (c6_j = 1; c6_j < 7; c6_j++) {
    c6_b_j = c6_j - 1;
    c6_jBcol = 6 * c6_b_j;
    c6_eml_switch_helper(chartInstance);
    for (c6_k = 1; c6_k < 7; c6_k++) {
      c6_b_k = c6_k;
      c6_kAcol = 6 * (c6_b_k - 1);
      if (c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_k + c6_jBcol)), 1, 36, 1, 0) - 1] != 0.0) {
        c6_i360 = c6_b_k + 1;
        c6_a = c6_i360;
        c6_b_a = c6_a;
        if (c6_b_a > 6) {
          c6_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_overflow = false;
        }

        if (c6_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_overflow);
        }

        for (c6_i = c6_i360; c6_i < 7; c6_i++) {
          c6_b_i = c6_i;
          c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_i + c6_jBcol)), 1, 36, 1, 0) - 1] =
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_i + c6_jBcol)), 1, 36, 1, 0) - 1] -
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_k + c6_jBcol)), 1, 36, 1, 0) - 1] *
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_i + c6_kAcol)), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void c6_d_eml_xtrsm(SFc6_EKF_SIL_02InstanceStruct *chartInstance, real_T
  c6_A[36], real_T c6_B[36])
{
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_jBcol;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_kAcol;
  int32_T c6_i361;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_i;
  int32_T c6_b_i;
  c6_below_threshold(chartInstance);
  c6_scalarEg(chartInstance);
  c6_eml_switch_helper(chartInstance);
  for (c6_j = 1; c6_j < 7; c6_j++) {
    c6_b_j = c6_j - 1;
    c6_jBcol = 6 * c6_b_j;
    c6_eml_switch_helper(chartInstance);
    for (c6_k = 6; c6_k > 0; c6_k--) {
      c6_b_k = c6_k;
      c6_kAcol = 6 * (c6_b_k - 1);
      if (c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_k + c6_jBcol)), 1, 36, 1, 0) - 1] != 0.0) {
        c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c6_b_k + c6_jBcol)), 1, 36, 1, 0) - 1] = c6_rdivide
          (chartInstance, c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)(c6_b_k + c6_jBcol)), 1, 36, 1, 0) -
           1], c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
             "", (real_T)(c6_b_k + c6_kAcol)), 1, 36, 1, 0) - 1]);
        c6_i361 = c6_b_k - 1;
        c6_b = c6_i361;
        c6_b_b = c6_b;
        if (1 > c6_b_b) {
          c6_overflow = false;
        } else {
          c6_eml_switch_helper(chartInstance);
          c6_eml_switch_helper(chartInstance);
          c6_overflow = (c6_b_b > 2147483646);
        }

        if (c6_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_overflow);
        }

        for (c6_i = 1; c6_i <= c6_i361; c6_i++) {
          c6_b_i = c6_i;
          c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_i + c6_jBcol)), 1, 36, 1, 0) - 1] =
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_i + c6_jBcol)), 1, 36, 1, 0) - 1] -
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_k + c6_jBcol)), 1, 36, 1, 0) - 1] *
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c6_b_i + c6_kAcol)), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc6_EKF_SIL_02InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_EKF_SIL_02InstanceStruct
  *chartInstance)
{
  chartInstance->c6_X_a = (real_T (*)[20])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_Phi = (real_T (*)[324])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_n = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c6_t_Kalman = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c6_p = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c6_M = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c6_V = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c6_EKF_SIL_02_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3070662707U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2322907135U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3898399433U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1913406081U);
}

mxArray* sf_c6_EKF_SIL_02_get_post_codegen_info(void);
mxArray *sf_c6_EKF_SIL_02_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4l5gPyDjeKW1VzIA7rNxDG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(20);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
      pr[0] = (double)(3);
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(18);
      pr[1] = (double)(18);
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
    mxArray* mxPostCodegenInfo = sf_c6_EKF_SIL_02_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_EKF_SIL_02_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_EKF_SIL_02_jit_fallback_info(void)
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

mxArray *sf_c6_EKF_SIL_02_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_EKF_SIL_02_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_EKF_SIL_02(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Phi\",},{M[8],M[0],T\"is_active_c6_EKF_SIL_02\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_EKF_SIL_02_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_EKF_SIL_02InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_EKF_SIL_02InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EKF_SIL_02MachineNumber_,
           6,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"X_a");
          _SFD_SET_DATA_PROPS(1,1,1,0,"n");
          _SFD_SET_DATA_PROPS(2,1,1,0,"t_Kalman");
          _SFD_SET_DATA_PROPS(3,1,1,0,"p");
          _SFD_SET_DATA_PROPS(4,1,1,0,"M");
          _SFD_SET_DATA_PROPS(5,1,1,0,"V");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Phi");
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
        _SFD_CV_INIT_EML(0,1,5,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",260,-1,636);
        _SFD_CV_INIT_EML_FCN(0,1,"fn_Create_Phi_r",923,-1,1539);
        _SFD_CV_INIT_EML_FCN(0,2,"fn_Create_M",1797,-1,1960);
        _SFD_CV_INIT_EML_FCN(0,3,"fn_Create_N",2188,-1,2310);
        _SFD_CV_INIT_EML_FCN(0,4,"fn_Create_Phi_t",2562,-1,2814);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"fn_VectorToSkewSymmetricTensor",0,-1,433);

        {
          unsigned int dimVector[1];
          dimVector[0]= 20;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
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
    SFc6_EKF_SIL_02InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_EKF_SIL_02InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c6_X_a);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c6_Phi);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c6_n);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c6_t_Kalman);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c6_p);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c6_M);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c6_V);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sRixDqVTQqeaCoQCIuwe4TF";
}

static void sf_opaque_initialize_c6_EKF_SIL_02(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*)
    chartInstanceVar);
  initialize_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_EKF_SIL_02(void *chartInstanceVar)
{
  enable_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_EKF_SIL_02(void *chartInstanceVar)
{
  disable_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_EKF_SIL_02(void *chartInstanceVar)
{
  sf_gateway_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_EKF_SIL_02(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_EKF_SIL_02(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c6_EKF_SIL_02(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EKF_SIL_02_optimization_info();
    }

    finalize_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_EKF_SIL_02(SimStruct *S)
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
    initialize_params_c6_EKF_SIL_02((SFc6_EKF_SIL_02InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_EKF_SIL_02(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EKF_SIL_02_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1170204430U));
  ssSetChecksum1(S,(1497380220U));
  ssSetChecksum2(S,(4019051081U));
  ssSetChecksum3(S,(3703122147U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_EKF_SIL_02(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_EKF_SIL_02(SimStruct *S)
{
  SFc6_EKF_SIL_02InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_EKF_SIL_02InstanceStruct *)utMalloc(sizeof
    (SFc6_EKF_SIL_02InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_EKF_SIL_02InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_EKF_SIL_02;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_EKF_SIL_02;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_EKF_SIL_02;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_EKF_SIL_02;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_EKF_SIL_02;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_EKF_SIL_02;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_EKF_SIL_02;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_EKF_SIL_02;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_EKF_SIL_02;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_EKF_SIL_02;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_EKF_SIL_02;
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

void c6_EKF_SIL_02_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_EKF_SIL_02(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_EKF_SIL_02(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_EKF_SIL_02(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_EKF_SIL_02_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
