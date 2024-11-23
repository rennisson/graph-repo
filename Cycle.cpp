#include "Cycle.h"
#include <iostream>
#include <fstream>
#include <stdio.h>  
using namespace std;

Cycle::Cycle(Graph* G) {
    this->G = G;
    cycle = false;
    marked.resize(G->vertices(), false);
    for (int s = 0; s < G->vertices(); s++)
        if (!marked[s]) dfs(*G, s, s);
}

void Cycle::dfs(Graph& G, int v, int u) {
    marked[v] = true;
    for (int w : G.adj[v])
        if (!marked[w])  dfs(G, w, v);
        // if adjacent vertex is visited and is not parent of current vertex
        // then there is a cycle.
        // Or if adjacent vertex is the same as its parent
        // then there is a self loop
        else if (w != u || w == v) cycle = true;
}

void Cycle::findEulerCycle() {
    // THIS DOES NOT FIND ANY EULER CYCLE
    dfsEulerian(*G, 0, 0);

    for (int i : eulerianCycle)
        cout << i << " ";
    cout << endl;
}

void Cycle::dfsEulerian(Graph& G, int v, int s) {
    eulerianCycle.push_back(v);

    while (!G.adj[v].empty()) {
        int w = G.adj[v].front();
        G.adj[v].remove(w);
        G.adj[w].remove(v);
        numberEdges--;
        dfsEulerian(G, w, s);
    }
}

bool Cycle::hasCycle() { return cycle; }

bool Cycle::hasEulerCycle() {
    // THIS WORKS PERFECTLY WELL
    for (int degree : G->degrees)
        if (degree % 2 != 0) return false;
    
    return true;
}

int main() {
    string filename = "tiny-euler2.txt";
    Graph graph(filename);
    Cycle cycle(&graph);

    cycle.findEulerCycle();
}