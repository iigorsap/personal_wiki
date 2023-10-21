/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>

int main()
{
	// Declarando as variáveis
	float a, b, c, d, e;

	printf("Digite os valores dos termos a seguir:\n");
	scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);

	// Calculando o resultado
	float x = (a * a * a) + (((b + c) / d) + e);

	printf("a = %f, b = %f, c = %f, d = %f, e = %f\n", a, b, c, d, e);
	printf("x = %f\n", x);

	return 0;
}
