#include <cstdio>
#include <algorithm>
#include <cmath> 
#include <cstdlib>
#include <cstring>
#include "numbers_related.cpp"

struct fraction{
    int num;
    int den;
};

void reduction(fraction *a)
{
    if (a->den < 0) {
        a->den = -a->den;
        a->num = -a->num;
    }
    if(a->num == 0){
        a->den = 1;
    } else {
        int gcd = GCD_r(abs(a->den), abs(a->num)); 
        a->den /= gcd;
        a->num /= gcd;
    } 
}

fraction add(fraction a, fraction b)
{
    fraction sum;
    sum.den = a.den * b.den;
    sum.num = a.den * b.num + a.num * b.den;
    reduction(&sum);
    return sum;
}

fraction sub(fraction a, fraction b)
{
    fraction subtraction;
    subtraction.den = a.den * b.den;
    subtraction.num = a.num * b.den - a.den * b.num;
    reduction(&subtraction);
    return subtraction;
}

fraction mul(fraction a, fraction b)
{
    fraction mul;
    mul.den = a.den * b.den;
    mul.num = a.num * b.num;
    reduction(&mul);
    return mul;
}

fraction div(fraction a, fraction b)
{
    fraction b_rev = {b.den, b.num};
    return mul(a, b_rev);
}

void printf_frac(fraction a)
{
    printf("%d/%d", a.num, a.den);
}
void print_operation(fraction a, fraction b, int op){
    fraction result;
    char opcode;
    switch (op) {
        case 1: 
            result = add(a, b);
            opcode = '+';
            break;
        case 2:
            result = sub(a, b);
            opcode = '-';
            break;
        case 3:
            result = mul(a, b);
            opcode = '*';
            break;
        case 4:
            result = div(a, b);
            opcode = '/';
            break;
    }
    printf_frac(a);
    printf(" %c ", opcode);
    printf_frac(b);
    printf("%c ", '=');
    printf_frac(result);
    printf("\n");
}

int main()
{
    struct fraction fractions[8] = {
        {1, 2},
        {-3, 4},
        {5, 1},
        {2, 3},
        {-1, 5},
        {4, 7},
        {-2, 9},
        {8, 6}
    };

    //// 输出数组中的每个fraction
    //for (int i = 0; i < 8; ++i) {
    //    printf("Fraction %d: %d/%d\n", i + 1, fractions[i].num, fractions[i].den);
    //}

    // test reduction 
    //for (int i = 0; i < 8; ++i) {
    //    reduction(fractions[i]);
    //    printf("Fraction %d after reducted: %d/%d\n", i , fractions[i].num, fractions[i].den);
    //}
    printf("------------test for add-----------\n");
    for (int i = 0; i < 8; i +=2) {
        print_operation(fractions[i], fractions[i+1], 1);
    }

    printf("------------test for sub-----------\n");
    for (int i = 0; i < 8; i +=2) {
        print_operation(fractions[i], fractions[i+1], 2);
    }

    printf("------------test for mul-----------\n");
    for (int i = 0; i < 8; i +=2) {
        print_operation(fractions[i], fractions[i+1], 3);
    }

    printf("------------test for div-----------\n");
    for (int i = 0; i < 8; i +=2) {
        print_operation(fractions[i], fractions[i+1], 4);
    }
    
    return 0;
}