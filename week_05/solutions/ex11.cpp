#include <iostream>

void mergeSorted(int arr1[], size_t size1, int arr2[], size_t size2,
int result[]) {
  size_t index1 = 0, index2 = 0, resCounter = 0;
  while (index1 < size1 && index2 < size2) {
    if (arr1[index1] < arr2[index2]) 
      result[resCounter++] = arr1[index1++];
    else
      result[resCounter++] = arr2[index2++];
  }

  while (index1 < size1) {
    result[resCounter++] = arr1[index1++];
  }

  while (index2 < size2) {
    result[resCounter++] = arr2[index2++];
  }
}

int main() {

  size_t const SIZE1 = 3;
  int arr1[SIZE1] = {1,4,7};

  size_t const SIZE2 = 2;
  int arr2[SIZE2] = {2,5};

  int result[SIZE1+SIZE2];

  mergeSorted(arr1,SIZE1,arr2,SIZE2,result);

  for (size_t i = 0; i < SIZE1+SIZE2; ++i) {
    std::cout << result[i] << ' ';
  }

  return 0;
}