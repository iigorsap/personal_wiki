// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "format.h"

    typedef struct aluno {
        long int inscricao;
        double nota;
        char estado[3];
        char cidade[51];
        char curso[31];
    }Aluno;
    
    void print_aluno(Aluno a);
    
#endif // ALUNO_H