#ifndef DFS_H 
#define DFS_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Vertice {
    public:
        int id;
        int visitado;        
        vector<int> ids_vizinhos;
        
        Vertice(int id = -1, int visitado = 0);
        
        virtual ~Vertice();

        void print_vertice();
        void adicionar_vizinho(int id_vizinho);
        void print_vizinhos();

        // Gets e Setters

        void set_id(int id);
        int get_id();

        void set_visitado(int visitado);
        int get_visitado();
};

class Aresta {
    public: 
        int id_aresta;
        int id_vertice_origem;
        int id_vertice_destino;
        int fluxo;
        int visitado;

        Aresta(int id, int id_vertice_origem = -1, int id_vertice_destino = -1, int fluxo = -1, int visitado = 0);
        virtual ~Aresta();
        void print_aresta();

        // Gets e Setters
        
        void set_id_vertice_origem(int id);
        int get_id_vertice_origem();

        void set_id_vertice_destino(int id);
        int get_id_vertice_destino();

        void set_fluxo(int fluxo);
        int get_fluxo();

        void set_visitado(int visitado);
        int get_visitado();
};

class Grafo {
    public: 
        int quantidade_vertices;
        int quantidade_arestas;
        int vertice_inicial;
        int direcionado;
        
        vector<Vertice> vertices;
        vector<Aresta> arestas;

        Grafo(int quantidade_vertices = -1, int quantidade_arestas = -1, int vertice_inicial = -1, int direcionado = 0);
        virtual ~Grafo();

        void inicializa_grafo();
        void inicializando_vertices();
        void inicializando_arestas();
        void DFS(int vertice_inicial, vector<int>* ordem_busca);
        Aresta aresta_obj(int vertice_origem, int vertice_destino);
        int verifica_se_ja_visitou_todos_vizinhos(int vertice);
        void print_grafo();


        // Gets e Setters
        void set_quantidade_vertices();
        int get_quantidade_vertices();

        void set_quantidade_arestas();
        int get_quantidade_arestas();

        void set_vertice_inicial();
        int get_vertice_inicial();

        void set_direcionado();
        int get_direcionado();

};


class Rede {
    public:
        int fluxo_maximo;
        Grafo grafo;
        int fonte;
        int semidouro;

        Rede(int fluxo_maximo = -1, int fonte = -1, int semidouro = -1);
        virtual ~Rede();

        


};

void print_busca(vector<int> ordem_busca);

#endif // DFS_H