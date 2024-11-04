#include <iostream>

void moveZeroes(int arr[], size_t size) {
  size_t write = 0;

  for (size_t i = 0; i < size; ++i) {
    if (arr[i] != 0) {
      arr[write++] = arr[i];
    }
  }

  for (size_t i = write; i < size; ++i) {
    arr[i] = 0;
  }
}

void printArr(int arr[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
}

int main() {

  int arr1[5] = {1,0,2,0,0};
  moveZeroes(arr1,5);
  printArr(arr1,5);

  std::cout << '\n';

  int arr2[10] = {0,4,0,3,91,3,1,0,2,0};
  moveZeroes(arr2,10);
  printArr(arr2,10);

  return 0;
}