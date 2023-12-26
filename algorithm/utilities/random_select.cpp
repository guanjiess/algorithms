#include <cstdio>
#include <cstdlib>
#include <ctime> 
#include <algorithm>
#include <type_traits>
using namespace std;


int rand_partition(int a[], int left, int right)
{ 
    srand((unsigned)time(NULL));     
    int p = rand() % (right - left) + left + 1; 
    swap(a[left], a[p]);

    int temp = a[left];
    while (left < right) {
        while (a[left] > temp && left < right) {
            left ++;
        }
        while (a[right] <= temp && left < right) {
            right --;
        }
    }
    a[left] = temp;

    return left;
}

void rand_select(int a[], int left, int right, int K)
{
    if(left == right) return;
    int p = rand_partition(a, left, right);

    int M = p - left + 1;
    if(M == K) return;
    if(K < M){
        rand_select(a, left, M - 1, K);
    } else {
        rand_select(a, M + 1, right, K-M); 
    }
}

int main()
{
    srand((unsigned)time(NULL));     
    int a[13] = {1,6,33,18,4,0,10,5,12,7,2,9,3};
    int len = sizeof(a) / sizeof(int);

    return 0;
}