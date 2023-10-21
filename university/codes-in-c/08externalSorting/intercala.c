// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#include "intercala.h"

// Inicializando as fitas
void inicia_fitas(Fita* fitas_entrada, Fita* fitas_saida) {
    
    for (int i = 0; i < FITAS; i++) {
        fitas_entrada[i].arquivo = NULL;
        fitas_entrada[i].qtd_blocos = 0;
        fitas_entrada[i].qtd_regs_blocos = NULL;
        fitas_saida[i].arquivo = NULL;
        fitas_saida[i].qtd_blocos = 0;
        fitas_saida[i].qtd_regs_blocos = NULL;
    }

}

// Retornando a quantidade de fitas disponiveis
int get_fitas_disponiveis(Fita* fitas) {
    
    int n_fitas = 0;

    for (int i = 0; i < FITAS; i++) {
        if (fitas[i].qtd_blocos != 0) n_fitas++; 
        else break;
    }

    return n_fitas;
}

//================== FUNCOES DO METODO DE ORDENACAO 1 ===============================

// Funcao que inicializa o metodo de ordenação 1 
void intercala_balanceada_ordenacao_interna(FILE* arq, int quantidade, Analise* analise) {
    
    Fita fitas_entrada[FITAS];
    Fita fitas_saida[FITAS];
    Aluno registros[REGISTROS];

    // Inicializando as fitas 
    inicia_fitas(fitas_entrada, fitas_saida);

    cria_fitas_entrada_ordenacao_interna(arq, fitas_entrada, registros, quantidade, analise);

    /*  A variavel op  é responsavel por determinar se será ultilizado as fitas geradas inicialmente (op = 1)
        ou as fitas geradas pela funcao de intercalação (op = 0).

        fitas de 1 a 20 (op = 1), fitas de 21 a 40 (op = 0)
    */

    int op = 1;
    int continua = 1;

    while (continua) {
        continua = inicia_intercalacao(fitas_entrada, fitas_saida, registros, op, analise);
        op = op == 1 ? 0 : 1;
    }
    
    fclose(arq);
}


void cria_fitas_entrada_ordenacao_interna(FILE* arq, Fita* fitas, Aluno* regs_alunos, int quantidade, Analise* analise) {
    
    // Garantindo que tenha quantidade de fitas corretas
    int quantidade_fitas = quantidade % REGISTROS != 0 ? (quantidade / REGISTROS) + 1 : quantidade / REGISTROS;
    int count_reg = 0;   
    int count = 0;
    char nome_arquivo[20];

    while (count < quantidade_fitas) {
        
        // Lendo os registros do arquivo
        while (!feof(arq) && count_reg < REGISTROS) {
            cont_transferencia_leitura(analise);
            fread(&regs_alunos[count_reg], sizeof(Aluno), 1, arq);
            count_reg++;
        }
        
        //  Garantindo que o numero de fitas nao ultrapasse o valor de FITAS, nomeando e criando arquivo de fitas
        if (count < FITAS) {
            sprintf(nome_arquivo, "fita-%d.bin", count + 1);
            fitas[count % FITAS].arquivo = fopen(nome_arquivo, "w+b");
        } else {
            sprintf(nome_arquivo, "fita-%d.bin", (count % FITAS) + 1);
            fseek(fitas[count % FITAS].arquivo, 0, SEEK_END);
        }

        // Ordenando registro de alunos por um quicksort
        quicksort(regs_alunos, 0, count_reg - 1, analise);
        
        for(int i = 0; i < count_reg; i++) { 
            cont_transferencia_escrita(analise);
        }

        // Escrevendo o vertor ordenado no arquivo de fitas
        fwrite(regs_alunos, sizeof(Aluno), count_reg, fitas[count % FITAS].arquivo); 
        
        fitas[count % FITAS].qtd_blocos++;

        // Faz a criacao de um vetor para cada bloco presente dentro das fitas
        int* aux = malloc((count / FITAS + 1) * sizeof(int));

        // Garante que a variavel aux tenha o quantidade correto de blocos presente em cada fitas
        // Atribui a quantidade de registros para cada posicao da variavel aux e aponta o numero de registros para aux

        if ((count / FITAS + 1) == 1) {
            aux[0] = count_reg;
            fitas[count % FITAS].qtd_regs_blocos = aux;
        } else {
            // Pega todos os registros ja contidos dentro da fita adicionando a quantidade de registros do novo bloco
            for (int i = 0; i < count / FITAS; i++) {
                aux[i] = fitas[count % FITAS].qtd_regs_blocos[i];
            }

            aux[count / FITAS] = count_reg;
            fitas[count % FITAS].qtd_regs_blocos = aux;
        }

        count++;
        count_reg = 0;
    }
}

