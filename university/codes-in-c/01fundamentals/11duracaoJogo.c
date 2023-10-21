/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>

int main()
{
	int horaInicio, minutoInicial, horaFinal, minutoFinal, totalMinutos;

	printf("Digite o horario de inicio do jogo no formato 00:00: ");
	scanf("%d:%d", &horaInicio, &minutoInicial);

	printf("Digite o horario de termino do jogo no formato 00:00: ");
	scanf("%d:%d", &horaFinal, &minutoFinal);
	
	printf("O total de minutos jogados pelo jogador e de %d minutos", duracaoJogo(horaInicio, minutoInicial, horaFinal, minutoFinal));

	return 0;
}

int duracaoJogo(int horaInicio, int minutoInicial, int horaFinal, int minutoFinal)
{
	int tMinutoInicial, tMinutoFinal, tempoTotal;
	tMinutoInicial = (horaInicio * 60); 
	tMinutoFinal = (horaFinal * 60);

	if (horaInicio > horaFinal)
	{
		tMinutoFinal = tMinutoFinal + 1440;
	}

	else if (horaInicio > horaFinal && minutoInicial > minutoFinal)
	{
		tMinutoFinal = tMinutoFinal + 1440;
	}

	tempoTotal = (tMinutoFinal + minutoFinal) - (tMinutoInicial + minutoInicial);

	return tempoTotal;
}
