#include <iostream>
#include <cmath>

int main() {

  double cabbage_x, cabbage_y;
  double room1_x, room1_y;
  double room2_x, room2_y;
  double room3_x, room3_y;
  double room4_x, room4_y;
  double room5_x, room5_y;

  std::cin >> cabbage_x >> cabbage_y;
  std::cin >> room1_x >> room1_y;
  std::cin >> room2_x >> room2_y;
  std::cin >> room3_x >> room3_y;
  std::cin >> room4_x >> room4_y;
  std::cin >> room5_x >> room5_y;

  double minDistance, maxDistance;
  // assume the first distance will be the max and min
  maxDistance = minDistance = sqrt(pow(room1_x-cabbage_x,2)
                                   +pow(room1_y-cabbage_y,2));
                                  
  double dist2 = sqrt(pow(room2_x-cabbage_x,2)+pow(room2_y-cabbage_y,2));
  double dist3 = sqrt(pow(room3_x-cabbage_x,2)+pow(room3_y-cabbage_y,2));
  double dist4 = sqrt(pow(room4_x-cabbage_x,2)+pow(room4_y-cabbage_y,2));
  double dist5 = sqrt(pow(room5_x-cabbage_x,2)+pow(room5_y-cabbage_y,2));
  
  /*
  you can also omit {} when the body of an if-statement
  consists of only one expression 
  */
  if (dist2 > maxDistance) maxDistance = dist2;
  if (dist3 > maxDistance) maxDistance = dist3;
  if (dist4 > maxDistance) maxDistance = dist4;
  if (dist5 > maxDistance) maxDistance = dist5;

  if (dist2 < minDistance) minDistance = dist2;
  if (dist3 < minDistance) minDistance = dist3;
  if (dist4 < minDistance) minDistance = dist4;
  if (dist5 < minDistance) minDistance = dist5;

  // note we couldn't have used else if statements above

  std::cout << "Minimum distance: " << minDistance << '\n';
  std::cout << "Maximum distance: " << maxDistance << '\n';

  return 0;
}