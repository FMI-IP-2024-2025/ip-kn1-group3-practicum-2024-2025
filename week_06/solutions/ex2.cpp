#include <iostream>

//ето тук можете да разгледате какво има в <cstring>
// https://cplusplus.com/reference/cstring/

//приемете наготово, че char const* str е съшото като
//char const str[]. евентуално ще разберем защо :)
//алтернативна имплементация е да се въведе брояч,
//който да брои символите, докато не срещнем '\0'
size_t strlen2(char const* str) {
  size_t size = 0;
  while (*str) {
    size++;
    str++;
  }
  return size;
}

//стандартната функция връща char*
void strcpy2(char* dest, char const* source) {
  while (*source) {
    *dest = *source;
    dest++;
    source++;
  }
  *dest = '\0';
}

//забележете, че не можем да знаем дали има достатъчно
//място в dest за source, тъй като не подаваме размера му.
//затова валидацията трябва или да стане на мястото,
//където се извиква функцията, или да въведем допълнителен
//параметър, който да обозначава капацитета на dest
void strcat2(char* dest, char const* source) {
  while (*dest) {
    dest++;
  }

  while (*source) {
    *dest = *source;
    dest++;
    source++;
  }
  *dest = '\0';
}

//ЗАБЕЛЕЖКА: това НЕ е начинът, по който е 
//имплементирана strcmp в <cstring>.
int strcmp2(char const* s1, char const* s2) {
  if (strlen2(s1) < strlen2(s2)) return -1;
  if (strlen2(s1) > strlen2(s2)) return 1;

  while (*s1 && *s2) {
    if (*s1 < *s2) return -1;
    else if (*s1 > *s2) return 1;

    s1++;
    s2++;
  }

  return 0;
}

//strcmp e имплементирана в <cstring> по следния начин,
//като имайте предвид, че в стандартната имплементация
//не е гарантирано, че стойностите ще са -1,0,1,
//а само че ще са или отрицателни, или нулеви,
//или положителни
int strcmp3(char const* s1, char const* s2) {
  while (*s1 && *s2) {
    if (*s1 < *s2) return -1;
    else if (*s1 > *s2) return 1;
    s1++;
    s2++;
  }

  if (*s1 == *s2) return 0;
  else if (*s1 < *s2) return -1;
  return *s1 > *s2;
}

int main() {

  char str1[14] = "hello, ";
  char str2[] = "world!";
  char str3[129];

  std::cout << strlen2(str1) << ' ' << strlen2(str2) << '\n';

  strcat2(str1,str2);
  std::cout << str1 << '\n';

  strcpy2(str3,str1);
  std::cout << str3 << '\n';

  char str4[] = "abd";
  char str5[] = "abcd";

  std::cout << strcmp2(str4,str5) << '\n';
  std::cout << strcmp3(str4,str5) << '\n';
  std::cout << strcmp2(str4,str4) << '\n';
  std::cout << strcmp3(str4,str4) << '\n';

  return 0;
}