#include <iostream>
#include <cstring>

bool isPalindrome(char const str[], size_t len) {

  for (size_t i = 0; i < len/2; ++i) {
    if (str[i] != str[len-1-i]) return false;
  }

  return true;
}

size_t longestPalindromicSubstring(char const str[]) {

  //инициализираме longest с 0, а не с 1,
  //защото празният низ "" също е валиден вход!
  size_t longest = 0;
  size_t len = strlen(str);
  for (size_t i = 0; i < len; ++i) {

    for (size_t j = i; j < len; ++j) {
      size_t size = j-i+1;
      if (size > longest && isPalindrome(str+i,size)) {
        longest = size;
      }
    }
    
  }

  return longest;
}

int main() {

  size_t const SIZE = 1025;
  char str[SIZE];
  std::cin.getline(str,SIZE);

  std::cout << longestPalindromicSubstring(str);

  return 0;
}