/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>

int main()
{
	double totalcompras, bonuscliente, taxadejuros;
	printf("Insira o valor total de compras efetuadas ao longo do ano pelo cliente:");
	scanf("%lf", &totalcompras);

	if (totalcompras < 50000.00)
	{
		taxadejuros = 0.10;
		bonuscliente = totalcompras * taxadejuros;
		printf("O bônus do cliente é de R$ %lf\n", bonuscliente);
	}

	if (totalcompras >= 50000.00)
	{
		taxadejuros = 0.15;
		bonuscliente = totalcompras * taxadejuros;
		printf("O bônus do cliente é de R$ %lf\n", bonuscliente);
	}
	return 0;
}
