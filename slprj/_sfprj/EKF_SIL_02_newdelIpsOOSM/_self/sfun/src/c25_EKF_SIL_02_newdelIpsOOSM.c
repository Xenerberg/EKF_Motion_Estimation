/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EKF_SIL_02_newdelIpsOOSM_sfun.h"
#include "c25_EKF_SIL_02_newdelIpsOOSM.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EKF_SIL_02_newdelIpsOOSM_sfun_debug_macros.h"
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
static const char * c25_debug_family_names[15] = { "temp", "nargin", "nargout",
  "Sk", "del_x", "UF", "Pd", "U", "H", "x_d", "K", "Phi", "U1", "xd", "Pd1" };

/* Function Declarations */
static void initialize_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void initialize_params_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void enable_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void disable_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void c25_update_debugger_state_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void set_sim_state_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_st);
static void finalize_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void sf_gateway_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void mdl_start_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void c25_chartstep_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void initSimStructsc25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber);
static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, const mxArray *c25_b_Pd1, const char_T *c25_identifier, real_T
  c25_y[324]);
static void c25_b_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[324]);
static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_c_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_b_xd, const char_T *c25_identifier, real_T
  c25_y[18]);
static void c25_d_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[18]);
static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T c25_inData_sizes[2]);
static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T c25_inData_sizes[2]);
static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T *c25_inData_sizes);
static const mxArray *c25_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T c25_inData_sizes[2]);
static const mxArray *c25_g_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_e_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T *c25_inData_sizes);
static void c25_f_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y_data[], int32_T *c25_y_sizes);
static void c25_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, real_T c25_outData_data[],
  int32_T *c25_outData_sizes);
static void c25_inv(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance,
                    real_T c25_x_data[], int32_T c25_x_sizes[2], real_T
                    c25_y_data[], int32_T c25_y_sizes[2]);
static void c25_realmin(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_eps(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);
static void c25_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_dimagree(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_eml_switch_helper(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_eml_xgetrf(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_b_A_data[], int32_T c25_b_A_sizes
  [2], int32_T c25_ipiv_data[], int32_T c25_ipiv_sizes[2]);
static void c25_check_forloop_overflow_error
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, boolean_T
   c25_overflow);
static int32_T c25_eml_ixamax(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, real_T c25_x_data[], int32_T c25_x_sizes[2],
  int32_T c25_ix0);
static boolean_T c25_use_refblas(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_eml_xgeru(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_alpha1, int32_T
  c25_ix0, int32_T c25_iy0, int32_T c25_incy, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_ia0, int32_T c25_lda, real_T c25_b_A_data[],
  int32_T c25_b_A_sizes[2]);
static void c25_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_eml_ipiv2perm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_ipiv_data[], int32_T c25_ipiv_sizes[2], int32_T
  c25_m, int32_T c25_perm_data[], int32_T c25_perm_sizes[2]);
static void c25_eml_xtrsm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes[2],
  int32_T c25_ldb, real_T c25_b_B_data[], int32_T c25_b_B_sizes[2]);
static real_T c25_norm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, real_T c25_x_data[], int32_T c25_x_sizes[2]);
static void c25_eml_warning(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_b_eml_warning(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, char_T c25_varargin_2[14]);
static void c25_b_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes,
  int32_T c25_ldb, real_T c25_C_data[], int32_T c25_C_sizes, int32_T c25_ldc,
  real_T c25_b_C_data[], int32_T *c25_b_C_sizes);
static void c25_b_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_b_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_c_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_b_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, real_T c25_A[324], real_T c25_B_data[], int32_T
  c25_B_sizes[2], real_T c25_C_data[], int32_T c25_C_sizes[2], real_T
  c25_b_C_data[], int32_T c25_b_C_sizes[2]);
static void c25_c_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_c_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_d_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_d_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_c_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[6], int32_T c25_ldb, real_T c25_C[18], real_T c25_b_C[18]);
static void c25_d_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_e_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_e_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_d_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], real_T c25_B_data[], int32_T c25_B_sizes[2], int32_T c25_ldb,
  real_T c25_C_data[], int32_T c25_C_sizes[2], real_T c25_b_C_data[], int32_T
  c25_b_C_sizes[2]);
static void c25_e_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_f_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_e_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[324], int32_T c25_ldb, real_T c25_C[324], real_T c25_b_C[324]);
static void c25_f_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_eye(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance,
                    real_T c25_I[324]);
static void c25_g_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_f_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, int32_T c25_k, real_T
  c25_A_data[], int32_T c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[],
  int32_T c25_B_sizes[2], int32_T c25_ldb, real_T c25_C_data[], int32_T
  c25_C_sizes[2], int32_T c25_ldc, real_T c25_b_C_data[], int32_T c25_b_C_sizes
  [2]);
static void c25_g_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_h_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void c25_g_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, real_T c25_A[324], real_T c25_B[324], real_T c25_C[324],
  real_T c25_b_C[324]);
static void c25_g_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_sprintf, const char_T *c25_identifier,
  char_T c25_y[14]);
static void c25_h_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  char_T c25_y[14]);
static const mxArray *c25_i_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static int32_T c25_i_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static uint8_T c25_j_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_b_is_active_c25_EKF_SIL_02_newdelIpsOOSM, const char_T *c25_identifier);
static uint8_T c25_k_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_b_eml_xgetrf(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, int32_T c25_ipiv_data[], int32_T
  c25_ipiv_sizes[2]);
static void c25_b_eml_xgeru(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_alpha1, int32_T
  c25_ix0, int32_T c25_iy0, int32_T c25_incy, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_ia0, int32_T c25_lda);
static void c25_b_eml_xtrsm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes[2],
  int32_T c25_ldb);
static void c25_h_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes,
  int32_T c25_ldb, real_T c25_C_data[], int32_T *c25_C_sizes, int32_T c25_ldc);
static void c25_i_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, real_T c25_A[324], real_T c25_B_data[], int32_T
  c25_B_sizes[2], real_T c25_C_data[], int32_T c25_C_sizes[2]);
static void c25_j_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[6], int32_T c25_ldb, real_T c25_C[18]);
static void c25_k_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], real_T c25_B_data[], int32_T c25_B_sizes[2], int32_T c25_ldb,
  real_T c25_C_data[], int32_T c25_C_sizes[2]);
static void c25_l_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[324], int32_T c25_ldb, real_T c25_C[324]);
static void c25_m_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, int32_T c25_k, real_T
  c25_A_data[], int32_T c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[],
  int32_T c25_B_sizes[2], int32_T c25_ldb, real_T c25_C_data[], int32_T
  c25_C_sizes[2], int32_T c25_ldc);
static void c25_n_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, real_T c25_A[324], real_T c25_B[324], real_T c25_C[324]);
static void init_dsm_address_info(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance);
static void init_simulink_io_address
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc25_EKF_SIL_02_newdelIpsOOSM(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c25_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c25_is_active_c25_EKF_SIL_02_newdelIpsOOSM = 0U;
}

static void initialize_params_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c25_update_debugger_state_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  const mxArray *c25_st;
  const mxArray *c25_y = NULL;
  const mxArray *c25_b_y = NULL;
  const mxArray *c25_c_y = NULL;
  const mxArray *c25_d_y = NULL;
  uint8_T c25_hoistedGlobal;
  uint8_T c25_u;
  const mxArray *c25_e_y = NULL;
  c25_st = NULL;
  c25_st = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_createcellmatrix(4, 1), false);
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", *chartInstance->c25_Pd1, 0, 0U, 1U,
    0U, 2, 18, 18), false);
  sf_mex_setcell(c25_y, 0, c25_b_y);
  c25_c_y = NULL;
  sf_mex_assign(&c25_c_y, sf_mex_create("y", *chartInstance->c25_U1, 0, 0U, 1U,
    0U, 2, 18, 18), false);
  sf_mex_setcell(c25_y, 1, c25_c_y);
  c25_d_y = NULL;
  sf_mex_assign(&c25_d_y, sf_mex_create("y", *chartInstance->c25_xd, 0, 0U, 1U,
    0U, 1, 18), false);
  sf_mex_setcell(c25_y, 2, c25_d_y);
  c25_hoistedGlobal = chartInstance->c25_is_active_c25_EKF_SIL_02_newdelIpsOOSM;
  c25_u = c25_hoistedGlobal;
  c25_e_y = NULL;
  sf_mex_assign(&c25_e_y, sf_mex_create("y", &c25_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_y, 3, c25_e_y);
  sf_mex_assign(&c25_st, c25_y, false);
  return c25_st;
}

static void set_sim_state_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_st)
{
  const mxArray *c25_u;
  real_T c25_dv0[324];
  int32_T c25_i0;
  real_T c25_dv1[324];
  int32_T c25_i1;
  real_T c25_dv2[18];
  int32_T c25_i2;
  chartInstance->c25_doneDoubleBufferReInit = true;
  c25_u = sf_mex_dup(c25_st);
  c25_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("Pd1", c25_u, 0)),
                       "Pd1", c25_dv0);
  for (c25_i0 = 0; c25_i0 < 324; c25_i0++) {
    (*chartInstance->c25_Pd1)[c25_i0] = c25_dv0[c25_i0];
  }

  c25_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("U1", c25_u, 1)),
                       "U1", c25_dv1);
  for (c25_i1 = 0; c25_i1 < 324; c25_i1++) {
    (*chartInstance->c25_U1)[c25_i1] = c25_dv1[c25_i1];
  }

  c25_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("xd", c25_u, 2)),
    "xd", c25_dv2);
  for (c25_i2 = 0; c25_i2 < 18; c25_i2++) {
    (*chartInstance->c25_xd)[c25_i2] = c25_dv2[c25_i2];
  }

  chartInstance->c25_is_active_c25_EKF_SIL_02_newdelIpsOOSM =
    c25_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c25_EKF_SIL_02_newdelIpsOOSM", c25_u, 3)),
    "is_active_c25_EKF_SIL_02_newdelIpsOOSM");
  sf_mex_destroy(&c25_u);
  c25_update_debugger_state_c25_EKF_SIL_02_newdelIpsOOSM(chartInstance);
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  int32_T c25_i3;
  int32_T c25_loop_ub;
  int32_T c25_i4;
  int32_T c25_i5;
  int32_T c25_b_loop_ub;
  int32_T c25_i6;
  int32_T c25_i7;
  int32_T c25_i8;
  int32_T c25_i9;
  int32_T c25_c_loop_ub;
  int32_T c25_i10;
  int32_T c25_d_loop_ub;
  int32_T c25_i11;
  int32_T c25_i12;
  int32_T c25_i13;
  int32_T c25_i14;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c25_sfEvent);
  for (c25_i3 = 0; c25_i3 < 324; c25_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_Phi)[c25_i3], 8U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  c25_loop_ub = (*chartInstance->c25_K_sizes)[0] * (*chartInstance->c25_K_sizes)
    [1] - 1;
  for (c25_i4 = 0; c25_i4 <= c25_loop_ub; c25_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_K_data)[c25_i4], 7U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  for (c25_i5 = 0; c25_i5 < 18; c25_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_x_d)[c25_i5], 6U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  c25_b_loop_ub = (*chartInstance->c25_H_sizes)[0] *
    (*chartInstance->c25_H_sizes)[1] - 1;
  for (c25_i6 = 0; c25_i6 <= c25_b_loop_ub; c25_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_H_data)[c25_i6], 5U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  for (c25_i7 = 0; c25_i7 < 324; c25_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_U)[c25_i7], 4U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  for (c25_i8 = 0; c25_i8 < 324; c25_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_Pd)[c25_i8], 3U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  for (c25_i9 = 0; c25_i9 < 324; c25_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_UF)[c25_i9], 2U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  c25_c_loop_ub = *chartInstance->c25_del_x_sizes - 1;
  for (c25_i10 = 0; c25_i10 <= c25_c_loop_ub; c25_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_del_x_data)[c25_i10], 1U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  c25_d_loop_ub = (*chartInstance->c25_Sk_sizes)[0] *
    (*chartInstance->c25_Sk_sizes)[1] - 1;
  for (c25_i11 = 0; c25_i11 <= c25_d_loop_ub; c25_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_Sk_data)[c25_i11], 0U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  chartInstance->c25_sfEvent = CALL_EVENT;
  c25_chartstep_c25_EKF_SIL_02_newdelIpsOOSM(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EKF_SIL_02_newdelIpsOOSMMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c25_i12 = 0; c25_i12 < 324; c25_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_U1)[c25_i12], 9U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  for (c25_i13 = 0; c25_i13 < 18; c25_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_xd)[c25_i13], 10U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }

  for (c25_i14 = 0; c25_i14 < 324; c25_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_Pd1)[c25_i14], 11U, 1U, 0U,
                          chartInstance->c25_sfEvent, false);
  }
}

