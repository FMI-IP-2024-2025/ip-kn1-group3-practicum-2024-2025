#include <iostream>

int collatzTerm(int n) {
  if (n%2 == 0) {
    return n/2;
  }
  return 3*n + 1;
}

void collatzConjecture(int n) {
  for (int i = 0; i < 500 && n != 1; ++i) {
    std::cout << n << '\n';
    n = collatzTerm(n);
  }
  std::cout << n;
}

int main() {

  collatzConjecture(11);

  return 0;
}