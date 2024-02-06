#include <iostream>

using namespace std;

void printArray(int[], int);
void swap(int *, int *);
void selectionSort(int[], int);

int main() {
    int arr[] = {1, 3, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, length);
    selectionSort(arr, length);
    printArray(arr, length);

    return 0;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int length) {
    int i, j, minIndex;
    for (int i = 0; i < length - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}