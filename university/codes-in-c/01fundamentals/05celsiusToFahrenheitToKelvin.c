/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>

int main()
{
	float c, f, k;
	printf(" Digite a temperatura em graus Celsius:\n");
	scanf("%f", &c);

	f = (((9.0 / 5.0) * c) + 32);
	k = (c + 273.15);

	printf(" Temperatura em Fahrenheit:%f\n", f);
	printf(" Temperatura em Kelvin: %f\n", k);

	return 0;
}
