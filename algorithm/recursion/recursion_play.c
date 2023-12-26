#include <stdio.h>
#include <stdbool.h>

const int MAX = 11;

void traverse(int index, int size, int* output, bool* num_status)
{
    if(index == size + 1){
        for (int i = 1; i <= size; i++)
        {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
        
    }
    for (int i = 1; i <= size; i++){
        if(!num_status[i]){
            output[index] = i;
            num_status[i] = true;
            traverse(index+1, size, output, num_status);
            num_status[i] = false;
        }
    }
    
}

int main()
{
    int output[100];
    bool num_status[100] = {false};
    int size = 3;
    traverse(1, size, output, num_status);
    return 0;
}