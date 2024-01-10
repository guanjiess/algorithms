#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <math.h>
using namespace std;
#define MAX_LEN 500

// judge wheather a number is a prime number.
bool is_prime(int n)
{
    int sqrtn = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqrtn; i ++) {
        if(n % i == 0) return false;
    }
    return true;
}

// find the primes less than or equal to n
int* prime_tables(int n)
{
    int p_num = 0;
    int* primes = (int*)malloc(n*sizeof(int)) ;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
             primes[p_num] = i;
             p_num ++;
        }
    }
    return primes;
}

// find primes under integer upper
void sieve_primes(int upper, int primes[])
{
    bool* is_prime = new bool(upper);
    for (int i = 0; i < upper; i ++) {
        is_prime[i] = true;
    }
    // remember to free primes in other functions.
    // int* primes = (int*)malloc(upper*sizeof(int));
    int p_num = 0;
    
    for (int i = 2; i <= upper; i ++) {
        if (is_prime[i]) {
            primes[p_num] = i;
            p_num ++; 
            for (int j = i; j <= upper; j += i) {
                is_prime[j] = false;
            }
        }
    }
    delete [] is_prime;
}

const int MAX = 10086;
bool prime_state[MAX] = {false};
void reset()
{
    for (int i = 0; i < MAX; i++) {
        prime_state[i] = false;
    }
}

void first_n_primes(int n, int primes[])
{
    int p_num = 0;
    for (int i = 2; i < MAX; i++) {
        if(!prime_state[i]){
            primes[p_num] = i;
            p_num ++;
            for (int j = i; j < MAX; j += i) {
                prime_state[j] = true;
            }
        }       
        if(p_num == n) break;
    }
}

void primes_m2n(int m, int n, int primes[])
{
    reset();
    // reset necessiary status.
    for (int i = 0; i < n; i++) {
        prime_state[i] = false;    
    }

    first_n_primes(n, primes);
    for (int i = m-1; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

// 质因子数据结构，包括质因子、质因子数量两个元素
// 对int型
struct prime_factor{
    int factor;
    int cnt;
}factors[10];


int main()
{
    // test is_prime
    //for (int i = 2; i < 20; i ++) {
    //    printf("%d is prime? -->%d\n", i, is_prime(i));
    //}

    // test prime_table
    int UPPER_BOUND = 30;
    int* primes = prime_tables(UPPER_BOUND);
    //int len = sizeof(primes) / sizeof(int);
    printf("-------------------->  test normal method\n");
    for (int i = 0; i < UPPER_BOUND; i ++) {
        int prime_i = primes[i];
        if(prime_i == 0) break;
        printf("%d ", prime_i);
    }
    printf("\n");
    free(primes);

    printf("-------------------->  test sieve method\n");
    const int UPPER = 50;
    int primes_sieve[UPPER] = {0};
    sieve_primes(UPPER, primes_sieve);
    for (int i = 0; i < UPPER_BOUND; i ++) {
        int prime_i = primes_sieve[i];
        if(prime_i == 0) break;
        printf("%d ", prime_i);
    }
    printf("\n");


    int n_t1 = 15;
    printf("-------------------->  test first %d primes\n", n_t1);
    int primes_t1[10] = {0};
    first_n_primes(n_t1, primes_t1);
    for (int i = 0; i < n_t1; i++) {
        printf("%d ", primes_t1[i]);
    } 
    printf("\n");
    
    
    int m = 3, n = 10;
    int primes_t2[10] = {0};
    printf("-------------------->  test %d to %d\n", m, n);
    primes_m2n(m, n, primes_t2);
 
    return 0;
}