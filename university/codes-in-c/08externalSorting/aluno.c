// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#include "aluno.h"

void print_aluno(Aluno a){
    print_inscricao(a.inscricao);
    print_nota(a.nota);
    printf("%-2s ",a.estado);
    printf("%-30s ",a.cidade);
    printf("%-50s\n",a.curso);
}