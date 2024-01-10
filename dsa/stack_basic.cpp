#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    stack<int> st1;
    for (int i  = 0; i < 5; i ++) {
        st1.push(i * i);
    }
    printf("top element of st1 is %d\n", st1.top());

    st1.pop();
    st1.pop();

    printf("top element of st1 is %d\n", st1.top());
    printf("size of st1 is %ld\n", st1.size());

    if (st1.empty()) {
        printf("st1 is empty\n");
    } else {
        printf("st1 is not empty\n");
    }

    return 0;
}