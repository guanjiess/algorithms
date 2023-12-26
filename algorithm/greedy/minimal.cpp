#include <cstdio>
#include <algorithm>
using namespace std;

//由输入的数字组成最小的数
void minimum_sort(int numbers[])
{

    bool number_used[10] = {false};
    sort(numbers, numbers+9);
    for (size_t i = 0; i < 10; i++)
    {
        if(numbers[i] != 0){
            printf("%d", numbers[i]);
            number_used[i] = true;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if(!number_used[i]) printf("%d", numbers[i]);
    }
    printf("\n");
}

void minimum_compose(int numbers[], int len)
{
    //int len = sizeof(numbers) / sizeof(int);
    for (int i = 1; i < len; i++)
    {
        if(numbers[i] > 0){
            printf("%d", i);
            numbers[i]--;
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < numbers[i]; j++)
        {
            printf("%d", i);
        }
    }
    printf("\n");
    
}



int main()
{
    int numbers[10] = {2,2,0,0,0,3,0,0,1,0};
    int len = sizeof(numbers) / sizeof(int);
    //for (int i = 0; i < 10; i++)
    //{
    //    scanf("%d", &(numbers[i]));
    //}
    //minimum_sort(numbers);
    minimum_compose(numbers, len);
    return 0;
}