#include <iostream>

bool isPowerOfK(int n, int k) {
  int product = 1;
  while (product < n) {
    product *= k;
  }
  return product == n;
}

unsigned int exactPowersOfK(int n, int k) {
  unsigned int counter = 0;
  for (int i = 1; i <= n; ++i) {
    if (isPowerOfK(i,k)) counter++;
  }
  return counter;
}

int main() {

  std::cout << exactPowersOfK(1024,2);

  return 0;
}