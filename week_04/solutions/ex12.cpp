#include <iostream>

int factorial(int n) {
  int res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}

int binomialCoeff(int n, int k) {
  if (k > n) return 0;
  return factorial(n) / (factorial(k) * factorial(n-k));
}

void printWhitespaces(int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << ' ';
  }
}

//of course, there are more clever ways to do this
//without computing the binomial coefficient for each term.
//but this is a good way to practice functions :)
void pascalsTriangle(int n) {
  for (int i = 0; i < n; ++i) {
    printWhitespaces(n-i-1);
    for (int j = 0; j < i+1; ++j) {
      int term = binomialCoeff(i, j);
      std::cout << term << ' ';
    }
    std::cout << '\n';
  }
}

int main() {

  pascalsTriangle(5);

  return 0;
}