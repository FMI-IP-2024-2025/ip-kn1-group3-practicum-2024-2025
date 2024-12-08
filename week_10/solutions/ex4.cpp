#include <iostream>
#include <cstdint>
//ще използваме std::min от <algorithm>.
//причината за това е, че в <utility>
//нямаме дефиниция на std::min, която да
//работи директно с инициализиращ списък -
//това значи, че трябва да пишем множество
//от вложени std::min, което е меко казано противно.
//в рамките на този курс не го използвайте за друго
//освен за тази функция
#include <algorithm>

unsigned int const M = 3;
unsigned int const N = 4;

bool isValidMove(int i, int j) {
  if (i < 0 || i >= M) return false;
  if (j < 0 || j >= N) return false;
  return true;
}

//1
unsigned int shortestPath(bool matrix[M][N], int startRow, int startCol,
int endRow, int endCol, unsigned int pathLength) {

  //UINT32_MAX ще бележи "безкрайност",
  //т.е. не съществува път от началната до крайната точки
  if (!isValidMove(startRow,startCol)) return UINT32_MAX;
  if (matrix[startRow][startCol] == 1) return UINT32_MAX;
  if (startRow==endRow && startCol==endCol) return pathLength+1;

  matrix[startRow][startCol] = true;
  //използваме std::min, която приема инициализиращ списък
  unsigned int shortest = std::min({
    shortestPath(matrix,startRow-1,startCol,endRow,endCol,pathLength+1),
    shortestPath(matrix,startRow,startCol+1,endRow,endCol,pathLength+1),
    shortestPath(matrix,startRow+1,startCol,endRow,endCol,pathLength+1),
    shortestPath(matrix,startRow,startCol-1,endRow,endCol,pathLength+1)
  });
  //ако не използвахме горната дефиниция, щяхме да имаме следното:
  /*
  unsigned int shortest = 
    std::min(shortestPath(matrix,startRow-1,startCol,endRow,endCol,pathLength+1),
      std::min(shortestPath(matrix,startRow,startCol+1,endRow,endCol,pathLength+1),
        std::min(shortestPath(matrix,startRow+1,startCol,endRow,endCol,pathLength+1),
                 shortestPath(matrix,startRow,startCol-1,endRow,endCol,pathLength+1))));
  */
  //което е крайно неприятно за четене

  matrix[startRow][startCol] = false;

  return shortest;
}

//2
unsigned int allPaths(bool matrix[M][N], int startRow, int startCol,
int endRow, int endCol) {

  if (!isValidMove(startRow,startCol)) return 0;
  if (matrix[startRow][startCol] == true) return 0;
  if (startRow==endRow && startCol==endCol) return 1;

  matrix[startRow][startCol] = true;
  int paths = allPaths(matrix,startRow-1,startCol,endRow,endCol) +
              allPaths(matrix,startRow,startCol+1,endRow,endCol) +
              allPaths(matrix,startRow+1,startCol,endRow,endCol) +
              allPaths(matrix,startRow,startCol-1,endRow,endCol);
  
  matrix[startRow][startCol] = false;

  return paths;
}

void print(int arr[], int size) {
  for (int i = 0; i < size; i+=2)
    std::cout << '(' << arr[i] << ',' << arr[i+1] << ')' << std::endl;
}

//3
void allPaths(bool matrix[][N], int startRow, int startCol,
int endRow, int endCol, int path[], int index) {

  if (!isValidMove(startRow,startCol)) return;
  if (matrix[startRow][startCol]) return;

  //path е буфер, в който записваме позициите, през които
  //сме преминали. ако достигнем крайната точка,
  //принтираме този път
  path[index] = startRow, path[index+1] = startCol;
  if (startRow==endRow && startCol==endCol) {
    print(path,index+2);
    std::cout << std::endl;
    return;
  }

  matrix[startRow][startCol] = true;
  allPaths(matrix,startRow-1,startCol,endRow,endCol,path,index+2);
  allPaths(matrix,startRow,startCol+1,endRow,endCol,path,index+2);
  allPaths(matrix,startRow+1,startCol,endRow,endCol,path,index+2);
  allPaths(matrix,startRow,startCol-1,endRow,endCol,path,index+2);
  matrix[startRow][startCol] = false;
}

int main() {

  bool matrix[M][N] = { {0,1,1,0},
                        {0,1,0,0},
                        {0,0,0,0} };

  //всъщност пътят не може да бъде по-дълъг от
  //M*N-1, тъй като тогава бихме имали цикъл в пътя,
  //което би означавало, че имаме разстояние 0 от
  //началаната до крайната точки. умножаваме по 2, защото
  //искаме за всяка позиция да пазим по две координати
  int path[2*M*N];

  std::cout << shortestPath(matrix,0,0,0,3,UINT32_MAX) << std::endl;
  std::cout << allPaths(matrix,0,0,0,3) << std::endl;
  allPaths(matrix,0,0,0,3,path,0);

  return 0;
}