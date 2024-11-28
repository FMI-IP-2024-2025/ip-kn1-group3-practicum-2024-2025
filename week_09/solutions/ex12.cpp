#include <iostream>

unsigned int const SIZE = 3;

//помощна функция, която рекурсивно намира
//най-малкия елемент на даден матричен ред
int minRow(int row[], int size) {
  if (size<=1) return row[size-1];
  return std::min(row[size-1], minRow(row, size-1));
}

//примитивна рекурсия
int sumOfMinRows(int matrix[][SIZE], int size) {
  if (size<=0) return 0;
  return minRow(matrix[size-1],SIZE) + sumOfMinRows(matrix,size-1);
}

//опашкова рекурсия
int helperSum(int matrix[][SIZE], int size, int res) {
  if (size<=0) return res;
  return helperSum(matrix,size-1,res+minRow(matrix[size-1],SIZE));
}

int tailSum(int matrix[][SIZE], int size) {
  return helperSum(matrix,size,0);
}

int main() {

  int matrix[SIZE][SIZE] = { {1,-10,-2}, {2,2,2}, {-13,14,0} };
  std::cout << sumOfMinRows(matrix,SIZE) << ' '
            << tailSum(matrix,SIZE);

  return 0;
}