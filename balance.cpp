#include<iostream>
#include<algorithm>
#include<cstdlib>
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
int height(struct node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l,r);
}
bool isb(struct node*root)
{
    if(root == NULL)
    {
        return true;
    }
    int le = height(root->left);
    int ri = height(root->right);
    if((le - ri ) > 1)
    {
        return false;
    }
    return isb(root->left) && isb(root->right);

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
    else
    {
        cout<<"not balanced tree"<<endl;
    }
    return 0;
}   