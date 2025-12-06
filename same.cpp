#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
node*newnode(int val)
{
    struct node*temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int id(struct node*t1 , struct node*t2)
{
    if(t1 == NULL && t2 == NULL)
    {
        return true;
    }
    if(t1 == NULL || t2 == NULL)
    {
        return false;
    }
    return (t1->data == t2->data) && id(t1->left , t2->left) && (t1->right , t2->right);
}
int main()
{
    struct node*root1 = newnode(1);
    root1->left = newnode(2);
    root1->right = newnode(3);
    root1->left->left = newnode(4);
    root1->left->right = newnode(5);

    struct node*root2 = newnode(1);
    root2->left = newnode(2);
    root2->right = newnode(3);
    root2->left->left = newnode(4);
    root2->left->right = newnode(5);

    if(id(root1 , root2))
    {
        cout<<"The two trees are identical"<<endl;
    }
    else
    {
        cout<<"The two trees are not identical"<<endl;
    }
    return 0;
}
