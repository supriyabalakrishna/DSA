#include<iostream>
using namespace std;
#include<stack>
struct node
{
    int data;
    node*left;
    node*right;
};
struct node*newnode(int val)
{
    struct node*temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void in(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);

}
void pos(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    pos(root->left);
    pos(root->right);
    cout<<root->data<<" ";
}
void pre(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
void ip(struct node*root)
{
    stack<node*>s;
    node*curr = root;
    while(curr != NULL || !s.empty())
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}
void ipr(struct node*root)
{
    stack<node*>s;
    s.push(root);
    while(!s.empty())
    {
        node*curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->left)
        {
            s.push(curr->left);
        }
        if(curr->right)
        {
            s.push(curr->right);
        }
    }
}
void ipo(struct node*root)
{
    stack<node*>s1;
    stack<node*>s2;
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
}
int main()
{
    struct node*root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout<<"Inorder traversal recursive: ";
    in(root);
    cout<<endl;
    cout<<"Preorder traversal recursive: ";
    pre(root);
    cout<<endl;
    cout<<"Postorder traversal recursive: ";
    pos(root);
    cout<<endl;
    cout<<"Inorder traversal iterative: ";
    ip(root);
    cout<<endl;
    cout<<"Preorder traversal iterative: ";
    ipr(root);
    cout<<endl;
    cout<<"Postorder traversal iterative: ";
    ipo(root);
    return 0;
}