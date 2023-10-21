#include "fib.h"
#include<stdio.h>

int main()
{
    //adicionar variaveis conforme necessidade
    
    TADfib f;
    long int chamada = 0;
    long int resultado = 0;
    int n_fib;

    scanf("%d", &f.n);

    for (int i = 0; i < f.n; i++){

        scanf("%d", &n_fib);
        
        // limpando dados da TADfib
        f.chamadas = 0;
        f.resultado = 0;
        
        fibonacci(n_fib, &f);
        printf("fib(%d) = %ld chamadas = %ld\n", n_fib, f.chamadas-1, f.resultado);  
    }
    
    return 0;//nao remova
}
