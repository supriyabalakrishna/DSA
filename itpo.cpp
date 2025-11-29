#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node*right;
};
struct node*newnode( int  val)
{
    struct node*temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void post(struct node*root)
{
    stack<node*>s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        struct node*curr = s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left)
        {
            s1.push(curr->left);
        }
        if(curr->right)
        {
            s1.push(curr->right);
        }
    }
    while(!s2.empty())
    {
        struct node*curr = s2.top();
        s2.pop();
        cout<<curr->data<<" "<<endl;
    }
}
int main()
{
    struct node*root = newnode(10);
    root->left = newnode(20);
    root->right = newnode(30);
    root->left->left = newnode(40);
    root->left->right = newnode(50);
    cout<<"postorder traversal is "<<endl;
    post(root);
    return 0;   
}
