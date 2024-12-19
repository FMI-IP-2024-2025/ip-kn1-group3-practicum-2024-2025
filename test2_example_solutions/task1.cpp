#include <iostream>
#include <cstring>
#include <climits>

int maxNumberIn(char* str)
{
    int len = strlen(str);
    int tmp = 0;
    int maxNumber = INT_MIN;
    for(int i = 0; i < len; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            tmp = tmp*10 + str[i] - '0';
        }
        else
        {
            maxNumber = maxNumber > tmp ? maxNumber : tmp;
            tmp = 0;
        }
    }
    maxNumber = maxNumber > tmp ? maxNumber : tmp;
    return maxNumber;
}
/*

019 99 3

19
*/


int main()
{
    char str[] = "019 99 3";
    std::cout << maxNumberIn(str);
}