#include <cstdio>
#include <cstring>

struct bign{
    int num[1000];
    int len;
    bool postive = true;
    bign(){
        for (int i = 0; i < 1000; i ++) {
            num[i] = 0;
        }
        len = 0;
    }
};

void print_bign(bign n)
{
    if(!n.postive) printf("-");
    for (int i = 0; i < n.len; i ++){
        printf("%d",n.num[n.len - 1 -i]);
    }
}

bign change_str(char num[])
{
    bign number;
    int len = strlen(num);
    number.len =  len;
    for (int i = 0; i < len; i ++) {
       number.num[i] = num[len - 1 - i] - '0'; 
       //number.num[i] = num[len - i - 1] - '0'; 
    }
    return number;
}

// a > b, a = b, a < b----> 1, 0, -1
// compare bitwise from higher bits.
// a little verbose, just to print the result.
int bign_cmp(bign a, bign b)
{
    int ans = 0;
    if(a.len > b.len) {ans = 1;}
    else if (a.len <  b.len) ans = -1;
    else {
        int len = a.len;
        bool compared = false;
        for (int i = 0; i < len; i ++) {
            if (a.num[i] > b.num[i]){
                ans = 1;
                compared = true;
                break;
            } 
            else if(a.num[i] < b.num[i]){
                ans = -1;
                compared = true;
                break;
            } 
        }
        if (!compared) ans = 0;
    }
    //print_bign(a);
    //printf(" compares with ");
    //print_bign(b);
    //printf(" is :%d\n",ans);
    return ans;
}


bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    int len = a.len >= b.len ? a.len : b.len;
    int c_len = 0;
    for (int i = 0; i < len; i ++) {
        int temp = a.num[i] + b.num[i] + carry;
        c.num[c_len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry) c.num[c_len++] = carry;
    c.len = c_len;
    return c;
}

bign sub(bign a, bign b)
{
    bign c;
    bign temp = a;
    bool need_reverse = false;
    if (bign_cmp(a, b) < 0) {
        a = b;
        b = temp;
        need_reverse = true;
    }

    int len = a.len >= b.len ? a.len : b.len;
    for (int i = 0; i < len; i ++) {
        if (a.num[i] < b.num[i]) {
            a.num[i+1] --;
            a.num[i] += 10;
        }
        c.num[c.len++] = a.num[i] - b.num[i];
    }

    while (c.len >= 1 && c.num[c.len-1] == 0) {
        c.len --;
    }
    if (need_reverse) {
        c.postive = false;
    }
    return c;
}

bign mul(bign a, int b)
{
    bign c;
    return c;
}

bign div(bign a, int b)
{
    bign c;
    return c;
}


void test_add()
{
    printf("---------->test add\n");
    char add1[30], add2[30];
    while (scanf("%s%s", add1, add2), *add1!= 'E') {
        bign c = change_str(add1);
        bign d = change_str(add2);
        bign e = add(c, d);
        print_bign(c);
        printf(" + ");
        print_bign(d);
        printf(" = ");
        print_bign(e);
        printf("\n");
    } 
}

void test_sub()
{
    printf("---------->test sub\n");
    char sub1[30], sub2[30];
    while (scanf("%s%s", sub1, sub2), *sub1!= 'E') {
        bign c = change_str(sub1);
        bign d = change_str(sub2);
        bign e = sub(c, d);
        print_bign(c);
        printf(" - ");
        print_bign(d);
        printf(" = ");
        print_bign(e);
        printf("\n");
    }
} 

void test_mul()
{
    printf("---------->test mul\n");
    char mul1[30];
    int mul2;
    while (scanf("%s%s", mul1, &mul2), *mul1!= 'E') {
        bign c = change_str(mul1);
        print_bign(c);
        printf(" * ");
        printf("%d = ", mul2);
        bign ans = mul(c, mul2);
        print_bign(ans);
        printf("\n");
    }
}

void test_div()
{

}

int main()
{
    char test1[30]; 
    char test2[30];
    //test construct function and print function
    //printf("---------->test change_str and print big\n");
    //while (scanf("%s",test1), *test1 != '0') {
    //    bign a = change_str(test1);
    //    print_bign(a);
    //    printf("\n");
    //} 

    //printf("---------->test bign_cmp\n");
    //char cmp1[30], cmp2[30];
    //while (scanf("%s%s", cmp1, cmp2), *cmp1 != 'A') {
    //    bign c = change_str(cmp1);
    //    bign d = change_str(cmp2);
    //    bign_cmp(c, d); 
    //} 
    
    //test_add();

    //test_sub();

    test_mul();

    test_div(); 
    
    return 0;
}