static void mdl_start_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_chartstep_c25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  int32_T c25_b_Sk_sizes[2];
  int32_T c25_Sk;
  int32_T c25_b_Sk;
  int32_T c25_loop_ub;
  int32_T c25_i15;
  real_T c25_b_Sk_data[144];
  int32_T c25_b_del_x_sizes;
  int32_T c25_b_loop_ub;
  int32_T c25_i16;
  real_T c25_b_del_x_data[12];
  int32_T c25_i17;
  real_T c25_b_UF[324];
  int32_T c25_i18;
  real_T c25_b_Pd[324];
  int32_T c25_i19;
  real_T c25_b_U[324];
  int32_T c25_b_H_sizes[2];
  int32_T c25_H;
  int32_T c25_b_H;
  int32_T c25_c_loop_ub;
  int32_T c25_i20;
  real_T c25_b_H_data[216];
  int32_T c25_i21;
  real_T c25_b_x_d[18];
  int32_T c25_b_K_sizes[2];
  int32_T c25_K;
  int32_T c25_b_K;
  int32_T c25_d_loop_ub;
  int32_T c25_i22;
  real_T c25_b_K_data[216];
  int32_T c25_i23;
  real_T c25_b_Phi[324];
  uint32_T c25_debug_family_var_map[15];
  int32_T c25_temp_sizes;
  real_T c25_temp_data[18];
  real_T c25_nargin = 9.0;
  real_T c25_nargout = 3.0;
  real_T c25_b_U1[324];
  real_T c25_b_xd[18];
  real_T c25_b_Pd1[324];
  int32_T c25_c_Sk_sizes[2];
  int32_T c25_c_Sk;
  int32_T c25_d_Sk;
  int32_T c25_e_loop_ub;
  int32_T c25_i24;
  real_T c25_c_Sk_data[144];
  int32_T c25_a_sizes[2];
  real_T c25_a_data[144];
  int32_T c25_b_sizes;
  int32_T c25_f_loop_ub;
  int32_T c25_i25;
  real_T c25_b_data[12];
  boolean_T c25_innerDimOk;
  boolean_T c25_b0;
  boolean_T c25_b1;
  const mxArray *c25_y = NULL;
  static char_T c25_u[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D', 'y',
    'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p', 'a',
    'n', 's', 'i', 'o', 'n' };

  const mxArray *c25_b_y = NULL;
  static char_T c25_b_u[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  int32_T c25_tmp_sizes;
  int32_T c25_g_loop_ub;
  int32_T c25_i26;
  real_T c25_tmp_data[12];
  int32_T c25_h_loop_ub;
  int32_T c25_i27;
  int32_T c25_k;
  real_T c25_dv3[2];
  int32_T c25_b_tmp_sizes;
  int32_T c25_i_loop_ub;
  int32_T c25_i28;
  real_T c25_b_tmp_data[12];
  int32_T c25_m;
  int32_T c25_i29;
  int32_T c25_j_loop_ub;
  int32_T c25_i30;
  int32_T c25_b_a_sizes[2];
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_k_loop_ub;
  int32_T c25_i31;
  real_T c25_b_a_data[144];
  int32_T c25_b_b_sizes;
  int32_T c25_l_loop_ub;
  int32_T c25_i32;
  real_T c25_b_b_data[12];
  int32_T c25_m_loop_ub;
  int32_T c25_i33;
  int32_T c25_i34;
  real_T c25_c_a[324];
  int32_T c25_c_b_sizes[2];
  int32_T c25_n_loop_ub;
  int32_T c25_i35;
  int32_T c25_o_loop_ub;
  int32_T c25_i36;
  real_T c25_c_b_data[216];
  boolean_T c25_b_innerDimOk;
  boolean_T c25_b2;
  boolean_T c25_b3;
  const mxArray *c25_c_y = NULL;
  const mxArray *c25_d_y = NULL;
  int32_T c25_y_sizes[2];
  int32_T c25_i37;
  int32_T c25_p_loop_ub;
  int32_T c25_i38;
  real_T c25_y_data[216];
  int32_T c25_i39;
  int32_T c25_c_a_sizes[2];
  int32_T c25_iv0[2];
  int32_T c25_d_a;
  int32_T c25_e_a;
  int32_T c25_q_loop_ub;
  int32_T c25_i40;
  real_T c25_c_a_data[216];
  int32_T c25_i41;
  int32_T c25_n;
  int32_T c25_r_loop_ub;
  int32_T c25_i42;
  int32_T c25_i43;
  int32_T c25_i44;
  real_T c25_f_a[324];
  int32_T c25_d_b_sizes[2];
  int32_T c25_b;
  int32_T c25_b_b;
  int32_T c25_s_loop_ub;
  int32_T c25_i45;
  real_T c25_d_b_data[216];
  int32_T c25_temp[2];
  int32_T c25_i46;
  real_T c25_c_b[6];
  boolean_T c25_c_innerDimOk;
  const mxArray *c25_e_y = NULL;
  int32_T c25_i47;
  real_T c25_f_y[18];
  int32_T c25_i48;
  int32_T c25_i49;
  int32_T c25_b_k;
  int32_T c25_i50;
  int32_T c25_b_y_sizes[2];
  int32_T c25_g_y;
  int32_T c25_h_y;
  int32_T c25_t_loop_ub;
  int32_T c25_i51;
  real_T c25_b_y_data[216];
  int32_T c25_i52;
  real_T c25_d_b[6];
  int32_T c25_i53;
  int32_T c25_i54;
  int32_T c25_u_loop_ub;
  int32_T c25_i55;
  int32_T c25_v_loop_ub;
  int32_T c25_i56;
  boolean_T c25_d_innerDimOk;
  boolean_T c25_b4;
  boolean_T c25_b5;
  const mxArray *c25_i_y = NULL;
  const mxArray *c25_j_y = NULL;
  int32_T c25_c_y_sizes[2];
  int32_T c25_i57;
  int32_T c25_w_loop_ub;
  int32_T c25_i58;
  real_T c25_c_y_data[216];
  int32_T c25_i59;
  int32_T c25_iv1[2];
  int32_T c25_g_a;
  int32_T c25_h_a;
  int32_T c25_x_loop_ub;
  int32_T c25_i60;
  int32_T c25_i61;
  int32_T c25_b_n;
  int32_T c25_y_loop_ub;
  int32_T c25_i62;
  int32_T c25_i63;
  int32_T c25_i64;
  real_T c25_i_a[324];
  int32_T c25_e_b_sizes[2];
  int32_T c25_e_b;
  int32_T c25_f_b;
  int32_T c25_ab_loop_ub;
  int32_T c25_i65;
  real_T c25_e_b_data[216];
  int32_T c25_d_Sk_sizes[2];
  int32_T c25_e_Sk;
  int32_T c25_f_Sk;
  int32_T c25_bb_loop_ub;
  int32_T c25_i66;
  real_T c25_d_Sk_data[144];
  int32_T c25_f_b_sizes[2];
  int32_T c25_g_b;
  int32_T c25_h_b;
  int32_T c25_cb_loop_ub;
  int32_T c25_i67;
  real_T c25_f_b_data[216];
  boolean_T c25_e_innerDimOk;
  boolean_T c25_b6;
  boolean_T c25_b7;
  const mxArray *c25_k_y = NULL;
  const mxArray *c25_l_y = NULL;
  int32_T c25_d_y_sizes[2];
  int32_T c25_i68;
  int32_T c25_db_loop_ub;
  int32_T c25_i69;
  real_T c25_d_y_data[324];
  int32_T c25_eb_loop_ub;
  int32_T c25_i70;
  int32_T c25_c_k;
  int32_T c25_c_tmp_sizes[2];
  int32_T c25_iv2[2];
  int32_T c25_i71;
  int32_T c25_i72;
  int32_T c25_fb_loop_ub;
  int32_T c25_i73;
  real_T c25_c_tmp_data[324];
  int32_T c25_i74;
  int32_T c25_c_n;
  int32_T c25_gb_loop_ub;
  int32_T c25_i75;
  int32_T c25_i76;
  int32_T c25_e_y_sizes[2];
  int32_T c25_m_y;
  int32_T c25_n_y;
  int32_T c25_hb_loop_ub;
  int32_T c25_i77;
  real_T c25_e_y_data[216];
  int32_T c25_g_b_sizes[2];
  int32_T c25_i_b;
  int32_T c25_j_b;
  int32_T c25_ib_loop_ub;
  int32_T c25_i78;
  real_T c25_g_b_data[216];
  int32_T c25_j_a;
  int32_T c25_k_a;
  int32_T c25_jb_loop_ub;
  int32_T c25_i79;
  int32_T c25_k_b;
  int32_T c25_l_b;
  int32_T c25_kb_loop_ub;
  int32_T c25_i80;
  boolean_T c25_f_innerDimOk;
  boolean_T c25_b8;
  boolean_T c25_b9;
  const mxArray *c25_o_y = NULL;
  const mxArray *c25_p_y = NULL;
  int32_T c25_f_y_sizes[2];
  int32_T c25_i81;
  int32_T c25_lb_loop_ub;
  int32_T c25_i82;
  real_T c25_f_y_data[324];
  int32_T c25_mb_loop_ub;
  int32_T c25_i83;
  int32_T c25_d_k;
  int32_T c25_iv3[2];
  int32_T c25_i84;
  int32_T c25_i85;
  int32_T c25_nb_loop_ub;
  int32_T c25_i86;
  int32_T c25_i87;
  int32_T c25_d_n;
  int32_T c25_ob_loop_ub;
  int32_T c25_i88;
  int32_T c25_i89;
  int32_T c25_d_a_sizes[2];
  int32_T c25_l_a;
  int32_T c25_m_a;
  int32_T c25_pb_loop_ub;
  int32_T c25_i90;
  real_T c25_d_a_data[216];
  int32_T c25_h_b_sizes[2];
  int32_T c25_m_b;
  int32_T c25_n_b;
  int32_T c25_qb_loop_ub;
  int32_T c25_i91;
  real_T c25_h_b_data[216];
  int32_T c25_i92;
  int32_T c25_i93;
  int32_T c25_i94;
  int32_T c25_i95;
  real_T c25_o_b[324];
  boolean_T c25_g_innerDimOk;
  const mxArray *c25_q_y = NULL;
  int32_T c25_i96;
  int32_T c25_i97;
  int32_T c25_i98;
  real_T c25_r_y[324];
  int32_T c25_i99;
  int32_T c25_i100;
  int32_T c25_e_k;
  int32_T c25_i101;
  int32_T c25_g_y_sizes[2];
  int32_T c25_s_y;
  int32_T c25_t_y;
  int32_T c25_rb_loop_ub;
  int32_T c25_i102;
  real_T c25_g_y_data[324];
  int32_T c25_i103;
  real_T c25_p_b[324];
  int32_T c25_i104;
  int32_T c25_q_b;
  int32_T c25_r_b;
  int32_T c25_sb_loop_ub;
  int32_T c25_i105;
  int32_T c25_s_b;
  int32_T c25_t_b;
  int32_T c25_tb_loop_ub;
  int32_T c25_i106;
  boolean_T c25_h_innerDimOk;
  boolean_T c25_b10;
  boolean_T c25_b11;
  boolean_T c25_b12;
  boolean_T c25_b13;
  const mxArray *c25_u_y = NULL;
  const mxArray *c25_v_y = NULL;
  int32_T c25_d_tmp_sizes[2];
  int32_T c25_ub_loop_ub;
  int32_T c25_i107;
  int32_T c25_vb_loop_ub;
  int32_T c25_i108;
  real_T c25_d_tmp_data[324];
  int32_T c25_wb_loop_ub;
  int32_T c25_i109;
  int32_T c25_f_k;
  int32_T c25_iv4[2];
  int32_T c25_e_tmp_sizes[2];
  int32_T c25_iv5[2];
  int32_T c25_i110;
  int32_T c25_i111;
  int32_T c25_xb_loop_ub;
  int32_T c25_i112;
  real_T c25_e_tmp_data[324];
  int32_T c25_i113;
  int32_T c25_b_m;
  int32_T c25_e_n;
  int32_T c25_yb_loop_ub;
  int32_T c25_i114;
  int32_T c25_ac_loop_ub;
  int32_T c25_i115;
  int32_T c25_i_b_sizes[2];
  int32_T c25_u_b;
  int32_T c25_v_b;
  int32_T c25_bc_loop_ub;
  int32_T c25_i116;
  real_T c25_i_b_data[216];
  int32_T c25_j_b_sizes[2];
  int32_T c25_w_b;
  int32_T c25_x_b;
  int32_T c25_cc_loop_ub;
  int32_T c25_i117;
  real_T c25_j_b_data[216];
  int32_T c25_i118;
  int32_T c25_iv6[2];
  int32_T c25_i119;
  int32_T c25_iv7[2];
  int32_T c25_i120;
  int32_T c25_i121;
  int32_T c25_i122;
  int32_T c25_i123;
  real_T c25_n_a[324];
  int32_T c25_i124;
  real_T c25_y_b[324];
  int32_T c25_i125;
  int32_T c25_i126;
  int32_T c25_i127;
  int32_T c25_i128;
  real_T c25_w_y[324];
  int32_T c25_i129;
  real_T c25_ab_b[324];
  int32_T c25_i130;
  int32_T c25_i131;
  int32_T c25_i132;
  int32_T c25_i133;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c25_sfEvent);
  c25_b_Sk_sizes[0] = (*chartInstance->c25_Sk_sizes)[0];
  c25_b_Sk_sizes[1] = (*chartInstance->c25_Sk_sizes)[1];
  c25_Sk = c25_b_Sk_sizes[0];
  c25_b_Sk = c25_b_Sk_sizes[1];
  c25_loop_ub = (*chartInstance->c25_Sk_sizes)[0] *
    (*chartInstance->c25_Sk_sizes)[1] - 1;
  for (c25_i15 = 0; c25_i15 <= c25_loop_ub; c25_i15++) {
    c25_b_Sk_data[c25_i15] = (*chartInstance->c25_Sk_data)[c25_i15];
  }

  c25_b_del_x_sizes = *chartInstance->c25_del_x_sizes;
  c25_b_loop_ub = *chartInstance->c25_del_x_sizes - 1;
  for (c25_i16 = 0; c25_i16 <= c25_b_loop_ub; c25_i16++) {
    c25_b_del_x_data[c25_i16] = (*chartInstance->c25_del_x_data)[c25_i16];
  }

  for (c25_i17 = 0; c25_i17 < 324; c25_i17++) {
    c25_b_UF[c25_i17] = (*chartInstance->c25_UF)[c25_i17];
  }

  for (c25_i18 = 0; c25_i18 < 324; c25_i18++) {
    c25_b_Pd[c25_i18] = (*chartInstance->c25_Pd)[c25_i18];
  }

  for (c25_i19 = 0; c25_i19 < 324; c25_i19++) {
    c25_b_U[c25_i19] = (*chartInstance->c25_U)[c25_i19];
  }

  c25_b_H_sizes[0] = (*chartInstance->c25_H_sizes)[0];
  c25_b_H_sizes[1] = (*chartInstance->c25_H_sizes)[1];
  c25_H = c25_b_H_sizes[0];
  c25_b_H = c25_b_H_sizes[1];
  c25_c_loop_ub = (*chartInstance->c25_H_sizes)[0] *
    (*chartInstance->c25_H_sizes)[1] - 1;
  for (c25_i20 = 0; c25_i20 <= c25_c_loop_ub; c25_i20++) {
    c25_b_H_data[c25_i20] = (*chartInstance->c25_H_data)[c25_i20];
  }

  for (c25_i21 = 0; c25_i21 < 18; c25_i21++) {
    c25_b_x_d[c25_i21] = (*chartInstance->c25_x_d)[c25_i21];
  }

  c25_b_K_sizes[0] = (*chartInstance->c25_K_sizes)[0];
  c25_b_K_sizes[1] = (*chartInstance->c25_K_sizes)[1];
  c25_K = c25_b_K_sizes[0];
  c25_b_K = c25_b_K_sizes[1];
  c25_d_loop_ub = (*chartInstance->c25_K_sizes)[0] *
    (*chartInstance->c25_K_sizes)[1] - 1;
  for (c25_i22 = 0; c25_i22 <= c25_d_loop_ub; c25_i22++) {
    c25_b_K_data[c25_i22] = (*chartInstance->c25_K_data)[c25_i22];
  }

  for (c25_i23 = 0; c25_i23 < 324; c25_i23++) {
    c25_b_Phi[c25_i23] = (*chartInstance->c25_Phi)[c25_i23];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c25_debug_family_names,
    c25_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c25_temp_data, (const int32_T *)
    &c25_temp_sizes, NULL, 0, 0, (void *)c25_h_sf_marshallOut, (void *)
    c25_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargin, 1U, c25_g_sf_marshallOut,
    c25_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargout, 2U, c25_g_sf_marshallOut,
    c25_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c25_b_Sk_data, (const int32_T *)&c25_b_Sk_sizes,
    NULL, 1, 3, (void *)c25_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c25_b_del_x_data, (const int32_T *)
    &c25_b_del_x_sizes, NULL, 1, 4, (void *)c25_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_UF, 5U, c25_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_Pd, 6U, c25_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_U, 7U, c25_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c25_b_H_data, (const int32_T *)&c25_b_H_sizes,
    NULL, 1, 8, (void *)c25_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_x_d, 9U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c25_b_K_data, (const int32_T *)&c25_b_K_sizes,
    NULL, 1, 10, (void *)c25_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_Phi, 11U, c25_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_b_U1, 12U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_b_xd, 13U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_b_Pd1, 14U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 4);
  c25_c_Sk_sizes[0] = c25_b_Sk_sizes[0];
  c25_c_Sk_sizes[1] = c25_b_Sk_sizes[1];
  c25_c_Sk = c25_c_Sk_sizes[0];
  c25_d_Sk = c25_c_Sk_sizes[1];
  c25_e_loop_ub = c25_b_Sk_sizes[0] * c25_b_Sk_sizes[1] - 1;
  for (c25_i24 = 0; c25_i24 <= c25_e_loop_ub; c25_i24++) {
    c25_c_Sk_data[c25_i24] = c25_b_Sk_data[c25_i24];
  }

  c25_inv(chartInstance, c25_c_Sk_data, c25_c_Sk_sizes, c25_a_data, c25_a_sizes);
  c25_b_sizes = c25_b_del_x_sizes;
  c25_f_loop_ub = c25_b_del_x_sizes - 1;
  for (c25_i25 = 0; c25_i25 <= c25_f_loop_ub; c25_i25++) {
    c25_b_data[c25_i25] = c25_b_del_x_data[c25_i25];
  }

  c25_innerDimOk = ((real_T)c25_a_sizes[1] == (real_T)c25_b_sizes);
  if (!c25_innerDimOk) {
    c25_b0 = (c25_a_sizes[0] == 1);
    c25_b1 = (c25_a_sizes[1] == 1);
    guard6 = false;
    if (c25_b0 && c25_b1) {
      guard6 = true;
    } else if (c25_b_sizes == 1) {
      guard6 = true;
    } else {
      c25_b_y = NULL;
      sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1,
        21), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_b_y));
    }

    if (guard6 == true) {
      c25_y = NULL;
      sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_y));
    }
  }

  guard5 = false;
  if ((real_T)c25_a_sizes[1] == 1.0) {
    guard5 = true;
  } else if ((real_T)c25_b_sizes == 1.0) {
    guard5 = true;
  } else {
    c25_k = c25_a_sizes[1];
    c25_b_eml_scalar_eg(chartInstance);
    c25_dv3[0] = (real_T)c25_a_sizes[0];
    c25_dv3[1] = 1.0;
    c25_b_tmp_sizes = (int32_T)c25_dv3[0];
    c25_i_loop_ub = (int32_T)c25_dv3[0] - 1;
    for (c25_i28 = 0; c25_i28 <= c25_i_loop_ub; c25_i28++) {
      c25_b_tmp_data[c25_i28] = 0.0;
    }

    c25_tmp_sizes = c25_b_tmp_sizes;
    c25_m = c25_a_sizes[0];
    c25_b_eml_scalar_eg(chartInstance);
    c25_i29 = c25_tmp_sizes;
    c25_tmp_sizes = c25_i29;
    c25_j_loop_ub = c25_i29 - 1;
    for (c25_i30 = 0; c25_i30 <= c25_j_loop_ub; c25_i30++) {
      c25_tmp_data[c25_i30] = 0.0;
    }

    c25_b_a_sizes[0] = c25_a_sizes[0];
    c25_b_a_sizes[1] = c25_a_sizes[1];
    c25_a = c25_b_a_sizes[0];
    c25_b_a = c25_b_a_sizes[1];
    c25_k_loop_ub = c25_a_sizes[0] * c25_a_sizes[1] - 1;
    for (c25_i31 = 0; c25_i31 <= c25_k_loop_ub; c25_i31++) {
      c25_b_a_data[c25_i31] = c25_a_data[c25_i31];
    }

    c25_b_b_sizes = c25_b_sizes;
    c25_l_loop_ub = c25_b_sizes - 1;
    for (c25_i32 = 0; c25_i32 <= c25_l_loop_ub; c25_i32++) {
      c25_b_b_data[c25_i32] = c25_b_data[c25_i32];
    }

    c25_h_eml_xgemm(chartInstance, c25_m, c25_k, c25_b_a_data, c25_b_a_sizes,
                    c25_m, c25_b_b_data, c25_b_b_sizes, c25_k, c25_tmp_data,
                    &c25_tmp_sizes, c25_m);
  }

  if (guard5 == true) {
    c25_tmp_sizes = c25_a_sizes[0];
    c25_g_loop_ub = c25_a_sizes[0] - 1;
    for (c25_i26 = 0; c25_i26 <= c25_g_loop_ub; c25_i26++) {
      c25_tmp_data[c25_i26] = 0.0;
      c25_h_loop_ub = c25_a_sizes[1] - 1;
      for (c25_i27 = 0; c25_i27 <= c25_h_loop_ub; c25_i27++) {
        c25_tmp_data[c25_i26] += c25_a_data[c25_i26 + c25_a_sizes[0] * c25_i27] *
          c25_b_data[c25_i27];
      }
    }
  }

  _SFD_DIM_SIZE_GEQ_CHECK(18, c25_tmp_sizes, 1);
  c25_temp_sizes = c25_tmp_sizes;
  c25_m_loop_ub = c25_tmp_sizes - 1;
  for (c25_i33 = 0; c25_i33 <= c25_m_loop_ub; c25_i33++) {
    c25_temp_data[c25_i33] = c25_tmp_data[c25_i33];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 6);
  for (c25_i34 = 0; c25_i34 < 324; c25_i34++) {
    c25_c_a[c25_i34] = c25_b_UF[c25_i34];
  }

  c25_c_b_sizes[0] = c25_b_H_sizes[1];
  c25_c_b_sizes[1] = c25_b_H_sizes[0];
  c25_n_loop_ub = c25_b_H_sizes[0] - 1;
  for (c25_i35 = 0; c25_i35 <= c25_n_loop_ub; c25_i35++) {
    c25_o_loop_ub = c25_b_H_sizes[1] - 1;
    for (c25_i36 = 0; c25_i36 <= c25_o_loop_ub; c25_i36++) {
      c25_c_b_data[c25_i36 + c25_c_b_sizes[0] * c25_i35] = c25_b_H_data[c25_i35
        + c25_b_H_sizes[0] * c25_i36];
    }
  }

  c25_b_innerDimOk = (18.0 == (real_T)c25_c_b_sizes[0]);
  if (!c25_b_innerDimOk) {
    c25_b2 = (c25_c_b_sizes[0] == 1);
    c25_b3 = (c25_c_b_sizes[1] == 1);
    if (c25_b2 && c25_b3) {
      c25_c_y = NULL;
      sf_mex_assign(&c25_c_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_c_y));
    } else {
      c25_d_y = NULL;
      sf_mex_assign(&c25_d_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1,
        21), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_d_y));
    }
  }

  if ((real_T)c25_c_b_sizes[0] == 1.0) {
    c25_y_sizes[0] = 18;
    c25_y_sizes[1] = c25_c_b_sizes[1];
    for (c25_i37 = 0; c25_i37 < 18; c25_i37++) {
      c25_p_loop_ub = c25_c_b_sizes[1] - 1;
      for (c25_i38 = 0; c25_i38 <= c25_p_loop_ub; c25_i38++) {
        c25_y_data[c25_i37 + c25_y_sizes[0] * c25_i38] = 0.0;
        for (c25_i39 = 0; c25_i39 < 18; c25_i39++) {
          c25_y_data[c25_i37 + c25_y_sizes[0] * c25_i38] += c25_c_a[c25_i37 + 18
            * c25_i39] * c25_c_b_data[c25_i39 + c25_c_b_sizes[0] * c25_i38];
        }
      }
    }
  } else {
    c25_c_eml_scalar_eg(chartInstance);
    c25_dv3[0] = 18.0;
    c25_dv3[1] = (real_T)c25_c_b_sizes[1];
    c25_c_a_sizes[0] = 18;
    c25_iv0[0] = 18;
    c25_iv0[1] = (int32_T)c25_dv3[1];
    c25_c_a_sizes[1] = c25_iv0[1];
    c25_d_a = c25_c_a_sizes[0];
    c25_e_a = c25_c_a_sizes[1];
    c25_q_loop_ub = 18 * (int32_T)c25_dv3[1] - 1;
    for (c25_i40 = 0; c25_i40 <= c25_q_loop_ub; c25_i40++) {
      c25_c_a_data[c25_i40] = 0.0;
    }

    for (c25_i41 = 0; c25_i41 < 2; c25_i41++) {
      c25_y_sizes[c25_i41] = c25_c_a_sizes[c25_i41];
    }

    c25_n = c25_c_b_sizes[1];
    c25_c_eml_scalar_eg(chartInstance);
    c25_y_sizes[0] = 18;
    c25_y_sizes[1];
    c25_r_loop_ub = c25_y_sizes[1] - 1;
    for (c25_i42 = 0; c25_i42 <= c25_r_loop_ub; c25_i42++) {
      for (c25_i43 = 0; c25_i43 < 18; c25_i43++) {
        c25_y_data[c25_i43 + c25_y_sizes[0] * c25_i42] = 0.0;
      }
    }

    for (c25_i44 = 0; c25_i44 < 324; c25_i44++) {
      c25_f_a[c25_i44] = c25_c_a[c25_i44];
    }

    c25_d_b_sizes[0] = c25_c_b_sizes[0];
    c25_d_b_sizes[1] = c25_c_b_sizes[1];
    c25_b = c25_d_b_sizes[0];
    c25_b_b = c25_d_b_sizes[1];
    c25_s_loop_ub = c25_c_b_sizes[0] * c25_c_b_sizes[1] - 1;
    for (c25_i45 = 0; c25_i45 <= c25_s_loop_ub; c25_i45++) {
      c25_d_b_data[c25_i45] = c25_c_b_data[c25_i45];
    }

    c25_i_eml_xgemm(chartInstance, c25_n, c25_f_a, c25_d_b_data, c25_d_b_sizes,
                    c25_y_data, c25_y_sizes);
  }

  c25_temp[0] = c25_temp_sizes;
  c25_temp[1] = 1;
  for (c25_i46 = 0; c25_i46 < 6; c25_i46++) {
    c25_c_b[c25_i46] = c25_temp_data[_SFD_EML_ARRAY_BOUNDS_CHECK("temp", c25_i46
      + 1, 1, c25_temp_sizes, 1, 0) - 1];
  }

  c25_c_innerDimOk = ((real_T)c25_y_sizes[1] == 6.0);
  if (!c25_c_innerDimOk) {
    c25_e_y = NULL;
    sf_mex_assign(&c25_e_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c25_e_y));
  }

  if ((real_T)c25_y_sizes[1] == 1.0) {
    for (c25_i47 = 0; c25_i47 < 18; c25_i47++) {
      c25_f_y[c25_i47] = 0.0;
      c25_i48 = 0;
      for (c25_i49 = 0; c25_i49 < 6; c25_i49++) {
        c25_f_y[c25_i47] += c25_y_data[c25_i48 + c25_i47] * c25_c_b[c25_i49];
        c25_i48 += 18;
      }
    }
  } else {
    c25_b_k = c25_y_sizes[1];
    c25_d_eml_scalar_eg(chartInstance);
    c25_d_eml_scalar_eg(chartInstance);
    for (c25_i50 = 0; c25_i50 < 18; c25_i50++) {
      c25_f_y[c25_i50] = 0.0;
    }

    c25_b_y_sizes[0] = 18;
    c25_b_y_sizes[1] = c25_y_sizes[1];
    c25_g_y = c25_b_y_sizes[0];
    c25_h_y = c25_b_y_sizes[1];
    c25_t_loop_ub = c25_y_sizes[0] * c25_y_sizes[1] - 1;
    for (c25_i51 = 0; c25_i51 <= c25_t_loop_ub; c25_i51++) {
      c25_b_y_data[c25_i51] = c25_y_data[c25_i51];
    }

    for (c25_i52 = 0; c25_i52 < 6; c25_i52++) {
      c25_d_b[c25_i52] = c25_c_b[c25_i52];
    }

    c25_j_eml_xgemm(chartInstance, c25_b_k, c25_b_y_data, c25_b_y_sizes, c25_d_b,
                    c25_b_k, c25_f_y);
  }

  for (c25_i53 = 0; c25_i53 < 18; c25_i53++) {
    c25_b_xd[c25_i53] = c25_b_x_d[c25_i53] + c25_f_y[c25_i53];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 7);
  for (c25_i54 = 0; c25_i54 < 324; c25_i54++) {
    c25_c_a[c25_i54] = c25_b_UF[c25_i54];
  }

  c25_c_b_sizes[0] = c25_b_H_sizes[1];
  c25_c_b_sizes[1] = c25_b_H_sizes[0];
  c25_u_loop_ub = c25_b_H_sizes[0] - 1;
  for (c25_i55 = 0; c25_i55 <= c25_u_loop_ub; c25_i55++) {
    c25_v_loop_ub = c25_b_H_sizes[1] - 1;
    for (c25_i56 = 0; c25_i56 <= c25_v_loop_ub; c25_i56++) {
      c25_c_b_data[c25_i56 + c25_c_b_sizes[0] * c25_i55] = c25_b_H_data[c25_i55
        + c25_b_H_sizes[0] * c25_i56];
    }
  }

  c25_d_innerDimOk = (18.0 == (real_T)c25_c_b_sizes[0]);
  if (!c25_d_innerDimOk) {
    c25_b4 = (c25_c_b_sizes[0] == 1);
    c25_b5 = (c25_c_b_sizes[1] == 1);
    if (c25_b4 && c25_b5) {
      c25_i_y = NULL;
      sf_mex_assign(&c25_i_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_i_y));
    } else {
      c25_j_y = NULL;
      sf_mex_assign(&c25_j_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1,
        21), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_j_y));
    }
  }

  if ((real_T)c25_c_b_sizes[0] == 1.0) {
    c25_c_y_sizes[0] = 18;
    c25_c_y_sizes[1] = c25_c_b_sizes[1];
    for (c25_i57 = 0; c25_i57 < 18; c25_i57++) {
      c25_w_loop_ub = c25_c_b_sizes[1] - 1;
      for (c25_i58 = 0; c25_i58 <= c25_w_loop_ub; c25_i58++) {
        c25_c_y_data[c25_i57 + c25_c_y_sizes[0] * c25_i58] = 0.0;
        for (c25_i59 = 0; c25_i59 < 18; c25_i59++) {
          c25_c_y_data[c25_i57 + c25_c_y_sizes[0] * c25_i58] += c25_c_a[c25_i57
            + 18 * c25_i59] * c25_c_b_data[c25_i59 + c25_c_b_sizes[0] * c25_i58];
        }
      }
    }
  } else {
    c25_c_eml_scalar_eg(chartInstance);
    c25_dv3[0] = 18.0;
    c25_dv3[1] = (real_T)c25_c_b_sizes[1];
    c25_c_a_sizes[0] = 18;
    c25_iv1[0] = 18;
    c25_iv1[1] = (int32_T)c25_dv3[1];
    c25_c_a_sizes[1] = c25_iv1[1];
    c25_g_a = c25_c_a_sizes[0];
    c25_h_a = c25_c_a_sizes[1];
    c25_x_loop_ub = 18 * (int32_T)c25_dv3[1] - 1;
    for (c25_i60 = 0; c25_i60 <= c25_x_loop_ub; c25_i60++) {
      c25_c_a_data[c25_i60] = 0.0;
    }

    for (c25_i61 = 0; c25_i61 < 2; c25_i61++) {
      c25_c_y_sizes[c25_i61] = c25_c_a_sizes[c25_i61];
    }

    c25_b_n = c25_c_b_sizes[1];
    c25_c_eml_scalar_eg(chartInstance);
    c25_c_y_sizes[0] = 18;
    c25_c_y_sizes[1];
    c25_y_loop_ub = c25_c_y_sizes[1] - 1;
    for (c25_i62 = 0; c25_i62 <= c25_y_loop_ub; c25_i62++) {
      for (c25_i63 = 0; c25_i63 < 18; c25_i63++) {
        c25_c_y_data[c25_i63 + c25_c_y_sizes[0] * c25_i62] = 0.0;
      }
    }

    for (c25_i64 = 0; c25_i64 < 324; c25_i64++) {
      c25_i_a[c25_i64] = c25_c_a[c25_i64];
    }

    c25_e_b_sizes[0] = c25_c_b_sizes[0];
    c25_e_b_sizes[1] = c25_c_b_sizes[1];
    c25_e_b = c25_e_b_sizes[0];
    c25_f_b = c25_e_b_sizes[1];
    c25_ab_loop_ub = c25_c_b_sizes[0] * c25_c_b_sizes[1] - 1;
    for (c25_i65 = 0; c25_i65 <= c25_ab_loop_ub; c25_i65++) {
      c25_e_b_data[c25_i65] = c25_c_b_data[c25_i65];
    }

    c25_i_eml_xgemm(chartInstance, c25_b_n, c25_i_a, c25_e_b_data, c25_e_b_sizes,
                    c25_c_y_data, c25_c_y_sizes);
  }

  c25_d_Sk_sizes[0] = c25_b_Sk_sizes[0];
  c25_d_Sk_sizes[1] = c25_b_Sk_sizes[1];
  c25_e_Sk = c25_d_Sk_sizes[0];
  c25_f_Sk = c25_d_Sk_sizes[1];
  c25_bb_loop_ub = c25_b_Sk_sizes[0] * c25_b_Sk_sizes[1] - 1;
  for (c25_i66 = 0; c25_i66 <= c25_bb_loop_ub; c25_i66++) {
    c25_d_Sk_data[c25_i66] = c25_b_Sk_data[c25_i66];
  }

  c25_inv(chartInstance, c25_d_Sk_data, c25_d_Sk_sizes, c25_a_data, c25_a_sizes);
  c25_f_b_sizes[0] = c25_a_sizes[0];
  c25_f_b_sizes[1] = c25_a_sizes[1];
  c25_g_b = c25_f_b_sizes[0];
  c25_h_b = c25_f_b_sizes[1];
  c25_cb_loop_ub = c25_a_sizes[0] * c25_a_sizes[1] - 1;
  for (c25_i67 = 0; c25_i67 <= c25_cb_loop_ub; c25_i67++) {
    c25_f_b_data[c25_i67] = c25_a_data[c25_i67];
  }

  c25_e_innerDimOk = ((real_T)c25_c_y_sizes[1] == (real_T)c25_f_b_sizes[0]);
  if (!c25_e_innerDimOk) {
    c25_b6 = (c25_f_b_sizes[0] == 1);
    c25_b7 = (c25_f_b_sizes[1] == 1);
    if (c25_b6 && c25_b7) {
      c25_k_y = NULL;
      sf_mex_assign(&c25_k_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_k_y));
    } else {
      c25_l_y = NULL;
      sf_mex_assign(&c25_l_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1,
        21), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_l_y));
    }
  }

  guard4 = false;
  if ((real_T)c25_c_y_sizes[1] == 1.0) {
    guard4 = true;
  } else if ((real_T)c25_f_b_sizes[0] == 1.0) {
    guard4 = true;
  } else {
    c25_c_k = c25_c_y_sizes[1];
    c25_e_eml_scalar_eg(chartInstance);
    c25_dv3[0] = 18.0;
    c25_dv3[1] = (real_T)c25_f_b_sizes[1];
    c25_c_tmp_sizes[0] = 18;
    c25_iv2[0] = 18;
    c25_iv2[1] = (int32_T)c25_dv3[1];
    c25_c_tmp_sizes[1] = c25_iv2[1];
    c25_i71 = c25_c_tmp_sizes[0];
    c25_i72 = c25_c_tmp_sizes[1];
    c25_fb_loop_ub = 18 * (int32_T)c25_dv3[1] - 1;
    for (c25_i73 = 0; c25_i73 <= c25_fb_loop_ub; c25_i73++) {
      c25_c_tmp_data[c25_i73] = 0.0;
    }

    for (c25_i74 = 0; c25_i74 < 2; c25_i74++) {
      c25_d_y_sizes[c25_i74] = c25_c_tmp_sizes[c25_i74];
    }

    c25_c_n = c25_f_b_sizes[1];
    c25_e_eml_scalar_eg(chartInstance);
    c25_d_y_sizes[0] = 18;
    c25_d_y_sizes[1];
    c25_gb_loop_ub = c25_d_y_sizes[1] - 1;
    for (c25_i75 = 0; c25_i75 <= c25_gb_loop_ub; c25_i75++) {
      for (c25_i76 = 0; c25_i76 < 18; c25_i76++) {
        c25_d_y_data[c25_i76 + c25_d_y_sizes[0] * c25_i75] = 0.0;
      }
    }

    c25_e_y_sizes[0] = 18;
    c25_e_y_sizes[1] = c25_c_y_sizes[1];
    c25_m_y = c25_e_y_sizes[0];
    c25_n_y = c25_e_y_sizes[1];
    c25_hb_loop_ub = c25_c_y_sizes[0] * c25_c_y_sizes[1] - 1;
    for (c25_i77 = 0; c25_i77 <= c25_hb_loop_ub; c25_i77++) {
      c25_e_y_data[c25_i77] = c25_c_y_data[c25_i77];
    }

    c25_g_b_sizes[0] = c25_f_b_sizes[0];
    c25_g_b_sizes[1] = c25_f_b_sizes[1];
    c25_i_b = c25_g_b_sizes[0];
    c25_j_b = c25_g_b_sizes[1];
    c25_ib_loop_ub = c25_f_b_sizes[0] * c25_f_b_sizes[1] - 1;
    for (c25_i78 = 0; c25_i78 <= c25_ib_loop_ub; c25_i78++) {
      c25_g_b_data[c25_i78] = c25_f_b_data[c25_i78];
    }

    c25_k_eml_xgemm(chartInstance, c25_c_n, c25_c_k, c25_e_y_data, c25_e_y_sizes,
                    c25_g_b_data, c25_g_b_sizes, c25_c_k, c25_d_y_data,
                    c25_d_y_sizes);
  }

  if (guard4 == true) {
    c25_d_y_sizes[0] = 18;
    c25_d_y_sizes[1] = c25_f_b_sizes[1];
    for (c25_i68 = 0; c25_i68 < 18; c25_i68++) {
      c25_db_loop_ub = c25_f_b_sizes[1] - 1;
      for (c25_i69 = 0; c25_i69 <= c25_db_loop_ub; c25_i69++) {
        c25_d_y_data[c25_i68 + c25_d_y_sizes[0] * c25_i69] = 0.0;
        c25_eb_loop_ub = c25_c_y_sizes[1] - 1;
        for (c25_i70 = 0; c25_i70 <= c25_eb_loop_ub; c25_i70++) {
          c25_d_y_data[c25_i68 + c25_d_y_sizes[0] * c25_i69] +=
            c25_c_y_data[c25_i68 + c25_c_y_sizes[0] * c25_i70] *
            c25_f_b_data[c25_i70 + c25_f_b_sizes[0] * c25_i69];
        }
      }
    }
  }

  c25_c_a_sizes[0] = 18;
  c25_c_a_sizes[1] = c25_d_y_sizes[1];
  c25_j_a = c25_c_a_sizes[0];
  c25_k_a = c25_c_a_sizes[1];
  c25_jb_loop_ub = c25_d_y_sizes[0] * c25_d_y_sizes[1] - 1;
  for (c25_i79 = 0; c25_i79 <= c25_jb_loop_ub; c25_i79++) {
    c25_c_a_data[c25_i79] = c25_d_y_data[c25_i79];
  }

  c25_f_b_sizes[0] = c25_b_H_sizes[0];
  c25_f_b_sizes[1] = c25_b_H_sizes[1];
  c25_k_b = c25_f_b_sizes[0];
  c25_l_b = c25_f_b_sizes[1];
  c25_kb_loop_ub = c25_b_H_sizes[0] * c25_b_H_sizes[1] - 1;
  for (c25_i80 = 0; c25_i80 <= c25_kb_loop_ub; c25_i80++) {
    c25_f_b_data[c25_i80] = c25_b_H_data[c25_i80];
  }

  c25_f_innerDimOk = ((real_T)c25_c_a_sizes[1] == (real_T)c25_f_b_sizes[0]);
  if (!c25_f_innerDimOk) {
    c25_b8 = (c25_f_b_sizes[0] == 1);
    c25_b9 = (c25_f_b_sizes[1] == 1);
    if (c25_b8 && c25_b9) {
      c25_o_y = NULL;
      sf_mex_assign(&c25_o_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_o_y));
    } else {
      c25_p_y = NULL;
      sf_mex_assign(&c25_p_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1,
        21), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_p_y));
    }
  }

  guard3 = false;
  if ((real_T)c25_c_a_sizes[1] == 1.0) {
    guard3 = true;
  } else if ((real_T)c25_f_b_sizes[0] == 1.0) {
    guard3 = true;
  } else {
    c25_d_k = c25_c_a_sizes[1];
    c25_e_eml_scalar_eg(chartInstance);
    c25_dv3[0] = 18.0;
    c25_dv3[1] = (real_T)c25_f_b_sizes[1];
    c25_c_tmp_sizes[0] = 18;
    c25_iv3[0] = 18;
    c25_iv3[1] = (int32_T)c25_dv3[1];
    c25_c_tmp_sizes[1] = c25_iv3[1];
    c25_i84 = c25_c_tmp_sizes[0];
    c25_i85 = c25_c_tmp_sizes[1];
    c25_nb_loop_ub = 18 * (int32_T)c25_dv3[1] - 1;
    for (c25_i86 = 0; c25_i86 <= c25_nb_loop_ub; c25_i86++) {
      c25_c_tmp_data[c25_i86] = 0.0;
    }

    for (c25_i87 = 0; c25_i87 < 2; c25_i87++) {
      c25_f_y_sizes[c25_i87] = c25_c_tmp_sizes[c25_i87];
    }

    c25_d_n = c25_f_b_sizes[1];
    c25_e_eml_scalar_eg(chartInstance);
    c25_f_y_sizes[0] = 18;
    c25_f_y_sizes[1];
    c25_ob_loop_ub = c25_f_y_sizes[1] - 1;
    for (c25_i88 = 0; c25_i88 <= c25_ob_loop_ub; c25_i88++) {
      for (c25_i89 = 0; c25_i89 < 18; c25_i89++) {
        c25_f_y_data[c25_i89 + c25_f_y_sizes[0] * c25_i88] = 0.0;
      }
    }

    c25_d_a_sizes[0] = 18;
    c25_d_a_sizes[1] = c25_c_a_sizes[1];
    c25_l_a = c25_d_a_sizes[0];
    c25_m_a = c25_d_a_sizes[1];
    c25_pb_loop_ub = c25_c_a_sizes[0] * c25_c_a_sizes[1] - 1;
    for (c25_i90 = 0; c25_i90 <= c25_pb_loop_ub; c25_i90++) {
      c25_d_a_data[c25_i90] = c25_c_a_data[c25_i90];
    }

    c25_h_b_sizes[0] = c25_f_b_sizes[0];
    c25_h_b_sizes[1] = c25_f_b_sizes[1];
    c25_m_b = c25_h_b_sizes[0];
    c25_n_b = c25_h_b_sizes[1];
    c25_qb_loop_ub = c25_f_b_sizes[0] * c25_f_b_sizes[1] - 1;
    for (c25_i91 = 0; c25_i91 <= c25_qb_loop_ub; c25_i91++) {
      c25_h_b_data[c25_i91] = c25_f_b_data[c25_i91];
    }

    c25_k_eml_xgemm(chartInstance, c25_d_n, c25_d_k, c25_d_a_data, c25_d_a_sizes,
                    c25_h_b_data, c25_h_b_sizes, c25_d_k, c25_f_y_data,
                    c25_f_y_sizes);
  }

  if (guard3 == true) {
    c25_f_y_sizes[0] = 18;
    c25_f_y_sizes[1] = c25_f_b_sizes[1];
    for (c25_i81 = 0; c25_i81 < 18; c25_i81++) {
      c25_lb_loop_ub = c25_f_b_sizes[1] - 1;
      for (c25_i82 = 0; c25_i82 <= c25_lb_loop_ub; c25_i82++) {
        c25_f_y_data[c25_i81 + c25_f_y_sizes[0] * c25_i82] = 0.0;
        c25_mb_loop_ub = c25_c_a_sizes[1] - 1;
        for (c25_i83 = 0; c25_i83 <= c25_mb_loop_ub; c25_i83++) {
          c25_f_y_data[c25_i81 + c25_f_y_sizes[0] * c25_i82] +=
            c25_c_a_data[c25_i81 + c25_c_a_sizes[0] * c25_i83] *
            c25_f_b_data[c25_i83 + c25_f_b_sizes[0] * c25_i82];
        }
      }
    }
  }

  c25_i92 = 0;
  for (c25_i93 = 0; c25_i93 < 18; c25_i93++) {
    c25_i94 = 0;
    for (c25_i95 = 0; c25_i95 < 18; c25_i95++) {
      c25_o_b[c25_i95 + c25_i92] = c25_b_UF[c25_i94 + c25_i93];
      c25_i94 += 18;
    }

    c25_i92 += 18;
  }

  c25_g_innerDimOk = ((real_T)c25_f_y_sizes[1] == 18.0);
  if (!c25_g_innerDimOk) {
    c25_q_y = NULL;
    sf_mex_assign(&c25_q_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c25_q_y));
  }

  if ((real_T)c25_f_y_sizes[1] == 1.0) {
    for (c25_i96 = 0; c25_i96 < 18; c25_i96++) {
      c25_i97 = 0;
      for (c25_i98 = 0; c25_i98 < 18; c25_i98++) {
        c25_r_y[c25_i97 + c25_i96] = 0.0;
        c25_i99 = 0;
        for (c25_i100 = 0; c25_i100 < 18; c25_i100++) {
          c25_r_y[c25_i97 + c25_i96] += c25_f_y_data[c25_i99 + c25_i96] *
            c25_o_b[c25_i100 + c25_i97];
          c25_i99 += 18;
        }

        c25_i97 += 18;
      }
    }
  } else {
    c25_e_k = c25_f_y_sizes[1];
    c25_f_eml_scalar_eg(chartInstance);
    c25_f_eml_scalar_eg(chartInstance);
    for (c25_i101 = 0; c25_i101 < 324; c25_i101++) {
      c25_r_y[c25_i101] = 0.0;
    }

    c25_g_y_sizes[0] = 18;
    c25_g_y_sizes[1] = c25_f_y_sizes[1];
    c25_s_y = c25_g_y_sizes[0];
    c25_t_y = c25_g_y_sizes[1];
    c25_rb_loop_ub = c25_f_y_sizes[0] * c25_f_y_sizes[1] - 1;
    for (c25_i102 = 0; c25_i102 <= c25_rb_loop_ub; c25_i102++) {
      c25_g_y_data[c25_i102] = c25_f_y_data[c25_i102];
    }

    for (c25_i103 = 0; c25_i103 < 324; c25_i103++) {
      c25_p_b[c25_i103] = c25_o_b[c25_i103];
    }

    c25_l_eml_xgemm(chartInstance, c25_e_k, c25_g_y_data, c25_g_y_sizes, c25_p_b,
                    c25_e_k, c25_r_y);
  }

  for (c25_i104 = 0; c25_i104 < 324; c25_i104++) {
    c25_b_Pd1[c25_i104] = c25_b_Pd[c25_i104] - c25_r_y[c25_i104];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 8);
  c25_c_b_sizes[0] = c25_b_K_sizes[0];
  c25_c_b_sizes[1] = c25_b_K_sizes[1];
  c25_q_b = c25_c_b_sizes[0];
  c25_r_b = c25_c_b_sizes[1];
  c25_sb_loop_ub = c25_b_K_sizes[0] * c25_b_K_sizes[1] - 1;
  for (c25_i105 = 0; c25_i105 <= c25_sb_loop_ub; c25_i105++) {
    c25_c_b_data[c25_i105] = c25_b_K_data[c25_i105];
  }

  c25_f_b_sizes[0] = c25_b_H_sizes[0];
  c25_f_b_sizes[1] = c25_b_H_sizes[1];
  c25_s_b = c25_f_b_sizes[0];
  c25_t_b = c25_f_b_sizes[1];
  c25_tb_loop_ub = c25_b_H_sizes[0] * c25_b_H_sizes[1] - 1;
  for (c25_i106 = 0; c25_i106 <= c25_tb_loop_ub; c25_i106++) {
    c25_f_b_data[c25_i106] = c25_b_H_data[c25_i106];
  }

  c25_h_innerDimOk = ((real_T)c25_c_b_sizes[1] == (real_T)c25_f_b_sizes[0]);
  if (!c25_h_innerDimOk) {
    c25_b10 = (c25_c_b_sizes[0] == 1);
    c25_b11 = (c25_c_b_sizes[1] == 1);
    guard2 = false;
    if (c25_b10 && c25_b11) {
      guard2 = true;
    } else {
      c25_b12 = (c25_f_b_sizes[0] == 1);
      c25_b13 = (c25_f_b_sizes[1] == 1);
      if (c25_b12 && c25_b13) {
        guard2 = true;
      } else {
        c25_v_y = NULL;
        sf_mex_assign(&c25_v_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1,
          21), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c25_v_y));
      }
    }

    if (guard2 == true) {
      c25_u_y = NULL;
      sf_mex_assign(&c25_u_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 45),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c25_u_y));
    }
  }

  guard1 = false;
  if ((real_T)c25_c_b_sizes[1] == 1.0) {
    guard1 = true;
  } else if ((real_T)c25_f_b_sizes[0] == 1.0) {
    guard1 = true;
  } else {
    c25_f_k = c25_c_b_sizes[1];
    c25_g_eml_scalar_eg(chartInstance);
    c25_dv3[0] = (real_T)c25_c_b_sizes[0];
    c25_dv3[1] = (real_T)c25_f_b_sizes[1];
    c25_iv4[0] = (int32_T)c25_dv3[0];
    c25_iv4[1] = (int32_T)c25_dv3[1];
    c25_e_tmp_sizes[0] = c25_iv4[0];
    c25_iv5[0] = (int32_T)c25_dv3[0];
    c25_iv5[1] = (int32_T)c25_dv3[1];
    c25_e_tmp_sizes[1] = c25_iv5[1];
    c25_i110 = c25_e_tmp_sizes[0];
    c25_i111 = c25_e_tmp_sizes[1];
    c25_xb_loop_ub = (int32_T)c25_dv3[0] * (int32_T)c25_dv3[1] - 1;
    for (c25_i112 = 0; c25_i112 <= c25_xb_loop_ub; c25_i112++) {
      c25_e_tmp_data[c25_i112] = 0.0;
    }

    for (c25_i113 = 0; c25_i113 < 2; c25_i113++) {
      c25_d_tmp_sizes[c25_i113] = c25_e_tmp_sizes[c25_i113];
    }

    c25_b_m = c25_c_b_sizes[0];
    c25_e_n = c25_f_b_sizes[1];
    c25_g_eml_scalar_eg(chartInstance);
    c25_d_tmp_sizes[0];
    c25_d_tmp_sizes[1];
    c25_yb_loop_ub = c25_d_tmp_sizes[1] - 1;
    for (c25_i114 = 0; c25_i114 <= c25_yb_loop_ub; c25_i114++) {
      c25_ac_loop_ub = c25_d_tmp_sizes[0] - 1;
      for (c25_i115 = 0; c25_i115 <= c25_ac_loop_ub; c25_i115++) {
        c25_d_tmp_data[c25_i115 + c25_d_tmp_sizes[0] * c25_i114] = 0.0;
      }
    }

    c25_i_b_sizes[0] = c25_c_b_sizes[0];
    c25_i_b_sizes[1] = c25_c_b_sizes[1];
    c25_u_b = c25_i_b_sizes[0];
    c25_v_b = c25_i_b_sizes[1];
    c25_bc_loop_ub = c25_c_b_sizes[0] * c25_c_b_sizes[1] - 1;
    for (c25_i116 = 0; c25_i116 <= c25_bc_loop_ub; c25_i116++) {
      c25_i_b_data[c25_i116] = c25_c_b_data[c25_i116];
    }

    c25_j_b_sizes[0] = c25_f_b_sizes[0];
    c25_j_b_sizes[1] = c25_f_b_sizes[1];
    c25_w_b = c25_j_b_sizes[0];
    c25_x_b = c25_j_b_sizes[1];
    c25_cc_loop_ub = c25_f_b_sizes[0] * c25_f_b_sizes[1] - 1;
    for (c25_i117 = 0; c25_i117 <= c25_cc_loop_ub; c25_i117++) {
      c25_j_b_data[c25_i117] = c25_f_b_data[c25_i117];
    }

    c25_m_eml_xgemm(chartInstance, c25_b_m, c25_e_n, c25_f_k, c25_i_b_data,
                    c25_i_b_sizes, c25_b_m, c25_j_b_data, c25_j_b_sizes, c25_f_k,
                    c25_d_tmp_data, c25_d_tmp_sizes, c25_b_m);
  }

  if (guard1 == true) {
    c25_d_tmp_sizes[0] = c25_c_b_sizes[0];
    c25_d_tmp_sizes[1] = c25_f_b_sizes[1];
    c25_ub_loop_ub = c25_c_b_sizes[0] - 1;
    for (c25_i107 = 0; c25_i107 <= c25_ub_loop_ub; c25_i107++) {
      c25_vb_loop_ub = c25_f_b_sizes[1] - 1;
      for (c25_i108 = 0; c25_i108 <= c25_vb_loop_ub; c25_i108++) {
        c25_d_tmp_data[c25_i107 + c25_d_tmp_sizes[0] * c25_i108] = 0.0;
        c25_wb_loop_ub = c25_c_b_sizes[1] - 1;
        for (c25_i109 = 0; c25_i109 <= c25_wb_loop_ub; c25_i109++) {
          c25_d_tmp_data[c25_i107 + c25_d_tmp_sizes[0] * c25_i108] +=
            c25_c_b_data[c25_i107 + c25_c_b_sizes[0] * c25_i109] *
            c25_f_b_data[c25_i109 + c25_f_b_sizes[0] * c25_i108];
        }
      }
    }
  }

  for (c25_i118 = 0; c25_i118 < 2; c25_i118++) {
    c25_iv6[c25_i118] = 18;
  }

  for (c25_i119 = 0; c25_i119 < 2; c25_i119++) {
    c25_iv7[c25_i119] = c25_d_tmp_sizes[c25_i119];
  }

  _SFD_SIZE_EQ_CHECK_ND(c25_iv6, c25_iv7, 2);
  c25_eye(chartInstance, c25_c_a);
  for (c25_i120 = 0; c25_i120 < 324; c25_i120++) {
    c25_c_a[c25_i120] -= c25_d_tmp_data[c25_i120];
  }

  for (c25_i121 = 0; c25_i121 < 324; c25_i121++) {
    c25_o_b[c25_i121] = c25_b_Phi[c25_i121];
  }

  c25_h_eml_scalar_eg(chartInstance);
  c25_h_eml_scalar_eg(chartInstance);
  for (c25_i122 = 0; c25_i122 < 324; c25_i122++) {
    c25_r_y[c25_i122] = 0.0;
  }

  for (c25_i123 = 0; c25_i123 < 324; c25_i123++) {
    c25_n_a[c25_i123] = c25_c_a[c25_i123];
  }

  for (c25_i124 = 0; c25_i124 < 324; c25_i124++) {
    c25_y_b[c25_i124] = c25_o_b[c25_i124];
  }

  c25_n_eml_xgemm(chartInstance, c25_n_a, c25_y_b, c25_r_y);
  for (c25_i125 = 0; c25_i125 < 324; c25_i125++) {
    c25_o_b[c25_i125] = c25_b_U[c25_i125];
  }

  c25_h_eml_scalar_eg(chartInstance);
  c25_h_eml_scalar_eg(chartInstance);
  for (c25_i126 = 0; c25_i126 < 324; c25_i126++) {
    c25_b_U1[c25_i126] = 0.0;
  }

  for (c25_i127 = 0; c25_i127 < 324; c25_i127++) {
    c25_c_a[c25_i127] = 0.0;
  }

  for (c25_i128 = 0; c25_i128 < 324; c25_i128++) {
    c25_w_y[c25_i128] = c25_r_y[c25_i128];
  }

  for (c25_i129 = 0; c25_i129 < 324; c25_i129++) {
    c25_ab_b[c25_i129] = c25_o_b[c25_i129];
  }

  c25_n_eml_xgemm(chartInstance, c25_w_y, c25_ab_b, c25_c_a);
  for (c25_i130 = 0; c25_i130 < 324; c25_i130++) {
    c25_b_U1[c25_i130] = c25_c_a[c25_i130];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c25_i131 = 0; c25_i131 < 324; c25_i131++) {
    (*chartInstance->c25_U1)[c25_i131] = c25_b_U1[c25_i131];
  }

  for (c25_i132 = 0; c25_i132 < 18; c25_i132++) {
    (*chartInstance->c25_xd)[c25_i132] = c25_b_xd[c25_i132];
  }

  for (c25_i133 = 0; c25_i133 < 324; c25_i133++) {
    (*chartInstance->c25_Pd1)[c25_i133] = c25_b_Pd1[c25_i133];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c25_sfEvent);
}

