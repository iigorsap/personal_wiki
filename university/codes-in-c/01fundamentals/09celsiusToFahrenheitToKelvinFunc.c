/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>

void converterCelsius(float celsius, float *fahrenheit, float *kelvin);

int main()
{
	float celsius, fahrenheit, kelvin;
	printf("Digite o valor em graus celsius:");
	scanf("%f", &celsius);
	converterCelsius(celsius, &fahrenheit, &kelvin);
	printf("Graus em fahrenheit: %.2f\n", fahrenheit);
	printf("Graus em kelvin: %.2f\n", kelvin);

	return 0;
}

void converterCelsius(float celsius, float *fahrenheit, float *kelvin)
{
	*fahrenheit = (celsius * 1.8) + 32;
	*kelvin = celsius + 273.15;
}
