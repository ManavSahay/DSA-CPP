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

        void dfs(int curr, int par, int dt[], int low[], bool vis[], int time, bool ap[]) {
            vis[curr] = true;
            dt[curr] = ++time;
            low[curr] = dt[curr];
            int children = 0;

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);
                int neigh = e.destination;

                if (par == neigh) {
                    continue;
                }
                else if (vis[neigh]) {
                    low[curr] = minimum(low[curr], dt[neigh]);
                }
                else {
                    dfs(neigh, curr, dt, low, vis, time, ap);
                    low[curr] = minimum(low[curr], low[neigh]);

                    if (dt[curr] <= low[neigh] && par != -1) {
                        ap[curr] = true;
                    }
                    children++;
                }
            }

            if (par == -1 && children > 1) {
                ap[curr] = true;
            }
        }

    public:
        Graph(int vertices): vertices(vertices), graph(vertices) {}

        void addEdge(int source, int destination) {
            Edge edge(source, destination);
            graph[source].push_back(edge);
        }

        void getAP() {
            int dt[vertices];
            int low[vertices];
            int time = 0;
            bool vis[vertices] = {false};
            bool ap[vertices] = {false};

            for (int i = 0; i < vertices; i++) {
                if (!vis[i]) {
                    dfs(i, -1, dt, low, vis, time, ap);
                }
            }

            for (int i = 0; i < vertices; i++) {
                if (ap[i]) {
                    cout << "Articulation Point: " << i << endl;
                }
            }
        }
};

int main() {
    int V = 5;
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

    graph.addEdge(4, 3);

    graph.getAP();

    return 0;
}