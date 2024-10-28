#include <iostream>

bool isPerfect(unsigned int n) {
  int sum = 0;
  for (unsigned int i = 1; i < n; ++i) {
    if (n%i == 0) sum += i;
  }
  return sum == n;
}

int main() {

  std::cout << std::boolalpha;
  std::cout << isPerfect(28);

  return 0;
}