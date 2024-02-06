#include <iostream>
#include <limits.h>

using namespace std;

void kadanes(int numbers[], int length) {
    int max_sum = INT_MIN;
    int curr_sum = 0;

    for (int i = 0; i < length; i++) {
        curr_sum += numbers[i];
        if (curr_sum < 0) {
            curr_sum = 0;
        }

        max_sum = max(curr_sum, max_sum);
    }

    cout << "Max Sum = " << max_sum << endl;
}

int main() {
    int numbers[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    kadanes(numbers, length);

    return 0;
}