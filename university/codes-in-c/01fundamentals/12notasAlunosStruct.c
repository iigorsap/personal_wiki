/* Igor Santiago Almeida Paixão
  Disciplina: BCC201
  Matrícula: 1914033
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 100
#define M 10

typedef struct
{
	char nome[100];
	long int matricula;
	float notas[M];
} Aluno;

Aluno encontraAluno(Aluno alunos[], int nAlunos, int matricula);

int main()
{
	Aluno alunos[N];
	int n1, n2, i;
	long int matricula;
	int mediaN = 0;
	printf("Digite o número de alunos: ");
	scanf("%d", &n1);
	printf("Digite a quantiade de provas: ");
	scanf("%d", &n2);

	for (int i = 0; i < n1; i++)
	{
		fgets(alunos[i].nome, N, stdin);
		printf("Digite o número de matricula do aluno %d: ", i);
		scanf("%ld", &alunos[i].matricula);
		for (int j = 0; j < n2; i++)
		{
			scanf("%f", alunos[j].notas);
		}
	}
	encontraAluno(alunos, n1, matricula);
	printf("Nome: %s", alunos[i].nome);
	printf("Média das notas: ");
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			mediaN += alunos[i].notas[j];
			mediaN /= N; 
		}
	}
	return 0;
}
Aluno encontraAluno(Aluno alunos[], int nAlunos, int matricula)
{
	printf("Digite o número de matricula: ");
	scanf("%ld", &matricula);
	for (int i = 0; i <= nAlunos; i++)
	{
		if (matricula == alunos[i].matricula)
			return alunos[i];
	}
}
