#include <iostream>

int reverseOddDigits(int n) {
  int reversed = 0;
  while (n) {
    int digit = n%10;
    if (digit%2 != 0) {
      reversed = reversed*10 + digit;
    }
    n/=10;
  }
  return reversed;
}

int main() {

  std::cout << reverseOddDigits(123) << '\n';
  std::cout << reverseOddDigits(425873) << '\n';
  std::cout << reverseOddDigits(2468) << '\n';

  return 0;
}