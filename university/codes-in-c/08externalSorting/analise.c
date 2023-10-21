// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#include "analise.h"

void inicia_analise(Analise* analise) {
    analise->qtd_transferencias_leitura = 0;
    analise->qtd_transferencias_escrita = 0;
    analise->qtd_comparacoes = 0;
    analise->tempo_total_execucao = 0.0;
}

void cont_transferencia_leitura(Analise* analise) {
    analise->qtd_transferencias_leitura++;
}
void cont_transferencia_escrita(Analise* analise) {
    analise->qtd_transferencias_escrita++;
}

void cont_comparacao(Analise* analise) {
    analise->qtd_comparacoes++;
}

void inicia_tempo_execucao(Analise* analise) {
    analise->tempo_inicio_execucao = clock();
}

void finaliza_tempo_execucao(Analise* analise) {
    analise->tempo_final_execucao = clock();
    analise->tempo_total_execucao = (analise->tempo_final_execucao - analise->tempo_inicio_execucao) * 1000.0/CLOCKS_PER_SEC;
}

void print_analise(Analise* analise) {
    printf("######### ANALISE #########\n");
    printf("Numero de transferencias (leitura) realizadas: %d\n",analise->qtd_transferencias_leitura);
    printf("Numero de transferencias (escrita) realizadas: %d\n",analise->qtd_transferencias_escrita);
    printf("Numero de comparacoes realizadas: %d\n", analise->qtd_comparacoes);
    printf("Tempo de execucao (em milissegundos): %lf\n",analise->tempo_total_execucao);
}