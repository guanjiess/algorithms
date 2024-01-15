#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct node{
    int v;
    node* left;
    node* right;
};

node* newNode(int x)
{
    node* root = new node;
    root->v = x;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void search(node* root, int x)
{
    if(root == NULL){
        return;
    }
    if(root->v == x){
        printf("%d exists!\n", x);
        return;
    } else if (root->v < x) {
        search(root->left, x);
    } else {
        search(root->right, x);
    }
}

void insert(node* &root, int x)
{
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (root->v == x) {
        return;
    } else if (root->v < x) {
        insert(root->right, x);
    } else {
        insert(root->left, x);
    }
}

node* create(int a[], int size)
{
    node* root = NULL;
    for (int i = 0; i < size; i++){
        insert(root, a[i]);   
    }
    return root;
}

void preOrder(node* root, vector<int> &pre)
{
    if(root == NULL){
        return;
    }
    //printf("%d ", root->v);
    pre.push_back(root->v);
    preOrder(root->left, pre);
    preOrder(root->right, pre);
}

void preOrderM(node* root, vector<int> &pre)
{
    if(root == NULL){
        return;
    }
    pre.push_back(root->v);
    preOrderM(root->right, pre);
    preOrderM(root->left, pre);
}

void inOrder(node* root)
{
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->v);
    inOrder(root->right);
}

void postOrder(node* root)
{
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->v);
}

node* find_max(node* root)
{
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

node* find_min(node* root)
{
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void delete_x(node* &root, int x)
{
    if(root == NULL) return;
    if(root->v == x){
        // execute deleting operation.
        // 2 situations, current root node is a leaf or is not a leaf.
        // delete root directly if it is a leaf.
        if(root->left == NULL && root->right == NULL){
            root = NULL;
        } else if (root->left != NULL) {
            // use pre-node to replace root
            // after replacing, delete pre-node.
            node* pre = find_max(root->left);
            root->v = pre->v;
            delete_x(root->left, pre->v);
        } else {
            // use post-node to replace root, same as left situation
            node* post = find_max(root->right);   
            root->v = post->v;
            delete_x(root->right, post->v);
        }
    } else if (root->v < x) {
        delete_x(root->right, x);
    } else {
        delete_x(root->left, x);
    }
}

void print_vec(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void judge(int a[], int size)
{
    node* root = create(a, size);
    vector<int> origin;
    for (int i = 0; i < size; i++) {
        origin.push_back(a[i]);
    }
    print_vec(origin);
    vector<int> pre, post, preM, postM;
    preOrder(root, pre);
    preOrderM(root, preM);
    printf("pre order is: ");  print_vec(pre);
    printf("pre order Mirror is: ");  print_vec(preM);

    if (origin == pre) {
        printf("YES! Input is pre order.\n");
    } else if (origin == preM) {
        printf("YES! Input is a mirror of pre order.\n");
    } else {
        printf("NOOOOOO!\n");
    }

}



int main()
{   
    node* root = newNode(0);
    printf("root is: %d\n", root->v);
    insert(root, 2);

    int a[7] = {5,3,7,4,2,8,6};
    node* root2 = create(a, 7);
    //preOrder(root2);
    //printf("\n");
    
    //inOrder(root2);
    //printf("\n");

    //postOrder(root2);
    //printf("\n");

    //node* max = find_max(root2);
    //printf("max value is: %d\n", max->v);
    //node* min = find_min(root2);
    //printf("min value is: %d\n", min->v);

    //delete_x(root2, 5);
    //preOrder(root2);
    //printf("\n");

    //delete_x(root2, 8);
    //preOrder(root2);
    //printf("\n");
    judge(a, 7);

    return 0;
}