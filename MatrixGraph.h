#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "IGraph.h"
#include <vector>

using namespace std;

struct MatrixGraph : public IGraph {
    MatrixGraph(int size);
    MatrixGraph(const IGraph &graph);
    ~MatrixGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    vector<int> GetNextVertices(int vertex) const override;
    vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<vector<bool>> adjacencyMatrix;
};

#endif