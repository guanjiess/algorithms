#include<stdio.h>
int main(){
    int array[2][3] = {
        {0, 1, 2},
        {3, 4, 5}
    };
    printf("%p, %p, %p, %p\n", &array[0][0], &array[0][1], &array[0][2], &array[1][0]);
    return 0;
}