#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 999;
const int maxn = 25;
bool visited[maxn] = {false};
int cost_i[maxn] = {INF};
int dis[maxn] = {INF};
int pre[maxn] = {0};   
vector<int> pre_vec[maxn];
vector<int> path, temp_path;

void reset()
{
    for (int i = 0; i < maxn; i++) {
        cost_i[i] = INF;
        dis[i] = INF;
        pre[i] = i;
        pre_vec[i].clear();
        visited[i] = false;
    }
    path.clear();
    temp_path.clear();
}

void Dijkstra(int** G, int** cost, int node_num, bool* visited, int start, int dest)
{
    reset();
    cost_i[start] = 0;
    dis[start] = 0;
    pre[0] = start;
    for (int i = 0; i < node_num; i++) {
        int min_idx = -1;
        int min = INF;
        // 找到距起点最小的节点
        for (int v = 0; v < node_num; v++) {
            if (dis[v] < min && !visited[v]) {
                min_idx = v;
                min = dis[v];
            }
        }
        if (min_idx == -1) return;
        visited[min_idx] = true;
        for (int u = 0; u < node_num; u++) {
            // 先判断该节点是否可访问
            if(!visited[u] && G[min_idx][u] != INF){
                int dis_vu = dis[min_idx] + G[min_idx][u];
                int new_cost = cost[min_idx][u] + cost_i[min_idx];
                if (dis_vu < dis[u]) {
                    dis[u] = dis_vu;
                    pre[u] = min_idx;
                    cost_i[u] = new_cost;
                } else if (dis_vu == dis[u]) {
                    if (cost_i[u] > new_cost) {
                        pre[u] = min_idx;
                        cost_i[u] = new_cost;
                    }
                }
            }
        }
    }
    for (int i = 0 ; i < node_num; i++) {
        printf("%d ", dis[i]);
    }
    printf("\n");
    for (int i = 0 ; i < node_num; i++) {
        printf("%d ", pre[i]);
    }
    printf("\n%d\n", cost_i[dest]);
}

void DFS_path(int st, int ed)
{
    if (ed == st) {
        printf("%d ", ed);
        return;
    }
    DFS_path(st, pre[ed]);
    printf("%d ", ed);
}

// 用Dijkstra算法得到并保存所有的最短路径
// 如果从起点到终点有多种可能的最短路径，则将这些路径都保存。后续用DFS计算第二指标，得到期望结果
void Dijkstra_dfs(int** G, int** cost, int node_num, bool* visited, int start, int dest)
{
    reset();
    dis[start] = 0;
    for (int i = 0; i < node_num; i++) {
        int min_idx = -1;
        int min = INF;
        // 找到距起点最小的节点
        for (int v = 0; v < node_num; v++) {
            if (dis[v] < min && !visited[v]) {
                min_idx = v;
                min = dis[v];
            }
        }
        if (min_idx == -1) return;
        visited[min_idx] = true;
        for (int u = 0; u < node_num; u++) {
            // 先判断该节点是否可访问
            if(!visited[u] && G[min_idx][u] != INF){
                int dis_vu = dis[min_idx] + G[min_idx][u];
                if (dis_vu < dis[u]) {
                    dis[u] = dis_vu;
                    pre_vec[u].clear();
                    pre_vec[u].push_back(min_idx);
                } else if (dis_vu == dis[u]) {
                    pre_vec[u].push_back(min_idx);
                }
            }
        }
    }
    for (int i = 0 ; i < node_num; i++) {
        printf("%d ", dis[i]);
    }
    printf("\n");
}

// 以花费作为第二指标进行计算，优先选花费小的，从后向前开始遍历
int cost_min = 0, cost_tmp = 0;
void DFS_second(int start, int end, int** cost, int size)
{
    // 遍历到出发点，根据保存的路径计算花费 
    if (start == end) {
        temp_path.push_back(end);
        int cost_end = 0;
        for (int i = temp_path.size()-1; i > 0; i--) {
            int from = temp_path[i];
            int to = temp_path[i-1];
            cost_end += cost[from][to];
        }
        if(cost_end < cost_min){
            cost_min = cost_end;
            path = temp_path;
        }
        temp_path.pop_back();
        return;
    }

    temp_path.push_back(end);
    vector<int> temp = pre_vec[end];
    for (int i = 0; i < temp.size(); i++) {
        DFS_second(start, temp[i], cost, size);
    }
    temp_path.pop_back();
}

int** create_2D(int n)
{
    int** G = new int*[n];
    for (int i = 0; i < n; i++) {
        G[i] = new int[n];
        for (int j = 0; j < n; j++) {
            G[i][j] = INF;
        }
    }
    return G;
}

void delete_2D(int** G, int node_num)
{
    for (int i = 0; i < node_num; i++) {
        delete [] G[i];
    }
    delete [] G;
}

void p_graph(int **G, int node_num)
{
    printf("------> 2D array is <------\n");

    for (int i = 0; i < node_num; i++) {
        for (int j = 0; j < node_num; j++) {
            printf("%d ", *(*(G+i)+j)); 
        }
        printf("\n");
    }
    printf("\n");
}

int test_edge[5][4] = {{0,1,1,20}, {1,3,2,30}, {0,3,4,10}, 
                       {0,2,2,20}, {2,3,1,20}};

int main()
{
    int node_num = 4, edge = 5, start = 0, dest = 3;
    int** G = create_2D(node_num);
    int** cost = create_2D(node_num);

    // 输入边权，构造邻接矩阵
    for (int edge_i = 0; edge_i < edge; edge_i++) {
        int u = test_edge[edge_i][0];
        int v = test_edge[edge_i][1];
        int dis_uv = test_edge[edge_i][2];
        int cost_uv = test_edge[edge_i][3];
        G[u][v] = G[v][u] = dis_uv;
        cost[u][v] = cost[v][u] = cost_uv;
    }
    p_graph(G, node_num);
    p_graph(cost, node_num);

    // 给定起点、终点，求起点到终点的最短路径，最短距离，以及花费
    printf("----------------Dijkstra only--------\n");
    Dijkstra(G, cost, node_num, visited, start, dest);
    DFS_path(start, dest);
    printf("\n");

    printf("----------------Dijkstra DFS--------\n");
    Dijkstra_dfs(G, cost, node_num, visited, start, dest);
    DFS_second(0, 3, cost, node_num);
    
    // 回收内存
    delete_2D(G, node_num);
    delete_2D(cost,node_num);
    return 0;
}