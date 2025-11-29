#include<iostream>
using namespace std;
#include<stack>
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
    temp->left  = NULL;
    temp->right = NULL;
    return temp;
}
void pre(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    stack<node*>s;
    s.push(root);
    while(!s.empty())
    {
        struct node* curr = s.top();
        s.pop();
        cout<<curr->data<<" "<<endl;
        if(curr->right)
        {
            s.push(curr->right);

        }
        if(curr->left )
        {
            s.push(curr->left);
        }
    }

}
int main()
{
    struct node*root = newnode(10);
    root->left = newnode(20);
    root->right = newnode(30);
    root->left->left = newnode(40);
    root->left->right = newnode(50);
    cout<<"preorder traversal is "<<endl;
    pre(root);
    return 0;
}