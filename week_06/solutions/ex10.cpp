#include <iostream>
#include <cstring>

bool isMatch(char const* regex, char const* str) {
  size_t len = strlen(str);
  size_t rlen = strlen(regex);

  //хваща случая, когато regex започва с *
  //(произволен брой),
  //което е еквивалентно на многократно
  //повторение на празния низ
  size_t i = 0, j = 0;
  while (rlen > 0 && regex[j] == '*') j++;

  while (i < len && j < rlen) {

    if (regex[j] == '.') {
      ++i;
      ++j;
    }
    else if (regex[j] == '*') {
      char symbol = str[i];
      ++i;
      while (i < len && str[i] == symbol) {
        ++i;
      }
      ++j;
    }
    else if (regex[j] != str[i]) {
      return false;
    }
    else {
      ++i;
      ++j;
    }

  }

  return i == len && j == rlen;
}

int main() {

  char regex[] = "***I lo*ve FMI.";
  char str[] = "I loooooooooooooooove FMI!";

  std::cout << isMatch(regex,str);

  return 0;
}