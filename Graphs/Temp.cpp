#include <iostream>
#include <queue>

using namespace std;

struct MyObject {
    int val1;
    int val2;

    MyObject(int val1, int val2): val1(val1), val2(val2) {}

    bool operator<(MyObject p2) const {
        return this->val1 < p2.val1;
    }
};

int main() {
    // Create a priority queue of MyObject with custom comparison function
    priority_queue<MyObject> pq;

    // Add some objects to the priority queue
    pq.push(MyObject(10, 20));
    pq.push(MyObject(20, 30));
    pq.push(MyObject(30, 40));

    // Pop elements from the priority queue to retrieve them in sorted order
    while (!pq.empty()) {
        MyObject obj = pq.top();
        pq.pop();
        cout << obj.val1 << endl;
    }

    return 0;
}
