#include <iostream>
#include <cmath>

int main() {

  int n;
  std::cin >> n;

  if (n <= 1) {
    std::cout << n << " is not prime";
    return 0;
  }

  bool isPrime = true;
  // you can optimise it using sqrt()
  for (unsigned int i = 2; i <= sqrt(n); ++i) {
    if (n%i == 0) {
      isPrime = false;
      break;
    }
  }

  isPrime ? std::cout << n << " is prime" 
          : std::cout << n << " is not prime";

  return 0;
}