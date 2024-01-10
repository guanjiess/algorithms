#include <cstddef>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100010;
struct Node{
    char data;
    int next;
    bool in_first;
} nodes[MAX];

int main()
{
    int first, second, total;
    scanf("%d%d%d", &first, &second, &total);

    int address, next;
    char data;
    for (int i = 0; i < total; i ++) {
        scanf("%d %c %d", &address, &data, &next);
        nodes[address].data = data;
        nodes[address].next = next;  
    }

    for (int p = first; p != -1; p = nodes[p].next) {
        nodes[p].in_first = true;
    }

    int count = 0;
    int i;

    for (i = second; i != -1; i = nodes[i].next) {
        if (nodes[i].in_first) break;
    }

    if( i != -1){
        printf("%05d\n", i);
    } else {
        printf("-1\n");
    }

    return 0;
}