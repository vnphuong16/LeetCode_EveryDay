#include <iostream>
#include <vector>
#include <map>

long long continuousSubarrays(std::vector<int>& nums) {
    long long result = 0;
    size_t left = 0;
    size_t right = 0;
    std::map<int,int> frequency;

    while (right < nums.size()) {

        ++frequency[nums[right]];

        while (frequency.rbegin()->first - frequency.begin()->first > 2) {
            --frequency[nums[left]];
            if (frequency[nums[left]] == 0) {
                frequency.erase(nums[left]);
            }
            left++;
        }
        
        result += (right - left + 1);

        right++;
    }

    return result;
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

    std::cout << continuousSubarrays(nums);

    return 0;
}