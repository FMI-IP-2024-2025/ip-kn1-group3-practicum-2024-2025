#include <iostream>
#include <cstring>

/*
Напишете функция, която приема низ и заменя 
всяка главна буква със съответната ѝ малка 
и всяка малка буква със съответната ѝ главна. 
Препинателните знаци ! и ? се заменят с интервали. 
Всички останали символи остават непроменени.
*/

//вариант 1 - указател
void modifyString1(char str[]) {
  //*str != '\0'
  while (*str) {

    if (*str >= 'a' && *str <= 'z')
      *str += 'A'-'a';
    else if (*str >= 'A' && *str <= 'Z') 
      *str += 'a'-'A';
    else if (*str == '?' || *str == '!')
      *str = ' ';

    str++;
  }
}

//вариант 2 - индексиране чрез променлива
void modifyString2(char str[]) {
  size_t i = 0;
  //str[i] != '\0'
  while (str[i]) {

    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] += 'A'-'a';
    else if (str[i] >= 'A' && str[i] <= 'Z') 
      str[i] += 'a'-'A';
    else if (str[i] == '?' || str[i] == '!')
      str[i] = ' ';

    i++;
  }
}

//вариант 3 (неоптимален) - чрез strlen и for цикъл
//причината да е неоптимален спрямо първите 2, е,
//че първо трябва да обходим целия низ, за да вземем
//дължината му, а след това да го обходим още веднъж,
//за да го модифицираме. в първите два варианта си
//спестяваме първото обхождане
void modifyString3(char str[]) {

  size_t len = strlen(str);
  
  for (size_t i = 0; i < len; ++i) {

    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] += 'A'-'a';
    else if (str[i] >= 'A' && str[i] <= 'Z') 
      str[i] += 'a'-'A';
    else if (str[i] == '?' || str[i] == '!')
      str[i] = ' ';
  }
}

int main() {

  char str[] = "ab?32c!D";
  modifyString1(str);
  std::cout << str;

  return 0;
}