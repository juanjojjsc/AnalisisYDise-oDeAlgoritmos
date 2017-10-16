//
//  main.cpp
//  Problema Practico 2
//
//  Created by JJ Santos on 10/15/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/floyd_warshall_shortest.hpp>
#include <boost/graph/exterior_property.hpp>


using namespace boost;
using namespace std;
typedef double t_weight;
typedef boost::property<boost::edge_weight_t, t_weight> EdgeWeightProperty;
typedef adjacency_list < vecS, vecS, directedS,
property<vertex_distance_t, int>,EdgeWeightProperty> Graph;
typedef graph_traits < Graph >::edge_descriptor edge_descriptor;
typedef graph_traits < Graph >::vertex_descriptor vertex_descriptor;
typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;
typedef boost::exterior_vertex_property<Graph, t_weight> DistanceProperty;
typedef DistanceProperty::matrix_type DistanceMatrix;
typedef DistanceProperty::matrix_map_type DistanceMatrixMap;
class visitadoD;
class visitadoB;
void prim(Graph grafo);
void kruskal(Graph grafo);
void dijkstra(Graph grafo);
void dfs(Graph grafo);
void bfs(Graph grafo);
void floyd(Graph grafo);
bool empty(Graph grafo);


int main() {
    int menu = 0;
    int num,ver1,ver2,peso;
    Graph grafo;
    while(menu != 11){
        cout << "1) Insertar vértices en el grafo"<< endl;
        cout << "2) Insertar arista en el grafo"<< endl;
        cout << "3) Eliminar vértices del grafo" << endl;
        cout << "4) Eliminar aristas del grafo" << endl;
        cout << "5) Realizar un recorrido en profundidad (DFS)" << endl;
        cout << "6) Realizar un recorrido en amplitud (BFS)" << endl;
        cout << "7) Obtener arbol con Prim" << endl;
        cout << "8) Obtener arbol con Kruskal" << endl;
        cout << "9) Obtener ruta minima con Dijkstra" << endl;
        cout << "10) Obtener ruta minima con Floyd-Warshall" << endl;
        cout << "11) Salir" << endl;
        cin >> menu;
        switch (menu) {
            case 1:
                cout << "Numero de vertice: ";
                cin >> num;
                add_vertex(num,grafo);
                break;
            case 2:
                cout << "De vertice: ";
                cin >> ver1;
                cout << "A vertice: ";
                cin >> ver2;
                cout << "Peso: ";
                cin >> peso;
                add_edge(ver1,ver2,peso,grafo);
                break;
            case 3:
                cout << "Numero de vertice: ";
                cin >> num;
                remove_vertex(num, grafo);
                break;
            case 4:
                cout << "De vertice: ";
                cin >> ver1;
                cout << "A vertice: ";
                cin >> ver2;
                cout << "Peso: ";
                cin >> peso;
                remove_edge(ver1, ver2, grafo);
                break;
            case 5:
                if(!empty(grafo))
                    dfs(grafo);
                break;
            case 6:
                if(!empty(grafo))
                    bfs(grafo);
                break;
            case 7:
                if(!empty(grafo))
                    prim(grafo);
                break;
            case 8:
                if(!empty(grafo))
                    kruskal(grafo);
                break;
            case 9:
                if(!empty(grafo))
                    dijkstra(grafo);
                break;
            case 10:
                if(!empty(grafo))
                    floyd(grafo);
                break;
            case 11:
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }
    return 0;
}

class visitadoD : public boost::default_dfs_visitor {
public:
    void discover_vertex(vertex_descriptor v, const Graph& g) const
    {
        cout << v+1 << endl;
        return;
    }
};

class visitadoB : public boost::default_bfs_visitor {
public:
    void discover_vertex(vertex_descriptor v, const Graph& g) const
    {
        cout << v+1 << endl;
        return;
    }
};

void prim(Graph grafo){
    vector < graph_traits < Graph >::vertex_descriptor > p(num_vertices(grafo));
    prim_minimum_spanning_tree(grafo, &p[0]);
    for (std::size_t i = 0; i != p.size(); ++i)
        if (p[i] != i)
            std::cout << "Padre[" << i+1 << "] = " << p[i]+1 << std::endl;
        else
            std::cout << "Padre[" << i+1 << "] = NULL" << std::endl;
}
void kruskal(Graph grafo){
    property_map < Graph, edge_weight_t >::type weight = get(edge_weight, grafo);
    vector < edge_descriptor > spanning_tree;
    kruskal_minimum_spanning_tree (grafo, back_inserter(spanning_tree));
    cout << endl << "Kruskal:" << endl;
    for (std::vector < edge_descriptor >::iterator ei = spanning_tree.begin();ei != spanning_tree.end(); ++ei) {
        cout << source(*ei, grafo)+1 << " <--> " << target(*ei, grafo)+1
        << " con peso de " << weight[*ei]
        << endl;
    }
    
}

void dijkstra(Graph grafo){
    vector<vertex_descriptor> predecesores(num_vertices(grafo));
    vector<int> distancias(num_vertices(grafo));
    vertex_descriptor s = vertex(0, grafo);
    dijkstra_shortest_paths(grafo, s, predecessor_map(&predecesores[0]).distance_map(&distancias[0]));
    cout<< endl << "Dijkstra" <<endl;
    graph_traits < Graph >::vertex_iterator vi, vend;
    for (tie(vi, vend) = vertices(grafo); vi != vend; ++vi) {
        cout << "Vértice: " << *vi +1 << "\nDistancia: " << distancias[*vi] << ", Predecesor: " << predecesores[*vi]+1 << endl;
        cout << endl;
    }
}

void dfs(Graph grafo){
    visitadoD vis;
    depth_first_search(grafo, visitor(vis));
}

void bfs(Graph grafo){
    cout <<endl <<  "BFS" << endl;
    visitadoB visB;
    breadth_first_search(grafo, vertex(0,grafo), visitor(visB));
}

void floyd(Graph grafo){
    WeightMap weight_pmap = boost::get(boost::edge_weight, grafo);
    DistanceMatrix distances(num_vertices(grafo));
    DistanceMatrixMap dm(distances, grafo);
    floyd_warshall_all_pairs_shortest_paths(grafo, dm,weight_map(weight_pmap));
    cout <<endl<< "Distance matrix: " << endl;
    for (size_t i = 0; i < num_vertices(grafo); ++i) {
        for (size_t j = i; j < num_vertices(grafo); ++j) {
            cout << "From vertex " << i+1 << " to " << j+1 << " : ";
            if(distances[i][j] == numeric_limits<t_weight>::max())
                cout << "inf" << endl;
            else
                cout << distances[i][j] << endl;
        }
        cout << endl;
    }
}

bool empty(Graph grafo){
    if(num_vertices(grafo) == 0)
        return true;
    else
        return false;
}



void timing(){
    Graph grafo;
    add_edge(0,3,8,grafo);
    add_edge(0,2,8,grafo);
    add_edge(1,4,7,grafo);
    add_edge(2,1,7,grafo);
    add_edge(2,9,4,grafo);
    add_edge(2,4,8,grafo);
    add_edge(3,6,3,grafo);
    add_edge(3,7,2,grafo);
    add_edge(3,4,1,grafo);
    add_edge(4,5,9,grafo);
    add_edge(5,12,4,grafo);
    add_edge(6,3,6,grafo);
    add_edge(7,6,3,grafo);
    add_edge(7,8,3,grafo);
    add_edge(8,9,2,grafo);
    add_edge(8,11,4,grafo);
    add_edge(9,5,6,grafo);
    add_edge(9,2,10,grafo);
    add_edge(10,11,6,grafo);
    add_edge(11,8,2,grafo);
    add_edge(11,10,8,grafo);
    add_edge(11,13,9,grafo);
    add_edge(12,13,6,grafo);
    add_edge(13,12,2,grafo);
    
    vector < graph_traits < Graph >::vertex_descriptor > p(num_vertices(grafo));
    auto begin = std::chrono::high_resolution_clock::now();
    prim_minimum_spanning_tree(grafo, &p[0]);
    auto end = std::chrono::high_resolution_clock::now();
    auto prim = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    
    
    //Kruskal
    property_map < Graph, edge_weight_t >::type weight = get(edge_weight, grafo);
    vector < edge_descriptor > spanning_tree;
    begin = std::chrono::high_resolution_clock::now();
    kruskal_minimum_spanning_tree (grafo, back_inserter(spanning_tree));
    end = std::chrono::high_resolution_clock::now();
    auto kruskal = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    
    
    //Dijkstra
    vector<vertex_descriptor> predecesores(num_vertices(grafo));
    vector<int> distancias(num_vertices(grafo));
    vertex_descriptor s = vertex(0, grafo);
    begin = std::chrono::high_resolution_clock::now();
    dijkstra_shortest_paths(grafo, s, predecessor_map(&predecesores[0]).distance_map(&distancias[0]));
    end = std::chrono::high_resolution_clock::now();
    auto dijkstra = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    
    
    //DFS
    cout << "DFS" << endl;
    visitadoD vis;
    begin = std::chrono::high_resolution_clock::now();
    depth_first_search(grafo, visitor(vis));
    end = std::chrono::high_resolution_clock::now();
    auto dfs = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    
    
    //BFS
    cout <<endl <<  "BFS" << endl;
    visitadoB visB;
    begin = std::chrono::high_resolution_clock::now();
    breadth_first_search(grafo, vertex(0,grafo), visitor(visB));
    end = std::chrono::high_resolution_clock::now();
    auto bfs = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    
    
    //Floyd Warshall
    WeightMap weight_pmap = boost::get(boost::edge_weight, grafo);
    DistanceMatrix distances(num_vertices(grafo));
    DistanceMatrixMap dm(distances, grafo);
    begin = std::chrono::high_resolution_clock::now();
    floyd_warshall_all_pairs_shortest_paths(grafo, dm,weight_map(weight_pmap));
    end = std::chrono::high_resolution_clock::now();
    auto floyd = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    
    cout << "Timings: " << endl;
    cout << "Prim: " << prim.count() << " us" << endl;
    cout << "Kruskal: " << kruskal.count() << " us" << endl;
    cout<<"Dijkstra: " << dijkstra.count() << " us" << endl;
    cout << "DFS: " << dfs.count() << " us" << endl;
    cout << "BFS: " << bfs.count() << " us" << endl;
    cout << "Floyd Warshall: " << floyd.count() << " us" << endl;
    
}
