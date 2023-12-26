#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-5;
const double PI = acos(-1);

double square(double x)
{
    return x * x;
}

double calculate()
{
    double left = 1, right = 2;
    double result = left;
    double mid;
    while (right - left > eps)
    {
        mid = (left + right) / 2;
        if(square(mid) > 2){
            right = mid;
        } else {
            left = mid;
        }
    }
    
    return mid;
}

// see p133
double r_of_h(double R, double h)
{
    double angle = 2 * acos((R-h) / R);
    double lower_side_len = sqrt(2 * R * h - h * h);
    double S1 = 0.5 * R * R * angle - lower_side_len * (R - h);
    double S2 = PI * R * R * 0.5;
    return S1 / S2;
}
double solve_r(double R, double r)
{
    double mid;
    double left = 0, right = R;
    while (right - left > eps)
    {
        mid = (left + right) / 2;
        if(r_of_h(R, mid) > r){
            right = mid;
        } else {
            left = mid;
        }
    }
    return mid;
}

typedef long long LL;
// a^b % m, recursion implementation
LL fast_power(LL a, LL b, LL m)
{
    if(b == 0) return 1;
    if(b % 2 == 0){
        LL half = fast_power(a, b / 2, m);
        return half * half % m;
    } else {
        return a * fast_power(a, b-1, m) % m;
    }
}

int main()
{
    double sqrt2 = calculate();
    printf("%f\n", sqrt2);
    double R = 2, h = 1;
    double r = r_of_h(R, h);
    printf("%f\n", r);

    double ans = solve_r(R, 0.391002);
    printf("%f\n", ans);

    LL a = 2, b = 11, m = 2048+1;
    LL a_b = fast_power(a, b, m);
    printf("%lld\n", a_b);
    return 0;
}