//
//  red_black_tree.h
//  csim
//
//  Created by Nohhyun Park on 4/30/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#ifndef csim_red_black_tree_h
#define csim_red_black_tree_h

#include "global.h"

typedef struct rbtree {
    ref_num_t ref_num;
    char color_field;
    struct rbtree *left;
    struct rbtree *right;
} rbtree;

void rbtree_add (struct rbtree **rbtree, ref_num_t ref_num);
void rbtree_rm (struct rbtree **rbtree, ref_num_t ref_num);
void delete_rbtree (struct rbtree *rbtree);
ref_num_t rbtree_length (struct rbtree *rbtree);
ref_num_t compute_distance (struct rbtree *rbtree, ref_num_t ref_num);
#endif
