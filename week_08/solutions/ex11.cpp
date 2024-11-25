#include <iostream>

unsigned int const MAX_SIZE = 129;

bool isUpperLetter(char a) {
  return a >= 'A' && a <= 'Z';
}

bool isLowerLetter(char a) {
  return a >= 'a' && a <= 'z';
}

bool isAscii(char a) {
  return isUpperLetter(a) || isLowerLetter(a);
}

bool isVowel(char a) {
  return a == 'a' || a == 'A' ||
         a == 'e' || a == 'E' ||
         a == 'i' || a == 'I' ||
         a == 'o' || a == 'O' ||
         a == 'u' || a == 'U' ||
         a == 'y' || a == 'Y';
}

bool isConsonant(char a) {
  return !isVowel(a);
}

char toUpper(char a) {
  return isLowerLetter(a) ? a + 'A'- 'a' : a;
}

char findFirstConsonant(char str[], char original) {
  while (*str) {
    if (isAscii(*str) && isConsonant(*str))
      return *str;
    str++;
  }
  return original;
}

char findFirstVowel(char str[], char original) {
  while (*str) {
    if (isAscii(*str) && isVowel(*str))
      return *str;
    str++;
  }
  return original;
}

void modify(char str[], char matrix[][MAX_SIZE], unsigned int size) {
  unsigned int oddIndex = 1, evenIndex = 0;
  for (unsigned int i = 0; str[i] != '\0'; ++i) {

    if (!isAscii(str[i])) continue;

    if (isConsonant(str[i]) && oddIndex < size) {
      char consonant = findFirstConsonant(matrix[oddIndex],str[i]);
      if (isLowerLetter(str[i]))
        str[i] = consonant;
      else if (isUpperLetter(str[i])) {
        str[i] = toUpper(consonant);
      }
      oddIndex+=2;
    }

    else if (isVowel(str[i]) && evenIndex < size) {
      char vowel = findFirstVowel(matrix[evenIndex],str[i]);
      if (isLowerLetter(str[i]))
        str[i] = vowel;
      else if (isUpperLetter(str[i])) {
        str[i] = toUpper(vowel);
      }
      evenIndex+=2;
    }

  }
}

int main() {

  char str[] = "Fmi";
  char matrix[4][MAX_SIZE] = {"imagine",
                              "i've written",
                              "something interesting",
                              "here"};

  char str2[] = "A stRiNg";  
  char matrix2[7][MAX_SIZE] = {"here are",
                                "a BUNCH of",
                                "other",
                                "uninteresting strings",
                                "to help",
                                "illustrate the",
                                "problem Better! :)" }; 

  modify(str,matrix,4);  
  std::cout << str << std::endl;
  modify(str2,matrix2,7);
  std::cout << str2 << std::endl;                            

  return 0;
}