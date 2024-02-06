#include <iostream>
#include <queue>

using namespace std;

class Row {
    public:
        int soldiers;
        int idx;

        Row(int soldiers, int idx) {
            this->soldiers = soldiers;
            this->idx = idx;
        }

        bool operator < (Row r2) const {
            if (this->soldiers == r2.soldiers) {
                return r2.idx < this->idx;
            }
            else {
                return r2.soldiers < this->soldiers;
            }
        }
};

int main() {
    int army[4][4] = {
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0}
    };
    int k = 2;
    int m = sizeof(army) / sizeof(army[0]);
    int n = sizeof(army[0]) / sizeof(army[0][0]);

    priority_queue<Row> pq;
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            count += (army[i][j] == 1) ? 1 : 0;
        }
        pq.push(Row(count, i));
    }

    for (int i = 0; i < k; i++) {
        cout << "R" << pq.top().idx << endl;
        pq.pop();
    }

    return 0;
}