 #include<bits/stdc++.h>
using namespace std;
int tree[100]= {0};
void Insert(int item)
{
    int i=0;

    while(1)
    {
        if(tree[i]==item)
        {
            cout<<item<<"is already in the position :"<<i<<endl;
            break;
        }
        else if(tree[i]==0)
        {
            tree[i]=item;
             break;
        }
        else if(item<tree[i])
        {
            i=2*i+1;
        }
        else
        {
            i=2*i+2;
        }

    }

}
void display()
{
    printf("Index -> Value\n");
    for(int i=0; i<15; i++){
        printf("%d   ->    %d\n", i, tree[i]);

    }
}
int main()
{
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Insert(4);
    display();
    return 0;

}
