#include "Cycle.h"
#include <iostream>
using namespace std;

Cycle::Cycle(Graph* G) {
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

bool Cycle::hasCycle() { return cycle; }

int main() {
    string filename = "tiny-loop.txt";
    Graph graph(filename);
    Cycle cycle(&graph);

    if (cycle.hasCycle()) cout << "Loop found" << endl;
    else cout << "Loop free" << endl;
}