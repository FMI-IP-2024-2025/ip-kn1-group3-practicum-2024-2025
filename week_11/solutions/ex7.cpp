#include <iostream>

//подаваме указателя по референция, тъй като искаме
//да променим накъде той сочи - в случая го пренасочваме
//към новия масив newArr
int insert(int*& arr, int size, int index, int elem) {
  if (index<0 || index>=size+1) return size;
  int* newArr = new int[size+1];
  for (int i = 0; i < index; ++i) {
    newArr[i] = arr[i];
  }
  newArr[index] = elem;
  for (int i = index+1; i < size+1; ++i) {
    newArr[i] = arr[i-1];
  }

  delete[] arr;
  arr = newArr;
  return size+1;
}

int main() {

  int size = 9;
  int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    arr[i] = i+1;
  }
  int newSize = insert(arr,size,4,999);
  for (int i = 0; i < newSize; ++i) {
    std::cout << arr[i] << ' ';
  }
  
  delete[] arr;

}