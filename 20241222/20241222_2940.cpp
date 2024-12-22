#include <iostream>
#include <vector>
#include <algorithm>

int search(int height, std::vector<std::pair<int, int>>& monoStack) {
    int left = 0;
    int right = monoStack.size() - 1;
    int ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (monoStack[mid].first > height) {
            ans = std::max(ans, mid);
            left = mid + 1;
        } else
            right = mid - 1;
    }
    return ans;
}

std::vector<int> leftmostBuildingQueries(std::vector<int>& heights, std::vector<std::vector<int>>& queries) {
    std::vector<std::pair<int, int>> monoStack;
    std::vector<int> result(queries.size(), -1);
    std::vector<std::vector<std::pair<int, int>>> newQueries(heights.size());
    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        if (a > b) {
            std::swap(a, b);
        }
        if (heights[b] > heights[a] || a == b) {
            result[i] = b;
        }
        else {
            newQueries[b].push_back({heights[a], i});
        }
    }

    for (int i = heights.size() - 1; i >= 0; i--) {
        int monoStackSize = monoStack.size();
        for (auto& [a, b] : newQueries[i]) {
            int position = search(a, monoStack);
            if (position < monoStackSize && position >= 0) {
                result[b] = monoStack[position].second;
            }
        }
        while (!monoStack.empty() && monoStack.back().first <= heights[i]) {
            monoStack.pop_back();
        }
        monoStack.push_back({heights[i], i});
    }
    return result;
}

int main() {
    std::vector<int> height;
    std::vector<std::vector<int>> queries;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        height.push_back(tmp);
    }

    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        int tmp1, tmp2;
        std::vector<int> tmp3;
        std::cin >> tmp1;
        std::cin >> tmp2;
        tmp3.push_back(tmp1);
        tmp3.push_back(tmp2);
        queries.push_back(tmp3);
    }

    std::vector<int> result = leftmostBuildingQueries(height, queries);

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}