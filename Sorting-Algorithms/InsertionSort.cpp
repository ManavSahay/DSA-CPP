#include <iostream>

using namespace std;

void printArray(int[], int);
void insertionSort(int[], int);

int main() {
    int arr[] = {1, 3, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, length);
    insertionSort(arr, length);
    printArray(arr, length);

    return 0;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int length) {
    int key, i, j;
    for (i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}