#include <iostream>
#include <vector>

using namespace std;

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000};

    int length = sizeof(coins) / sizeof(coins[0]);

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    int countOfCoins = 0;
    int amount = 590;
    vector<int> ans;

    for (int i = 0; i < length; i++) {
        if (coins[i] <= amount) {
            while (coins[i] <= amount) {
                countOfCoins++;
                ans.push_back(coins[i]);
                amount = amount - coins[i];
            }
        }
    }

    cout << "Total (minimum) coins used = " << countOfCoins << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;

    return 0;
}