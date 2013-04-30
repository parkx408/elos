//
//  red_black_tree.c
//  csim
//
//  Created by Nohhyun Park on 4/30/13.
//  Copyright (c) 2013 Nohhyun Park. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.h"
#include "sglib.h"


#define CMPARATOR(x,y) (int)((x->ref_num)-(y->ref_num))

SGLIB_DEFINE_RBTREE_PROTOTYPES(rbtree, left, right, color_field, CMPARATOR);
SGLIB_DEFINE_RBTREE_FUNCTIONS(rbtree, left, right, color_field, CMPARATOR);

void rbtree_add (struct rbtree **rbtree, ref_num_t ref_num) {
    struct rbtree *tmp = malloc(sizeof(struct rbtree));
    tmp->ref_num = ref_num;
    sglib_rbtree_add(rbtree, tmp);
}

void rbtree_rm (struct rbtree **rbtree, ref_num_t ref_num) {
    struct rbtree tmp;
    tmp.ref_num = ref_num;
    struct rbtree *rm;
    sglib_rbtree_delete_if_member(rbtree, &tmp, &rm);
    free(rm);
}

void delete_rbtree (rbtree *rbtree) {
    struct sglib_rbtree_iterator it;
    struct rbtree *te;
    for(te = sglib_rbtree_it_init(&it,rbtree); te != NULL; te = sglib_rbtree_it_next(&it)) {
        free(te);
    }
}

ref_num_t compute_distance (rbtree *rbtree, ref_num_t ref_num) {
    struct sglib_rbtree_iterator it;
    struct rbtree * te;
    int dist = 0;
    for(te = sglib_rbtree_it_init_inorder(&it, rbtree); te != NULL; te = sglib_rbtree_it_next(&it)) {
        dist ++;
    }
    return dist;
}

ref_num_t rbtree_length (rbtree *rbtree) {
    return(sglib_rbtree_len(rbtree));
}