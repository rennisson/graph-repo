#include "Cycle.h"
#include <iostream>
using namespace std;

Cycle::Cycle(Graph* G) {
    this->G = G;
    cycle = false;
    eulerianCycle = false;
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

bool Cycle::hasCycle() { return cycle; }

bool Cycle::hasEulerCycle() {
    //marked.resize(G->vertices(), false);
    for (auto v : edgesVisited)
        v.second.resize(G->vertices(), false);

    for (int s = 0; s < G->vertices(); s++)
        if (!marked[s]) dfs(*G, s, s);
    return eulerianCycle;
}

void Cycle::dfsEulerian(Graph& G, int v, int s) {
    for (int w : G.adj[v])
        if (w == s) eulerianCycle = true;
        else if (!edgesVisited[v].at(w))  {
            edgesVisited[v].at(w) = true;
            edgesVisited[w].at(v) = true;
            dfs(G, w, s);
        }
}

int main() {
    string filename = "tiny-euler.txt";
    Graph graph(filename);
    Cycle cycle(&graph);

    if (cycle.hasEulerCycle()) cout << "Euler cycle found" << endl;
    else cout << "Loop free" << endl;
}