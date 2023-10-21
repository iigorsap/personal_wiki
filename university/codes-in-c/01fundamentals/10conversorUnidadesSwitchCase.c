/* Aluno: Igor Santiago ALmeida Paixão
   Turma: BBC201-61P
   Matrícula: 1914033
*/

#include <stdio.h>

// Protótipos das funções //
double GrausRadianos(double graus);
double RadianosGraus(double radianos);
double CelsiusFahrenheit(double celsius);
double CelsiusKelvin(double celsius);
double FahrenheitCelsius(double fahrenheit);
double FahrenheitKelvin(double fahrenheit);
double KelvinCelsius(double kelvin);
double KelvinFahrenheit(double kelvin);

int main()
{
	int alt, alt2, alt3;
	double radianos, graus, celsius, fahrenheit, kelvin;
	printf("## CONVERSOR DE UNIDADES ## \n\n");
	printf("1) Angulo\n");
	printf("2) Temperatura\n\n");
	printf("Digite a opção desejada:");
	scanf("%d", &alt);
	printf("\n");

	switch (alt)
	{
	case 1:
		printf("Qual a unidade de origem?\n\n");
		printf("1) Graus\n");
		printf("2) Radianos\n\n");
		printf("Seleciona uma opção:");
		scanf("%d", &alt2);
		printf("\n");

		switch (alt2)
		{

		case 1:
			printf("Digite o valor em Graus:");
			scanf("%lf", &graus);
			printf("\n");
			printf("Valor em radianos: %lf\n", GrausRadianos(graus));
			printf("\n");
			break;

		case 2:
			printf("Digite o valor em Radianos:");
			scanf("%lf", &radianos);
			printf("\n");
			printf("Valor em Graus: %lf\n", RadianosGraus(radianos));
			printf("\n");
			break;
		}
		break;

	case 2:
		printf("Qual a unidade de origem?\n\n");
		printf("1) Celsius\n");
		printf("2) Fahrenheit\n");
		printf("3) Kelvin\n\n");
		printf("Seleciona uma opção:");
		scanf("%d", &alt3);
		printf("\n");

		switch (alt3)
		{

		case 1:
			printf("Digite o valor em Celsius:");
			scanf("%lf", &celsius);
			printf("\n");
			printf("Valor em Fahrenheit: %.2lf\n", CelsiusFahrenheit(celsius));
			printf("Valor em Kelvin: %.2lf\n", CelsiusKelvin(celsius));
			break;
		case 2:
			printf("Digite o valor em Fahrenheit:");
			scanf("%lf", &fahrenheit);
			printf("\n");
			printf("Valor em Celsius: %.2lf\n", FahrenheitCelsius(fahrenheit));
			printf("Valor em Kelvin: %.2lf\n", FahrenheitKelvin(fahrenheit));
			break;
		case 3:
			printf("Digite o valor em Kelvin:");
			scanf("%lf", &kelvin);
			printf("\n");
			printf("Valor em Celsius: %.2lf\n", KelvinCelsius(kelvin));
			printf("Valor em Fahrenheit: %.2lf\n", KelvinFahrenheit(kelvin));
			break;
		}
		break;
	}
	return 0;
}

// Definições das funções ultilizadas //

double GrausRadianos(double graus)
{
	return (graus / 180) * 3.141593;
}

double RadianosGraus(double radianos)
{
	return (radianos * 3.141593) / 180;
}

double CelsiusFahrenheit(double celsius)
{
	return 1.8 * celsius + 32;
}

double CelsiusKelvin(double celsius)
{
	return celsius + 273.15;
}

double FahrenheitCelsius(double fahrenheit)
{
	return (fahrenheit - 32) / 1.8;
}

double FahrenheitKelvin(double fahrenheit)
{
	return (fahrenheit + 459.67) * 1.8;
}

double KelvinCelsius(double kelvin)
{
	return kelvin - 273.15;
}

double KelvinFahrenheit(double kelvin)
{
	return ((kelvin - 273.15) * 1.8) + 32.00;
}
