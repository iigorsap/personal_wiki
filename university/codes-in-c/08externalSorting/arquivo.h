// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

    void cria_arquivos_qs_externo(FILE** arq_LEs, FILE** arq_Li, FILE** arq_Ei, FILE** arq_texto, int situacao, int quantidade);
    void cria_arquivo_intercalacao_balanceada(FILE** arq, FILE** arq_texto, int situacao, int quantidade);
    void converter_bin(FILE* arq_texto, FILE* arq_bin, int quantidade);
    void converter_texto(FILE* arq_bin, FILE* arq_texto, int quantidade);
    void print_arquivo(FILE* arq, int quantidade);

#endif // ARQUIVO_H