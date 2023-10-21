// Created by Igor Santiago - 19.1.4033 on 28/07/2021.

#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MedalsBoard *new_board(MedalsBoard *medals_board, int number_countries){
    medals_board = (MedalsBoard *) malloc(number_countries * sizeof(MedalsBoard));
    if ( medals_board == NULL)
    {
        printf("Insufficient Memory.\n");
        exit(1);
    }

    return medals_board;
}

MedalsBoard *free_board(MedalsBoard *medals_board){
    free(medals_board);
    medals_board = NULL;
    return medals_board;
}

void size_of_board(int *number_countries){
    scanf("%d", number_countries);
}

void fill_medals_board(MedalsBoard *medals_board, int number_countries){
    
    for (int i = 0; i < number_countries; i++){
       scanf("%s", medals_board[i].country); 
       scanf("%d", &medals_board[i].gold_medals);
       scanf("%d", &medals_board[i].silver_medals);
       scanf("%d", &medals_board[i].bronze_medals);
    }
}

void print_medals_board(MedalsBoard *medals_board, int number_countries){
    
    for (int i = 0; i < number_countries; i++){
       printf("%s", medals_board[i].country); 
       printf(" %d", medals_board[i].gold_medals);
       printf(" %d", medals_board[i].silver_medals);
       printf(" %d\n", medals_board[i].bronze_medals);
    }
}

void order_golds(MedalsBoard *medals_board, int number_countries){
    
    int max;
    MedalsBoard *aux = (MedalsBoard *) malloc(1 * sizeof(MedalsBoard));

    for (int i = 0; i < number_countries; i++)
    {
        max = i;

        for (int j = (i+1); j < number_countries; j++)
        {
            if (medals_board[j].gold_medals > medals_board[max].gold_medals)
            {
                max = j;
            }
        }
        if (i != max ){
            if(medals_board[max].gold_medals > medals_board[i].gold_medals){
                aux[0] = medals_board[max];
                medals_board[max] = medals_board[i];
                medals_board[i] = aux[0];
            }

        }
    }
    
    free(aux);

}


void order_silvers(MedalsBoard *medals_board, int number_countries){
    
    int max;
    MedalsBoard *aux = (MedalsBoard *) malloc(1 * sizeof(MedalsBoard));

    for (int i = 0; i < number_countries; i++)
    {
        max = i;

        for (int j = (i+1); j < number_countries; j++)
        {
            if ((medals_board[j].gold_medals == medals_board[max].gold_medals) && 
                (medals_board[j].silver_medals > medals_board[max].silver_medals)
            ){
                max = j;
            }
        }
        
        if (i != max){
            
            aux[0] = medals_board[max];
            medals_board[max] = medals_board[i];
            medals_board[i] = aux[0];      
        
        }    
    }         

    free(aux);

}

void order_bronzes(MedalsBoard *medals_board, int number_countries){
    
    int max;
    MedalsBoard *aux = (MedalsBoard *) malloc(1 * sizeof(MedalsBoard));

    for (int i = 0; i < number_countries; i++)
    {
        max = i;

        for (int j = (i+1); j < number_countries; j++)
        {
            if (medals_board[j].gold_medals == medals_board[max].gold_medals && 
                medals_board[j].silver_medals == medals_board[max].silver_medals && 
                medals_board[j].bronze_medals > medals_board[max].bronze_medals
            ){
                max = j;
            }
        }

        if(i != max){
            aux[0] = medals_board[max];
            medals_board[max] = medals_board[i];
            medals_board[i] = aux[0];
        }

    }
    
    free(aux);

}

void order_country_name(MedalsBoard *medals_board, int number_countries){
    
    int min;

    MedalsBoard *aux = (MedalsBoard *) malloc(1 * sizeof(MedalsBoard));

    for (int i = 0; i < number_countries; i++)
    {
        min = i;

        for (int j = (i+1); j < number_countries; j++)
        {
            if (medals_board[j].gold_medals == medals_board[min].gold_medals && 
                medals_board[j].silver_medals == medals_board[min].silver_medals && 
                medals_board[j].bronze_medals == medals_board[min].bronze_medals && 
                (strcmp(medals_board[j].country, medals_board[min].country) < 0)
            ){
                min = j;
            }
        }

        if(i != min){
            aux[0] = medals_board[min];
            medals_board[min] = medals_board[i];
            medals_board[i] = aux[0];
        }

    }
    
    free(aux);

}