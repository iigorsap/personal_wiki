// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#include "sequential_acess.h"

/* 
    Pesquisa utilizando Acesso Sequencial Indexado, caso o valor registro seja encontrado retorna 1, 
    se não retornará 0.
*/
int searchASI(PageIndex *tab, int tam, Registry *regs, FILE *arq, int ordenacao, Statistic *stat) {

    Registry page_regs[SIZE_PAGE_REGISTRY];
    int qt_items;
    long displace;

    int i = 0;

    increment_comparison(stat);

    if (ordenacao != 2) { // Ordenação decrescente
        
        while (i < tam && tab[i].index_key <= regs[i].search_key) { // Realiza procura por qual página de indice armazena o registro desejado
            increment_comparison(stat);
            i++;
        }

    } else { //Ordenção crescente. obs> o arquivo não pode está desordenado

        while (i < tam && tab[i].index_key >= regs[i].search_key) { // Realiza procura por qual página de indice armazena o registro desejado 
            increment_comparison(stat);
            i++;
        }

    }

    if (i == 0) { //Chave desejada é menor que primeira chave, logo o registro não esta presente no arquivo. 
        
        return 0;
    
    } else {

        if (i < tam) {
        
            qt_items = SIZE_PAGE_REGISTRY;
        
        } else {
            
            fseek(arq, 0, SEEK_END);
            qt_items = (ftell(arq) / sizeof(Registry)) % SIZE_PAGE_REGISTRY; // Calcula quantos itens tem na ultima página, ftell pega posição do ponteiro em bytes

            if (qt_items == 0) { //Pesquisa na última page_regs do arquivo caso a mesma esteja completa

                qt_items = SIZE_PAGE_REGISTRY; 
            
            }
        }

        // Lê a pagína desejada do arquivo
        displace = (i - 1) * SIZE_PAGE_REGISTRY * sizeof(Registry);   //deslocamento para posição da página desejada
       
        fseek(arq, displace, SEEK_SET);                        //Posicionamento do leitor dentro do arquivo
       
        fread(&page_regs, sizeof(Registry), qt_items, arq); //Traz página para memória principal

        increment_tranfer(stat);

        for (int i = 0; i < qt_items; i++) {

            increment_comparison(stat);

            if (page_regs[i].search_key == regs[i].search_key) {
                *regs = page_regs[i];
                return 1; //Chave encontrada no arquivo
            }
        }

        return 0;
    }
}