static void initSimStructsc25_EKF_SIL_02_newdelIpsOOSM
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber)
{
  (void)c25_machineNumber;
  (void)c25_chartNumber;
  (void)c25_instanceNumber;
}

static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i134;
  int32_T c25_i135;
  int32_T c25_i136;
  real_T c25_u[324];
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_i134 = 0;
  for (c25_i135 = 0; c25_i135 < 18; c25_i135++) {
    for (c25_i136 = 0; c25_i136 < 18; c25_i136++) {
      c25_u[c25_i136 + c25_i134] = (*(real_T (*)[324])c25_inData)[c25_i136 +
        c25_i134];
    }

    c25_i134 += 18;
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 2, 18, 18),
                false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, const mxArray *c25_b_Pd1, const char_T *c25_identifier, real_T
  c25_y[324])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_Pd1), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_b_Pd1);
}

static void c25_b_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[324])
{
  real_T c25_dv4[324];
  int32_T c25_i137;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv4, 1, 0, 0U, 1, 0U, 2, 18,
                18);
  for (c25_i137 = 0; c25_i137 < 324; c25_i137++) {
    c25_y[c25_i137] = c25_dv4[c25_i137];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_Pd1;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[324];
  int32_T c25_i138;
  int32_T c25_i139;
  int32_T c25_i140;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_b_Pd1 = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_Pd1), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_b_Pd1);
  c25_i138 = 0;
  for (c25_i139 = 0; c25_i139 < 18; c25_i139++) {
    for (c25_i140 = 0; c25_i140 < 18; c25_i140++) {
      (*(real_T (*)[324])c25_outData)[c25_i140 + c25_i138] = c25_y[c25_i140 +
        c25_i138];
    }

    c25_i138 += 18;
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i141;
  real_T c25_u[18];
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i141 = 0; c25_i141 < 18; c25_i141++) {
    c25_u[c25_i141] = (*(real_T (*)[18])c25_inData)[c25_i141];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 1, 18), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_c_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_b_xd, const char_T *c25_identifier, real_T
  c25_y[18])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_xd), &c25_thisId, c25_y);
  sf_mex_destroy(&c25_b_xd);
}

