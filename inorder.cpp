#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    ;
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

void inorder(struct node *root)

{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
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
    inorder(root);
    cout << endl;
    return 0;
}