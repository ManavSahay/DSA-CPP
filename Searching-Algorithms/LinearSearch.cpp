#include <iostream>

using namespace std;

void printArray(int[], int);
int linearSearch(int[], int, int);

int main() {
    int arr[] = {1, 3, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, length);
    int element = 4;
    int pos = linearSearch(arr, element, length);
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

int linearSearch(int arr[], int key, int length) {
    for (int i = 0; i < length; i++) {
        if (key == arr[i]) {
            return i;
        }
    }
    return -1;
}