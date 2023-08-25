#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    struct node *left,*right;
};
struct node* getNode(char data)
{

    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};
struct node* insertLeft(struct node *root,char data)
{
    root->left=getNode(data);
    return  root->left;
};
struct node* insertRight(struct node *root,char data)
{
    root->right=getNode(data);
    return  NULL;
};
void preOrderTraversal(struct node *root)
{
    stack<struct node*> ptrStack;

    struct node *ptr=root;
    ptrStack.push(NULL);

    while(ptr!=NULL)
    {
        cout<<ptr->data;
        if(ptr->right!=NULL)
            ptrStack.push(ptr->right);
        if(ptr->left!=NULL)
            ptr=ptr->left;
        else
        {
            ptr=ptrStack.top();
            ptrStack.pop();
        }
    }
}
void inOrderTraversal(struct node *root)
{
    stack<struct node*> ptrStack;

    struct node *ptr=root;
    ptrStack.push(NULL);

    while(ptr!=NULL)
    {
        ptrStack.push(ptr);
        ptr=ptr->left;
    }
    ptr=ptrStack.top();
    ptrStack.pop();
    while(ptr!=NULL)
    {
        cout<<ptr->data;
        if(ptr->right!=NULL)
        {
            ptr=ptr->right;
            while(ptr!=NULL)
            {
                ptrStack.push(ptr);
                ptr=ptr->left;
            }
        }
        ptr=ptrStack.top();
        ptrStack.pop();
    }


}
int postOrderTraversal(struct node *root)
{
    if(root==NULL)
        return 0;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data;
}

int main()
{
    struct node *root=getNode('/');
    insertLeft(root,'+');
    insertRight(root,'d');
    insertLeft(root->left,'a');
    insertRight(root->left,'c');

    cout<<"\nPreorder Traversing:"<<endl;
    preOrderTraversal(root);
    cout<<"\nInorder Traversing:"<<endl;
    inOrderTraversal(root);
    cout<<"\nPostorder Traversing:"<<endl;
    postOrderTraversal(root);
}
