#ifndef ARCGRAPH_H
#define ARCGRAPH_H

#include "IGraph.h"
#include <vector>
#include <utility>

using namespace std;

struct ArcGraph : public IGraph {
    ArcGraph(int size);
    ArcGraph(const IGraph &graph);
    ~ArcGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<pair<int, int>> edges;
    int vertexCount;
};

#endif