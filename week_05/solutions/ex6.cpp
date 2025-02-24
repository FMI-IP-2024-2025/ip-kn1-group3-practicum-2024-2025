#include <iostream>

void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size-1; ++i) {
    bool swapped = false;
    for (int j = 0; j < size-1-i; ++j) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }
    if (!swapped) return;
  }
}

void selectionSort(int arr[], int size) {
  int smallestIdx = 0;
  for (int i = 0; i < size-1; ++i) {
    for (int j = i+1; j < size; ++j) {
      if (arr[smallestIdx] > arr[j]) {
        smallestIdx = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[smallestIdx];
    arr[smallestIdx] = temp;
  }
}

void printArr(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
}

int main() {

  size_t const SIZE = 10;
  int arr1[SIZE] = {4,5,3,8,53,12,13,1,0,-1};
  bubbleSort(arr1,SIZE);
  printArr(arr1,SIZE);

  std::cout << '\n';

  int arr2[SIZE] = {4,5,3,8,53,12,13,1,0,-1};
  selectionSort(arr2,SIZE);
  printArr(arr2,SIZE);

  return 0;
}