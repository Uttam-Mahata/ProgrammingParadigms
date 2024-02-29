#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <stdexcept>
using namespace std;

template <class T>
class Graph
{
private:
    set<T> vertices;
    set<pair<T, T>> edges;

public:
    // Constructors
    Graph() {}
    Graph(set<T> v, set<pair<T, T>> e) : vertices(v), edges(e) {}

    // Method to create subgraph based on user's choice
    Graph<T> CreateSubGraph(set<T> v) const;

    // Method to calculate the union of two graphs
    Graph<T> Union(const Graph<T> &g) const;

    // Method to calculate the intersection of two graphs
    Graph<T> Intersection(const Graph<T> &g) const;

    // Method to check for a disconnected vertex
    bool IsDisconnectedVertex(const T &v) const;

    // Method to find the degree of any node
    size_t FindDegree(const T &v) const;

    // Method to find at least one path from given two vertices
    bool HasPath(const T &v1, const T &v2) const;

    // Method to display the graph
    void display() const;
};

template <class T>
Graph<T> Graph<T>::CreateSubGraph(set<T> v) const
{
    set<pair<T, T>> e;
    for (auto edge : edges)
    {
        if (v.find(edge.first) != v.end() && v.find(edge.second) != v.end())
            e.insert(edge);
    }
    return Graph<T>(v, e);
}

template <class T>
Graph<T> Graph<T>::Union(const Graph<T> &g) const
{
    set<T> v;
    set_union(vertices.begin(), vertices.end(), g.vertices.begin(), g.vertices.end(), inserter(v, v.begin()));

    set<pair<T, T>> e;
    set_union(edges.begin(), edges.end(), g.edges.begin(), g.edges.end(), inserter(e, e.begin()));

    return Graph<T>(v, e);
}

template <class T>
Graph<T> Graph<T>::Intersection(const Graph<T> &g) const
{
    set<T> v;
    set_intersection(vertices.begin(), vertices.end(), g.vertices.begin(), g.vertices.end(), inserter(v, v.begin()));

    set<pair<T, T>> e;
    set_intersection(edges.begin(), edges.end(), g.edges.begin(), g.edges.end(), inserter(e, e.begin()));

    return Graph<T>(v, e);
}

template <class T>
bool Graph<T>::IsDisconnectedVertex(const T &v) const
{
    return vertices.find(v) == vertices.end();
}

template <class T>
size_t Graph<T>::FindDegree(const T &v) const
{
    size_t degree = 0;
    for (auto edge : edges)
    {
        if (edge.first == v || edge.second == v)
            degree++;
    }
    return degree;
}

template <class T>
bool Graph<T>::HasPath(const T &v1, const T &v2) const
{
    set<T> visited;
    vector<T> stack;
    stack.push_back(v1);
    while (!stack.empty())
    {
        T current = stack.back();
        stack.pop_back();
        if (current == v2)
            return true;
        if (visited.find(current) == visited.end())
        {
            visited.insert(current);
            for (auto edge : edges)
            {
                if (edge.first == current)
                    stack.push_back(edge.second);
                else if (edge.second == current)
                    stack.push_back(edge.first);
            }
        }
    }
    return false;
}

template <class T>
void Graph<T>::display() const
{
    cout << "Vertices: ";
    for (auto v : vertices)
        cout << v << " ";
    cout << endl;

    cout << "Edges: ";
    for (auto e : edges)
        cout << "(" << e.first << ", " << e.second << ") ";
    cout << endl;
}

int main()
{
    set<int> v1 = {1, 2, 3, 4, 5};
    set<pair<int, int>> e1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}};
    Graph<int> g1(v1, e1);
    cout << "Graph 1:" << endl;
    g1.display();

    set<int> v2 = {3, 4, 5, 6, 7};
    set<pair<int, int>> e2 = {{3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 3}};
    Graph<int> g2(v2, e2);
    cout << "Graph 2:" << endl;
    g2.display();

    Graph<int> subgraph = g1.CreateSubGraph({1, 2, 3});
    cout << "Subgraph of Graph 1:" << endl;
    subgraph.display();

    Graph<int> unionGraph = g1.Union(g2);
    cout << "Union of Graph 1 and Graph 2:" << endl;
    unionGraph.display();

    Graph<int> intersectionGraph = g1.Intersection(g2);
    cout << "Intersection of Graph 1 and Graph 2:" << endl;
    intersectionGraph.display();

    cout << "Is 1 a disconnected vertex in Graph 1? " << (g1.IsDisconnectedVertex(1) ? "Yes" : "No") << endl;
    cout << "Is 6 a disconnected vertex in Graph 1? " << (g1.IsDisconnectedVertex(6) ? "Yes" : "No") << endl;

    cout << "Degree of 1 in Graph 1: " << g1.FindDegree(1) << endl;
    cout << "Degree of 3 in Graph 1: " << g1.FindDegree(3) << endl;

    cout << "Is there a path from 1 to 3 in Graph 1? " << (g1.HasPath(1, 3) ? "Yes" : "No") << endl;
    cout << "Is there a path from 1 to 6 in Graph 1? " << (g1.HasPath(1, 6) ? "Yes"
                                                                        : "No") << endl;                

    return 0;
}