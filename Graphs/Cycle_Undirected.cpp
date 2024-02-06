#include <iostream>
#include <vector>

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

        bool isCycleUndirected(bool vis[], int curr, bool parent) {
            vis[curr] = true;

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);

                if (vis[e.destination] && e.destination != parent) {
                    return true;
                }
                else if (!vis[e.destination]) {
                    if (isCycleUndirected(vis, e.destination, curr)) {
                        return true;
                    }
                }
            }

            return false;
        }
};

int main() {
    int vertices = 6;
    Graph graph(vertices);
    bool isCycleDetected = false;

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);

    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);
    
    graph.addEdge(3, 2);
    
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(4, 5);

    graph.addEdge(5, 4);

    bool vis[vertices] = {false};

    isCycleDetected = graph.isCycleUndirected(vis, 0, -1);

    cout << isCycleDetected << endl;

    return 0;
}