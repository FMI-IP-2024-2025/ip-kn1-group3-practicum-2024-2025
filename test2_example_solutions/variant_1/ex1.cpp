#include <iostream>

//може и просто да използваме std::swap()
void swap(char& a, char& b) {
  char tmp = a;
  a = b;
  b = tmp;
}

void reverse(char* beg, char* end) {
  while (beg<end) {
    swap(*beg,*end);
    beg++;
    end--;
  }
}

//обхваща и случаите, когато имаме последователни интервали
void reverseWordsIn(char text[]) {
  char* beg = text;
  while (*text) {
    if (*text == ' ') {
      //не е проблем, ако beg==text, защото
      //правим проверка за това в reverse
      reverse(beg,text-1);
      beg = text+1;
    }
    text++;
  }
  reverse(beg,text-1);
}

int main() {

  char str[] = "i like to code";
  reverseWordsIn(str);

  std::cout << str;

  return 0;
}