//
//  main.c
//  csim
//
//  Created by Nohhyun Park on 4/28/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <stdint.h>

#include "global.h"
#include "lru_stack.h"
#include "trace.h"

void parse_options (int argc, const char *argv[]) {
  
  int opt;
  while ((opt = getopt(argc, argv, "t:f:")) != -1) {
    switch (opt) {
      case 't':
        env.file_name = optarg;
        break;
      case 'f':
        env.trace_format = SEAGATE;
        break;
      default:
        fprintf (stderr, "Usage: %s [-t trace file] [-f trace format]\n",
                 argv[0]);
        exit(EXIT_FAILURE);
    }
  }
}

int main(int argc, const char * argv[])
{
  
  parse_options (argc, argv);
  
  FILE *tr_s = fopen(env.file_name, "r");
  if (!tr_s) {
    perror ("failed to open trace file");
    exit (EXIT_FAILURE);
  }
  tr_entry_t record;
  
  
  lru_stack_t *stack = malloc(sizeof(lru_stack_t));
  init_lru_stack(stack);
  
  ref_num_t ref_num = 0;
  lbn_t prev_lbn = 0;
  time_t prev_st = 0;
  
  while (1 == fread (&record, sizeof (tr_entry_t), 1, tr_s)) {
    time_t st = (uint64_t)record.sth << 32;
    st = st | record.stl;
    lbn_t lbn = (uint64_t)record.lbah << 32;
    lbn = lbn | record.lbal;
    if (ref_num == 0) {
      prev_lbn = lbn;
      prev_st = st;
    }
  
    ref_num_t dist = push(stack, lbn, ref_num);
    printf ("%c %hhu %hu %llu %lu %u %ld %lld %llu\n", record.rw, record.dn, record.sc, lbn, st, record.e, st-prev_st, lbn-prev_lbn, dist);
    
    ref_num ++;
  }

  delete_lru_stack(stack);
  free(stack);
  return 0;
}