static void c25_d_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[18])
{
  real_T c25_dv5[18];
  int32_T c25_i142;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv5, 1, 0, 0U, 1, 0U, 1, 18);
  for (c25_i142 = 0; c25_i142 < 18; c25_i142++) {
    c25_y[c25_i142] = c25_dv5[c25_i142];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_xd;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[18];
  int32_T c25_i143;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_b_xd = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_xd), &c25_thisId, c25_y);
  sf_mex_destroy(&c25_b_xd);
  for (c25_i143 = 0; c25_i143 < 18; c25_i143++) {
    (*(real_T (*)[18])c25_outData)[c25_i143] = c25_y[c25_i143];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T c25_inData_sizes[2])
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u_sizes[2];
  int32_T c25_u;
  int32_T c25_b_u;
  int32_T c25_loop_ub;
  int32_T c25_i144;
  real_T c25_u_data[216];
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u_sizes[0] = c25_inData_sizes[0];
  c25_u_sizes[1] = c25_inData_sizes[1];
  c25_u = c25_u_sizes[0];
  c25_b_u = c25_u_sizes[1];
  c25_loop_ub = c25_inData_sizes[0] * c25_inData_sizes[1] - 1;
  for (c25_i144 = 0; c25_i144 <= c25_loop_ub; c25_i144++) {
    c25_u_data[c25_i144] = c25_inData_data[c25_i144];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u_data, 0, 0U, 1U, 0U, 2,
    c25_u_sizes[0], c25_u_sizes[1]), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T c25_inData_sizes[2])
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u_sizes[2];
  int32_T c25_u;
  int32_T c25_b_u;
  int32_T c25_loop_ub;
  int32_T c25_i145;
  real_T c25_u_data[216];
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u_sizes[0] = c25_inData_sizes[0];
  c25_u_sizes[1] = c25_inData_sizes[1];
  c25_u = c25_u_sizes[0];
  c25_b_u = c25_u_sizes[1];
  c25_loop_ub = c25_inData_sizes[0] * c25_inData_sizes[1] - 1;
  for (c25_i145 = 0; c25_i145 <= c25_loop_ub; c25_i145++) {
    c25_u_data[c25_i145] = c25_inData_data[c25_i145];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u_data, 0, 0U, 1U, 0U, 2,
    c25_u_sizes[0], c25_u_sizes[1]), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T *c25_inData_sizes)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u_sizes;
  int32_T c25_loop_ub;
  int32_T c25_i146;
  real_T c25_u_data[12];
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u_sizes = *c25_inData_sizes;
  c25_loop_ub = *c25_inData_sizes - 1;
  for (c25_i146 = 0; c25_i146 <= c25_loop_ub; c25_i146++) {
    c25_u_data[c25_i146] = c25_inData_data[c25_i146];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u_data, 0, 0U, 1U, 0U, 1,
    c25_u_sizes), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T c25_inData_sizes[2])
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u_sizes[2];
  int32_T c25_u;
  int32_T c25_b_u;
  int32_T c25_loop_ub;
  int32_T c25_i147;
  real_T c25_u_data[144];
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u_sizes[0] = c25_inData_sizes[0];
  c25_u_sizes[1] = c25_inData_sizes[1];
  c25_u = c25_u_sizes[0];
  c25_b_u = c25_u_sizes[1];
  c25_loop_ub = c25_inData_sizes[0] * c25_inData_sizes[1] - 1;
  for (c25_i147 = 0; c25_i147 <= c25_loop_ub; c25_i147++) {
    c25_u_data[c25_i147] = c25_inData_data[c25_i147];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u_data, 0, 0U, 1U, 0U, 2,
    c25_u_sizes[0], c25_u_sizes[1]), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_g_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_e_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d0, 1, 0, 0U, 0, 0U, 0);
  c25_y = c25_d0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_nargout;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_nargout = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_nargout),
    &c25_thisId);
  sf_mex_destroy(&c25_nargout);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c25_inData_data[], int32_T *c25_inData_sizes)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u_sizes;
  int32_T c25_loop_ub;
  int32_T c25_i148;
  real_T c25_u_data[18];
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u_sizes = *c25_inData_sizes;
  c25_loop_ub = *c25_inData_sizes - 1;
  for (c25_i148 = 0; c25_i148 <= c25_loop_ub; c25_i148++) {
    c25_u_data[c25_i148] = c25_inData_data[c25_i148];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u_data, 0, 0U, 1U, 0U, 1,
    c25_u_sizes), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_f_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y_data[], int32_T *c25_y_sizes)
{
  static uint32_T c25_uv0[1] = { 18U };

  uint32_T c25_uv1[1];
  static boolean_T c25_bv0[1] = { true };

  boolean_T c25_bv1[1];
  int32_T c25_tmp_sizes;
  real_T c25_tmp_data[18];
  int32_T c25_loop_ub;
  int32_T c25_i149;
  (void)chartInstance;
  c25_uv1[0] = c25_uv0[0];
  c25_bv1[0] = c25_bv0[0];
  sf_mex_import_vs(c25_parentId, sf_mex_dup(c25_u), c25_tmp_data, 1, 0, 0U, 1,
                   0U, 1, c25_bv1, c25_uv1, &c25_tmp_sizes);
  *c25_y_sizes = c25_tmp_sizes;
  c25_loop_ub = c25_tmp_sizes - 1;
  for (c25_i149 = 0; c25_i149 <= c25_loop_ub; c25_i149++) {
    c25_y_data[c25_i149] = c25_tmp_data[c25_i149];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, real_T c25_outData_data[],
  int32_T *c25_outData_sizes)
{
  const mxArray *c25_temp;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_y_sizes;
  real_T c25_y_data[18];
  int32_T c25_loop_ub;
  int32_T c25_i150;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_temp = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_temp), &c25_thisId,
    c25_y_data, &c25_y_sizes);
  sf_mex_destroy(&c25_temp);
  *c25_outData_sizes = c25_y_sizes;
  c25_loop_ub = c25_y_sizes - 1;
  for (c25_i150 = 0; c25_i150 <= c25_loop_ub; c25_i150++) {
    c25_outData_data[c25_i150] = c25_y_data[c25_i150];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

const mxArray *sf_c25_EKF_SIL_02_newdelIpsOOSM_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c25_nameCaptureInfo = NULL;
  c25_nameCaptureInfo = NULL;
  sf_mex_assign(&c25_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c25_nameCaptureInfo;
}

static void c25_inv(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance,
                    real_T c25_x_data[], int32_T c25_x_sizes[2], real_T
                    c25_y_data[], int32_T c25_y_sizes[2])
{
  boolean_T c25_b14;
  const mxArray *c25_y = NULL;
  static char_T c25_u[19] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'q', 'u', 'a', 'r', 'e' };

  int32_T c25_b_x_sizes[2];
  int32_T c25_x;
  int32_T c25_b_x;
  int32_T c25_loop_ub;
  int32_T c25_i151;
  real_T c25_b_x_data[144];
  int32_T c25_n;
  int32_T c25_i152;
  int32_T c25_b_loop_ub;
  int32_T c25_i153;
  int32_T c25_c_loop_ub;
  int32_T c25_i154;
  int32_T c25_ipiv_sizes[2];
  int32_T c25_ipiv_data[12];
  int32_T c25_b_ipiv_sizes[2];
  int32_T c25_ipiv;
  int32_T c25_b_ipiv;
  int32_T c25_d_loop_ub;
  int32_T c25_i155;
  int32_T c25_b_ipiv_data[12];
  int32_T c25_p_sizes[2];
  int32_T c25_p_data[12];
  int32_T c25_b_n;
  int32_T c25_b;
  int32_T c25_b_b;
  int32_T c25_k;
  int32_T c25_b_k;
  int32_T c25_c;
  int32_T c25_c_k;
  int32_T c25_c_n;
  int32_T c25_a;
  int32_T c25_c_b;
  int32_T c25_b_a;
  int32_T c25_d_b;
  boolean_T c25_overflow;
  int32_T c25_j;
  int32_T c25_b_j;
  int32_T c25_c_a;
  int32_T c25_d_a;
  int32_T c25_i156;
  int32_T c25_d_n;
  int32_T c25_e_a;
  int32_T c25_e_b;
  int32_T c25_f_a;
  int32_T c25_f_b;
  boolean_T c25_b_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  int32_T c25_c_x_sizes[2];
  int32_T c25_c_x;
  int32_T c25_d_x;
  int32_T c25_e_loop_ub;
  int32_T c25_i157;
  real_T c25_c_x_data[144];
  int32_T c25_d_x_sizes[2];
  int32_T c25_e_x;
  int32_T c25_f_x;
  int32_T c25_f_loop_ub;
  int32_T c25_i158;
  real_T c25_d_x_data[144];
  real_T c25_n1x;
  int32_T c25_b_y_sizes[2];
  int32_T c25_b_y;
  int32_T c25_c_y;
  int32_T c25_g_loop_ub;
  int32_T c25_i159;
  real_T c25_b_y_data[144];
  real_T c25_n1xinv;
  real_T c25_rc;
  real_T c25_g_x;
  boolean_T c25_g_b;
  real_T c25_h_x;
  const mxArray *c25_d_y = NULL;
  static char_T c25_b_u[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  real_T c25_c_u;
  const mxArray *c25_e_y = NULL;
  real_T c25_d_u;
  const mxArray *c25_f_y = NULL;
  real_T c25_e_u;
  const mxArray *c25_g_y = NULL;
  char_T c25_str[14];
  int32_T c25_i160;
  char_T c25_b_str[14];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c25_b14 = ((real_T)c25_x_sizes[0] == (real_T)c25_x_sizes[1]);
  if (c25_b14) {
  } else {
    c25_y = NULL;
    sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 19),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c25_y));
  }

  c25_b_x_sizes[0] = c25_x_sizes[0];
  c25_b_x_sizes[1] = c25_x_sizes[1];
  c25_x = c25_b_x_sizes[0];
  c25_b_x = c25_b_x_sizes[1];
  c25_loop_ub = c25_x_sizes[0] * c25_x_sizes[1] - 1;
  for (c25_i151 = 0; c25_i151 <= c25_loop_ub; c25_i151++) {
    c25_b_x_data[c25_i151] = c25_x_data[c25_i151];
  }

  c25_n = c25_b_x_sizes[0];
  for (c25_i152 = 0; c25_i152 < 2; c25_i152++) {
    c25_y_sizes[c25_i152] = c25_b_x_sizes[c25_i152];
  }

  c25_y_sizes[0];
  c25_y_sizes[1];
  c25_b_loop_ub = c25_y_sizes[1] - 1;
  for (c25_i153 = 0; c25_i153 <= c25_b_loop_ub; c25_i153++) {
    c25_c_loop_ub = c25_y_sizes[0] - 1;
    for (c25_i154 = 0; c25_i154 <= c25_c_loop_ub; c25_i154++) {
      c25_y_data[c25_i154 + c25_y_sizes[0] * c25_i153] = 0.0;
    }
  }

  c25_b_eml_xgetrf(chartInstance, c25_n, c25_n, c25_b_x_data, c25_b_x_sizes,
                   c25_n, c25_ipiv_data, c25_ipiv_sizes);
  c25_b_ipiv_sizes[0] = 1;
  c25_b_ipiv_sizes[1] = c25_ipiv_sizes[1];
  c25_ipiv = c25_b_ipiv_sizes[0];
  c25_b_ipiv = c25_b_ipiv_sizes[1];
  c25_d_loop_ub = c25_ipiv_sizes[0] * c25_ipiv_sizes[1] - 1;
  for (c25_i155 = 0; c25_i155 <= c25_d_loop_ub; c25_i155++) {
    c25_b_ipiv_data[c25_i155] = c25_ipiv_data[c25_i155];
  }

  c25_eml_ipiv2perm(chartInstance, c25_b_ipiv_data, c25_b_ipiv_sizes, c25_n,
                    c25_p_data, c25_p_sizes);
  c25_b_n = c25_n;
  c25_b = c25_b_n;
  c25_b_b = c25_b;
  if (1 > c25_b_b) {
  } else {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
  }

  for (c25_k = 1; c25_k <= c25_b_n; c25_k++) {
    c25_b_k = c25_k;
    c25_c = c25_p_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_k, 1, c25_p_sizes[1],
      1, 0) - 1];
    c25_y_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_k, 1, c25_y_sizes[0], 1, 0)
                + c25_y_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_c, 1,
      c25_y_sizes[1], 2, 0) - 1)) - 1] = 1.0;
    c25_c_k = c25_b_k;
    c25_c_n = c25_n;
    c25_a = c25_c_k;
    c25_c_b = c25_c_n;
    c25_b_a = c25_a;
    c25_d_b = c25_c_b;
    if (c25_b_a > c25_d_b) {
      c25_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_overflow = (c25_d_b > 2147483646);
    }

    if (c25_overflow) {
      c25_check_forloop_overflow_error(chartInstance, true);
    }

    for (c25_j = c25_c_k; c25_j <= c25_c_n; c25_j++) {
      c25_b_j = c25_j;
      if (c25_y_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_j, 1, c25_y_sizes[0],
            1, 0) + c25_y_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_c, 1,
             c25_y_sizes[1], 2, 0) - 1)) - 1] != 0.0) {
        c25_c_a = c25_b_j;
        c25_d_a = c25_c_a + 1;
        c25_i156 = c25_d_a;
        c25_d_n = c25_n;
        c25_e_a = c25_i156;
        c25_e_b = c25_d_n;
        c25_f_a = c25_e_a;
        c25_f_b = c25_e_b;
        if (c25_f_a > c25_f_b) {
          c25_b_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_b_overflow = (c25_f_b > 2147483646);
        }

        if (c25_b_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_i = c25_i156; c25_i <= c25_d_n; c25_i++) {
          c25_b_i = c25_i;
          c25_y_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_i, 1, c25_y_sizes[0],
            1, 0) + c25_y_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_c, 1,
            c25_y_sizes[1], 2, 0) - 1)) - 1] = c25_y_data
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_i, 1, c25_y_sizes[0], 1, 0)
              + c25_y_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_c, 1,
                c25_y_sizes[1], 2, 0) - 1)) - 1] - c25_y_data
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_j, 1, c25_y_sizes[0], 1, 0)
              + c25_y_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_c, 1,
                c25_y_sizes[1], 2, 0) - 1)) - 1] * c25_b_x_data
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_i, 1, c25_b_x_sizes[0], 1, 0)
              + c25_b_x_sizes[0] * (_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_j, 1,
                c25_b_x_sizes[1], 2, 0) - 1)) - 1];
        }
      }
    }
  }

  c25_c_x_sizes[0] = c25_b_x_sizes[0];
  c25_c_x_sizes[1] = c25_b_x_sizes[1];
  c25_c_x = c25_c_x_sizes[0];
  c25_d_x = c25_c_x_sizes[1];
  c25_e_loop_ub = c25_b_x_sizes[0] * c25_b_x_sizes[1] - 1;
  for (c25_i157 = 0; c25_i157 <= c25_e_loop_ub; c25_i157++) {
    c25_c_x_data[c25_i157] = c25_b_x_data[c25_i157];
  }

  c25_b_eml_xtrsm(chartInstance, c25_n, c25_n, c25_c_x_data, c25_c_x_sizes,
                  c25_n, c25_y_data, c25_y_sizes, c25_n);
  c25_d_x_sizes[0] = c25_x_sizes[0];
  c25_d_x_sizes[1] = c25_x_sizes[1];
  c25_e_x = c25_d_x_sizes[0];
  c25_f_x = c25_d_x_sizes[1];
  c25_f_loop_ub = c25_x_sizes[0] * c25_x_sizes[1] - 1;
  for (c25_i158 = 0; c25_i158 <= c25_f_loop_ub; c25_i158++) {
    c25_d_x_data[c25_i158] = c25_x_data[c25_i158];
  }

  c25_n1x = c25_norm(chartInstance, c25_d_x_data, c25_d_x_sizes);
  c25_b_y_sizes[0] = c25_y_sizes[0];
  c25_b_y_sizes[1] = c25_y_sizes[1];
  c25_b_y = c25_b_y_sizes[0];
  c25_c_y = c25_b_y_sizes[1];
  c25_g_loop_ub = c25_y_sizes[0] * c25_y_sizes[1] - 1;
  for (c25_i159 = 0; c25_i159 <= c25_g_loop_ub; c25_i159++) {
    c25_b_y_data[c25_i159] = c25_y_data[c25_i159];
  }

  c25_n1xinv = c25_norm(chartInstance, c25_b_y_data, c25_b_y_sizes);
  c25_rc = 1.0 / (c25_n1x * c25_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c25_n1x == 0.0) {
    guard2 = true;
  } else if (c25_n1xinv == 0.0) {
    guard2 = true;
  } else if (c25_rc == 0.0) {
    guard1 = true;
  } else {
    c25_g_x = c25_rc;
    c25_g_b = muDoubleScalarIsNaN(c25_g_x);
    guard3 = false;
    if (c25_g_b) {
      guard3 = true;
    } else {
      c25_eps(chartInstance);
      if (c25_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c25_h_x = c25_rc;
      c25_d_y = NULL;
      sf_mex_assign(&c25_d_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1,
        8), false);
      c25_c_u = 14.0;
      c25_e_y = NULL;
      sf_mex_assign(&c25_e_y, sf_mex_create("y", &c25_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c25_d_u = 6.0;
      c25_f_y = NULL;
      sf_mex_assign(&c25_f_y, sf_mex_create("y", &c25_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      c25_e_u = c25_h_x;
      c25_g_y = NULL;
      sf_mex_assign(&c25_g_y, sf_mex_create("y", &c25_e_u, 0, 0U, 0U, 0U, 0),
                    false);
      c25_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug
        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14, sf_mex_call_debug
         (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14, c25_d_y, 14,
          c25_e_y, 14, c25_f_y), 14, c25_g_y), "sprintf", c25_str);
      for (c25_i160 = 0; c25_i160 < 14; c25_i160++) {
        c25_b_str[c25_i160] = c25_str[c25_i160];
      }

      c25_b_eml_warning(chartInstance, c25_b_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c25_eml_warning(chartInstance);
  }
}

static void c25_realmin(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_eps(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_dimagree(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_eml_switch_helper(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_eml_xgetrf(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_b_A_data[], int32_T c25_b_A_sizes
  [2], int32_T c25_ipiv_data[], int32_T c25_ipiv_sizes[2])
{
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_loop_ub;
  int32_T c25_i161;
  c25_b_A_sizes[0] = c25_A_sizes[0];
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i161 = 0; c25_i161 <= c25_loop_ub; c25_i161++) {
    c25_b_A_data[c25_i161] = c25_A_data[c25_i161];
  }

  c25_b_eml_xgetrf(chartInstance, c25_m, c25_n, c25_b_A_data, c25_b_A_sizes,
                   c25_lda, c25_ipiv_data, c25_ipiv_sizes);
}

static void c25_check_forloop_overflow_error
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, boolean_T
   c25_overflow)
{
  const mxArray *c25_y = NULL;
  static char_T c25_u[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c25_b_y = NULL;
  static char_T c25_b_u[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c25_overflow;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c25_y, 14, c25_b_y));
}

static int32_T c25_eml_ixamax(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, real_T c25_x_data[], int32_T c25_x_sizes[2],
  int32_T c25_ix0)
{
  int32_T c25_idxmax;
  int32_T c25_b_n;
  int32_T c25_b_ix0;
  int32_T c25_c_n;
  int32_T c25_c_ix0;
  int32_T c25_var;
  ptrdiff_t c25_n_t;
  ptrdiff_t c25_incx_t;
  ptrdiff_t c25_idxmax_t;
  (void)chartInstance;
  c25_b_n = c25_n;
  c25_b_ix0 = c25_ix0;
  if (c25_b_n < 1) {
    c25_idxmax = 0;
  } else {
    c25_c_n = c25_b_n;
    c25_c_ix0 = c25_b_ix0;
    c25_var = c25_c_n;
    c25_n_t = (ptrdiff_t)c25_var;
    c25_incx_t = (ptrdiff_t)1;
    c25_idxmax_t = idamax(&c25_n_t, &c25_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      c25_c_ix0, 1, c25_x_sizes[0] * c25_x_sizes[1], 1, 0) - 1], &c25_incx_t);
    c25_idxmax = (int32_T)c25_idxmax_t;
  }

  return c25_idxmax;
}

static boolean_T c25_use_refblas(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
  return false;
}

static void c25_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_eml_xgeru(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_alpha1, int32_T
  c25_ix0, int32_T c25_iy0, int32_T c25_incy, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_ia0, int32_T c25_lda, real_T c25_b_A_data[],
  int32_T c25_b_A_sizes[2])
{
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_loop_ub;
  int32_T c25_i162;
  c25_b_A_sizes[0] = c25_A_sizes[0];
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i162 = 0; c25_i162 <= c25_loop_ub; c25_i162++) {
    c25_b_A_data[c25_i162] = c25_A_data[c25_i162];
  }

  c25_b_eml_xgeru(chartInstance, c25_m, c25_n, c25_alpha1, c25_ix0, c25_iy0,
                  c25_incy, c25_b_A_data, c25_b_A_sizes, c25_ia0, c25_lda);
}

static void c25_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_eml_ipiv2perm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_ipiv_data[], int32_T c25_ipiv_sizes[2], int32_T
  c25_m, int32_T c25_perm_data[], int32_T c25_perm_sizes[2])
{
  int32_T c25_d;
  int32_T c25_b;
  int32_T c25_b_b;
  int32_T c25_a;
  int32_T c25_bi;
  int32_T c25_c_b;
  int32_T c25_d_b;
  int32_T c25_e_b;
  int32_T c25_n;
  int32_T c25_b_a;
  int32_T c25_c;
  int32_T c25_c_a;
  int32_T c25_span;
  int32_T c25_d_a;
  int32_T c25_nm1;
  int32_T c25_e_a;
  int32_T c25_f_b;
  int32_T c25_f_a;
  int32_T c25_g_a;
  int32_T c25_tmp_sizes[2];
  int32_T c25_iv8[2];
  int32_T c25_i163;
  int32_T c25_i164;
  int32_T c25_loop_ub;
  int32_T c25_i165;
  int32_T c25_tmp_data[12];
  int32_T c25_i166;
  int32_T c25_yk;
  int32_T c25_b_n;
  int32_T c25_g_b;
  int32_T c25_h_b;
  int32_T c25_k;
  int32_T c25_b_k;
  int32_T c25_h_a;
  real_T c25_nipiv;
  real_T c25_kmax;
  real_T c25_b_kmax;
  int32_T c25_i167;
  int32_T c25_c_k;
  real_T c25_d_k;
  int32_T c25_ipk;
  int32_T c25_i_a;
  real_T c25_i_b;
  int32_T c25_j_a;
  real_T c25_j_b;
  int32_T c25_idx;
  real_T c25_flt;
  boolean_T c25_p;
  int32_T c25_pipk;
  c25_d = c25_m;
  c25_b = c25_d;
  c25_b_b = c25_b;
  c25_a = c25_b_b;
  c25_bi = c25_a;
  c25_c_b = c25_bi;
  c25_d_b = c25_c_b;
  c25_e_b = c25_d_b;
  if (c25_e_b < 1) {
    c25_n = 0;
  } else {
    c25_b_a = c25_e_b;
    c25_c = c25_b_a;
    c25_c_a = c25_c - 1;
    c25_span = c25_c_a;
    c25_d_a = c25_span;
    c25_nm1 = c25_d_a;
    c25_e_a = c25_nm1;
    c25_f_b = c25_e_a;
    c25_f_a = c25_f_b;
    c25_g_a = c25_f_a + 1;
    c25_n = c25_g_a;
  }

  c25_tmp_sizes[0] = 1;
  c25_iv8[0] = 1;
  c25_iv8[1] = c25_n;
  c25_tmp_sizes[1] = c25_iv8[1];
  c25_i163 = c25_tmp_sizes[0];
  c25_i164 = c25_tmp_sizes[1];
  c25_loop_ub = c25_n - 1;
  for (c25_i165 = 0; c25_i165 <= c25_loop_ub; c25_i165++) {
    c25_tmp_data[c25_i165] = 0;
  }

  for (c25_i166 = 0; c25_i166 < 2; c25_i166++) {
    c25_perm_sizes[c25_i166] = c25_tmp_sizes[c25_i166];
  }

  if (c25_n > 0) {
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_perm_sizes[1], 1, 0);
    c25_perm_data[0] = 1;
    c25_yk = 1;
    c25_b_n = c25_n;
    c25_g_b = c25_b_n;
    c25_h_b = c25_g_b;
    if (2 > c25_h_b) {
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
    }

    for (c25_k = 2; c25_k <= c25_b_n; c25_k++) {
      c25_b_k = c25_k;
      c25_h_a = c25_yk + 1;
      c25_yk = c25_h_a;
      c25_perm_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_k, 1, c25_perm_sizes[1],
        1, 0) - 1] = c25_yk;
    }
  }

  c25_nipiv = (real_T)c25_ipiv_sizes[1];
  c25_kmax = c25_nipiv;
  c25_b_kmax = c25_kmax;
  c25_i167 = (int32_T)c25_b_kmax - 1;
  for (c25_c_k = 0; c25_c_k <= c25_i167; c25_c_k++) {
    c25_d_k = 1.0 + (real_T)c25_c_k;
    c25_ipk = c25_ipiv_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c25_d_k, 1,
      c25_ipiv_sizes[1], 1, 0) - 1];
    c25_i_a = c25_ipk;
    c25_i_b = c25_d_k;
    c25_j_a = c25_i_a;
    c25_j_b = c25_i_b;
    c25_idx = c25_j_a;
    c25_flt = c25_j_b;
    c25_p = ((real_T)c25_idx > c25_flt);
    if (c25_p) {
      c25_pipk = c25_perm_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ipk, 1,
        c25_perm_sizes[1], 1, 0) - 1];
      c25_perm_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ipk, 1, c25_perm_sizes[1],
        1, 0) - 1] = c25_perm_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        c25_d_k, 1, c25_perm_sizes[1], 1, 0) - 1];
      c25_perm_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c25_d_k, 1,
        c25_perm_sizes[1], 1, 0) - 1] = c25_pipk;
    }
  }
}

