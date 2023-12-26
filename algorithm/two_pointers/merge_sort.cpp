#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// merge 2 arrays in a increasing order.
void merge_array(int a[], int L1, int R1, int L2, int R2)
{
    int merge_len = R2 - L1 + 1;
    //int merged[merge_len] = {0};
    int* merged = new int[merge_len];
    int a_idx = L1, b_idx = L2;
    int m_idx = 0;
    while (a_idx <= R1 && b_idx <= R2)
    {
       if(a[a_idx] <= a[b_idx]){
            merged[m_idx] = a[a_idx];
            m_idx ++;
            a_idx ++;
       } else {
            merged[m_idx] = a[b_idx];
            m_idx ++;
            b_idx ++;
       }
    }
    // merged[m_idx++] = a[a_idx++];
    while (a_idx <= R1)
    {
        merged[m_idx] = a[a_idx];
        a_idx ++;
        m_idx ++;
    }
    
    while (b_idx <= R2)
    {
        merged[m_idx] = a[b_idx];
        b_idx ++;
        m_idx ++;
    }
    
    for (int i = 0; i < merge_len; i++)
    {
        a[L1+i] = merged[i];
        //printf("%d ", merged[i]);
        //if(i == merge_len - 1) printf("\n");
    }
    delete [] merged; 
}

// 遗留问题 core dump, segmentation error.
void merge_sort_r(int a[], int left, int right)
{
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort_r(a, left, mid);
        merge_sort_r(a, mid+1, right);
        merge_array(a, left, mid, mid+1, right);
    }
}

void merge_sort_nr(int a[], int len)
{   
    //以不同的分段长度进行操作
    for(int seg_len = 2; seg_len/2 <= len; seg_len *=2){
        //对每一段分别归并排序
        for(int i = 0; i < len; i += seg_len){
            int mid = i + seg_len/2 -1;
            if(mid + 1 <= len){
                merge_array(a, i, mid, mid+1, min(i+seg_len-1, len-1));
            }
        }
    }
}

int main()
{
    int a[14] = {1,3,5,7,9, 12,342,1242,2,4,4,5,6,10};
    int len = sizeof(a) / sizeof(int);
    merge_array(a, 0, 7, 8,13);
    
    for (int i = 0; i < 14; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    int c[7] = {66, 12, 33, 57, 64, 27, 18};
    int b[7] = {66, 12, 33, 57, 64, 27, 18};
    //merge_sort_r(b, 0, 6);
    merge_sort_nr(b, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    
    merge_sort_r(c, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}