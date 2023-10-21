/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>

int main()
{
	printf("CÁLCULO DA CONTA DE ENERGIA ELÉTRICA\n");
	printf("____________________________________\n");
	printf("\n");

	double consumototal, consumonormal, consumoexcedido, valorconta, taxabasica = 5.00;

	printf("DIGITE O CONSUMO DE ENERGIA ELÉTRICA (KW):");
	scanf("%lf", &consumototal);
	printf("\n");

	if (consumototal < 500.00)
	{
		valorconta = (consumototal * 0.02) + taxabasica;
		printf("TAXA BÁSICA: %.2lf\n", taxabasica);
		printf("CONSUMO (KW): %.1lf\n", consumototal);
		printf("VALOR DA CONTA (R$): %.2lf\n", valorconta);
	}

	if (consumototal > 500.00 && consumototal < 1000.00)
	{
		consumoexcedido = consumototal - 500;
		valorconta = (consumoexcedido * 0.05) + 10.00 + taxabasica;
		printf("TAXA BÁSICA: %.2lf\n", taxabasica);
		printf("CONSUMO (KW): %.1lf\n", consumototal);
		printf("VALOR DA CONTA (R$): %.2lf\n", valorconta);
	}

	if (consumototal > 1000.00)
	{
		consumoexcedido = consumototal - 1000;
		valorconta = (consumoexcedido * 0.10) + 35 + taxabasica;
		printf("TAXA BÁSICA: %.2lf\n", taxabasica);
		printf("CONSUMO (KW): %.1lf\n", consumototal);
		printf("VALOR DA CONTA (R$): %.2lf\n", valorconta);
	}

	return 0;
}
