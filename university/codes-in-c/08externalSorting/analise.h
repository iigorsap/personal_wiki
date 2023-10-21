// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#ifndef ANALISE_H
#define ANALISE_H

#include <stdio.h>
#include <time.h>

    typedef struct analise{
        int qtd_transferencias_leitura;
        int qtd_transferencias_escrita;
        int qtd_comparacoes;
        clock_t tempo_inicio_execucao;
        clock_t tempo_final_execucao;
        double tempo_total_execucao;
    }Analise;

    void inicia_analise(Analise* analise);

    void cont_transferencia_leitura(Analise* analise);
    void cont_transferencia_escrita(Analise* analise);
    void cont_comparacao(Analise* analise);

    void inicia_tempo_execucao(Analise* analise);
    void finaliza_tempo_execucao(Analise* analise);

    void print_analise(Analise* analise);

#endif // ANALISE_H