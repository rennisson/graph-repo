#include "BreadthFirstPaths.h"
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include<limits>
using namespace std;

BreadthFirstPaths::BreadthFirstPaths(Graph* G, int s) {
    this->G = G;
    this->count = 0;
    this->s = s;
    marked.resize(G->vertices(), false);
    edgeTo.resize(G->vertices());
    distTo.resize(G->vertices(), 0);
    vertices.push(s);
    marked[s] = true;
    bfs(*G, s);
}

void BreadthFirstPaths::bfs(Graph& G, int v) {
    if (vertices.empty()) return;
    vertices.pop();
    count++;
    for (int w : G.adj[v])
        if (!marked[w]) {
            edgeTo[w] = v;
            vertices.push(w);
            marked[w] = true;
            distTo[w] = distTo[v] + 1;
        }
        
    bfs(G, vertices.front());
}

bool BreadthFirstPaths::hasPathTo(int v) { return marked.at(v); }

int BreadthFirstPaths::distanceTo(int v) { return distTo[v]; }

vector<int> BreadthFirstPaths::pathTo(int v) {
    if (!hasPathTo(v)) return {};
    vector<int> pathTo;
    for (int x = v; x != s; x = edgeTo.at(x))
        pathTo.push_back(x);
    pathTo.push_back(s);
    reverse(pathTo.begin(), pathTo.end());
    return pathTo;
}

int main() {
    string filename = "tinyG-ec.txt";
    Graph graph(filename);
    int source = 0;
    BreadthFirstPaths search(&graph, source);
    for (int v = 0; v < graph.vertices(); v++) {
        cout << source << " to " << v << ": ";
        if (search.hasPathTo(v))
            for (int x : search.pathTo(v))
                if (x == source) cout << x;
                else cout << "-" << x;
            cout << "\n";
    }

    for (int v = 0; v < graph.vertices(); v++) {
        if (search.hasPathTo(v))
            cout << "Distance from " << source << " to " << v << ": " << search.distanceTo(v);
        cout << "\n";
    }
}