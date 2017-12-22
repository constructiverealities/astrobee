//
// File: dbiebiecimopdbaa_xnrm2.cpp
//
// Code generated for Simulink model 'est_estimator'.
//
// Model version                  : 1.1142
// Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
// C/C++ source code generated on : Mon Dec  4 08:33:06 2017
//
#include "rtwtypes.h"
#include <math.h>
#include "dbiebiecimopdbaa_xnrm2.h"

// Function for MATLAB Function: '<S24>/compute_of_global_points'
real32_T dbiebiecimopdbaa_xnrm2(int32_T n, const real32_T x[16], int32_T ix0)
{
  real32_T y;
  real32_T scale;
  int32_T kend;
  real32_T absxk;
  real32_T t;
  int32_T k;
  y = 0.0F;
  scale = 1.17549435E-38F;
  kend = (int32_T)((int32_T)(ix0 + n) - 1);
  for (k = ix0; k <= kend; k++) {
    absxk = (real32_T)fabs((real_T)x[(int32_T)(k - 1)]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0F;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * (real32_T)sqrt((real_T)y);
}

//
// File trailer for generated code.
//
// [EOF]
//
