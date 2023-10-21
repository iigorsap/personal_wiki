#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h";

int main(){
    Dados *memoria;
    montandoMemoria(&memoria);
    menu(memoria);
    liberaMemoria(memoria);
    return 0;
}

void montandoMemoria(Dados **memoria){
    (*memoria) = malloc(sizeof(Dados));
    
    srand(time(NULL));
    for(int i = 0; i < T; i++){
        for(int j = 0; j < 4; j++){
            (*memoria)->Instrucoes[i][j] = 0;
        }
    }
    
    for(int i = 0; i < T; i++){
        (*memoria)->RAM[i] = rand() % 1000;
    }
}

void maquina(Dados *memoria){
       
    // Language -> Cave Language
    //01|22|13|45 => isto é uma instrução 
	//02|33|12|01 => isto é uma instrução
				
	// 0 => opcode => salvar na memória
	// 1 => opcode => somar
	// 2 => opcode => subtrair
	//SAIR => opcode => Sair
    
    int end1 = 0;
    int end2 = 0;
    int end3 = 0;
    int PC = 0;    
    int opcode = -2;

    while (opcode != SAIR){

        opcode = memoria->Instrucoes[PC][0];

        switch (opcode){
            case SALVAR_MEMORIA:{
                end1 = memoria->Instrucoes[PC][1];
                end2 = memoria->Instrucoes[PC][2];
                memoria->RAM[end2] = end1;
                break;
            }
            case SOMAR:{
                end1 = memoria->Instrucoes[PC][1];
                end2 = memoria->Instrucoes[PC][2];
                end3 = memoria->Instrucoes[PC][3];
                memoria->RAM[end3] = memoria->RAM[end1] + memoria->RAM[end2];
                break;
            }
            case SUBTRAIR:{
            
                end1 = memoria->Instrucoes[PC][1];
                end2 = memoria->Instrucoes[PC][2];
                end3 = memoria->Instrucoes[PC][3];
                memoria->RAM[end3] = memoria->RAM[end1] - memoria->RAM[end2];
                break;
            }       
        }
        PC++;
    }
}

