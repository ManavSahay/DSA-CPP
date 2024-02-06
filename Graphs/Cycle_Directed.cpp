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

        bool isCycleDirected(bool vis[], int curr, bool rec[]) {
            // rec --> recursion stack
            vis[curr] = true;
            rec[curr] = true;

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);
                if (rec[e.destination]) {
                    return true;
                }
                else if (!vis[e.destination] && isCycleDirected(vis, e.destination, rec)) {
                    return true;
                }
            }
            rec[curr] = false;
            return false;
        }
};

int main() {
    int vertices = 4;
    Graph graph(vertices);
    bool isCycleDetected = false;

    graph.addEdge(0, 2);
    graph.addEdge(1, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    bool vis[vertices] = {false};
    bool rec[vertices] = {false};

    for (int i = 0; i < vertices; i++) {
        if (!vis[i]) {
            isCycleDetected = graph.isCycleDirected(vis, 0, rec);
        }
    }

    cout << isCycleDetected << endl;

    return 0;
}