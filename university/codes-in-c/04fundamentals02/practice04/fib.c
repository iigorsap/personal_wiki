#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

long int fibonacci(int n, TADfib *f){
    if(n == 0){ 
        f->chamadas++;
        return (f->resultado += 0);
    }else if(n == 1){
        f->chamadas++;
        return (f->resultado += 1);
    }else{
        f->chamadas++;
        return fibonacci(n-1, f) + fibonacci(n-2, f);
    }
}
