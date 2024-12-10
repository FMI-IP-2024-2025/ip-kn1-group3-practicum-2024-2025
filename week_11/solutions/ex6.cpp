#include <iostream>

int main() {

  unsigned int const SIZE = 10;
  int* arr[SIZE] {};

  unsigned int index = 0;
  int n;
  std::cin >> n;
  while (n != 0 && index < SIZE) {
    if (n > 0) {
      arr[index] = new int[n+1];
      arr[index][0] = n;
      index++;
    }
    std::cin >> n;
  }

  for (unsigned int i = 0; i < index; ++i) {
    for (unsigned int j = 1; j <= arr[i][0]; ++j) {
      std::cin >> arr[i][j];
    }
  }

  for (unsigned int i = 0; i < index; ++i) {
    for (unsigned int j = 1; j <= arr[i][0]; ++j) {
      std::cout << arr[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  for (unsigned int i = 0; i < index; ++i) {
    delete[] arr[i];
  }

  return 0;
}