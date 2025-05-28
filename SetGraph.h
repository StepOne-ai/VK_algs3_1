#ifndef SETGRAPH_H
#define SETGRAPH_H

#include "IGraph.h"
#include <vector>
#include <unordered_set>

using namespace std;

struct SetGraph : public IGraph {
    SetGraph(int size);
    SetGraph(const IGraph &graph);
    ~SetGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<unordered_set<int>> adjacencySets;
};

#endif