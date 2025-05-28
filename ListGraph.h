#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include "IGraph.h"
#include <vector>

struct ListGraph : public IGraph {
    ListGraph(int size);
    ListGraph(const IGraph &graph);
    ~ListGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<pair<int, int>> edges;
    int vertexCount;
};

#endif