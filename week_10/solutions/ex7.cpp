#include <iostream>

void print(char const str[], bool subset[], int size) {
  for (int i = 0; i < size; ++i) {
    if (subset[i]) std::cout << str[i];
  }
  std::cout << std::endl;
}

void strings(char const str[], int size, bool subset[], int index, int n, int k) {
  //k следи колко символа сме "добавили" към новия низ,
  //а n е дължината на новия низ
  if (k==n) {
    print(str,subset,size);
    return;
  }
  if (index>=size) return;

  //"добавяме" текущия символ към новия низ
  subset[index] = true;
  strings(str,size,subset,index+1,n,k+1);
  //"премахваме" текущия символ от новия низ
  subset[index] = false;
  strings(str,size,subset,index+1,n,k);
}

int main() {

  char str[] = "abcdef";
  //забележете, че не можем да използваме strlen,
  //понеже резултата от нея не е задължително
  //да се знае по време на компилация!
  bool subset[sizeof(str)] {};
  strings(str,6,subset,0,5,0);

  return 0;
}