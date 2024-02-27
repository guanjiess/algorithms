#include<stdio.h>

void select_sort(int *src, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        int index = i;
        for (size_t j = i+1; j < size; j++){
           if(src[index] > src[j]){
                index =  j;
               // min = src[j];
           } 
        }
        int min = src[index];
        src[index] = src[i];
        src[i] = min;
    }
}

void insert_sort(int *src, int size)
{
    //index 0~size-1
    //need size-1 round 
    for(int i = 1; i < size; i++){
        // temp为待插入的值
        int j = i;
        int temp = src[i];

        //把src[i]插入到前i-1个数中，共有i个数，所以j从i开始递减
        //由j-1赋值到j，不会对j-1的值产生覆盖，所以该流程可以持续进行
        //直到temp > a[j]
        while(j >= 1 && src[j-1] > temp){
            src[j] = src[j-1];
            j --;
        }
        src[j] = temp;
    }
}

int main(){
    int src[] = {4, 3, 2, 9, 12, 15, 7, 11, 6, 89};
    int len = sizeof(src) / sizeof(int);
    printf("%d\n", len);

    select_sort(src, 10);
    printf("select sort:");
    for (int i = 0; i < len; i++){
        printf("%d ", src[i]);
        if(i == len-1) printf("\n");       
    }
    
    int src11[] = {4, 3, 2, 9, 12, 15, 7, 11, 6, 89};
    int len11 = sizeof(src11) / sizeof(int);
    insert_sort(src11, len11);
    printf("insert sort:");
    for (int i = 0; i < len11; i++){
        printf("%d ", src11[i]);
        if(i == len11-1) printf("\n");       
    }
    
    
    int src2[] = {1, 4, 3, 2, 5, 6};
    int len2 = sizeof(src2) / sizeof(int);
    insert_sort(src2, len2);

    printf("insert sort:");
    for (int i = 0; i < len2; i++){
        printf("%d ", src2[i]);
        if(i == len2-1) printf("\n");       
    }
    
    return 0;    
}