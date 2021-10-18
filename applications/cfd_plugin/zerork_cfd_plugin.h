#ifndef ZERORK_CVREACTOR_LIB_H
#define ZERORK_CVREACTOR_LIB_H


#ifdef __cplusplus  /* wrapper to enable C++ usage */
extern "C" {
#endif

typedef enum _zerork_field_type {
  ZERORK_FIELD_DPDT,
  ZERORK_FIELD_COST,
  ZERORK_FIELD_Y_SRC,
  ZERORK_FIELD_E_SRC
} zerork_field_type;

typedef struct zerork_handle_impl* zerork_handle;
zerork_handle zerork_reactor_init(const char* input_filename,
                        const char* mech_file,
                        const char* therm_file);

int zerork_reactor_solve(const int n_cycle, const double time,
                         const double dt, const int n_reactors,
                         double *T, double *P,
                         double *mf,
                         zerork_handle handle);

int zerork_reactor_set_aux_field_pointer(zerork_field_type ft, double * field_pointer, zerork_handle handle);

int zerork_reactor_set_int_option(const char* option_name_chr,
                                  int option_value,
                                  zerork_handle handle);

int zerork_reactor_set_double_option(const char* option_name_chr,
                                     double option_value,
                                     zerork_handle handle);

int zerork_reactor_get_int_option(const char* option_name_chr,
                                  int* option_value,
                                  zerork_handle handle);

int zerork_reactor_get_double_option(const char* option_name_chr,
                                     double* option_value,
                                     zerork_handle handle);

int zerork_reactor_free(zerork_handle handle); 


#ifdef __cplusplus
}
#endif


#endif
