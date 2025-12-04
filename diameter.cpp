#include<iostream>
using namespace std;
#include<cstdlib>
#include<algorithm>
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
int height(struct node*root , int &d)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = height(root->left , d);
    int r = height(root->right , d);
    d = max(d,l+r);
    return 1+max(l,r);
}
int dia(struct node*root)
{
    int d = 0;
    height(root,d);
    return d;
}
int main()
{
    struct node*root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);
    root->left->left->left = newnode(7);
    cout<<"Diameter of the tree is "<<dia(root)<<endl;
    return 0;
}