// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#include "registry.h"

Registry* new_registry() {
    
    Registry* registry = (Registry*) malloc(sizeof(Registry));
    
    if (registry == NULL) {
        puts("Insufficient Memory!");
        exit(1);
    }

    registry->search_key = -1;
    registry->data_long_int = -1;
    strcpy(registry->cData, "");
    strcpy(registry->cData_02, "");

    return registry;  
}

void free_registry(Registry* registry) {
    free(registry);
}

void print_registry(Registry* registry){
    printf("DADOS DO REGISTRO: \n");
    printf("CHAVE: %d\n", get_search_key(registry));
    printf("DADO 1: %ld\n", get_data_long_int(registry));
    printf("DADO 2: %s\n", get_cData(registry));
    printf("DADO 3: %s\n", get_cData_02(registry));
}

// GETs
int get_search_key(Registry* registry){
    return registry->search_key;
}

long int get_data_long_int(Registry* registry){
    return registry->data_long_int;
}

char* get_cData(Registry* registry){
    return registry->cData;
}

char* get_cData_02(Registry* registry){
    return registry->cData_02;
}

// SETs
void set_key(Registry* registry, int key){
    registry->search_key = key;
}

void set_data_long_int(Registry* registry, long int data_long_int){
    registry->data_long_int = data_long_int;
}

void set_cData(Registry* registry, char* cData){
    strcpy(registry->cData, cData);
}

void set_cData_02(Registry* registry, char* cData_02){
    strcpy(registry->cData_02, cData_02);
}