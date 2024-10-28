#include <iostream>

bool isMersenneNumber(int n) {
  if (n < 0) return false;
  unsigned int current = 2;
  n++;
  for (int i = 0; current <= n; ++i) {
    if (current == n) return true;
    current *= 2;
  }
  return false;
}

//bonus
void printFirstNMersenneNumbers(unsigned int n) {
  unsigned int current = 2;
  while (n > 0) {
    std::cout << current-1 << '\n';
    current <<= 1;
    n--;
  }
}

int main() {

  std::cout << isMersenneNumber(0);

  printFirstNMersenneNumbers(10);

  return 0;
}