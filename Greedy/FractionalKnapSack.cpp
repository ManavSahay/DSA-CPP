#include <iostream>

using namespace std;

class Items {
    private:
        float calcRatio() {
            return this->val / (float) this->weight;
        }

    public:
        int name;
        int val;
        int weight;
        float ratio;

        Items(int name, int val, int weight):name(name), val(val), weight(weight) {
            ratio = calcRatio();
        }

        Items() {}

        bool operator < (Items i1) {
            return this->ratio > i1.ratio;
        }
};

int main() {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;

    int weightLength = sizeof(weight) / sizeof(weight[0]);

    Items *items = new Items[weightLength];

    for (int i = 0; i < weightLength; i++) {
        items[i] = Items(i, value[i], weight[i]);
    }

    for (int i = 0; i < weightLength; i++) {
        for (int j = i + 1; j < weightLength; j++) {
            if (items[i] < items[j]) {
                Items temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int capacity = W;
    int finalValue = 0;

    for (int i = weightLength - 1; i >= 0; i--) {
        if (capacity >= items[i].weight) {
            finalValue = finalValue + items[i].val;
            capacity = capacity - items[i].weight;
        }
        else {
            finalValue += (items[i].ratio * capacity);
            capacity = 0;
        }
    }

    cout << "Final value = " << finalValue << endl;

    return 0;
}