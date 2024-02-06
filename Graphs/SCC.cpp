#include <iostream>
#include <vector>
#include <stack>

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
        stack<int> s;
        bool vis[];

        void topSort(int curr) {
            vis[curr] = true;

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);
                if (!vis[e.destination]) {
                    topSort(e.destination);
                }
            }

            s.push(curr);
        }

        void dfs(vector<vector<Edge>> graph, int curr) {
            vis[curr] = true;
            cout << curr << " ";

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);
                if (!vis[e.destination]) {
                    dfs(graph, e.destination);
                }
            }
        }

    public:
        Graph(int vertices): vertices(vertices), graph(vertices) {}

        void addEdge(int source, int destination) {
            Edge edge(source, destination);
            graph[source].push_back(edge);
        }

        void kosarajuAlgo() {
            vis[vertices] = {false};

            for (int i = 0; i < vertices; i++) {
                if (!vis[i]) {
                    topSort(i);
                }
            }

            vector<vector<Edge>> transpose(vertices);
            for (int i = 0; i < vertices; i++) {
                vis[i] = false;
            }

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < graph[i].size(); j++) {
                    Edge e = graph[i].at(j);
                    transpose[e.destination].push_back(Edge(e.destination, e.source));
                }
            }

            while (!s.empty()) {
                int curr = s.top();
                s.pop();

                if (!vis[curr]) {
                    dfs(transpose, curr);
                    cout << endl;
                }
            }
        }
};

int main() {
    // SCC --> Strongly Connected Components
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 2);
    graph.addEdge(0, 3);

    graph.addEdge(1, 0);

    graph.addEdge(2, 1);

    graph.addEdge(3, 4);

    graph.kosarajuAlgo();

    return 0;
}
