#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 999;
const int maxn = 100;
int G[maxn][maxn];

struct node{
    int v;
    int dis;
};

// 目的是求解最小生成树，minimum spanning tree, 即给定一个无向图结构，生成一棵包含
// 该图结构所有顶点的树，这个树的边均是无向图的边，且满足这些边权之和最短。
// 注意：树有n个顶点，则有n-1条边。
// prim算法的基本思想和Dijkstra算法一致，分两大步骤
// 0、定义一个集合S存储已访问的节点
// 1、每次都从未访问的节点中筛选出距离最近的节点k，将该节点标记为已访问后，开放所有与之相连的边
// 2、遍历与k相连的其余节点，观察以k为中间节点后，是否可以缩短与S的距离，如果可以，则更新
bool visited[maxn] = {false};
int dis[maxn];
int prim(int start, int size)
{
    fill(&visited[0], &visited[0] + size, false);
    fill(&dis[0], &dis[0] + size, INF); 
    int answer = 0;
    dis[start] = 0;
    for (int i = 0; i < size; i++) {
        int min_idx = -1, min = INF;
        //从未访问节点中筛选出距离S最短的节点
        for (int u = 0; u < size; u++) {
            if (!visited[u] && dis[u] < min){
                min = dis[u];
                min_idx = u;
            }
        }
        if (min_idx == -1) {
            return -1;
        }
        visited[min_idx] = true;
        answer += dis[min_idx];
        // 更新
        for (int v = 0; v < size; v++) {
            if (!visited[v] && G[min_idx][v] != INF) {
                //和Dijkstra最大差别在这里，Dijkstra算法评判的标准是节点和源点的距离--以筛选出的节点为中间点，距离源点的距离
                //也就是d[u] + G[u][v]；而prim算法的筛选标准是距离集合的距离，就是G[u][v]
                if (G[min_idx][v] < dis[v]) {
                    dis[v] = G[min_idx][v];
                }
            }
        }
    }
    return answer;
}

int test[10][3] = {{0,1,4}, {0,4,1}, {0,5,2}, {1,2,6}, {1,5,3},
                   {2,3,5}, {2,5,5}, {3,4,4}, {3,5,5}, {4,5,3}};

int main()
{
    int n = 6, m = 10, start = 0;
    fill(&G[0][0], &G[0][0]+maxn*maxn, INF);
    for (int i = 0; i < m; i++) {
        int from = test[i][0], to = test[i][1];
        G[from][to] = G[to][from] = test[i][2];
    }
    
    //for (int i = 0; i < m; i++) {
    //    for (int j = 0; j < m; j++) {
    //        printf("%d ", G[i][j]);
    //    }
    //    printf("\n");
    //}

    int min = prim(start, n);
    printf("MFS distance is : %d.\n", min);

    return 0;
}