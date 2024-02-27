#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100;

// 用动态规划的思想实现斐波那契数列
// dp1保存斐波那契数列计算结果，如果4
int dp1[maxn] = {0};
int fib(int n)
{
    if (n == 0 | n == 1) {
        return 1;
    }
    // dp1[n]=-1，说明已经计算过fib(n)，直接返回计算结果
    if (dp1[n] != -1) {
        return dp1[n];
    } else {
        dp1[n] = fib(n-1) + fib(n-2);
        return dp1[n];
    }
}

// 问题描述：给定n行数字，第一行1个数字，第二行2个...，从第一层走到第n层的过程中，
// 每次只能走向下一层连接的两个数字中的一个，求路径上所有数字的和最大是多少
// 思路分析：对于数据G[i][j]来说，它需要进行一次二选一的决策，dp2[i][j]的选择依据是：
// max(dp2[i+1][j], dp2[i+1][j+1])，由此操作可以得到最大的和，因此我们需要进一步求解子问题
// dp2[i+1][j]和dp2[i+1][j+1]，如果我们自底向上地对每个节点进行操作更新，那么只需要O(n)的复杂度
// 即可计算出所有节点出发时得到的最大值。
int dp2[maxn][maxn];
int num_tower(int** G, int n)
{
    for (int i = 0; i < n; i++) {
        dp2[n-1][i] = G[n-1][i];
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int left = dp2[i+1][j] + G[i][j];
            int right = dp2[i+1][j+1] + G[i][j];
            dp2[i][j] = max(left, right);
        }
    }
    return dp2[0][0];
}


// 求解最大连续子序列的和：给定一个序列A，求序列A最大的连续子序列和
// 思路：设dp数组存放中间结果，dp[i]表示以A[i]为末尾的子序列的最大序列和，同样采用自底向上的思想，
// 以A[i]为末尾的子序列有两种情况
// 1、序列长度为1；dp[i] = A[i]
// 2、序列长度大于1；dp[i] = A[i] + dp[i-1]
// 综合结果可表示为：max{A[i], A[i]+dp[i-1]}
int dp3[maxn];
int A[maxn]; 
int max_continuous_sequence(int* A, int size)
{
    //初始化设置，其和一定为A[0]
    dp3[0] = A[0];

    for (int i = 1; i < size; i++) {
        int dp_new = A[i] + dp3[i-1];
        dp3[i] = max(dp_new,A[i]);        
    }

    //从dp3从筛选出最大的结果
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (dp3[index] < dp3[i]) {
            index = i;
        }
    }
    return dp3[index];
}

void init_dp()
{
    fill(dp1, dp1+maxn, -1);
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            dp2[i][j] = 0;
        }
    }
}

int test_num[5][5] = {{5,0,0,0,0}, {8,3,0,0,0}, {12,7,16,0,0}, 
                      {4,10,11,6,0}, {9,5,3,9,4}};

int test_A[6] = {-2,11,-4,13,-5,-2};

int main()
{
    init_dp();
    printf("-----------Fibonacci-----------\n");
    int fib5 = fib(5);
    printf("%d\n", fib5);
    printf("-----------NUM TOWER-----------\n");
    int n = 5;
    int **G = new int*[n];
    for (int i = 0; i < n; i++) {
        G[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            G[i][j] = test_num[i][j];    
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    int max_path = num_tower(G, n);
    printf("Max path value is:%d\n", max_path);    
    
    printf("-----------CONTIUOUS SUM-----------\n");
    int size = 6;
    for (int i = 0; i < size; i++) {
        A[i] = test_A[i];
    }
    int max_sum = max_continuous_sequence(A, size);
    printf("Max sum for A is: %d\n", max_sum);

    for (int i = 0; i < n; i++) {
        delete [] G[i];
    }    
    delete [] G;
    return 0;
}