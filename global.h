#ifndef _GLOBAL_
#define _GLOBAL_

#include <stdint.h>

typedef enum {
  SEAGATE,
  VSCSI1,
  VSCSI2
} trace_format_t;

typedef struct env_s {
  char *file_name;
  trace_format_t trace_format;
} env_t;

env_t env;

typedef uint64_t cbn_t;
typedef uint64_t lbn_t; 
typedef uint64_t ref_num_t;
typedef uint16_t rs_t;
 
#endif
