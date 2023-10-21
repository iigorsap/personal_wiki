/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>
int main()
{
	float g, r;
	printf(" Digite o grau desejável, para conversão em radianos:\n");
	scanf("%f", &g);
	r = ((3.1415926535 / 180) * g);

	printf(" o radiano equivalente ao grau é:%f\n", r);

	return 0;
}
