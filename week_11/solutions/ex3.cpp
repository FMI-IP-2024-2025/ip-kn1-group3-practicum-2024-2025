#include <iostream>

int binarySearch(int* begin, int* end, int el) {
  int* ogBegin = begin;
  int* mid = begin + (end-begin)/2;
  while (begin <= end && *mid != el) {
    if (*mid < el)
      begin = mid+1;
    else if (*mid > el)
      end = mid-1;
    mid = begin + (end-begin)/2;
  }
  return *mid == el ? mid-ogBegin : -1;
}

int main() {

  unsigned int const SIZE = 7;
  int arr[SIZE] {3,7,13,14,20,42,90};
  for (unsigned int i = 0; i < SIZE; ++i) {
    std::cout << binarySearch(arr,arr+SIZE-1,arr[i]) << std::endl;
  }
  std::cout << binarySearch(arr,arr+SIZE-1,41);

  return 0;
}