#include <iostream>
#include <vector>
#include <queue>

double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
    auto calculateGain = [](int passes, int totalStudents) {
        return (double)(passes + 1) / (totalStudents + 1) -
                (double)passes / totalStudents;
    };

    std::priority_queue<std::pair<double, std::pair<int, int>>> maxHeap;
    for (const auto& singleClass : classes) {
        maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                        {singleClass[0], singleClass[1]}});
    }

    while (extraStudents--) {
        auto [_, classInfo] = maxHeap.top();
        maxHeap.pop();
        int passes = classInfo.first;
        int totalStudents = classInfo.second;
        maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                        {passes + 1, totalStudents + 1}});
    }

    double totalPassRatio = 0;
    while (!maxHeap.empty()) {
        auto [_, classInfo] = maxHeap.top();
        maxHeap.pop();
        totalPassRatio += (double)classInfo.first / classInfo.second;
    }

    return totalPassRatio / classes.size();
}

int main() {
    int read;
    int n;

    std::cin >> n;
    std::vector<std::vector<int>> classes;
    for (int i = 0; i < n; ++i) {
        std::vector<int> students;
        std::cin >> read;
        students.push_back(read);
        std::cin >> read;
        students.push_back(read);
        classes.push_back(students);
    }
    std::cin >> read;

    std::cout << maxAverageRatio(classes, read);

    return 0;
}