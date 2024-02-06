#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    pq.push(3);
    pq.push(4);
    pq.push(1);
    pq.push(7);

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}