#include <cstdio>
#include <cmath>
using namespace std;

void sum_target(int a[], int len, int target)
{
    int i = 0, j = len - 1; 
    int count = 0;
    while (i < j)
    {
        if(a[i] + a[j] == target){
            count ++;
            printf("solution%d is: a[%d] = %d ,a[%d] = %d\n", count, i, a[i], j, a[j]);
            i ++;
            j --;
        } else if(a[i] + a[j] > target){
            j --;
        } else {
            i ++;
        } 
    } 
    if (!count) printf("no satisfactory condition\n");  
    else printf("total %d satisfactory conditions\n", count); 
}

// merge 2 arrays in a increasing order.
void merge_array(int a[], int len_a, int b[], int len_b)
{
    //int merged[len_a+len_b] = {0};
    int* merged = new int[len_a+len_b];
    int a_idx = 0, b_idx = 0;
    int m_idx = 0;
    while (a_idx < len_a && b_idx < len_b)
    {
       if(a[a_idx] <= b[b_idx]){
            merged[m_idx] = a[a_idx];
            m_idx ++;
            a_idx ++;
       } else {
            merged[m_idx] = b[b_idx];
            m_idx ++;
            b_idx ++;
       }
    }
    // merged[m_idx++] = a[a_idx++];
    while (a_idx < len_a)
    {
        merged[m_idx] = a[a_idx];
        a_idx ++;
        m_idx ++;
    }
    
    while (b_idx < len_b)
    {
        merged[m_idx] = b[b_idx];
        b_idx ++;
        m_idx ++;
    }
    
    int total_len = len_a + len_b; 
    for (int i = 0; i < total_len; i++)
    {
        printf("%d ", merged[i]);
        if(i == total_len - 1) printf("\n");
    }
}


int main()
{
    int a[10] = {1, 3, 4, 8, 9 ,10, 12, 13, 34, 89};
    int len = sizeof(a) / sizeof(int);
    sum_target(a, len, 11);

    int a1[5] = {1,3,5,7,9};
    int a2[5] = {2,4,6,8,10};
    merge_array(a1, 5, a2, 5);
 
    int a3[8] = {1,3,5,7,9, 12,342,1242};
    int a4[6] = {2,4,4,5,6,10};
    merge_array(a3, 8, a4, 6);
    
    int a5[2] = {1,3};
    int a6[7] = {1,2,4,6,8,13,15};
    merge_array(a5, 2, a6, 7);
    return 0;
}