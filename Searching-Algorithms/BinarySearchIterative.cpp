#include <iostream>

using namespace std;

void printArray(int[], int);
int binarySearch(int[], int, int, int);
void sort(int[], int);
void swap(int *, int *);

int main() {
    int arr[] = {1, 3, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    sort(arr, length);
    printArray(arr, length);
    int element = 4;
    int pos = binarySearch(arr, element, 0, length - 1);
    if (pos == -1) {
        cout << "Element not found!" << endl;
    }
    else {
        cout << "Element found at position " << pos << endl;
    }


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

void sort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int binarySearch(int arr[], int key, int low, int high) {
    while (high >= low) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}