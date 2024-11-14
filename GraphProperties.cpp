#include "GraphProperties.h"
#include "ConnectedComponents.h"
#include <bits/stdc++.h>
#include<limits>

GraphProperties::GraphProperties(Graph* G) {
    this->G = G;
    this->count = 0;
    ConnectedComponents cc(G);

    if (cc.count() > 1) {
        diameter = numeric_limits<int>::infinity();
        radius   = numeric_limits<int>::infinity();
        center   = 0;
    }
    else {
        diameter = 0;
        radius   = numeric_limits<int>::infinity();
        center   = 0;
        for (this->source = 0; this->source < G->vertices(); this->source++) {

            marked.resize(G->vertices(), false);
            edgeTo.resize(G->vertices());
            distTo.resize(G->vertices());
            
            vertices.push(source);
            marked[source] = true;
            bfs(*G, source);
            
            for (int v = 0; v < G->vertices(); v++) {
                if (v == source) continue;
                int eccentricity = 0;
                if (distanceTo(v) >= diameter) diameter = distanceTo(v);
                if (distanceTo(v) <= radius)  {
                    radius = distanceTo(v);
                    center = source;
                }

            }
        }
    }
}

void GraphProperties::bfs(Graph& G, int v) {
    if (vertices.empty()) return;
    vertices.pop();
    count++;
    for (int w : G.adj[v])
        if (!marked[w]) {
            edgeTo[w] = v;
            distTo[w] = count;
            vertices.push(w);
            marked[w] = true;
        }
    bfs(G, vertices.front());
}

bool GraphProperties::hasPathTo(int v) { return marked.at(v); }

int GraphProperties::distanceTo(int v) { return distTo[v]; }

vector<int> GraphProperties::pathTo(int v) {
    if (!hasPathTo(v)) return {};
    vector<int> pathTo;
    for (int x = v; x != source; x = edgeTo.at(x))
        pathTo.push_back(x);
    pathTo.push_back(source);
    reverse(pathTo.begin(), pathTo.end());
    return pathTo;
}

int GraphProperties::d() { return diameter; }
int GraphProperties::c() { return center; }
int GraphProperties::r() { return radius; }

// int main() {
//     string filename = "tinyG-ec.txt";
//     Graph G(filename);

//     GraphProperties graph(&G);
//     cout << "Center: " << graph.c() << endl;
//     cout << "Diameter: " << graph.d() << endl;
//     cout << "Radius: " << graph.r() << endl;

// }