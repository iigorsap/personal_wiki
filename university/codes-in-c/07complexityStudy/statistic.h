// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#ifndef STATISTIC_H
#define STATISTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

    typedef struct statistic{
        int number_tranfers;
        int number_comparisons; 
        double time_create_index;
        double search_time;
        double time_total;
        clock_t index_creation_start_time;
        clock_t index_creation_end_time;
        clock_t start_time_research;
        clock_t end_time_research;
    }Statistic;

    Statistic *new_statistic();
    free_statistic(Statistic *statistic);

    void print_statistics(Statistic *statistic);

    void increment_tranfer(Statistic *statistic);
    void increment_comparison(Statistic *statistic);
    
    void start_index_creation_time(Statistic *statistic);
    void end_index_creation_time(Statistic* statistic);
    void calculate_creation_time(Statistic *statistic);

    void start_search_time(Statistic *statistic);
    void end_search_time(Statistic *statistic);
    void calculate_search_time(Statistic *statistic);
    
    void total_program_time(Statistic *statistic);

    // GETs
    int get_number_tranfers(Statistic *statistic);
    int get_number_comparisons(Statistic *statistic);
    double get_time_create_index(Statistic *statistic);
    double get_time_research(Statistic *statistic);
    double get_time_total(Statistic *statistic);

    // SETs
    void set_number_tranfers(Statistic *statistic, int num_tranfers);
    void set_number_comparisons(Statistic *statistic, int num_comparisons);
    void set_time_create_index(Statistic *statistic, double time_create_index);
    void set_time_research(Statistic *statistic, double time_research);
    void set_time_total(Statistic *statistic, double time_total);
#endif 
