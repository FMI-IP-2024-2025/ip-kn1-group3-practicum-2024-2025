#include <iostream>

void reverse(int* begin, int* end) {
  while (begin < end) {
    std::swap(*begin, *end);
    begin++;
    end--;
  }
}

int main() {

  unsigned int const SIZE = 4;
  int arr[SIZE] {1,2,3,4};
  reverse(arr,arr+SIZE-1);

  for (int i = 0; i < SIZE; ++i) {
    std::cout << arr[i] << ' ';
  }

  return 0;
}