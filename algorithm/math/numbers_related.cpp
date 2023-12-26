#include <cstdio>
#include <cstring>

// Greatest common divisor
// recursion version
int GCD_r(int x, int y)
{
    if(y == 0) 
        return x;
    else
        return GCD_r(y, x%y);
}

// not recursion version
int GCD_nr(int x, int y)
{
    int gcd = 1;
    int remain = x % y;
    int temp = y;
    while ( y!= 0) {
        remain = x % y;
        x = y;
        y = remain;
    }
    return x;
}

int LCM(int a, int b)
{
    int gcd = GCD_r(a, b);
    return a / gcd * b;
}

int main()
{
    int test[10] = {2,4,3,18,5,-5,16,24,74,12};
    for (int i = 0; i < 10; i +=2) {
        int gcd = GCD_nr(test[i], test[i+1]);
        printf("gcd_nr of %d, %d is: %d\n", test[i], test[i+1], gcd);
    }

    for (int i = 0; i < 10; i +=2) {
        int lcm = LCM(test[i], test[i+1]);
        printf("lcm of %d, %d is: %d\n", test[i], test[i+1],lcm); 
    }

    return 0;
}