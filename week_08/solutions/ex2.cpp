#include <iostream>

unsigned int const M = 3;
unsigned int const N = 3;

int main() {

  int n;
  std::cin >> n;
  int matrix[M][N] = { {1,2,3},
                       {4,5,6},
                       {7,8,9} };

  int x = -1, y = -1;
  for (unsigned int i = 0; i < M; ++i) {
    bool found = false;
    for (unsigned int j = 0; j < N; ++j) {
      if (matrix[i][j] == n) {
        x = j;
        y = i;
        found = true;
        break;
      }
    }
    if (found) break; 
  }

  std::cout << '(' << x << ',' << y << ')';

  return 0;
}