#include <iostream>
#include <vector>
#include <stack>

std::vector<int> finalPrices(std::vector<int>& prices) {
    std::stack<int> myStack;

    for (size_t i = 0; i < prices.size() - 1; ++i) {
        while (!myStack.empty() && prices[myStack.top()] >= prices[i]) {
            prices[myStack.top()] -= prices[i];
            myStack.pop();
        }
        myStack.push(i);
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