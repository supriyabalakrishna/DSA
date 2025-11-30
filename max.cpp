#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node*newnode(int val)
{
    struct node*temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int maxv(struct node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    int l = maxv(root->left);
    int r = maxv(root->right);
    return 1 + max(l,r);
}
int main()
{
    struct node*root = newnode(10);
    root->left = newnode(20);
    root->right = newnode(30);
    root->left->left = newnode(40);
    root->left->right = newnode(50);
    cout<<"The maximum depth of the binary tree is "<<maxv(root);
    return 0;
}