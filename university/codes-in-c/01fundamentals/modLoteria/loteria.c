/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>
#include <stdlib.h>
#include "loteria.h"

int main()
{
	int escolha1, escolha2, escolha3, n1, n2, n3, nAcertos;

	leituraN(&escolha1, &escolha2, &escolha3);
	nsorteados(&n1, &n2, &n3);
	nAcertos = premiacao(n1, n2, n3, escolha1, escolha2, escolha3);

	switch (premioUsuario(n1, n2, n2, escolha1, escolha2, escolha3))
	{
	case 1:
		printf("Parabéns você acertou 1 número, sua premição é de R$1,00.\n");
		break;
	case 2:
		printf("Parabéns você acertou 2 números, sua premição é de R$1.000,00.\n");
		break;
	case 3:
		printf("Parabéns você acertou 3 números, você acaba de ganhar R$100.000,00!!!!!!.\n");
		break;
	case 0:
		printf("Não foi dessa vez, tente novamente!\n");
		break;
	}

	return 0;
}
void leituraN(int *escolha1, int *escolha2, int *escolha3)
{
	printf("Escolha 3 números de no intervalo de [1,30].");
	printf("\n\nPrimeiro número:");
	scanf("%d", escolha1);
	printf("\nSegundo número:");
	scanf("%d", escolha2);
	printf("\nTerceiro número:");
	scanf("%d", escolha3);
}

int nsorteados(int *n1, int *n2, int *n3)
{
	*n1 = (rand() % 30) + 1;
	*n2 = (rand() % 30) + 1;
	*n3 = (rand() % 30) + 1;

	printf("\nPrimero número: %d", *n1);
	printf("\nSegundo número: %d", *n2);
	printf("\nTerceiro número: %d\n\n", *n3);
}

int premiacao(int n1, int n2, int n3, int escolha1, int escolha2, int escolha3)
{
	int nAcertos = 0;

	if (escolha1 == n1 || escolha1 == n2 || escolha1 == n3)
	{
		nAcertos = nAcertos + 1;
	}
	if (escolha2 == n1 || escolha2 == n2 || escolha2 == n3)
	{
		nAcertos = nAcertos + 1;
	}
	if (escolha3 == n1 || escolha3 == n2 || escolha3 == n3)
	{
		nAcertos = nAcertos + 1;
	}
	return nAcertos;
}
