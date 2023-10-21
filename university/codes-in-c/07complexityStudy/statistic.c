// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#include "statistic.h"

Statistic *new_statistic() {
    Statistic *statistic = (Statistic *) malloc(sizeof(Statistic));

    if (statistic == NULL) {
        puts("Insufficient Memory!");
        exit(1);
    }
    
    statistic->number_tranfers = 0;
    statistic->number_comparisons = 0;
    statistic->time_create_index = 0;
    statistic->search_time = 0;
    statistic->time_total = 0;

    return statistic;
}

free_statistic(Statistic *statistic) {
    free(statistic);
}

void print_statistics(Statistic *statistic) {
    printf("-------------ESTATISTICAS------------- \n");
    printf("NUMERO DE TRANSFERENCIAS: %d\n", get_number_tranfers(statistic));
    printf("NUMERO DE COMPARACOES: %d\n", get_number_comparisons(statistic));
    printf("TEMPO GASTO CRIACAO DE INDICES: %ld\n", get_time_create_index(statistic));
    printf("TEMPO GASTO NA PESQUISA: %ld\n", get_time_research(statistic));
    printf("TEMPO TOTAL DE EXECUCAO: %ld\n", get_time_total(statistic));
}

void increment_tranfer(Statistic *statistic) {
    statistic->number_tranfers++;
}

void increment_comparison(Statistic *statistic) {
    statistic->number_comparisons++;
}

void start_index_creation_time(Statistic *statistic) {
    statistic->index_creation_start_time = clock();
}

void end_index_creation_time(Statistic *statistic) {
    statistic->index_creation_end_time = clock();
}

void calculate_creation_time(Statistic *statistic) {
    statistic->time_create_index = ((statistic->index_creation_end_time - statistic->index_creation_start_time) / (CLOCKS_PER_SEC / 1000));
}

void start_search_time(Statistic *statistic) {
    statistic->start_time_research = clock();
    
}

void end_search_time(Statistic *statistic) {
    statistic->end_time_research = clock();
}

void calculate_search_time(Statistic *statistic){
    statistic->search_time = ((statistic->end_time_research - statistic->start_time_research) / (CLOCKS_PER_SEC / 1000));
}

void total_program_time(Statistic *statistic) {
    statistic->time_total = statistic->search_time + statistic->time_create_index;
}

// GETs
int get_number_tranfers(Statistic *statistic) {
    return statistic->number_tranfers;
}

int get_number_comparisons(Statistic *statistic) {
    return statistic->number_comparisons;
}

double get_time_create_index(Statistic *statistic) {
    return statistic->time_create_index;
}

double get_time_research(Statistic *statistic) {
    return statistic->search_time;
}

double get_time_total(Statistic *statistic) {
    return statistic->time_total;
}

// SETs
void set_number_tranfers(Statistic *statistic, int num_tranfers) {
    statistic->number_tranfers = num_tranfers;
}

void set_number_comparisons(Statistic *statistic, int num_comparisons) {
    statistic->number_comparisons = num_comparisons;
}
void set_time_create_index(Statistic *statistic, double time_create_index) {
    statistic->time_create_index = time_create_index;
}
void set_time_research(Statistic *statistic, double time_research){
    statistic->search_time = time_research;
}

void set_time_total(Statistic *statistic, double time_total) {
    statistic->time_total = time_total;
}