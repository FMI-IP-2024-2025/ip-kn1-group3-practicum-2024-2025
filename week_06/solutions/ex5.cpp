#include <iostream>

unsigned int const ALPHA_SIZE = 26;

bool areAnagrams(char const* s1, char const* s2) {

  //тук броят на срещанията има значение, така че няма
  //как хистограмата да е булев масив
  unsigned int hist1[ALPHA_SIZE] {}, hist2[ALPHA_SIZE] {};
  
  while (*s1) {
    if (*s1 >= 'a' && *s1 <= 'z')
      hist1[*s1-'a']++;
    else if (*s1 >= 'A' && *s1 <= 'Z')
      hist1[*s1-'A']++;

    s1++;
  }

  while (*s2) {
    if (*s2 >= 'a' && *s2 <= 'z')
      hist2[*s2-'a']++;
    else if (*s2 >= 'A' && *s2 <= 'Z')
      hist2[*s2-'A']++;

    s2++;
  }

  for (unsigned int i = 0; i < ALPHA_SIZE; ++i) {
    if (hist1[i] != hist2[i]) return false;
  }

  return true;
}

int main() {

  std::cout << std::boolalpha;
  std::cout << areAnagrams("deal", "lead") << '\n';
  std::cout << areAnagrams("silent", "listen") << '\n';
  std::cout << areAnagrams("still", "slit") << '\n';

  unsigned int const SIZE = 129;
  char str1[SIZE], str2[SIZE];
  std::cin.getline(str1,SIZE);
  std::cin.getline(str2,SIZE);

  std::cout << areAnagrams(str1,str2);

  return 0;
}