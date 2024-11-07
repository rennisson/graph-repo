#include "Paths.h"
#include "Graph.h"
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Paths::Paths(Graph* G, int s) {
    this->G = G;
    this->count = 0;
    this->s = s;
    marked.resize(G->vertices(), false);
    edgeTo.resize(G->vertices());
    dfs(*G, s);
}

void Paths::dfs(Graph& G, int v) {
    marked[v] = true;
    for (int w : G.adj[v]) {
        if (!marked[w]) {
            edgeTo[w] = v;
            dfs(G, w);
        }
    }
}

bool Paths::hasPathTo(int v) { return marked.at(v); }

vector<int> Paths::pathTo(int v) {
    if (!hasPathTo(v)) return {};
    vector<int> pathTo;
    for (int x = v; x != s; x = edgeTo.at(x))
        pathTo.push_back(x);
    pathTo.push_back(s);
    reverse(pathTo.begin(), pathTo.end());
    return pathTo;
}

int main() {
    string filename = "tinyCG.txt";
    Graph graph(filename);
    int source = 0;
    Paths search(&graph, source);
    for (int v = 0; v < graph.vertices(); v++) {
        cout << source << " to " << v << ": ";
        if (search.hasPathTo(v))
            for (int x : search.pathTo(v))
                if (x == source) cout << x;
                else cout << "-" << x;
            cout << "\n";
    }
}