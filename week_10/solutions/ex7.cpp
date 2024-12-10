#include <iostream>

void print(char arr[]) {
  std::cout << arr << std::endl;
}

void permute(char arr[], int size, int index) {
  if (index>=size-1) {
    print(arr);
    return;
  } 

  for (int i = index; i < size; ++i) {
    std::swap(arr[i],arr[index]);
    permute(arr,size,index+1);
    std::swap(arr[i],arr[index]);
  }
}

void strings(char const str[], int size, bool subset[], int index, int n, int k, char buffer[]) {
  //k следи колко символа сме "добавили" към новия низ,
  //а n е дължината на новия низ
  if (k==n) {
    //генерирали сме подмножество от n на брой елемента (букви).
    //правим низ от тях (за да работим по-лесно с тях)
    //и взимаме всичките пермутации на този низ,
    //за да получим всички възможни думи
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
      if (subset[i]) buffer[cnt++] = str[i];
    }
    buffer[cnt] = '\0';
    permute(buffer,cnt,0);
    return;
  }
  if (index>=size) return;

  //"добавяме" текущия символ към новия низ
  subset[index] = true;
  strings(str,size,subset,index+1,n,k+1,buffer);
  //"премахваме" текущия символ от новия низ
  subset[index] = false;
  strings(str,size,subset,index+1,n,k,buffer);
}

int main() {

  char str[] = "abcd";
  //забележете, че не можем да използваме strlen,
  //понеже резултата от нея не е задължително
  //да се знае по време на компилация!
  bool subset[sizeof(str)-1] {};
  char buffer[sizeof(str)] {};
  strings(str,4,subset,0,3,0,buffer);

  return 0;
}