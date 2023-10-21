// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

    #include "stdlib.h"
    #include "stdio.h"

    #include "registry.c"
    #include "statistic.h"

    typedef struct node{
        Registry registry;
        int position;
        int node_left, node_right;
    }Node;

    void new_binary_tree(FILE *binary_file_in, FILE *tree_out, Statistic *stat);
    int binary_tree_search(FILE *tree, Node *node, Registry *searched_registry, Statistic *stat);

    // GETs
    get_registry(FILE *binary_file);
    
#endif 