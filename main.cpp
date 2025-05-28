#include <iostream>
#include <vector>
#include <cassert>
#include <functional>
#include <queue>
#include <deque>
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"
#include "ListGraph.h"

using namespace std;

void BFS(const IGraph &graph, int vertex, vector<bool> &visited, const function<void(int)> &func)
{
    queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;
    
    while (!qu.empty())
    {
        int currentVertex = qu.front();
        qu.pop();
        
        func(currentVertex);
        
        for (int nextVertex: graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void mainBFS(const IGraph &graph, const function<void(int)> &func)
{
    vector<bool> visited(graph.VerticesCount(), false);
    
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            BFS(graph, i, visited, func);
        }
    }
}

void DFS(const IGraph &graph, int vertex, vector<bool> &visited, const function<void(int)> &func)
{
    visited[vertex] = true;
    func(vertex);
    
    for (int nextVertex: graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
        {
            DFS(graph, nextVertex, visited, func);
        }
    }
}

void mainDFS(const IGraph &graph, const function<void(int)> &func)
{
    vector<bool> visited(graph.VerticesCount(), false);
    
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited, func);
        }
    }
}

void topologicalSortInternal(const IGraph &graph, int vertex, vector<bool> &visited, deque<int> &sorted)
{
    visited[vertex] = true;
    
    for (int nextVertex: graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
        {
            topologicalSortInternal(graph, nextVertex, visited, sorted);
        }
    }
    
    sorted.push_front(vertex);
}

deque<int> topologicalSort(const IGraph &graph)
{
    deque<int> sorted;
    vector<bool> visited(graph.VerticesCount(), false);
    
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            topologicalSortInternal(graph, i, visited, sorted);
        }
    }
    
    return sorted;
}

int main(int argc, const char * argv[]) {
    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(4, 5);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 0);

    MatrixGraph matrixGraph(listGraph);
    matrixGraph.AddEdge(1, 2);
    matrixGraph.AddEdge(2, 3);
    matrixGraph.AddEdge(3, 4);
    matrixGraph.AddEdge(4, 5);
    matrixGraph.AddEdge(5, 6);
    matrixGraph.AddEdge(6, 0);

    ArcGraph arcGraph(matrixGraph);
    arcGraph.AddEdge(1, 2);
    arcGraph.AddEdge(2, 3);
    arcGraph.AddEdge(3, 4);
    arcGraph.AddEdge(4, 5);
    arcGraph.AddEdge(5, 6);
    arcGraph.AddEdge(6, 0);

    SetGraph setGraph(arcGraph);
    setGraph.AddEdge(1, 2);
    setGraph.AddEdge(2, 3);
    setGraph.AddEdge(3, 4);
    setGraph.AddEdge(4, 5);
    setGraph.AddEdge(5, 6);
    setGraph.AddEdge(6, 0);

    cout << "MatrixGraph vertices: " << matrixGraph.VerticesCount() << endl;
    cout << "ArcGraph vertices: " << arcGraph.VerticesCount() << endl;
    cout << "SetGraph vertices: " << setGraph.VerticesCount() << endl;

    cout << "BFS MatrixGraph: ";
    mainBFS(matrixGraph, [](int v) { cout << v << " "; });
    cout << endl;

    cout << "BFS ListGraph: ";
    mainBFS(listGraph, [](int v) { cout << v << " "; });
    cout << endl;

    cout << "BFS ArcGraph: ";
    mainBFS(arcGraph, [](int v) { cout << v << " "; });
    cout << endl;

    cout << "BFS SetGraph: ";
    mainBFS(setGraph, [](int v) { cout << v << " "; });
    cout << endl;

    cout << endl;

    cout << "DFS MatrixGraph: ";
    mainDFS(matrixGraph, [](int v) { cout << v << " "; });
    cout << endl;

    cout << "DFS ListGraph: ";
    mainDFS(listGraph, [](int v) { cout << v << " "; });
    cout << endl;

    cout << "DFS ArcGraph: ";
    mainDFS(arcGraph, [](int v) { cout << v << " "; });
    cout << endl;

    cout << "DFS SetGraph: ";
    mainDFS(setGraph, [](int v) { cout << v << " "; });
    cout << endl;
    
    cout << endl;

    // Последовательность вывода в SetGraph обусловлена использованием unordered_set,
    // который не гарантирует упорядоченность элементов
    
    // Topological sort
    cout << "Topological sort: ";
    deque<int> sorted = topologicalSort(arcGraph);
    for (int i = 0; i < sorted.size(); ++i)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;

    cout << "Topological sort: ";
    sorted = topologicalSort(matrixGraph);
    for (int i = 0; i < sorted.size(); ++i)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;

    cout << "Topological sort: ";
    sorted = topologicalSort(listGraph);
    for (int i = 0; i < sorted.size(); ++i)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;

    cout << "Topological sort: ";
    sorted = topologicalSort(setGraph);
    for (int i = 0; i < sorted.size(); ++i)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;

    return 0;
}