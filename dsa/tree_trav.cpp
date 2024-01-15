#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000;
struct node{
    int v;
    vector<int> children;
}nodes[maxn];

bool cmp(int a, int b)
{
    return nodes[a].v > nodes[b].v;
}

int node_num;
int branch_num;
int target;
int paths[maxn];
void DFS(int root, int numNode, int sum, int target)
{
    if(sum > target) {
        return;
    }
    if(sum == target){
        for (int i = 0; i < numNode; i ++) {
            node temp = nodes[paths[i]];
            printf("%d ", temp.v);
            if (i < numNode-1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
        return;   
    }
    for (int i = 0; i < nodes[root].children.size(); i++) {
        int child = nodes[root].children[i];
        DFS(child, numNode+1, sum+nodes[child].v, target);
    }
}

int main()
{
    scanf("%d%d%d", &node_num, &branch_num, &target);
    printf("%d %d %d\n", node_num, branch_num, target);
    for(int i = 0; i < node_num; i++){
        scanf("%d", &nodes[i].v);
        printf("%d ", nodes[i].v);
        if(i == node_num- 1) printf("\n");
    }

    int branch_id, child_num, child;
    for (int i = 0; i < branch_num; i ++) {
        scanf("%d%d", &branch_id, &child_num);
        for (int k = 0; k < child_num; k++) {
            scanf("%d", &child);
            nodes[branch_id].children.push_back(child);
        }
        sort(nodes[branch_id].children.begin(), nodes[branch_id].children.end(), cmp);

        printf("%d %d ", branch_id, child_num);
        for (int k = 0; k < child_num; k++) {
            int child_k = nodes[branch_id].children[i];
            printf("%d ", child_k);
        }
        printf("\n");

    }
    paths[0] = 0;
    DFS(0, 1, nodes[0].v, target);
    return 0;
}