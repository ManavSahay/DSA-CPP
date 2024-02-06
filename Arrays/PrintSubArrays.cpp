#include <iostream>

using namespace std;

void printSubArrays(int arr[], int length) {
    int ts = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Total Sub Arrays = " << ts << endl;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    printSubArrays(arr, length);

    return 0;
}