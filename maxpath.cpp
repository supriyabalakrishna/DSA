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
struct  node*newnode(int val)
{
    struct node*temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;

}
int height(struct node*root , int&v)
{
    if(root== NULL)
    {
        return 0;
    }
    int l = height(root->left , v);
    int r = height(root->right , v);
    v = max( v , l+r+root->data);
    return (root->data)+max(l,r);
}
int maxp(struct node*root)
{
    int v = INT16_MIN;
    height(root,v);
    return v;
}
int main()
{
    struct node*root = newnode(10);
    root->left = newnode(2);
    root->right = newnode(10);
    root->left->left = newnode(20);
    root->left->right = newnode(1);
    root->right->right = newnode(-25);
    root->right->right->left = newnode(3);
    root->right->right->right = newnode(4);
    cout<<"Maximum path sum is "<<maxp(root)<<endl;
    return 0;
}