#include <iostream>

int main() {

  int n;
  std::cin >> n;
  //може и да се направи с булев масив.
  //в случая използваме масив от указатели към int,
  //за да използваме nullptr като различима стойност
  int** arr = new int*[n] {};

  int index, num;
  std::cin >> index >> num;
  while (index >= 0 && index < n) {
    arr[index] = new int(num);
    std::cin >> index >> num;
  }

  for (int i = 0; i < n; ++i) {
    if (arr[i] == nullptr)
      std::cout << "undefined" << std::endl;
    else std::cout << *arr[i] << std::endl;
  }

  for (int i = 0; i < n; ++i) {
    delete arr[i];
  }
  delete[] arr;

  return 0;
}