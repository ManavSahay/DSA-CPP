#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Edge {
    public:
        int source;
        int destination;
        int weight;

        Edge(int source, int destination, int weight): source(source), destination(destination), weight(weight) {}
};

class Graph {
    private:
        int vertices;
        vector<vector<Edge>> graph;

    public:
        Graph(int vertices): vertices(vertices), graph(vertices) {}

        void addEdge(int source, int destination, int weight) {
            Edge edge(source, destination, weight);
            graph[source].push_back(edge);
        }

        void bellmanFord(int source) {
            int dist[vertices] = {0};
            for (int i = 0; i < vertices; i++) {
                if (i != source) {
                    dist[i] = INT_MAX;
                }
            }

            // O(V.E)
            for (int k = 0; k < vertices - 1; k++) {
                for (int i = 0; i < vertices; i++) {
                    for (int j = 0; j < graph[i].size(); j++) {
                        Edge e = graph[i].at(j);
                        int u = e.source;
                        int v = e.destination;

                        if (dist[u] != INT_MAX && dist[u] + e.weight < dist[v]) {
                            dist[v] = dist[u] + e.weight;
                        }
                    }
                }
            }

            // check for negative cycle
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < graph[i].size(); j++) {
                    Edge e = graph[i].at(j);
                    int u = e.source;
                    int v = e.destination;

                    if (dist[u] != INT_MAX && dist[u] + e.weight < dist[v]) {
                        cout << "Negative Cycle" << endl;
                    }
                }
            }

            for (int i = 0; i < vertices; i++) {
                cout << dist[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);

    graph.addEdge(1, 2, -4);

    graph.addEdge(2, 3, 2);

    graph.addEdge(3, 4, 4);

    graph.addEdge(4, 1, -1);

    graph.bellmanFord(0);

    return 0;
}