#include <iostream>
#include <vector>
#include <algorithm>

void ReadVec(std::vector<int>& vec, int n) {
    int temp;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        vec.push_back(temp);
    }
}

void PrintVec(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i == vec.size() - 1)
            std::cout << vec[i];
        else
            std::cout << vec[i] << " ";
    }
}

std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {
    std::vector<int> result;

    std::vector<std::pair<int, int>> vec;
    for (size_t i = 0; i < nums.size(); ++i) {
        vec.push_back(std::make_pair(nums[i], i));
    }

    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < k; ++i) {
        vec[0].first *= multiplier;
        std::sort(vec.begin(), vec.end());
    }

    auto cmp = [](std::pair<int, int>& pair1, std::pair<int, int>& pair2) {
        return pair1.second < pair2.second;
    };

    std::sort(vec.begin(), vec.end(), cmp);

    for (size_t i = 0; i < vec.size(); ++i) {
        result.push_back(vec[i].first);
    }

    return result;
}

int main() {
    int k;
    int numsSize;
    int multiplier;
    std::vector<int> nums;

    std::cin >> numsSize;
    ReadVec(nums, numsSize);
    std::cin >> k;
    std::cin >> multiplier;

    PrintVec(getFinalState(nums, k, multiplier));

    return 0;
}