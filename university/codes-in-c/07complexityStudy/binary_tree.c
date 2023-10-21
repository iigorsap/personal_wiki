// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#include "binary_tree.h"

void new_binary_tree(FILE *binary_file_in, FILE *tree_out, Statistic *stat) {
    
    fseek(binary_file_in, 0, SEEK_SET);

    Registry registry;
    Node *node_child;
    Node *node_aux;

    int cont = 0;     

    while(fread(&registry, sizeof(Registry), 1, binary_file_in) == 1) { // verifica leitura
        // Iniciando 
        fill_node(node_child, registry, cont);
        fwrite(&node_child, sizeof(Node), 1, tree_out);

        if (cont != 1) {
            fseek(tree_out, 0, SEEK_SET);
            
            while (fread(&node_aux, sizeof(Node), 1, tree_out) == 1) {
                if (registry.search_key < node_aux->registry.search_key) {
                    
                }
                
            }
        }
        
    }

}

int binary_tree_search(FILE *tree, Node *node, Registry *searched_registry, Statistic *stat){
    
    

    return 1;
} 

int verify_node(FILE *tree, Node *node, Statistic *stat, int pos){}

void fill_node(Node *node, Registry registry, int position){
    node->node_left = -1;
    node->node_right = -1;
    node->registry = registry;
    node->position = position;
}