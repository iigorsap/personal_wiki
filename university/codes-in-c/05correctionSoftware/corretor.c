// Created by Igor Santiago - 19.1.4033 on 17/06/2021.

#include "corretor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct submissions{
    int time; // 1 <= time <= 300 
    char identifier; // A <= time <= Z 
    char judgment[20]; 
    int checked_incorrect;
};

struct hits_and_misses{
    int n_hits; 
    char *correct_question;
};

void read_length_submissions(int *length){
    scanf("%d", length);
}

TADsub *new_submissions(TADsub *S, int length){
    
    S = (TADsub *) malloc(length * sizeof(TADsub));

    if ( S == NULL )
    {
        printf("Insufficient Memory.\n");
        exit(1);
    }

    return S;
}

TADsub *free_submissions(TADsub * S){
    free(S);
}

void read_submissions(TADsub *S, int length){
    
    for (int i = 0; i < length; i++)
    {
        scanf(" %c ", &S[i].identifier); 
        scanf(" %d ", &S[i].time);
        scanf(" %s ", S[i].judgment);
    }

    S[0].checked_incorrect = 0;
}

/* Função responsável por fazer a contabilidade de quantos acertos
o aluno conseguiu em suas submissões. */
int get_hits(TADsub *S, int length){
    
    int n_hits = 0;

    for (int i = 0; i < length; i++)
    {
        if (strcmp(S[i].judgment, "correto") == 0)
        {
            n_hits++;   
        }
        
    }

    return n_hits;
}

TADhm *new_hm(TADhm *H, TADsub *S, int length, int hits){

    H = (TADhm *) malloc(sizeof(TADhm));

    if ( H == NULL )
    {
        printf("Insufficient Memory.\n");
        exit(1);
    }
    
    H->correct_question = (char *) malloc(hits * sizeof(char));
    H->n_hits = hits;
    
    return H;
}

TADhm *free_hm(TADhm *H){
    free(H);
}

/* Função que armazena no vetor correct_question, o identificador das questões 
que estão corretas */
void get_correct_questions(TADhm *H, TADsub *S, int length){

    for (int i = 0; i < length; i++)
    {
        if(strcmp(S[i].judgment, "correto") == 0)
        {
            for (int j = 0; j < H->n_hits; j++)
            {
                H->correct_question[j] = S[i].identifier;
            }
            
            
        }
    }  
}

/* Função responsável por fazer o cálculo de submissões incompletas,
somente das questões que foram acertadas em algum momento */
void check_incomplete_judgments(TADhm *H, TADsub *S, int length){

    for (int i = 0; i < H->n_hits; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if ((H->correct_question[i] == S[j].identifier) && strcmp(S[j].judgment, "incompleto") == 0)
            {
                S[0].checked_incorrect++;
            }
        }
    }
}

/* Função responsável pelo cálculo do tempo de todas as submissões feita pelo aluno
julgadas como corretas, além de calcular a multa para submissões incompletas */
int correction(TADsub *S, TADhm *H, int length){

    int total_time = 0;
    
     for (int i = 0; i < H->n_hits; i++)
     {
        for (int j = 0; j < length; j++)
        {
            if ((H->correct_question[i] == S[j].identifier) && strcmp(S[j].judgment, "correto") == 0)
            {
                total_time += S[j].time;
            }
           
        }
    }

    total_time += (S[0].checked_incorrect * TAXA_ERROR);

    return total_time;
}

void print_correction(int qtd_correct, int total_time){
    printf("%d %d \n", qtd_correct, total_time);
}