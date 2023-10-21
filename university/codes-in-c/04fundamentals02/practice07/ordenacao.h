# ifndef ordenacao_h
# define ordenacao_h

    void ordenacao(int *vetor, int esquerdo, int direito, int *movimentos);
        
    void mergeSort_intercala(int *vetor, int esquerdo, int meio, int direito, int *movimentos);
    //Manter como especificado
    int *alocaVetor(int *vetor, int n);
    //Manter como especificado
    int *desalocaVetor(int *vetor);

    
# endif
