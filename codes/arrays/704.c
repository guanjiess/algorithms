#include <stdio.h>

int b_search(int *nums, int len, int target){
    int answer = 0;
    int left = 0;
    int right = len - 1;
    while(left <= right){
    	int mid = (left + right) / 2;
	if(nums[mid] == target){
	    return mid;
	} 
	if (nums[mid] > target){
	    right = mid - 1;
	} else{
	    left = mid + 1;
	}

    }
    return -1;
}

int main(){

    int a = 2;
    int b = 3;
    double c = (a + b) / 2;
    double d = (double)(a + b) / 2;
    int nums[10] = {0, 2, 4, 5, 6, 12, 31, 88, 7};
    int len = sizeof(nums) / sizeof(int);
    printf("%d\n", b_search(nums, len, 2));
    printf("%d\n", b_search(nums, len, 31));
    return 0;
}
