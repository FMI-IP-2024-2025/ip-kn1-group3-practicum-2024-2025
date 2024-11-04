#include <iostream>

size_t const MAX_SIZE = 10;

double getArithmeticMean(int arr[]) {
  double sum = 0;
  for (size_t i = 0; i < MAX_SIZE; ++i) {
    sum += arr[i];
  }
  return sum/MAX_SIZE;
} 

int main() {

  int arr[MAX_SIZE];
  for (size_t i = 0; i < MAX_SIZE; ++i) {
    std::cin >> arr[i];
  }

  std::cout << getArithmeticMean(arr);

  return 0;
}