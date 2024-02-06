#include <iostream>
#include <queue>

using namespace std;

class Pair {
    public:
        int val;
        int idx;

        Pair(int val, int idx): val(val), idx(idx) {}

        bool operator < (Pair p2) const {
            return this->val < p2.val;
        }
};

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int resLength = length - k + 1;
    int res[resLength];

    priority_queue<Pair> pq;

    for (int i = 0; i < k; i++) {
        pq.push(Pair(arr[i], i));
    }

    res[0] = pq.top().val;

    for (int i = k; i < length; i++) {
        while (pq.size() > 0 && pq.top().idx <= (i - k)) {
            pq.pop();
        }

        pq.push(Pair(arr[i], i));

        res[i - k + 1] = pq.top().val;
    }

    for (int i = 0; i < resLength; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}