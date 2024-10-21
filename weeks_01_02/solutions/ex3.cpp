#include <iostream>
#include <cmath>  // for using sqrt()

/* it is common practice to use all uppercase letters 
for const identifiers (const variable names);
global variables aren't always a good idea
(that's because when you have different translation
units, you might get clashing variable names,
you don't have to worry about it in this course),
but for small programs like this one, it's ok :)
*/
double const PI = 3.14;

int main() {

  double radius;
  double roomX, roomY;

  std::cin >> radius >> roomX >> roomY;

  // calculating the distance to the room starting from the point (0,0)
  double roomDistance = sqrt(roomX*roomX + roomY*roomY);
  
  if (radius >= roomDistance) {  
    std::cout << "Don't do it!";
  }
  else {
    std::cout << "Let's do it!";
  }

  return 0;
}