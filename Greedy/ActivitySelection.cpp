#include <iostream>
#include <vector>

using namespace std;

class Activities {
    public:
        int name;
        int start;
        int end;

        Activities(int name, int start, int end): name(name), start(start), end(end) {}

        Activities(){}

        bool operator < (Activities a1) {
            return this->end > a1.end;
        }
};

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int startSize = sizeof(start) / sizeof(start[0]);
    Activities *arr = new Activities[startSize];
    
    for (int i = 0; i < startSize; i++) {
        arr[i] = Activities(i, start[i], end[i]);
    }

    for (int i = 0; i < startSize; i++) {
        for (int j = i + 1; j < startSize; j++) {
            if (arr[i] < arr[j]) {
                Activities temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int maxAct = 0;
    vector<int> ans;

    maxAct = 1;
    ans.push_back(arr[0].name);

    int lastEnd = arr[0].end;

    for (int i = 0; i < startSize; i++) {
        if (arr[i].start >= lastEnd) {
            maxAct++;
            ans.push_back(arr[i].name);
            lastEnd = arr[i].end;
        }
    }

    cout << "Max Activity: " << maxAct << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << 'A' << ans.at(i) << " ";
    }

    return 0;
}