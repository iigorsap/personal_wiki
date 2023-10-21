//inclusão de todas as funções, defines e declaração de struct
#include "funcoes.h"

int main(int argc, char **argv){

    CriaJogo jogo;
    Menu menuDeInicio;
    Menu menuDeComandos;

    //menu inicial para perguntar inciar o jogo
    menuInicial(&menuDeInicio, argc);

    // else e if para determinar se o jogo é passado por parametro ou é um jogo aleatório.
    // também verifica a quantidade de argumentos passados para execução do jogo, caso for = 3 quer dizer que tem um jogo em andamento salvo
    // caso for 1 começa um jogo normal, aleatorrio
    // caso for 2 inicia o jogo passado por paramentro
    if((menuInicial(&menuDeInicio, argc) == 0 || menuInicial(&menuDeInicio, argc) == 3)  && (argc == 2 || argc ==3)){
        limpaTela();
        //função que gera o jogo passado por parametro
        campoMinadoPorParametro(argv, &jogo, &menuDeComandos, &menuDeInicio, argc);
    }else if(menuInicial(&menuDeInicio, argc) == 0 && argc == 1){
        limpaTela();
        // função que gera o jogo aleatorio
        campoMinadoAleatorio(&jogo, &menuDeComandos, &menuDeInicio);
    }

    return 0;
}

