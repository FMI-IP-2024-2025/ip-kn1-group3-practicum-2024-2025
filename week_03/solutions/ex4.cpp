#include <iostream>

int main() {

  // if a valid entry is guaranteed,
  // you can just use unsigned int
  int n;
  std::cin >> n;
  
  // you can also start counting from 0,
  // it's a matter of personal preference
  // and convention
  if (n <= 0) {
    std::cout << "We start counting from 1 this time!";
    return -1;
  }
  else if (n == 1) {
    std::cout << "The 1-st Fibonacci number is 0";
    return 0; 
  }

  unsigned int firstFib = 0, secondFib = 1;
  for (int i = 0; i < n-2; ++i) {
    unsigned int temp = secondFib;
    secondFib = firstFib + secondFib;
    firstFib = temp;
  }  // result gets stored in secondFib

  // English grammar is still somewhat important :D
  switch (n%10) {
    case 1:
      std::cout << "The " << n << "-st Fibonacci number is " 
                << firstFib;
      break;
    case 2:
      std::cout << "The " << n << "-nd Fibonacci number is "
                << secondFib;
      break;
    case 3:
      std::cout << "The " << n << "-rd Fibonacci number is "
                << secondFib;
      break;
    default:
      std::cout << "The " << n << "-th Fibonacci number is "
                << secondFib;
      break;  // redundant if "default" is the last case
  }

  return 0;
}