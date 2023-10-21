#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista->primeiro_amigo = (TCelula*) malloc(sizeof(TCelula));
    pLista->ultimo_amigo = pLista->primeiro_amigo;
    pLista->primeiro_amigo->proximo = NULL; 
}
    
//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    return (pLista->primeiro_amigo == pLista->ultimo_amigo);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
    pLista->ultimo_amigo->proximo = (TCelula*) malloc(sizeof(TCelula));
    pLista->ultimo_amigo = pLista->ultimo_amigo->proximo; 
    pLista->ultimo_amigo->amigo_atual = x;
    pLista->ultimo_amigo->proximo = NULL;

    return 1;  
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    /* Retira o primeiro item da lista */
    if (TLista_EhVazia(pLista)){
        return 0;
    }
       
    TCelula *pLista_aux = pLista->primeiro_amigo->proximo; 
    *pX = pLista_aux->amigo_atual;
    
    pLista->primeiro_amigo->proximo = pLista_aux->proximo;

    
    free(pLista_aux);
    pLista_aux = NULL;
    
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {

    TCelula *celula_aux = pLista->primeiro_amigo->proximo;

    printf("Em ordem [");
    while(celula_aux != pLista->ultimo_amigo) {
        printf("%s ", celula_aux->amigo_atual.nome);
        celula_aux = celula_aux->proximo;
    }
    printf("%s ", celula_aux->amigo_atual.nome);
    printf("]\n");
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    
    TItem *armazena_item; 

    while (TLista_EhVazia(pLista) != 1){
        TLista_RetiraPrimeiro(pLista, armazena_item);
    }  
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
    
    TCelula *armazena_celula = pLista2->primeiro_amigo->proximo;
    
    while(armazena_celula != pLista2->ultimo_amigo){
        TLista_InsereFinal(pLista1, armazena_celula->amigo_atual);
        armazena_celula = armazena_celula->proximo;
    }

    TLista_InsereFinal(pLista1, armazena_celula->amigo_atual);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    
    TCelula *celula_01 = pLista1->primeiro_amigo->proximo;
    TCelula *celula_02 = pLista2->primeiro_amigo->proximo;

    // Primeiro procura aonde esta a str passada por paramentro
      while(strcmp(str, celula_01->proximo->amigo_atual.nome) != 0){
            TLista_InsereFinal(pLista1, celula_01->amigo_atual);
            celula_01 = celula_01->proximo;
            celula_02 = celula_02->proximo;
    }
    celula_01->proximo = pLista2->primeiro_amigo->proximo;


    pLista2->ultimo_amigo->proximo = celula_02;
    pLista1->ultimo_amigo = pLista2->ultimo_amigo;

    while(celula_02->proximo != NULL){
        TLista_InsereFinal(pLista1, celula_02->amigo_atual);
        celula_02 = celula_02->proximo;
    }
}

    
