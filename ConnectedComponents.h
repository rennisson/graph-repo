#ifndef CONNECTEDCOMPONENTS_H
#define CONNECTEDCOMPONENTS_H
#include "Graph.h"
#include <vector>

class ConnectedComponents {
    private:
        Graph* G;
        int c;
        vector<int> id;
        vector<bool> marked;
        bool connected(int v, int w);
        void dfs(Graph& G, int s);

    public:
        ConnectedComponents(Graph* G);
        int count();
        int getId(int v);

};

#endif