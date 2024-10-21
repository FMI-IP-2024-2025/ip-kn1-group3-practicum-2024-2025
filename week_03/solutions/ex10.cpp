#include <iostream>
#include <cmath>
#include <cfloat>

int main() {

  // will format floating point numbers
  // to have 2 digits after floating point
  std::cout << std::fixed;
  std::cout.precision(2);

  // better to use integer values for comparison
  // try and see what happens if you don't :D
  unsigned int saltSticksPrice = 60;
  unsigned int proteinBarPrice = 290;
  unsigned int cocaColaPrice = 180;
  unsigned int sparklingWaterPrice = 50;

  // you can also use the variables above,
  // but i think it's neater if you write it this way
  std::cout << "1. Salt sticks      |  0.60lv\n"
            << "2. Protein bar      |  2.90lv\n"
            << "3. Coca Cola        |  1.80lv\n"
            << "4. Sparkling water  |  0.50lv\n";

  int product;
  std::cin >> product;

  unsigned int totalPrice = 0;
  switch (product) {
  case 1:
    totalPrice = saltSticksPrice; break;
  case 2:
    totalPrice = proteinBarPrice; break;
  case 3:
    totalPrice = cocaColaPrice; break;
  case 4:
    totalPrice = sparklingWaterPrice; break;
  default:
    std::cout << "We do not offer such a product, sorry.\n";
    return 0;
  }

  std::cout << "Your total is: " << totalPrice/100.0 << "lv.\n";

  double total;
  std::cin >> total;

  int change = total*100 - totalPrice;
  while (change < 0) {
    std::cout << "You need " << abs(change)/100.0 << " more lv.\n";
    std::cin >> total;
    change += total*100;
  }

  std::cout << "Your change is:\n";

  // vending machine can return 0.05 lv as its lowest value
  // if the user enters a number that is not a multiple of 5,
  // it's their own fault they got robbed :)
  while (change >= 5) {
    if (change >= 200) {
      change -= 200;
      std::cout << "2lv.\n";
    }
    else if (change >= 100) {
      change -= 100;
      std::cout << "1lv.\n";
    }
    else if (change >= 50) {
      change -= 50;
      std::cout << "0.50lv.\n";
    }
    else if (change >= 20) {
      change -= 20;
      std::cout << "0.20lv.\n"; 
    }
    else if (change >= 10) {
      change -= 10;
      std::cout << "0.10lv.\n";
    }
    else {
      change -= 5;
      std::cout << "0.05lv.\n";
    }
  }

  return 0;
}