#include <iostream>
#include <cstring>

bool isPalindrome(char const str[], int l, int r) {
  return r>=l || str[l]==str[r] && isPalindrome(str,l+1,r-1);
}

int main() {

  char str[] = "abcba";
  std::cout << isPalindrome(str,0,strlen(str)-1);

  return 0;
}