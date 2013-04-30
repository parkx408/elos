//
//  cache.h
//  csim
//
//  Created by Nohhyun Park on 4/30/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#ifndef csim_cache_h
#define csim_cache_h

typedef struct cache_s {
    ref_num_t ref_num;
    cbn_t cbn_in_blocks;
    lru_stack_t *stack;
} cache_t;

void init_cache (cache_t *cache);
void delete_cache (cache_t *cache);
ref_num_t allocate (cache_t *cache, lbn_t lbn, rs_t size);


#endif
