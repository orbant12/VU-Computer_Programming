#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {3, 56, 3, 1, 24, 6, 5, 1}; // The initial vector to be sorted
    int n = v.size();

    // Bubble Sort Algorithm
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    // Output the sorted vector
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << ", ";
    }

    return 0;
}
