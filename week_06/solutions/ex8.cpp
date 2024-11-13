#include <iostream>
#include <cstring>

const unsigned int SIZE = 1025;

bool isDigit(char a) {
  return a >= '0' && a <= '9';
}

//or char* str
void replaceNumbers(char str[]) {
  unsigned int length = strlen(str)+1;  // including '\0'!!!
  unsigned int read = 0, write = 0; 

  while (read < length) {
    if (isDigit(str[read])) {

      if (str[read++] == '0') {
        str[write++] = '#';  
        continue;
      }

      str[write++] = '#';  
      while (read < length && isDigit(str[read])) {
        read++;
      }
    }
    else {
      str[write++] = str[read++];
    }
  }
}

int main() {

  char str[SIZE];
  std::cin.getline(str, SIZE);

  replaceNumbers(str);
  std::cout << str;

  return 0;
}