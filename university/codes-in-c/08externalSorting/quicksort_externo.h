// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#ifndef QUICKSORT_EXTERNO_H
#define QUICKSORT_EXTERNO_H

#include "arquivo.h"
#include "aluno.h"
#include "analise.h"
#include "format.h"

    //Macros

    #define SIZE_AREA 20
    #define INT_MIN -2147483648
    #define INT_MAX 2147483647
    #define FALSE 0
    #define TRUE 1

    void main_quicksort_externo(FILE **arq_Li, FILE **arq_Ei, FILE **arq_LEs, int Esq, int Dir, Analise *analise);
    void particao(FILE **arq_Li, FILE **arq_Ei, FILE **arq_LEs, Aluno *area_pivo, int Esq, int Dir, int *i, int *j, Analise *analise);
    void print_area(Aluno *area_pivo);
    
    void new_area_vazia(Aluno *area_pivo, Analise *analise);

    void leitura_superior(FILE ** arq_LEs, Aluno *ultimo_aluno_lido, int *Ls, short *onde_ler, Analise *analise);
    void escrita_superior(FILE **arq_LEs, Aluno aluno, int *Es, Analise *analise);
    
    void leitura_inferior(FILE **arq_Li, Aluno *ultimo_aluno_lido, int *Li, short *onde_ler, Analise *analise); // short *onde_ler -> controla a leitura, se vai ler inferior ou superior
    void escrita_inferior(FILE **arq_Ei, Aluno aluno, int *Ei, Analise *analise);

    void insere_aluno_na_area(Aluno *area_pivo, Aluno *ultimo_aluno_lido, int *qtd_elementos_area, Analise *analise); // De forma ordenada
    void insere_aluno_na_area_(Aluno ultimo_aluno_lido, Aluno *area_pivo, Analise *analise);
    
    void retira_maior_elemento(Aluno *area_pivo, Aluno *aluno, int *qtd_elementos_area, Analise *analise);
    void retira_maior_elemento_(Aluno *area_pivo, Aluno *aluno, Analise *analise);
    
    void retira_menor_elemento(Aluno *area_pivo, Aluno *aluno, int *qtd_elementos_area, Analise *analise);
    void retira_menor_elemento_(Aluno *area_pivo, Aluno *aluno, Analise *analise);

    int numeros_celulas_ocupadas(Aluno *area_pivo, Analise *analise);

#endif // QUICKSORT_EXTERNO_H