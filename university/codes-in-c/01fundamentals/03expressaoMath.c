/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>

int main ()
{      
	// Declarando as variáveis
	int a, b, c;

	printf ("Digite os valores dos termos a seguir:\n");
	scanf ("%d %d %d", &a, &b, &c);

	// Calculando o a expressão
	int y = ((a + b + c) * (a + b + c) * (a + b + c) * (a + b + c)) + ((a * b * c ) * (a * b * c));


	printf ("a = %d, b = %d, c = %d\n", a, b, c);
	printf ("y= %d\n", y);
	
	return 0;
}  	 
