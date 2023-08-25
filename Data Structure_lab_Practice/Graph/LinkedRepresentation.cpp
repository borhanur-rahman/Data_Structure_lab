#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    struct node *next;
    struct edge *out;
};
struct edge {
struct node *in;
struct edge *nextedge;
};
typedef struct node *nodeptr;
typedef struct edge *edgeptr;
nodeptr newNode(char data)
{
    nodeptr temp=(nodeptr)malloc(sizeof(nodeptr));
    temp->data=data;
    temp->next=NULL;
    temp->out=NULL;
    return temp;
}

void makeAdjacent(nodeptr A,nodeptr B)
{
    // cout<<"compile"<<endl;
    edgeptr a,temp;
    a=(edgeptr)malloc(sizeof(edgeptr));
    a->in=B;
    a->nextedge=NULL;
    if(A->out==NULL)
    {
      A->out=a;
    }
    else
    {
        temp=A->out;
        while(temp->nextedge!=NULL)
        {
            temp=temp->nextedge;
        }
        temp->nextedge=a;

    }

}
void PrintAdjacent(nodeptr A)
{
    edgeptr e;
    if(A->out==NULL)
    {
         cout<<"None"<<endl;
    }
    else{
       e= A->out;
       while(e!=NULL)
       {
           cout<<e->in->data<<endl;
           e=e->nextedge;
       }
    }
}

int main()
{
    int n,a,x,y;
    char c;
    cout<<"How many node do you want"<<endl;
    cin>>n;
    nodeptr Graph[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element"<<endl;
        cin>>c;
        Graph[i]=newNode(c);
    }
    cout<<"How long your adjacency list:"<<endl;
    cin>>a;
    while(a--)
    {
        cout<<"Enter nodes numbers A--->B"<<endl;
        cin>>x>>y;
       makeAdjacent(Graph[x-1],Graph[y-1]);
    }
     for(nodeptr node:Graph)
        cout<<node->data<<endl;
    for(nodeptr node:Graph)
    {
        cout<<"Adjacent node of : "<<node->data<<endl;
         PrintAdjacent(node);
    }


}

/*nodeptr getList()
{
    nodeptr head,temp;
    int n,a;
    cout<<"How many number do you need?"<<endl;
    cin>>n;
    if(n>0)
    {   cout<<"Enter element"<<endl;
        cin>>a;
        head=newNode(a);
        temp=head;
        n=n-1;
        while(n--)
        {
           cout<<"Enter element"<<endl;
        cin>>a;
        temp->next=newNode(a);
        temp=temp->next;
        }
    }
    return head;

}*/
