#include <cstdio>
#include <cstring>
#include <cmath>

int factorial(int n)
{
    if(n == 0) 
        return 1;
    else 
        return factorial(n - 1) * n;
}


int fibonacci(int n)
{
    if(n == 0 || n == 1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

const int maxn = 11;
int sort[maxn];
bool hash_table[maxn] = {false};
void full_sort_recur(int index, int size)
{
    if(index == size + 1){
        for (int i = 1; i <= size; i++)
        {
            printf("%d ", sort[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= size; i++)
    {
        if(!hash_table[i]){
            sort[index] = i; 
            hash_table[i] = true;
            full_sort_recur(index+1, size);
            hash_table[i] = false;
        }       
    }
}

int queens_col[maxn];
bool col_status[maxn] = {false};
int count_queen = 0;
void n_queens(int row, int size)
{
    if(row == size + 1){
        bool is_valid = true;
        for (int col = 1; col <= size; col++)
        {
            for (int col2 = col+1; col2 <= size ; col2++)
            {
                if(abs(col - col2) == abs(queens_col[col] - queens_col[col2])){
                    is_valid = false;                  
                }
            } 
        }
        if( is_valid ) count_queen ++;
        return;
    }
    for(int col = 1; col <= size; col ++){
        if(!col_status[col]){
            queens_col[row] = col;
            col_status[col] = true;
            n_queens(row+1, size);
            col_status[col] = false;
        }
    }
}

void n_queens_pro(int row, int size)
{
    if(row == size + 1){
        count_queen ++;
        return;
    }
    for(int col = 1; col <= size; col ++){
        if(!col_status[col]){
            bool flag = true;
            for (int pre = 1; pre < row; pre++)
            {
               if(abs(pre - row) == abs(queens_col[pre] - queens_col[row])){
                    flag = false;
                    break;
               } 
            }

            if(flag){
                queens_col[row] = col;
                col_status[col] = true;
                n_queens(row+1, size);
                col_status[col] = false;
            }
        }
    }
}

int main()
{
    int count = 10;
    for (int i = 0; i < count; i++)
    {
        int k = factorial(i);
        printf("%d\n", k); 
    }

    for (int i = 0; i < count; i++)
    {
        int k = fibonacci(i);
        printf("%d\n", k); 
    }

    full_sort_recur(1, 3);

    for (int queens = 1; queens <= 10; queens++)
    {
        count_queen = 0;
        //n_queens(1, queens);
        n_queens_pro(1, queens);
        printf("queens of %d is %d\n", queens, count_queen);
    }
    
    return 0;

    
}