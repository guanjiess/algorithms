#include <cstdio>
#include <algorithm>
using namespace std;

struct interval
{
    int left;
    int right;
} INTERVAL[10];

bool cmp(interval a, interval b)
{
    if(a.left != b.left) return a.left > b.left;
    else return a.right < b.right;
}

int main()
{
    int n;
    while (scanf("%d", &n), n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &INTERVAL[i].left, &INTERVAL[i].right);
        }

        sort(INTERVAL, INTERVAL+n, cmp);

        int num = 1;
        //lastLEFT保存上一个不相交区间的左端点
        int lastLEFT = INTERVAL[0].left;
        for (int i = 1; i < n; i++)
        {
            if(INTERVAL[i].right <= lastLEFT){
                num ++;
                lastLEFT = INTERVAL[i].left;
            }
        }
       printf("%d\n", num); 
        
    }
    
    return 0;
}