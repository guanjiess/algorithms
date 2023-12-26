#include<cstdio>

int factorial(int n)
{
    if(n == 0) 
        return 1;
    else 
        //return 2;
        return factorial(n - 1) * n;
}

int main()
{
    int count = 10;
    for (int i = 0; i < count; i++)
    {
        int k = factorial(i);
        printf("%d\n", k); 
    }

    return 0;
    
}