static void c25_eml_xtrsm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes[2],
  int32_T c25_ldb, real_T c25_b_B_data[], int32_T c25_b_B_sizes[2])
{
  int32_T c25_B;
  int32_T c25_b_B;
  int32_T c25_loop_ub;
  int32_T c25_i168;
  int32_T c25_b_A_sizes[2];
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_b_loop_ub;
  int32_T c25_i169;
  real_T c25_b_A_data[144];
  c25_b_B_sizes[0] = c25_B_sizes[0];
  c25_b_B_sizes[1] = c25_B_sizes[1];
  c25_B = c25_b_B_sizes[0];
  c25_b_B = c25_b_B_sizes[1];
  c25_loop_ub = c25_B_sizes[0] * c25_B_sizes[1] - 1;
  for (c25_i168 = 0; c25_i168 <= c25_loop_ub; c25_i168++) {
    c25_b_B_data[c25_i168] = c25_B_data[c25_i168];
  }

  c25_b_A_sizes[0] = c25_A_sizes[0];
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_b_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i169 = 0; c25_i169 <= c25_b_loop_ub; c25_i169++) {
    c25_b_A_data[c25_i169] = c25_A_data[c25_i169];
  }

  c25_b_eml_xtrsm(chartInstance, c25_m, c25_n, c25_b_A_data, c25_b_A_sizes,
                  c25_lda, c25_b_B_data, c25_b_B_sizes, c25_ldb);
}

static real_T c25_norm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, real_T c25_x_data[], int32_T c25_x_sizes[2])
{
  real_T c25_y;
  boolean_T c25_b15;
  boolean_T c25_b16;
  real_T c25_d1;
  int32_T c25_i170;
  int32_T c25_k;
  real_T c25_b_k;
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_b_y;
  real_T c25_m;
  real_T c25_n;
  real_T c25_b_n;
  int32_T c25_i171;
  int32_T c25_j;
  real_T c25_b_j;
  real_T c25_s;
  real_T c25_b_m;
  int32_T c25_i172;
  int32_T c25_i;
  real_T c25_b_i;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_c_y;
  real_T c25_e_x;
  boolean_T c25_b;
  boolean_T exitg1;
  (void)chartInstance;
  c25_b15 = (c25_x_sizes[0] == 1);
  c25_b16 = (c25_x_sizes[1] == 1);
  if (c25_b15 || c25_b16) {
    c25_y = 0.0;
    c25_d1 = (real_T)(c25_x_sizes[0] * c25_x_sizes[1]);
    c25_i170 = (int32_T)c25_d1 - 1;
    for (c25_k = 0; c25_k <= c25_i170; c25_k++) {
      c25_b_k = 1.0 + (real_T)c25_k;
      c25_x = c25_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c25_b_k, 1,
        c25_x_sizes[0] * c25_x_sizes[1], 1, 0) - 1];
      c25_b_x = c25_x;
      c25_b_y = muDoubleScalarAbs(c25_b_x);
      c25_y += c25_b_y;
    }
  } else {
    c25_m = (real_T)c25_x_sizes[0];
    c25_n = (real_T)c25_x_sizes[1];
    c25_y = 0.0;
    c25_b_n = c25_n;
    c25_i171 = (int32_T)c25_b_n - 1;
    c25_j = 0;
    exitg1 = false;
    while ((exitg1 == false) && (c25_j <= c25_i171)) {
      c25_b_j = 1.0 + (real_T)c25_j;
      c25_s = 0.0;
      c25_b_m = c25_m;
      c25_i172 = (int32_T)c25_b_m - 1;
      for (c25_i = 0; c25_i <= c25_i172; c25_i++) {
        c25_b_i = 1.0 + (real_T)c25_i;
        c25_c_x = c25_x_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c25_b_i,
          1, c25_x_sizes[0], 1, 0) + c25_x_sizes[0] *
                              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c25_b_j,
          1, c25_x_sizes[1], 2, 0) - 1)) - 1];
        c25_d_x = c25_c_x;
        c25_c_y = muDoubleScalarAbs(c25_d_x);
        c25_s += c25_c_y;
      }

      c25_e_x = c25_s;
      c25_b = muDoubleScalarIsNaN(c25_e_x);
      if (c25_b) {
        c25_y = rtNaN;
        exitg1 = true;
      } else {
        if (c25_s > c25_y) {
          c25_y = c25_s;
        }

        c25_j++;
      }
    }
  }

  return c25_y;
}

static void c25_eml_warning(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  const mxArray *c25_y = NULL;
  static char_T c25_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  (void)chartInstance;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c25_y));
}

static void c25_b_eml_warning(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, char_T c25_varargin_2[14])
{
  const mxArray *c25_y = NULL;
  static char_T c25_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *c25_b_y = NULL;
  (void)chartInstance;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    33), false);
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_varargin_2, 10, 0U, 1U, 0U, 2,
    1, 14), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c25_y, 14, c25_b_y));
}

static void c25_b_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes,
  int32_T c25_ldb, real_T c25_C_data[], int32_T c25_C_sizes, int32_T c25_ldc,
  real_T c25_b_C_data[], int32_T *c25_b_C_sizes)
{
  int32_T c25_loop_ub;
  int32_T c25_i173;
  int32_T c25_b_A_sizes[2];
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_b_loop_ub;
  int32_T c25_i174;
  real_T c25_b_A_data[144];
  int32_T c25_b_B_sizes;
  int32_T c25_c_loop_ub;
  int32_T c25_i175;
  real_T c25_b_B_data[12];
  *c25_b_C_sizes = c25_C_sizes;
  c25_loop_ub = c25_C_sizes - 1;
  for (c25_i173 = 0; c25_i173 <= c25_loop_ub; c25_i173++) {
    c25_b_C_data[c25_i173] = c25_C_data[c25_i173];
  }

  c25_b_A_sizes[0] = c25_A_sizes[0];
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_b_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i174 = 0; c25_i174 <= c25_b_loop_ub; c25_i174++) {
    c25_b_A_data[c25_i174] = c25_A_data[c25_i174];
  }

  c25_b_B_sizes = c25_B_sizes;
  c25_c_loop_ub = c25_B_sizes - 1;
  for (c25_i175 = 0; c25_i175 <= c25_c_loop_ub; c25_i175++) {
    c25_b_B_data[c25_i175] = c25_B_data[c25_i175];
  }

  c25_h_eml_xgemm(chartInstance, c25_m, c25_k, c25_b_A_data, c25_b_A_sizes,
                  c25_lda, c25_b_B_data, c25_b_B_sizes, c25_ldb, c25_b_C_data,
                  c25_b_C_sizes, c25_ldc);
}

static void c25_b_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  c25_threshold(chartInstance);
}

static void c25_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_b_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_c_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_b_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, real_T c25_A[324], real_T c25_B_data[], int32_T
  c25_B_sizes[2], real_T c25_C_data[], int32_T c25_C_sizes[2], real_T
  c25_b_C_data[], int32_T c25_b_C_sizes[2])
{
  int32_T c25_C;
  int32_T c25_b_C;
  int32_T c25_loop_ub;
  int32_T c25_i176;
  int32_T c25_i177;
  real_T c25_b_A[324];
  int32_T c25_b_B_sizes[2];
  int32_T c25_B;
  int32_T c25_b_B;
  int32_T c25_b_loop_ub;
  int32_T c25_i178;
  real_T c25_b_B_data[216];
  c25_b_C_sizes[0] = 18;
  c25_b_C_sizes[1] = c25_C_sizes[1];
  c25_C = c25_b_C_sizes[0];
  c25_b_C = c25_b_C_sizes[1];
  c25_loop_ub = c25_C_sizes[0] * c25_C_sizes[1] - 1;
  for (c25_i176 = 0; c25_i176 <= c25_loop_ub; c25_i176++) {
    c25_b_C_data[c25_i176] = c25_C_data[c25_i176];
  }

  for (c25_i177 = 0; c25_i177 < 324; c25_i177++) {
    c25_b_A[c25_i177] = c25_A[c25_i177];
  }

  c25_b_B_sizes[0] = c25_B_sizes[0];
  c25_b_B_sizes[1] = c25_B_sizes[1];
  c25_B = c25_b_B_sizes[0];
  c25_b_B = c25_b_B_sizes[1];
  c25_b_loop_ub = c25_B_sizes[0] * c25_B_sizes[1] - 1;
  for (c25_i178 = 0; c25_i178 <= c25_b_loop_ub; c25_i178++) {
    c25_b_B_data[c25_i178] = c25_B_data[c25_i178];
  }

  c25_i_eml_xgemm(chartInstance, c25_n, c25_b_A, c25_b_B_data, c25_b_B_sizes,
                  c25_b_C_data, c25_b_C_sizes);
}

static void c25_c_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  c25_threshold(chartInstance);
}

static void c25_c_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_d_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_d_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_c_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[6], int32_T c25_ldb, real_T c25_C[18], real_T c25_b_C[18])
{
  int32_T c25_i179;
  int32_T c25_b_A_sizes[2];
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_loop_ub;
  int32_T c25_i180;
  real_T c25_b_A_data[216];
  int32_T c25_i181;
  real_T c25_b_B[6];
  for (c25_i179 = 0; c25_i179 < 18; c25_i179++) {
    c25_b_C[c25_i179] = c25_C[c25_i179];
  }

  c25_b_A_sizes[0] = 18;
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i180 = 0; c25_i180 <= c25_loop_ub; c25_i180++) {
    c25_b_A_data[c25_i180] = c25_A_data[c25_i180];
  }

  for (c25_i181 = 0; c25_i181 < 6; c25_i181++) {
    c25_b_B[c25_i181] = c25_B[c25_i181];
  }

  c25_j_eml_xgemm(chartInstance, c25_k, c25_b_A_data, c25_b_A_sizes, c25_b_B,
                  c25_ldb, c25_b_C);
}

static void c25_d_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  c25_threshold(chartInstance);
}

static void c25_e_scalarEg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_e_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_d_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], real_T c25_B_data[], int32_T c25_B_sizes[2], int32_T c25_ldb,
  real_T c25_C_data[], int32_T c25_C_sizes[2], real_T c25_b_C_data[], int32_T
  c25_b_C_sizes[2])
{
  int32_T c25_C;
  int32_T c25_b_C;
  int32_T c25_loop_ub;
  int32_T c25_i182;
  int32_T c25_b_A_sizes[2];
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_b_loop_ub;
  int32_T c25_i183;
  real_T c25_b_A_data[216];
  int32_T c25_b_B_sizes[2];
  int32_T c25_B;
  int32_T c25_b_B;
  int32_T c25_c_loop_ub;
  int32_T c25_i184;
  real_T c25_b_B_data[216];
  c25_b_C_sizes[0] = 18;
  c25_b_C_sizes[1] = c25_C_sizes[1];
  c25_C = c25_b_C_sizes[0];
  c25_b_C = c25_b_C_sizes[1];
  c25_loop_ub = c25_C_sizes[0] * c25_C_sizes[1] - 1;
  for (c25_i182 = 0; c25_i182 <= c25_loop_ub; c25_i182++) {
    c25_b_C_data[c25_i182] = c25_C_data[c25_i182];
  }

  c25_b_A_sizes[0] = 18;
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_b_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i183 = 0; c25_i183 <= c25_b_loop_ub; c25_i183++) {
    c25_b_A_data[c25_i183] = c25_A_data[c25_i183];
  }

  c25_b_B_sizes[0] = c25_B_sizes[0];
  c25_b_B_sizes[1] = c25_B_sizes[1];
  c25_B = c25_b_B_sizes[0];
  c25_b_B = c25_b_B_sizes[1];
  c25_c_loop_ub = c25_B_sizes[0] * c25_B_sizes[1] - 1;
  for (c25_i184 = 0; c25_i184 <= c25_c_loop_ub; c25_i184++) {
    c25_b_B_data[c25_i184] = c25_B_data[c25_i184];
  }

  c25_k_eml_xgemm(chartInstance, c25_n, c25_k, c25_b_A_data, c25_b_A_sizes,
                  c25_b_B_data, c25_b_B_sizes, c25_ldb, c25_b_C_data,
                  c25_b_C_sizes);
}

static void c25_e_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  c25_threshold(chartInstance);
}

static void c25_f_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_e_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[324], int32_T c25_ldb, real_T c25_C[324], real_T c25_b_C[324])
{
  int32_T c25_i185;
  int32_T c25_b_A_sizes[2];
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_loop_ub;
  int32_T c25_i186;
  real_T c25_b_A_data[324];
  int32_T c25_i187;
  real_T c25_b_B[324];
  for (c25_i185 = 0; c25_i185 < 324; c25_i185++) {
    c25_b_C[c25_i185] = c25_C[c25_i185];
  }

  c25_b_A_sizes[0] = 18;
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i186 = 0; c25_i186 <= c25_loop_ub; c25_i186++) {
    c25_b_A_data[c25_i186] = c25_A_data[c25_i186];
  }

  for (c25_i187 = 0; c25_i187 < 324; c25_i187++) {
    c25_b_B[c25_i187] = c25_B[c25_i187];
  }

  c25_l_eml_xgemm(chartInstance, c25_k, c25_b_A_data, c25_b_A_sizes, c25_b_B,
                  c25_ldb, c25_b_C);
}

static void c25_f_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  c25_threshold(chartInstance);
}

static void c25_eye(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance,
                    real_T c25_I[324])
{
  int32_T c25_i188;
  int32_T c25_k;
  int32_T c25_b_k;
  for (c25_i188 = 0; c25_i188 < 324; c25_i188++) {
    c25_I[c25_i188] = 0.0;
  }

  c25_eml_switch_helper(chartInstance);
  for (c25_k = 1; c25_k < 19; c25_k++) {
    c25_b_k = c25_k - 1;
    c25_I[c25_b_k + 18 * c25_b_k] = 1.0;
  }
}

static void c25_g_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_f_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, int32_T c25_k, real_T
  c25_A_data[], int32_T c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[],
  int32_T c25_B_sizes[2], int32_T c25_ldb, real_T c25_C_data[], int32_T
  c25_C_sizes[2], int32_T c25_ldc, real_T c25_b_C_data[], int32_T c25_b_C_sizes
  [2])
{
  int32_T c25_C;
  int32_T c25_b_C;
  int32_T c25_loop_ub;
  int32_T c25_i189;
  int32_T c25_b_A_sizes[2];
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_b_loop_ub;
  int32_T c25_i190;
  real_T c25_b_A_data[216];
  int32_T c25_b_B_sizes[2];
  int32_T c25_B;
  int32_T c25_b_B;
  int32_T c25_c_loop_ub;
  int32_T c25_i191;
  real_T c25_b_B_data[216];
  c25_b_C_sizes[0] = c25_C_sizes[0];
  c25_b_C_sizes[1] = c25_C_sizes[1];
  c25_C = c25_b_C_sizes[0];
  c25_b_C = c25_b_C_sizes[1];
  c25_loop_ub = c25_C_sizes[0] * c25_C_sizes[1] - 1;
  for (c25_i189 = 0; c25_i189 <= c25_loop_ub; c25_i189++) {
    c25_b_C_data[c25_i189] = c25_C_data[c25_i189];
  }

  c25_b_A_sizes[0] = c25_A_sizes[0];
  c25_b_A_sizes[1] = c25_A_sizes[1];
  c25_A = c25_b_A_sizes[0];
  c25_b_A = c25_b_A_sizes[1];
  c25_b_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
  for (c25_i190 = 0; c25_i190 <= c25_b_loop_ub; c25_i190++) {
    c25_b_A_data[c25_i190] = c25_A_data[c25_i190];
  }

  c25_b_B_sizes[0] = c25_B_sizes[0];
  c25_b_B_sizes[1] = c25_B_sizes[1];
  c25_B = c25_b_B_sizes[0];
  c25_b_B = c25_b_B_sizes[1];
  c25_c_loop_ub = c25_B_sizes[0] * c25_B_sizes[1] - 1;
  for (c25_i191 = 0; c25_i191 <= c25_c_loop_ub; c25_i191++) {
    c25_b_B_data[c25_i191] = c25_B_data[c25_i191];
  }

  c25_m_eml_xgemm(chartInstance, c25_m, c25_n, c25_k, c25_b_A_data,
                  c25_b_A_sizes, c25_lda, c25_b_B_data, c25_b_B_sizes, c25_ldb,
                  c25_b_C_data, c25_b_C_sizes, c25_ldc);
}

static void c25_g_below_threshold(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  c25_threshold(chartInstance);
}

static void c25_h_eml_scalar_eg(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_g_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, real_T c25_A[324], real_T c25_B[324], real_T c25_C[324],
  real_T c25_b_C[324])
{
  int32_T c25_i192;
  int32_T c25_i193;
  real_T c25_b_A[324];
  int32_T c25_i194;
  real_T c25_b_B[324];
  for (c25_i192 = 0; c25_i192 < 324; c25_i192++) {
    c25_b_C[c25_i192] = c25_C[c25_i192];
  }

  for (c25_i193 = 0; c25_i193 < 324; c25_i193++) {
    c25_b_A[c25_i193] = c25_A[c25_i193];
  }

  for (c25_i194 = 0; c25_i194 < 324; c25_i194++) {
    c25_b_B[c25_i194] = c25_B[c25_i194];
  }

  c25_n_eml_xgemm(chartInstance, c25_b_A, c25_b_B, c25_b_C);
}

static void c25_g_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_sprintf, const char_T *c25_identifier,
  char_T c25_y[14])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_sprintf), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_sprintf);
}

static void c25_h_emlrt_marshallIn(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *
  chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  char_T c25_y[14])
{
  char_T c25_cv0[14];
  int32_T c25_i195;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_cv0, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c25_i195 = 0; c25_i195 < 14; c25_i195++) {
    c25_y[c25_i195] = c25_cv0[c25_i195];
  }

  sf_mex_destroy(&c25_u);
}

static const mxArray *c25_i_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(int32_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static int32_T c25_i_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  int32_T c25_y;
  int32_T c25_i196;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_i196, 1, 6, 0U, 0, 0U, 0);
  c25_y = c25_i196;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_sfEvent;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_y;
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
    chartInstanceVoid;
  c25_b_sfEvent = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_sfEvent),
    &c25_thisId);
  sf_mex_destroy(&c25_b_sfEvent);
  *(int32_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static uint8_T c25_j_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_b_is_active_c25_EKF_SIL_02_newdelIpsOOSM, const char_T *c25_identifier)
{
  uint8_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c25_b_is_active_c25_EKF_SIL_02_newdelIpsOOSM), &c25_thisId);
  sf_mex_destroy(&c25_b_is_active_c25_EKF_SIL_02_newdelIpsOOSM);
  return c25_y;
}

