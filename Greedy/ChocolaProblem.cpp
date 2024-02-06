#include <iostream>

using namespace std;

void sort(int [], int);

int main() {
    int n = 4, m = 6;
    int costVer[] = {2, 1, 3, 1, 4};
    int costHor[] = {4, 1, 2};

    int verLen = sizeof(costVer) / sizeof(costVer[0]);
    int horLen = sizeof(costHor) / sizeof(costHor[0]);

    sort(costHor, horLen);
    sort(costVer, verLen);

    int h = 0, v = 0;
    int hp = 1, vp = 1;
    int cost = 0;

    while (h < horLen && v < verLen) {
        if (costVer[v] < costHor[h]) {
            cost += (costHor[h] * vp);
            hp++;
            h++;
        }
        else {
            cost += (costVer[v] * hp);
            vp++;
            v++;
        }
    }

    while (h < horLen) {
        cost += (costHor[h] * vp);
        hp++;
        h++;
    }

    while (v < verLen) {
        cost += (costVer[v] * hp);
        vp++;
        v++;
    }

    cout << "Minimum cost of cuts = " << cost << endl;

    return 0;
}

void sort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}