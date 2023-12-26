#include <cstdio>
#include <algorithm>
using namespace std;

struct mooncake
{
    double inventory;
    double total_revenue; 
    double price;
}mooncakes[100];

bool cmp(mooncake a, mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int TYPES;
    double demand;
    scanf("%d %lf", &TYPES, &demand);
    double demand_copy = demand;
    printf("TYPES:%d, demand:%lf\n", TYPES, demand);
    for (int i = 0; i < TYPES; i++)
    {
        scanf("%lf", &(mooncakes[i].inventory));
    }
    
    for (int i = 0; i < TYPES; i++)
    {
        scanf("%lf", &(mooncakes[i].total_revenue));
        mooncakes[i].price = mooncakes[i].total_revenue / mooncakes[i].inventory;
    }
    sort(mooncakes, mooncakes+TYPES, cmp);

    double max_sales = 0;
    for (int type = 0; type < TYPES; type++)
    {
        if(mooncakes[type].inventory >= demand){
            max_sales += mooncakes[type].price * demand;
            demand = 0;
            break;
        } else {
            max_sales += mooncakes[type].total_revenue;
            demand -= mooncakes[type].inventory;        
        }
    }
    printf("max sale revenue is:%lf\n", max_sales);
    return 0;
}