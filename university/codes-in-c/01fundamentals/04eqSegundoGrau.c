/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int delta, a, b, c, x1, x2;

	printf("Digite os valores das variáveis: ");
	scanf("%d %d %d", &a, &b, &c);

	delta = b * b - 4 * a * c;

	printf("\nvalor do delta: %d\n\n", delta);

	x1 = (-b + sqrt(delta)) / 2 * a;
	x2 = (-b - sqrt(delta)) / 2 * a;

	printf("valor de x1: %d\n", x1);
	printf("valor de x2: %d\n", x2);

	return 0;
}
