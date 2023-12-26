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
    int numbers[4] = {0};
    num_to_array(num, numbers);
    for (int i = 0; i < 4; i ++) {
        ans = ans*10 + numbers[i];
    }
    return ans;
}

int to_number(int numbers[])
{
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = ans*10 + numbers[i];       
    }
    return ans;
}

void black_hole(int number)
{
    int num2arr[4] = {0};
    num_to_array(number, num2arr);
    sort(num2arr, num2arr+4);    
    int small = to_number(num2arr);
    int big = reverse_num(small);
    
    if(big - small == 6174){
        printf("%d - %d = %d\n", big, small, 6174);
        return;
    } 
    else{
        int new_num = big - small;
        printf("%d - %d = %d\n", big, small, new_num);
        black_hole(new_num);
    }
}

int main()
{
    const int size = 10;
    int test_blackhole[size] = {4231, 7736, 6521, 9852, 9752, 8665, 7651, 8444, 6322, 5444};
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
        printf("\n");
    }
    return 0;
}