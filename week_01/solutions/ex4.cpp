#include <iostream>
#include <cmath>

double const PI = 3.14;

int main() {

  // input validation is left as an exercise to the coder
  double cylinderRadius, cylinderHeight;
  double sphereRadius;
  std::cin >> cylinderRadius >> cylinderHeight >> sphereRadius;

  // generic mathematical formulae
  double cylinderVolume = PI * cylinderRadius * cylinderRadius * cylinderHeight;
  // since PI is of type double, the entire expression will
  // be converted into a double
  double sphereVolume = PI * pow(sphereRadius,3) * 4 / 3;

  /*
  here, we want to know the total amount of "whole" spheres we can
  put inside the cylinder - meaning we cannot "cut up" a sphere into parts
  and then put only some of them inside.
  */
  unsigned int totalNumberOfSpheres = floor((cylinderVolume/2) / sphereVolume);

  std::cout << "You can fit in a total of " << totalNumberOfSpheres
            << " spheres.";

  return 0;
}