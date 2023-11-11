#include <iostream>
#include <vector>

using namespace std;

class Edge {
    public:
        int source;
        int destination;
        
        // Edge(int source, int destination) {
        //     this->source = source;
        //     this->destination = destination;
        // }

        Edge(int source, int destination): source(source), destination(destination) {}
};

class Graph {
    private:
        int vertices;
        vector<vector<Edge>> list;

    public:
        Graph(int vertices): vertices(vertices), list(vertices) {};

        void addEdge(int source, int destination) {
            Edge edge(source, destination);
            list[source].push_back(edge);
        }
        
        void printGraph() {
            for (int i = 0; i < vertices; i++) {
                cout << "List for vertex " << i << ": ";
                for (const Edge& edge: list[i]) {
                    cout << "(" << edge.source << ", " << edge.destination << ")";
                }
                cout << endl;
            }
        }
};

int main() {
    int vertices = 4;
    Graph graph(vertices);

    graph.addEdge(0, 2);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);

    graph.addEdge(2, 0);
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);

    graph.addEdge(3, 1);
    graph.addEdge(3, 2);

    graph.printGraph();

    return 0;
}