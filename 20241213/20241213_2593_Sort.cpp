#include <iostream>
#include <algorithm>
#include <vector>

long long findScore(std::vector<int>& nums) {
    long long score = 0;

    std::vector<std::pair<int, int>> sorted;

    for (size_t i = 0; i < nums.size(); ++i) {
        sorted.push_back(std::make_pair(nums[i], i));
    }

    std::sort(sorted.begin(), sorted.end());

    std::vector<bool> marked(nums.size(), false);

    for (size_t i = 0; i < nums.size(); ++i) {
        int num = sorted[i].first;
        int index = sorted[i].second;

        if (!marked[index]) {
            score += num;

            marked[index] = true;

            if (index - 1 >= 0) {
                marked[index - 1] = true;
            }

            if (index + 1 < nums.size()) {
                marked[index + 1] = true;
            }
        }
    }

    return score;
}

int main() {
    int read;
    int n;

    std::cin >> n;
    std::vector<int> nums;
    for (int i = 0; i < n; ++i) {
        std::cin >> read;
        nums.push_back(read);
    }

    // std::vector<int> nums { 2,1,3,4,5,2 };
    // std::vector<int> nums { 2,3,5,1,3,2 };
    // std::vector<int> nums { 10,44,10,8,48,30,17,38,41,27,16,33,45,45,34,30,22,3,42,42 };
    
    std::cout << findScore(nums);

    return 0;
}