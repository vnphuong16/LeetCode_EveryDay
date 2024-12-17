#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string repeatLimitedString(std::string s, int repeatLimit) {
    std::string result = "";

    std::vector<int> myVec(26, 0);

    for (char c : s) {
        ++myVec[c - 'a'];
    }

    int idx = 25; // Start from z

    while (idx >= 0) {
        if (myVec[idx] == 0) {
            --idx;
            continue;
        }

        int use = std::min(myVec[idx], repeatLimit);
        result.append(use, 'a' + idx);
        myVec[idx] -= use;

        if (myVec[idx] > 0) {
            int smallerIdx = idx - 1;
            while (smallerIdx >= 0 && myVec[smallerIdx] == 0) {
                --smallerIdx;
            }
            if (smallerIdx < 0) {
                break;
            }
            result.push_back('a' + smallerIdx);
            --myVec[smallerIdx];
        }
    }

    return result;
}

int main() {
    std::string s;
    std::cin >> s;
    int repeatLimit;
    std::cin >> repeatLimit;

    std::cout << repeatLimitedString(s, repeatLimit);

    return 0;
} 
