#include <iostream>
#include <cmath>

int main() {

  // in square metres
  double room1, room2, room3, room4, room5;
  std::cin >> room1 >> room2 >> room3 >> room4 >> room5;

  double pricePerPackage, materialPerPackage, installationPrice;
  std::cin >> pricePerPackage >> materialPerPackage >> installationPrice;

  double totalArea = room1+room2+room3+room4+room5;

  // we need to round up to make sure we have enough material
  unsigned int packagesNeeded = ceil(totalArea/materialPerPackage);

  double totalPrice = totalArea*installationPrice + packagesNeeded*pricePerPackage;

  std::cout << "Total packages needed: " << packagesNeeded << std::endl;
  // format price to 2 digits after decimal point
  std::cout << std::fixed << std::cout.precision(2);
  std::cout << "The total price is: " << totalPrice << std::endl;

  return 0;
}