#include <iostream>
#include <vector>
#include <algorithm>

// int maxChunksToSorted(std::vector<int>& arr) {
//     int result = 0;
    
//     std::vector<int> max = arr;
//     std::vector<int> min = arr;

//     for (int i = 1; i < max.size(); ++i) {
//         max[i] = std::max(max[i - 1], max[i]);
//     }

//     for (int i = min.size() - 2; i >= 0; --i) {
//         min[i] = std::min(min[i + 1], min[i]);
//     }

//     for (int i = 0; i < arr.size(); ++i) {
//         if (i == 0 || min[i] > max[i - 1])
//             ++result;
//     }

//     return result;
// }

int maxChunksToSorted(std::vector<int>& arr) {
    int result = 0;
    int max = 0;

    for (int i = 0; i < arr.size(); ++i) {
        max = std::max(max, arr[i]);
        if (max == i) {
            ++result;
        }
    }

    return result;
}

int main() {
    int n;
    int tmp;
    std::vector<int> arr;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    // std::vector<int> arr1 ({4, 3, 2, 1, 0});
    // std::vector<int> arr2 ({1, 0, 2, 3, 4});
    // std::vector<int> arr3 ({2, 0, 1});

    std::cout << maxChunksToSorted(arr) << std::endl;

    return 0;
}