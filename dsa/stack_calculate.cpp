#include <cstdio>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct node{
    double num;
    char op;
    bool flag;
    node(){
        num = 0;
        flag = false;
    }
};

string operations;
stack<node> op_stack;
queue<node> poland_express;
map<char, int> prior; 

void clear_stack(stack<node> st)
{
    while (!op_stack.empty()) {
        op_stack.pop();
    }
}
void clear_queue(queue<node> q)
{
    while (!q.empty()) {
        q.pop();
    }
}

void to_poland_express()
{
    clear_queue(poland_express);
    clear_stack(op_stack);
    double num;

    // first put numbers in poland
    // operators in op_stack
    for (int i = 0; i < operations.length(); ){
        struct node temp;
        char cha_i = operations[i];
        // if cha_i is number, do as follow
        // since a number may have multiple digits, we need a while loop
        // to get the full number
        if (cha_i >= '0' && cha_i <= '9') {
            temp.flag = true;
            while (cha_i >= '0' && cha_i <= '9') {
                temp.num = 10 * temp.num + (cha_i- '0');
                i ++;
                cha_i = operations[i];
            }
            poland_express.push(temp);
        } else {
            // character is a operator
            temp.flag = false;
            temp.op = cha_i;

            // if current operator's priority is lower than top element of 
            // op_stack, push those operators into poland expression
            // until top-element is less prior than current operator
            while (!op_stack.empty() && prior[cha_i] <= prior[op_stack.top().op]) {
                poland_express.push(op_stack.top());
                op_stack.pop();
            }
            op_stack.push(temp);
            i ++;
        }
    }

    // push remaining operators into poland express,
    while (!op_stack.empty()) {
        poland_express.push(op_stack.top());
        op_stack.pop();
    }

    //int size = poland_express.size();
    //for (int i = 0; i < size; i++) {
    //    struct node temp = poland_express.front();
    //    if(temp.flag){
    //        printf("%lf ", temp.num);
    //    } else {
    //        printf("%c ", temp.op);
    //    }
    //    poland_express.pop();    
    //}
    //printf("\n");
}

void calculate()
{
    int size = poland_express.size();
    // poland_express is a queue. 
    for (int i = 0; i < size; i ++) {
        struct node temp = poland_express.front();
        poland_express.pop();
        if (temp.flag) {
            op_stack.push(temp);
        } else {
            double temp1, temp2;
            temp1 = op_stack.top().num;
            op_stack.pop();
            temp2 = op_stack.top().num;
            op_stack.pop();
            
            struct node temp3;
            temp3.flag = true;
            char op = temp.op;
            if(op == '+'){
                temp3.num = temp1 + temp2;
            } else if (op == '-') {
                temp3.num = temp2 - temp1;
            } else if (op == '*') {
                temp3.num = temp1 * temp2;
            } else {
                temp3.num = temp2 / temp1;
            }
            op_stack.push(temp3);
        }
    }
    printf("%lf\n", op_stack.top().num);
}



int main()
{
    prior['+'] = 1;
    prior['-'] = 1;
    prior['*'] = 2;
    prior['/'] = 2;

    while (getline(cin, operations), operations != "0") {
        to_poland_express();
        calculate();
    }
    return 0;
}