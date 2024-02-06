#include <iostream>
#include <queue>

using namespace std;

int main() {
    int ropes[] = {2, 3, 3, 4, 6};
    int length = sizeof(ropes) / sizeof(ropes[0]);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < length; i++) {
        pq.push(ropes[i]);
    }

    int cost = 0;
    while (pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        cost += (min1 + min2);
        pq.push(min1 + min2);
    }

    cout << "Cost of connecting ropes = " << cost << endl;

    return 0;
}