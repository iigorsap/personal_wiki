// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#include "quicksort_externo.h"

// Método principal do QuickSort Externo

void main_quicksort_externo(FILE **arq_Li, FILE **arq_Ei, FILE **arq_LEs, int Esq, int Dir, Analise *analise) {
    int i, j;

    // Area de armazenamento interna
    Aluno *area_pivo;
    area_pivo = malloc(SIZE_AREA * sizeof(Aluno));

    if (Dir - Esq < 1) return;
        
    new_area_vazia(area_pivo, analise);
    
    particao(arq_Li, arq_Ei, arq_LEs, area_pivo, Esq, Dir, &i, &j, analise);
    
    fflush(*arq_Li);
    fflush(*arq_Ei);
    fflush(*arq_LEs);

    // Ordena primeiro o subarquivo menor
    if ( i - Esq < Dir - j ) {
        main_quicksort_externo(arq_Li, arq_Ei, arq_LEs, Esq, i, analise);
        main_quicksort_externo(arq_Li, arq_Ei, arq_LEs, j, Dir, analise);
    }
    else {
        main_quicksort_externo(arq_Li, arq_Ei, arq_LEs, j, Dir, analise);
        main_quicksort_externo(arq_Li, arq_Ei, arq_LEs, Esq, i, analise);
    }

    free(area_pivo);
}

void leitura_superior(FILE **arq_LEs, Aluno *ultimo_aluno_lido, int *Ls, short *onde_ler, Analise *analise) {
    fseek(*arq_LEs, (*Ls-1)*sizeof(Aluno), SEEK_SET);
    
    cont_transferencia_leitura(analise);
	
    fread(ultimo_aluno_lido, sizeof(Aluno), 1, *arq_LEs);
    
    (*Ls)--;
    
    *onde_ler = FALSE;
}

void leitura_inferior(FILE **arq_Li, Aluno *ultimo_aluno_lido, int *Li, short *onde_ler, Analise *analise) {
    
    cont_transferencia_leitura(analise);
    
    fread(ultimo_aluno_lido, sizeof(Aluno), 1, *arq_Li);
    
    (*Li)++; 
    
    *onde_ler = TRUE;
}

void insere_aluno_na_area(Aluno *area_pivo, Aluno *ultimo_aluno_lido, int *qtd_elementos_area, Analise *analise) {
    // Insere ultimo_aluno_lido de forma ordenada na Area
    insere_aluno_na_area_(*ultimo_aluno_lido, area_pivo, analise);
    *qtd_elementos_area = numeros_celulas_ocupadas(area_pivo, analise);
}

void escrita_superior(FILE **arq_LEs, Aluno aluno, int *Es, Analise *analise) {
    fseek(*arq_LEs, (*Es-1)*sizeof(Aluno), SEEK_SET);
    cont_transferencia_escrita(analise);
	fwrite(&aluno, sizeof(Aluno), 1, *arq_LEs);
    (*Es)--;
}

void escrita_inferior(FILE **arq_Ei, Aluno aluno, int *Ei, Analise *analise) {
    cont_transferencia_escrita(analise);
    fwrite(&aluno, sizeof(Aluno), 1, *arq_Ei);
    (*Ei)++;
}

void retira_maior_elemento(Aluno *area_pivo, Aluno *aluno, int *qtd_elementos_area, Analise *analise) {
    retira_maior_elemento_(area_pivo, aluno, analise);
    *qtd_elementos_area = numeros_celulas_ocupadas(area_pivo, analise);
}

void retira_menor_elemento(Aluno *area_pivo, Aluno *aluno, int *qtd_elementos_area, Analise *analise) {
    retira_menor_elemento_(area_pivo, aluno, analise);
    *qtd_elementos_area = numeros_celulas_ocupadas(area_pivo, analise);  
}

