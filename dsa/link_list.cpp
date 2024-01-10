#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    node* next;
};

node* create(int a[], int size)
{
    node* head;
    head = new node;
    head ->next = NULL;
    node *p, *pre;
    pre = head;
    for (int i = 0; i < size; i ++) {
        p = new node;
        p -> data = a[i];
        p -> next = NULL;
        pre -> next = p;
        pre = p;
    }
    return head;
}

// return total occurance time of x.
int search(node* head, int x)
{
    int count = 0;
    node* p = head -> next;
    while (p != NULL) {
        if (p -> data == x) {
            count ++;
        }
        p = p -> next;
    }
    return count;
}

void insert(node* head, int x, int pos)
{
    node* pre = head -> next;
    node* p = new node;
    p -> data = x;
    for (int i = 0; i < pos-1; i++){
        pre =  pre -> next;    
    }
    p -> next = pre -> next;
    pre ->next = p;
}

// delete all the items with data x.
void delete_item(node* head, int x)
{
    node* pre = head;
    node* p = head -> next;
    while (p != NULL) {
        if(p -> data == x){
            pre -> next = p -> next;
            delete(p);
            p = pre -> next;
        } else {
            pre = p;
            p = p -> next;
        }
    }
}

void print_list(node* head)
{
    for (node* p = head -> next; p != NULL; p = p ->next) {
        printf("%d -->", p -> data);
        if(p -> next == NULL) printf("NULL\n");
    }
}

int main()
{
    int a[9] = {1, 4, 4, 3, 4, 2, 657, 3, 32};
    node* L = create(a, 9);

    print_list(L);
    //for (node* p = L -> next; p != NULL; p = p ->next) {
    //    printf("%d -->", p -> data);
    //    if(p -> next == NULL) printf("NULL\n");
    //}

    int x = 4;
    int count = search(L, x);
    printf("%d %d in L.\n", count, x);

    int pos = 3, y = 666;
    insert(L, y, pos);
    print_list(L);

    delete_item(L, y);
    print_list(L); 
    delete_item(L, x);
    print_list(L); 

    return 0;
}