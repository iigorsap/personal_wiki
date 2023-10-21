#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem){
    scanf("%d", ordem);
}

//manter como especificado
void lerOperacao(char *operacao){
    getchar();
    scanf("%c", operacao);
}

//manter como especificado
double **alocaMatriz(double **M, int ordem){
    M = (double**) malloc(ordem * sizeof(double*));
    for(int i = 0; i < ordem; i++){
        M[i] = (double*) malloc(ordem * sizeof(double));
    }

    return M;
}

//manter como especificado
double **desalocaMatriz(double **M, int ordem){
    for(int i = 0; i < ordem; i++){
        free(M[i]);
    }

    free(M);

    return M;
}


void lerMatriz(double **M, int ordem){
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++){
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double **M, int ordem){

    double soma = 0;
    int aux = 0;
    double cont = 0;
    
    for(int i = 0; i < (ordem/2) - 1; i++){
        aux++;
        for(int j = aux; j < (ordem - 1) - i; j++){
                soma += M[i][j];   
                cont++;
        }
    }

    return soma;
}

double media(double resultado, int ordem){


    return resultado / (((ordem * ordem) / 4 ) - (ordem / 2));

}

void printResultado(double resultado){
    printf("%.1lf ", resultado);
}
