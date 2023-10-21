#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
	alunos = (TipoAluno*) malloc(n * sizeof(TipoAluno));
	return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
	free(alunos);
	alunos = NULL;
	return alunos;
}

void ordena(TipoAluno *alunos, int n){
	int min;
	TipoAluno nome_aux[1];

	for (int i = 0; i < n; i++)
	{	
		min = i;
		for (int j = i; j < n; j++)
		{
			if(strcmp(alunos[j].nome, alunos[min].nome) < 0){
				min = j;
			}
		}
		nome_aux[0] = alunos[i];
		alunos[i] = alunos[min];
		alunos[min] = nome_aux[0];
	}
}
