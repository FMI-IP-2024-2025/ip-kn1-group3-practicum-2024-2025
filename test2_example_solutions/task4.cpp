#include <iostream>

bool mirror(int a[][5])
{
    bool result = false;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            bool isMirror = true;
            for(int c = 0; c < 5; c++)
            {
                isMirror = isMirror && a[i][c] == a[j][4 - c];
            }
            result = result || isMirror;
        }
    }
    return result;
}
int main()
{
    int matrix[][5] = {
        {1, 2, 1, 2, 1},
        {1, 2, 3, 4, 5},
        {0, 0, 0, 0, 0},
        {5, 4, 3, 2, 1},
        {3, 6, 3, 6, 3}
    };
    std::cout << std::boolalpha << mirror(matrix);
}