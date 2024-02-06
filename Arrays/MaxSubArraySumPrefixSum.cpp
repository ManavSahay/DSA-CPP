#include <iostream>
#include <limits.h>

using namespace std;

void maxSubArraySum(int arr[], int length) {
    int maxSum = INT_MIN;
    int currSum = 0;
    int prefix[length];

    prefix[0] = arr[0];
    for (int i = 1; i < length; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            currSum = i == 0 ? prefix[j] : prefix[j] - prefix[i - 1];

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