void particao(FILE **arq_Li, FILE **arq_Ei, FILE **arq_LEs, Aluno* area_pivo, int Esq, int Dir, int *i, int *j, Analise *analise) {
    int Ls = Dir;
    int Es = Dir;
    int Li = Esq;
    int Ei = Esq;
    int qtd_elementos_area = 0;
    double limite_inferior = INT_MIN;
    double limite_superior = INT_MAX;

    short onde_ler = TRUE;

    Aluno aluno;

    fseek(*arq_Li, (Li-1)*sizeof(Aluno), SEEK_SET);
	fseek(*arq_Ei, (Ei-1)*sizeof(Aluno), SEEK_SET);

    *i = Esq - 1;
    *j = Dir + 1;

    while (Ls >= Li) {

        Aluno ultimo_aluno_lido;
        
        if (qtd_elementos_area < SIZE_AREA - 1) {

            if (onde_ler) {
                leitura_superior(arq_LEs, &ultimo_aluno_lido, &Ls, &onde_ler, analise);
            }
            else {
                leitura_inferior(arq_Li, &ultimo_aluno_lido, &Li, &onde_ler, analise);
            }

            insere_aluno_na_area(area_pivo, &ultimo_aluno_lido, &qtd_elementos_area, analise);

            continue;
        }

        if (Ls == Es) {
            leitura_superior(arq_LEs, &ultimo_aluno_lido, &Ls, &onde_ler, analise);
        }
        else if (Li == Ei) {
            leitura_inferior(arq_Li, &ultimo_aluno_lido, &Li, &onde_ler, analise);
        }
        else if (onde_ler) {
            leitura_superior(arq_LEs, &ultimo_aluno_lido, &Ls, &onde_ler, analise);        
        }
        else {
            leitura_inferior(arq_Li, &ultimo_aluno_lido, &Li, &onde_ler, analise);
        }

        cont_comparacao(analise);
        if (ultimo_aluno_lido.nota > limite_superior) {
            *j = Es;
            escrita_superior(arq_LEs, ultimo_aluno_lido, &Es, analise);
            continue;
        }

        cont_comparacao(analise);
        if (ultimo_aluno_lido.nota < limite_inferior) {
            *i = Ei;
            escrita_inferior(arq_Ei, ultimo_aluno_lido, &Ei, analise);
            continue;
        }

        insere_aluno_na_area(area_pivo, &ultimo_aluno_lido, &qtd_elementos_area, analise);

        if (Ei - Esq < Dir - Es) {
            retira_menor_elemento(area_pivo, &aluno, &qtd_elementos_area, analise);
            escrita_inferior(arq_Ei, aluno, &Ei, analise);
            limite_inferior = aluno.nota;
        }
        else {
            retira_maior_elemento(area_pivo, &aluno, &qtd_elementos_area, analise);
            escrita_superior(arq_LEs, aluno, &Es, analise);
            limite_superior = aluno.nota;
        }
    }

    while (Ei <= Es) {
        retira_menor_elemento(area_pivo, &aluno, &qtd_elementos_area, analise);
        escrita_inferior(arq_Ei, aluno, &Ei, analise);
    }
}

// Cria uma Área vazia
void new_area_vazia(Aluno *area_pivo, Analise *analise) {
    // Preenchendo a área com células vazias
    for(int i=0; i<SIZE_AREA; i++) {
        area_pivo[i].inscricao = -1;
        area_pivo[i].nota = -1.0;
        strcpy(area_pivo[i].estado,"XX");
        strcpy(area_pivo[i].cidade,"XX");
        strcpy(area_pivo[i].curso,"XX");
    }
}

// Insere o ultimo aluno lido ordenadamente na Área
void insere_aluno_na_area_(Aluno ultimo_aluno_lido, Aluno *area_pivo, Analise *analise) {
    int i = 0;
    int j = 18, k = 19;

    // Achando a posição correta na área
    cont_comparacao(analise);
    cont_comparacao(analise);

    while (area_pivo[i].nota < ultimo_aluno_lido.nota && area_pivo[i].inscricao != -1 && i < SIZE_AREA) {
        cont_comparacao(analise);
        cont_comparacao(analise);
        i++;
    }
    
    // Reorganizando a área
    while (j >= i) {
        area_pivo[k] = area_pivo[j];
        j--;
        k--;
    }
    
    // Posição recebe o aluno a ser inserido
    area_pivo[i] = ultimo_aluno_lido;
}

// Retorna o número de células ocupadas na Área
int numeros_celulas_ocupadas(Aluno *area_pivo, Analise *analise) {
    int cont = 0;

    // Procura até achar uma posição vazia ou até o fim da área
    cont_comparacao(analise);
    while (area_pivo[cont].inscricao != -1 && cont < SIZE_AREA) {
        cont_comparacao(analise);
        cont++;
    }

    return cont;
}

// Retira o ultimo Aluno presente na Área
void retira_maior_elemento_(Aluno *area_pivo, Aluno *aluno, Analise *analise) {
    int cont = 0;

    // Achando a última posição válida da área
    cont_comparacao(analise);

    while (area_pivo[cont].inscricao != -1 && cont < SIZE_AREA) {
        cont_comparacao(analise);
        cont++;
    }

    cont--; // Achar o último aluno válido, antes da primeira posição vazia (aluno com inscrição -1)

    // aluno recebe o último aluno
    *aluno = area_pivo[cont];

    // Esta última posição se torna vazia
    area_pivo[cont].inscricao = -1;
    area_pivo[cont].nota = -1.0;
    strcpy(area_pivo[cont].estado,"XX");
    strcpy(area_pivo[cont].cidade,"XX");
    strcpy(area_pivo[cont].curso,"XX");
}

// Retira o primeiro Aluno presente na Área
void retira_menor_elemento_(Aluno *area_pivo, Aluno *aluno, Analise *analise) {
    int i = 0, j = 1;

    // aluno recebe o primeiro elemento da área
    *aluno = area_pivo[0];

    // Reorganizando a área
    cont_comparacao(analise);
    while (area_pivo[j].inscricao != -1 && i < SIZE_AREA-1) {
        cont_comparacao(analise);
        area_pivo[i] = area_pivo[j];
        i++;
        j++;
    }

    // Criando uma posição vazia no último elemento
    area_pivo[i].inscricao = -1;
    area_pivo[i].nota = -1.0;
    strcpy(area_pivo[i].estado,"XX");
    strcpy(area_pivo[i].cidade,"XX");
    strcpy(area_pivo[i].curso,"XX");
}

// Função que imprime a área
void imprimirArea(Aluno *area_pivo) {
    puts("===== Área =====");

    for (int i = 0 ; i < SIZE_AREA ; i++) print_aluno(area_pivo[i]);
    puts("");
}
