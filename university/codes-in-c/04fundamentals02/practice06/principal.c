#include "ordenacao.h"
#include <stdio.h>
#include <string.h>

int main ()
{
	int i;
	int n, k;
  	TipoAluno *alunos;

	//ler as quantidades	
	scanf("%d", &n);
	scanf("%d", &k);
	
	//alocar o vetor
	alunos = alocaAlunos(alunos, n);

	//preencher o vetor
	for (int i = 0; i < n; i++)
	{
		scanf("%s", alunos[i].nome);
	}
	
	//ordenar
	ordena(alunos, n);

	//imprimir o resultado
	for (int i = 0; i <=n; i++)
	{	
		if(strcmp(alunos[i].nome, alunos[k].nome) == 0){
			
			printf("%s\n", alunos[i-1].nome);
		}
	}

	//desalocar o vetor
	alunos = desalocaAlunos(alunos);

  return 0;
}