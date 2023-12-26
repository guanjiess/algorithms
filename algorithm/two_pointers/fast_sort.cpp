#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <time.h>
using namespace std;

int partition(int a[], int left, int right)
{
    int temp = a[left];
    //left < right的条件表明left和right没有相遇·
    while (left < right) {
        while (left < right && a[right] > temp) right --;
        a[left] = a[right];
        while (left < right && a[left] <= temp) left ++; 
        a[right] = a[left]; 
    }
    a[left] = temp;
    return left;
}

void quick_sort(int a[], int left, int right)
{
    if(left < right){
        int pos = partition(a, left, right);
        if(pos > left) quick_sort(a, left, pos-1);
        quick_sort(a, pos+1, right);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int a[11] = {3,1,9,11,2,8,16,23,231,-5,9};

    //int destination = partition(a, 0, 10);
    //for (int i = 0; i < 11; i++) {
    //    printf("%d ", a[i]);
    //}
    quick_sort(a, 0, 10);

    for (int i = 0; i < 11; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    //for (int i = 10; i > 0; i--) {
    //    printf("%d ",rand() % 10 + 5);
    //}
    return 0;
}