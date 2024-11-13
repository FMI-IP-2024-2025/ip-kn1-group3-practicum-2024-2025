#include <iostream>
#include <cstring>

//str в случая е просто указател, който можем да местим,
//като прибавяме число към него.
//използвала съм го в няколко от първите задачи, тъй като е по-чист начин
//за запис, вместо да въвеждаме променлива за размера на низа.
//но иначе няма значение как ще го направите, може и просто да
//използвате strlen(), за да вземете размера на низа, след което
//да използвате индекс, за да достъпвате елементита на низа.

//долните две имплементации са еквивалентни.
//ако не разбирате тази с указателя, не се притеснявайте,
//предстои ни да учим указатели по-подробно.

/*
void toLower(char str[]) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; ++i) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += 'a'-'A';
  }
}
*/

void toLower(char str[]) {
  //или *str != '\0'
  while (*str) {
    if (*str >= 'A' && *str <= 'Z')
      *str += 'a'-'A';

    str++;
  }
}

int main() {

  char str[] = "I WIll pasS my INtroduCTION to pROGRAMMING courSe!";
  toLower(str);

  std::cout << str << '\n';

  unsigned int const SIZE = 129;
  char str[SIZE];
  std::cin.getline(str,SIZE);
  toLower(str);

  std::cout << str;

  return 0;
}