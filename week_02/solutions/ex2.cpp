#include <iostream>

int main() {

  int n;
  std::cin >> n;

  if (n < 0) {
    std::cout << "Error: number cannot be negative!";
    return -1;
  }

  float sum = 0;
  for (unsigned int i = 0; i < n; ++i) {
    int number;
    std::cin >> number;
    sum += number;
  }

  float arithmeticMean = sum/n;
  
  std::cout << arithmeticMean << std::endl;

  return 0;
}