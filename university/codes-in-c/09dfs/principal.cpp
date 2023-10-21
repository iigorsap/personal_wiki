#include "DFS.h"

using namespace std;

int main() {
    Grafo grafo = Grafo();
    
    grafo.inicializa_grafo();
    
    vector<int> ordem_busca;

    grafo.DFS(grafo.vertice_inicial, &ordem_busca);
    
    print_busca(ordem_busca);   
    
    return 0;
}