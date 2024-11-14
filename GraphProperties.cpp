#include "GraphProperties.h"
#include "ConnectedComponents.h"
#include <bits/stdc++.h>
#include<limits>

GraphProperties::GraphProperties(Graph* G) {
    this->G = G;
    diameter = 0;
    radius = INT_MAX;
    center = 0;
    ConnectedComponents cc(G);

    if (cc.count() > 1) {
        diameter = INT_MAX;
        radius = INT_MAX;
        center = -1;  // No valid center in disconnected graph
    }
    else {
        for (source = 0; source < G->vertices(); source++) {

            marked.assign(G->vertices(), false);
            edgeTo.assign(G->vertices(), 0);
            distTo.assign(G->vertices(), 0);
            
            vertices.push(source);
            marked[source] = true;
            bfs(*G, source);

            int eccentricity = 0;
            for (int v = 0; v < G->vertices(); v++)
                 if (distTo[v] > eccentricity) eccentricity = distTo[v];

            for (int i = 0; i < G->vertices(); i++) cout << distTo[i] << " ";
            cout << endl;
            
            cout << "Eccentricity of " << source << ": " << eccentricity << endl;
            
            if (eccentricity > diameter) diameter = eccentricity;
            if (eccentricity < radius) {
                radius = eccentricity;
                center = source;
            }
        }
    }
}

void GraphProperties::bfs(Graph& G, int v) {
    if (vertices.empty()) return;
    vertices.pop();
    for (int w : G.adj[v])
        if (!marked[w]) {
            edgeTo[w] = v;
            vertices.push(w);
            marked[w] = true;
            distTo[w] = distTo[v] + 1;
        }
    bfs(G, vertices.front());
}

int GraphProperties::distanceTo(int v) { return distTo[v]; }

int GraphProperties::d() { return diameter; }
int GraphProperties::c() { return center; }
int GraphProperties::r() { return radius; }

int main() {
    string filename = "tinyG-ec.txt";
    Graph G(filename);

    GraphProperties graph(&G);
    cout << "Center: " << graph.c() << endl;
    cout << "Diameter: " << graph.d() << endl;
    cout << "Radius: " << graph.r() << endl;

}