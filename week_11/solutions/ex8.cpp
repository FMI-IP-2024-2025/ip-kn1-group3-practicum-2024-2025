#include <iostream>
#include <cstring>

void copy(char const* begin, char const* end, char* dest) {
  while (begin <= end) {
    *dest = *begin;
    dest++;
    begin++;
  }
  *dest = '\0';
}

void split(char const* str, char* dest[], char delim) {
  char const* end = str + strlen(str)-1;
  char const* ptr = str;
  int size = 0;
  int counter = 0;
  while (ptr <= end) {
    if (*ptr == delim) {
      dest[counter] = new char[size+1];
      copy(str,ptr-1,dest[counter]);
      size = 0;
      counter++;
      str = ptr+1; 
    }
    else {
      size++;
    }
    ptr++;
  }

  dest[counter] = new char[size+1];
  copy(str,end,dest[counter]);
}

int main() {

  char const* str = "pointers$are$cool";
  //не можем да имаме повече от strlen(str)+1 низа
  //като резултат. най-лошият случай е, когато 
  //низът се състои само от разделители и имаме
  //само празни низове
  int size = strlen(str)+1;
  char** dest = new char*[size] {};

  split(str,dest,'$');

  int index = 0;
  while (dest[index] != nullptr && index < size) {
    std::cout << dest[index] << std::endl;
    index++;
  }

  index = 0;
  while (dest[index] != nullptr && index < size) {
    delete[] dest[index];
    index++;
  }
  delete[] dest;

  return 0;
}