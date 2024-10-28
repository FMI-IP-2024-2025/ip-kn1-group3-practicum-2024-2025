#include <iostream>

int reverseNumber(int n) {
  int res = 0;
  do {
    res = res*10 + n%10;
  } while (n/=10);

  return res;
}

bool isPalindrome(int n) {
  return n == reverseNumber(n);
}

int main() {

  int reversed = reverseNumber(123);
  std::cout << reversed << '\n';

  std::cout << std::boolalpha;
  std::cout << isPalindrome(2300) << '\n';
  std::cout << isPalindrome(1234321) << '\n';

  return 0;
}