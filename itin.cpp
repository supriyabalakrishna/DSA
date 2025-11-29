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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void ip(struct node*root)
{
    struct node *curr = root;
    stack<node*>s;
    while(curr != NULL || !s.empty())
    {
        while(curr != NULL)
        {
            s.push(curr);
     
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<"  "<<endl;
        curr = curr->right;
    }

}
int main()
{
    struct node*root = newnode(10);
    root->left = newnode(20);
    root->right = newnode(30);
    root->left->left = newnode(40);
    root->left->right = newnode(50);
    cout<<"inorder traversal is "<<endl;
    ip(root);
    return 0;
}