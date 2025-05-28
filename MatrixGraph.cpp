#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size)
    : adjacencyMatrix(size, vector<bool>(size, false)) {}

MatrixGraph::MatrixGraph(const IGraph &graph)
    : adjacencyMatrix(graph.VerticesCount(), vector<bool>(graph.VerticesCount(), false)) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            adjacencyMatrix[from][to] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    vector<int> result;
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[vertex][i]) {
            result.push_back(i);
        }
    }
    return result;
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    vector<int> result;
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[i][vertex]) {
            result.push_back(i);
        }
    }
    return result;
}