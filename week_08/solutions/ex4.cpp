#include <iostream>

unsigned int const M = 5;
unsigned int const N = 129;

unsigned int capitalLetters(char str[]) {
  unsigned int counter = 0;
  while (*str) {
    if (*str >= 'A' && *str <= 'Z') counter++;
    str++;
  }
  return counter;
}

char* strWithMostCapitalLetters(char matrix[][N]) {
  unsigned int maxCapitalLetters = 0;
  char* str = matrix[0];
  for (unsigned int i = 0; i < M; ++i) {
    unsigned int currLetters = capitalLetters(matrix[i]);
    if (currLetters > maxCapitalLetters) {
      maxCapitalLetters = currLetters;
      str = matrix[i];
    }
  }
  return str;
}

int main() {

  char matrix[M][N] = {"Hello", "World", "FMI", "IP", "string"};
  std::cout << strWithMostCapitalLetters(matrix);

  return 0;
}