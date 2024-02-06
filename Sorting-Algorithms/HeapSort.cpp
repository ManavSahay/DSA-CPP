#include <iostream>

using namespace std;


void printArray(int[], int);
void heapify(int[], int, int);
void heapSort(int[], int);

int main() {
    int arr[] = {1, 3, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, length);
    heapSort(arr, length);
    printArray(arr, length);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int length, int i) {
    int largest = i;
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, length, largest);
    }
}

void heapSort(int arr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, length, i);
    }

    for (int i = length - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}