#include <iostream>

using namespace std;

class Pairs {
    public:
        int start;
        int end;

        Pairs() {}

        Pairs(int start, int end): start(start), end(end) {}

        bool operator < (Pairs p1) {
            return this->start > p1.start;
        }
};

int main() {
    int pairs[][2] = {{5, 24}, {39, 60}, {5, 28}, {27, 40}, {50, 90}};

    int length = sizeof(pairs) / sizeof(pairs[0]);

    Pairs *p = new Pairs[length];

    for (int i = 0; i < length; i++) {
        p[i] = Pairs(pairs[i][0], pairs[i][1]);
    }

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (p[i] < p[j]) {
                Pairs temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int chainLen = 1;
    int chainEnd = p[0].end;

    for (int i = 1; i < length; i++) {
        if (p[i].start > chainEnd) {
            chainLen++;
            chainEnd = p[i].end;
        }
    }

    cout << "Max Length = " << chainLen << endl;

    return 0;
}