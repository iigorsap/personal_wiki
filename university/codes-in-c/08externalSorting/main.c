// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#include "arquivo.h"
#include "aluno.h"
#include "format.h"
#include "analise.h"
#include "intercala.h"
#include "quicksort_externo.h"
#include <stdio.h>

// entrada: ordena <método> <quantidade> <situação> [-P] 
int main(int argc, char **argv){
    
    // Arquivo que sera ordenado
    FILE *arq;
    
    // Arquivos usados no quicksort externo
    FILE* arq_Ei; // Apontador que controla a escrita da parte inferior do arquivo
    FILE* arq_Li; // Apontador que controla a leitura da parte inferior do arquivo
    FILE* arq_LEs; // Apontador que controla a leitura e escrita da parte superior do arquivo

    if (argc < 4 || argc > 5) {
        puts("ERRO!! Entrada invalida, formato correto: ordena <metodo> <quantidade> <situacao> ");
        exit(1);
    }

    // Variaveis de entrada lidas no arquivo da linha de execução
    int ordena = atoi(argv[1]);
    int quantidade = atoi(argv[2]);
    int situacao = atoi(argv[3]);

    // Determinando se os dados devem ser ordenados ou não, e apresentados na tela.

    int opcional = 0;

    if (argc == 5) {
        if (!strcmp(argv[4], "[-P]")){
            opcional = 1;
        }
        else {
            puts("o parametro opcional deve ser digitado como '[-P]' (sem as aspas).");
            exit(1);
        }
    }

    /* 
        Switch defini qual o arquivo deve ser aberto para ser ordenado!
        1 - Arquivo original ordenado em ordem crescente (ascendentemente)
        2 - Arquivo original ordenado em ordem decrescente (descendentemente)
        3 - Arquivo original ordenado de forma aleatorio 
        default - modelo de ordenação inválido!
    */ 

    switch (situacao) {
        case 1: 
            if ((arq = fopen("PROVAO-CRESCENTE.txt", "r+")) == NULL) { // Retorna NULL se o arquivo for vazio ou não existir
                puts("ERRO!! O arquivo PROVAO-CRESCENTE.txt nao pode ser aberto corretamente.");
                exit(1);
            }
            break;
        case 2: 
            if ((arq = fopen("PROVAO-DECRESCENTE.txt", "r+")) == NULL) { // Retorna NULL se o arquivo for vazio ou não existir
                puts("ERRO!! O arquivo PROVAO-DECRESCENTE.txt nao pode ser aberto corretamente.");
                exit(1);
            }
            break;
        case 3: 
            if ((arq = fopen("PROVAO-ALEATORIO.txt", "r+")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-ALEATORIO.txt nao pode ser aberto corretamente.");
                exit(1);
            }
            break;
        default:
            puts("ERRO!! O parametro de situacao do executavel deve ser de 1 a 3.");
            break;
    }

    // Iniciando a análise   
    Analise analise;
    inicia_analise(&analise);
    FILE* resultado;
    FILE* resultado_bin;

    /* 
        Switch defini qual metodo de ordenação deve ser ultilizado!
        1 - Intercalação Balanceada + Ordenação Interna
        2 - Intercalação Balanceada + Seleção por Substituição
        3 - Quicksort Externo
        default - metodo de ordenação inválido!
    */ 

    switch (ordena) {
        case 1:
            cria_arquivo_intercalacao_balanceada(&arq_Li, &arq, situacao, quantidade);

            if (opcional) {
                puts("Antes de Ordenação");
                print_arquivo(arq_Li, quantidade);
                puts("");
            }

            inicia_analise(&analise);
            intercala_balanceada_ordenacao_interna(arq_Li, quantidade, &analise);
            finaliza_tempo_execucao(&analise);

            resultado_bin = fopen("resultado.bin", "r+b");

            if ((resultado = fopen("resultado.txt", "w+")) == NULL) {
                puts("ERRO!! O arquivo resultado.txt nao pode ser aberto corretamente.");
                exit(1);
            }

            if (opcional) {
                puts("Depois da Ordenação");
                print_arquivo(resultado_bin, quantidade);
                puts("");
            }
            
            rewind(resultado_bin);
            converter_texto(resultado_bin, resultado, quantidade);

            fclose(resultado);
            remove("resultado.bin");
            print_analise(&analise);

            break;

        case 2:
            cria_arquivo_intercalacao_balanceada(&arq_Li, &arq, situacao, quantidade);
            
            if (opcional) {
                puts("Antes de Ordenação");
                print_arquivo(arq_Li, quantidade);
                puts("");
            }

            inicia_analise(&analise);
            intercala_balanceada_selecao_subs(arq_Li, quantidade, &analise);
            finaliza_tempo_execucao(&analise);

            resultado_bin = fopen("resultado.bin", "r+b");

            if ((resultado = fopen("resultado.txt", "w+")) == NULL) {
                puts("ERRO!! O arquivo resultado.txt nao pode ser aberto corretamente.");
                exit(1);
            }

            if (opcional) {
                puts("Depois da Ordenação");
                print_arquivo(resultado_bin, quantidade);
                puts("");
            }
            
            rewind(resultado_bin);
            converter_texto(resultado_bin, resultado, quantidade);

            fclose(resultado);
            remove("resultado.bin");
            print_analise(&analise);

            break;

        case 3: 
            cria_arquivos_qs_externo(&arq_LEs, &arq_Li, &arq_Ei, &arq, situacao, quantidade);

            if (opcional) {
                puts("Antes de Ordenação");
                print_arquivo(arq_Li, quantidade);
                puts("");
            }

            inicia_analise(&analise);
            main_quicksort_externo(&arq_Li, &arq_Ei, &arq_LEs, 1, quantidade, &analise);
            finaliza_tempo_execucao(&analise);

            fclose(arq_Ei);
            fclose(arq_LEs);

            if (opcional) {
                puts("Depois da Ordenação");
                print_arquivo(arq_Li, quantidade);
                puts("");
            }
            
            rewind(arq_Li);

            if ((resultado = fopen("resultado.txt", "w+")) == NULL) {
                puts("ERRO!! O arquivo resultado.txt nao pode ser aberto corretamente.");
                exit(1);
            }

            converter_texto(arq_Li, resultado, quantidade);
            fclose(resultado);
            print_analise(&analise);

            break;
            
        default:
            puts("ERRO!! O parametro de ordenacao do executavel deve ser de 1 a 3.");
            
            break;    
    }   

    return 0;
}