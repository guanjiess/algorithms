#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <vector>
using namespace std;

// to find the optimal combination
// within the limits of total weight tw
// given the weight and value of the goods.
void DFS(int n, int weights[], int value[], int index, int limit_w, int total_w, int total_v, int* maxv)
{
    if (index == n) {
        return;
    }
    DFS(n, weights, value, index + 1, limit_w, total_w, total_v, maxv);
    if(total_w + weights[index] <= limit_w){
        if (value[index] + total_v > *maxv) {
            *maxv = value[index] + total_v;
        }
        int new_value = total_v + value[index];
        int new_weight = total_w + weights[index];
        DFS(n, weights, value, index + 1, limit_w, new_weight, new_value, maxv);
    }
}

void test_DFS()
{
    int n, capacity;
    while (scanf("%d%d", &n, &capacity), n != 0){
        int* weight = (int*)malloc(n*sizeof(int));
        int* value = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", weight+i);
        }
        for (int i = 0; i < n; i ++) {
            scanf("%d", value+i);
        }
        int* max_value = (int*)malloc(sizeof(int));
        DFS(n, weight, value, 0, capacity, 0, 0, max_value);
        printf("%d\n", *max_value);
        free(max_value);
        free(weight);
        free(value);
    }
}

// find n numbers in src that sum target.
// if there are multiple choice, return the one with the largest square sum.
// use DFS method
const int maxn = 10010;
int maxSqu = -1;
int N, k, target, src[maxn];
vector<int> temp, ans;
void DFS_k(int index, int nowK, int sum, int sumSqu)
{
    // base case, k numbers in temp and sum x.
    if (nowK == k && sum == target) {
        if(sumSqu > maxSqu){
            ans = temp;
            maxSqu = sumSqu;
        }
        return;
    }
    // overflow 
    if (index == N || nowK > k || sum > target) {
        return;
    }
    
    // in normal case, we have 2 situations
    // push index-th item into temp
    // or not push it.
    temp.push_back(src[index]);
    DFS_k(index+1, nowK+1, sum+src[index], sumSqu+src[index]*src[index]);
    temp.pop_back();
    DFS_k(index+1, nowK, sum, sumSqu);

}

int main()
{
    while (scanf("%d %d %d", &target , &N, &k), target != 0) {
        for (int i = 0; i < N; i ++) {
            scanf("%d", src+i);
        }
        printf("src is: ");
        for (int i = 0; i < N; i ++) {
            printf("%d ", src[i]);
        }
        printf("\n");
        
        DFS_k(0, 0, 0, 0);
        vector<int>::iterator it;
        for (it = ans.begin(); it != ans.end(); it++) {
            printf("%d ", *it);
        }
        printf("over\n");

    }

    return 0;
}