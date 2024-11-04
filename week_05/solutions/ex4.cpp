#include <iostream>

void reverse(int arr[], size_t size) {
  for (size_t i = 0; i < size/2; ++i) {
    int temp = arr[i];
    arr[i] = arr[size-1-i];
    arr[size-1-i] = temp;
  }
}

void printArray(int arr[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;
}

int main() {

  size_t const SIZE1 = 8;
  int arr1[SIZE1] = {2,7,1,5,1,6,0,-12};
  
  size_t const SIZE2 = 5;
  int arr2[SIZE2] = {7,-32,8,42,100}; 

  std::cout << "Array 1:\n";
  printArray(arr1,SIZE1);
  reverse(arr1,SIZE1);
  std::cout << "Reversed array 1:\n";
  printArray(arr1,SIZE1);

  std::cout << "Array 2:\n";
  printArray(arr2,SIZE2);
  reverse(arr2,SIZE2);
  std::cout << "Reversed array 2:\n";
  printArray(arr2,SIZE2);

  return 0;
}