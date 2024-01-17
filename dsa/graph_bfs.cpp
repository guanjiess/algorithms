#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct node{
    int v;
    int layer;
    node(int _v, int _layer){
        v = _v;
        layer = _layer;
    }
};

int** new_adj(int n)
{
    int** G = new int*[n];
    for (int i = 0; i < n; i++) {
        G[i] = new int[n];
    }
    return G;
}

void p_node(node p)
{
    printf("value:%d, layer:%d\n", p.v, p.layer);
}

void BFS(int u, int** G, bool* inq, int size)
{
    queue<node> q;
    node start = node(u, 1);
    p_node(start);
    q.push(start);
    while (!q.empty()) {
        node temp = q.front();
        inq[temp.v] = true;
        q.pop();
        for (int i = 0; i < size; i++) {
            if(G[temp.v][i]!=0 && !inq[i]){
                node node_i = node(i, temp.layer+1);
                p_node(node_i);
                q.push(node_i);
                inq[i] = true;
            }
        }
    }
}

void delete_adj(int** G, int size)
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

void p_inq(bool* in, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%s", in[i] ? "ture " : "false ");
    }
    printf("\n\n");
}

int test_G[6][6]  = { {0,1,1,0,0,0},
                    {0,0,0,1,1,0},
                    {0,1,0,0,1,0},
                    {0,0,0,0,0,0},
                    {0,0,0,1,0,1},
                    {0,0,0,1,0,0}};



int main()
{
    // first line input
    const int size = 7, max_layer = 3;
    
    // input linkage situation between nodes and create adjacency matrix. 
    int** G = new_adj(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            G[i][j] = test_G[i][j];
        }
    } 
    p_graph(G, size);
    bool* inq = new bool[size];
    p_inq(inq, size);

    // input queries, and print the answer. 
    int queryNum = 2;
    int toBque[2] = {2,6};

    BFS(0, G, inq, size);
    p_inq(inq, size);
    
    delete_adj(G, size);
    delete [] inq;
    return 0;
}