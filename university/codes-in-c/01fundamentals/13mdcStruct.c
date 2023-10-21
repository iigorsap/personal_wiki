/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
	int num;
	int den;
} Racional;

int Eq(Racional r1, Racional r2);
int MDC(int x, int y);

int main()
{
	Racional r1, r2;
	int volta;

	printf("Insira Numerador e Denominador de r1. ");
	printf("Numerador: ");
	scanf("%d", &r1.num);
	printf("Denominador: ");
	scanf("%d", &r1.den);
	printf("Insira numerador e denominador de r2: ");
	scanf("%d %d", &r2.num, &r2.den);
	printf("Numerador: ");
	scanf("%d", &r2.num);
	printf("Denominador: ");
	scanf("%d", &r2.den);

	volta = Eq(r1, r2);

	if (volta == 1)
	{
		printf("R1 e R2 sao iguais.\n\n");
	}
	else
		printf("Os valores de r1 e r2 nao sao iguais.\n\n");
	return 0;
}

int Eq(Racional r1, Racional r2)
{

	int MDCr1 = MDC(r1.num, r1.den);
	int MDCr2 = MDC(r2.num, r2.den);

	r2.num /= MDCr2;
	r1.num /= MDCr1;
	r2.den /= MDCr2;
	r1.den /= MDCr1;

	if ((r2.num == r1.num) && (r2.den == r1.den))
		return 1;
	else
		return 0;
}
int MDC(int x, int y)
{
	int aux;
	do
	{
		aux = x % y;
		x = y;
		y = aux;
	} while (aux != 0);
	return x;
}