static uint8_T c25_k_emlrt_marshallIn
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance, const mxArray
   *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  uint8_T c25_y;
  uint8_T c25_u0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_u0, 1, 3, 0U, 0, 0U, 0);
  c25_y = c25_u0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_b_eml_xgetrf(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, int32_T c25_ipiv_data[], int32_T
  c25_ipiv_sizes[2])
{
  int32_T c25_b_m;
  int32_T c25_b_n;
  int32_T c25_b_lda;
  int32_T c25_c_m;
  int32_T c25_c_n;
  int32_T c25_c_lda;
  int32_T c25_varargin_1;
  int32_T c25_varargin_2;
  int32_T c25_b_varargin_2;
  int32_T c25_varargin_3;
  int32_T c25_x;
  int32_T c25_y;
  int32_T c25_b_x;
  int32_T c25_b_y;
  int32_T c25_xk;
  int32_T c25_yk;
  int32_T c25_c_x;
  int32_T c25_c_y;
  int32_T c25_minval;
  int32_T c25_d;
  int32_T c25_b;
  int32_T c25_b_b;
  int32_T c25_a;
  int32_T c25_bi;
  int32_T c25_c_b;
  int32_T c25_d_b;
  int32_T c25_e_b;
  int32_T c25_d_n;
  int32_T c25_b_a;
  int32_T c25_c;
  int32_T c25_c_a;
  int32_T c25_span;
  int32_T c25_d_a;
  int32_T c25_nm1;
  int32_T c25_e_a;
  int32_T c25_f_b;
  int32_T c25_f_a;
  int32_T c25_g_a;
  int32_T c25_tmp_sizes[2];
  int32_T c25_iv9[2];
  int32_T c25_i197;
  int32_T c25_i198;
  int32_T c25_loop_ub;
  int32_T c25_i199;
  int32_T c25_tmp_data[12];
  int32_T c25_i200;
  int32_T c25_b_yk;
  int32_T c25_e_n;
  int32_T c25_g_b;
  int32_T c25_h_b;
  int32_T c25_k;
  int32_T c25_b_k;
  int32_T c25_h_a;
  int32_T c25_info;
  int32_T c25_i_a;
  int32_T c25_j_a;
  int32_T c25_ldap1;
  int32_T c25_b_varargin_1;
  int32_T c25_c_varargin_2;
  int32_T c25_d_varargin_2;
  int32_T c25_b_varargin_3;
  int32_T c25_d_x;
  int32_T c25_d_y;
  int32_T c25_e_x;
  int32_T c25_e_y;
  int32_T c25_b_xk;
  int32_T c25_c_yk;
  int32_T c25_f_x;
  int32_T c25_f_y;
  int32_T c25_i201;
  int32_T c25_i_b;
  int32_T c25_j_b;
  int32_T c25_j;
  int32_T c25_b_j;
  int32_T c25_k_a;
  int32_T c25_l_a;
  int32_T c25_jm1;
  int32_T c25_m_a;
  int32_T c25_k_b;
  int32_T c25_n_a;
  int32_T c25_l_b;
  int32_T c25_mmj;
  int32_T c25_o_a;
  int32_T c25_m_b;
  int32_T c25_p_a;
  int32_T c25_n_b;
  int32_T c25_b_c;
  int32_T c25_o_b;
  int32_T c25_p_b;
  int32_T c25_jj;
  int32_T c25_q_a;
  int32_T c25_r_a;
  int32_T c25_jp1j;
  int32_T c25_s_a;
  int32_T c25_t_a;
  int32_T c25_c_c;
  int32_T c25_b_A_sizes[2];
  int32_T c25_A;
  int32_T c25_b_A;
  int32_T c25_b_loop_ub;
  int32_T c25_i202;
  real_T c25_b_A_data[144];
  int32_T c25_u_a;
  int32_T c25_v_a;
  int32_T c25_jpiv_offset;
  int32_T c25_w_a;
  int32_T c25_q_b;
  int32_T c25_x_a;
  int32_T c25_r_b;
  int32_T c25_jpiv;
  int32_T c25_y_a;
  int32_T c25_s_b;
  int32_T c25_ab_a;
  int32_T c25_t_b;
  int32_T c25_d_c;
  int32_T c25_u_b;
  int32_T c25_v_b;
  int32_T c25_jrow;
  int32_T c25_bb_a;
  int32_T c25_w_b;
  int32_T c25_cb_a;
  int32_T c25_x_b;
  int32_T c25_jprow;
  int32_T c25_f_n;
  int32_T c25_ix0;
  int32_T c25_incx;
  int32_T c25_iy0;
  int32_T c25_incy;
  int32_T c25_g_n;
  int32_T c25_b_ix0;
  int32_T c25_b_incx;
  int32_T c25_b_iy0;
  int32_T c25_b_incy;
  int32_T c25_h_n;
  int32_T c25_c_ix0;
  int32_T c25_c_incx;
  int32_T c25_c_iy0;
  int32_T c25_c_incy;
  int32_T c25_ix;
  int32_T c25_iy;
  int32_T c25_g_x;
  int32_T c25_h_x;
  int32_T c25_ixinc;
  int32_T c25_i_x;
  int32_T c25_j_x;
  int32_T c25_iyinc;
  int32_T c25_i_n;
  int32_T c25_y_b;
  int32_T c25_ab_b;
  int32_T c25_c_k;
  real_T c25_temp;
  int32_T c25_c_A[1];
  int32_T c25_d_A[1];
  int32_T c25_db_a;
  int32_T c25_bb_b;
  int32_T c25_eb_a;
  int32_T c25_cb_b;
  int32_T c25_b_jp1j;
  int32_T c25_fb_a;
  int32_T c25_gb_a;
  int32_T c25_e_c;
  int32_T c25_hb_a;
  int32_T c25_db_b;
  int32_T c25_ib_a;
  int32_T c25_eb_b;
  int32_T c25_i203;
  int32_T c25_jb_a;
  int32_T c25_fb_b;
  int32_T c25_kb_a;
  int32_T c25_gb_b;
  boolean_T c25_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  real_T c25_k_x;
  real_T c25_g_y;
  real_T c25_l_x;
  real_T c25_h_y;
  real_T c25_z;
  int32_T c25_e_A[1];
  int32_T c25_lb_a;
  int32_T c25_hb_b;
  int32_T c25_mb_a;
  int32_T c25_ib_b;
  int32_T c25_f_c;
  int32_T c25_nb_a;
  int32_T c25_jb_b;
  int32_T c25_ob_a;
  int32_T c25_kb_b;
  int32_T c25_g_c;
  int32_T c25_pb_a;
  int32_T c25_lb_b;
  int32_T c25_qb_a;
  int32_T c25_mb_b;
  int32_T c25_h_c;
  c25_b_m = c25_m;
  c25_b_n = c25_n;
  c25_b_lda = c25_lda;
  c25_c_m = c25_b_m;
  c25_c_n = c25_b_n;
  c25_c_lda = c25_b_lda;
  c25_realmin(chartInstance);
  c25_eps(chartInstance);
  c25_varargin_1 = c25_c_m;
  c25_varargin_2 = c25_c_n;
  c25_b_varargin_2 = c25_varargin_1;
  c25_varargin_3 = c25_varargin_2;
  c25_x = c25_b_varargin_2;
  c25_y = c25_varargin_3;
  c25_b_x = c25_x;
  c25_b_y = c25_y;
  c25_eml_scalar_eg(chartInstance);
  c25_dimagree(chartInstance);
  c25_xk = c25_b_x;
  c25_yk = c25_b_y;
  c25_c_x = c25_xk;
  c25_c_y = c25_yk;
  c25_eml_scalar_eg(chartInstance);
  c25_minval = muIntScalarMin_sint32(c25_c_x, c25_c_y);
  c25_d = c25_minval;
  c25_b = c25_d;
  c25_b_b = c25_b;
  c25_a = c25_b_b;
  c25_bi = c25_a;
  c25_c_b = c25_bi;
  c25_d_b = c25_c_b;
  c25_e_b = c25_d_b;
  if (c25_e_b < 1) {
    c25_d_n = 0;
  } else {
    c25_b_a = c25_e_b - 1;
    c25_c = c25_b_a;
    c25_c_a = c25_c;
    c25_span = c25_c_a;
    c25_d_a = c25_span;
    c25_nm1 = c25_d_a;
    c25_e_a = c25_nm1;
    c25_f_b = c25_e_a;
    c25_f_a = c25_f_b;
    c25_g_a = c25_f_a + 1;
    c25_d_n = c25_g_a;
  }

  c25_tmp_sizes[0] = 1;
  c25_iv9[0] = 1;
  c25_iv9[1] = c25_d_n;
  c25_tmp_sizes[1] = c25_iv9[1];
  c25_i197 = c25_tmp_sizes[0];
  c25_i198 = c25_tmp_sizes[1];
  c25_loop_ub = c25_d_n - 1;
  for (c25_i199 = 0; c25_i199 <= c25_loop_ub; c25_i199++) {
    c25_tmp_data[c25_i199] = 0;
  }

  for (c25_i200 = 0; c25_i200 < 2; c25_i200++) {
    c25_ipiv_sizes[c25_i200] = c25_tmp_sizes[c25_i200];
  }

  if (c25_d_n > 0) {
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_ipiv_sizes[1], 1, 0);
    c25_ipiv_data[0] = 1;
    c25_b_yk = 1;
    c25_e_n = c25_d_n;
    c25_g_b = c25_e_n;
    c25_h_b = c25_g_b;
    if (2 > c25_h_b) {
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
    }

    for (c25_k = 2; c25_k <= c25_e_n; c25_k++) {
      c25_b_k = c25_k;
      c25_h_a = c25_b_yk + 1;
      c25_b_yk = c25_h_a;
      c25_ipiv_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_k, 1, c25_ipiv_sizes[1],
        1, 0) - 1] = c25_b_yk;
    }
  }

  c25_info = 0;
  if (c25_c_m < 1) {
  } else if (c25_c_n < 1) {
  } else {
    c25_i_a = c25_c_lda;
    c25_j_a = c25_i_a + 1;
    c25_ldap1 = c25_j_a;
    c25_b_varargin_1 = c25_c_m;
    c25_c_varargin_2 = c25_c_n;
    c25_d_varargin_2 = c25_b_varargin_1 - 1;
    c25_b_varargin_3 = c25_c_varargin_2;
    c25_d_x = c25_d_varargin_2;
    c25_d_y = c25_b_varargin_3;
    c25_e_x = c25_d_x;
    c25_e_y = c25_d_y;
    c25_eml_scalar_eg(chartInstance);
    c25_dimagree(chartInstance);
    c25_b_xk = c25_e_x;
    c25_c_yk = c25_e_y;
    c25_f_x = c25_b_xk;
    c25_f_y = c25_c_yk;
    c25_eml_scalar_eg(chartInstance);
    c25_i201 = muIntScalarMin_sint32(c25_f_x, c25_f_y);
    c25_i_b = c25_i201;
    c25_j_b = c25_i_b;
    if (1 > c25_j_b) {
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
    }

    for (c25_j = 1; c25_j <= c25_i201; c25_j++) {
      c25_b_j = c25_j;
      c25_k_a = c25_b_j;
      c25_l_a = c25_k_a - 1;
      c25_jm1 = c25_l_a;
      c25_m_a = c25_c_m;
      c25_k_b = c25_b_j;
      c25_n_a = c25_m_a;
      c25_l_b = c25_k_b;
      c25_mmj = c25_n_a - c25_l_b;
      c25_o_a = c25_jm1;
      c25_m_b = c25_ldap1;
      c25_p_a = c25_o_a;
      c25_n_b = c25_m_b;
      c25_b_c = c25_p_a * c25_n_b;
      c25_o_b = c25_b_c;
      c25_p_b = c25_o_b + 1;
      c25_jj = c25_p_b;
      c25_q_a = c25_jj;
      c25_r_a = c25_q_a + 1;
      c25_jp1j = c25_r_a;
      c25_s_a = c25_mmj;
      c25_t_a = c25_s_a + 1;
      c25_c_c = c25_t_a;
      c25_b_A_sizes[0] = c25_A_sizes[0];
      c25_b_A_sizes[1] = c25_A_sizes[1];
      c25_A = c25_b_A_sizes[0];
      c25_b_A = c25_b_A_sizes[1];
      c25_b_loop_ub = c25_A_sizes[0] * c25_A_sizes[1] - 1;
      for (c25_i202 = 0; c25_i202 <= c25_b_loop_ub; c25_i202++) {
        c25_b_A_data[c25_i202] = c25_A_data[c25_i202];
      }

      c25_u_a = c25_eml_ixamax(chartInstance, c25_c_c, c25_b_A_data,
        c25_b_A_sizes, c25_jj);
      c25_v_a = c25_u_a - 1;
      c25_jpiv_offset = c25_v_a;
      c25_w_a = c25_jj;
      c25_q_b = c25_jpiv_offset;
      c25_x_a = c25_w_a;
      c25_r_b = c25_q_b;
      c25_jpiv = c25_x_a + c25_r_b;
      if (c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_jpiv, 1, c25_A_sizes[0]
           * c25_A_sizes[1], 1, 0) - 1] != 0.0) {
        if (c25_jpiv_offset != 0) {
          c25_y_a = c25_b_j;
          c25_s_b = c25_jpiv_offset;
          c25_ab_a = c25_y_a;
          c25_t_b = c25_s_b;
          c25_d_c = c25_ab_a + c25_t_b;
          c25_ipiv_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_j, 1,
            c25_ipiv_sizes[1], 1, 0) - 1] = c25_d_c;
          c25_u_b = c25_jm1;
          c25_v_b = c25_u_b + 1;
          c25_jrow = c25_v_b;
          c25_bb_a = c25_jrow;
          c25_w_b = c25_jpiv_offset;
          c25_cb_a = c25_bb_a;
          c25_x_b = c25_w_b;
          c25_jprow = c25_cb_a + c25_x_b;
          c25_f_n = c25_c_n;
          c25_ix0 = c25_jrow;
          c25_incx = c25_c_lda;
          c25_iy0 = c25_jprow;
          c25_incy = c25_c_lda;
          c25_g_n = c25_f_n;
          c25_b_ix0 = c25_ix0;
          c25_b_incx = c25_incx;
          c25_b_iy0 = c25_iy0;
          c25_b_incy = c25_incy;
          c25_h_n = c25_g_n;
          c25_c_ix0 = c25_b_ix0;
          c25_c_incx = c25_b_incx;
          c25_c_iy0 = c25_b_iy0;
          c25_c_incy = c25_b_incy;
          c25_ix = c25_c_ix0;
          c25_iy = c25_c_iy0;
          c25_g_x = c25_c_incx;
          c25_h_x = c25_g_x;
          c25_ixinc = c25_h_x;
          c25_i_x = c25_c_incy;
          c25_j_x = c25_i_x;
          c25_iyinc = c25_j_x;
          c25_i_n = c25_h_n;
          c25_y_b = c25_i_n;
          c25_ab_b = c25_y_b;
          if (1 > c25_ab_b) {
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
          }

          for (c25_c_k = 1; c25_c_k <= c25_i_n; c25_c_k++) {
            c25_temp = c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ix, 1,
              c25_A_sizes[0] * c25_A_sizes[1], 1, 0) - 1];
            c25_c_A[0] = c25_A_sizes[0] * c25_A_sizes[1];
            c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ix, 1, c25_A_sizes[0]
              * c25_A_sizes[1], 1, 0) - 1] =
              c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_iy, 1, c25_A_sizes
              [0] * c25_A_sizes[1], 1, 0) - 1];
            c25_d_A[0] = c25_A_sizes[0] * c25_A_sizes[1];
            c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_iy, 1, c25_A_sizes[0]
              * c25_A_sizes[1], 1, 0) - 1] = c25_temp;
            c25_db_a = c25_ix;
            c25_bb_b = c25_ixinc;
            c25_ix = c25_db_a + c25_bb_b;
            c25_eb_a = c25_iy;
            c25_cb_b = c25_iyinc;
            c25_iy = c25_eb_a + c25_cb_b;
          }
        }

        c25_b_jp1j = c25_jp1j;
        c25_fb_a = c25_mmj;
        c25_gb_a = c25_fb_a - 1;
        c25_e_c = c25_gb_a;
        c25_hb_a = c25_jp1j;
        c25_db_b = c25_e_c;
        c25_ib_a = c25_hb_a;
        c25_eb_b = c25_db_b;
        c25_i203 = c25_ib_a + c25_eb_b;
        c25_jb_a = c25_b_jp1j;
        c25_fb_b = c25_i203;
        c25_kb_a = c25_jb_a;
        c25_gb_b = c25_fb_b;
        if (c25_kb_a > c25_gb_b) {
          c25_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_overflow = (c25_gb_b > 2147483646);
        }

        if (c25_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_i = c25_b_jp1j; c25_i <= c25_i203; c25_i++) {
          c25_b_i = c25_i;
          c25_k_x = c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_i, 1,
            c25_A_sizes[0] * c25_A_sizes[1], 1, 0) - 1];
          c25_g_y = c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_jj, 1,
            c25_A_sizes[0] * c25_A_sizes[1], 1, 0) - 1];
          c25_l_x = c25_k_x;
          c25_h_y = c25_g_y;
          c25_z = c25_l_x / c25_h_y;
          c25_e_A[0] = c25_A_sizes[0] * c25_A_sizes[1];
          c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_i, 1, c25_A_sizes[0] *
            c25_A_sizes[1], 1, 0) - 1] = c25_z;
        }
      } else {
        c25_info = c25_b_j;
      }

      c25_lb_a = c25_c_n;
      c25_hb_b = c25_b_j;
      c25_mb_a = c25_lb_a;
      c25_ib_b = c25_hb_b;
      c25_f_c = c25_mb_a - c25_ib_b;
      c25_nb_a = c25_jj;
      c25_jb_b = c25_c_lda;
      c25_ob_a = c25_nb_a;
      c25_kb_b = c25_jb_b;
      c25_g_c = c25_ob_a + c25_kb_b;
      c25_pb_a = c25_jj;
      c25_lb_b = c25_ldap1;
      c25_qb_a = c25_pb_a;
      c25_mb_b = c25_lb_b;
      c25_h_c = c25_qb_a + c25_mb_b;
      c25_b_eml_xgeru(chartInstance, c25_mmj, c25_f_c, -1.0, c25_jp1j, c25_g_c,
                      c25_c_lda, c25_A_data, c25_A_sizes, c25_h_c, c25_c_lda);
    }

    if (c25_info == 0) {
      if (c25_c_m <= c25_c_n) {
        _SFD_EML_ARRAY_BOUNDS_CHECK("", c25_c_m, 1, c25_A_sizes[0], 1, 0);
        _SFD_EML_ARRAY_BOUNDS_CHECK("", c25_c_m, 1, c25_A_sizes[1], 2, 0);
      }
    }
  }
}

static void c25_b_eml_xgeru(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_alpha1, int32_T
  c25_ix0, int32_T c25_iy0, int32_T c25_incy, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_ia0, int32_T c25_lda)
{
  int32_T c25_b_m;
  int32_T c25_b_n;
  int32_T c25_b_ix0;
  int32_T c25_b_iy0;
  int32_T c25_b_incy;
  int32_T c25_b_ia0;
  int32_T c25_b_lda;
  int32_T c25_c_m;
  int32_T c25_c_n;
  int32_T c25_c_ix0;
  int32_T c25_c_iy0;
  int32_T c25_c_incy;
  int32_T c25_c_ia0;
  int32_T c25_c_lda;
  int32_T c25_d_m;
  int32_T c25_d_n;
  real_T c25_b_alpha1;
  int32_T c25_d_ix0;
  int32_T c25_d_iy0;
  int32_T c25_d_incy;
  int32_T c25_d_ia0;
  int32_T c25_d_lda;
  int32_T c25_var;
  ptrdiff_t c25_m_t;
  int32_T c25_b_var;
  ptrdiff_t c25_n_t;
  ptrdiff_t c25_incx_t;
  int32_T c25_c_var;
  ptrdiff_t c25_incy_t;
  int32_T c25_d_var;
  ptrdiff_t c25_lda_t;
  int32_T c25_A[1];
  int32_T c25_b_A[1];
  int32_T c25_c_A[1];
  (void)c25_alpha1;
  c25_b_m = c25_m;
  c25_b_n = c25_n;
  c25_b_ix0 = c25_ix0;
  c25_b_iy0 = c25_iy0;
  c25_b_incy = c25_incy;
  c25_b_ia0 = c25_ia0;
  c25_b_lda = c25_lda;
  c25_c_m = c25_b_m;
  c25_c_n = c25_b_n;
  c25_c_ix0 = c25_b_ix0;
  c25_c_iy0 = c25_b_iy0;
  c25_c_incy = c25_b_incy;
  c25_c_ia0 = c25_b_ia0;
  c25_c_lda = c25_b_lda;
  c25_below_threshold(chartInstance);
  if (c25_c_m < 1) {
  } else if (c25_c_n < 1) {
  } else {
    c25_d_m = c25_c_m;
    c25_d_n = c25_c_n;
    c25_b_alpha1 = -1.0;
    c25_d_ix0 = c25_c_ix0;
    c25_d_iy0 = c25_c_iy0;
    c25_d_incy = c25_c_incy;
    c25_d_ia0 = c25_c_ia0;
    c25_d_lda = c25_c_lda;
    c25_var = c25_d_m;
    c25_m_t = (ptrdiff_t)c25_var;
    c25_b_var = c25_d_n;
    c25_n_t = (ptrdiff_t)c25_b_var;
    c25_incx_t = (ptrdiff_t)1;
    c25_c_var = c25_d_incy;
    c25_incy_t = (ptrdiff_t)c25_c_var;
    c25_d_var = c25_d_lda;
    c25_lda_t = (ptrdiff_t)c25_d_var;
    c25_A[0] = c25_A_sizes[0] * c25_A_sizes[1];
    c25_b_A[0] = c25_A_sizes[0] * c25_A_sizes[1];
    c25_c_A[0] = c25_A_sizes[0] * c25_A_sizes[1];
    dger(&c25_m_t, &c25_n_t, &c25_b_alpha1,
         &c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_d_ix0, 1, c25_A_sizes[0]
          * c25_A_sizes[1], 1, 0) - 1], &c25_incx_t,
         &c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_d_iy0, 1, c25_A_sizes[0]
          * c25_A_sizes[1], 1, 0) - 1], &c25_incy_t,
         &c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_d_ia0, 1, c25_A_sizes[0]
          * c25_A_sizes[1], 1, 0) - 1], &c25_lda_t);
  }
}

static void c25_b_eml_xtrsm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes[2],
  int32_T c25_ldb)
{
  int32_T c25_b_m;
  int32_T c25_b_n;
  int32_T c25_b_lda;
  int32_T c25_b_ldb;
  int32_T c25_c_m;
  int32_T c25_c_n;
  real_T c25_alpha1;
  int32_T c25_c_lda;
  int32_T c25_c_ldb;
  char_T c25_DIAGA;
  char_T c25_TRANSA;
  char_T c25_UPLO;
  char_T c25_SIDE;
  int32_T c25_var;
  ptrdiff_t c25_m_t;
  int32_T c25_b_var;
  ptrdiff_t c25_n_t;
  int32_T c25_c_var;
  ptrdiff_t c25_lda_t;
  int32_T c25_d_var;
  ptrdiff_t c25_ldb_t;
  int32_T c25_B[1];
  (void)chartInstance;
  c25_b_m = c25_m;
  c25_b_n = c25_n;
  c25_b_lda = c25_lda;
  c25_b_ldb = c25_ldb;
  if (c25_b_m < 1) {
  } else if (c25_b_n < 1) {
  } else {
    c25_c_m = c25_b_m;
    c25_c_n = c25_b_n;
    c25_alpha1 = 1.0;
    c25_c_lda = c25_b_lda;
    c25_c_ldb = c25_b_ldb;
    c25_DIAGA = 'N';
    c25_TRANSA = 'N';
    c25_UPLO = 'U';
    c25_SIDE = 'L';
    c25_var = c25_c_m;
    c25_m_t = (ptrdiff_t)c25_var;
    c25_b_var = c25_c_n;
    c25_n_t = (ptrdiff_t)c25_b_var;
    c25_c_var = c25_c_lda;
    c25_lda_t = (ptrdiff_t)c25_c_var;
    c25_d_var = c25_c_ldb;
    c25_ldb_t = (ptrdiff_t)c25_d_var;
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_A_sizes[0] * c25_A_sizes[1], 1, 0);
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_B_sizes[0] * c25_B_sizes[1], 1, 0);
    c25_B[0] = c25_B_sizes[0] * c25_B_sizes[1];
    dtrsm(&c25_SIDE, &c25_UPLO, &c25_TRANSA, &c25_DIAGA, &c25_m_t, &c25_n_t,
          &c25_alpha1, &c25_A_data[0], &c25_lda_t, &c25_B_data[0], &c25_ldb_t);
  }
}

static void c25_h_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[], int32_T c25_B_sizes,
  int32_T c25_ldb, real_T c25_C_data[], int32_T *c25_C_sizes, int32_T c25_ldc)
{
  int32_T c25_b_m;
  int32_T c25_b_k;
  int32_T c25_b_lda;
  int32_T c25_b_ldb;
  int32_T c25_b_ldc;
  int32_T c25_c_m;
  int32_T c25_c_k;
  int32_T c25_c_lda;
  int32_T c25_c_ldb;
  int32_T c25_c_ldc;
  int32_T c25_lda1;
  int32_T c25_ldb1;
  int32_T c25_ldc1;
  int32_T c25_b_ldc1;
  int32_T c25_d;
  int32_T c25_b_d;
  boolean_T c25_overflow;
  int32_T c25_cr;
  int32_T c25_b_cr;
  int32_T c25_a;
  int32_T c25_i204;
  int32_T c25_b_a;
  int32_T c25_b;
  int32_T c25_i205;
  int32_T c25_c_a;
  int32_T c25_b_b;
  int32_T c25_d_a;
  int32_T c25_c_b;
  boolean_T c25_b_overflow;
  int32_T c25_ic;
  int32_T c25_b_ic;
  int32_T c25_br;
  int32_T c25_c_ldc1;
  int32_T c25_c_d;
  int32_T c25_d_d;
  boolean_T c25_c_overflow;
  int32_T c25_c_cr;
  int32_T c25_ar;
  int32_T c25_e_a;
  int32_T c25_i206;
  int32_T c25_f_a;
  int32_T c25_d_b;
  int32_T c25_i207;
  int32_T c25_g_a;
  int32_T c25_e_b;
  int32_T c25_h_a;
  int32_T c25_f_b;
  boolean_T c25_d_overflow;
  int32_T c25_ib;
  int32_T c25_b_ib;
  real_T c25_temp;
  int32_T c25_ia;
  int32_T c25_i_a;
  int32_T c25_i208;
  int32_T c25_j_a;
  int32_T c25_g_b;
  int32_T c25_i209;
  int32_T c25_k_a;
  int32_T c25_h_b;
  int32_T c25_l_a;
  int32_T c25_i_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_ic;
  int32_T c25_m_a;
  int32_T c25_n_a;
  int32_T c25_j_b;
  int32_T c25_o_a;
  int32_T c25_k_b;
  int32_T c25_d_m;
  int32_T c25_d_k;
  real_T c25_alpha1;
  int32_T c25_d_lda;
  int32_T c25_d_ldb;
  real_T c25_beta1;
  int32_T c25_d_ldc;
  char_T c25_TRANSB;
  char_T c25_TRANSA;
  int32_T c25_var;
  ptrdiff_t c25_m_t;
  ptrdiff_t c25_n_t;
  int32_T c25_b_var;
  ptrdiff_t c25_k_t;
  int32_T c25_c_var;
  ptrdiff_t c25_lda_t;
  int32_T c25_d_var;
  ptrdiff_t c25_ldb_t;
  int32_T c25_e_var;
  ptrdiff_t c25_ldc_t;
  c25_b_m = c25_m;
  c25_b_k = c25_k;
  c25_b_lda = c25_lda;
  c25_b_ldb = c25_ldb;
  c25_b_ldc = c25_ldc;
  if (c25_use_refblas(chartInstance)) {
    c25_b_scalarEg(chartInstance);
    c25_b_scalarEg(chartInstance);
    c25_c_m = c25_b_m;
    c25_c_k = c25_b_k;
    c25_c_lda = c25_b_lda;
    c25_c_ldb = c25_b_ldb;
    c25_c_ldc = c25_b_ldc;
    if (c25_c_m == 0) {
    } else {
      c25_lda1 = c25_c_lda;
      c25_ldb1 = c25_c_ldb;
      c25_ldc1 = c25_c_ldc;
      c25_b_ldc1 = c25_ldc1;
      c25_d = c25_b_ldc1;
      c25_b_d = c25_d;
      if (c25_b_d == 0) {
        c25_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = (0 > MAX_int32_T - c25_b_d);
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      c25_cr = 0;
      while ((c25_b_ldc1 > 0) && (c25_cr <= 0)) {
        c25_b_cr = c25_cr;
        c25_a = c25_b_cr + 1;
        c25_i204 = c25_a;
        c25_b_a = c25_b_cr;
        c25_b = c25_c_m;
        c25_i205 = c25_b_a + c25_b;
        c25_c_a = c25_i204;
        c25_b_b = c25_i205;
        c25_d_a = c25_c_a;
        c25_c_b = c25_b_b;
        if (c25_d_a > c25_c_b) {
          c25_b_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_b_overflow = (c25_c_b > 2147483646);
        }

        if (c25_b_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ic = c25_i204; c25_ic <= c25_i205; c25_ic++) {
          c25_b_ic = c25_ic;
          c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, *c25_C_sizes,
            1, 0) - 1] = 0.0;
        }

        c25_cr += c25_b_ldc1;
      }

      c25_br = 0;
      c25_c_ldc1 = c25_ldc1;
      c25_c_d = c25_c_ldc1;
      c25_d_d = c25_c_d;
      if (c25_d_d == 0) {
        c25_c_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_c_overflow = (0 > MAX_int32_T - c25_d_d);
      }

      if (c25_c_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      c25_c_cr = 0;
      while ((c25_c_ldc1 > 0) && (c25_c_cr <= 0)) {
        c25_b_cr = c25_c_cr;
        c25_ar = 0;
        c25_e_a = c25_br + 1;
        c25_i206 = c25_e_a;
        c25_f_a = c25_br;
        c25_d_b = c25_c_k;
        c25_i207 = c25_f_a + c25_d_b;
        c25_g_a = c25_i206;
        c25_e_b = c25_i207;
        c25_h_a = c25_g_a;
        c25_f_b = c25_e_b;
        if (c25_h_a > c25_f_b) {
          c25_d_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_d_overflow = (c25_f_b > 2147483646);
        }

        if (c25_d_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ib = c25_i206; c25_ib <= c25_i207; c25_ib++) {
          c25_b_ib = c25_ib;
          if (c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
               c25_B_sizes, 1, 0) - 1] != 0.0) {
            c25_temp = c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
              c25_B_sizes, 1, 0) - 1];
            c25_ia = c25_ar;
            c25_i_a = c25_b_cr + 1;
            c25_i208 = c25_i_a;
            c25_j_a = c25_b_cr;
            c25_g_b = c25_c_m;
            c25_i209 = c25_j_a + c25_g_b;
            c25_k_a = c25_i208;
            c25_h_b = c25_i209;
            c25_l_a = c25_k_a;
            c25_i_b = c25_h_b;
            if (c25_l_a > c25_i_b) {
              c25_e_overflow = false;
            } else {
              c25_eml_switch_helper(chartInstance);
              c25_eml_switch_helper(chartInstance);
              c25_e_overflow = (c25_i_b > 2147483646);
            }

            if (c25_e_overflow) {
              c25_check_forloop_overflow_error(chartInstance, true);
            }

            for (c25_c_ic = c25_i208; c25_c_ic <= c25_i209; c25_c_ic++) {
              c25_b_ic = c25_c_ic;
              c25_m_a = c25_ia + 1;
              c25_ia = c25_m_a;
              c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1,
                *c25_C_sizes, 1, 0) - 1] =
                c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1,
                *c25_C_sizes, 1, 0) - 1] + c25_temp *
                c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ia, 1,
                c25_A_sizes[0] * c25_A_sizes[1], 1, 0) - 1];
            }
          }

          c25_n_a = c25_ar;
          c25_j_b = c25_lda1;
          c25_ar = c25_n_a + c25_j_b;
        }

        c25_o_a = c25_br;
        c25_k_b = c25_ldb1;
        c25_br = c25_o_a + c25_k_b;
        c25_c_cr += c25_c_ldc1;
      }
    }
  } else {
    c25_b_below_threshold(chartInstance);
    if (c25_b_m < 1) {
    } else if (c25_b_k < 1) {
    } else {
      c25_d_m = c25_b_m;
      c25_d_k = c25_b_k;
      c25_alpha1 = 1.0;
      c25_d_lda = c25_b_lda;
      c25_d_ldb = c25_b_ldb;
      c25_beta1 = 0.0;
      c25_d_ldc = c25_b_ldc;
      c25_TRANSB = 'N';
      c25_TRANSA = 'N';
      c25_var = c25_d_m;
      c25_m_t = (ptrdiff_t)c25_var;
      c25_n_t = (ptrdiff_t)1;
      c25_b_var = c25_d_k;
      c25_k_t = (ptrdiff_t)c25_b_var;
      c25_c_var = c25_d_lda;
      c25_lda_t = (ptrdiff_t)c25_c_var;
      c25_d_var = c25_d_ldb;
      c25_ldb_t = (ptrdiff_t)c25_d_var;
      c25_e_var = c25_d_ldc;
      c25_ldc_t = (ptrdiff_t)c25_e_var;
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_A_sizes[0] * c25_A_sizes[1], 1,
        0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_B_sizes, 1, 0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, *c25_C_sizes, 1, 0);
      dgemm(&c25_TRANSA, &c25_TRANSB, &c25_m_t, &c25_n_t, &c25_k_t, &c25_alpha1,
            &c25_A_data[0], &c25_lda_t, &c25_B_data[0], &c25_ldb_t, &c25_beta1,
            &c25_C_data[0], &c25_ldc_t);
    }
  }
}