int menuInicial(Menu *menuDeInicio, int argc){

    //loop para o usuario definir o que pretende fazer, jogar, continuar um jogo salvo, digitar seu nome, e etc
    while(strcmp(menuDeInicio->opcao, "Jogar") != 0 && strcmp(menuDeInicio->opcao, "Sair") != 0 && strcmp(menuDeInicio->opcao, "Continuar") != 0){
        if(argc == 3){
            printf(ANSI_COLOR_GREEN"Bem vindo ao Campo Minado\n"ANSI_RESET);
            printf(ANSI_COLOR_GREEN"\n1 - Jogar\n"ANSI_RESET);
            printf(ANSI_COLOR_GREEN"2 - Continuar\n"ANSI_RESET);
            printf(ANSI_COLOR_GREEN"3 - Sair\n"ANSI_RESET);
        }
        else if(argc == 1 || argc == 2){
            printf(ANSI_COLOR_GREEN"Bem vindo ao Campo Minado\n"ANSI_RESET);
            printf(ANSI_COLOR_GREEN"\n1 - Jogar\n"ANSI_RESET);
            printf(ANSI_COLOR_GREEN"2 - Sair\n"ANSI_RESET);
        }


        printf(ANSI_COLOR_GREEN"\nPara comecar, digite o seu nome: "ANSI_RESET);
        fgets(menuDeInicio->nomeJogador, 50, stdin);
        menuDeInicio->nomeJogador[(strlen(menuDeInicio->nomeJogador)-1)] = '\0';

        printf(ANSI_COLOR_GREEN"Digite uma opcao e tecle ENTER: "ANSI_RESET);
        fgets(menuDeInicio->opcao, 20, stdin);
        menuDeInicio->opcao[(strlen(menuDeInicio->opcao)-1)] = '\0';
        limpaTela();
    }

    // dependendo da opção que o usuario digitar retorna um valor na função main e continua para o proximo menu
    if(strcmp(menuDeInicio->opcao, "Jogar") == 0)
        return 0;
    else if(strcmp(menuDeInicio->opcao, "Sair") == 0)
        return 1;
    else if(strcmp(menuDeInicio->opcao, "Continuar") == 0)
        return 2;
    else
        printf(ANSI_COLOR_GREEN"Comando inválido!\n"ANSI_RESET);
}
void menuComandos(Menu *menuDeComandos, CriaJogo *jogo, Menu *menuDeInicio, int **matriz, int q){
    // Basicamente essa função é o jogo em si, esta função ler os comandos e executa os mesmos
    // função onde sera impresso o campo minado tanto incial quanto atualizado

    int k = 0;
    while(strcmp(menuDeComandos->comando, "sair") != 0 && conlusaoJogo(&jogo->matrizJogo, matriz, q, jogo->m, jogo->n) != 1){

        //layout do jogo e informações
        printf(ANSI_COLOR_GREEN"         !!!!!! BEM VINDO AO CAMPO MINADO %s !!!!!!\n"ANSI_RESET, menuDeInicio->nomeJogador);
        printf("\n");
        printf("\n");
        printf(ANSI_COLOR_GREEN"----COMANDOS---------ARGUMENTO-------------------------------------------------------------------------\n"ANSI_RESET);
        printf(ANSI_COLOR_GREEN"       x                AC        Indica que a celula da linha A e coluna C contem uma mina.\n"ANSI_RESET);
        printf(ANSI_COLOR_GREEN"       o                EC        Revela o valor da celula da linha E e coluna C.\n"ANSI_RESET);
        printf(ANSI_COLOR_GREEN"    resolver                      Resolve o jogo, marcando automaticamente as celulas com o valor certo.\n"ANSI_RESET);
        printf(ANSI_COLOR_GREEN"     salvar         'out.txt'     Salva o jogo tal como esta no momento no arquivo 'out.txt'.\n"ANSI_RESET);
        printf(ANSI_COLOR_GREEN"      sair                        Encerra o programa (sem salvar as ultimas alteracoes).\n"ANSI_RESET);
        printf("\n");

        //imprime o jogo e pede para o usuario digitar um comando
        imprime(jogo->matrizJogo, jogo->m, jogo->n);
        printf(ANSI_COLOR_GREEN"\n\nDigite um comando: "ANSI_RESET);
        fgets(menuDeComandos->comando, 20, stdin);
        menuDeComandos->comando[(strlen(menuDeComandos->comando)-1)] = '\0';

        int i = menuDeComandos->comando[2] - 65;
        int j = menuDeComandos->comando[3] - 65;

        if(menuDeComandos->comando[0] == 'x')
            // função que o usuario ultiliza para indicar que possui uma mina na determinada posição
            apontaMina(&jogo->matrizJogo, matriz, menuDeComandos->comando, jogo->m, jogo->n);
        else if(menuDeComandos->comando[0] == 'o'){
            // Caso o usuario acerte uma mina na primeira jogada, o jogo sorteia as posiçoes das minas novamente, para sempre poder ter pelo menos 1 jogada
            // Essa condição faz com que sempre o usuario consiga jogar o jogo sem problemas
            if(matriz[i][j] == 120){
                if(k != 0){
                    // Caso a jogada em questao nao for a primeira, o usuario e comunicado que acertou a mina, e a celular é revelada

                    //função que revela celula
                    revelaCelula(&jogo->matrizJogo, matriz, menuDeComandos->comando, jogo->m, jogo->n);
                    printf(ANSI_COLOR_RED"VOCE ACERTOU UMA MINA, QUE PENA!!\nTENTE OUTRA VEZ!"ANSI_RESET);
                    break;
                }
                if(k == 0){
                    // Esse if é para sempre a primeira celula que o usuario revelar será diferente de uma mina, sendo assim ele sempre vai poder iniciar o jogo sem problemas!
                    for(int i = 0; i < jogo->m; i++){
                        for(int j = 0; j < jogo->n; j++){
                            matriz[i][j] = 0;
                        }
                    }
                    // reposicionando as minas e imprimindo novamente o novo jogo
                    posicionaMinas(jogo, &matriz, jogo->dificuldade, jogo->m, jogo->n);
                    contagemDeMinas(&matriz, jogo->m, jogo->n);
                    criaArquivoTextoDoJogo(matriz, jogo->m, jogo->n);
                    revelaCelula(&jogo->matrizJogo, matriz, menuDeComandos->comando, jogo->m, jogo->n);
                }
            }
            else if(menuDeComandos->comando[1] != ' ' || (menuDeComandos->comando[2] - 65) < 0 || (menuDeComandos->comando[2] - 65) > jogo->m || (menuDeComandos->comando[3] - 65) < 0 || (menuDeComandos->comando[3] - 65) > jogo->n)
                // Caso o usuario digitar uma posição inválida ele é alertado com essa condição, e nao acontece nada.
                printf(ANSI_COLOR_RED"!!!!!!! VOCE DIGITOU UMA POSICAO INVALIDA, ESSA POSICAO NAO EXISTE NO TABULEIRO, DIGITE UMA POSICAO VALIDA !!!!!!!\n"ANSI_RESET);
            else{
                // Caso o usuario digita um celula com posições validas automaticamente, a celula é revelada, sem problemas
                revelaCelula(&jogo->matrizJogo, matriz, menuDeComandos->comando, jogo->m, jogo->n);
                k++;
            }
        }
        else if(strcmp(menuDeComandos->comando, "resolver") == 0){
            // Esse if contem a função que faz a função de resolver o jogo, e o jogo se encerra.
            resolver(matriz, jogo->m, jogo->n);
            break;
        }
        else if(strcmp(menuDeComandos->comando, "salvar") == 0){
            // Caso o usuario deseja salvar o jogo esta função que ira fazer o comando, e o jogo se encerra.
            salvar(menuDeComandos, jogo->matrizJogo, jogo->m, jogo->n);
            break;
        }
        else if(strcmp(menuDeComandos->comando, "sair") == 0){
            // Caso o usuario deseja para o jogo, ele somente pede para sair, e ira fechar automaticamente.
            liberaMatriz(jogo->campoMinadoA, jogo->n);
            liberaMatriz(jogo->matrizJogo, jogo->n);
            printf(ANSI_COLOR_GREEN"AHH! QUE PENA, ESPERO QUE TENHA SE DIVERTIDO :)"ANSI_RESET);
        }
        else
            // else para se caso o usuario digitar um comando invalido, seja comunicado
            printf(ANSI_COLOR_RED"!!!!!!! VOCE DIGITOU UM COMANDO INVALIDO, POR FAVOR, DIGITE UM COMANDO NOVAMENTE !!!!!!!\n\n"ANSI_RESET);
    }
    if(conlusaoJogo(&jogo->matrizJogo, matriz, q, jogo->m, jogo->n) == 1){
        //Após concluir o jogo saimos do loop, e aparece uma mensagem de sucesso para o vencedor!
        revelaCelula(&jogo->matrizJogo, matriz, menuDeComandos->comando, jogo->m, jogo->n);
        printf(ANSI_BG_COLOR_YELLOW"PARABENSSS!!!!\nVOCE CONSEGUIU CONCLUIU O DESAFIO!!!"ANSI_RESET);
    }
}
void campoMinadoPorParametro(char **argv, CriaJogo *jogo, Menu *menuDeComandos, Menu *menuDeInicio, int argc){

    // Esta função gera o jogo passado por parametro
    FILE *entrada = fopen(argv[1], "r");

    //lendo as dimensoes do campo minado no arquivo texto
    fscanf(entrada, "%d %d", &jogo->m, &jogo->n);

    // alocando as matrizes necessarias para o jogo
    alocaMatriz(&jogo->campoMinado, jogo->m, jogo->n);
    alocaMatriz(&jogo->matrizJogo, jogo->m, jogo->n);

    // Lendo o campo minado no arquivo texto
    for(int i = 0; i < jogo->m; i++){
        for(int j = 0; j < jogo->n; j++){
            fscanf(entrada, "%c", &jogo->campoMinado[i][j]);
            if(jogo->campoMinado[i][j] == 'x')
                jogo->campoMinado[i][j] = 120;
            else if(jogo->campoMinado[i][j] == 10)
                j--;
            else if (jogo->campoMinado[i][j] == 32)
                j--;
            }
        }

    // Inicializando a matriz com jogo sem nenhuma alteracoes, caso nao tenha passado nenhum jogo salvo por parametro
    if(argc == 2){
        for(int i = 0; i < jogo->m; i++){
            for(int j = 0; j < jogo->n; j++){
                jogo->matrizJogo[i][j] = 45;
            }
        }
    }
    // lendo o jogo salvo passado por parametro caso o usuario deseja continuar o jogo que estava jogando antes
    else if(argc == 3){
        FILE *arq = fopen(argv[2], "r");

        fscanf(arq, "%d %d", &jogo->m, &jogo->n);

        for(int i = 0; i < jogo->m; i++){
            for(int j = 0; j < jogo->n; j++){
                fscanf(arq, "%c", &jogo->matrizJogo[i][j]);
                if(jogo->matrizJogo[i][j] == 'x')
                    jogo->matrizJogo[i][j] = 120;
                else if(jogo->matrizJogo[i][j] == 'o'){
                    jogo->matrizJogo[i][j] = jogo->campoMinado[i][j];
                }
                else if(jogo->matrizJogo[i][j] == '-'){
                    jogo->matrizJogo[i][j] = 45;
                }
                else if(jogo->matrizJogo[i][j] == 10)
                    j--;
                else if (jogo->matrizJogo[i][j] == 32)
                    j--;
            }
        }
        fclose(arq);
    }

    //fgets para resolver '\n'
    fgets(menuDeComandos->comando, 20, stdin);

    // Chamamos o menu de comandos para começarmos o jogo
    menuComandos(menuDeComandos, jogo, menuDeInicio, jogo->campoMinado, jogo->quantidadeDeMinas);

    // Fechando o arquivo.jogo
    fclose(entrada);

    // Liberando as memorias alocadas
    liberaMatriz(jogo->campoMinado, jogo->n);
    liberaMatriz(jogo->matrizJogo, jogo->n);
}
void campoMinadoAleatorio(CriaJogo *jogo, Menu *menuDeComandos, Menu *menuDeInicio){

    // Esta função gera um jogo aleatorio
    srand(time(NULL));
    // Escolhendo aleatoriamente as dimensoes do tabuleiro
    jogo->m = rand() % 26;
    jogo->n = rand() % 26;
    // Caso o tabuleiro for < 3, demos uma solução para que nao fique um jogo com poucas linhas e colunas
    if(jogo->m < 3)
        jogo->m = 3;
    if(jogo->n < 3)
        jogo->n = 3;

    // Alocando matrizes necessarias para o jogo
    alocaMatriz(&jogo->campoMinadoA, jogo->m, jogo->n);
    alocaMatriz(&jogo->matrizJogo, jogo->m, jogo->n);

    // Escolhendo a dificuldade do jogo, foi feita pela quantidade de minas presentes no jogo, quanto mais dificil mais minas.
    printf(ANSI_COLOR_GREEN"Escolha o nivel de dificuldade.\n\n"ANSI_RESET);
    printf(ANSI_COLOR_GREEN"1 - Facil\n"ANSI_RESET);
    printf(ANSI_COLOR_GREEN"2 - Medio\n"ANSI_RESET);
    printf(ANSI_COLOR_GREEN"3 - Dificil\n"ANSI_RESET);
    printf(ANSI_COLOR_GREEN"\nDigite o numero da opcao desejada: "ANSI_RESET);
    scanf("%d", &jogo->dificuldade);

    //fgets para resolver '\n'
    fgets(menuDeComandos->comando, 20, stdin);

    limpaTela();

    //  posicionando as minas aleatoriamente
    posicionaMinas(jogo, &jogo->campoMinadoA, jogo->dificuldade, jogo->m, jogo->n);
    // Função que realiza a contagem de minas presentes em volta de casa celula do jogo.
    contagemDeMinas(&jogo->campoMinadoA, jogo->m, jogo->n);
    // Criando arquivo.jogo do jogo aleatorio gerado
    criaArquivoTextoDoJogo(jogo->campoMinadoA, jogo->m, jogo->n);

    // Inicializando a matriz como não foi passado por parametro nao tem como continuar algum jogo, sempre sera um jogo iniciado
    for(int i = 0; i < jogo->m; i++){
        for(int j = 0; j < jogo->n; j++){
            jogo->matrizJogo[i][j] = 45;
        }
    }

    // Chamamos o menu de comandos para começarmos o jogo
    menuComandos(menuDeComandos, jogo, menuDeInicio, jogo->campoMinadoA, jogo->quantidadeDeMinas);

    liberaMatriz(jogo->campoMinadoA, jogo->n);
    liberaMatriz(jogo->matrizJogo, jogo->n);
}
void limpaTela(){
  system("clear");
}
void imprime(int **matriz, int m, int n){

    // Função que imprime o jogo sempre que necessario
    printf("\n");

    int k = 0;

    while(k != n){
        for(int j = 0; j < n; j++){
            if(j == 0)
                printf(ANSI_COLOR_BLUE"   "ANSI_RESET);
            printf(ANSI_COLOR_BLUE"%-3c"ANSI_RESET, 65+k);
            k++;
        }
    }

    printf("\n");

    for(int i = 0; i < m; i++){
        printf(ANSI_COLOR_BLUE"%-2c"ANSI_RESET, 65+i);
        for(int j = 0; j < n; j++){
            if(matriz[i][j] == 45)
                printf(BG_WHITE(BLACK(BOLD(" - "))));
            else if(matriz[i][j] == 32)
                j--;
            else if(matriz[i][j] == 120)
                printf(ANSI_BG_COLOR_RED" %c "ANSI_RESET, matriz[i][j]);
            else if(matriz[i][j] == 48)
                printf((ANSI_BG_COLOR_CYAN" 0 "ANSI_RESET));
            else if(matriz[i][j] == 49)
                printf((ANSI_BG_COLOR_CYAN" 1 "ANSI_RESET));
            else if(matriz[i][j] == 50)
                printf((ANSI_BG_COLOR_CYAN" 2 "ANSI_RESET));
            else if(matriz[i][j] == 51)
                printf((ANSI_BG_COLOR_CYAN" 3 "ANSI_RESET));
            else if(matriz[i][j] == 52)
                printf((ANSI_BG_COLOR_CYAN" 4 "ANSI_RESET));
            else if(matriz[i][j] == 53)
                printf((ANSI_BG_COLOR_CYAN" 5 "ANSI_RESET));
            else if(matriz[i][j] == 54)
                printf((ANSI_BG_COLOR_CYAN" 6 "ANSI_RESET));
            else if(matriz[i][j] == 55)
                printf((ANSI_BG_COLOR_CYAN" 7 "ANSI_RESET));
            else if(matriz[i][j] == 56)
                printf((ANSI_BG_COLOR_CYAN" 8 "ANSI_RESET));
            else
                printf(ANSI_BG_COLOR_CYAN" %d "ANSI_RESET, matriz[i][j]);
        }
        printf("\n");
    }
}
void alocaMatriz(int ***matriz, int m, int n){
    // Função que aloca matrizes
    *matriz = malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        (*matriz)[i] = calloc(n, sizeof(int));
    }
}
void liberaMatriz(int **matriz, int n){
    // Função que libera as matrizes
    for(int i = 0; i < n; i++){
        free(matriz[i]);
    }
    free(matriz);
}
void posicionaMinas(CriaJogo *jogo, int ***matriz, int dificuldade, int m, int n){
    // Função que posiciona as minas aleatoriamente
    srand(time(NULL));
    int k = 0;

    if(dificuldade == 1)
          jogo->quantidadeDeMinas = (m * n) * 0.1;
    else if(dificuldade == 2)
          jogo->quantidadeDeMinas = (m * n) * 0.2;
    else if(dificuldade == 3)
          jogo->quantidadeDeMinas = (m * n) * 0.4;

   // Posicionando as minas no tabuleiro do campo minado
    while(k != jogo->quantidadeDeMinas){
        int i = rand() % m;
        int j = rand() % n;
        if((*matriz)[i][j] != 120){
          (*matriz)[i][j] = 120;
            k++;
        }
    }

}
void contagemDeMinas(int ***matriz, int m, int n){

    // Função que conta a quantidade de minas presentes na celulas adjacentes a cada celula.
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0 && (*matriz)[i][j] != 120){
                if((*matriz)[i][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j+1] == 120)
                    (*matriz)[i][j]++;
            }
            if(i == (m - 1) && j == 0 && (*matriz)[i][j] != 120){
                if((*matriz)[i-1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j+1] == 120)
                    (*matriz)[i][j]++;
            }
            if(i == (m - 1) && j == (n -1) && (*matriz)[i][j] != 120){
                if((*matriz)[i-1][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j-1] == 120)
                    (*matriz)[i][j]++;
            }
            if(i == 0 && j == (n - 1) && (*matriz)[i][j] != 120){
                if((*matriz)[i][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j-1] == 120)
                    (*matriz)[i][j]++;
            }
            if(i == 0 && j > 0 && j < (n - 1) && (*matriz)[i][j] != 120){
                if((*matriz)[i+1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j+1] == 120)
                    (*matriz)[i][j]++;
            }
            if(j == 0 && i > 0 && i < (m - 1) && (*matriz)[i][j] != 120){
                if((*matriz)[i-1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j+1] == 120)
                    (*matriz)[i][j]++;
            }
            if(i == (m - 1) && j > 0 && j < (n - 1) && (*matriz)[i][j] != 120){
                if((*matriz)[i-1][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j+1] == 120)
                    (*matriz)[i][j]++;
            }
            if(j == (n - 1) && i > 0 && i < (m - 1) && (*matriz)[i][j] != 120){
                if((*matriz)[i-1][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j] == 120)
                    (*matriz)[i][j]++;
            }
            if(i > 0 && i < (m - 1) && j > 0 && j < (n - 1) && (*matriz)[i][j] != 120){
                if((*matriz)[i-1][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j-1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i-1][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i][j+1] == 120)
                    (*matriz)[i][j]++;
                if((*matriz)[i+1][j+1] == 120)
                    (*matriz)[i][j]++;
            }
        }
    }
}
void criaArquivoTextoDoJogo(int **matriz, int m, int n){

    // Função que cria um arquivo quando o jogo é gerado aleatoriamente.
    FILE *arq = fopen("campoMinado.jogo", "w+");
    fprintf(arq, "%d %d\n\n", m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matriz[i][j] == 120)
                if(j == 0)
                    fprintf(arq, "x ");
                else
                    fprintf(arq, " x ");
            else
                if(j == 0)
                    fprintf(arq, "%d ", matriz[i][j]);
                else
                    fprintf(arq, " %d ", matriz[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
}
void resolver(int **matriz, int m, int n){

    // Função que resolve o jogo, assim como o pedido, ela somente revela o campo minado para o usuario, e encerra o jogo.
    limpaTela();
    printf("          ");
    printf(ANSI_COLOR_GREEN"!!!!!! CAMPO MINADO RESOLVIDO !!!!!!\n"ANSI_RESET);
    imprime(matriz, m, n);
}
void salvar(Menu *menuDeComandos, int **matriz, int m, int n){

    // Função que salva o jogo em andamento.
    limpaTela();
    // A função pergunta qual o nome desejado para salvar a partida em andamento, que pode facilitar na hora de continuar o jogo
    printf(ANSI_COLOR_GREEN"Salvar Como | "ANSI_RESET);
    fgets(menuDeComandos->argumento, 20, stdin);
    menuDeComandos->argumento[(strlen(menuDeComandos->argumento)-1)] = '\0';

    // Escrevendo o campo minado em andamento no arquivo em questão
    FILE *arq = fopen(menuDeComandos->argumento, "w+");
    fprintf(arq, "%d %d\n\n", m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matriz[i][j] == 120){
                if(j == 0)
                    fprintf(arq, "x ");
                else
                    fprintf(arq, " x ");
            }
            else if(matriz[i][j] == 45){
                if(j == 0)
                    fprintf(arq, "- ");
                else
                    fprintf(arq, " - ");
            }
            else
                if(j == 0)
                    fprintf(arq, "o ");
                else
                    fprintf(arq, " o ");
        }
        fprintf(arq, "\n");
    }
    // Fechando o arquivo salvado pois caso nao feche ele nao fica salvo na pasta.
    fclose(arq);

}
void revelaCelula(int ***matrizJogo, int **matriz, char *matrizComando, int m, int n){

    // Função que revela as celulas
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrizComando[2] - 65 == i && matrizComando[3] - 65 == j){
            // Somente revela celula caso a celula for diferente de 0
                (*matrizJogo)[i][j] = matriz[i][j];
                // Caso a celula seja igual a 0, são reveladas suas celulas adjacentes
                if(matriz[i][j] == 0 || matriz[i][j] == 48){
                    if(i == 0 && j == 0){
                        if((*matrizJogo)[i][j+1] != 120)
                            (*matrizJogo)[i][j+1] = matriz[i][j+1];
                        if((*matrizJogo)[i+1][j] != 120)
                            (*matrizJogo)[i+1][j] = matriz[i+1][j];
                        if((*matrizJogo)[i+1][j+1] != 120)
                            (*matrizJogo)[i+1][j+1] = matriz[i+1][j+1];
                    }
                    if(i == (m - 1) && j == 0){
                        if((*matrizJogo)[i-1][j] != 120)
                            (*matrizJogo)[i-1][j]  = matriz[i-1][j];
                        if((*matrizJogo)[i-1][j+1] != 120)
                            (*matrizJogo)[i-1][j+1] = matriz[i-1][j+1];
                        if((*matrizJogo)[i][j+1] != 120)
                            (*matrizJogo)[i][j+1] = matriz[i][j+1];
                    }
                    if(i == (m - 1) && j == (n -1)){
                        if((*matrizJogo)[i-1][j-1] != 120)
                            (*matrizJogo)[i-1][j-1]  = matriz[i-1][j-1];
                        if((*matrizJogo)[i-1][j] != 120)
                            (*matrizJogo)[i-1][j] = matriz[i-1][j];
                        if((*matrizJogo)[i][j-1] != 120)
                            (*matrizJogo)[i][j-1] = matriz[i][j-1];
                    }
                    if(i == 0 && j == (n - 1)){
                        if((*matrizJogo)[i][j-1] != 120)
                            (*matrizJogo)[i][j-1] = matriz[i][j-1];
                        if((*matrizJogo)[i+1][j] != 120)
                            (*matrizJogo)[i+1][j] = matriz[i+1][j];
                        if((*matrizJogo)[i+1][j-1] != 120)
                            (*matrizJogo)[i+1][j-1] = matriz[i+1][j-1];
                    }
                    if(i == 0 && j > 0 && j < (n - 1)){
                        if((*matrizJogo)[i+1][j] != 120)
                            (*matrizJogo)[i+1][j] = matriz[i+1][j];
                        if((*matrizJogo)[i][j-1] != 120)
                            (*matrizJogo)[i][j-1] = matriz[i][j-1];
                        if((*matrizJogo)[i+1][j-1] != 120)
                            (*matrizJogo)[i+1][j-1] = matriz[i+1][j-1];
                        if((*matrizJogo)[i][j+1] != 120)
                            (*matrizJogo)[i][j+1] = matriz[i][j+1];
                        if((*matrizJogo)[i+1][j+1] != 120)
                            (*matrizJogo)[i+1][j+1] = matriz[i+1][j+1];
                    }
                    if(j == 0 && i > 0 && i < (m - 1)){
                        if((*matrizJogo)[i-1][j] != 120)
                            (*matrizJogo)[i-1][j] = matriz[i-1][j];
                        if((*matrizJogo)[i+1][j] != 120)
                            (*matrizJogo)[i+1][j] = matriz[i+1][j];
                        if((*matrizJogo)[i-1][j+1] != 120)
                            (*matrizJogo)[i-1][j+1] = matriz[i-1][j+1];
                        if((*matrizJogo)[i][j+1] != 120)
                            (*matrizJogo)[i][j+1] = matriz[i][j+1];
                        if((*matrizJogo)[i+1][j+1] != 120)
                            (*matrizJogo)[i+1][j+1] = matriz[i+1][j+1];
                    }
                    if(i == (m - 1) && j > 0 && j < (n - 1)){
                        if((*matrizJogo)[i-1][j-1] != 120)
                            (*matrizJogo)[i-1][j-1] = matriz[i-1][j-1];
                        if((*matrizJogo)[i][j-1] != 120)
                            (*matrizJogo)[i][j-1] = matriz[i][j-1];
                        if((*matrizJogo)[i-1][j] != 120)
                            (*matrizJogo)[i-1][j] = matriz[i-1][j];
                        if((*matrizJogo)[i-1][j+1] != 120)
                            (*matrizJogo)[i-1][j+1] = matriz[i-1][j+1];
                        if((*matrizJogo)[i][j+1] != 120)
                            (*matrizJogo)[i][j+1] = matriz[i][j+1];
                    }
                    if(j == (n - 1) && i > 0 && i < (m - 1)){
                        if((*matrizJogo)[i-1][j-1] != 120)
                            (*matrizJogo)[i-1][j-1] = matriz[i-1][j-1];
                        if((*matrizJogo)[i][j-1] != 120)
                            (*matrizJogo)[i][j-1] = matriz[i][j-1];
                        if((*matrizJogo)[i+1][j-1] != 120)
                            (*matrizJogo)[i+1][j-1] = matriz[i+1][j-1];
                        if((*matrizJogo)[i-1][j] != 120)
                            (*matrizJogo)[i-1][j] = matriz[i-1][j];
                        if((*matrizJogo)[i+1][j] != 120)
                            (*matrizJogo)[i+1][j] = matriz[i+1][j];
                    }
                    if(i > 0 && i < (m - 1) && j > 0 && j < (n - 1)){
                        if((*matrizJogo)[i-1][j-1] != 120)
                            (*matrizJogo)[i-1][j-1] = matriz[i-1][j-1];
                        if((*matrizJogo)[i][j-1] != 120)
                            (*matrizJogo)[i][j-1] = matriz[i][j-1];
                        if((*matrizJogo)[i+1][j-1] != 120)
                            (*matrizJogo)[i+1][j-1] = matriz[i+1][j-1];
                        if((*matrizJogo)[i-1][j] != 120)
                            (*matrizJogo)[i-1][j] = matriz[i-1][j];
                        if((*matrizJogo)[i+1][j] != 120)
                            (*matrizJogo)[i+1][j] = matriz[i+1][j];
                        if((*matrizJogo)[i-1][j+1] != 120)
                            (*matrizJogo)[i-1][j+1] = matriz[i-1][j+1];
                        if((*matrizJogo)[i][j+1] != 120)
                            (*matrizJogo)[i][j+1] = matriz[i][j+1];
                        if((*matrizJogo)[i+1][j+1] != 120)
                            (*matrizJogo)[i+1][j+1] = matriz[i+1][j+1];
                    }
                }
            }
        }
    }
}
void apontaMina(int ***matrizJogo, int **matriz, char *matrizComando, int m, int n){

    // Função que faz o usuario indicar que existe uma mina em determinada posição
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrizComando[2] - 65 == i && matrizComando[3] - 65 == j){
                (*matrizJogo)[i][j] = 120;
            }
        }
    }
}
int conlusaoJogo(int ***matrizJogo, int **matriz, int q, int m, int n){

    // Função que define se o jogo foi concluido, caso o jogo tiver todas as celulas que não tiver minas forem reveladas, o usuario concluiu o jogo
    int casasReveladas = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matriz[i][j] != 120 && matriz[i][j] == (*matrizJogo)[i][j])
                casasReveladas++;
        }
    }

    if(casasReveladas == (m*n) - q)
      return 1;
}
