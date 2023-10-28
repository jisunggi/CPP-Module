#include <iostream>
#include <vector>
#include <algorithm>

// 이진 탐색을 사용하여 element가 삽입될 위치를 찾는 함수
int insert_element(std::vector<int>& mainChain, int element) {
    int left = 0;
    int right = mainChain.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (element < mainChain[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    std::vector<int> mainChain = {5, 11, 22};
    std::vector<int> pendingElements = {3, 7, 20, 13};

    // pendingElements를 정렬하면서 mainChain에 삽입
    for (int element : pendingElements) {
        int index = insert_element(mainChain, element);
        mainChain.insert(mainChain.begin() + index, element);
    }

    // 결과 출력
    std::cout << "mainChain: ";
    for (int element : mainChain) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
