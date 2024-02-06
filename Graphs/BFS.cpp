#include <iostream>
#include <vector>
#define MAX_SIZE 100

using namespace std;

class Edge {
    public:
        int source;
        int destination;

        Edge(int source, int destination): source(source), destination(destination) {}
};

class Queue {
    private:
        int front = -1;
        int rear = -1;
        int queue[MAX_SIZE];

    public:
        int getFront() {
            return front;
        }

        int getRear() {
            return rear;
        }
        
        void push(int data) {
            rear++;
            if (rear >= MAX_SIZE) {
                cout << "Overflow" << endl;
                rear--;
                return;
            }
            queue[rear] = data;
        }

        int remove() {
            front++;
            if (front > rear) {
                front--;
                return -1;
            }
            int deletedElement = queue[front];
            return deletedElement;
        }
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

        void BFS(bool visited[], int start) {
            Queue queue;
            queue.push(start);

            while (queue.getFront() < queue.getRear()) {
                int curr = queue.remove();
                if (!visited[curr]) {
                    cout << curr << " ";
                    visited[curr] = true;

                    for (int i = 0; i < graph[curr].size(); i++) {
                        Edge e = graph[curr].at(i);
                        queue.push(e.destination);
                    }
                }
            }
        }
};

int main() {
    int vertices = 7;
    bool visited[vertices] = {false};
    Graph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);

    graph.addEdge(1, 0);
    graph.addEdge(1, 3);

    graph.addEdge(2, 0);
    graph.addEdge(2, 4);

    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    graph.addEdge(4, 2);
    graph.addEdge(4, 3);
    graph.addEdge(4, 5);

    graph.addEdge(5, 3);
    graph.addEdge(5, 4);
    graph.addEdge(5, 6);

    graph.addEdge(6, 5);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            graph.BFS(visited, i);
        }
    }

    return 0;
}