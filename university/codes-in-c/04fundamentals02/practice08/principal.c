#include "arvore.h"
#include <stdio.h>

int main ()
{
	int n, no;
	TArvore *arvore;

	//ler n
	scanf("%d", &n);

	//ler o primeiro no e criar a raiz da arvore
	TArvore_Inicia(&(*arvore)); // Iniciando Arvore

	scanf("%d", &no); // Lendo no raiz

	TItem aux;
	aux.chave = no;	
	TArvore_Insere_Raiz(&(*arvore), aux); // Inserindo no Raiz

	for(int i = 1; i<n; i++) {
		scanf("%d", &no);	//ler o no
		aux.chave = no;		//inserir na arvore
		TArvore_Insere(&(*arvore), aux);
	}

	//gerar percurso em ordem prefixa
	printf("PREFIXA: ");
	Prefixa(*arvore);
	printf("\n");
	//gerar percurso em ordem infixa
	printf("INFIXA: ");
	Infixa(*arvore);
	printf("\n");
	//gerar percurso em ordem posfixa
	printf("POSFIXA: ");
	Posfixa(*arvore);
	printf("\n");

	return 0;
}
