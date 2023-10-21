#include "matriz.h"
#include<stdio.h>

void lerOperacao(char *operacao){
    scanf("%c", operacao);
}

void lerMatriz(double M[][12]){
    int n = 12;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &M[i][j]);
        }
    }

}

double somaMatriz(double M[][12]){

   double sum = 0;
   double cont = 0;
   for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
        
            if(    ((i == 0) && (j > 0 && j < 11)) 
                || ((i == 1) && (j > 1 && j < 10)) 
                || ((i == 2) && (j > 2 && j < 9)) 
                || ((i == 3) && (j > 3 && j < 8)) 
                || ((i == 4) && (j > 4 && j < 7))
            ){
                sum += M[i][j];
            }
        }
    }

    return sum;
}

double media(double resultado){    
    double md = resultado / 30;
    return md;
}

void printResultado(double resultado){
    printf("%.1lf\n", resultado);
}
