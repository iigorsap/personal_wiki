#include "DFS.h"

using namespace std;

void print_busca(vector<int> ordem_busca) {
    for (int i = 0; i < static_cast<int>(ordem_busca.size()); i++){
        cout << ordem_busca[i] << "\n";
    }
}

Vertice::Vertice(int id, int visitado) : id(id), visitado(visitado) {}
Vertice::~Vertice() {}

void Vertice::print_vertice() {
    cout << "-----Vertice-----\n";
    cout << "ID      : " << id << "\n";
    cout << "Visitado: " << visitado << "\n\n";
    print_vizinhos();
}

void Vertice::adicionar_vizinho(int id_vizinho){
    ids_vizinhos.push_back(id_vizinho);
}

void Vertice::print_vizinhos(){
    if (ids_vizinhos.size() != 0) {
        for (auto vizinho : ids_vizinhos) {
            cout << "Vizinho: " << vizinho << endl;
        }
        cout << "\n";
    }
}

void Vertice::set_id(int id) {
    this->id = id;
}

int Vertice::get_id() {
    return id;
}

void Vertice::set_visitado(int visitado) {
    this->visitado = visitado;
}

int Vertice::get_visitado() {
    return this->visitado;
}

Aresta::Aresta(int id_aresta, int id_vertice_origem, int id_vertice_destino, int fluxo, int visitado) : 
               id_aresta(id_aresta), id_vertice_origem(id_vertice_origem), id_vertice_destino(id_vertice_destino), 
               fluxo(fluxo), visitado(visitado) {}

Aresta::~Aresta(){}

void Aresta::print_aresta() {
    cout << "-----Aresta-----\n";
    cout << "ID Aresta :" << id_aresta << "\n";
    cout << "ID Origem :" << id_vertice_origem << "\n";
    cout << "ID Destino:" << id_vertice_destino << "\n";
    cout << "Visitado  :" << visitado << "\n\n";
}

void Aresta::set_id_vertice_origem(int id) {
    id_vertice_origem = id;
}

int Aresta::get_id_vertice_origem() {
    return id_vertice_origem;
}

void Aresta::set_id_vertice_destino(int id) {
    id_vertice_destino = id;
}

int Aresta::get_id_vertice_destino() {
    return id_vertice_destino;
}

void Aresta::set_fluxo(int fluxo) {
    this->fluxo = fluxo;
}

int Aresta::get_fluxo() {
    return fluxo;
}

void Aresta::set_visitado(int visitado) {
    this->visitado = visitado;
}

int Aresta::get_visitado() {
    return this->visitado;
}

Grafo::Grafo(int quantidade_vertices, int quantidade_arestas, int vertice_inicial, int direcionado) : 
             quantidade_vertices(quantidade_vertices), quantidade_arestas(quantidade_arestas), vertice_inicial(vertice_inicial), direcionado(direcionado) {}

Grafo::~Grafo() {}

void Grafo::print_grafo(){
    cout << "--------- Grafo ---------\n";
    cout << "Quantiade Vertices: " << quantidade_vertices << "\n";
    cout << "Quantiade Arestas : " << quantidade_arestas << "\n";
    cout << "Direcionado       : " << direcionado << "\n";
    cout << "Vertice inicial   : " << vertice_inicial << "\n";
}

void Grafo::inicializa_grafo(){
    set_quantidade_vertices();
    set_quantidade_arestas();
    set_direcionado();
    set_vertice_inicial();
    inicializando_vertices();
    inicializando_arestas();
}

void Grafo::set_quantidade_vertices() {
    cin >> quantidade_vertices;
}

int Grafo::get_quantidade_vertices() {
    return quantidade_vertices;
}

void Grafo::set_quantidade_arestas() {
    cin >> quantidade_arestas;
}

int Grafo::get_quantidade_arestas() {
    return quantidade_arestas;
}

void Grafo::set_vertice_inicial() {
    vertice_inicial = 1;
}

int Grafo::get_vertice_inicial() {
    return vertice_inicial;
}

void Grafo::set_direcionado() {
    direcionado = 1;
}

int Grafo::get_direcionado() {
    return direcionado;
}

void Grafo::inicializando_vertices() {
    for (int i = 1; i <= quantidade_vertices; i++) {
        Vertice novo_vertice(i, 0);
        vertices.push_back(novo_vertice);
    }
}

void Grafo::inicializando_arestas() {

    int vertice_origem, vertice_destino, fluxo_aresta;

    for (int i = 1; i <= quantidade_arestas; i++) {

        cin >> vertice_origem >> vertice_destino >> fluxo_aresta;

        Aresta nova_aresta(i, vertice_origem, vertice_destino, fluxo_aresta, 0);

        arestas.push_back(nova_aresta);

        vertices[vertice_origem - 1].adicionar_vizinho(vertice_destino);
        
        // if (direcionado == 0) {
        //     vertices[vertice_destino - 1].adicionar_vizinho(vertice_origem);
        // }
        
    }
}

int Grafo::verifica_se_ja_visitou_todos_vizinhos(int vertice) {
    int tam = vertices[vertice].ids_vizinhos.size();
    int i = 0;
    
    for (auto vizinho : vertices[vertice].ids_vizinhos) {
        if (vertices[vizinho - 1].get_visitado() == 1) {
            i++;
        }
    }

    if (i == tam) {
        return 1;
    }

    return 0;
}

void Grafo::DFS(int vertice_inicial, vector<int>* ordem_busca) {
    
    cout << "v ->"<< vertice_inicial << endl;

    ordem_busca->push_back(vertice_inicial);
    vertices[vertice_inicial - 1].set_visitado(1);

    for (auto vizinho : vertices[vertice_inicial - 1].ids_vizinhos)
    {

        if (vertices[vizinho - 1].get_visitado() == 0) {
            aresta_obj(vertice_inicial - 1, vizinho - 1).set_visitado(1);
            DFS(vizinho, ordem_busca);
        }
        else if (vertices[vizinho - 1].get_visitado() == 1) {
            if (aresta_obj(vertice_inicial - 1, vizinho - 1).get_visitado() == 0) {
                aresta_obj(vertice_inicial - 1, vizinho - 1).set_visitado(1);
            }
            
        }
    }
}

Aresta Grafo::aresta_obj(int vertice_origem, int vertice_destino) {
    for (int j = 0; j < quantidade_arestas; j++) {
        if (arestas[j].id_vertice_origem == vertice_origem && 
            arestas[j].id_vertice_destino == vertice_destino)
            return arestas[j];
    }

    return arestas[-1];
}