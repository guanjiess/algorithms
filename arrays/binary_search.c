#include<stdio.h>
int b_search(int *arr, int len, int target){
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        printf("%d\n", mid);
        //if(arr[mid])
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] > target){
            right = mid - 1;
        } else if (arr[mid] < target)
        {
            left = mid + 1; 
        }
    }
    
    return -1;
}

int lower_bound(int *arr, int left, int right, int target){
    int mid;

    while(left < mid){
    	mid = (left + right) / 2;
	if(arr[mid] >= target){
	    right = mid;
	} else{
	    left = mid + 1; 
	}
    }
    return left;
}


int upper_bound(int *arr, int left, int right, int target){
    int mid;

    while(left < mid){
    	mid = (left + right) / 2;
	if(arr[mid] > target){
	    right = mid;
	} else{
	    left = mid + 1; 
	}
    }
    return left;
}


int main(){
    int arr1[] = {-1, 0, 3, 5, 9 ,12};
    int len1 = sizeof(arr1) / sizeof(int);
    int answer = b_search(arr1, len1, 9);
    printf("Binary search answer is: %d.\n", answer);
    int arr2[] = {-1, 0, 3,3,3,3, 5, 9 ,12};
    int len2 = sizeof(arr2) / sizeof(int);
    int lowbound_3 = lower_bound(arr2, 0, len2, 3);
    int upperbound_3 = upper_bound(arr2, 0, len2, 3);
    printf("lower: %d, upper: %d\n", lowbound_3, upperbound_3);
    return 0;
}
