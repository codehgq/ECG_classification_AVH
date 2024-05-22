// tvm target: c -keys=arm_cpu,cpu -mcpu=cortex-m55
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_expand_dims_reshape(float* p0, float* T_reshape, uint8_t* global_const_workspace_2_var, uint8_t* global_workspace_3_var) {
  for (int32_t ax3_outer = 0; ax3_outer < 900; ++ax3_outer) {
    for (int32_t ax3_inner = 0; ax3_inner < 4; ++ax3_inner) {
      int32_t cse_var_1 = ((ax3_outer * 4) + ax3_inner);
      T_reshape[cse_var_1] = p0[cse_var_1];
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_conv2d(float* p0, float* output_unpack, uint8_t* global_const_workspace_4_var, uint8_t* global_workspace_5_var) {
  void* fused_constant_let = (&(global_const_workspace_4_var[15441920]));
  void* data_vec_let = (&(global_workspace_5_var[0]));
  for (int32_t w = 0; w < 200; ++w) {
    for (int32_t vw = 0; vw < 65; ++vw) {
      int32_t cse_var_1 = ((w * 18) + vw);
      ((float*)data_vec_let)[((w * 65) + vw)] = (((23 <= cse_var_1) && (cse_var_1 < 3623)) ? p0[(cse_var_1 - 23)] : 0.000000e+00f);
    }
  }
  for (int32_t co_outer = 0; co_outer < 8; ++co_outer) {
    for (int32_t w_outer = 0; w_outer < 200; ++w_outer) {
      void* conv_let = (&(global_workspace_5_var[52000]));
      for (int32_t vc_init = 0; vc_init < 16; ++vc_init) {
        ((float*)conv_let)[vc_init] = 0.000000e+00f;
      }
      for (int32_t vc_init_1 = 0; vc_init_1 < 16; ++vc_init_1) {
        ((float*)conv_let)[(vc_init_1 + 16)] = 0.000000e+00f;
      }
      for (int32_t vc_init_2 = 0; vc_init_2 < 16; ++vc_init_2) {
        ((float*)conv_let)[(vc_init_2 + 32)] = 0.000000e+00f;
      }
      for (int32_t vc_init_3 = 0; vc_init_3 < 16; ++vc_init_3) {
        ((float*)conv_let)[(vc_init_3 + 48)] = 0.000000e+00f;
      }
      for (int32_t vc_init_4 = 0; vc_init_4 < 16; ++vc_init_4) {
        ((float*)conv_let)[(vc_init_4 + 64)] = 0.000000e+00f;
      }
      for (int32_t vc_init_5 = 0; vc_init_5 < 16; ++vc_init_5) {
        ((float*)conv_let)[(vc_init_5 + 80)] = 0.000000e+00f;
      }
      for (int32_t kw = 0; kw < 50; ++kw) {
        for (int32_t vc = 0; vc < 16; ++vc) {
          ((float*)conv_let)[vc] = (((float*)conv_let)[vc] + (((float*)data_vec_let)[((w_outer * 65) + kw)] * ((float*)fused_constant_let)[(((co_outer * 800) + (kw * 16)) + vc)]));
        }
        for (int32_t vc_1 = 0; vc_1 < 16; ++vc_1) {
          int32_t cse_var_2 = (vc_1 + 16);
          ((float*)conv_let)[cse_var_2] = (((float*)conv_let)[cse_var_2] + (((float*)data_vec_let)[(((w_outer * 65) + kw) + 3)] * ((float*)fused_constant_let)[(((co_outer * 800) + (kw * 16)) + vc_1)]));
        }
        for (int32_t vc_2 = 0; vc_2 < 16; ++vc_2) {
          int32_t cse_var_3 = (vc_2 + 32);
          ((float*)conv_let)[cse_var_3] = (((float*)conv_let)[cse_var_3] + (((float*)data_vec_let)[(((w_outer * 65) + kw) + 6)] * ((float*)fused_constant_let)[(((co_outer * 800) + (kw * 16)) + vc_2)]));
        }
        for (int32_t vc_3 = 0; vc_3 < 16; ++vc_3) {
          int32_t cse_var_4 = (vc_3 + 48);
          ((float*)conv_let)[cse_var_4] = (((float*)conv_let)[cse_var_4] + (((float*)data_vec_let)[(((w_outer * 65) + kw) + 9)] * ((float*)fused_constant_let)[(((co_outer * 800) + (kw * 16)) + vc_3)]));
        }
        for (int32_t vc_4 = 0; vc_4 < 16; ++vc_4) {
          int32_t cse_var_5 = (vc_4 + 64);
          ((float*)conv_let)[cse_var_5] = (((float*)conv_let)[cse_var_5] + (((float*)data_vec_let)[(((w_outer * 65) + kw) + 12)] * ((float*)fused_constant_let)[(((co_outer * 800) + (kw * 16)) + vc_4)]));
        }
        for (int32_t vc_5 = 0; vc_5 < 16; ++vc_5) {
          int32_t cse_var_6 = (vc_5 + 80);
          ((float*)conv_let)[cse_var_6] = (((float*)conv_let)[cse_var_6] + (((float*)data_vec_let)[(((w_outer * 65) + kw) + 15)] * ((float*)fused_constant_let)[(((co_outer * 800) + (kw * 16)) + vc_5)]));
        }
      }
      for (int32_t w_inner = 0; w_inner < 6; ++w_inner) {
        for (int32_t co_inner = 0; co_inner < 16; ++co_inner) {
          output_unpack[((((co_outer * 19200) + (co_inner * 1200)) + (w_outer * 6)) + w_inner)] = ((float*)conv_let)[((w_inner * 16) + co_inner)];
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_conv2d_1(float* p0, float* output_unpack, uint8_t* global_const_workspace_10_var, uint8_t* global_workspace_11_var) {
  void* fused_constant_1_let = (&(global_const_workspace_10_var[15204352]));
  void* data_vec_let = (&(global_workspace_11_var[0]));
  for (int32_t w = 0; w < 200; ++w) {
    for (int32_t ci = 0; ci < 128; ++ci) {
      for (int32_t vw = 0; vw < 8; ++vw) {
        int32_t cse_var_2 = (w * 2);
        int32_t cse_var_1 = (cse_var_2 + vw);
        ((float*)data_vec_let)[(((w * 1024) + (ci * 8)) + vw)] = (((3 <= cse_var_1) && (cse_var_1 < 403)) ? p0[((((ci * 400) + cse_var_2) + vw) - 3)] : 0.000000e+00f);
      }
    }
  }
  for (int32_t co_outer = 0; co_outer < 8; ++co_outer) {
    for (int32_t w_outer = 0; w_outer < 200; ++w_outer) {
      void* conv_let = (&(global_workspace_11_var[870400]));
      for (int32_t vc_init = 0; vc_init < 4; ++vc_init) {
        for (int32_t vw_init = 0; vw_init < 2; ++vw_init) {
          ((float*)conv_let)[((vw_init * 4) + vc_init)] = 0.000000e+00f;
        }
      }
      for (int32_t ci_1 = 0; ci_1 < 128; ++ci_1) {
        for (int32_t vc = 0; vc < 4; ++vc) {
          for (int32_t vw_1 = 0; vw_1 < 2; ++vw_1) {
            int32_t cse_var_3 = ((vw_1 * 4) + vc);
            ((float*)conv_let)[cse_var_3] = (((float*)conv_let)[cse_var_3] + (((float*)data_vec_let)[(((w_outer * 1024) + (ci_1 * 8)) + vw_1)] * ((float*)fused_constant_1_let)[(((co_outer * 3584) + (ci_1 * 28)) + vc)]));
          }
        }
        for (int32_t vc_1 = 0; vc_1 < 4; ++vc_1) {
          for (int32_t vw_2 = 0; vw_2 < 2; ++vw_2) {
            int32_t cse_var_4 = ((vw_2 * 4) + vc_1);
            ((float*)conv_let)[cse_var_4] = (((float*)conv_let)[cse_var_4] + (((float*)data_vec_let)[((((w_outer * 1024) + (ci_1 * 8)) + vw_2) + 1)] * ((float*)fused_constant_1_let)[((((co_outer * 3584) + (ci_1 * 28)) + vc_1) + 4)]));
          }
        }
        for (int32_t vc_2 = 0; vc_2 < 4; ++vc_2) {
          for (int32_t vw_3 = 0; vw_3 < 2; ++vw_3) {
            int32_t cse_var_5 = ((vw_3 * 4) + vc_2);
            ((float*)conv_let)[cse_var_5] = (((float*)conv_let)[cse_var_5] + (((float*)data_vec_let)[((((w_outer * 1024) + (ci_1 * 8)) + vw_3) + 2)] * ((float*)fused_constant_1_let)[((((co_outer * 3584) + (ci_1 * 28)) + vc_2) + 8)]));
          }
        }
        for (int32_t vc_3 = 0; vc_3 < 4; ++vc_3) {
          for (int32_t vw_4 = 0; vw_4 < 2; ++vw_4) {
            int32_t cse_var_6 = ((vw_4 * 4) + vc_3);
            ((float*)conv_let)[cse_var_6] = (((float*)conv_let)[cse_var_6] + (((float*)data_vec_let)[((((w_outer * 1024) + (ci_1 * 8)) + vw_4) + 3)] * ((float*)fused_constant_1_let)[((((co_outer * 3584) + (ci_1 * 28)) + vc_3) + 12)]));
          }
        }
        for (int32_t vc_4 = 0; vc_4 < 4; ++vc_4) {
          for (int32_t vw_5 = 0; vw_5 < 2; ++vw_5) {
            int32_t cse_var_7 = ((vw_5 * 4) + vc_4);
            ((float*)conv_let)[cse_var_7] = (((float*)conv_let)[cse_var_7] + (((float*)data_vec_let)[((((w_outer * 1024) + (ci_1 * 8)) + vw_5) + 4)] * ((float*)fused_constant_1_let)[((((co_outer * 3584) + (ci_1 * 28)) + vc_4) + 16)]));
          }
        }
        for (int32_t vc_5 = 0; vc_5 < 4; ++vc_5) {
          for (int32_t vw_6 = 0; vw_6 < 2; ++vw_6) {
            int32_t cse_var_8 = ((vw_6 * 4) + vc_5);
            ((float*)conv_let)[cse_var_8] = (((float*)conv_let)[cse_var_8] + (((float*)data_vec_let)[((((w_outer * 1024) + (ci_1 * 8)) + vw_6) + 5)] * ((float*)fused_constant_1_let)[((((co_outer * 3584) + (ci_1 * 28)) + vc_5) + 20)]));
          }
        }
        for (int32_t vc_6 = 0; vc_6 < 4; ++vc_6) {
          for (int32_t vw_7 = 0; vw_7 < 2; ++vw_7) {
            int32_t cse_var_9 = ((vw_7 * 4) + vc_6);
            ((float*)conv_let)[cse_var_9] = (((float*)conv_let)[cse_var_9] + (((float*)data_vec_let)[((((w_outer * 1024) + (ci_1 * 8)) + vw_7) + 6)] * ((float*)fused_constant_1_let)[((((co_outer * 3584) + (ci_1 * 28)) + vc_6) + 24)]));
          }
        }
      }
      for (int32_t w_inner = 0; w_inner < 2; ++w_inner) {
        for (int32_t co_inner = 0; co_inner < 4; ++co_inner) {
          output_unpack[((((co_outer * 1600) + (co_inner * 400)) + (w_outer * 2)) + w_inner)] = ((float*)conv_let)[((w_inner * 4) + co_inner)];
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_conv2d_2(float* p0, float* output_unpack, uint8_t* global_const_workspace_16_var, uint8_t* global_workspace_17_var) {
  void* fused_constant_2_let = (&(global_const_workspace_16_var[15400960]));
  void* data_vec_let = (&(global_workspace_17_var[0]));
  for (int32_t w = 0; w < 100; ++w) {
    for (int32_t ci = 0; ci < 32; ++ci) {
      for (int32_t vw = 0; vw < 11; ++vw) {
        int32_t cse_var_1 = ((vw >> 1) + w);
        ((float*)data_vec_let)[(((w * 352) + (ci * 11)) + vw)] = (((2 <= cse_var_1) && (cse_var_1 < 102)) ? p0[((((ci * 200) + (w * 2)) + vw) - 4)] : 0.000000e+00f);
      }
    }
  }
  for (int32_t co_outer = 0; co_outer < 8; ++co_outer) {
    for (int32_t w_outer = 0; w_outer < 100; ++w_outer) {
      void* conv_let = (&(global_workspace_17_var[166400]));
      for (int32_t vc_init = 0; vc_init < 4; ++vc_init) {
        for (int32_t vw_init = 0; vw_init < 2; ++vw_init) {
          ((float*)conv_let)[((vw_init * 4) + vc_init)] = 0.000000e+00f;
        }
      }
      for (int32_t ci_1 = 0; ci_1 < 32; ++ci_1) {
        for (int32_t vc = 0; vc < 4; ++vc) {
          for (int32_t vw_1 = 0; vw_1 < 2; ++vw_1) {
            int32_t cse_var_2 = ((vw_1 * 4) + vc);
            ((float*)conv_let)[cse_var_2] = (((float*)conv_let)[cse_var_2] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + vw_1)] * ((float*)fused_constant_2_let)[(((co_outer * 1280) + (ci_1 * 40)) + vc)]));
          }
        }
        for (int32_t vc_1 = 0; vc_1 < 4; ++vc_1) {
          for (int32_t vw_2 = 0; vw_2 < 2; ++vw_2) {
            int32_t cse_var_3 = ((vw_2 * 4) + vc_1);
            ((float*)conv_let)[cse_var_3] = (((float*)conv_let)[cse_var_3] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_2) + 1)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_1) + 4)]));
          }
        }
        for (int32_t vc_2 = 0; vc_2 < 4; ++vc_2) {
          for (int32_t vw_3 = 0; vw_3 < 2; ++vw_3) {
            int32_t cse_var_4 = ((vw_3 * 4) + vc_2);
            ((float*)conv_let)[cse_var_4] = (((float*)conv_let)[cse_var_4] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_3) + 2)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_2) + 8)]));
          }
        }
        for (int32_t vc_3 = 0; vc_3 < 4; ++vc_3) {
          for (int32_t vw_4 = 0; vw_4 < 2; ++vw_4) {
            int32_t cse_var_5 = ((vw_4 * 4) + vc_3);
            ((float*)conv_let)[cse_var_5] = (((float*)conv_let)[cse_var_5] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_4) + 3)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_3) + 12)]));
          }
        }
        for (int32_t vc_4 = 0; vc_4 < 4; ++vc_4) {
          for (int32_t vw_5 = 0; vw_5 < 2; ++vw_5) {
            int32_t cse_var_6 = ((vw_5 * 4) + vc_4);
            ((float*)conv_let)[cse_var_6] = (((float*)conv_let)[cse_var_6] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_5) + 4)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_4) + 16)]));
          }
        }
        for (int32_t vc_5 = 0; vc_5 < 4; ++vc_5) {
          for (int32_t vw_6 = 0; vw_6 < 2; ++vw_6) {
            int32_t cse_var_7 = ((vw_6 * 4) + vc_5);
            ((float*)conv_let)[cse_var_7] = (((float*)conv_let)[cse_var_7] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_6) + 5)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_5) + 20)]));
          }
        }
        for (int32_t vc_6 = 0; vc_6 < 4; ++vc_6) {
          for (int32_t vw_7 = 0; vw_7 < 2; ++vw_7) {
            int32_t cse_var_8 = ((vw_7 * 4) + vc_6);
            ((float*)conv_let)[cse_var_8] = (((float*)conv_let)[cse_var_8] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_7) + 6)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_6) + 24)]));
          }
        }
        for (int32_t vc_7 = 0; vc_7 < 4; ++vc_7) {
          for (int32_t vw_8 = 0; vw_8 < 2; ++vw_8) {
            int32_t cse_var_9 = ((vw_8 * 4) + vc_7);
            ((float*)conv_let)[cse_var_9] = (((float*)conv_let)[cse_var_9] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_8) + 7)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_7) + 28)]));
          }
        }
        for (int32_t vc_8 = 0; vc_8 < 4; ++vc_8) {
          for (int32_t vw_9 = 0; vw_9 < 2; ++vw_9) {
            int32_t cse_var_10 = ((vw_9 * 4) + vc_8);
            ((float*)conv_let)[cse_var_10] = (((float*)conv_let)[cse_var_10] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_9) + 8)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_8) + 32)]));
          }
        }
        for (int32_t vc_9 = 0; vc_9 < 4; ++vc_9) {
          for (int32_t vw_10 = 0; vw_10 < 2; ++vw_10) {
            int32_t cse_var_11 = ((vw_10 * 4) + vc_9);
            ((float*)conv_let)[cse_var_11] = (((float*)conv_let)[cse_var_11] + (((float*)data_vec_let)[((((w_outer * 352) + (ci_1 * 11)) + vw_10) + 9)] * ((float*)fused_constant_2_let)[((((co_outer * 1280) + (ci_1 * 40)) + vc_9) + 36)]));
          }
        }
      }
      for (int32_t w_inner = 0; w_inner < 2; ++w_inner) {
        for (int32_t co_inner = 0; co_inner < 4; ++co_inner) {
          output_unpack[((((co_outer * 800) + (co_inner * 200)) + (w_outer * 2)) + w_inner)] = ((float*)conv_let)[((w_inner * 4) + co_inner)];
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_conv2d_3(float* p0, float* output_unpack, uint8_t* global_const_workspace_20_var, uint8_t* global_workspace_21_var) {
  void* fused_constant_3_let = (&(global_const_workspace_20_var[15319040]));
  void* data_vec_let = (&(global_workspace_21_var[51200]));
  for (int32_t w = 0; w < 25; ++w) {
    for (int32_t ci = 0; ci < 32; ++ci) {
      for (int32_t vw = 0; vw < 11; ++vw) {
        int32_t cse_var_2 = (w * 8);
        int32_t cse_var_1 = (cse_var_2 + vw);
        ((float*)data_vec_let)[(((w * 352) + (ci * 11)) + vw)] = (((1 <= cse_var_1) && (cse_var_1 < 201)) ? p0[((((ci * 200) + cse_var_2) + vw) - 1)] : 0.000000e+00f);
      }
    }
  }
  for (int32_t co_outer = 0; co_outer < 8; ++co_outer) {
    for (int32_t w_outer = 0; w_outer < 25; ++w_outer) {
      void* conv_let = (&(global_workspace_21_var[86400]));
      for (int32_t vc_init = 0; vc_init < 16; ++vc_init) {
        ((float*)conv_let)[vc_init] = 0.000000e+00f;
      }
      for (int32_t vc_init_1 = 0; vc_init_1 < 16; ++vc_init_1) {
        ((float*)conv_let)[(vc_init_1 + 16)] = 0.000000e+00f;
      }
      for (int32_t vc_init_2 = 0; vc_init_2 < 16; ++vc_init_2) {
        ((float*)conv_let)[(vc_init_2 + 32)] = 0.000000e+00f;
      }
      for (int32_t vc_init_3 = 0; vc_init_3 < 16; ++vc_init_3) {
        ((float*)conv_let)[(vc_init_3 + 48)] = 0.000000e+00f;
      }
      for (int32_t ci_1 = 0; ci_1 < 32; ++ci_1) {
        for (int32_t vc = 0; vc < 16; ++vc) {
          ((float*)conv_let)[vc] = (((float*)conv_let)[vc] + (((float*)data_vec_let)[((w_outer * 352) + (ci_1 * 11))] * ((float*)fused_constant_3_let)[(((co_outer * 2560) + (ci_1 * 80)) + vc)]));
        }
        for (int32_t vc_1 = 0; vc_1 < 16; ++vc_1) {
          int32_t cse_var_3 = (vc_1 + 16);
          ((float*)conv_let)[cse_var_3] = (((float*)conv_let)[cse_var_3] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 2)] * ((float*)fused_constant_3_let)[(((co_outer * 2560) + (ci_1 * 80)) + vc_1)]));
        }
        for (int32_t vc_2 = 0; vc_2 < 16; ++vc_2) {
          int32_t cse_var_4 = (vc_2 + 32);
          ((float*)conv_let)[cse_var_4] = (((float*)conv_let)[cse_var_4] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 4)] * ((float*)fused_constant_3_let)[(((co_outer * 2560) + (ci_1 * 80)) + vc_2)]));
        }
        for (int32_t vc_3 = 0; vc_3 < 16; ++vc_3) {
          int32_t cse_var_5 = (vc_3 + 48);
          ((float*)conv_let)[cse_var_5] = (((float*)conv_let)[cse_var_5] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 6)] * ((float*)fused_constant_3_let)[(((co_outer * 2560) + (ci_1 * 80)) + vc_3)]));
        }
        for (int32_t vc_4 = 0; vc_4 < 16; ++vc_4) {
          ((float*)conv_let)[vc_4] = (((float*)conv_let)[vc_4] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 1)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_4) + 16)]));
        }
        for (int32_t vc_5 = 0; vc_5 < 16; ++vc_5) {
          int32_t cse_var_6 = (vc_5 + 16);
          ((float*)conv_let)[cse_var_6] = (((float*)conv_let)[cse_var_6] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 3)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_5) + 16)]));
        }
        for (int32_t vc_6 = 0; vc_6 < 16; ++vc_6) {
          int32_t cse_var_7 = (vc_6 + 32);
          ((float*)conv_let)[cse_var_7] = (((float*)conv_let)[cse_var_7] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 5)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_6) + 16)]));
        }
        for (int32_t vc_7 = 0; vc_7 < 16; ++vc_7) {
          int32_t cse_var_8 = (vc_7 + 48);
          ((float*)conv_let)[cse_var_8] = (((float*)conv_let)[cse_var_8] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 7)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_7) + 16)]));
        }
        for (int32_t vc_8 = 0; vc_8 < 16; ++vc_8) {
          ((float*)conv_let)[vc_8] = (((float*)conv_let)[vc_8] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 2)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_8) + 32)]));
        }
        for (int32_t vc_9 = 0; vc_9 < 16; ++vc_9) {
          int32_t cse_var_9 = (vc_9 + 16);
          ((float*)conv_let)[cse_var_9] = (((float*)conv_let)[cse_var_9] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 4)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_9) + 32)]));
        }
        for (int32_t vc_10 = 0; vc_10 < 16; ++vc_10) {
          int32_t cse_var_10 = (vc_10 + 32);
          ((float*)conv_let)[cse_var_10] = (((float*)conv_let)[cse_var_10] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 6)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_10) + 32)]));
        }
        for (int32_t vc_11 = 0; vc_11 < 16; ++vc_11) {
          int32_t cse_var_11 = (vc_11 + 48);
          ((float*)conv_let)[cse_var_11] = (((float*)conv_let)[cse_var_11] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 8)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_11) + 32)]));
        }
        for (int32_t vc_12 = 0; vc_12 < 16; ++vc_12) {
          ((float*)conv_let)[vc_12] = (((float*)conv_let)[vc_12] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 3)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_12) + 48)]));
        }
        for (int32_t vc_13 = 0; vc_13 < 16; ++vc_13) {
          int32_t cse_var_12 = (vc_13 + 16);
          ((float*)conv_let)[cse_var_12] = (((float*)conv_let)[cse_var_12] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 5)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_13) + 48)]));
        }
        for (int32_t vc_14 = 0; vc_14 < 16; ++vc_14) {
          int32_t cse_var_13 = (vc_14 + 32);
          ((float*)conv_let)[cse_var_13] = (((float*)conv_let)[cse_var_13] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 7)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_14) + 48)]));
        }
        for (int32_t vc_15 = 0; vc_15 < 16; ++vc_15) {
          int32_t cse_var_14 = (vc_15 + 48);
          ((float*)conv_let)[cse_var_14] = (((float*)conv_let)[cse_var_14] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 9)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_15) + 48)]));
        }
        for (int32_t vc_16 = 0; vc_16 < 16; ++vc_16) {
          ((float*)conv_let)[vc_16] = (((float*)conv_let)[vc_16] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 4)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_16) + 64)]));
        }
        for (int32_t vc_17 = 0; vc_17 < 16; ++vc_17) {
          int32_t cse_var_15 = (vc_17 + 16);
          ((float*)conv_let)[cse_var_15] = (((float*)conv_let)[cse_var_15] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 6)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_17) + 64)]));
        }
        for (int32_t vc_18 = 0; vc_18 < 16; ++vc_18) {
          int32_t cse_var_16 = (vc_18 + 32);
          ((float*)conv_let)[cse_var_16] = (((float*)conv_let)[cse_var_16] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 8)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_18) + 64)]));
        }
        for (int32_t vc_19 = 0; vc_19 < 16; ++vc_19) {
          int32_t cse_var_17 = (vc_19 + 48);
          ((float*)conv_let)[cse_var_17] = (((float*)conv_let)[cse_var_17] + (((float*)data_vec_let)[(((w_outer * 352) + (ci_1 * 11)) + 10)] * ((float*)fused_constant_3_let)[((((co_outer * 2560) + (ci_1 * 80)) + vc_19) + 64)]));
        }
      }
      for (int32_t w_inner = 0; w_inner < 4; ++w_inner) {
        for (int32_t co_inner = 0; co_inner < 16; ++co_inner) {
          output_unpack[((((co_outer * 1600) + (co_inner * 100)) + (w_outer * 4)) + w_inner)] = ((float*)conv_let)[((w_inner * 16) + co_inner)];
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_conv2d_4(float* p0, float* output_unpack, uint8_t* global_const_workspace_26_var, uint8_t* global_workspace_27_var) {
  void* fused_constant_4_let = (&(global_const_workspace_26_var[13107200]));
  void* data_vec_let = (&(global_workspace_27_var[102400]));
  for (int32_t w = 0; w < 10; ++w) {
    for (int32_t ci = 0; ci < 128; ++ci) {
      for (int32_t vw = 0; vw < 9; ++vw) {
        int32_t cse_var_2 = (w * 5);
        int32_t cse_var_1 = (cse_var_2 + vw);
        ((float*)data_vec_let)[(((w * 1152) + (ci * 9)) + vw)] = (((2 <= cse_var_1) && (cse_var_1 < 52)) ? p0[((((ci * 50) + cse_var_2) + vw) - 2)] : 0.000000e+00f);
      }
    }
  }
  for (int32_t co_outer = 0; co_outer < 32; ++co_outer) {
    for (int32_t w_outer = 0; w_outer < 10; ++w_outer) {
      void* conv_let = (&(global_workspace_27_var[148480]));
      for (int32_t vc_init = 0; vc_init < 16; ++vc_init) {
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[((vw_init * 16) + vc_init)] = 0.000000e+00f;
        }
      }
      for (int32_t ci_1 = 0; ci_1 < 128; ++ci_1) {
        for (int32_t kw = 0; kw < 5; ++kw) {
          for (int32_t vc = 0; vc < 16; ++vc) {
            for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
              int32_t cse_var_3 = ((vw_1 * 16) + vc);
              ((float*)conv_let)[cse_var_3] = (((float*)conv_let)[cse_var_3] + (((float*)data_vec_let)[((((w_outer * 1152) + (ci_1 * 9)) + vw_1) + kw)] * ((float*)fused_constant_4_let)[((((co_outer * 10240) + (ci_1 * 80)) + (kw * 16)) + vc)]));
            }
          }
        }
      }
      for (int32_t w_inner = 0; w_inner < 5; ++w_inner) {
        for (int32_t co_inner = 0; co_inner < 16; ++co_inner) {
          output_unpack[((((co_outer * 800) + (co_inner * 50)) + (w_outer * 5)) + w_inner)] = ((float*)conv_let)[((w_inner * 16) + co_inner)];
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_conv2d_5(float* p0, float* output_unpack, uint8_t* global_const_workspace_30_var, uint8_t* global_workspace_31_var) {
  void* fused_constant_5_let = (&(global_const_workspace_30_var[14417920]));
  void* data_vec_let = (&(global_workspace_31_var[0]));
  for (int32_t w = 0; w < 10; ++w) {
    for (int32_t ci = 0; ci < 512; ++ci) {
      for (int32_t vw = 0; vw < 7; ++vw) {
        int32_t cse_var_2 = (w * 5);
        int32_t cse_var_1 = (cse_var_2 + vw);
        ((float*)data_vec_let)[(((w * 3584) + (ci * 7)) + vw)] = (((1 <= cse_var_1) && (cse_var_1 < 51)) ? p0[((((ci * 50) + cse_var_2) + vw) - 1)] : 0.000000e+00f);
      }
    }
  }
  for (int32_t co_outer = 0; co_outer < 8; ++co_outer) {
    for (int32_t w_outer = 0; w_outer < 10; ++w_outer) {
      void* conv_let = (&(global_workspace_31_var[168960]));
      for (int32_t vc_init = 0; vc_init < 16; ++vc_init) {
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[((vw_init * 16) + vc_init)] = 0.000000e+00f;
        }
      }
      for (int32_t ci_1 = 0; ci_1 < 512; ++ci_1) {
        for (int32_t kw = 0; kw < 3; ++kw) {
          for (int32_t vc = 0; vc < 16; ++vc) {
            for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
              int32_t cse_var_3 = ((vw_1 * 16) + vc);
              ((float*)conv_let)[cse_var_3] = (((float*)conv_let)[cse_var_3] + (((float*)data_vec_let)[((((w_outer * 3584) + (ci_1 * 7)) + vw_1) + kw)] * ((float*)fused_constant_5_let)[((((co_outer * 24576) + (ci_1 * 48)) + (kw * 16)) + vc)]));
            }
          }
        }
      }
      for (int32_t w_inner = 0; w_inner < 5; ++w_inner) {
        for (int32_t co_inner = 0; co_inner < 16; ++co_inner) {
          output_unpack[((((co_outer * 800) + (co_inner * 50)) + (w_outer * 5)) + w_inner)] = ((float*)conv_let)[((w_inner * 16) + co_inner)];
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_dense_add(float* p0, float* T_add, uint8_t* global_const_workspace_36_var, uint8_t* global_workspace_37_var) {
  void* fused_nn_dense_constant_1_let = (&(global_const_workspace_36_var[15489024]));
  void* fused_constant_7_let = (&(global_const_workspace_36_var[15467520]));
  void* T_matmul_NT_let = (&(global_workspace_37_var[2048]));
  for (int32_t j = 0; j < 7; ++j) {
    ((float*)T_matmul_NT_let)[j] = 0.000000e+00f;
    for (int32_t k = 0; k < 512; ++k) {
      ((float*)T_matmul_NT_let)[j] = (((float*)T_matmul_NT_let)[j] + (p0[k] * ((float*)fused_constant_7_let)[((j * 512) + k)]));
    }
  }
  for (int32_t ax1 = 0; ax1 < 7; ++ax1) {
    T_add[ax1] = (((float*)T_matmul_NT_let)[ax1] + ((float*)fused_nn_dense_constant_1_let)[ax1]);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_dense_add_nn_relu(float* p0, float* T_relu, uint8_t* global_const_workspace_34_var, uint8_t* global_workspace_35_var) {
  void* fused_nn_dense_constant_let = (&(global_const_workspace_34_var[15483904]));
  void* fused_constant_6_let = (&(global_const_workspace_34_var[0]));
  void* T_matmul_NT_let = (&(global_workspace_35_var[25600]));
  for (int32_t j = 0; j < 512; ++j) {
    ((float*)T_matmul_NT_let)[j] = 0.000000e+00f;
    for (int32_t k = 0; k < 6400; ++k) {
      ((float*)T_matmul_NT_let)[j] = (((float*)T_matmul_NT_let)[j] + (p0[k] * ((float*)fused_constant_6_let)[((j * 6400) + k)]));
    }
  }
  void* T_add_let = (&(global_workspace_35_var[2048]));
  for (int32_t ax1 = 0; ax1 < 512; ++ax1) {
    ((float*)T_add_let)[ax1] = (((float*)T_matmul_NT_let)[ax1] + ((float*)fused_nn_dense_constant_let)[ax1]);
  }
  for (int32_t ax1_1 = 0; ax1_1 < 512; ++ax1_1) {
    float v_ = ((float*)T_add_let)[ax1_1];
    T_relu[ax1_1] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_max_pool2d(float* p0, float* pool_max, uint8_t* global_const_workspace_8_var, uint8_t* global_workspace_9_var) {
  for (int32_t ax1 = 0; ax1 < 128; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 400; ++ax2) {
      pool_max[((ax1 * 400) + ax2)] = -3.402823e+38f;
      for (int32_t rv0 = 0; rv0 < 2; ++rv0) {
        int32_t cse_var_1 = ((ax1 * 400) + ax2);
        float v_ = pool_max[cse_var_1];
        float v__1 = p0[(((ax1 * 1200) + (ax2 * 3)) + rv0)];
        pool_max[cse_var_1] = ((v_) > (v__1) ? (v_) : (v__1));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_max_pool2d_1(float* p0, float* pool_max, uint8_t* global_const_workspace_14_var, uint8_t* global_workspace_15_var) {
  for (int32_t ax1 = 0; ax1 < 32; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 200; ++ax2) {
      pool_max[((ax1 * 200) + ax2)] = -3.402823e+38f;
      for (int32_t rv0 = 0; rv0 < 2; ++rv0) {
        int32_t cse_var_1 = ((ax1 * 200) + ax2);
        float v_ = pool_max[cse_var_1];
        float v__1 = p0[(((ax1 * 400) + (ax2 * 2)) + rv0)];
        pool_max[cse_var_1] = ((v_) > (v__1) ? (v_) : (v__1));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_max_pool2d_2(float* p0, float* pool_max, uint8_t* global_const_workspace_24_var, uint8_t* global_workspace_25_var) {
  for (int32_t ax1 = 0; ax1 < 128; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 50; ++ax2) {
      pool_max[((ax1 * 50) + ax2)] = -3.402823e+38f;
      for (int32_t rv0 = 0; rv0 < 2; ++rv0) {
        int32_t cse_var_1 = ((ax1 * 50) + ax2);
        float v_ = pool_max[cse_var_1];
        float v__1 = p0[(((ax1 * 100) + (ax2 * 2)) + rv0)];
        pool_max[cse_var_1] = ((v_) > (v__1) ? (v_) : (v__1));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_nn_softmax(float* p0, float* T_softmax_norm, uint8_t* global_const_workspace_38_var, uint8_t* global_workspace_39_var) {
  void* T_softmax_maxelem_let = (&(global_workspace_39_var[64]));
  ((float*)T_softmax_maxelem_let)[0] = -3.402823e+38f;
  for (int32_t k = 0; k < 7; ++k) {
    float v_ = ((float*)T_softmax_maxelem_let)[0];
    float v__1 = p0[k];
    ((float*)T_softmax_maxelem_let)[0] = ((v_) > (v__1) ? (v_) : (v__1));
  }
  void* T_softmax_exp_let = (&(global_workspace_39_var[32]));
  for (int32_t i1 = 0; i1 < 7; ++i1) {
    ((float*)T_softmax_exp_let)[i1] = expf((p0[i1] - ((float*)T_softmax_maxelem_let)[0]));
  }
  void* T_softmax_expsum_let = (&(global_workspace_39_var[0]));
  ((float*)T_softmax_expsum_let)[0] = 0.000000e+00f;
  for (int32_t k_1 = 0; k_1 < 7; ++k_1) {
    ((float*)T_softmax_expsum_let)[0] = (((float*)T_softmax_expsum_let)[0] + ((float*)T_softmax_exp_let)[k_1]);
  }
  for (int32_t i1_1 = 0; i1_1 < 7; ++i1_1) {
    T_softmax_norm[i1_1] = (((float*)T_softmax_exp_let)[i1_1] / ((float*)T_softmax_expsum_let)[0]);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_squeeze_add_nn_relu_expand_dims(float* p0, float* T_expand_dims, uint8_t* global_const_workspace_18_var, uint8_t* global_workspace_19_var) {
  void* fused_squeeze_constant_2_let = (&(global_const_workspace_18_var[15488512]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 32; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax3_outer = 0; ax3_outer < 50; ++ax3_outer) {
      for (int32_t ax3_inner = 0; ax3_inner < 4; ++ax3_inner) {
        int32_t cse_var_1 = (((ax0_ax1_fused_ax2_fused * 200) + (ax3_outer * 4)) + ax3_inner);
        float v_ = p0[cse_var_1] + ((float*)fused_squeeze_constant_2_let)[ax0_ax1_fused_ax2_fused];
        T_expand_dims[cse_var_1] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_squeeze_add_nn_relu_expand_dims_1(float* p0, float* T_expand_dims, uint8_t* global_const_workspace_28_var, uint8_t* global_workspace_29_var) {
  void* fused_squeeze_constant_4_let = (&(global_const_workspace_28_var[15481856]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 512; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax3_outer = 0; ax3_outer < 13; ++ax3_outer) {
      for (int32_t ax3_inner = 0; ax3_inner < 4; ++ax3_inner) {
        if (((ax3_outer * 2) + (ax3_inner >> 1)) < 25) {
          int32_t cse_var_1 = (((ax0_ax1_fused_ax2_fused * 50) + (ax3_outer * 4)) + ax3_inner);
          float v_ = p0[cse_var_1] + ((float*)fused_squeeze_constant_4_let)[ax0_ax1_fused_ax2_fused];
          T_expand_dims[cse_var_1] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_squeeze_add_nn_relu_expand_dims_reshape(float* p0, float* T_reshape, uint8_t* global_const_workspace_22_var, uint8_t* global_workspace_23_var) {
  void* fused_squeeze_constant_3_let = (&(global_const_workspace_22_var[15486464]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 12800; ++ax0_ax1_fused_ax2_fused) {
    float v_ = p0[ax0_ax1_fused_ax2_fused] + ((float*)fused_squeeze_constant_3_let)[(ax0_ax1_fused_ax2_fused / 100)];
    T_reshape[ax0_ax1_fused_ax2_fused] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_squeeze_add_nn_relu_multiply_add_expand_dims_reshape(float* p0, float* T_reshape, uint8_t* global_const_workspace_6_var, uint8_t* global_workspace_7_var) {
  void* fused_squeeze_add_nn_relu_multiply_constant_let = (&(global_const_workspace_6_var[15487488]));
  void* fused_squeeze_add_nn_relu_constant_let = (&(global_const_workspace_6_var[15488000]));
  void* fused_squeeze_constant_let = (&(global_const_workspace_6_var[15486976]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 153600; ++ax0_ax1_fused_ax2_fused) {
    int32_t cse_var_1 = (ax0_ax1_fused_ax2_fused / 1200);
    float v_ = p0[ax0_ax1_fused_ax2_fused] + ((float*)fused_squeeze_constant_let)[cse_var_1];
    T_reshape[ax0_ax1_fused_ax2_fused] = ((((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f)) * ((float*)fused_squeeze_add_nn_relu_constant_let)[cse_var_1]) + ((float*)fused_squeeze_add_nn_relu_multiply_constant_let)[cse_var_1]);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_squeeze_add_nn_relu_multiply_add_expand_dims_reshape_1(float* p0, float* T_reshape, uint8_t* global_const_workspace_12_var, uint8_t* global_workspace_13_var) {
  void* fused_squeeze_add_nn_relu_multiply_constant_1_let = (&(global_const_workspace_12_var[15488768]));
  void* fused_squeeze_add_nn_relu_constant_1_let = (&(global_const_workspace_12_var[15488896]));
  void* fused_squeeze_constant_1_let = (&(global_const_workspace_12_var[15488640]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 12800; ++ax0_ax1_fused_ax2_fused) {
    int32_t cse_var_1 = (ax0_ax1_fused_ax2_fused / 400);
    float v_ = p0[ax0_ax1_fused_ax2_fused] + ((float*)fused_squeeze_constant_1_let)[cse_var_1];
    T_reshape[ax0_ax1_fused_ax2_fused] = ((((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f)) * ((float*)fused_squeeze_add_nn_relu_constant_1_let)[cse_var_1]) + ((float*)fused_squeeze_add_nn_relu_multiply_constant_1_let)[cse_var_1]);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls_fused_squeeze_add_nn_relu_transpose_reshape(float* p0, float* T_reshape, uint8_t* global_const_workspace_32_var, uint8_t* global_workspace_33_var) {
  void* fused_squeeze_constant_5_let = (&(global_const_workspace_32_var[15485952]));
  for (int32_t ax1_outer = 0; ax1_outer < 1600; ++ax1_outer) {
    for (int32_t ax1_inner = 0; ax1_inner < 4; ++ax1_inner) {
      int32_t cse_var_1 = (ax1_outer & 31);
      float v_ = p0[(((cse_var_1 * 200) + (ax1_inner * 50)) + (ax1_outer >> 5))] + ((float*)fused_squeeze_constant_5_let)[((cse_var_1 * 4) + ax1_inner)];
      T_reshape[((ax1_outer * 4) + ax1_inner)] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_cls___tvm_main__(float* x_buffer_var, float* output_buffer_var, uint8_t* global_const_workspace_0_var, uint8_t* global_workspace_1_var) {
  void* sid_9_let = (&(global_workspace_1_var[0]));
  void* sid_11_let = (&(global_workspace_1_var[51200]));
  void* sid_7_let = (&(global_workspace_1_var[140800]));
  void* sid_12_let = (&(global_workspace_1_var[0]));
  void* sid_6_let = (&(global_workspace_1_var[0]));
  void* sid_10_let = (&(global_workspace_1_var[0]));
  void* sid_2_let = (&(global_workspace_1_var[614400]));
  void* sid_13_let = (&(global_workspace_1_var[0]));
  void* sid_8_let = (&(global_workspace_1_var[140800]));
  void* sid_1_let = (&(global_workspace_1_var[52000]));
  void* sid_4_let = (&(global_workspace_1_var[819200]));
  void* sid_3_let = (&(global_workspace_1_var[0]));
  void* sid_5_let = (&(global_workspace_1_var[819200]));
  void* sid_14_let = (&(global_workspace_1_var[143360]));
  void* sid_15_let = (&(global_workspace_1_var[143360]));
  void* sid_16_let = (&(global_workspace_1_var[0]));
  void* sid_17_let = (&(global_workspace_1_var[0]));
  void* sid_18_let = (&(global_workspace_1_var[0]));
  if (tvmgen_cls_fused_expand_dims_reshape(x_buffer_var, sid_1_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_conv2d(sid_1_let, sid_2_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_squeeze_add_nn_relu_multiply_add_expand_dims_reshape(sid_2_let, sid_3_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_max_pool2d(sid_3_let, sid_4_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_conv2d_1(sid_4_let, sid_5_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_squeeze_add_nn_relu_multiply_add_expand_dims_reshape_1(sid_5_let, sid_6_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_max_pool2d_1(sid_6_let, sid_7_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_conv2d_2(sid_7_let, sid_8_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_squeeze_add_nn_relu_expand_dims(sid_8_let, sid_9_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_conv2d_3(sid_9_let, sid_10_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_squeeze_add_nn_relu_expand_dims_reshape(sid_10_let, sid_11_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_max_pool2d_2(sid_11_let, sid_12_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_conv2d_4(sid_12_let, sid_13_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_squeeze_add_nn_relu_expand_dims_1(sid_13_let, sid_14_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_conv2d_5(sid_14_let, sid_15_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_squeeze_add_nn_relu_transpose_reshape(sid_15_let, sid_16_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_dense_add_nn_relu(sid_16_let, sid_17_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_dense_add(sid_17_let, sid_18_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_cls_fused_nn_softmax(sid_18_let, output_buffer_var, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  return 0;
}

