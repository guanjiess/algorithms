#include<stdio.h>
int b_search(int *arr, int len, int target){
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
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

int remove_v(int *arr, int len, int v){

    for(int i = 0; i < len; i++){
        if(arr[i] == v){
            for (int j = i + 1; j < len ; j++){
                arr[j-1] = arr[j];
            }
            len --;
            i --;

        }
    }

    return len;
}

int remove_v_pointers(int *arr, int len, int v){
    int fast = 0;
    int slow = 0;
    for(fast = 0; fast < len; fast ++){
        if(arr[fast] != v){
            arr[slow] = arr[fast];
            slow ++;
        }
    }
    return slow ;
}

int main(){
    int arr1[] = {-1, -1, -1, 0, 3, 5, 5, 9 ,12};
    int len1 = sizeof(arr1) / sizeof(int);
    int answer = b_search(arr1, len1, 9);
    printf("Binary search answer is: %d.\n", answer);
    int answer2 = remove_v(arr1, len1, -1);
    printf("Remove answer is: %d.\n", answer2);
    int answer3 = remove_v_pointers(arr1, len1, 5);
    printf("Remove_pointers answer is: %d.\n", answer3);
    /*int b[3] = {1, 2, 3};
    int k = 1;
    b[k++] = 4;
    printf("%d, %d, %d", b[0], b[1], b[2]);
    */
    return 0;
}