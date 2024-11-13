#include <iostream>

bool isDigit(char a) {
  return a >= '0' && a <= '9';
}

int toDigit(char a) {
  return a - '0';
}

//приемаме, че няма да се подава nullptr.
//иначе просто можем да имаме отделна проверка за това
int atoi2(char const* str) {

  int sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
  }

  int res = 0;
  while (isDigit(*str)) {
    res = res*10 + toDigit(*str);
    str++;
  }

  return sign*res;
}

int main() {

  std::cout << atoi2("1234") << '\n';
  std::cout << atoi2("0342") << '\n';
  std::cout << atoi2("-543210") << '\n';
  std::cout << atoi2("123abcdefgh") << '\n';

  unsigned int const SIZE = 129;
  char str[SIZE];
  std::cin.getline(str,SIZE);

  int num = atoi2(str);
  std::cout << num;

  return 0;
}