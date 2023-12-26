#include <stdio.h>
#include <algorithm>
using namespace std;

bool int_cmp(int a, int b){
    // a > b时，把a放在前面
    // C++的sort函数的 cmp选项，用于确定第一个参数是否要排在第二个参数之前
    return a > b;
}

bool char_cmp(char a, char b){
    return a > b;
}

int main()
{
    int a[6] = {9, 4, 2, 5, 6, 11};
    sort(a, a+6, int_cmp);
    for(int i = 0; i < 6; i ++){
        printf("%d ", a[i]);
        if(i == 5) printf("\n");
    }

    char b[] = "tesla";
    sort(b, b+5, int_cmp);
    for(int i = 0; i < 5; i ++){
        printf("%c", b[i]);
        if(i == 4) printf("\n");
    }

    return 0;
}
