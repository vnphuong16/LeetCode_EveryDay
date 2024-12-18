#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> finalPrices(std::vector<int>& prices) {
    for (size_t i = 0; i < prices.size() - 1; ++i) {
        for (size_t j = i + 1; j < prices.size(); ++j) {
            if (prices[i] >= prices[j]) {
                prices[i] -= prices[j];
                break;
            }
        }
    }

    return prices;
}

int main() {
    int n;
    int temp;
    std::vector<int> prices;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        prices.push_back(temp);
    }

    prices = finalPrices(prices);

    for (size_t i = 0; i < n; ++i) {
        if (i == (n - 1)) {
            std::cout << prices[i];
        }
        else {
            std::cout << prices[i] << " ";
        }
    }

    return 0;
}