#include <algorithm>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <iterator>
using namespace std;

struct node{
    int v;
    int height;
    node* left;
    node* right;
};

node* newNode(int v)
{
    node* root = new node;
    root->v = v;
    root->height = 1;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int getHeight(node* root)
{
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int balance_fac(node* root)
{
    if(root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

void update_height(node* root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void search(node* root, int x)
{
    if (root == NULL) {
        return;
    }
    if (root->v == x) {
        printf("find %d!\n", root->v);
    } else if (root->v < x) {
        search(root->right, x);
    } else {
        search(root->left, x);
    }
}

// 对AVL树左旋操作，将原根节点A的右节点B作为新的根节点
// 为了维持平衡性，在新的树中需要把B的左节点C挂在A的右节点
void L(node* &root)
{
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    // update heights from bottom to top
    // otherwise you will get an error result.
    // new root node is temp
    update_height(root);
    update_height(temp);
    root = temp;
}

// 右旋操作是左旋的对称过程
void R(node* root)
{
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    update_height(root);
    update_height(temp);
    root = temp;
}

void insert(node* &root, int x)
{
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if(root->v == x) return;
    else if (root->v < x) {
        insert(root->right, x);
        update_height(root);
        //L mode
        if (balance_fac(root) == 2) {
            if(balance_fac(root->left) == 1){
            //LL
                R(root);
            } else if (balance_fac(root->right) == -1) {
            //LR
                L(root->left);
                R(root);
            }
        }
    } else {
        insert(root->left, x);
        update_height(root);
        // R mode
        if (balance_fac(root) == -2) {
            if(balance_fac(root->right) == -1){
                L(root->right);
            } else if (balance_fac(root->right) == 1) {
                R(root->right);
                L(root);
            }
        }
    }
}

int main()
{

    return 0;
}