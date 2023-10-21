#include <stdio.h>
int main()

/*
    Preencha a sua implementacao aqui
    - declare suas variáveis
    - faca a leitura e some os valores
    - se necessario, calcule a media
    - imprima o resultado no formato correto
*/

{
    double M[12][12];//utilize esta matriz para ler os 144 numeros reais

    double sum = 0;

    int cont = 0;

    char Op;
    
    scanf("%c", &Op);

    for(int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf", &M[i][j]);
        }
        
    }

    //somatorio para linha 0

    for (int j = 1; j < 11; j++)
    {   
        int i = 0;
        sum += M[i][j];
        cont++;
    }
    
    //somatorio para linha 1

    for (int j = 2; j < 10; j++)
    {   
        int i = 1;
        sum += M[i][j];
        cont++;
    }
    
    //somatorio para linha 2

    for (int j = 3; j < 9; j++)
    {   
        int i = 2;
        sum += M[i][j];
        cont++;
    }
    
    //somatorio para linha 3

    for (int j = 4; j < 8; j++)
    {   
        int i = 3;
        sum += M[i][j];
        cont++;
    }
    
    //somatorio para linha 4

    for (int j = 5; j < 7; j++)
    {   
        int i = 4;
        sum += M[i][j];
        cont++;
    }

    if (Op == 'S')
    {
        printf("%.1lf\n", sum);
    }
    else if (Op == 'M')
    {
        printf("%.1lf\n", sum / cont);
    }
    
                     
    return 0;//não remova
}