// Ordenando registro de alunos por um quicksort
void quicksort(Aluno* regs_alunos, int esquerda, int direita, Analise* analise) {
    
    int i = esquerda;
    int j = direita;

    Aluno x = regs_alunos[(esquerda + direita) / 2];
    Aluno y;

    while (i <= j) {

        cont_comparacao(analise);
        
        while (regs_alunos[i].nota < x.nota && i < direita) {
            cont_comparacao(analise);
            i++;
        }

        cont_comparacao(analise);

        while (regs_alunos[i].nota > x.nota && j > esquerda) {
            cont_comparacao(analise);
            j--;
        }

        if (i <= j) {
            y = regs_alunos[i];
            regs_alunos[i] = regs_alunos[j];
            regs_alunos[j] = y;
            i++;
            j--;
        }
    }

    if ( j > esquerda) {
        quicksort(regs_alunos, esquerda, j, analise);
    }

    if (i < direita) {
        quicksort(regs_alunos, i, direita, analise);
    }

}

//================== FUNCOES DO METODO DE ORDENACAO 2 ===============================

// Funcao que inicializa o metodo de ordenação 2 
void intercala_balanceada_selecao_subs(FILE* arq, int quantidade, Analise* analise) {
    
    Fita fitas_entrada[FITAS];
    Fita fitas_saida[FITAS];
    Aluno registros[REGISTROS];

    // Inicializando as fitas 
    inicia_fitas(fitas_entrada, fitas_saida);

    cria_fitas_entrada_selecao_subs(arq, fitas_entrada, quantidade, analise);

    /*  A variavel op  é responsavel por determinar se será ultilizado as fitas geradas inicialmente (op = 1)
        ou as fitas geradas pela funcao de intercalação (op = 0).

        fitas de 1 a 20 (op = 1), fitas de 21 a 40 (op = 0)
    */

    int op = 1;
    int continua = 1;

    while (continua) {
        continua = inicia_intercalacao(fitas_entrada, fitas_saida, registros, op, analise);
        op = op == 1 ? 0 : 1;
    }
    
    fclose(arq);
}

