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

class Stack {
    private:
        int top = -1;
        int stack[MAX_SIZE];

    public:
        int getTop() {
            return top;
        }

        void push(int data) {
            top++;
            if (top == MAX_SIZE) {
                cout << "Overflow" << endl;
                top--;
                return;
            }
            stack[top] = data;
        }

        int pop() {
            if (top <= -1) {
                return -1;
            }
            int poppedElement = stack[top];
            top--;
            return poppedElement;
        }
};

class Graph {
    private:
        int vertices;
        vector<vector<Edge>> graph;
        Stack stack;

        void topSortUtil(int curr, bool vis[]) {
            vis[curr] = true;

            for (int i = 0; i < graph[curr].size(); i++) {
                Edge e = graph[curr].at(i);

                if (!vis[e.destination]) {
                    topSortUtil(e.destination, vis);
                }
            }

            stack.push(curr);
        }
    
    public:
        Graph(int vertices): vertices(vertices), graph(vertices) {}

        void addEdge(int source, int destination) {
            Edge edge(source, destination);
            graph[source].push_back(edge);
        }

        void topSort(int vertices) {
            bool vis[vertices] = {false};

            for (int i = 0; i < vertices; i++) {
                if (!vis[i]) {
                    topSortUtil(i, vis);
                }
            }

            while (stack.getTop() != -1) {
                cout << stack.pop() << " ";
            }
            cout << endl;
        }
};

int main() {
    int vertices = 6;
    Graph graph(vertices);
    graph.addEdge(2, 3);

    graph.addEdge(3, 1);
    
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topSort(vertices);

    return 0;
}