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

    degrees.resize(vertices(), 0);
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

bool Graph::hasEdge(int v, int u) {
    for (int s : adj[v]) 
        if (s == u) return true;
    return false;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    degrees[v]++;
    adj[w].push_back(v);
    degrees[w]++;
}

void Graph::setV(int v) { this->V = v; }
void Graph::setE(int e) { this->E = e; }
int Graph::vertices() { return V; }
int Graph::edges() { return E; }

void Graph::print() {
    // Iterate over each vertex
    for (auto i : adj) {
        cout << i.first << ": ";  // Print the vertex
        for (auto j : i.second)  // Iterate over the connected vertices
            cout << j << " ";  // Print the connected vertex
        cout << endl;
    }
}

void Graph::showDegrees() {
    cout << "Vertices degrees" << endl;
    // Iterate over each vertex
    for (int i = 0; i < vertices(); i++)
        cout << i << ": " << degrees[i] << endl;  // Print the vertex and its degree
}

// int main() {
//     string filename = "tiny-euler.txt";
//     Graph graph(filename);

//     cout << graph.vertices() <<  " vertices, ";
//     cout << graph.edges() << " edges" << endl;

//     graph.print();
//     graph.showDegrees();

//     return 0;
// }