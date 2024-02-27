#include <stdio.h>
int* toQsystem(int x, int Q){
    int* z;
    int num = 0;
    do{
        z[num] = x % Q;
        x = x / Q;
    }while(x != 0);
    return z;
}

int Q2decimal(int x, int Q){
    int y = 0;
    int product = 1;
    while (x != 0)
    {
        y = y + (x % 10) * product;
        x = x / 10;
        product = product * Q;
    }

    return y;
}

int main(){
    // transform a P-system to decimal 
    int y = 0;
    int Q = 2;
    int x = 10110;
    y = Q2decimal(10110, Q);
    printf("Number system is :%d, input number is %d, output is: %d\n", Q, x, y);
    return 0;
}