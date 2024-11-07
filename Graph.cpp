#include "Graph.h"
#include <iostream>
#include <fstream>
#include <stdio.h>  
using namespace std;

Graph::Graph(int v) {
    this->V = v;
    this->E = 0;
 }

Graph::Graph(string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    int V, E;
    inFile >> V >> E;
    this->V = V;
    this->E = E;

    for (int i = 0; i < E; i++) {
        int v, w;
        inFile >> v >> w;
        addEdge(v, w);
    }
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::setV(int v) { this->V = v; }
void Graph::setE(int e) { this->E = e; }
int Graph::vertices() { return V; }
int Graph::edges() { return E; }

void Graph::print()
    {
        cout << "Adjacency list for the Graph: " << endl;
        // Iterate over each vertex
        for (auto i : adj) {
            // Print the vertex
            cout << i.first << ": ";
            // Iterate over the connected vertices
            for (auto j : i.second)
                cout << j << " ";  // Print the connected vertex
            cout << endl;
        }
    }

// int main() {
//     string filename = "tinyCG.txt";
//     Graph graph(filename);

//     cout << "Number of vertices: " << graph.totalV() << endl;
//     cout << "Number of edges: " << graph.totalE() << endl;

//     graph.print();

//     return 0;
// }