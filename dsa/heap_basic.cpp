#include <cstdio>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <type_traits>
using namespace std;


void heap_init(int n, int *heap)
{
    for (int i = 0; i <= n; i ++) {
        heap[i] = 0;
    }
}

void print_heap(int n, int* heap)
{
    int layers = ceil(log2((double)n));
    printf("===========>This heap has %d layers.\n",layers);
    for (int layer_i = 1; layer_i <= layers; layer_i++) {
        int begin = pow(2, layer_i-1);
        int end = pow(2,layer_i)-1;
        for (int i = begin; i <= end; i ++) {
            for (int i = 0; i < layer_i; i++) {
                printf(" ");
            }            
            if (i <= n) {
                printf("%d\n", heap[i]);
            } else {
                break;
            }
        }
    }
    printf("\n");
}

// adjust element in a top-down order.
// for node i, 2i is left child, 2i+1 is right child.
// low is the node to be adjusted, usually high is set to be total number 
void adjustDown(int low, int high, int* heap)
{
    int i = low;
    int j = i * 2;
    while (j <= high) {
        //对比左右孩子，选中二者中较大的值
        if (j+1 <= high && heap[j+1] > heap[j]) {
            j = j + 1;
        }
        if (heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

void create_heap(int n, int* heap)
{
    for (int i = n/2; i >= 1; i--){
        adjustDown(i, n, heap);
    }
}

// 这里默认已经插入的堆是有序的，对heap数组在[low, high]范围内向上调整
// low 一般设置为1，high为打算调整的数组下标
void adjustHigh(int low, int high, int* heap)
{
    int i = high;
    int j = i / 2;
    while (i >= low) {
        if(heap[j] < heap[i] && j >= low){
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        } else {
            break;
        }
    }
}

void insert(int x, int* heap, int &n)
{
    n ++;
    heap[n] = x;
    adjustHigh(1, n, heap);
}

void deleteTop(int* heap, int &n)
{
    heap[1] = heap[n];
    n --;
    adjustDown(1, n, heap);   
}

void heap_sort(int* heap, int size)
{
    for (int i = size; i >= 1; i--) {
        swap(heap[1], heap[i]);
        adjustDown(1, i-1, heap);
    }
}

int main()
{
    // 堆是一个满二叉树
    const int maxn = 1001;
    int heap[maxn];
    
    int a[5] = {10, 15, 20, 25, 30};
    int sequence[11] = {0,85,55,82,57,68,92,99,98,66,56};
    for (int i = 1; i <= 10; i++) {
        heap[i] = sequence[i];
    }   
    print_heap(10, heap);

    //adjustDown(1, 10, heap);
    create_heap(10, heap);
    print_heap(10, heap);

    int size = 10;
    insert(103, heap, size);
    printf("size is:%d\n", size);
    print_heap(size, heap);

    deleteTop(heap, size);
    printf("===========>after delete top, new heap is\n");
    print_heap(size, heap);

    heap_sort(heap, size);
    print_heap(size, heap);

    return 0;
}