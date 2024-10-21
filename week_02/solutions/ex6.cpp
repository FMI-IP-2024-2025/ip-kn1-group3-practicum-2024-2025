#include <iostream>

int main() {

  int n;
  std::cin >> n;

  // make sure n is positive,
  // otherwise we'll get a negative sum!
  if (n < 0) n *= -1;

  unsigned int sum = 0;

  do {
    sum += n%10;
  } while (n/=10);

  std::cout << "Sum of the number's digits: " << sum;

  return 0;
}