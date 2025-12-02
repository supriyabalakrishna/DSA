#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdlib>
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
int check(struct node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = check(root->left);
    if(l == -1)
    {
        return -1;
    }
    int r = check(root->right);
    if(r == -1)
    {
        return -1;
    }
    if(abs(l-r)>1)
    {
        return -1;
    }
    return 1 + max(l,r);


}
bool isb(struct node*root)
{
    return check(root) != -1;
}
int main()
{
    struct node*root = newnode(10);
    root->left = newnode(20);
    root->right = newnode(30);
    root->left->left = newnode(40);
    root->left->right = newnode(50);
    if(isb(root))
    {
        cout<<"balanced tree"<<endl;
    }
    else{
        cout<<"not balanced tree"<<endl;
    }
    return 0;
}