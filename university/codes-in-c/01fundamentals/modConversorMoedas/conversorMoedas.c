#include <stdio.h>
#include "cambio.h"

int main()
{
    double real;
    printf("Digite o valor em reais: R$ ");
    scanf("%lf", &real);

    double dollar = realToDollar(real);
    printf("R$ %.2lf equivale a US$ %.2lf\n", real, dollar);

    return 0;
}
