// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#include "format.h"

// Retorna a quantidade de dígitos de um long int n
int conta_digitos_long(long int n, int cont) {
    if (n > 0) {
        return conta_digitos_long(n/10, ++cont);
    }  
    else {
        return cont;  
    }  
}

// Completa a inscrição com 0 adicionados à esquerda do número e imprime na tela
void print_inscricao(long int n) {
    
    int aux = 8 - conta_digitos_long(n, 0);

    // Serão impressos aux vezes o dígito 0 na tela para completar a inscrição
    for (int i = 0; i < aux; i++) {
        printf("0");
    }

    printf("%ld ",n);
}

// Completa a inscrição com 0 adicionados à esquerda do número e imprime no arquivo arq
void print_inscricao_arq(FILE* arq, long int n) {
    
    int aux = 8 - conta_digitos_long(n, 0);

    // Serão impressos aux vezes o dígito 0 no arquivo arq para completar a inscrição
    for (int i = 0; i < aux; i++) {
        fprintf(arq, "0");
    }

    fprintf(arq, "%ld ", n);
}

// Retorna a quantidade de dígitos de um double n antes do ponto (ou vírgula)
int conta_digitos_double(double n, int cont) {
    
    if (n >= 1.0) {
        return conta_digitos_double(n/10.0, ++cont);
    }
    else {
        return cont;
    }

}

// Completa a nota com 0 adicionados à esquerda do número e imprime na tela
void print_nota(double n) {
    int aux = 3 - conta_digitos_long(n, 0);

    // Se o número n estiver entre 0 e 1
    if((n >= 0.0) && (n <= 1.0)) {
        printf("00"); //Será impresso 2 vezes o dígito 0 na tela para completar a nota
    } 
    else { // Se o número for maior que 1
        for(int i = 0; i < aux; i++) {  // Serão impressos aux vezes o dígito 0 na tela para completar a nota
            printf("0");
        }
    }

    printf("%.1lf ",n);
}


//Completa a nota com 0 adicionados à esquerda do número e imprime no arquivo arq
void print_nota_arq(FILE* arq, double n) {
    
    int aux = 3 - conta_digitos_long(n, 0);

    // Se o número n estiver entre 0 e 1
    if((n >= 0.0) && (n <= 1.0)) {
        fprintf(arq, "00"); // Será impresso 2 vezes o dígito 0 no arquivo arq para completar a nota
    } 
    else { // Se o número for maior que 1
        for(int i = 0; i < aux; i++) {  // Serão impressos aux vezes o dígito 0 no arquivo arq para completar a nota
            fprintf(arq, "0");
        }
    }

    fprintf(arq, "%.1lf ",n);
}