// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 12/2021.

#include "arquivo.h"

void print_arquivo(FILE* arq, int quantidade){
    Aluno aluno;
    int i = 1;
    
    rewind(arq);
    while(i <= quantidade && fread(&aluno, sizeof(Aluno), 1, arq) == 1){
        print_aluno(aluno);
        i++;
    }
    rewind(arq);
}

// Criando os arquivos binários necéssarios na intercalação balanceada
void cria_arquivo_intercalacao_balanceada(FILE** arq, FILE** arq_texto, int situacao, int quantidade){
    
    FILE* arq_bin;

     switch (situacao) {
        
        case 1:  
        
            if((arq_bin = fopen("PROVAO-CRESCENTE.bin", "wb")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-CRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            converter_bin(*arq_texto, arq_bin, quantidade);

            fclose(arq_bin);

            if((*arq = fopen("PROVAO-CRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-CRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }
            
            break;  

        case 2:

            if((arq_bin = fopen("PROVAO-DECRESCENTE.bin", "wb")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-DECRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            converter_bin(*arq_texto, arq_bin, quantidade);

            fclose(arq_bin);

            if((*arq = fopen("PROVAO-DECRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-DECRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }
            
            break;

        case 3: 

           if((arq_bin = fopen("PROVAO-ALEATORIO.bin", "wb")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-ALEATORIO.bin nao pode ser criado corretamente.");
                exit(1);
            }

            converter_bin(*arq_texto, arq_bin, quantidade);

            fclose(arq_bin);

            if((*arq = fopen("PROVAO-ALEATORIO.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-ALEATORIO.bin nao pode ser criado corretamente.");
                exit(1);
            }

            break;
        
        default:
            puts("ERRO!! Nao foi criado nenhum arquivo!");
    }    
}

// Criando os arquivos binários necéssarios na ordenação externa
void cria_arquivos_qs_externo(FILE** arq_LEs, FILE** arq_Li, FILE** arq_Ei, FILE** arq_texto, int situacao, int quantidade) {

    FILE *arq_bin;

    switch (situacao) {
        
        case 1:  
        
            if((arq_bin = fopen("PROVAO-CRESCENTE.bin", "wb")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-CRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            converter_bin(*arq_texto, arq_bin, quantidade);

            fclose(arq_bin);

            if((*arq_Li = fopen("PROVAO-CRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-CRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            if((*arq_Ei = fopen("PROVAO-CRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-CRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            if((*arq_LEs = fopen("PROVAO-CRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-CRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }
            
            break;  

        case 2:

            if((arq_bin = fopen("PROVAO-DECRESCENTE.bin", "wb")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-DECRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            converter_bin(*arq_texto, arq_bin, quantidade);

            fclose(arq_bin);

            if((*arq_Li = fopen("PROVAO-DECRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-DECRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            if((*arq_Ei = fopen("PROVAO-DECRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-DECRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }

            if((*arq_LEs = fopen("PROVAO-DECRESCENTE.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-DECRESCENTE.bin nao pode ser criado corretamente.");
                exit(1);
            }
            
            break;

        case 3: 

            if((arq_bin = fopen("PROVAO-ALEATORIO.bin", "wb")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-ALEATORIO.bin nao pode ser criado corretamente.");
                exit(1);
            }

            converter_bin(*arq_texto, arq_bin, quantidade);

            fclose(arq_bin);

            if((*arq_Li = fopen("PROVAO-ALEATORIO.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-ALEATORIO.bin nao pode ser criado corretamente.");
                exit(1);
            }

            if((*arq_Ei = fopen("PROVAO-ALEATORIO.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-ALEATORIO.bin nao pode ser criado corretamente.");
                exit(1);
            }

            if((*arq_LEs = fopen("PROVAO-ALEATORIO.bin", "r+b")) == NULL) {
                puts("ERRO!! O arquivo PROVAO-ALEATORIO.bin nao pode ser criado corretamente.");
                exit(1);
            }
            
            break;
        
        default:
            puts("ERRO!! Nao foi criado nenhum arquivo!");
    }    
}

// Lendo os dados de arq_texto (arquivo texto) e escrevendo em arq_bin (arquivo binário)
void converter_bin(FILE* arq_texto, FILE* arq_bin, int quantidade) {
    long int inscricao;
    double nota;
    char estado[3];
    char cidade[51];
    char curso[31];

    int i = 0;

    while(i < quantidade) {
        fscanf(arq_texto, "%ld", &inscricao);
		fscanf(arq_texto, "%lf", &nota);
		fgets(estado, 2, arq_texto);
		fgets(cidade, 50, arq_texto);
		fgets(curso, 30, arq_texto);

        Aluno* aluno = malloc(sizeof(Aluno));
        aluno->inscricao = inscricao;
        aluno->nota = nota;
        strcpy(aluno->estado, estado);
        strcpy(aluno->cidade, cidade);
        strcpy(aluno->curso, curso);

        fwrite(aluno, sizeof(Aluno), 1, arq_bin);
        free(aluno);

        i++;
    }
}


void converter_texto(FILE* arq_bin, FILE* arq_texto, int quantidade) {
    long int inscricao;
    double nota;
    char estado[3];
    char cidade[51];
    char curso[31];

    int i = 0;

    while(i < quantidade)
	{
		Aluno* aluno = malloc(sizeof(Aluno));

		fread(aluno, sizeof(Aluno), 1, arq_bin);

		inscricao = aluno->inscricao;
		nota = aluno->nota;
		strcpy(estado, aluno->estado);
		strcpy(cidade, aluno->cidade);
		strcpy(curso, aluno->curso);

		print_inscricao_arq(arq_texto, inscricao);
		print_nota_arq(arq_texto, nota);
		fprintf(arq_texto, "%-s %-s %-s\n", estado, cidade, curso);
		
		free(aluno);

		i++;
	}

	fclose(arq_bin);

    // Deletando os arquivos bin usados
    remove("PROVAO-CRESCENTE.bin");
    remove("PROVAO-DECRESCENTE.bin");
    remove("PROVAO-ALEATORIO.bin");
}