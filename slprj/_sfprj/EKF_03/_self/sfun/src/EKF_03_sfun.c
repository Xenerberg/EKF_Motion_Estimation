/* Include files */

#include "EKF_03_sfun.h"
#include "EKF_03_sfun_debug_macros.h"
#include "c2_EKF_03.h"
#include "c3_EKF_03.h"
#include "c4_EKF_03.h"
#include "c5_EKF_03.h"
#include "c6_EKF_03.h"
#include "c7_EKF_03.h"
#include "c8_EKF_03.h"
#include "c9_EKF_03.h"
#include "c10_EKF_03.h"
#include "c11_EKF_03.h"
#include "c12_EKF_03.h"
#include "c13_EKF_03.h"
#include "c18_EKF_03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _EKF_03MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void EKF_03_initializer(void)
{
}

void EKF_03_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_EKF_03_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_EKF_03_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_EKF_03_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(287908223U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(106125404U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2600041503U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3001248391U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2057387638U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3599560630U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3320463748U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2592486783U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c2_EKF_03_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c3_EKF_03_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c4_EKF_03_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c5_EKF_03_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c6_EKF_03_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c7_EKF_03_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c8_EKF_03_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c9_EKF_03_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c10_EKF_03_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c11_EKF_03_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c12_EKF_03_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c13_EKF_03_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_EKF_03_get_check_sum(mxArray *plhs[]);
          sf_c18_EKF_03_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3884087561U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2590574685U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3243408026U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3782162482U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EKF_03_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "dAwER4BQVW7WyQwhwHKjN") == 0) {
          extern mxArray *sf_c2_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c2_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "d4vouQUsiG0gKw23NeUxLE") == 0) {
          extern mxArray *sf_c3_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c3_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "d4vouQUsiG0gKw23NeUxLE") == 0) {
          extern mxArray *sf_c4_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c4_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "d4vouQUsiG0gKw23NeUxLE") == 0) {
          extern mxArray *sf_c5_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c5_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "gqsmeDvjorgRIIRpT5CyTH") == 0) {
          extern mxArray *sf_c6_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c6_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "YCUUo4NLtqpoc8IBQ9KNGB") == 0) {
          extern mxArray *sf_c7_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c7_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "yW53vFYTTYynsrcdU0R6wE") == 0) {
          extern mxArray *sf_c8_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c8_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "d4vouQUsiG0gKw23NeUxLE") == 0) {
          extern mxArray *sf_c9_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c9_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "9Su5bOd41H9LAwJwHG1sfD") == 0) {
          extern mxArray *sf_c10_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c10_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "d4vouQUsiG0gKw23NeUxLE") == 0) {
          extern mxArray *sf_c11_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c11_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "d4vouQUsiG0gKw23NeUxLE") == 0) {
          extern mxArray *sf_c12_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c12_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "d4vouQUsiG0gKw23NeUxLE") == 0) {
          extern mxArray *sf_c13_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c13_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "dAwER4BQVW7WyQwhwHKjN") == 0) {
          extern mxArray *sf_c18_EKF_03_get_autoinheritance_info(void);
          plhs[0] = sf_c18_EKF_03_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EKF_03_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray *sf_c2_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray *sf_c18_EKF_03_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_EKF_03_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EKF_03_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "CA1Hoy753gVYtifiO7STHH") == 0) {
          extern mxArray *sf_c2_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c2_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c3_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c3_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c4_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c4_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c5_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c5_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "3A1NRZFPVZlcXAc10vjYfG") == 0) {
          extern mxArray *sf_c6_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c6_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "EforzPMyvPho6YHhxHakWC") == 0) {
          extern mxArray *sf_c7_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c7_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "kSiq8AVWPXEug3LVXJKZGH") == 0) {
          extern mxArray *sf_c8_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c8_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c9_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c9_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "cIgJO9Fg2ZUlYMATVlKSqD") == 0) {
          extern mxArray *sf_c10_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c10_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c11_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c11_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c12_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c12_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c13_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c13_EKF_03_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "CA1Hoy753gVYtifiO7STHH") == 0) {
          extern mxArray *sf_c18_EKF_03_third_party_uses_info(void);
          plhs[0] = sf_c18_EKF_03_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_EKF_03_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "CA1Hoy753gVYtifiO7STHH") == 0) {
          extern mxArray *sf_c2_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c3_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c4_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c5_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "3A1NRZFPVZlcXAc10vjYfG") == 0) {
          extern mxArray *sf_c6_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "EforzPMyvPho6YHhxHakWC") == 0) {
          extern mxArray *sf_c7_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "kSiq8AVWPXEug3LVXJKZGH") == 0) {
          extern mxArray *sf_c8_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c9_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "cIgJO9Fg2ZUlYMATVlKSqD") == 0) {
          extern mxArray *sf_c10_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c11_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c12_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "cIBiYNm46H62nSvGIWwbME") == 0) {
          extern mxArray *sf_c13_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "CA1Hoy753gVYtifiO7STHH") == 0) {
          extern mxArray *sf_c18_EKF_03_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_EKF_03_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void EKF_03_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _EKF_03MachineNumber_ = sf_debug_initialize_machine(debugInstance,"EKF_03",
    "sfun",0,13,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_EKF_03MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_EKF_03MachineNumber_,0);
}

void EKF_03_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_EKF_03_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("EKF_03",
      "EKF_03");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_EKF_03_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
