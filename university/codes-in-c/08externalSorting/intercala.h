// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#ifndef INTERCALA_H
#define INTERCALA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aluno.h"
#include "analise.h"
#include "format.h"

    #define REGISTROS 20
    #define FITAS 20
    
    typedef struct fita{
        FILE *arquivo;
        int qtd_blocos;
        int* qtd_regs_blocos; // Ponteiro que armazena a quantidade de registros em cada bloco 
    }Fita;

    typedef struct heap{
        Aluno registro;
        double marcado; // A marcação em questão é somar um valor grande à nota do aluno
    }Heap;

    void inicia_fitas(Fita* fitas_entrada, Fita* fitas_saida);
    int get_fitas_disponiveis(Fita* fitas);

    void intercala_balanceada_ordenacao_interna(FILE* arq, int quantidade, Analise* analise);
    void cria_fitas_entrada_ordenacao_interna(FILE* arq, Fita* fitas, Aluno* regs_aluno, int quantidade, Analise* analise);
    void quicksort(Aluno* regs_alunos, int esquerda, int direita, Analise* analise);
    
    void intercala_balanceada_selecao_subs(FILE* arq, int quantidade, Analise* analise);
    void cria_fitas_entrada_selecao_subs(FILE* arq, Fita* fitas, int quantidade, Analise* analise);
    void heapsort(Heap* vetor_heap, int n, Analise* analise);

    int inicia_intercalacao(Fita* fitas_entrada, Fita* fitas_saida, Aluno* registros, int op, Analise* analise);
    int main_intercala(Fita* fitas_entrada, Fita* fitas_saida, Aluno* registros, int op, Analise* analise);

    // Funcoes auxiliares
    int confere_registros_lido(int* qtd_regs_disponiveis_blocos, int quantidade_fitas);
    bool verifica_marcacao_vheap(Heap* vetor_heap, int marca, int reg);
    void desmarca_todo_vheap(Heap* vetor_heap, int marca, int reg);

#endif // INTERCALA_H