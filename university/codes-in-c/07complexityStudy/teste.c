#include "stdio.h"
#include "time.h"


int main(){
    int keys[10000];
    // int position_vector = 0;
    int size = 10000;
    int aux;
    // int escolha_aleatoria = 0;
     int tmp;
    srand(time(NULL));

    for (int i = 0; i < size; i++){
        keys[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        int randm_idx = rand() % size;
        tmp = keys[randm_idx];
        keys[randm_idx] = keys[size - 1];
        size--;
        printf("%d\n", tmp);
    }
    

    // while (position_vector < size - 1) {
    //     escolha_aleatoria = rand() % size;
    //     tmp = keys[position_vector];
    //     keys[position_vector] = keys[escolha_aleatoria];
    //     keys[escolha_aleatoria] = tmp;
    //     position_vector++;
    // }

    for (int i = 0; i < size; i++){
        printf("%d\n", keys[i]);
    }

    return 0;
}

// int escolha = 0,rand_num = N,pos_vetor = 0,tmp;
//     while( pos_vetor < N - 1 )
//     {
//         /** Escolhe uma posicao aleatoria **/
//         escolha = rand() % rand_num;
//         /** Faz a troca pela posicao sequencial **/
//         tmp = vetor[pos_vetor];
//         vetor[pos_vetor] = vetor[escolha];
//         vetor[escolha] = tmp;
//         /** Proxima posicao que sera trocada **/
//         pos_vetor++;
//     }