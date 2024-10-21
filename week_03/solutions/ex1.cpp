#include <iostream>

int main() {

  int n;
  std::cin >> n;

  if (n < 0) {
    std::cout << "Error: number cannot be negative!";
    return -1;
  }

  unsigned int sum = 0;  // additive identity
  for (unsigned int i = 1; i <= n; ++i) {
    sum += i;
  }

  std::cout << "The sum of the first " << n 
            << " numbers is: " << sum << std::endl;

  /*
  The above really is just an arithmetic progression 
  with a common difference of 1; we could've just written:
  */
  unsigned int sumAP = n * (n+1) / 2;

  std::cout << "The sum of the first " << n
            << " numbers using the formula for an arithmetic progression is "
            << sumAP << std::endl; 

  return 0;
}