#include <cstddef>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node{
    int v;
    int layer;
    node* left;
    node* right;
};

node* newNode(int v)
{
    node* newLeaf = new node;
    newLeaf -> v = v;
    newLeaf -> left = NULL;
    newLeaf -> right = NULL;
    return newLeaf;
}

void print_tree(node* root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->v);
    print_tree(root->left);
    print_tree(root->right);
}

// find all data on tree and replace them with newdata
// implement with recursion.
void search(node* root, int x, int newdata)
{
    if (root == NULL) {
        return;
    }
    if (root->v == x) {
        root->v = newdata;
    }
    search(root->left, x, newdata);
    search(root->right, x, newdata);
}

void insert(node* &root, int x)
{
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if (x <= root->v) {
        insert(root->left, x);
    } else {
        insert(root->right, x);
    }
}


node* Create(int a[], int n)
{
    node* root = newNode(0);
    for (int i = 0; i < n; i ++) {
        insert(root, a[i]);
    }
    return root;
}

void preorder(node* root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->v);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->v);
    inorder(root->right);
}

void postorder(node* root)
{
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->v);
}

void layerOrder(node* root)
{
    queue<node*> q;
    root->layer = 1;
    q.push(root);

    while (!q.empty()) {
        node* front = q.front();
        q.pop();
        printf("%d ", front->v);
        if (front->left != NULL) {
            node* left = front->left;
            left->layer = front->layer + 1;
            q.push(left);
        } 
        if (front->right != NULL) {
            node* right = front->right;
            right->layer = front->layer + 1;
            q.push(right);
        }
    }
}

// build a tree from its preorder and inorder sequence
// implemented with recursion
node* create_from(int in[], int pre[], int preL, int preR, int inL, int inR)
{
    if (preL > preR) {
        return NULL;
    }
    int root_v = pre[preL]; 
    node* root = newNode(0);
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == root_v) {
            break;
        }
    } 
    int left_len = k - inL;
    root->left = create_from(in, pre, preL+1, preL + left_len, inL, k-1);
    root->right = create_from(in, pre, preL + left_len + 1, preR, k + 1, inR);
    return root;
}

node* create_from_post_in(int post[], int in[], int pL, int pR, int inL, int inR)
{
    if (pL > pR) {
        return NULL; 
    }
    int root_v = post[pR];
    node* root = newNode(root_v);
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == root_v) {
            break;
        }
    }
    int left_len = k - inL;
    root->left = create_from_post_in(post, in, pL, pL+left_len-1, inL, k-1);
    root->right= create_from_post_in(post, in, pL+left_len, pR-1, k+1, inR);
    return root;
}

void BFSP(node* root, int n)
{
    queue<node*> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d", now->v);
        count ++;
        if (count < n) {
            printf(" ");
        } else {
            printf("\n");
        }
        if(now->left != NULL){
            q.push(now->left);
        }
        if(now->right!= NULL){
            q.push(now->right);
        }
    }
}

int main()
{
    node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    print_tree(root);
    printf("\n");

    search(root, 0, 999);
    print_tree(root);
    printf("\n");

    insert(root, 888);
    print_tree(root);
    printf("\n");

    int a[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    node* root2 = Create(a, 10);
    print_tree(root2);
    printf("\n");

    printf("preorder\n");
    preorder(root2);
    printf("\n");
    
    printf("inorder\n");
    inorder(root2);
    printf("\n");
    
    printf("inorder\n");
    postorder(root2);
    printf("\n");
    
    printf("layer order\n");
    layerOrder(root2);
    printf("\n");

    printf("------------restore tree from post order and inorder sequence.\n");
    int post[7] = {2, 3, 1, 5, 7, 6, 4};
    int in[7] = {1, 2, 3, 4, 5, 6, 7};
    node* root3 = create_from_post_in(post, in, 0, 6, 0, 6);
    BFSP(root3, 7);    
    return 0;

}