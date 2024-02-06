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

        int minimum(int n1, int n2) {
            if (n1 < n2) {
                return n1;
            }
            else if (n2 < n1) {
                return n2;
            }
            else {
                return n1;
            }
        }

        void dfs(int curr, bool vis[], int dt[], int low[], int time, int par) {
            vis[curr] = true;
            dt[curr] = ++time;
            low[curr] = dt[curr];

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);
                if (e.destination == par) {
                    continue;
                }
                if (!vis[e.destination]) {
                    dfs(e.destination, vis, dt, low, time, curr);
                    low[curr] = minimum(low[curr], low[e.destination]);
                    if (dt[curr] < low[e.destination]) {
                        cout << "Bridge: " << curr << " --- " << e.destination << endl;
                    }
                }
                else {
                    low[curr] = minimum(low[curr], dt[e.destination]);
                }
            }
        }

    public:
        Graph(int vertices): vertices(vertices), graph(vertices) {}

        void addEdge(int source, int destination) {
            Edge edge(source, destination);
            graph[source].push_back(edge);
        }

        void getBridge() {
            int dt[vertices] = {false};
            int low[vertices] = {false};
            int time = 0;
            bool vis[vertices] = {false};

            for (int i = 0; i < vertices; i++) {
                if (!vis[i]) {
                    dfs(i, vis, dt, low, time, -1);
                }
            }
        }
};

int main() {
    int V = 6;
    Graph graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);

    graph.addEdge(1, 0);
    graph.addEdge(1, 2);

    graph.addEdge(2, 0);
    graph.addEdge(2, 1);

    graph.addEdge(3, 0);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    graph.addEdge(4, 3);
    graph.addEdge(4, 5);

    graph.addEdge(5, 3);
    graph.addEdge(5, 4);

    graph.getBridge();

    return 0;
}