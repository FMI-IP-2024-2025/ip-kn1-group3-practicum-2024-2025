#include <iostream>

int main() {

  int n;
  std::cin >> n;

  if (n < 0) {
    std::cout << "Factorial of a negative number is undefined!";
    return -1;
  }

  unsigned int factorial = 1;  // multiplicative identity
  for (unsigned int i = n; n >= 2; --i) {
    factorial *= i;
  }

  std::cout << n << "! = " << factorial << std::endl;

  // bonus: double factorial
  unsigned int doubleFactorial = 1;
  for (unsigned int i = n; n >= 2; i-=2) {
    doubleFactorial *= i;
  }

  std::cout << n << "!! = " << doubleFactorial << std::endl;

  return 0;
}