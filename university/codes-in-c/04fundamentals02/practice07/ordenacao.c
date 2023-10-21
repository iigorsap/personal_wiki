#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    vetor = (int*) malloc(n * sizeof(int));
    return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    vetor = NULL;
    return vetor;
}

void ordenacao(int *vetor, int esquerdo, int direito, int *movimentos){
    if (esquerdo == direito){
        return;
    }
    
    int meio = (esquerdo + direito) / 2;
 
    ordenacao(vetor, esquerdo, meio, movimentos);
    ordenacao(vetor, meio+1, direito, movimentos);
    mergeSort_intercala(vetor, esquerdo, meio, direito, movimentos);
    return;
}

void mergeSort_intercala(int *vetor, int esquerdo, int meio, int direito, int *movimentos){

    int tam_esquerdo = meio - esquerdo + 1;
    int tam_direito = direito - meio;
    
    int *vet_esquerdo = alocaVetor(vet_esquerdo, tam_esquerdo);
    int *vet_direito = alocaVetor(vet_direito, tam_direito);    

    for (int i = 0; i < tam_esquerdo; i++)
    {
        vet_esquerdo[i] = vetor[i+esquerdo];
    }

    for (int j = 0; j < tam_direito; j++)
    {
        vet_direito[j] = vetor[meio+j+1];    
    }

    int i = 0;
    int j = 0;

    for (int k = esquerdo; k <= direito; k++)
    {
        if(i == tam_esquerdo){

            vetor[k] = vet_direito[j++];
   
        }else if (j == tam_direito){
            
            vetor[k] = vet_esquerdo[i++];

        }else if (vet_esquerdo[i] <= vet_direito[j]){
            
            vetor[k] = vet_esquerdo[i++];

        }else{

            vetor[k] = vet_direito[j++];
            *movimentos += (tam_esquerdo - i);
        }
    }
    desalocaVetor(vet_esquerdo);
    free(vet_direito);
} 