#include <iostream>

using namespace std;

void quickSort(int[], int, int);
void printArray(int[], int);
int partition(int[], int, int);
void swap(int *, int *);

int main() {
    int arr[] = {1, 3, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, length);
    quickSort(arr, 0, length - 1);
    printArray(arr, length);
    
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotInd = partition(arr, low, high);
        quickSort(arr, low, pivotInd - 1);
        quickSort(arr, pivotInd + 1, high);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[high], &arr[i]);
    return i;
}