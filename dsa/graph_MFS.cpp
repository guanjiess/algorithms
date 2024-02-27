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

// prim算法
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

// kruskal算法需要的子功能
const int MAXE = 999;
const int MAXV = 110;
struct edge{
    int u,v;
    int cost;
}E[MAXE];

void p_E(int size)
{
    for (int i = 0; i < size; i++){
        printf("edge_%d: %d<--->%d, %d\n",i, E[i].u, E[i].v, E[i].cost);
    }
}

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

int father[MAXV];
void set_father(int size)
{
    for (int i = 0; i < size; i++) {
        father[i] = i;
    }
}

void print_father(int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", father[i]);
    }
    printf("\n");
}

int find_father(int x)
{
    int ans = x;
    while (ans != father[ans]) {
        ans = father[ans];
    }

    // 路径压缩部分
    int y = x;
    while (y != father[y]) {
        int y_tmp = y;
        y = father[y_tmp];
        father[y_tmp] = ans;
    }
    return ans;
}

// 目的：给定边和边权，求得最小生成树，即找出n-1条边，使得这n-1条边在包括全部n个顶点，同时这n-1条边的权值之和是最小的
// kruskal算法的主要思想：将所有未选中的边按照边权从小到大排列，依次选出最短的边以使得总权值最小。
// 1、将所有未选中的边按照边权从小到大排列，并选出边权最小的边
// 2、如果这条边的两个顶点处在不同的连通块上，将这条边加入最小生成树中
// 3、处在相同的连通块上，该条边不予处理，回到步骤1
// 4、执行上述循环到最小生成树的边数为n-1为止
int kruskal(int n, int m)
{
    int ans = 0;
    int edge_num = 0;
    set_father(n);
    sort(E, E+m, cmp);
    //p_E(m);
    for (int i = 0; i < m; i++) {
        int father_u = find_father(E[i].u);
        int father_v = find_father(E[i].v);
        if (father_u != father_v){
            edge_num ++;
            ans += E[i].cost;
            // 关键的一点，合并连通块，即把二者的父节点统一
            father[father_v] = father_u;
            if (edge_num == n - 1) {
                break;
            }
        }
    }
    // 遍历完所有的边之后，如果树的边数没有达到n-1，说明错误
    if (edge_num != n-1) {
        return -1;
    }
    return ans;
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
        E[i].u = from, E[i].v = to;
        E[i].cost = test[i][2];
    }
    
    //for (int i = 0; i < m; i++) {
    //    for (int j = 0; j < m; j++) {
    //        printf("%d ", G[i][j]);
    //    }
    //    printf("\n");
    //}

    printf("----------> PRIM algorithm <------------\n\n");
    int min = prim(start, n);
    printf("MFS distance is : %d.\n\n", min);

    printf("----------> Kruskal algorithm <-----------\n");
    printf("---------test find father.\n");
    int size = 10;
    set_father(size);
    print_father(size);
    for (int i = 1; i < size; i++) {
        father[i] = i-1; 
    }
    print_father(size);
    find_father(5);
    print_father(size);
    printf("---------test edges.\n");
    p_E(size);

    printf("---------test kruskal.\n");
    int sum = kruskal(n, m);
    printf("Kruskal calculated answer is %d.\n", sum);

    return 0;
}