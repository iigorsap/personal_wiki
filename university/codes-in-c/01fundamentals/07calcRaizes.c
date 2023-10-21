/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>
#include <math.h>

double calculaRaizes(double a, double b, double c, double delta, double *x1, double *x2);

int main()
{
	double a, b, c, delta, x1, x2;

	printf("Digite o valor das variáveis a, b e c da função quadrática:");
	scanf("%lf %lf %lf", &a, &b, &c);
	calculaRaizes(a, b, c, delta, &x1, &x2);
	printf("As raízes da equação são: %.2lf e %.2lf", x1, x2);

	return 0;
}

double calculaRaizes(double a, double b, double c, double delta, double *x1, double *x2)
{
	delta = pow(b, 2) - 4 * a * c;

	if (delta >= 0)
	{

		*x1 = (-b + sqrt(delta)) / 2 * a;
		*x2 = (-b - sqrt(delta)) / 2 * a;

		return 1;
	}
	else
		return 0;
}
