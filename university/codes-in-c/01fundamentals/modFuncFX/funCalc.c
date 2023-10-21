/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>
#include <math.h>
#include "funCalc.h"

int main()
{

  double x, y, fx;

  printf("Digite o valor de X:");
  scanf("%lf", &x);
  printf("Digite o valor de Y:");
  scanf("%lf", &y);

  funCalc(&x, &y, &fx);

  printf("\nValor de x: %lf", x);
  printf("\nValor de y: %lf", y);
  printf("\nValor de f: %lf", fx);

  return 0;
}

void funCalc(double *x, double *y, double *fx)
{
  if (x >= 0 && y >= 0)
    *fx = *x + *y;

  if (x >= 0 && y < 0)
    *fx = *x + pow(*y, 2);

  if (x < 0 && y >= 0)
    *fx = pow(*x, 2) + *y;

  if (x < 0 && y < 0)
    *fx = pow(*x, 2) + pow(*y, 2);
}
