// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#include "file.h"

void new_file(int qtt_registry, int order) {

    FILE *file;
    Registry *registry;

    if ((file = fopen("dados.bin", "wb")) == NULL) {
        puts("Failed to open");
        return 0; 
    }

    if (order == 1) {
        ascending_file(qtt_registry, &registry, file);
    }
    else if (order == 2) {
        descending_file(qtt_registry, &registry, file);    
    }
    else if (order == 0) {
        random_file(qtt_registry, &registry, file);
    } 
    else {
        puts("Invalid order");
    }
    
    fclose(file);
}

void view_file(FILE * file) {
    Registry registry;
    int i = 1;

    fseek(file, 0, SEEK_SET);

    while (fread(&registry, sizeof(Registry), 1, file) == 1) {
        printf("Key %d : %d\n", i, registry.search_key);
        i++;
    }
     
    fseek(file, 0, SEEK_SET);
}

void ascending_file(int qtt_registry, Registry* registry, FILE* file) {
    
    registry = new_registry();

    for (int i = 0; i < qtt_registry; i++)
    {
        registry->search_key = i + 1;

        fwrite(registry, sizeof(Registry), 1, file);
    }

    free_registry(registry);

}

void descending_file(int qtt_registry, Registry* registry, FILE* file) {
    
    registry = new_registry();

    for (int i = 0; i < qtt_registry; i++)
    {
        registry->search_key = qtt_registry - 1;

        fwrite(registry, sizeof(Registry), 1, file);
    }

    free_registry(registry);
    
}

void random_file(int qtt_registry, Registry* registry, FILE* file) {
    
    registry = new_registry();
    srand(time(NULL));
    
    int temp;

    int *keys = (int *) malloc(qtt_registry * sizeof(int));

    for (int i = 0; i < qtt_registry; i++){
        keys[i] = i + 1;
    }

    for (int i = 0; i < qtt_registry; i++){
        
        int random_index = rand() % qtt_registry;
        temp = keys[random_index];
        keys[random_index] = keys[qtt_registry - 1]; //troca ultima posição com o que ja foi usado.
        qtt_registry--;

        fwrite(registry, sizeof(Registry), 1, file);
    }

    free(keys);    
}

