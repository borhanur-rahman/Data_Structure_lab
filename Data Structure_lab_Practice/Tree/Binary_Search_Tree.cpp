#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node* getNode(int data)
{

    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};
struct node* insertLeft(struct node *root,int data)
{
    root->left=getNode(data);
    return  NULL;
};
struct node* insertRight(struct node *root,int data)
{
    root->right=getNode(data);
    return  NULL;
};
/*
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
        cout<<ptr->data<<" ";
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
}*/
void inOrderTraversal(struct node *root)
{
    if(root==NULL)
        return;
     inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
int Insert_Binary_Search_Tree(struct node *root,int item)
{


    while(1)
    {
        if(root->data>item)
        {
            if(root->left==NULL)
            {
                insertLeft(root,item);
                return 0;
            }
            else
            {
                root=root->left;
            }
        }
        else
        {
            if(root->right==NULL)
            {
                insertRight(root,item);
                return 0;
            }
            else
            {
                root=root->right;
            }


        }

    }



}


int main()
{
    struct node *root=getNode(10);
    insertLeft(root,7);
    insertRight(root,12);
    insertLeft(root->left,4);
    insertRight(root->left,9);
    inOrderTraversal(root);
    cout<<endl;
    Insert_Binary_Search_Tree(root,20);
    inOrderTraversal(root);
    cout<<endl;
    Insert_Binary_Search_Tree(root,8);
    inOrderTraversal(root);


}

