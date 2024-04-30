#include <iostream>
#include <vector>

void
fillLeftOvers(std::vector<int> &arr, int LSize, int RSize, const std::vector<int> &L, const std::vector<int> &R, int i,
              int j, int k);

void populateLandR(int left, int middle, int LSize, int RSize, std::vector<int> &arr, std::vector<int> &L,
                   std::vector<int> &R);

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int LSize = middle - left + 1;
    int RSize = right - middle;

    std::vector<int> L(LSize), R(RSize);

    populateLandR(left, middle, LSize, RSize, arr, L, R);

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < LSize && j < RSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    fillLeftOvers(arr, LSize, RSize, L, R, i, j, k);

}

void populateLandR(int left, int middle, int LSize, int RSize, std::vector<int> &arr, std::vector<int> &L,
                   std::vector<int> &R) {
    for (int i = 0; i < LSize; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < RSize; j++)
        R[j] = arr[middle + 1 + j];
}

void
fillLeftOvers(std::vector<int> &arr, int LSize, int RSize, const std::vector<int> &L, const std::vector<int> &R, int i,
              int j, int k) {
    while (i < LSize) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < RSize) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {

        int middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    std::cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
