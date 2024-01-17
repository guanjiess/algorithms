#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


void graph_init(int** graph, int n, vector<int> *G)
{
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            G[i].push_back(graph[i][j]);
        }
    }
}

void print_graph(vector<int> *G, int n)
{
    printf("\n<--------THE GRAPH IS----------->\n\n");
    printf("   ");
    for (int i = 0; i < n; i ++) {
        printf("%d ", i);
    }
    printf("\n   ");
    for (int i = 0 ; i < 2*n-1; i++) {
        printf("=");
    }
    printf("\n");
    
    for (int i = 0; i < n; i ++) {
        printf("%d |", i);
        vector<int> temp = G[i];
        for (int j = 0; j < n; j ++) {
            if(count(temp.begin(), temp.end(), j)){
                printf("%d ", 1);
            } else {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

void p_visit(bool* v, int n)
{
    printf("\n---------------->visited situation\n\n");
    for (int i = 0; i < n; i ++) {
        printf("%s", v[i]? "true ":"false ");
    }
    printf("\n\n");
}


void DFS(vector<int>* G, int n, int depth, bool* marked)
{
    marked[n] = true;   
    vector<int> temp = G[n];
    for (int i = 0; i < temp.size(); i++) {
        int adj_i = temp[i];
        if (!marked[adj_i]) {
            DFS(G, adj_i, depth+1, marked);
        }
    }
}

void DFS_g(vector<int> *G, int size, bool* marked)
{
    for (int n = 0; n < size; n++) {
        DFS(G, n, 1, marked);
    }
}


int main()
{
    const int maxn = 1001;
    const int n = 6;
    vector<int> G[n];
    bool marked[maxn] = {false};
    G[0].push_back(1);
    G[0].push_back(4);
    G[1].push_back(0);
    G[1].push_back(2);
    G[1].push_back(4);
    G[2].push_back(1);
    G[2].push_back(3);
    G[3].push_back(2);
    G[3].push_back(4);
    G[4].push_back(0);
    G[4].push_back(1);
    G[4].push_back(3);
    print_graph(G, n);

    p_visit(marked, n);   
    //DFS(G, 0, 1, marked);
    DFS_g(G, n,marked);
    p_visit(marked, n);   
    
    return 0;
}