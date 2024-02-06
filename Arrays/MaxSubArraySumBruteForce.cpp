#include <iostream>
#include <limits.h>

using namespace std;

void maxSubArraySum(int arr[], int length) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            currSum = 0;
            for (int k = i; k <= j; k++) {
                currSum += arr[k];
            }
            if (maxSum < currSum) {
                maxSum = currSum;
            }
        }
    }
    cout << "Max Sum = " << maxSum << endl;
}

int main() {
    int arr[] = {1, -1, 6, -1, 3};
    int length = sizeof(arr) / sizeof(arr[0]);
    maxSubArraySum(arr, length);

    return 0;
}