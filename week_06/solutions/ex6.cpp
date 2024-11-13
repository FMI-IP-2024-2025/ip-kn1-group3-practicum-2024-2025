#include <iostream>
#include <cstring>

bool isSubstring(char const* str, char const* substr) {
  if (!strcmp(substr,"")) return true;
  if (!strcmp(str,"")) return false;

  size_t len1 = strlen(str), len2 = strlen(substr);
  if (len1 < len2) return false;
  
  for (size_t i = 0; i < len1; ++i) {

    bool isSubstr = true;
    for (size_t j = 0; j < len2; ++j) {
      if (str[i+j] != substr[j]) {
        isSubstr = false;
        break;
      }
    }

    //забележете, че не можем да напишем
    //return isSubstr;
    //това е, защото трябва да преминем през целия низ str,
    //за да разберем дали съществува негов подниз, който
    //да е равен на substr
    if (isSubstr) return true;

  }

  return false;
}

int main() {

  size_t const SIZE = 1025;
  char str[SIZE];
  char substr[SIZE];
  std::cin.getline(str,SIZE);
  std::cin.getline(substr,SIZE);
  
  std::cout << isSubstring(str,substr);

  return 0;
}