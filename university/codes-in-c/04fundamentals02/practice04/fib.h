# ifndef fib_h
# define fib_h

  typedef struct{
    int n;
    long int chamadas;
    long int resultado;
  } TADfib;

  long int fibonacci(int n, TADfib *f);

# endif
