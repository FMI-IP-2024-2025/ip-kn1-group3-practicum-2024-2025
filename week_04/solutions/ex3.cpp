#include <iostream>
#include <cmath>

bool isPrime(unsigned int n) {
  for (unsigned int i = 2; i <= sqrt(n); ++i) {
    if (n%i == 0)
      return false;
  }
  return true;
}

void printFirstNPrimes(int n) {
  unsigned int num = 2;
  while (n > 0) {
    if (isPrime(num)) {
      std::cout << num << '\n';
      n--;
    }
    num++;
  }
}

int main() {

  printFirstNPrimes(10);

  return 0;
}