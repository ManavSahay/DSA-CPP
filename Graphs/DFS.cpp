#include <iostream>
#include <vector>
#define MAX_SIZE 100

using namespace std;

class Edge {
    public:
        int source;
        int destination;

        Edge(int source, int destination): source(source), destination(destination) {}
};

class Graph {
    private:
        int vertices;
        vector<vector<Edge>> graph;
    
    public:
        Graph(int vertices): vertices(vertices), graph(vertices) {}

        void addEdge(int source, int destination) {
            Edge edge(source, destination);
            graph[source].push_back(edge);
        }
        
        void DFS(int curr, bool visited[]) {
            cout << curr << " ";
            visited[curr] = true;

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);
                if (!visited[e.destination]) {
                    DFS(e.destination, visited);
                }
            }
        }
};

int main() {
    int vertices = 7;
    bool visited[vertices] = {false};
    Graph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);

    graph.addEdge(1, 0);
    graph.addEdge(1, 3);

    graph.addEdge(2, 0);
    graph.addEdge(2, 4);

    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    graph.addEdge(4, 2);
    graph.addEdge(4, 3);
    graph.addEdge(4, 5);

    graph.addEdge(5, 3);
    graph.addEdge(5, 4);
    graph.addEdge(5, 6);

    graph.addEdge(6, 5);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            graph.DFS(i, visited);
        }
    }

    return 0;
}