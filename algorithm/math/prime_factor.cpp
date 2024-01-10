#include <cstdio>
#include <cmath>
#include <math.h>

const int max = 10000;
int primes[max] = {0};
bool is_prime[max] = {false};
int p_num = 0;

void reset_prime()
{
    p_num = 0;
    for (int i = 0; i < max; i ++) {
        is_prime[i] = true;
    }    
}

// fill first n primes in primes[]
void sieve_primes(int n)
{
    reset_prime();
    for (int i = 2; i < max; i ++) {
        if(p_num == n) break;
        if(is_prime[i]){
            primes[p_num] = i;
            p_num ++;
        }
        for (int j = i; j < max; j += i){
            is_prime[j] = false;
        }
    }    
}

struct prime_factor{
    int factor;
    int cnt;
} factors[10];

void clear_factors()
{
    for (int i = 0; i < 10; i ++) {
        factors[i].factor = 1;
        factors[i].cnt = 0;
    }
}

// all the data are stored in an initial array factors[10].
// hence we need refresh factors[10] each time.
void find_prime_factor(int n)
{
    clear_factors();
    int num = 0;
    int sqrtn = (int)sqrt(1.0*n);
    for (int i = 0; i < p_num && primes[i] <= sqrtn; i++) {
        // if i is a prime factor of n
        int prime_i = primes[i];
        if(n % prime_i == 0){
            factors[num].factor = primes[i];
            while (n % prime_i == 0) {
                factors[num].cnt ++;   
                n /= prime_i;
            }
            num++;
        }
        if(n == 1) break;
    }

    //跳出上述for循环后如果n!=1
    //说明存在一个质因子大于 sqrtn
    if(n != 1){
        factors[num].factor = n;
        factors[num].cnt = 1;
        num ++;
    }
    for (int i = 0; i < num; i ++) {
        printf("factor :%d, times: %d\n", factors[i].factor, factors[i].cnt);
    }
}

int main()
{
    int n = 20;
    printf("--------->test first %d primes.\n", n);
    sieve_primes(n);
    for (int i = 0; i < n; i ++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    for(int test = 33; test < 42; test ++){
        printf("------------->test for %d\n", test);
        find_prime_factor(test);
    }
    return 0;
}