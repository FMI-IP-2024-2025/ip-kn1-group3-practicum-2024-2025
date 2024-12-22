#include <iostream>

int dominant(int a[], int n)
{
    int maxCount = 0;
    int counter = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i-1])
        {
            counter++;
        }
        else
        {
            maxCount = maxCount > counter ? maxCount : counter;
            counter = 1;
        }
    }
    maxCount = maxCount > counter ? maxCount : counter;
    return maxCount;

}
int main()
{
   int a[]={0,1,1,1,2,2,7};
   int n = 7;
   std::cout << dominant(a, n) << std::endl; 
}