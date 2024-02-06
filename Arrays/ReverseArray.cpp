#include <iostream>

using namespace std;

void swap(int *a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(&arr[start], &arr[end]);

        start++;
        end--;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int length = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, length);
    reverse(arr, length);
    printArray(arr, length);

    return 0;
}