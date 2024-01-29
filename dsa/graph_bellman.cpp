#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// solution of PAT A1003, using Bellman Ford algorithm.

// v is node index; dis is weight of an edge.
struct node{
    int v;
    int dis;
    node(int _v, int _dis){
        v = _v;
        dis = _dis;
    }
};

const int maxn = 101;
const int INF = 999;
// adj means adjacent table, dis means distance between src point to i-th point.
// w means weights accumulated from src point to i-th point. 
// num means shortest path number.
// pre is used to store path.
vector<node> adj[maxn];
int dis[maxn];
int w[maxn];
int num[maxn];
set<int> pre[maxn];

void reset()
{
    for (int i = 0; i < maxn; i++) {
        adj[i].clear();
        dis[i] = INF;
        w[i] = 0;
        num[i] = 0;
    }
}

void p_graph(vector<node>* g, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g[i].size(); j++) {
            printf("%d ", g[i][j].v);
        }
        printf("\n");
    }
}

// 
// 共三层循环，最外层循环遍历size-1轮，每次循环都会遍历更新所有边
// 每次迭代只可以保证更新一层
// 在N个节点组成的图结构中，任何一条最短路径都不可能超过N-1层
bool bellman(int start, int end, int* weight, int size)
{
    dis[start] = 0;
    w[start] = weight[start];
    num[start] = 1;
    for (int i = 0; i < size - 1; i++) {
        for (int u = 0; u < size; u++) {
            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].v;
                int d = adj[u][j].dis;
                // 判断以u为中继节点到节点v的距离是否小于原有距离
                // 如果是，则替换v的原有距离和权重weight，并且记录去路径前驱节点为u
                if (dis[u] + d < dis[v]) {
                    dis[v] = dis[u] + d;
                    w[v] = weight[v] + w[u];
                    // 没有多余的分支路径，所以直接继承之前的路径数
                    num[v] = num[u];      
                    pre[v].clear();
                    pre[v].insert(u);              
                } 
                // 如果以u为中继节点到v的距离和原有距离相同，则保留较大的权值
                else if (dis[u] + d == dis[v]) {
                    if (weight[v] + w[u] > w[v]) {
                        w[v] = weight[v] + w[u];
                    }
                    pre[v].insert(u);

                    //更新最短路径的数量，最短路径为前驱节点最短路径数量之和
                    num[v] = 0;
                    set<int>::iterator it;
                    for (it = pre[v].begin(); it != pre[v].end(); it ++) {
                        num[v] += num[*it];
                    }
                }
            }
        }
    }

    // 判断负环，如果经历了N-1轮的迭代之后，依然可以缩短距离，则一定存在某条边的权为负
    for (int u = 0; u < size; u++) {
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].v;
            int d = adj[u][j].dis;
            if (dis[u] + d < dis[v]) {
                return false;
            }
        }
    }
    return true;
}

bool inq[maxn] = {false};
int num_inq[maxn] = {0};
bool SPFA(int start, int size)
{
    memset(inq, false, maxn);
    memset(num_inq, 0, maxn);
    queue<int> q;
    q.push(start);
    inq[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            int duv = adj[u][i].dis;
            if (duv + dis[u] < dis[v]) {
                dis[v] = duv + dis[u];
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] >= size) return false;
                }
            }
        }
    } 
    return true;
}

int test_w[5] = {1,2,1,5,3};
int test_graph[6][3] = {{0,1,1}, {0,2,2}, {0,3,1},
                        {1,2,1}, {2,4,1}, {3,4,1}};


int main()
{
    int n = 5, m = 6;
    int start = 0, end = 2;

    //scanf("%d%d%d%d", &n, &m, &start, &end);

    reset();
    // 输入点权
    int* weight = new int[n];
    for (int i = 0; i < n; i++) {
        //scanf("%d", &weight[i]);
        weight[i] = test_w[i];
    }

    //输入边权，构成图
    int from, to, distance;
    for (int i = 0; i < m; i++) {
        //scanf("%d%d%d", &from, &to, &distance);
        from = test_graph[i][0];
        to = test_graph[i][1];
        distance = test_graph[i][2];
        struct node node_i(to, distance);
        struct node node_i_rev(from, distance);
        adj[from].push_back(node_i);
        adj[to].push_back(node_i_rev);
    }
    p_graph(adj, n);

    bellman(start, end, weight, n);

    printf("%d %d\n", num[end], w[end]);

    delete [] weight;

    return 0;
}