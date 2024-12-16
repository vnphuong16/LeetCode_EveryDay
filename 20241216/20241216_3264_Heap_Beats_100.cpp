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
    std::vector<std::pair<int, int>> heap;
    for (size_t i = 0; i < nums.size(); ++i) {
        heap.push_back(std::make_pair(nums[i], i));
    }

    std::make_heap(heap.begin(), heap.end(), std::greater<>());

    while (k--) {
        // Move the largest element to the end to get and delete
        std::pop_heap(heap.begin(), heap.end(), std::greater<>());
        // Get largest value
        auto [value, i] = heap.back();
        // Delete largest value
        heap.pop_back();
        // Multiple
        nums[i] *= multiplier;
        // Add
        heap.push_back({nums[i], i});
        // Sort after insert
        std::push_heap(heap.begin(), heap.end(), std::greater<>());
    }

    return nums;
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