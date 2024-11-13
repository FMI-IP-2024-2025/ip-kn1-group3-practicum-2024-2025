#include <iostream>

unsigned int const ALPHA_SIZE = 26;

//приемаме, че низът няма да е nullptr.
//иначе бихме могли директно да върнем false
bool isPangram(char const* str) {
  //инициализира масива със стойността по подразбиране,
  //в случая false. такъв масив се нарича хистограма
  bool alphabet[ALPHA_SIZE] {};

  while (*str) {
    if (*str >= 'a' && *str <= 'z')
      alphabet[*str-'a'] = true;
    else if (*str >= 'A' && *str <= 'Z')
      alphabet[*str-'A'] = true;

    str++;
  }

  for (unsigned int i = 0; i < ALPHA_SIZE; ++i) {
    if (!alphabet[i]) return false;
  }

  return true;
}

int main() {

  unsigned int const SIZE = 1025; //1024+1
  char str[SIZE];
  std::cin.getline(str,SIZE);

  std::cout << isPangram(str);

  return 0;
}