#include "ConnectedComponents.h"
#include <iostream>
using namespace std;

ConnectedComponents::ConnectedComponents(Graph* G) {
    this->G = G;
    this->c = 0;
    marked.resize(G->vertices(), false);
    id.resize(G->vertices());

    for (int v = 0; v < G->vertices(); v++)
        if (!marked[v]) { dfs(*G, v); c++; }
}

void ConnectedComponents::dfs(Graph& G, int v) {
    marked[v] = true;
    id[v] = c;
    for (int w : G.adj[v])
        if (!marked[w]) dfs(G, w);
}

bool ConnectedComponents::connected(int v, int w) { return id[v] == id[w]; }

int ConnectedComponents::count() { return c; }

int ConnectedComponents::getId(int v) { return id[v]; }

int main() {
    string filename = "tinyG.txt";
    Graph G(filename);
    ConnectedComponents cc(&G);
    int M = cc.count();
    cout << M << " components" << endl;
    map<int, vector<int>> components;
    for (int v = 0; v < G.vertices(); v++)
        components[cc.getId(v)].push_back(v);

    for (auto v : components) {
        cout << v.first << ": ";
        for (auto i : v.second)
            cout << i << " ";
        cout << endl;
    }
        
}