void cria_fitas_entrada_selecao_subs(FILE* arq, Fita* fitas, int quantidade, Analise* analise) {
    int count = 0; 
    int count_reg = 0; 
    int reg = 0; 
    int marca = quantidade * 2; // Garante que marca seja um valor grande para ser usado como marcação
    char nome_arquivo[20];
    Heap reg_heap[REGISTROS];

    // Faz a leitura dos primeiros registros para o vetor interno
    for (int i = 0; i < REGISTROS; i++) {
        cont_transferencia_leitura(analise);
        fread(&reg_heap[i].registro, sizeof(Aluno), 1, arq);
        reg_heap[i].marcado = reg_heap[i].registro.nota;
    }

    while (quantidade != 0) {
        
        // Realiza o Heap dos registros
        heapsort(reg_heap, REGISTROS - reg, analise);

        /*  
            Garantindo que o numero de fitas não ultrapasse a quantidade estabelecida 
            na constante FITAS, nomeando o arquivo e o criando.
        */
        if (count < FITAS && fitas[count % FITAS].arquivo == NULL) {
            sprintf(nome_arquivo, "fita-%d.bin", count + 1);
            fitas[count % FITAS].arquivo = fopen(nome_arquivo, "w+b");
        } else {
            sprintf(nome_arquivo, "fita-%d.bin", (count % FITAS) + 1);
            fseek(fitas[count % FITAS].arquivo, 0, SEEK_END);
        }

        // Verifica se o vetor esta todo marcado
        if (verifica_marcacao_vheap(reg_heap, marca, reg)) {
            
            desmarca_todo_vheap(reg_heap, marca, reg);
            fitas[count % FITAS].qtd_blocos++;

            // Faz a criação de um vetor para cada bloco presente dentro das fitas
            int* aux = malloc((count / FITAS + 1) * sizeof(int));

            /* 
                Garante que a variavel aux tenha o quantidade correto de blocos presente em cada fita
                Atribui a quantidade de registros para cada posicao da variavel aux e aponta qtd_regs_blocos para aux 
            */
            if ((count / FITAS + 1) == 1) {
                aux[0] = count_reg;
                fitas[count % FITAS].qtd_regs_blocos = aux;
            } else {
                // Pega todos os registros ja contidos dentro da fita adicionando a quantidade de registros do novo bloco
                for(int i = 0; i < count / FITAS; i++)
                    aux[i] = fitas[count % FITAS].qtd_regs_blocos[i];

                aux[count / FITAS] = count_reg;
                fitas[count % FITAS].qtd_regs_blocos = aux;
            }

            count++;
            count_reg = 0;
        }

        else {
            // Pega o menor registro do vetor reg_heap
            Heap menor_reg_heap = reg_heap[0];

            // Escreve o valor na fita
            cont_transferencia_escrita(analise);
            fwrite(&menor_reg_heap.registro, sizeof(Aluno), 1, fitas[count % FITAS].arquivo);
            count_reg++;

            // Garantindo que não haja leitura desnecessária
            if(quantidade - REGISTROS > 0) {
                cont_transferencia_leitura(analise);
                fread(&reg_heap[0].registro, sizeof(Aluno), 1, arq);

                cont_comparacao(analise);

                // A marcação utilizada é aumentando o valor inicial da nota em um valor arbitrário
                if(reg_heap[0].registro.nota < menor_reg_heap.registro.nota)
                    reg_heap[0].marcado = reg_heap[0].registro.nota + marca;

                else
                    reg_heap[0].marcado = reg_heap[0].registro.nota;
            }

            // Manipula os registros restantes que estão dentro do vetor reg_heap
            else {
                // Pega o ultimo registro e coloca ele para a primeira posicao
                menor_reg_heap = reg_heap[REGISTROS - reg - 1];
                reg_heap[0] = menor_reg_heap;
                reg++;
            }

            quantidade--;
        }
    }

    fitas[count % FITAS].qtd_blocos++;

    // Garante que a quantidade de registros restantes seja armazenada na fita
    // Faz a criação de um vetor para cada bloco presente dentro das fitas

    int* aux = malloc((count / FITAS + 1) * sizeof(int));

    // Garante que a variavel aux tenha o quantidade correto de blocos presente em cada fita
    // Atribui a quantidade de registros para cada posicao da variavel aux e aponta qtd_regs_blocos para aux
    if ((count / FITAS + 1) == 1) {
        aux[0] = count_reg;
        fitas[count % FITAS].qtd_regs_blocos = aux;
    }

    else {
        // Pega todos os registros ja contidos dentro da fita adicionando a quantidade de registros do novo bloco
        for(int i = 0; i < count / FITAS; i++)
            aux[i] = fitas[count % FITAS].qtd_regs_blocos[i];

        // Insere na ultima posicao
        aux[count / FITAS] = count_reg;
        fitas[count % FITAS].qtd_regs_blocos = aux;
    }
}

