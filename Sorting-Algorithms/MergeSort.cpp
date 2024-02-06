#include <iostream>

using namespace std;

void printArray(int[], int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);

int main() {
    int arr[] = {1, 3, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    mergeSort(arr, 0, len - 1);
    printArray(arr, len);

    return 0;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[low + i];
    }

    for (int j = 0; j < n2; j++) {
        arr2[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}