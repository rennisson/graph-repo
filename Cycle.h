#ifndef CYCLE_H
#define CYCLE_H
#include "Graph.h"
#include <vector>
#include <map>

class Cycle {
    private:
        Graph* G;
        vector<bool> marked;
        map<int, list<int>> edges;
        int numberEdges;
        bool cycle;
        vector<int> eulerianCycle;
        void dfs(Graph& G, int v, int u);
        void dfsEulerian(Graph&, int v, int s);

    public:
        Cycle(Graph* G);
        void findEulerCycle();
        bool hasCycle();
        bool hasEulerCycle();
};

#endif