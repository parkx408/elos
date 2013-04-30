//
//  hash_table.c
//  csim
//
//  Created by Nohhyun Park on 4/28/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "sglib.h"
#include "hash_table.h"

#define HT_ENTRY_COMPARATOR(e1, e2)    (e1->cbn - e2->cbn)

uint64_t ht_entry_hash_function(ht_entry_t *e) {
    return(e->cbn);
}

SGLIB_DEFINE_LIST_PROTOTYPES(ht_entry_t, HT_ENTRY_COMPARATOR, next)
SGLIB_DEFINE_LIST_FUNCTIONS(ht_entry_t, HT_ENTRY_COMPARATOR, next)
SGLIB_DEFINE_HASHED_CONTAINER_PROTOTYPES(ht_entry_t, HASH_TAB_SIZE,
                                         ht_entry_hash_function)
SGLIB_DEFINE_HASHED_CONTAINER_FUNCTIONS(ht_entry_t, HASH_TAB_SIZE, ht_entry_hash_function)

void init_ht (ht_entry_t **ht) {
    sglib_hashed_ht_entry_t_init(ht);
}

ht_entry_t* hash_lookup (ht_entry_t **ht, uint64_t cbn) {
    ht_entry_t entry = {cbn, 0, NULL};
    ht_entry_t *ret = sglib_hashed_ht_entry_t_find_member(ht, &entry);
    if (ret) {
        return ret;
    } else {
        return NULL;
    }
}

void hash_add (ht_entry_t **ht, ht_entry_t* entry) {
    sglib_hashed_ht_entry_t_add(ht, entry);
}

void delete_ht (ht_entry_t **ht) {
    ht_entry_t *i;
    struct sglib_hashed_ht_entry_t_iterator it;
    for (i = sglib_hashed_ht_entry_t_it_init(&it, ht); i != NULL;
         i = sglib_hashed_ht_entry_t_it_next(&it)) {
        free(i);
    }
}