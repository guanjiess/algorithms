//https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi-2/
#include <stdio.h>

void hanoi(int n,char from, char to, char aux)
{
    if(n == 1){
        printf("move disk 1: %c--->%c\n", from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    printf("move disk %d: %c--->%c\n",n , from, to);
    hanoi(n-1, aux, to, from);
}

int main()
{
    hanoi(3, 'a', 'c', 'b');
    return 0;
}
