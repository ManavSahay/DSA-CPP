#include <iostream>

using namespace std;

void sort(int[], int);

int main() {
    int A[] = {1, 2, 3};
    int B[] = {2, 1, 3};

    int length = sizeof(A) / sizeof(A[0]);

    sort(A, length);
    sort(B, length);

    int minDiff = 0;

    for (int i = 0; i < minDiff; i++) {
        minDiff += abs(A[i] - B[i]);
    }

    cout << "Minimum Difference = " << minDiff << endl;

    return 0;
}

void sort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}