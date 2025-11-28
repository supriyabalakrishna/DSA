#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int val)
{
    struct node *temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l, r);
}
int main()
{
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->right->left = newnode(6);
    root->right = newnode(3);
    root->right->left = newnode(7);
    root->right->right = newnode(8);
    root->right->right->left = newnode(9);
    root->right->right->right = newnode(10);
    cout << height(root) << endl;
    return 0;
}