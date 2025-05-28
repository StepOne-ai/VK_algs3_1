#include "SetGraph.h"

SetGraph::SetGraph(int size)
    : adjacencySets(size) {}

SetGraph::SetGraph(const IGraph &graph)
    : adjacencySets(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            adjacencySets[from].insert(to);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacencySets.size();
}

vector<int> SetGraph::GetNextVertices(int vertex) const {
    return vector<int>(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
}

vector<int> SetGraph::GetPrevVertices(int vertex) const {
    vector<int> result;
    for (int from = 0; from < adjacencySets.size(); ++from) {
        if (adjacencySets[from].find(vertex) != adjacencySets[from].end()) {
            result.push_back(from);
        }
    }
    return result;
}