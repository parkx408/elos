//
//  lru_stack.c
//  csim
//
//  Created by Nohhyun Park on 4/30/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "lru_stack.h"

ref_num_t push (lru_stack_t *stack, cbn_t cbn, ref_num_t ref_num) {
    ht_entry_t *res = hash_lookup(stack->ht, cbn);
    ref_num_t dist;
    if (res) {
        dist = compute_distance(stack->tree, ref_num);
        rbtree_rm(&stack->tree, res->ref_num);
        res->ref_num = ref_num;
    } else {
        ht_entry_t *entry = malloc(sizeof(ht_entry_t));
        entry->cbn = cbn;
        entry->ref_num = ref_num;
        hash_add(stack->ht, entry);
    }
    rbtree_add(&stack->tree, ref_num);
    return dist;
}

void init_lru_stack (lru_stack_t *stack) {
    init_ht(stack->ht);
}

void delete_lru_stack (lru_stack_t *stack) {
    delete_ht(stack->ht);
    delete_rbtree(stack->tree);
}
