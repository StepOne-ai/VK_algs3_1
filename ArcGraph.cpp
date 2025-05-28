#include "ArcGraph.h"

ArcGraph::ArcGraph(int size)
    : vertexCount(size) {}

ArcGraph::ArcGraph(const IGraph &graph)
    : vertexCount(graph.VerticesCount()) {
    for (int from = 0; from < vertexCount; ++from) {
        for (int to : graph.GetNextVertices(from)) {
            edges.emplace_back(from, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertexCount;
}

vector<int> ArcGraph::GetNextVertices(int vertex) const {
    vector<int> result;
    for (const auto &edge : edges) {
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }
    return result;
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    vector<int> result;
    for (const auto &edge : edges) {
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }
    return result;
}