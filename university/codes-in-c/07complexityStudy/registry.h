// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#ifndef REGISTRY_H
#define REGISTRY_H

#include "string.h"
#include "stdio.h"

    typedef struct registry {
        int search_key; 
        long int data_long_int;  
        char cData[1000];
        char cData_02[5000];
    }Registry;

    Registry* new_registry();
    void free_registry(Registry* registry);
    void print_registry(Registry* registry);

    // GETs
    int get_search_key(Registry* registry);
    long int get_data_long_int(Registry* registry);
    char* get_cData(Registry* registry);
    char* get_cData_02(Registry* registry);

    // SETs
    void set_key(Registry* registry, int key);
    void set_data_long_int(Registry* registry, long int data_long_int);
    void set_cData(Registry* registry, char* Data);
    void set_cData_02(Registry* registry, char* Data);

#endif