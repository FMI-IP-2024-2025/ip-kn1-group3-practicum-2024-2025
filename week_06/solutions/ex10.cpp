#include <iostream>
#include <cstring>

bool isMatch(char const* regex, char const* str) {
  //хваща случая, когато regex започва с *
  //(произволен брой),
  //което е еквивалентно на многократно
  //повторение на празния низ
  size_t i = 0, j = 0;
  while (regex[j] != '\0' && regex[j] == '*') j++;

  while (str[i] != '\0' && regex[j] != '\0') {

    if (regex[j] == '.' || str[i] == regex[j]) {
      ++i;
      ++j;
    }
    else if (regex[j] == '*') {
      char symbol = str[i];
      ++i;
      while (i != '\0' && str[i] == symbol) {
        ++i;
      }
      ++j;
    }
    else {
      return false;
    }

  }

  return str[i] == regex[j];
}

int main() {

  char regex[] = "***I lo*ve FMI.";
  char str[] = "I loooooooooooooooove FMI!";

  std::cout << isMatch(regex,str);

  return 0;
}