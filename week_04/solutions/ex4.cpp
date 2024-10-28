#include <iostream>
#include <cmath>
#include <stdexcept>

unsigned int countDigitOccurences(int num, int targetDigit) {
  if (targetDigit >= 10 || targetDigit < 0) {
    throw std::invalid_argument("Error: Number is not a digit");
  }

  num = abs(num);
  unsigned int counter = 0;
  do {
    if (num%10 == targetDigit) counter++;
  } while (num/=10);

  return counter;
}

int main() {

  try {
    unsigned int occurences = countDigitOccurences(-440, 4);
    std::cout << occurences;
  }
  catch (std::exception const& e) {
    std::cout << e.what();
  }

  return 0;
}