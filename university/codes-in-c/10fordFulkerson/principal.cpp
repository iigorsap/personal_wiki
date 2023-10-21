#include "DFS.h"

using namespace std;

int main() {
    Grafo grafo = Grafo();
    
    grafo.inicializa_grafo();

    // grafo.print_grafo();
    
    // for (int i = 0; i < grafo.quantidade_vertices; i++) {
    //     grafo.vertices[i].print_vertice();
    // }

    // for (int i = 0; i < grafo.quantidade_arestas; i++) {
    //     grafo.arestas[i].print_aresta();
    // }
    
    vector<int> ordem_busca;

    grafo.DFS(grafo.vertice_inicial, &ordem_busca);

    for (int i = 0; i < grafo.quantidade_vertices; i++) {
        grafo.vertices[i].print_vertice();
    }

    // for (int i = 0; i < grafo.quantidade_arestas; i++) {
    //     grafo.arestas[i].print_aresta();
    // }
    
    print_busca(ordem_busca);
    
    return 0;
}