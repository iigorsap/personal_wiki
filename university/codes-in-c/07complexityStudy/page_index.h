// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#ifndef PAGE_INDEX_H
#define PAGE_INDEX_H

#include "registry.h"
#include "statistic.h"
    
    #define SIZE_PAGE_REGISTRY 4 // Quantidade de registros por página
    #define MAX_TABLE_SIZE 1000000

    typedef struct page_index{
        int index_key;
    }PageIndex;

    PageIndex* new_table_page_index(FILE* arq, Statistic* st, int order);
    
    void free_table_page_index(PageIndex* page_index);

    // GETs
    int get_page_index(PageIndex* page_index, int pos);

    // SETs 
    void set_page_index(PageIndex* page_index, int pos, int index);
    
#endif 
