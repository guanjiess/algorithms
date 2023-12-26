#include <cstdio>
#include <algorithm>
using namespace std;

void num_to_array(int x, int num[])
{
    for (int i = 0; i < 4; i++) {
        num[i] = x % 10;
        x = x / 10;
    }
}

int reverse_num(int num)
{
    int ans = 0;
    while (num / 10 != 0) {
       ans = ans*10 + num % 10;
       num = num / 10; 
    }
    ans = ans*10 + num;
    printf("%d\n", ans);
    return ans;
}

void black_hole(int number)
{
    int num2arr[4] = {0};
    num_to_array(number, num2arr);
    sort(num2arr, num2arr+4);    
    for (int i = 0; i < 4; i++) {
        printf("%d ", num2arr[i]);
    }
    printf("\n");
}

int main()
{
    const int size = 10;
    int test_blackhole[size] = {4321, 7766, 6521, 9852, 9752, 8665, 7651, 8444, 6322, 5444};
    //for (int i = 0; i < size; i ++) {
    //    reverse_num(test_blackhole[i]);    
    //}
    //printf("\n");

    // test num_to_array
    //for (int i = 0; i < size; i ++) {
    //    int num[4] = {0};
    //    num_to_array(test_blackhole[i], num);
    //}

    // test black hole
    for (int i = 0; i < size; i ++) {
        black_hole(test_blackhole[i]);    

    }
    return 0;
}