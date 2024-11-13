#include <iostream>

int const OFFSET = -3;

bool isUpper(char symbol) {
  return symbol >= 'A' && symbol <= 'Z';
}

bool isLower(char symbol) {
  return symbol >= 'a' && symbol <= 'z';
}

void caeserCipher(char* str) {
  while (*str) {
    if (isLower(*str)) {
      *str = (*str - 'a' + OFFSET + 26) % 26 + 'a';
    }
    else if (isUpper(*str)) {
      *str = (*str - 'A' + OFFSET + 26) % 26 + 'A';
    }
    str++;
  }
}

int main() {

  unsigned int const SIZE = 1025;
  char str[SIZE];
  std::cin.getline(str, SIZE);

  caeserCipher(str);

  std::cout << str;

  return 0;
}