static void c25_i_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, real_T c25_A[324], real_T c25_B_data[], int32_T
  c25_B_sizes[2], real_T c25_C_data[], int32_T c25_C_sizes[2])
{
  int32_T c25_b_n;
  int32_T c25_c_n;
  int32_T c25_a;
  int32_T c25_nm1;
  int32_T c25_b;
  int32_T c25_c;
  int32_T c25_b_b;
  int32_T c25_lastColC;
  int32_T c25_b_lastColC;
  int32_T c25_c_b;
  int32_T c25_d_b;
  boolean_T c25_overflow;
  int32_T c25_cr;
  int32_T c25_b_cr;
  int32_T c25_b_a;
  int32_T c25_i210;
  int32_T c25_c_a;
  int32_T c25_i211;
  int32_T c25_d_a;
  int32_T c25_e_b;
  int32_T c25_e_a;
  int32_T c25_f_b;
  boolean_T c25_b_overflow;
  int32_T c25_ic;
  int32_T c25_b_ic;
  int32_T c25_iv10[1];
  int32_T c25_br;
  int32_T c25_c_lastColC;
  int32_T c25_g_b;
  int32_T c25_h_b;
  boolean_T c25_c_overflow;
  int32_T c25_c_cr;
  int32_T c25_ar;
  int32_T c25_f_a;
  int32_T c25_i212;
  int32_T c25_g_a;
  int32_T c25_i213;
  int32_T c25_h_a;
  int32_T c25_i_b;
  int32_T c25_i_a;
  int32_T c25_j_b;
  boolean_T c25_d_overflow;
  int32_T c25_ib;
  int32_T c25_b_ib;
  real_T c25_temp;
  int32_T c25_ia;
  int32_T c25_j_a;
  int32_T c25_i214;
  int32_T c25_k_a;
  int32_T c25_i215;
  int32_T c25_l_a;
  int32_T c25_k_b;
  int32_T c25_m_a;
  int32_T c25_l_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_ic;
  int32_T c25_n_a;
  int32_T c25_iv11[1];
  int32_T c25_o_a;
  int32_T c25_p_a;
  int32_T c25_d_n;
  real_T c25_alpha1;
  real_T c25_beta1;
  char_T c25_TRANSB;
  char_T c25_TRANSA;
  ptrdiff_t c25_m_t;
  int32_T c25_var;
  ptrdiff_t c25_n_t;
  ptrdiff_t c25_k_t;
  ptrdiff_t c25_lda_t;
  ptrdiff_t c25_ldb_t;
  ptrdiff_t c25_ldc_t;
  int32_T c25_iv12[1];
  c25_b_n = c25_n;
  if (c25_use_refblas(chartInstance)) {
    c25_c_scalarEg(chartInstance);
    c25_c_scalarEg(chartInstance);
    c25_c_n = c25_b_n;
    if (c25_c_n == 0) {
    } else {
      c25_a = c25_c_n;
      c25_nm1 = c25_a;
      c25_b = c25_nm1 - 1;
      c25_c = 18 * c25_b;
      c25_b_b = c25_c;
      c25_lastColC = c25_b_b;
      c25_b_lastColC = c25_lastColC;
      c25_c_b = c25_b_lastColC;
      c25_d_b = c25_c_b;
      if (0 > c25_d_b) {
        c25_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = (c25_d_b > 2147483629);
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      for (c25_cr = 0; c25_cr <= c25_b_lastColC; c25_cr += 18) {
        c25_b_cr = c25_cr;
        c25_b_a = c25_b_cr + 1;
        c25_i210 = c25_b_a;
        c25_c_a = c25_b_cr + 18;
        c25_i211 = c25_c_a;
        c25_d_a = c25_i210;
        c25_e_b = c25_i211;
        c25_e_a = c25_d_a;
        c25_f_b = c25_e_b;
        if (c25_e_a > c25_f_b) {
          c25_b_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_b_overflow = (c25_f_b > 2147483646);
        }

        if (c25_b_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ic = c25_i210; c25_ic <= c25_i211; c25_ic++) {
          c25_b_ic = c25_ic;
          c25_iv10[0] = 18 * c25_C_sizes[1];
          c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 18 *
            c25_C_sizes[1], 1, 0) - 1] = 0.0;
        }
      }

      c25_br = 0;
      c25_c_lastColC = c25_lastColC;
      c25_g_b = c25_c_lastColC;
      c25_h_b = c25_g_b;
      if (0 > c25_h_b) {
        c25_c_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_c_overflow = (c25_h_b > 2147483629);
      }

      if (c25_c_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      for (c25_c_cr = 0; c25_c_cr <= c25_c_lastColC; c25_c_cr += 18) {
        c25_b_cr = c25_c_cr;
        c25_ar = 0;
        c25_f_a = c25_br + 1;
        c25_i212 = c25_f_a;
        c25_g_a = c25_br + 18;
        c25_i213 = c25_g_a;
        c25_h_a = c25_i212;
        c25_i_b = c25_i213;
        c25_i_a = c25_h_a;
        c25_j_b = c25_i_b;
        if (c25_i_a > c25_j_b) {
          c25_d_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_d_overflow = (c25_j_b > 2147483646);
        }

        if (c25_d_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ib = c25_i212; c25_ib <= c25_i213; c25_ib++) {
          c25_b_ib = c25_ib;
          if (c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
               c25_B_sizes[0] * c25_B_sizes[1], 1, 0) - 1] != 0.0) {
            c25_temp = c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
              c25_B_sizes[0] * c25_B_sizes[1], 1, 0) - 1];
            c25_ia = c25_ar;
            c25_j_a = c25_b_cr + 1;
            c25_i214 = c25_j_a;
            c25_k_a = c25_b_cr + 18;
            c25_i215 = c25_k_a;
            c25_l_a = c25_i214;
            c25_k_b = c25_i215;
            c25_m_a = c25_l_a;
            c25_l_b = c25_k_b;
            if (c25_m_a > c25_l_b) {
              c25_e_overflow = false;
            } else {
              c25_eml_switch_helper(chartInstance);
              c25_eml_switch_helper(chartInstance);
              c25_e_overflow = (c25_l_b > 2147483646);
            }

            if (c25_e_overflow) {
              c25_check_forloop_overflow_error(chartInstance, true);
            }

            for (c25_c_ic = c25_i214; c25_c_ic <= c25_i215; c25_c_ic++) {
              c25_b_ic = c25_c_ic;
              c25_n_a = c25_ia + 1;
              c25_ia = c25_n_a;
              c25_iv11[0] = 18 * c25_C_sizes[1];
              c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 18 *
                c25_C_sizes[1], 1, 0) - 1] =
                c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 18 *
                c25_C_sizes[1], 1, 0) - 1] + c25_temp *
                c25_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ia, 1, 324, 1, 0) - 1];
            }
          }

          c25_o_a = c25_ar + 18;
          c25_ar = c25_o_a;
        }

        c25_p_a = c25_br + 18;
        c25_br = c25_p_a;
      }
    }
  } else {
    c25_c_below_threshold(chartInstance);
    if (c25_b_n < 1) {
    } else {
      c25_d_n = c25_b_n;
      c25_alpha1 = 1.0;
      c25_beta1 = 0.0;
      c25_TRANSB = 'N';
      c25_TRANSA = 'N';
      c25_m_t = (ptrdiff_t)18;
      c25_var = c25_d_n;
      c25_n_t = (ptrdiff_t)c25_var;
      c25_k_t = (ptrdiff_t)18;
      c25_lda_t = (ptrdiff_t)18;
      c25_ldb_t = (ptrdiff_t)18;
      c25_ldc_t = (ptrdiff_t)18;
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_B_sizes[0] * c25_B_sizes[1], 1,
        0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, 18 * c25_C_sizes[1], 1, 0);
      c25_iv12[0] = 18 * c25_C_sizes[1];
      dgemm(&c25_TRANSA, &c25_TRANSB, &c25_m_t, &c25_n_t, &c25_k_t, &c25_alpha1,
            &c25_A[0], &c25_lda_t, &c25_B_data[0], &c25_ldb_t, &c25_beta1,
            &c25_C_data[0], &c25_ldc_t);
    }
  }
}

static void c25_j_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[6], int32_T c25_ldb, real_T c25_C[18])
{
  int32_T c25_b_k;
  int32_T c25_b_ldb;
  int32_T c25_c_k;
  int32_T c25_ic;
  int32_T c25_b_ic;
  int32_T c25_ar;
  int32_T c25_b;
  int32_T c25_i216;
  int32_T c25_b_b;
  int32_T c25_c_b;
  boolean_T c25_overflow;
  int32_T c25_ib;
  int32_T c25_b_ib;
  real_T c25_temp;
  int32_T c25_ia;
  int32_T c25_c_ic;
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_d_k;
  real_T c25_alpha1;
  int32_T c25_c_ldb;
  real_T c25_beta1;
  char_T c25_TRANSB;
  char_T c25_TRANSA;
  ptrdiff_t c25_m_t;
  ptrdiff_t c25_n_t;
  int32_T c25_var;
  ptrdiff_t c25_k_t;
  ptrdiff_t c25_lda_t;
  int32_T c25_b_var;
  ptrdiff_t c25_ldb_t;
  ptrdiff_t c25_ldc_t;
  c25_b_k = c25_k;
  c25_b_ldb = c25_ldb;
  if (c25_use_refblas(chartInstance)) {
    c25_e_scalarEg(chartInstance);
    c25_e_scalarEg(chartInstance);
    c25_c_k = c25_b_k;
    c25_eml_switch_helper(chartInstance);
    for (c25_ic = 1; c25_ic < 19; c25_ic++) {
      c25_b_ic = c25_ic - 1;
      c25_C[c25_b_ic] = 0.0;
    }

    c25_ar = 0;
    c25_b = c25_c_k;
    c25_i216 = c25_b;
    c25_b_b = c25_i216;
    c25_c_b = c25_b_b;
    if (1 > c25_c_b) {
      c25_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_overflow = (c25_c_b > 2147483646);
    }

    if (c25_overflow) {
      c25_check_forloop_overflow_error(chartInstance, true);
    }

    for (c25_ib = 1; c25_ib <= c25_i216; c25_ib++) {
      c25_b_ib = c25_ib;
      if (c25_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1, 6, 1, 0) - 1] !=
          0.0) {
        c25_temp = c25_B[c25_b_ib - 1];
        c25_ia = c25_ar;
        c25_eml_switch_helper(chartInstance);
        for (c25_c_ic = 1; c25_c_ic < 19; c25_c_ic++) {
          c25_b_ic = c25_c_ic - 1;
          c25_a = c25_ia + 1;
          c25_ia = c25_a;
          c25_C[c25_b_ic] += c25_temp * c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", c25_ia, 1, 18 * c25_A_sizes[1], 1, 0) - 1];
        }
      }

      c25_b_a = c25_ar + 18;
      c25_ar = c25_b_a;
    }
  } else {
    c25_d_below_threshold(chartInstance);
    if (c25_b_k < 1) {
    } else {
      c25_d_k = c25_b_k;
      c25_alpha1 = 1.0;
      c25_c_ldb = c25_b_ldb;
      c25_beta1 = 0.0;
      c25_TRANSB = 'N';
      c25_TRANSA = 'N';
      c25_m_t = (ptrdiff_t)18;
      c25_n_t = (ptrdiff_t)1;
      c25_var = c25_d_k;
      c25_k_t = (ptrdiff_t)c25_var;
      c25_lda_t = (ptrdiff_t)18;
      c25_b_var = c25_c_ldb;
      c25_ldb_t = (ptrdiff_t)c25_b_var;
      c25_ldc_t = (ptrdiff_t)18;
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, 18 * c25_A_sizes[1], 1, 0);
      dgemm(&c25_TRANSA, &c25_TRANSB, &c25_m_t, &c25_n_t, &c25_k_t, &c25_alpha1,
            &c25_A_data[0], &c25_lda_t, &c25_B[0], &c25_ldb_t, &c25_beta1,
            &c25_C[0], &c25_ldc_t);
    }
  }
}

static void c25_k_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_n, int32_T c25_k, real_T c25_A_data[], int32_T
  c25_A_sizes[2], real_T c25_B_data[], int32_T c25_B_sizes[2], int32_T c25_ldb,
  real_T c25_C_data[], int32_T c25_C_sizes[2])
{
  int32_T c25_b_n;
  int32_T c25_b_k;
  int32_T c25_b_ldb;
  int32_T c25_c_n;
  int32_T c25_c_k;
  int32_T c25_c_ldb;
  int32_T c25_ldb1;
  int32_T c25_a;
  int32_T c25_nm1;
  int32_T c25_b;
  int32_T c25_c;
  int32_T c25_b_b;
  int32_T c25_lastColC;
  int32_T c25_b_lastColC;
  int32_T c25_c_b;
  int32_T c25_d_b;
  boolean_T c25_overflow;
  int32_T c25_cr;
  int32_T c25_b_cr;
  int32_T c25_b_a;
  int32_T c25_i217;
  int32_T c25_c_a;
  int32_T c25_i218;
  int32_T c25_d_a;
  int32_T c25_e_b;
  int32_T c25_e_a;
  int32_T c25_f_b;
  boolean_T c25_b_overflow;
  int32_T c25_ic;
  int32_T c25_b_ic;
  int32_T c25_iv13[1];
  int32_T c25_br;
  int32_T c25_c_lastColC;
  int32_T c25_g_b;
  int32_T c25_h_b;
  boolean_T c25_c_overflow;
  int32_T c25_c_cr;
  int32_T c25_ar;
  int32_T c25_f_a;
  int32_T c25_i219;
  int32_T c25_g_a;
  int32_T c25_i_b;
  int32_T c25_i220;
  int32_T c25_h_a;
  int32_T c25_j_b;
  int32_T c25_i_a;
  int32_T c25_k_b;
  boolean_T c25_d_overflow;
  int32_T c25_ib;
  int32_T c25_b_ib;
  real_T c25_temp;
  int32_T c25_ia;
  int32_T c25_j_a;
  int32_T c25_i221;
  int32_T c25_k_a;
  int32_T c25_i222;
  int32_T c25_l_a;
  int32_T c25_l_b;
  int32_T c25_m_a;
  int32_T c25_m_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_ic;
  int32_T c25_n_a;
  int32_T c25_iv14[1];
  int32_T c25_o_a;
  int32_T c25_p_a;
  int32_T c25_n_b;
  int32_T c25_d_n;
  int32_T c25_d_k;
  real_T c25_alpha1;
  int32_T c25_d_ldb;
  real_T c25_beta1;
  char_T c25_TRANSB;
  char_T c25_TRANSA;
  ptrdiff_t c25_m_t;
  int32_T c25_var;
  ptrdiff_t c25_n_t;
  int32_T c25_b_var;
  ptrdiff_t c25_k_t;
  ptrdiff_t c25_lda_t;
  int32_T c25_c_var;
  ptrdiff_t c25_ldb_t;
  ptrdiff_t c25_ldc_t;
  int32_T c25_iv15[1];
  c25_b_n = c25_n;
  c25_b_k = c25_k;
  c25_b_ldb = c25_ldb;
  if (c25_use_refblas(chartInstance)) {
    c25_c_scalarEg(chartInstance);
    c25_c_scalarEg(chartInstance);
    c25_c_n = c25_b_n;
    c25_c_k = c25_b_k;
    c25_c_ldb = c25_b_ldb;
    if (c25_c_n == 0) {
    } else {
      c25_ldb1 = c25_c_ldb;
      c25_a = c25_c_n;
      c25_nm1 = c25_a;
      c25_b = c25_nm1 - 1;
      c25_c = 18 * c25_b;
      c25_b_b = c25_c;
      c25_lastColC = c25_b_b;
      c25_b_lastColC = c25_lastColC;
      c25_c_b = c25_b_lastColC;
      c25_d_b = c25_c_b;
      if (0 > c25_d_b) {
        c25_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = (c25_d_b > 2147483629);
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      for (c25_cr = 0; c25_cr <= c25_b_lastColC; c25_cr += 18) {
        c25_b_cr = c25_cr;
        c25_b_a = c25_b_cr + 1;
        c25_i217 = c25_b_a;
        c25_c_a = c25_b_cr + 18;
        c25_i218 = c25_c_a;
        c25_d_a = c25_i217;
        c25_e_b = c25_i218;
        c25_e_a = c25_d_a;
        c25_f_b = c25_e_b;
        if (c25_e_a > c25_f_b) {
          c25_b_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_b_overflow = (c25_f_b > 2147483646);
        }

        if (c25_b_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ic = c25_i217; c25_ic <= c25_i218; c25_ic++) {
          c25_b_ic = c25_ic;
          c25_iv13[0] = 18 * c25_C_sizes[1];
          c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 18 *
            c25_C_sizes[1], 1, 0) - 1] = 0.0;
        }
      }

      c25_br = 0;
      c25_c_lastColC = c25_lastColC;
      c25_g_b = c25_c_lastColC;
      c25_h_b = c25_g_b;
      if (0 > c25_h_b) {
        c25_c_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_c_overflow = (c25_h_b > 2147483629);
      }

      if (c25_c_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      for (c25_c_cr = 0; c25_c_cr <= c25_c_lastColC; c25_c_cr += 18) {
        c25_b_cr = c25_c_cr;
        c25_ar = 0;
        c25_f_a = c25_br + 1;
        c25_i219 = c25_f_a;
        c25_g_a = c25_br;
        c25_i_b = c25_c_k;
        c25_i220 = c25_g_a + c25_i_b;
        c25_h_a = c25_i219;
        c25_j_b = c25_i220;
        c25_i_a = c25_h_a;
        c25_k_b = c25_j_b;
        if (c25_i_a > c25_k_b) {
          c25_d_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_d_overflow = (c25_k_b > 2147483646);
        }

        if (c25_d_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ib = c25_i219; c25_ib <= c25_i220; c25_ib++) {
          c25_b_ib = c25_ib;
          if (c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
               c25_B_sizes[0] * c25_B_sizes[1], 1, 0) - 1] != 0.0) {
            c25_temp = c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
              c25_B_sizes[0] * c25_B_sizes[1], 1, 0) - 1];
            c25_ia = c25_ar;
            c25_j_a = c25_b_cr + 1;
            c25_i221 = c25_j_a;
            c25_k_a = c25_b_cr + 18;
            c25_i222 = c25_k_a;
            c25_l_a = c25_i221;
            c25_l_b = c25_i222;
            c25_m_a = c25_l_a;
            c25_m_b = c25_l_b;
            if (c25_m_a > c25_m_b) {
              c25_e_overflow = false;
            } else {
              c25_eml_switch_helper(chartInstance);
              c25_eml_switch_helper(chartInstance);
              c25_e_overflow = (c25_m_b > 2147483646);
            }

            if (c25_e_overflow) {
              c25_check_forloop_overflow_error(chartInstance, true);
            }

            for (c25_c_ic = c25_i221; c25_c_ic <= c25_i222; c25_c_ic++) {
              c25_b_ic = c25_c_ic;
              c25_n_a = c25_ia + 1;
              c25_ia = c25_n_a;
              c25_iv14[0] = 18 * c25_C_sizes[1];
              c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 18 *
                c25_C_sizes[1], 1, 0) - 1] =
                c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 18 *
                c25_C_sizes[1], 1, 0) - 1] + c25_temp *
                c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ia, 1, 18 *
                c25_A_sizes[1], 1, 0) - 1];
            }
          }

          c25_o_a = c25_ar + 18;
          c25_ar = c25_o_a;
        }

        c25_p_a = c25_br;
        c25_n_b = c25_ldb1;
        c25_br = c25_p_a + c25_n_b;
      }
    }
  } else {
    c25_e_below_threshold(chartInstance);
    if (c25_b_n < 1) {
    } else if (c25_b_k < 1) {
    } else {
      c25_d_n = c25_b_n;
      c25_d_k = c25_b_k;
      c25_alpha1 = 1.0;
      c25_d_ldb = c25_b_ldb;
      c25_beta1 = 0.0;
      c25_TRANSB = 'N';
      c25_TRANSA = 'N';
      c25_m_t = (ptrdiff_t)18;
      c25_var = c25_d_n;
      c25_n_t = (ptrdiff_t)c25_var;
      c25_b_var = c25_d_k;
      c25_k_t = (ptrdiff_t)c25_b_var;
      c25_lda_t = (ptrdiff_t)18;
      c25_c_var = c25_d_ldb;
      c25_ldb_t = (ptrdiff_t)c25_c_var;
      c25_ldc_t = (ptrdiff_t)18;
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, 18 * c25_A_sizes[1], 1, 0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_B_sizes[0] * c25_B_sizes[1], 1,
        0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, 18 * c25_C_sizes[1], 1, 0);
      c25_iv15[0] = 18 * c25_C_sizes[1];
      dgemm(&c25_TRANSA, &c25_TRANSB, &c25_m_t, &c25_n_t, &c25_k_t, &c25_alpha1,
            &c25_A_data[0], &c25_lda_t, &c25_B_data[0], &c25_ldb_t, &c25_beta1,
            &c25_C_data[0], &c25_ldc_t);
    }
  }
}

