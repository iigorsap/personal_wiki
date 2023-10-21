// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#ifndef FILE_H
#define FILE_H

    #include "registry.h"
    #include "time.h"

    void new_file(int qtt_registry, int order);
    void view_file(FILE * file);
    void ascending_file(int qtt_registry, Registry* registry, FILE* file);
    void descending_file(int qtt_registry, Registry* registry, FILE* file);
    void random_file(int qtt_registry, Registry* registry, FILE* file);

#endif 
