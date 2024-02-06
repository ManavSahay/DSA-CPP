#include <iostream>
#include <queue>

using namespace std;

class Point {
    public:
        int idx;
        int x;
        int y;
        int distSq;

        Point(int idx, int x, int y, int distSq) {
            this->idx = idx;
            this->x = x;
            this->y = y;
            this->distSq = distSq;
        }

        bool operator < (Point p2) const {
            return p2.distSq < this->distSq;
        }
};

int main() {
    priority_queue<Point> pq;

    int pts[3][2] = {{3, 3}, {5, -1}, {-2, 4}};
    int length = sizeof(pts) / sizeof(pts[0]);
    int k = 2;

    for (int i = 0; i < length; i++) {
        int distSq = (pts[i][0] * pts[i][1]) + (pts[i][0] * pts[i][1]);
        pq.push(Point(i, pts[i][0], pts[i][1], distSq));
    }

    for (int i = 0; i < k; i++) {
        cout << "C" << pq.top().idx << endl;
        pq.pop();
    }

    return 0;
}