#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    int testCase;
    std::cin >> testCase;

    while (testCase--) {
        int n;
        std::cin >> n;

        std::vector<int> snowFlakesArray(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> snowFlakesArray[i];
        }

        int maxLength = 0;
        std::unordered_set<int> snowFlakes;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            int value = snowFlakesArray[right];

            while (snowFlakes.find(value) != snowFlakes.end()) {
                snowFlakes.erase(snowFlakesArray[left]);
                left++;
            }

            snowFlakes.insert(value);
            maxLength = std::max(maxLength, right - left + 1);
        }

        std::cout << maxLength << std::endl;
    }

    return 0;
}
