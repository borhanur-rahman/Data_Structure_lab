/*Linked List:

1.    Create a Linked List and store the value 5, 3, 9, 42, 0, 10.

2.    Traversing: Travarse the linked list and find the maximum, minimum, total and average value.

3.	  Inserting: Insert an element in a specific position and in a sorted linked list

4.	  Deleting: Delete an element from a specific position and from a sorted linked list

5.    Sorting: Sort the contents of a linked list.

6.    Searching: search for an element in a linked list.*/





#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *newNode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));

    temp->data=data;
    temp->next=NULL;
    return temp;
}
struct node *getList(int n)
{
    int a,i=1;
    struct node *temp,*head=NULL;

    if(n>=1)
    {
        cout<<"Enter the element on "<<i<<" node"<<endl;
        cin>>a;
        temp=newNode(a);
        head=temp;
        while(n-i)
        {
            i++;
            cout<<"Enter the element on "<<i<<" node"<<endl;
            cin>>a;
            temp->next=newNode(a);
            temp=temp->next;

        }
    }
    return head;

}
struct node* insertInSortedList(struct node *head,int item)
{
    struct node *connect=NULL,*temp=NULL,*newnode=newNode(item);
    temp=head;
    if(temp->data>item)
    {
        newnode->next=temp;
        return newnode;
    }

    while(1)
    {

        if(temp->data<=item&&(temp->next==NULL||temp->next->data>item))
        {

            connect=temp->next;
            newnode->next=connect;
            temp->next=newnode;
            return head;
        }
        else
        {
            temp=temp->next;
        }

    }

}
struct node* insertInIndex(struct node *head,int item,int index)
{
    struct node *temp,*newnode=newNode(item);
    temp=head;
    int n=index-2;


    if(index==1)
    {
        newnode->next=head;
        return newnode;
    }
    else
    {
        while(n--)
        {
            temp=temp->next;
        }
      newnode->next=temp->next;
      temp->next=newnode;
       return head;

    }



}
struct node* Delete(struct node *head,int index)
{
    struct node *temp;
    temp=head;
    int n=index-2;
 if(index==1)
        return head->next;
 else{
    while(n--)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
 }
}
void bubbleSort(struct node *head)
{
    struct node *start;
    while(head->next!=NULL)
    {

        start=head->next;

        while(start!=NULL)
        {
            if(start->data<head->data)
            {
                int temp=head->data;
                head->data=start->data;
                start->data=temp;
            }
            start=start->next;
        }
        head=head->next;
    }
}
void Print(struct node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    int n,sum=0,lowest=INT_MAX,higest=INT_MIN;
    struct node *temp,*head=NULL;
    cout<<"How long list do you want?"<<endl;
    cin>>n;
    head=getList(n);
    Print(head);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data<lowest)
            lowest=temp->data;
        if(temp->data>higest)
            higest=temp->data;
        sum=sum+temp->data;
        temp=temp->next;
    }

    cout<<"Sum="<<sum<<"\nLowest="<<lowest<<"\nHighest="<<higest<<"\nAverage="<<sum/n<<endl;
    cout<<"Enter Which element do you want to add"<<endl;
    int a;
    cin>>a;
    head=insertInSortedList(head,a);
    Print(head);
    int index,item;
    cout<<"Enter the element and index:"<<endl;
    cin>>item;
    cin>>index;
    head=insertInIndex(head,item,index);
    Print(head);
    cout<<"Enter the  index from which do you want to delete:"<<endl;
        cin>>index;
        head=Delete(head,index);
        Print(head);

        bubbleSort(head);
        cout<<endl;
        Print(head);
}

