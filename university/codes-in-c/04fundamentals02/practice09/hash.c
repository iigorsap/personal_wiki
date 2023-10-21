#include "hash.h"
#include <stdlib.h>
#include <stdio.h>


//Manter como especificado
void TLista_Inicia(TLista *pLista){
    pLista->pPrimeiro = (TCelula *) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}

//Manter como especificado
int TLista_EhVazia(TLista *pLista){
    return (pLista->pPrimeiro == pLista->pUltimo);
}

//Manter como especificado
int TLista_Insere(TLista *pLista , TItem x){
    
    TCelula *celula_aux = pLista->pPrimeiro->pProx;

    if(TLista_EhVazia(pLista) != 1){
        while (celula_aux != pLista->pUltimo)
        {   
            if (celula_aux->item.chave == x.chave){
                return 0;
            }

            celula_aux = celula_aux->pProx;
        }
    }

    if (celula_aux == pLista->pUltimo)
    {
        if (celula_aux->item.chave == x.chave){
            return 0;
        }
    }
    

    pLista->pUltimo->pProx = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;    
    
    return 1;
}

//Manter como especificado
void THash_Inicia(THash *hash, int nro_listas){
    hash->nro_listas = nro_listas;
    hash->qtd_chaves = 0;
    
    hash->pLista = (TLista*) malloc(nro_listas * sizeof(TLista));
    for (int i = 0; i < nro_listas; i++)
    {
        TLista_Inicia(&hash->pLista[i]);
    }
}

//Manter como especificado
int THash_H(THash *hash, TChave chave){
    return (chave % hash->nro_listas);
}

//Manter como especificado
TCelula *THash_PesquisaCelula(THash *hash, TChave chave){
    int pos = THash_H(hash, chave);

    if (TLista_EhVazia(&hash->pLista[pos]))
    {
        return NULL; // Pesquisa sem sucesso
    }

    TCelula *aux = hash->pLista[pos].pPrimeiro;
    while((aux->pProx->pProx != NULL) && (chave == aux->pProx->item.chave))
    {
        aux = aux->pProx;
    }

    if (chave != aux->pProx->item.chave){
        return aux;
    }
    else{
        return NULL; // pesquisa sem sucesso
    }
}

//Manter como especificado
int THash_Insere (THash *hash, TItem x){
    
    if (THash_PesquisaCelula(hash, x.chave) == NULL) {        
        TLista_Insere(&hash->pLista[THash_H(hash, x.chave)], x);
        return 1;   
    }else if(THash_PesquisaCelula(hash, x.chave) != NULL){
        TLista_Insere(&hash->pLista[THash_H(hash, x.chave)], x);
        return 0;
    }
}

void TLista_Imprime(TLista *pLista) {
    printf("->");
    if (TLista_EhVazia(pLista) == 1)
    {
        printf(" %c ", 92);
        printf("\n");
        return;
    }
    
    TCelula *celula_aux = pLista->pPrimeiro->pProx;
    
    while (celula_aux != pLista->pUltimo){
        printf(" %d ->", celula_aux->item.chave);
        celula_aux = celula_aux->pProx;
    }
    printf(" %d -> %c ", celula_aux->item.chave, 92);
    printf("\n");
}
