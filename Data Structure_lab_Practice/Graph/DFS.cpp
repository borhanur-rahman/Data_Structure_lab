#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    int check;
    struct node *next;
    struct edge *out;
};
struct edge {
struct node *in;
struct edge *nextedge;
};
typedef struct node *nodeptr;
typedef struct edge *edgeptr;
queue<nodeptr>que;
stack<nodeptr>stck;
nodeptr newNode(char data)
{
    nodeptr temp=(nodeptr)malloc(sizeof(nodeptr));
    temp->data=data;
    temp->check=0;
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
void BSF(nodeptr root)
{
   que.push(root);
   root->check=2;
   while(!que.empty())
   {
       if(que.front()->check==3)
       {
           que.pop();
       }
       else if(que.front()->out==NULL)
       {
         cout<<que.front()->data<<" ";
         que.front()->check=3;
         que.pop();
       }
       else{
        edgeptr temp=que.front()->out;
        while(temp!=NULL)
        {
            que.push(temp->in);
            temp=temp->nextedge;
        }
        cout<<que.front()->data<<" ";
         que.front()->check=3;
         que.pop();

       }
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
void makeGraph(nodeptr Graph[],int n)
{
    char c;
    int a,x,y;
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
}
void printGraph(nodeptr Graph[],int n)
{
   for(int i=0;i<n;i++)
    {
        cout<<"Adjacent node of : "<<Graph[i]->data<<endl;
         PrintAdjacent(Graph[i]);
    }
}
void DFS(nodeptr root)
{
  stck.push(NULL);
  stck.push(root);
  root->check=1;
  while(stck.top()!=NULL)
  {
      cout<<stck.top()->data<<" ";
      if(stck.top()->out==NULL)
      {
          stck.top()->check=2;
          stck.pop();
      }
      else
      {
          edgeptr temp=stck.top()->out;
          stck.top()->check=2;
          stck.pop();
          while(temp!=NULL)
          {
              if(temp->in->check==0)
              {
                  stck.push(temp->in);
                  temp->in->check=1;
              }

              temp=temp->nextedge;
          }

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
    makeGraph(Graph,n);
    printGraph(Graph,n);
    cout<<"which node do you pass as a root"<<endl;
    cin>>a;
   // cout<<"BFS:"<<endl;
   // BSF(Graph[a-1]);
    cout<<"DFS:"<<endl;
    DFS(Graph[a-1]);


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

