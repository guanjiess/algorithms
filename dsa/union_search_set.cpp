#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000;
int father[maxn];
bool is_root[maxn];


void father_init(int n, int* father)
{
    for (int i = 1; i <= n; i ++) {
        father[i] = i;
        is_root[i] = false;
    }
}

int find_fa_rec(int x)
{
    if (x == father[x]) {
        return x;
    }
    return find_fa_rec(father[x]);
}

int find_father(int x)
{
    // use a to store initial x.
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    // 路径压缩操作
    // now, x is the root.
    // set all the value to be x from a to x.  
    while (a != father[a]) {
        int b = a; 
        a = father[a];
        father[b] = x;
    }
    return x;
}

void union_(int a, int b)
{
    int father_a = find_father(a);
    int father_b = find_father(b);
    if (father_a != father_b) {
        father[father_b] = father_a;
    }
}

int main()
{
    father_init(8, father);
    father[1] = 1;
    father[2] = 1;
    father[3] = 2;
    father[4] = 3;

    father[5] = 5;
    father[6] = 5;

    printf("-----------normally, father of sequence is\n");

    for (int i = 1; i <= 6; i++) {
        printf("father of %d is %d.\n", i, find_fa_rec(i));
    }

    printf("-----------normally, father of sequence is\n");
    
    for (int i = 1; i <= 6; i++) {
        printf("father of %d is %d.\n", i, find_father(i));
    }
    //for (int i = 0; i <= 6; i++) {
    //    printf("father of %d is %d.\n", i, find_fa_rec(i));
    //}
    printf("-----------after union, father of sequence is\n");
    union_(2, 5);

    for (int i = 1; i <= 6; i++) {
        printf("father of %d is %d.\n", i, find_father(i));
    }

    int m,n,a,b;
    scanf("%d%d", &m, &n);
    father_init(m, father);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        union_(a, b);
    }

    int count = 0;
    for (int i = 1; i < m; i++) {
        int father_i = find_father(i);
        is_root[father_i] = true;
    }
    for (int i = 1; i <= m; i++) {
        if (is_root[i]) {
            count++;
        }
    }
    printf("how many circles: %d.\n", count);
    return 0;
}