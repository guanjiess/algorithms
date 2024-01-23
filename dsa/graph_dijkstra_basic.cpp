#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int INF = 10000;
struct node{
    int v;
    int dis;
    node(int _v, int _dis){
        v = _v, dis = _dis;
    }
};

// Dijkstra算法，给定图结构，求出各个顶点到起点的最短距离，基本的思想是
// 1-从起点s出发，遍历其周边的所有节点，选择距离起点最近的节点t
// 2-继续遍历和t相连的其他节点mi，计算以t为中间点的情况下，由起点到mi的距离是否小于原有距离，如果是则更新节点点权,
// 循环执行上述的1-2
void Dijkstra(int** G, bool* visited, int* dis, int size, int start)
{
    //除了start外，其余节点均设为INF，表明当前没有访问过其他节点
    fill(dis, dis+size, INF);
    dis[start] = 0;
    for (int i = 0; i < size; i++) {
        // 循环size次，以挑选出当前循环距离起点最近的节点，记其下标为min_index
        int min = INF;
        int min_index = -1;
        for (int j = 0; j < size; j++) {
            if (!visited[j] && dis[j] < min) {
                min = dis[j];
                min_index = j;
            }
        }
        // 遍历后仍然是INF，说明当前节点和其他节点没有链接
        if (min == INF) 
            return;            
        
        // 这一步的目的是对dis做优化，实际应用中优化的指标可能更加复杂
        visited[min_index] = true;
        for (int k = 0; k < size; k++) {
            //如果经由中间节点到达k的距离更小，更新点权dis[k]
            if( !visited[k] && min+G[min_index][k]<dis[k]){
                dis[k] = min + G[min_index][k];
            }
        } 
    }
}

int** create_G(int size)
{
    int **G = new int*[size];
    for (int i = 0; i < size; i++) {
        G[i] = new int[size];
        for (int j = 0; j < size; j++) {
            G[i][j] = INF;
        }
    }
    return G; 
}

void delete_G(int** G, int size)
{
    for (int i = 0; i < size; i++) {
        delete [] G[i];
    }
    delete [] G;
}

void p_graph(int **G, int size)
{
    printf("------> GRAPH <------\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(G+i)+j)); 
        }
        printf("\n");
    }
    printf("\n");
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
    const int maxn = 100;
    const int v_size = 6, edge = 8, start = 0;
    bool visited[maxn] = {false};
    int dis[maxn] = {0};
    int** G = create_G(v_size);
    for (int i = 0; i < edge; i++) {
        int from_node_i = test_edges[i][0];
        int to_node_i = test_edges[i][1];
        int dis2 = test_edges[i][2];
        G[from_node_i][to_node_i] = dis2;
    }
    p_graph(G, v_size);

    Dijkstra(G, visited, dis, v_size, start);

    for (int i = 0; i < v_size; i++) {
        printf("%d ", dis[i]);
    }    
    printf("\n");

    delete_G(G, v_size);
    return 0;
}