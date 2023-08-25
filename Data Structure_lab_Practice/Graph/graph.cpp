#include<bits/stdc++.h>
using namespace std;
struct nodeList
{
    int data;
    struct nodeList *next;
    struct edgeList *adj;
};
struct edgeList
{
    struct nodeList *dest;
    struct edgeList *link;
};
struct nodeList* getNode()
{
    int a;
    cout<<"Enter value of this node:"<<endl;
    cin>>a;
    struct nodeList *node=(struct nodeList*)malloc(sizeof(struct nodeList));
    node->data=a;
    node->next=NULL;
    node->adj=NULL;
    return node;
};
struct edgeList* getEdge()
{
    struct edgeList *edge=(struct edgeList*)malloc(sizeof(struct edgeList));
    edge->dest=NULL;
    edge->link=NULL;
    return edge;
};

int main()
{
    struct nodeList *A,*B,*C;
    struct edgeList *edge,*ab,*ac;
    A=getNode();
    B=getNode();
    C=getNode();

    A->next=B;
    B->next=C;

    ab=getEdge();
    ac=getEdge();
    A->adj=ab;
    ab->link=ac;
    ab->dest=B;
    ac->dest=C;




    edge=A->adj;
    cout<<A->data<<"----"<<edge->dest->data<<endl;
    edge=edge->link;
    cout<<A->data<<"----"<<edge->dest->data<<endl;





}
