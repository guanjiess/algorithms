#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;

const int maxn = 99;
const int INF = 999;
int dis[maxn][maxn];

// Floyd算法的核心思想是：如果以某个节点k为中间节点，可以使得节点i和节点j的距离变短
// 那么则用这个以k为中间节点的距离替换原有距离，需要三重循环，外层循环为中间节点，内层
// 的两层循环为ij间距
void Floyd(int size)
{
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j]; 
                }
            }
        }
    }    
}

int test_nodes_num = 6;
int test_edges_num = 8;
int test_start = 0;
int test_edges[8][3]= {
    {0,1,1},{0,3,4},{0,4,4},{1,3,2},
    {2,5,1},{3,2,2},{3,4,3},{4,5,4}
};

int main()
{
    //printf("%ld\n", sizeof(dis)/sizeof(int));
    int n = test_nodes_num, m = test_edges_num;
    fill(&dis[0][0], &dis[0][0] + sizeof(dis)/sizeof(int), INF);
    for (int i = 0;  i < n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u = test_edges[i][0];
        int v = test_edges[i][1];
        dis[u][v] = test_edges[i][2];
    }
    Floyd(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    
    //for (int i = 0; i < n; i++) {
    //    delete [] dis[i];
    //}
    //delete [] dis; 
    return 0;
}