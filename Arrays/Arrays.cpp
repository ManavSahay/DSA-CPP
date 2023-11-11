#include <iostream>
#include <stdlib.h>
#define MAX_SIZE 10

using namespace std;

int length = MAX_SIZE;

void insertion(int[], int, int);
int deletion(int[], int);
void traversal(int[]);

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    length = 5;
    
    traversal(arr);
    insertion(arr, 2, 10);
    traversal(arr);

    int deletedElement = deletion(arr, 2);
    if (deletedElement == -1) {
        cout << "Array already empty!" << endl;
    }
    else {
        cout << "Element deleted is: " << deletedElement << endl;
    }
    
    traversal(arr);

    return 0;
}

void insertion(int arr[], int position, int data) {
    if (length >= MAX_SIZE) {
        cout << "Length Exceeded" << endl;
        return;
    }
    for (int i = length - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = data;
    length++;
}

int deletion(int arr[], int position) {
    if (length < 0) {
        return -1;
    }
    int deletedElement = arr[position];
    for (int i = position; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    length--;
    return deletedElement;
}

void traversal(int arr[]) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}