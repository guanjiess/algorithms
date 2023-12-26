#include <cstdio>
#include <cstring>
using namespace std;

int b_search_basic(int a[], int left, int right, int target)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if(a[mid] == target){
            return mid;
        } else if (a[mid] > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }  
    } 
    return -1;
}

// multiple entries can satisfy target result
// so interval is composed of a lower bound and a upper bound. 
// [lower, upper)
int lower_bound(int a[], int left, int right, int target)
{
    int mid;
    //we assume there exists at least 1 target
    //if we reach the condition of left = right, that means
    //we arrived at the first element which satisfy the condition.
    //so return left
    while(left < right){
        mid = (left + right) / 2;
        if(a[mid] >= target){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int upper_bound(int a[], int left, int right, int target)
{
    int mid;
    //we assume such a target exists
    while(left < right){
        mid = (left + right) / 2;
        if(a[mid] > target){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    int a[10] = {1,3,7,8,10,11,12,15,19,23};
    int len = 10;
    int search;
    // these few lines are used to test basic case. 
    //while(scanf("%d", &search), search != 99){
    //    printf("index for %d in array:%d\n", search, b_search_basic(a, 0, len-1, search));
    //}

    int b[10] = {1,3,7,8,10,10,10,15,19,23};
    int search2 = 10;
    int lower = lower_bound(b, 0, len-1, search2);
    int upper = upper_bound(b, 0, len-1, search2);
    printf("lower bound of %d is %d , upper bound is %d.", search2, lower, upper );

    return 0;
}