static void c25_l_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_k, real_T c25_A_data[], int32_T c25_A_sizes[2],
  real_T c25_B[324], int32_T c25_ldb, real_T c25_C[324])
{
  int32_T c25_b_k;
  int32_T c25_b_ldb;
  int32_T c25_c_k;
  int32_T c25_c_ldb;
  int32_T c25_ldb1;
  int32_T c25_cr;
  int32_T c25_b_cr;
  int32_T c25_a;
  int32_T c25_i223;
  int32_T c25_b_a;
  int32_T c25_i224;
  int32_T c25_c_a;
  int32_T c25_b;
  int32_T c25_d_a;
  int32_T c25_b_b;
  boolean_T c25_overflow;
  int32_T c25_ic;
  int32_T c25_b_ic;
  int32_T c25_br;
  int32_T c25_c_cr;
  int32_T c25_ar;
  int32_T c25_e_a;
  int32_T c25_i225;
  int32_T c25_f_a;
  int32_T c25_c_b;
  int32_T c25_i226;
  int32_T c25_g_a;
  int32_T c25_d_b;
  int32_T c25_h_a;
  int32_T c25_e_b;
  boolean_T c25_b_overflow;
  int32_T c25_ib;
  int32_T c25_b_ib;
  real_T c25_temp;
  int32_T c25_ia;
  int32_T c25_i_a;
  int32_T c25_i227;
  int32_T c25_j_a;
  int32_T c25_i228;
  int32_T c25_k_a;
  int32_T c25_f_b;
  int32_T c25_l_a;
  int32_T c25_g_b;
  boolean_T c25_c_overflow;
  int32_T c25_c_ic;
  int32_T c25_m_a;
  int32_T c25_n_a;
  int32_T c25_o_a;
  int32_T c25_h_b;
  int32_T c25_d_k;
  real_T c25_alpha1;
  int32_T c25_d_ldb;
  real_T c25_beta1;
  char_T c25_TRANSB;
  char_T c25_TRANSA;
  ptrdiff_t c25_m_t;
  ptrdiff_t c25_n_t;
  int32_T c25_var;
  ptrdiff_t c25_k_t;
  ptrdiff_t c25_lda_t;
  int32_T c25_b_var;
  ptrdiff_t c25_ldb_t;
  ptrdiff_t c25_ldc_t;
  c25_b_k = c25_k;
  c25_b_ldb = c25_ldb;
  if (c25_use_refblas(chartInstance)) {
    c25_d_scalarEg(chartInstance);
    c25_d_scalarEg(chartInstance);
    c25_c_k = c25_b_k;
    c25_c_ldb = c25_b_ldb;
    c25_ldb1 = c25_c_ldb;
    c25_eml_switch_helper(chartInstance);
    for (c25_cr = 0; c25_cr < 307; c25_cr += 18) {
      c25_b_cr = c25_cr;
      c25_a = c25_b_cr + 1;
      c25_i223 = c25_a;
      c25_b_a = c25_b_cr + 18;
      c25_i224 = c25_b_a;
      c25_c_a = c25_i223;
      c25_b = c25_i224;
      c25_d_a = c25_c_a;
      c25_b_b = c25_b;
      if (c25_d_a > c25_b_b) {
        c25_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = (c25_b_b > 2147483646);
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      for (c25_ic = c25_i223; c25_ic <= c25_i224; c25_ic++) {
        c25_b_ic = c25_ic;
        c25_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 324, 1, 0) - 1] = 0.0;
      }
    }

    c25_br = 0;
    c25_eml_switch_helper(chartInstance);
    for (c25_c_cr = 0; c25_c_cr < 307; c25_c_cr += 18) {
      c25_b_cr = c25_c_cr;
      c25_ar = 0;
      c25_e_a = c25_br + 1;
      c25_i225 = c25_e_a;
      c25_f_a = c25_br;
      c25_c_b = c25_c_k;
      c25_i226 = c25_f_a + c25_c_b;
      c25_g_a = c25_i225;
      c25_d_b = c25_i226;
      c25_h_a = c25_g_a;
      c25_e_b = c25_d_b;
      if (c25_h_a > c25_e_b) {
        c25_b_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_b_overflow = (c25_e_b > 2147483646);
      }

      if (c25_b_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      for (c25_ib = c25_i225; c25_ib <= c25_i226; c25_ib++) {
        c25_b_ib = c25_ib;
        if (c25_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1, 324, 1, 0) - 1]
            != 0.0) {
          c25_temp = c25_B[c25_b_ib - 1];
          c25_ia = c25_ar;
          c25_i_a = c25_b_cr + 1;
          c25_i227 = c25_i_a;
          c25_j_a = c25_b_cr + 18;
          c25_i228 = c25_j_a;
          c25_k_a = c25_i227;
          c25_f_b = c25_i228;
          c25_l_a = c25_k_a;
          c25_g_b = c25_f_b;
          if (c25_l_a > c25_g_b) {
            c25_c_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_c_overflow = (c25_g_b > 2147483646);
          }

          if (c25_c_overflow) {
            c25_check_forloop_overflow_error(chartInstance, true);
          }

          for (c25_c_ic = c25_i227; c25_c_ic <= c25_i228; c25_c_ic++) {
            c25_b_ic = c25_c_ic;
            c25_m_a = c25_ia + 1;
            c25_ia = c25_m_a;
            c25_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 324, 1, 0) - 1] =
              c25_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, 324, 1, 0) - 1]
              + c25_temp * c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ia, 1,
              18 * c25_A_sizes[1], 1, 0) - 1];
          }
        }

        c25_n_a = c25_ar + 18;
        c25_ar = c25_n_a;
      }

      c25_o_a = c25_br;
      c25_h_b = c25_ldb1;
      c25_br = c25_o_a + c25_h_b;
    }
  } else {
    c25_f_below_threshold(chartInstance);
    if (c25_b_k < 1) {
    } else {
      c25_d_k = c25_b_k;
      c25_alpha1 = 1.0;
      c25_d_ldb = c25_b_ldb;
      c25_beta1 = 0.0;
      c25_TRANSB = 'N';
      c25_TRANSA = 'N';
      c25_m_t = (ptrdiff_t)18;
      c25_n_t = (ptrdiff_t)18;
      c25_var = c25_d_k;
      c25_k_t = (ptrdiff_t)c25_var;
      c25_lda_t = (ptrdiff_t)18;
      c25_b_var = c25_d_ldb;
      c25_ldb_t = (ptrdiff_t)c25_b_var;
      c25_ldc_t = (ptrdiff_t)18;
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, 18 * c25_A_sizes[1], 1, 0);
      dgemm(&c25_TRANSA, &c25_TRANSB, &c25_m_t, &c25_n_t, &c25_k_t, &c25_alpha1,
            &c25_A_data[0], &c25_lda_t, &c25_B[0], &c25_ldb_t, &c25_beta1,
            &c25_C[0], &c25_ldc_t);
    }
  }
}

static void c25_m_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, int32_T c25_m, int32_T c25_n, int32_T c25_k, real_T
  c25_A_data[], int32_T c25_A_sizes[2], int32_T c25_lda, real_T c25_B_data[],
  int32_T c25_B_sizes[2], int32_T c25_ldb, real_T c25_C_data[], int32_T
  c25_C_sizes[2], int32_T c25_ldc)
{
  int32_T c25_b_m;
  int32_T c25_b_n;
  int32_T c25_b_k;
  int32_T c25_b_lda;
  int32_T c25_b_ldb;
  int32_T c25_b_ldc;
  int32_T c25_c_m;
  int32_T c25_c_n;
  int32_T c25_c_k;
  int32_T c25_c_lda;
  int32_T c25_c_ldb;
  int32_T c25_c_ldc;
  int32_T c25_lda1;
  int32_T c25_ldb1;
  int32_T c25_ldc1;
  int32_T c25_a;
  int32_T c25_nm1;
  int32_T c25_b_a;
  int32_T c25_b;
  int32_T c25_c;
  int32_T c25_b_b;
  int32_T c25_lastColC;
  int32_T c25_b_ldc1;
  int32_T c25_b_lastColC;
  int32_T c25_d;
  int32_T c25_c_b;
  int32_T c25_b_d;
  int32_T c25_d_b;
  boolean_T c25_overflow;
  int32_T c25_cr;
  int32_T c25_b_cr;
  int32_T c25_c_a;
  int32_T c25_i229;
  int32_T c25_d_a;
  int32_T c25_e_b;
  int32_T c25_i230;
  int32_T c25_e_a;
  int32_T c25_f_b;
  int32_T c25_f_a;
  int32_T c25_g_b;
  boolean_T c25_b_overflow;
  int32_T c25_ic;
  int32_T c25_b_ic;
  int32_T c25_C[1];
  int32_T c25_br;
  int32_T c25_c_ldc1;
  int32_T c25_c_lastColC;
  int32_T c25_c_d;
  int32_T c25_h_b;
  int32_T c25_d_d;
  int32_T c25_i_b;
  boolean_T c25_c_overflow;
  int32_T c25_c_cr;
  int32_T c25_ar;
  int32_T c25_g_a;
  int32_T c25_i231;
  int32_T c25_h_a;
  int32_T c25_j_b;
  int32_T c25_i232;
  int32_T c25_i_a;
  int32_T c25_k_b;
  int32_T c25_j_a;
  int32_T c25_l_b;
  boolean_T c25_d_overflow;
  int32_T c25_ib;
  int32_T c25_b_ib;
  real_T c25_temp;
  int32_T c25_ia;
  int32_T c25_k_a;
  int32_T c25_i233;
  int32_T c25_l_a;
  int32_T c25_m_b;
  int32_T c25_i234;
  int32_T c25_m_a;
  int32_T c25_n_b;
  int32_T c25_n_a;
  int32_T c25_o_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_ic;
  int32_T c25_o_a;
  int32_T c25_b_C[1];
  int32_T c25_p_a;
  int32_T c25_p_b;
  int32_T c25_q_a;
  int32_T c25_q_b;
  int32_T c25_d_m;
  int32_T c25_d_n;
  int32_T c25_d_k;
  real_T c25_alpha1;
  int32_T c25_d_lda;
  int32_T c25_d_ldb;
  real_T c25_beta1;
  int32_T c25_d_ldc;
  char_T c25_TRANSB;
  char_T c25_TRANSA;
  int32_T c25_var;
  ptrdiff_t c25_m_t;
  int32_T c25_b_var;
  ptrdiff_t c25_n_t;
  int32_T c25_c_var;
  ptrdiff_t c25_k_t;
  int32_T c25_d_var;
  ptrdiff_t c25_lda_t;
  int32_T c25_e_var;
  ptrdiff_t c25_ldb_t;
  int32_T c25_f_var;
  ptrdiff_t c25_ldc_t;
  int32_T c25_c_C[1];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c25_b_m = c25_m;
  c25_b_n = c25_n;
  c25_b_k = c25_k;
  c25_b_lda = c25_lda;
  c25_b_ldb = c25_ldb;
  c25_b_ldc = c25_ldc;
  if (c25_use_refblas(chartInstance)) {
    c25_scalarEg(chartInstance);
    c25_scalarEg(chartInstance);
    c25_c_m = c25_b_m;
    c25_c_n = c25_b_n;
    c25_c_k = c25_b_k;
    c25_c_lda = c25_b_lda;
    c25_c_ldb = c25_b_ldb;
    c25_c_ldc = c25_b_ldc;
    if (c25_c_m == 0) {
    } else if (c25_c_n == 0) {
    } else {
      c25_lda1 = c25_c_lda;
      c25_ldb1 = c25_c_ldb;
      c25_ldc1 = c25_c_ldc;
      c25_a = c25_c_n;
      c25_nm1 = c25_a;
      c25_b_a = c25_ldc1;
      c25_b = c25_nm1 - 1;
      c25_c = c25_b_a * c25_b;
      c25_b_b = c25_c;
      c25_lastColC = c25_b_b;
      c25_b_ldc1 = c25_ldc1;
      c25_b_lastColC = c25_lastColC;
      c25_d = c25_b_ldc1;
      c25_c_b = c25_b_lastColC;
      c25_b_d = c25_d;
      c25_d_b = c25_c_b;
      guard2 = false;
      if (c25_b_d == 0) {
        guard2 = true;
      } else if (0 > c25_d_b) {
        guard2 = true;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = (c25_d_b > MAX_int32_T - c25_b_d);
      }

      if (guard2 == true) {
        c25_overflow = false;
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      c25_cr = 0;
      while ((c25_b_ldc1 > 0) && (c25_cr <= c25_b_lastColC)) {
        c25_b_cr = c25_cr;
        c25_c_a = c25_b_cr + 1;
        c25_i229 = c25_c_a;
        c25_d_a = c25_b_cr;
        c25_e_b = c25_c_m;
        c25_i230 = c25_d_a + c25_e_b;
        c25_e_a = c25_i229;
        c25_f_b = c25_i230;
        c25_f_a = c25_e_a;
        c25_g_b = c25_f_b;
        if (c25_f_a > c25_g_b) {
          c25_b_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_b_overflow = (c25_g_b > 2147483646);
        }

        if (c25_b_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ic = c25_i229; c25_ic <= c25_i230; c25_ic++) {
          c25_b_ic = c25_ic;
          c25_C[0] = c25_C_sizes[0] * c25_C_sizes[1];
          c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1, c25_C_sizes[0]
            * c25_C_sizes[1], 1, 0) - 1] = 0.0;
        }

        c25_cr += c25_b_ldc1;
      }

      c25_br = 0;
      c25_c_ldc1 = c25_ldc1;
      c25_c_lastColC = c25_lastColC;
      c25_c_d = c25_c_ldc1;
      c25_h_b = c25_c_lastColC;
      c25_d_d = c25_c_d;
      c25_i_b = c25_h_b;
      guard1 = false;
      if (c25_d_d == 0) {
        guard1 = true;
      } else if (0 > c25_i_b) {
        guard1 = true;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_c_overflow = (c25_i_b > MAX_int32_T - c25_d_d);
      }

      if (guard1 == true) {
        c25_c_overflow = false;
      }

      if (c25_c_overflow) {
        c25_check_forloop_overflow_error(chartInstance, true);
      }

      c25_c_cr = 0;
      while ((c25_c_ldc1 > 0) && (c25_c_cr <= c25_c_lastColC)) {
        c25_b_cr = c25_c_cr;
        c25_ar = 0;
        c25_g_a = c25_br + 1;
        c25_i231 = c25_g_a;
        c25_h_a = c25_br;
        c25_j_b = c25_c_k;
        c25_i232 = c25_h_a + c25_j_b;
        c25_i_a = c25_i231;
        c25_k_b = c25_i232;
        c25_j_a = c25_i_a;
        c25_l_b = c25_k_b;
        if (c25_j_a > c25_l_b) {
          c25_d_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_d_overflow = (c25_l_b > 2147483646);
        }

        if (c25_d_overflow) {
          c25_check_forloop_overflow_error(chartInstance, true);
        }

        for (c25_ib = c25_i231; c25_ib <= c25_i232; c25_ib++) {
          c25_b_ib = c25_ib;
          if (c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
               c25_B_sizes[0] * c25_B_sizes[1], 1, 0) - 1] != 0.0) {
            c25_temp = c25_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ib, 1,
              c25_B_sizes[0] * c25_B_sizes[1], 1, 0) - 1];
            c25_ia = c25_ar;
            c25_k_a = c25_b_cr + 1;
            c25_i233 = c25_k_a;
            c25_l_a = c25_b_cr;
            c25_m_b = c25_c_m;
            c25_i234 = c25_l_a + c25_m_b;
            c25_m_a = c25_i233;
            c25_n_b = c25_i234;
            c25_n_a = c25_m_a;
            c25_o_b = c25_n_b;
            if (c25_n_a > c25_o_b) {
              c25_e_overflow = false;
            } else {
              c25_eml_switch_helper(chartInstance);
              c25_eml_switch_helper(chartInstance);
              c25_e_overflow = (c25_o_b > 2147483646);
            }

            if (c25_e_overflow) {
              c25_check_forloop_overflow_error(chartInstance, true);
            }

            for (c25_c_ic = c25_i233; c25_c_ic <= c25_i234; c25_c_ic++) {
              c25_b_ic = c25_c_ic;
              c25_o_a = c25_ia + 1;
              c25_ia = c25_o_a;
              c25_b_C[0] = c25_C_sizes[0] * c25_C_sizes[1];
              c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1,
                c25_C_sizes[0] * c25_C_sizes[1], 1, 0) - 1] =
                c25_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_b_ic, 1,
                c25_C_sizes[0] * c25_C_sizes[1], 1, 0) - 1] + c25_temp *
                c25_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c25_ia, 1,
                c25_A_sizes[0] * c25_A_sizes[1], 1, 0) - 1];
            }
          }

          c25_p_a = c25_ar;
          c25_p_b = c25_lda1;
          c25_ar = c25_p_a + c25_p_b;
        }

        c25_q_a = c25_br;
        c25_q_b = c25_ldb1;
        c25_br = c25_q_a + c25_q_b;
        c25_c_cr += c25_c_ldc1;
      }
    }
  } else {
    c25_g_below_threshold(chartInstance);
    if (c25_b_m < 1) {
    } else if (c25_b_n < 1) {
    } else if (c25_b_k < 1) {
    } else {
      c25_d_m = c25_b_m;
      c25_d_n = c25_b_n;
      c25_d_k = c25_b_k;
      c25_alpha1 = 1.0;
      c25_d_lda = c25_b_lda;
      c25_d_ldb = c25_b_ldb;
      c25_beta1 = 0.0;
      c25_d_ldc = c25_b_ldc;
      c25_TRANSB = 'N';
      c25_TRANSA = 'N';
      c25_var = c25_d_m;
      c25_m_t = (ptrdiff_t)c25_var;
      c25_b_var = c25_d_n;
      c25_n_t = (ptrdiff_t)c25_b_var;
      c25_c_var = c25_d_k;
      c25_k_t = (ptrdiff_t)c25_c_var;
      c25_d_var = c25_d_lda;
      c25_lda_t = (ptrdiff_t)c25_d_var;
      c25_e_var = c25_d_ldb;
      c25_ldb_t = (ptrdiff_t)c25_e_var;
      c25_f_var = c25_d_ldc;
      c25_ldc_t = (ptrdiff_t)c25_f_var;
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_A_sizes[0] * c25_A_sizes[1], 1,
        0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_B_sizes[0] * c25_B_sizes[1], 1,
        0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c25_C_sizes[0] * c25_C_sizes[1], 1,
        0);
      c25_c_C[0] = c25_C_sizes[0] * c25_C_sizes[1];
      dgemm(&c25_TRANSA, &c25_TRANSB, &c25_m_t, &c25_n_t, &c25_k_t, &c25_alpha1,
            &c25_A_data[0], &c25_lda_t, &c25_B_data[0], &c25_ldb_t, &c25_beta1,
            &c25_C_data[0], &c25_ldc_t);
    }
  }
}

static void c25_n_eml_xgemm(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance, real_T c25_A[324], real_T c25_B[324], real_T c25_C[324])
{
  real_T c25_alpha1;
  real_T c25_beta1;
  char_T c25_TRANSB;
  char_T c25_TRANSA;
  ptrdiff_t c25_m_t;
  ptrdiff_t c25_n_t;
  ptrdiff_t c25_k_t;
  ptrdiff_t c25_lda_t;
  ptrdiff_t c25_ldb_t;
  ptrdiff_t c25_ldc_t;
  c25_threshold(chartInstance);
  c25_alpha1 = 1.0;
  c25_beta1 = 0.0;
  c25_TRANSB = 'N';
  c25_TRANSA = 'N';
  c25_m_t = (ptrdiff_t)18;
  c25_n_t = (ptrdiff_t)18;
  c25_k_t = (ptrdiff_t)18;
  c25_lda_t = (ptrdiff_t)18;
  c25_ldb_t = (ptrdiff_t)18;
  c25_ldc_t = (ptrdiff_t)18;
  dgemm(&c25_TRANSA, &c25_TRANSB, &c25_m_t, &c25_n_t, &c25_k_t, &c25_alpha1,
        &c25_A[0], &c25_lda_t, &c25_B[0], &c25_ldb_t, &c25_beta1, &c25_C[0],
        &c25_ldc_t);
}

static void init_dsm_address_info(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance)
{
  chartInstance->c25_Sk_data = (real_T (*)[144])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c25_Sk_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 0);
  chartInstance->c25_U1 = (real_T (*)[324])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c25_del_x_data = (real_T (*)[12])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c25_del_x_sizes = (int32_T *)
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 1);
  chartInstance->c25_UF = (real_T (*)[324])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c25_Pd = (real_T (*)[324])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c25_U = (real_T (*)[324])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c25_xd = (real_T (*)[18])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c25_Pd1 = (real_T (*)[324])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c25_H_data = (real_T (*)[216])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c25_H_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 5);
  chartInstance->c25_x_d = (real_T (*)[18])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c25_K_data = (real_T (*)[216])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c25_K_sizes = (int32_T (*)[2])
    ssGetCurrentInputPortDimensions_wrapper(chartInstance->S, 7);
  chartInstance->c25_Phi = (real_T (*)[324])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
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

void sf_c25_EKF_SIL_02_newdelIpsOOSM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1277924763U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(297615061U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3931699720U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(234082261U);
}

mxArray* sf_c25_EKF_SIL_02_newdelIpsOOSM_get_post_codegen_info(void);
mxArray *sf_c25_EKF_SIL_02_newdelIpsOOSM_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Hi00y3NgxcZxWcfSxcpteC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
      pr[0] = (double)(18);
      pr[1] = (double)(18);
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
      pr[0] = (double)(18);
      pr[1] = (double)(18);
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
      pr[0] = (double)(18);
      pr[1] = (double)(18);
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
      pr[0] = (double)(12);
      pr[1] = (double)(18);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(18);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(18);
      pr[1] = (double)(12);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(18);
      pr[1] = (double)(18);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(18);
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
      pr[0] = (double)(18);
      pr[1] = (double)(18);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c25_EKF_SIL_02_newdelIpsOOSM_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c25_EKF_SIL_02_newdelIpsOOSM_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c25_EKF_SIL_02_newdelIpsOOSM_jit_fallback_info(void)
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

mxArray *sf_c25_EKF_SIL_02_newdelIpsOOSM_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c25_EKF_SIL_02_newdelIpsOOSM_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c25_EKF_SIL_02_newdelIpsOOSM(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[11],T\"Pd1\",},{M[1],M[5],T\"U1\",},{M[1],M[10],T\"xd\",},{M[8],M[0],T\"is_active_c25_EKF_SIL_02_newdelIpsOOSM\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_EKF_SIL_02_newdelIpsOOSM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EKF_SIL_02_newdelIpsOOSMMachineNumber_,
           25,
           1,
           1,
           0,
           12,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_EKF_SIL_02_newdelIpsOOSMMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_EKF_SIL_02_newdelIpsOOSMMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _EKF_SIL_02_newdelIpsOOSMMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Sk");
          _SFD_SET_DATA_PROPS(1,1,1,0,"del_x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"UF");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Pd");
          _SFD_SET_DATA_PROPS(4,1,1,0,"U");
          _SFD_SET_DATA_PROPS(5,1,1,0,"H");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x_d");
          _SFD_SET_DATA_PROPS(7,1,1,0,"K");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Phi");
          _SFD_SET_DATA_PROPS(9,2,0,1,"U1");
          _SFD_SET_DATA_PROPS(10,2,0,1,"xd");
          _SFD_SET_DATA_PROPS(11,2,0,1,"Pd1");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,288);

        {
          unsigned int dimVector[2];
          dimVector[0]= 12;
          dimVector[1]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)
            c25_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_b_sf_marshallOut,(MexInFcnForType)
            c25_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)
            c25_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _EKF_SIL_02_newdelIpsOOSMMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(0U, *chartInstance->c25_Sk_data, (void *)
          chartInstance->c25_Sk_sizes);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c25_U1);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(1U, *chartInstance->c25_del_x_data,
          (void *)chartInstance->c25_del_x_sizes);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c25_UF);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c25_Pd);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c25_U);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c25_xd);
        _SFD_SET_DATA_VALUE_PTR(11U, *chartInstance->c25_Pd1);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(5U, *chartInstance->c25_H_data, (void *)
          chartInstance->c25_H_sizes);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c25_x_d);
        _SFD_SET_DATA_VALUE_PTR_VAR_DIM(7U, *chartInstance->c25_K_data, (void *)
          chartInstance->c25_K_sizes);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c25_Phi);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sVEQZjGtamBJF3P4RqzCvgG";
}

static void sf_opaque_initialize_c25_EKF_SIL_02_newdelIpsOOSM(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*) chartInstanceVar);
  initialize_c25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c25_EKF_SIL_02_newdelIpsOOSM(void *chartInstanceVar)
{
  enable_c25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c25_EKF_SIL_02_newdelIpsOOSM(void
  *chartInstanceVar)
{
  disable_c25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c25_EKF_SIL_02_newdelIpsOOSM(void
  *chartInstanceVar)
{
  sf_gateway_c25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c25_EKF_SIL_02_newdelIpsOOSM
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c25_EKF_SIL_02_newdelIpsOOSM(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c25_EKF_SIL_02_newdelIpsOOSM(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EKF_SIL_02_newdelIpsOOSM_optimization_info();
    }

    finalize_c25_EKF_SIL_02_newdelIpsOOSM
      ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc25_EKF_SIL_02_newdelIpsOOSM
    ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_EKF_SIL_02_newdelIpsOOSM(SimStruct *S)
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
    initialize_params_c25_EKF_SIL_02_newdelIpsOOSM
      ((SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c25_EKF_SIL_02_newdelIpsOOSM(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EKF_SIL_02_newdelIpsOOSM_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,25,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,25);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,25,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,25,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(298551188U));
  ssSetChecksum1(S,(1982886625U));
  ssSetChecksum2(S,(2667792241U));
  ssSetChecksum3(S,(4190861704U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c25_EKF_SIL_02_newdelIpsOOSM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_EKF_SIL_02_newdelIpsOOSM(SimStruct *S)
{
  SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct *)utMalloc
    (sizeof(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc25_EKF_SIL_02_newdelIpsOOSMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.mdlStart = mdlStart_c25_EKF_SIL_02_newdelIpsOOSM;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c25_EKF_SIL_02_newdelIpsOOSM;
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

void c25_EKF_SIL_02_newdelIpsOOSM_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_EKF_SIL_02_newdelIpsOOSM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_EKF_SIL_02_newdelIpsOOSM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_EKF_SIL_02_newdelIpsOOSM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_EKF_SIL_02_newdelIpsOOSM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
