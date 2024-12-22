#include <iostream>
#include <cmath>
//алтернативно, бихме могли ние сами да си дефинираме
//някакво достатъчно малко епсилон
#include <float.h>

unsigned int const SIZE = 5;

//ако искаме да използваме числа с плаваща запетая
bool linear(unsigned int const matrix[][SIZE]) {
  for (unsigned int i = 0; i < SIZE; ++i) {
    for (unsigned int j = i+1; j < SIZE; ++j) {

      bool isLinearCombination = true;
      double k = static_cast<double>(matrix[i][0]) / matrix[j][0];

      for (unsigned int l = 1; l < SIZE; ++l) {
        if (std::abs(matrix[j][l]*k - matrix[i][l]) > DBL_EPSILON) {
          isLinearCombination = false;
          break;
        }
      }

      if (isLinearCombination) return true;
    }
  } 
  return false;
}

//можем и да избегнем работата с числата с плаваща запетая по следния начин
//(това работи единствено защото числата са цели - тогава ни е гарантирано,
//че и скаларният коефициент ще е цяло число за някои два реда)
bool linear2(unsigned int const matrix[][SIZE]) {
  for (unsigned int i = 0; i < SIZE; ++i) {
    //за всеки ред matrix[i] искаме да проверим всички останали редове
    //matrix[j], 0 <= j <= SIZE-1
    for (unsigned int j = 0; j < SIZE; ++j) {

      //не искаме да проверяваме дали един и същи ред
      //е линейна комбинация на себе си, тъй като
      //това е тривиално вярно
      if (i==j) continue;

      bool isLinearCombination = true;
      unsigned int k = matrix[i][0] / matrix[j][0];

      for (unsigned int l = 1; l < SIZE; ++l) {
        if (matrix[j][l]*k != matrix[i][l]) {
          isLinearCombination = false;
          break;
        }
      }

      if (isLinearCombination) return true;
    }
  } 
  return false;
}

int main() {

  unsigned int const matrix[SIZE][SIZE]
  = { {1,2,1,2,1},
      {1,2,3,4,5},
      {1,1,1,1,1},
      {5,4,3,2,1},
      {3,6,3,6,3} };

  std::cout << std::boolalpha;
  std::cout << linear2(matrix);

  return 0;
}