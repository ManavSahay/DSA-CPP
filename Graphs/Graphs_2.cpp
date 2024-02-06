#include <iostream>
#include <vector>

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
        vector<vector<Edge>> list;

    public:
        Graph(int vertices): vertices(vertices), list(vertices) {};

        void addEdge(int source, int destination, int weight) {
            Edge edge(source, destination, weight);
            list[source].push_back(edge);
        }

        void printGraph() {
            for (int i = 0; i < vertices; i++) {
                cout << "List for vertex " << i << ": ";
                for (const Edge& edge: list[i]) {
                    cout << "(" << edge.source << ", " << edge.destination << ", " << edge.weight << ")";
                }
                cout << endl;
            }
        }
};

int main() {
    int vertices = 4;
    Graph graph(vertices);

    graph.addEdge(0, 2, 2);

    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 0);

    graph.addEdge(2, 0, 2);
    graph.addEdge(2, 1, 10);
    graph.addEdge(2, 3, -1);

    graph.addEdge(3, 1, 0);
    graph.addEdge(3, 2, -1);

    graph.printGraph();

    return 0;
}