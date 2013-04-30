//
//  hash_table.h
//  csim
//
//  Created by Nohhyun Park on 4/28/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#ifndef csim_hash_table_h
#define csim_hash_table_h

#include <stdint.h>

#include "global.h"

// allocate 12KB at a time. - needs tunning.
#define HASH_TAB_SIZE  512

typedef struct ht_entry_s {
  cbn_t cbn;
  ref_num_t ref_num;
  struct ht_entry_s *next;
} ht_entry_t;

// XXX: no iterator for now.
void init_ht (ht_entry_t **ht);
ht_entry_t* hash_lookup (ht_entry_t **ht, uint64_t cbn);
void hash_add (ht_entry_t **ht, ht_entry_t* ht_entry);
void delete_ht (ht_entry_t **ht);

#endif