void heapsort(Heap* vetor_heap, int n, Analise* analise) {
   
    int i = n / 2;
    int pai, filho;
    Heap temp;
    
    while (true) {
        if (i > 0) {
            i--;
            temp = vetor_heap[i];
        } else {
            n--;
            if (n <= 0) return;
            temp = vetor_heap[n];
            vetor_heap[n] = vetor_heap[0];
        }

        pai = i;
        filho = i * 2 + 1;
        
        while (filho < n) {
            
            cont_comparacao(analise);
            
            if ((filho + 1 < n) && (vetor_heap[filho + 1].marcado > vetor_heap[filho].marcado)) {
                filho ++;
            }
            
            cont_comparacao(analise);
            
            if (vetor_heap[filho].marcado > temp.marcado) {
                vetor_heap[pai] = vetor_heap[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }

        vetor_heap[pai] = temp;
    }
}

// Função que verifica se todos os registros do vetor foram marcados
bool verifica_marcacao_vheap(Heap* vetor_heap, int marca, int reg) {
    for(int i = 0; i < REGISTROS - reg; i++) {
        if(vetor_heap[i].marcado <= marca / 2)
            return false;
    }

    return true;
}

// Função que desmarcar todos os registros do vetor
void desmarca_todo_vheap(Heap* vetor_heap, int marca, int reg) {
    for(int i = 0; i < REGISTROS - reg; i++)
        vetor_heap[i].marcado -= marca;
}

// Função que alterna as fitas de entrada pelas fitas de saida e vice versa
int inicia_intercalacao(Fita* fitas_entrada, Fita* fitas_saida, Aluno* registros, int op, Analise* analise) {

    // Fitas de 1 a FITAS, no caso de 1 a 20.
    if (op == 1) {
        return main_intercala(fitas_entrada, fitas_saida, registros, op, analise);
    } else {
        // fitas de (FITAS + 1) a (FITAS * 2), no caso de 21 a 40.
        return main_intercala(fitas_entrada, fitas_saida, registros, op, analise);
    }
}


// Funcao principal de intercalaçao, retorna 0 caso tenha terminado ou 1 caso contrario
int main_intercala(Fita* fitas_entrada, Fita* fitas_saida, Aluno* registros, int op, Analise* analise) {
    int quantidade_fitas = 0;
    char nome_arquivo[20];
    int fita_selecionada = op == 1 ? 1 : (FITAS + 1); // Determina a fita final gerada apos toda intercalação
    int fita_resultante = op == 1 ? (FITAS + 1) : 1; // Determina o numero da fita gerada pelo metodo
    int length = 0;

    // Confere a quantidade de fitas disponiveis
    quantidade_fitas = get_fitas_disponiveis(fitas_entrada);

    // Arquivo totalmente ordenado sendo renomeado
    if (quantidade_fitas == 1) {
        sprintf(nome_arquivo, "fita-%d.bin", fita_selecionada);
        rename(nome_arquivo, "resultado.bin");

        // Fecha todos os arquivos de fita 
        for (int i = 0; i < FITAS; i++) {
            if(fitas_entrada[i].arquivo != NULL) fclose(fitas_entrada[i].arquivo);
            if(fitas_saida[i].arquivo != NULL) fclose(fitas_saida[i].arquivo);
        }

        // Exclui todos os arquivos de fita
        for (int i = 0; i < FITAS * 2; i++) {
            sprintf(nome_arquivo, "fita-%d.bin", i + 1);
            remove(nome_arquivo);
        }

        return 0;
    }  

    // Caso se for maior que 1 a quantidade de fitas 
    // Movendo o ponteiros de todos os arquivos que serão ultilizados para o inicio
    for(int i = 0; i < quantidade_fitas; i++)
        fseek(fitas_entrada[i].arquivo, 0, SEEK_SET);


    // Cria vetor com o numero maximo de fitas que serão ultilizadas
    int* qtd_regs_disponiveis_blocos = malloc(quantidade_fitas * sizeof(int));
    int  posicao, continua; 
    int  index = 0;
    int* aux;
    Aluno menor;

    while (quantidade_fitas != 0) {

        // Atribui ao contador o numero de registros disponivel em cada arquivo
        for (int i = 0; i < quantidade_fitas; i++) {
            qtd_regs_disponiveis_blocos[i] = fitas_entrada[i].qtd_regs_blocos[index];
        }

        // Faz a leitura do primeiro item de cada bloco 
        for (int i = 0; i < quantidade_fitas; i++) {
            cont_transferencia_leitura(analise);
            fread(&registros[i], sizeof(Aluno), 1, fitas_entrada[i].arquivo);
            qtd_regs_disponiveis_blocos[i]--;
        }

        continua = 1;
        sprintf(nome_arquivo, "fita-%d.bin", fita_resultante);
        
        // Cria a fita caso não exista as fitas de saida
        if (fitas_saida[(fita_resultante - 1) % FITAS].arquivo == NULL) {
            fitas_saida[(fita_resultante - 1) % FITAS].arquivo = fopen(nome_arquivo, "w+b");
        } // Apenas continua com a fita de saida caso tiver fitas disponiveis ainda
         else if (fitas_saida[(fita_resultante - 1) % FITAS].arquivo != NULL && fitas_saida[(fita_resultante - 1) % FITAS].qtd_blocos != 0) {
            continua = 1;
        } // Se não, move o ponteiro para o inicio do arquivo quando as fitas de saida ja se encontram todas criadas.
        else {
            fseek(fitas_saida[(fita_resultante - 1) % FITAS].arquivo, 0, SEEK_SET);
        }

        // Verificando se tem ou não blocos nas fitas
        if (length / FITAS == 0 ) {
            // Faz alocação de vetor aux
            aux = malloc((length / FITAS + 1) * sizeof(int));

            // Caso não tenha blocos, o aux simplesmente recebe 0 e a qtd_regs_blocos é apontado pra ele
            aux[0] = 0;
            
            fitas_saida[(fita_resultante - 1) % FITAS].qtd_regs_blocos = aux;
        } else {
            aux = malloc((length / FITAS + 1) * sizeof(int));

            for(int i = 0; i < (length / FITAS); i++) {
                aux[i] = fitas_saida[(fita_resultante - 1) % FITAS].qtd_regs_blocos[i];
            }


            /*  Caso tenha blocos na fita, o aux copia tudo que está no qtd_regs_blocos, 
                atrbui 0 para ultima posicao do aux e qtd_regs_blocos é apontado para ele 
            */    
            aux[length / FITAS] = 0;
            fitas_saida[(fita_resultante - 1) % FITAS].qtd_regs_blocos = aux;
        }

        while (continua) {
            menor.nota = RAND_MAX;
            posicao = -1;
        
            // Procura qual é a menor nota presente no vetor de registro, guardando ele e sua posicao
            for (int i = 0; i < quantidade_fitas; i++) {
                cont_comparacao(analise);
                if (registros[i].nota < menor.nota && qtd_regs_disponiveis_blocos >= 0) {
                    menor = registros[i];
                    posicao = i;
                }
            }

            // Realiza a escrita do registro na fita de saida e le um novo registro da fita de entrada
            cont_transferencia_escrita(analise);
            fwrite(&menor, sizeof(Aluno), 1, fitas_saida[(fita_resultante - 1) % FITAS].arquivo);
            fitas_saida[(fita_resultante - 1) % FITAS].qtd_regs_blocos[length / FITAS]++;
            
            // Lê somente a quantidade de registros presente no bloco
            if (qtd_regs_disponiveis_blocos[posicao] > 0) {
                cont_transferencia_leitura(analise);
                fread(&registros[posicao], sizeof(Aluno), 1, fitas_entrada[posicao].arquivo);
            }

            qtd_regs_disponiveis_blocos[posicao]--;

            // Confere se os registros de todos os blocos foram lidos
            continua = confere_registros_lido(qtd_regs_disponiveis_blocos, quantidade_fitas);
        }

        for(int i = 0; i < quantidade_fitas; i++) {	
            fitas_entrada[i].qtd_blocos--;
        }

        fitas_saida[(fita_resultante - 1) % FITAS].qtd_blocos++;
        quantidade_fitas = get_fitas_disponiveis(fitas_entrada);
        fita_resultante++;
        index++;
        length++;
    }  

    free(qtd_regs_disponiveis_blocos);

    return 1;
}

// Função que verifica se todo o bloco foi lido, retornando 0 caso a condição seja verdadeira e 1 caso seja falsa
int confere_registros_lido(int* qtd_regs_disponiveis_blocos, int quantidade_fitas) {
    int continua = 0;

    for(int i = 0; i < quantidade_fitas; i++) {
        if (qtd_regs_disponiveis_blocos[i] < 0) continua++;
    }

    if (continua == quantidade_fitas) return 0;

    else return 1;
}