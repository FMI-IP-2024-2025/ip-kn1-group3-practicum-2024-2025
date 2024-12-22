#include <iostream>

bool limits(int a[], unsigned na, int b[], unsigned nb)
{
    int* countArray = new int[na];
    for(int i = 0; i < nb; i++)
    {
        if(b[i] < na && b[i] >= 0)
        {
            countArray[b[i]]++;
        }
    }
    bool result = true;
    for(int i = 0; i < na; i++)
    {
        result = result && countArray[i] >= a[i];
    }
    return result;
}
int main()
{
    //int a[]={0,1,2}, na = 3, b[]={1,1,2}, nb = 3;
    int a[]={2,1,0}, na = 3, b[]={0,1,0}, nb = 3;
    std::cout << std::boolalpha << limits(a, na, b, nb) << std::endl;
}