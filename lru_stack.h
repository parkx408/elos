//
//  lru_stack.h
//  csim
//
//  Created by Nohhyun Park on 4/30/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#ifndef csim_lru_stack_h
#define csim_lru_stack_h

#include "global.h"
#include "hash_table.h"
#include "red_black_tree.h"

typedef struct lru_stack_s {
    struct rbtree *tree;
    ht_entry_t *ht[HASH_TAB_SIZE];
} lru_stack_t;

ref_num_t push (lru_stack_t *stack, cbn_t cbn, ref_num_t ref_num);
void init_lru_stack (lru_stack_t *stack);
void delete_lru_stack (lru_stack_t *stack);

#endif
