#include <iostream>
#include <vector>

// Merge function to merge two sorted arrays
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge-insertion sort
void mergeInsertionSort(std::vector<int>& arr) {
    int n = arr.size();

    std::vector<int> mainChain;  // Create main Chain
    std::vector<int> otherChain; // Create other Chain

    for (int i = 0; i < n; i++) {
        if (mainChain.empty() || arr[i] >= mainChain.back()) {
            mainChain.push_back(arr[i]);
        } else {
            otherChain.push_back(arr[i]);
        }
    }

    // Insertion Sort for other Chain
    for (int i = 1; i < otherChain.size(); i++) {
        int key = otherChain[i];
        int j = i - 1;
        while (j >= 0 && otherChain[j] < key) {
            otherChain[j + 1] = otherChain[j];
            j--;
        }
        otherChain[j + 1] = key;
    }

    // Merge the main and other chains
    int i = 0, j = 0;
    while (i < mainChain.size() && j < otherChain.size()) {
        if (mainChain[i] >= otherChain[j]) {
            arr[i + j] = mainChain[i];
            i++;
        } else {
            arr[i + j] = otherChain[j];
            j++;
        }
    }

    while (i < mainChain.size()) {
        arr[i + j] = mainChain[i];
        i++;
    }

    while (j < otherChain.size()) {
        arr[i + j] = otherChain[j];
        j++;
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 11};
    
    mergeInsertionSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
