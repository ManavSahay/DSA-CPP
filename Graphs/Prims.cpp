#include <iostream>
#include <queue>
#include <vector>

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
        int cost;

        Pair(int node, int cost): node(node), cost(cost) {}

        bool operator<(Pair p2) const {
            return this->cost > p2.cost;
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

        void primsAlgo() {
            priority_queue<Pair> pq;
            bool vis[vertices] = {false};
            pq.push(Pair(0, 0));

            int mstCost = 0;

            while (!pq.empty()) {
                Pair curr = pq.top();
                pq.pop();

                if (!vis[curr.node]) {
                    vis[curr.node] = true;
                    mstCost += curr.cost;

                    for (int i = 0; i < graph[curr.node].size(); i++) {
                        Edge e = graph[curr.node].at(i);
                        if (!vis[e.destination]) {
                            pq.push(Pair(e.destination, e.weight));
                        }
                    }
                }
            }

            cout << "Minimum cost of MST: " << mstCost << endl;
        }
};

int main() {
    int V = 4;
    Graph graph(V);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    
    graph.addEdge(1, 0, 10);
    graph.addEdge(1, 3, 40);
    
    graph.addEdge(2, 0, 15);
    graph.addEdge(2, 3, 50);
    
    graph.addEdge(3, 1, 40);
    graph.addEdge(3, 2, 50);

    graph.primsAlgo();

    return 0;
}