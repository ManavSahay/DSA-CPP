#include <iostream>

using namespace std;

int trappedRainWater(int height[], int length) {
    // Left Max boundary
    int leftMax[length];
    leftMax[0] = height[0];

    for (int i = 1; i < length; i++) {
        leftMax[i] = max(height[i], leftMax[i - 1]);
    }

    // Right Max boundary
    int rightMax[length];
    rightMax[length - 1] = height[length - 1];

    for (int i = length - 2; i >= 0; i--) {
        rightMax[i] = max(height[i], rightMax[i + 1]);
    }

    int trappedWater = 0;
    // Loop
    for (int i = 0; i < length; i++) {
        // WaterLevel = min(meftMax boundary, rightMax boundary)
        int waterLevel = min(leftMax[i], rightMax[i]);

        // trappedWater = waterLevel - height[i]
        trappedWater += waterLevel - height[i];
    }

    return trappedWater;

}

int main() {
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int length = sizeof(height) / sizeof(height[0]);

    cout << "Trapped Rain Water = " << trappedRainWater(height, length) << endl;

    return 0;
}