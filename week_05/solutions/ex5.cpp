#include <iostream>

bool isSorted(int arr[], size_t size) {
  for (size_t i = 1; i < size; ++i)
    if (arr[i-1] > arr[i]) return false;

  return true;
}

int main() {

  size_t const SIZE = 7;
  int arr[SIZE] = {2,7,19,64,128,1235,9999};

  std::cout << std::boolalpha;
  std::cout << isSorted(arr,SIZE) << '\n';

  int arr2[SIZE] = {2,7,19,128,127,555,5555};

  std::cout << isSorted(arr2,SIZE);

  return 0;
}