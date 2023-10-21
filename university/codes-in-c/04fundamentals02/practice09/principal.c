#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	//criar variavel para tabela hash
	THash *tabela_hash;
	int nro_listas, qtd_chaves;

	//ler tamanho da tabela hash e a quantidade de chaves
	scanf("%d", &nro_listas);
	scanf("%d", &qtd_chaves);

	int *chaves = malloc(qtd_chaves * sizeof(int));
	
	
	//inicializar a tabela hash
	THash_Inicia(tabela_hash, nro_listas);
	tabela_hash->qtd_chaves = qtd_chaves;
	
	//para cada chave da entrada, ler e inserir na tabela hash
	TItem item;
	for (int i = 0; i <= tabela_hash->qtd_chaves; i++)
	{	
		scanf("%d", &item.chave);
		// printf(" %d ", item.chave);
		THash_Insere(tabela_hash, item);
	}

	//imprimir a tabela hash de acordo com a especificacao da saida
   
	for (int i = 0; i < tabela_hash->nro_listas; i++)
	{	
		printf("%d ", i);
		TLista_Imprime(&tabela_hash->pLista[i]);
	}
	
	free(chaves);
	
	return 0;
}