void menu(Dados *memoria){
    int opcao = -1;
    int a, b, c, d;

    do{
        printf("\n");
        printf("# Bem-vindo a MAQUINA DE OPERAOES #\n");
        printf("\n_____Operacoes basicas_____\n");
        printf("1. Soma\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicao\n");
        printf("4. Divisao\n");
        printf("5. Potenciacao\n");
        printf("\n_____Figuras Planas_____\n");
        printf("6. Area do Triangulo\n");
        printf("7. Area do Retangulo\n");
        printf("8. Area do Losango\n");
        printf("9. Area do Trapezio\n");
        printf("10. Area do Circulo\n");
        printf("\n_____Matematica Financeira_____\n");
        printf("11. Juros Simples\n");
        printf("\n_____Principais Solidos_____\n");
        printf("12. Volume da Esfera\n");
        printf("13. Area da Esfera\n");
        printf("14. Volume da Cilindro\n");
        printf("15. Area da Cilindro\n");
        printf("16. Volume do Cone\n");
        printf("17. Volume do Prisma\n");
        printf("18. Volume da Piramide\n");
        printf("\n_____Conversao Unidades de Medidas_____\n");
        printf("19. Horas -> Minutos\n");
        printf("20. Horas -> Segundos\n");
        printf("21. Minutos -> Segundos\n");
        printf("22. Celsius->Fahrenheit\n");
        printf("23. Celsius->Kelvin\n");
        printf("24. Litros->ML\n");
        printf("25. Velocidade Media\n");
        printf("\n_____EXIT_____\n");
        printf("0. SAIR\n");
        printf("\n");
        
        printf("\nEscolha uma operacao:\n");
        printf("-> "); scanf("%d", &opcao);
        
        switch (opcao){
            
        case 1:
            system("cls");
            printf("Digite a 1 parcela: "); scanf("%d", &a);
            printf("Digite a 2 parcela: "); scanf("%d", &b);
            system("cls");            
            progSoma(memoria, a, b);
            printf("\nA SOMA DE %d + %d = %d\n\n", a, b, memoria->RAM[1]);
            scanf("Tecle ENTER para continuar.");
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            printf("Digite o minuendo: "); scanf("%d", &a);
            printf("Digite o subtraendo: "); scanf("%d", &b);
            system("cls");            
            progSubtracao(memoria, a, b);
            printf("A DIFERENCA DE %d - %d = %d\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            printf("Digite o multiplicando: "); scanf("%d", &a);
            printf("Digite o multiplicador: "); scanf("%d", &b);
            system("cls");            
            progMultiplicacao(memoria, a, b);
            printf("O PRODUTO DE %d x %d = %d\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            printf("Digite o dividendo: "); scanf("%d", &a);
            printf("Digite o divisor: "); scanf("%d", &b);
            system("cls");            
            progDivisao(memoria, a, b);
            printf("O QUOCIENTE DE %d / %d = %d\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
         case 5:
            system("cls");
            printf("Digite a base: "); scanf("%d", &a);
            printf("Digite o expoente: "); scanf("%d", &b);
            system("cls");            
            progPotencia(memoria, a, b);
            printf("A POTENCIA %d^%d = %d\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            printf("Digite a base: "); scanf("%d", &a);
            printf("Digite a altura: "); scanf("%d", &b);
            system("cls");            
            progAreaDoTriangulo(memoria, a, b);
            printf("AREA DO TRIANGULO DE BASE %d E ALTURA %d = %dm^2\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            printf("Digite a base: "); scanf("%d", &a);
            printf("Digite a altura: "); scanf("%d", &b);
            system("cls");            
            progAreaDoRetangulo(memoria, a, b);
            printf("AREA DO RETANGULO DE BASE %d E ALTURA %d = %dm^2\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            printf("Digite o diametro maior: "); scanf("%d", &a);
            printf("Digite o diametro menor: "); scanf("%d", &b);
            system("cls");            
            progAreaDoLosango(memoria, a, b);
            printf("AREA DO LOSANGO DE DIAMENTRO MAIOR %d E DIAMETRO MENOR %d = %dm^2\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 9:
            system("cls");
            printf("Digite o base maior: "); scanf("%d", &a);
            printf("Digite o base menor: "); scanf("%d", &b);
            printf("Digite a altura: "); scanf("%d", &c);
            system("cls");            
            progAreaDoTrapezio(memoria, a, b, c);
            printf("AREA DO TRAPEZIO DE BASE MAIOR %d, BASE MENOR %d E ALTURA %d = %dm^2\n\n", a, b, c, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 10:
            system("cls");
            printf("Digite o raio: "); scanf("%d", &a);
            system("cls");            
            progAreaDoCirculo(memoria, a);
            printf("AREA DO CIRCULO DE RAIO %d = %dm²\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 11:
            system("cls");
            printf("Digite o capital: "); scanf("%d", &a);
            printf("Digite a taxa de juros: "); scanf("%d", &b);
            printf("Digite a tempo: "); scanf("%d", &c);
            system("cls");            
            progJurosSimples(memoria, a, b, c);
            printf("JUROS SIMPLES DO CAPITAL %d, COM UMA TAXA DE %d%c AO MES, EM UM PERIODO DE %d MESES = R$%d,00\n", a, b, 37, c ,memoria->RAM[1]);
            printf("MONTANTE = R$%d,00\n\n", (a + memoria->RAM[1]));
            system("pause");
            system("cls");
            break;
        case 12:
            system("cls");
            printf("Digite o raio da esfera: "); scanf("%d", &a);
            system("cls");            
            progVolumeDaEsfera(memoria, a);
            printf("O VOLUME DA ESFERA DE RAIO %d = %dm^3\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 13:
            system("cls");
            printf("Digite o raio da esfera: "); scanf("%d", &a);
            system("cls");            
            progAreaDaEsfera(memoria, a);
            printf("A AREA DA ESFERA DE RAIO %d = %d\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 14:
            system("cls");
            printf("Digite o raio do cilindro: "); scanf("%d", &a);
            printf("Digite a altura do cilindro: "); scanf("%d", &b);
            system("cls");            
            progVolumeDoCilindro(memoria, a, b);
            printf("O VOLUME DO CILINDRO DE RAIO %d E ALTURA %d = %dm^3\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 15:
            system("cls");
            printf("Digite o raio do cilindro: "); scanf("%d", &a);
            printf("Digite a altura do cilindro: "); scanf("%d", &b);
            system("cls");            
            progAreaDoCilindro(memoria, a, b);
            printf("A AREA DO CILINDRO DE RAIO %d E ALTURA %d = %d\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;   
        case 16:
            system("cls");
            printf("Digite o raio da base do Cone: "); scanf("%d", &a);
            printf("Digite a altura do cone: "); scanf("%d", &b);
            system("cls");            
            progVolumeDoCone(memoria, a, b);
            printf("O VOLUME DO CONE DE RAIO DA BASE %d E ALTURA %d = %dm^3\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 17:
            system("cls");
            printf("Digite a area da base do prisma: "); scanf("%d", &a);
            printf("Digite a altura do prisma: "); scanf("%d", &b);
            system("cls");            
            progVolumeDoPrisma(memoria, a, b);
            printf("O VOLUME DO PRISMA DE AREA DA BASE %d E ALTURA %d = %dm^3\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 18:
            system("cls");
            printf("Digite a area da base da piramide: "); scanf("%d", &a);
            printf("Digite a altura da piramide: "); scanf("%d", &b);
            system("cls");            
            progVolumeDaPiramide(memoria, a, b);
            printf("O VOLUME DA PIRAMIDE DE AREA DA BASE %d E ALTURA %d = %dm^3\n\n", a, b, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 19: 
            system("cls");
            printf("Digite a quantidade de horas: "); scanf("%d", &a);
            system("cls");            
            progHorasParaMinutos(memoria, a);
            printf("%d HORAS E EQUIVALENTE A %d MINUTOS\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 20: 
            system("cls");
            printf("Digite a quantidade de horas: "); scanf("%d", &a);
            system("cls");            
            progHorasParaSegundos(memoria, a);
            printf("%d HORAS E EQUIVALENTE A %d SEGUNDOS\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 21: 
            system("cls");
            printf("Digite a quantidade de horas: "); scanf("%d", &a);
            system("cls");            
            progMinutosParaSegundos(memoria, a);
            printf("%d MINUTOS E EQUIVALENTE A %d SEGUNDOS\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 22: 
            system("cls");
            printf("Digite a temperatura em Celsius: "); scanf("%d", &a);
            system("cls");            
            progCelsiusParaFahrenheit(memoria, a);
            printf("%d CELSIUS E EQUIVALENTE A %d FAHRENHEIT\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 23: 
            system("cls");
            printf("Digite a temperatura em Celsius: "); scanf("%d", &a);
            system("cls");            
            progCelsiusParaKelvin(memoria, a);
            printf("%d CELSIUS E EQUIVALENTE A %d KELVIN\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        case 24: 
            system("cls");
            printf("Digite quantos litros deseja converter: "); scanf("%d", &a);
            system("cls");            
            progLitrosParaMl(memoria, a);
            printf("%d LITROS E EQUIVALENTE A %d ML\n\n", a, memoria->RAM[1]);
            system("pause");
            system("cls");
            break;
        case 25: 
            system("cls");
            printf("Digite a Velocidade Inicial: "); scanf("%d", &b);
            printf("Digite a Velocidade Final: "); scanf("%d", &a);
            printf("Digite a Tempo Inicial: "); scanf("%d", &d);
            printf("Digite a Tempo Final: "); scanf("%d", &c);
            system("cls");            
            progVelocidadeMedia(memoria, a, b, c, d);
            printf("A VELOCIDADE MEDIA = %dm/s\n\n", memoria->RAM[1]);
            system("pause");
            system("cls");
            break; 
        }
    }while(opcao != 0);
}

void progSoma(Dados *memoria, int parcela1, int parcela2){

    memoria->Instrucoes[0][0] = SALVAR_MEMORIA;
    memoria->Instrucoes[0][1] = parcela1;
    memoria->Instrucoes[0][2] = 0; // posicao da RAM que vai salvar o parcela1
    memoria->Instrucoes[0][3] = SAIR;
    
    memoria->Instrucoes[1][0] = SALVAR_MEMORIA;
    memoria->Instrucoes[1][1] = parcela2;
    memoria->Instrucoes[1][2] = 1; // posicao da RAM que vai salvar o parcela2
    memoria->Instrucoes[1][3] = SAIR;
    
    memoria->Instrucoes[2][0] = SOMAR;
    memoria->Instrucoes[2][1] = 0; // posicao do parcela1
    memoria->Instrucoes[2][2] = 1; // posicao do parcela2
    memoria->Instrucoes[2][3] = 1; // posicao que vai salvar a soma

    
    memoria->Instrucoes[3][0] = SAIR;
    memoria->Instrucoes[3][1] = SAIR;
    memoria->Instrucoes[3][2] = SAIR;
    memoria->Instrucoes[3][3] = SAIR;

    maquina(memoria);

}

void progSubtracao(Dados *memoria, int minuendo, int subtraendo){
    
    memoria->Instrucoes[0][0] = SALVAR_MEMORIA;
    memoria->Instrucoes[0][1] = minuendo;
    memoria->Instrucoes[0][2] = 0; // posicao da RAM que vai salvar o minuendo
    memoria->Instrucoes[0][3] = SAIR;

    memoria->Instrucoes[1][0] = SALVAR_MEMORIA;
    memoria->Instrucoes[1][1] = subtraendo;
    memoria->Instrucoes[1][2] = 1; // posicao da RAM que vai salvar o subtraendo
    memoria->Instrucoes[1][3] = SAIR;

    memoria->Instrucoes[2][0] = SUBTRAIR;
    memoria->Instrucoes[2][1] = 0; // posicao do number1
    memoria->Instrucoes[2][2] = 1; // posicao do number2
    memoria->Instrucoes[2][3] = 1; // posicao que vai salvar o resultado

    memoria->Instrucoes[3][0] = SAIR;
    memoria->Instrucoes[3][1] = SAIR;
    memoria->Instrucoes[3][2] = SAIR;
    memoria->Instrucoes[3][3] = SAIR;

    maquina(memoria);
}

void progMultiplicacao(Dados *memoria, int multiplicando, int multiplicador){
    
    memoria->Instrucoes[0][0] = SALVAR_MEMORIA;
    memoria->Instrucoes[0][1] = multiplicando;
    memoria->Instrucoes[0][2] = 0; // posicao da RAM que vai salvar o multiplicando
    memoria->Instrucoes[0][3] = SAIR;

    memoria->Instrucoes[1][0] = SALVAR_MEMORIA;
    memoria->Instrucoes[1][1] = 0;
    memoria->Instrucoes[1][2] = 1; // posicao da RAM que vai salvar o multiplicando
    memoria->Instrucoes[1][3] = SAIR;

    for(int i = 0; i < multiplicador; i++){
        memoria->Instrucoes[i+2][0] = SOMAR;
        memoria->Instrucoes[i+2][1] = 0; // posicao do multiplicando
        memoria->Instrucoes[i+2][2] = 1; // posicao do multiplicador
        memoria->Instrucoes[i+2][3] = 1; // posicao que vai ficar salvando a multiplicacao
    }
   
    memoria->Instrucoes[multiplicador+2][0] = SAIR;
    memoria->Instrucoes[multiplicador+2][1] = SAIR;
    memoria->Instrucoes[multiplicador+2][2] = SAIR;
    memoria->Instrucoes[multiplicador+2][3] = SAIR;

    maquina(memoria);
}

void progDivisao(Dados *memoria, int dividendo, int divisor){
    
    int cont = 0; // cont armazena o resultado da divisao

    memoria->Instrucoes[0][0] = SALVAR_MEMORIA;   
    memoria->Instrucoes[0][1] = dividendo;
    memoria->Instrucoes[0][2] = 0;
    memoria->Instrucoes[0][3] = SAIR;

    memoria->Instrucoes[1][0] = SALVAR_MEMORIA;  
    memoria->Instrucoes[1][1] = divisor;
    memoria->Instrucoes[1][2] = 1;
    memoria->Instrucoes[1][3] = SAIR;

    memoria->Instrucoes[2][0] = SAIR;   
    memoria->Instrucoes[2][1] = SAIR;
    memoria->Instrucoes[2][2] = SAIR;
    memoria->Instrucoes[2][3] = SAIR;

    maquina(memoria);

    while (memoria->RAM[0] >= memoria->RAM[1]){

        memoria->Instrucoes[0][0] = SUBTRAIR;
        memoria->Instrucoes[0][1] = 0; // posicao do dividendo
        memoria->Instrucoes[0][2] = 1; // posicao do divisor
        memoria->Instrucoes[0][3] = 0; // posicao que vai salvar o cont = resultado da divisao


        memoria->Instrucoes[1][0] = SAIR;  
        memoria->Instrucoes[1][1] = SAIR;
        memoria->Instrucoes[1][2] = SAIR;
        memoria->Instrucoes[1][3] = SAIR;

        maquina(memoria);

        cont++;
    }

        memoria->Instrucoes[0][0] = SALVAR_MEMORIA;
        memoria->Instrucoes[0][1] = cont; // posicao do dividendo
        memoria->Instrucoes[0][2] = 1; // posicao do divisor
        memoria->Instrucoes[0][3] = -1; 

        memoria->Instrucoes[1][0] = SAIR;  
        memoria->Instrucoes[1][1] = SAIR;
        memoria->Instrucoes[1][2] = SAIR;
        memoria->Instrucoes[1][3] = SAIR;

        maquina(memoria);
        
}

void progPotencia(Dados *memoria, int base, int expoente){
    int aux = base;
    for(int i = 0; i < expoente-1; i++){
        progMultiplicacao(memoria, aux, base);
        aux = memoria->RAM[1];
    }
    
    memoria->RAM[1] = aux;
}

void progAreaDoTriangulo(Dados *memoria, int base, int altura){
    // A = b.h/2
    progMultiplicacao(memoria, base, altura);
    progDivisao(memoria, memoria->RAM[1], 2);
}

void progAreaDoRetangulo(Dados *memoria, int base, int altura){
    // A = b.h
    progMultiplicacao(memoria, base, altura);
}

void progAreaDoLosango(Dados *memoria, int diametroMaior, int diametroMenor){
    // A = D.d/2
    progMultiplicacao(memoria, diametroMaior, diametroMenor);
    progDivisao(memoria, memoria->RAM[1], 2);
}

void progAreaDoTrapezio(Dados *memoria, int baseMaior, int baseMenor, int altura){
    // A = (B+b).h/2
    progSoma(memoria, baseMaior, baseMenor);
    progMultiplicacao(memoria, memoria->RAM[1], altura);
    progDivisao(memoria, memoria->RAM[1], 2);
}

void progAreaDoCirculo(Dados *memoria, int raio){
    // A = π.R²
    progPotencia(memoria, raio, 2);
    progMultiplicacao(memoria, PI, memoria->RAM[1]);
}

void progJurosSimples(Dados *memoria, int capital, int taxaJuros, int tempo){
    // J = C.i.t
    progMultiplicacao(memoria, capital, tempo);
    progMultiplicacao(memoria, memoria->RAM[1], taxaJuros);
    progDivisao(memoria, memoria->RAM[1], 100); 
}

void progVolumeDaEsfera(Dados *memoria, int raio){
    // V = 4.πR³/3
    progPotencia(memoria, raio, 3);
    progMultiplicacao(memoria, memoria->RAM[1], 4);
    progMultiplicacao(memoria, memoria->RAM[1], PI);
    progDivisao(memoria, memoria->RAM[1], 3);
}

void progAreaDaEsfera(Dados *memoria, int raio){
    // A = 4.π.R²
    progPotencia(memoria, raio, 2);
    progMultiplicacao(memoria, memoria->RAM[1], 4);
    progMultiplicacao(memoria, memoria->RAM[1], PI);
}

void progVolumeDoCilindro(Dados *memoria, int raio, int altura){
    // V = π.R².h
    progPotencia(memoria, raio, 2);
    progMultiplicacao(memoria, memoria->RAM[1], altura);
    progMultiplicacao(memoria, memoria->RAM[1], PI);
}

void progAreaDoCilindro(Dados *memoria, int raio, int altura){
    int aux, aux2;

    // A = 2.π.R.h + 2.π.R²
    
    // primeira parcela da soma 
     progPotencia(memoria, raio, 2);
     progMultiplicacao(memoria, memoria->RAM[1], 2);
     progMultiplicacao(memoria, memoria->RAM[1], PI);
     aux = memoria->RAM[1];

    // Segunda parcela da soma
     progMultiplicacao(memoria, raio, altura);
     progMultiplicacao(memoria, memoria->RAM[1], PI);
     progMultiplicacao(memoria, memoria->RAM[1], 2);
     aux2 = memoria->RAM[1];

    // Area
     progSoma(memoria, aux, aux2);     
}

void progVolumeDoCone(Dados *memoria, int raio, int altura){
    // V = π.R².h / 3
    progPotencia(memoria, raio, 2);
    progMultiplicacao(memoria, memoria->RAM[1], altura);
    progMultiplicacao(memoria, memoria->RAM[1], PI);
    progDivisao(memoria, memoria->RAM[1], 3);
}

void progVolumeDoPrisma(Dados *memoria, int areaBase, int altura){
    // V = Ab.H
    progMultiplicacao(memoria, areaBase, altura);
}

void progVolumeDaPiramide(Dados *memoria, int areaBase, int altura){
    // V = Ab.H / 3
    progMultiplicacao(memoria, areaBase, altura);
    progDivisao(memoria, memoria->RAM[1], 3);
}

void progHorasParaMinutos(Dados *memoria, int horas){
    progMultiplicacao(memoria, horas, 60);
}

void progHorasParaSegundos(Dados *memoria, int horas){
    progMultiplicacao(memoria, horas, 60);
    progMultiplicacao(memoria, memoria->RAM[1], 60);
}

void progMinutosParaSegundos(Dados *memoria, int minutos){
    progMultiplicacao(memoria, minutos, 60);
    
}

void progCelsiusParaFahrenheit(Dados *memoria, int celsius){
    progMultiplicacao(memoria, celsius, 2);
    progSoma(memoria, memoria->RAM[1], 32);
}

void progCelsiusParaKelvin(Dados *memoria, int celsius){
    progSoma(memoria, celsius, 273);
}

void progLitrosParaMl(Dados *memoria, int litros){
    progMultiplicacao(memoria, litros, 1000);
}

void progVelocidadeMedia(Dados* memoria, int distanciaFinal, int distanciaInicial, int tempoFinal, int tempoInicial){
    
    int aux;
    int aux2;

    progSubtracao(memoria, distanciaFinal, distanciaInicial);
    aux = memoria->RAM[1];

    progSubtracao(memoria, tempoFinal, tempoInicial);
    aux2 = memoria->RAM[1];

    progDivisao(memoria, aux, aux2);
}

void liberaMemoria(Dados *memoria){
    free(memoria);
}
