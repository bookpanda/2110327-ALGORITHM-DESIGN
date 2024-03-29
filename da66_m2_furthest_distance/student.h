#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    if(!n) return -1;
    int maxl = my_recur(n->left, aux);
    int maxr = my_recur(n->right, aux);
    aux = std::max(aux, 2 + maxl + maxr); //lvl left + lvl right + 2 edges to root node
    return 1 + std::max(maxl, maxr); //return level of tree
    
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
    if(!mRoot) return -1;
    int a = 0;
    my_recur(mRoot, a);
    return a;
}

#endif
