#include <iostream>
#include <random>

int main() {

  // randomises the number each time you run
  // the executable file
  srand(time(NULL));
  // 1-100
  int randomNumber = rand()%100 + 1;
  int guessNumber;
  std::cin >> guessNumber;

  while (guessNumber != randomNumber) {
    if (guessNumber < randomNumber) {
      std::cout << "Go higher!\n";
    }
    else {
      std::cout << "Go lower!\n";
    }
    std::cin >> guessNumber;
  }

  std::cout << "You've guessed correctly!";

  return 0;
}