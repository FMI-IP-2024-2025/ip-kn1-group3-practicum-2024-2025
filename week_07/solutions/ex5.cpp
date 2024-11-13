#include <iostream>
#include <cstring>

bool isAlpha(char a) {
  return a >= 'a' && a <= 'z' 
         ||
         a >= 'A' && a <= 'Z';
}

//в някои случаи y се счита за гласна, в други - не 
//но това за нас няма значение
bool isVowel(char a) {
  return a == 'a' || a == 'A' ||
         a == 'e' || a == 'E' ||
         a == 'i' || a == 'I' ||
         a == 'o' || a == 'O' ||
         a == 'u' || a == 'U' ||
         a == 'y' || a == 'Y';
}

size_t numberOfConsonants(char const str[]) {
  size_t len = strlen(str);
  size_t counter = 0;

  for (size_t i = 0; i < len; ++i) {
    if (isAlpha(str[i]) && !isVowel(str[i]))
      counter++;
  }

  return counter;
}


int main() {

  char str[] = "good luck on your introduction to programming test if you're reading this :)";
  std::cout << numberOfConsonants(str);

  return 0;
}