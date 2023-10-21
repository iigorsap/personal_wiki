// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#include "page_index.h"


typedef struct page_index{
    int index_key;
}PageIndex;

/* Criação do índice de páginas para armazenar os itens e depois realizar pesquisa */
PageIndex* new_table_page_index(FILE* arq, Statistic* st, int order) {
    
    PageIndex *table = (PageIndex*) malloc(MAX_TABLE_SIZE * sizeof(PageIndex));
    
    if (table == NULL) {
        puts("Insufficient Memory to create table!");
        exit(1);
    }
    
    Registry *aux; 
    int i = 0;

    while (fread(&aux, sizeof(Registry), 1, arq) == 1) {
        increment_tranfer(st);
    
        set_page_index(table, i, aux->search_key);
    
        i++; 
    
        fseek(arq, (SIZE_PAGE_REGISTRY - 1) * sizeof(Registry), SEEK_CUR);
    }

    fseek(arq, 0, SEEK_SET);

    if (order == 1) // Crescente
    {
        while (i < MAX_TABLE_SIZE)
        {
            table[i].index_key = 2000000;
            i++;
        }
    }
    else
    {
        while (i < MAX_TABLE_SIZE)
        {
            table[i].index_key = -2000000;
            i++;
        }
    }


    return table;
}

void free_table_page_index(PageIndex* page_index){
    free(page_index);
}

// GETs
int get_page_index(PageIndex* page_index, int pos) {
    return page_index[pos].index_key;
}

// SETs 
void set_page_index(PageIndex* page_index, int pos, int index) {
    page_index[pos].index_key = index;
}