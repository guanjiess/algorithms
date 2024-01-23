#include <algorithm>
#include <cstdio>
#include <fstream>
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

//int BFS(int u, int** G, int layer_limit, bool* inq, int size)
int BFS(int u, vector<int>* G, int layer_limit, bool* inq, int size)
{
    queue<node> q;
    node start = node(u, 0);
    p_node(start);
    q.push(start);
    int count = 0;
    while (!q.empty()) {
        node top = q.front();
        int top_id = top.v;
        inq[top_id] = true;
        q.pop();
        for (int i = 0; i < G[top_id].size(); i++) {
            int follow_i_id = G[top_id][i];
            node follow_i = node(follow_i_id, top.layer+1);
            if(!inq[follow_i_id] && follow_i.layer <= layer_limit){
                count ++;
                p_node(follow_i);
                q.push(follow_i);
                inq[follow_i_id] = true;
            }
        }
    }
    return count;
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

void set_q(bool* in, int size)
{
    for (int i = 0; i < size; i++){
        in[i] = false;
    }
}

int test_G[6][6]  = { {0,1,1,0,0,0},
                    {0,0,0,1,1,0},
                    {0,1,0,0,1,0},
                    {0,0,0,0,0,0},
                    {0,0,0,1,0,1},
                    {0,0,0,1,0,0}};


int test_follower_num[8] = {0,3,0,2,2,2,1,1};
int test_follow_id[8][3] = {
    {0,0,0},{2,3,4}, {0,0,0}, {5,6,0},
    {3,1,0},{3,4,0}, {4,0,0}, {5,0,0}
};


int main()
{
    // first line input
    const int size = 7, max_layer = 3;
    
    // input linkage situation between nodes and create adjacency matrix.
    // 2 versions. 
    int** G = new_adj(size+1);
    vector<int> *G_vec = new vector<int>[size+1];
    for (int i = 1; i <= size; i++) {
        int size_i = test_follower_num[i];
        for (int j = 0; j < size_i; j++) {
            int follow_id = test_follow_id[i][j];
            if(follow_id != 0){
                // G[i][j] means j follows i.
                G[follow_id][i] = 1;
                G_vec[follow_id].push_back(i);
            }
        }
    } 
    p_graph(G, size);

    // input queries, and print the answer. 
    int queryNum = 2;
    int toBque[2] = {2,6};

    bool* inq = new bool[size+1];
    p_inq(inq, size+1);
    
    for (int query_i = 0; query_i < queryNum; query_i++){
        printf("------------query_i: %d\n", toBque[query_i]);
        set_q(inq, size);
        int count = BFS(toBque[query_i], G_vec, max_layer, inq, size);
        printf("%d\n", count);
    }

    delete_adj(G, size);
    delete [] G_vec;
    delete [] inq;
    return 0;
}