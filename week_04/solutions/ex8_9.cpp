#include <iostream>

double myPow(double a, int b) {
  a = b > 0 ? a : 1/a;
  b = abs(b);
  double res = 1;
  for (int i = 0; i < b; ++i) {
    res *= a;
  }

  return res;
}

unsigned int numberLength(int n) {
  unsigned int counter = 0;
  do {
    counter++;
  } while (n/=10);
  return counter;
}

bool isArmstrong(int n) {
  if (n < 0) return false;
  int sum = 0, nCopy = n;
  unsigned int len = numberLength(n); 
  do {
    sum += myPow(nCopy%10, len);
  } while(nCopy/=10);
  return n == sum;
}

int main() {

  double res = myPow(4, -2);
  std::cout << res << '\n';

  std::cout << std::boolalpha;
  std::cout << isArmstrong(407);

  return 0;
}