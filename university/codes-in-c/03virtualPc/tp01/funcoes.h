#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// PI
#define PI 3.1416

// Opcode
#define SALVAR_MEMORIA 0
#define SOMAR 1
#define SUBTRAIR 2
#define SAIR -1

// Dimensões
#define T 100

typedef struct{
    int Instrucoes[T][4];
    int RAM[T];
}Dados;

// Montado RAM e Instrucoes
void montandoMemoria(Dados **memoria);
void maquina(Dados *memoria);

// Menu de Operacoes
void menu(Dados *memoria);

// Operacoes Basicas
void progSoma(Dados *memoria, int parcela1, int parcela2);
void progSubtracao(Dados *memoria, int minuendo, int subtraendo);
void progMultiplicacao(Dados *memoria, int multiplicando, int multiplicador);
void progDivisao(Dados *memoria, int dividendo, int divisor);

// Areas
void progPotencia(Dados *memoria, int base, int expoente);
void progAreaDoTriangulo(Dados *memoria, int base, int altura);
void progAreaDoRetangulo(Dados *memoria, int base, int altura);
void progAreaDoLosango(Dados *memoria, int diametroMaior, int diametroMenor);
void progAreaDoTrapezio(Dados *memoria, int baseMaior, int baseMenor, int altura);
void progAreaDoCirculo(Dados *memoria, int raio);

// Juros
void progJurosSimples(Dados *memoria, int capital, int taxaJuros, int tempo);

// Principais Solidos
void progVolumeDaEsfera(Dados *memoria, int raio);
void progAreaDaEsfera(Dados *memoria, int raio);
void progVolumeDoCilindro(Dados *memoria, int raio, int altura);
void progAreaDoCilindro(Dados *memoria, int raio, int altura);
void progVolumeDoCone(Dados *memoria, int raio, int altura);
void progVolumeDoPrisma(Dados *memoria, int areaBase, int altura);
void progVolumeDaPiramide(Dados *memoria, int areaBase, int altura);

// Conversao Unidades de Medidas
void progHorasParaMinutos(Dados *memoria, int horas);
void progHorasParaSegundos(Dados *memoria, int horas);
void progMinutosParaSegundos(Dados *memoria, int minutos);
void progCelsiusParaFahrenheit(Dados *memoria, int celsius);
void progCelsiusParaKelvin(Dados *memoria, int celsius);
void progLitrosParaMl(Dados *memoria, int litros);
void progVelocidadeMedia(Dados* memoria, int distanciaFinal, int distanciaInicial, int tempoFinal, int tempoInicial);

// Liberando memoria da struct memoria
void liberaMemoria(Dados *memoria);
