// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#ifndef FORMAT_H
#define FORMAT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    // Inscricoes
    int conta_digitos_long(long int n, int cont);
    void print_inscricao(long int n);
    void print_inscricao_arq(FILE* arq, long int n);

    // Nota
    int conta_digitos_double(double n, int cont);
    void print_nota(double n);
    void print_nota_arq(FILE* arq, double n);

#endif // FORMAT_H