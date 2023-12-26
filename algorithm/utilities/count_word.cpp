#include <stdio.h>
#include <iostream>
#include <cstring>
#include <utility>

const int MAXN = 10010;
const int MOD = 100000007;
char str[MAXN];
int leftNum[MAXN] = {0};

int main()
{
    int ans = 0;
    char source[MAXN];
    std::cin >> str;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (i == 0) 
            leftNum[i] = (int)(str[i]=='P');
        else
            leftNum[i] = leftNum[i-1] + (int)(str[i]=='P');
    }

    int rightNum = 0;
    for (int j = len - 1; j > 0; j--) {
        if (str[j] == 'T') {
            rightNum ++;
        }   
        if(str[j] == 'A'){
            ans += leftNum[j]*rightNum;
        } 
    } 
    printf("Total PAT number is: %d\n", ans);
    return 0;
}