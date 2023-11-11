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

class Pair {
    public:
        int node;
        int dist;

        Pair(int node, int dist): node(node), dist(dist) {}

        bool operator<(Pair p2) const {
            return this->dist > p2.dist;
        }
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

        void dijkstra(int src) {
            priority_queue<Pair> pq;

            int dist[vertices] = {0};
            for (int i = 0; i < vertices; i++) {
                if (i != src) {
                    dist[i] = INT_MAX;
                }
            }

            bool vis[vertices] = {false};

            pq.push(Pair(0, 0));

            while (!pq.empty()) {
                Pair curr = pq.top();
                pq.pop();

                if (!vis[curr.node]) {
                    vis[curr.node] = true;

                    for (int i = 0; i < graph[curr.node].size(); i++) {
                        Edge e = graph[curr.node].at(i);
                        int u = e.source;
                        int v = e.destination;

                        if (dist[u] + e.weight < dist[v]) {
                            dist[v] = dist[u] + e.weight;
                            pq.push(Pair(v, dist[v]));
                        }
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
    int V = 6;
    Graph graph(V);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);

    graph.addEdge(1, 3, 7);
    graph.addEdge(1, 2, 1);

    graph.addEdge(2, 4, 3);

    graph.addEdge(3, 5, 1);

    graph.addEdge(4, 3, 2);
    graph.addEdge(4, 5, 5);

    graph.dijkstra(0);

    return 0;
}