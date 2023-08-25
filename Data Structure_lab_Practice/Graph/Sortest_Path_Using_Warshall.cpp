#include<bits/stdc++.h>
using namespace std;
int warshall[100][100]= {0};
void displayPath(int nodeNumber)
{
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
        {
            if(warshall[i][j]==214748)
                cout<<"0"<<" ";
            else
                cout<<warshall[i][j]<<" ";
        }

        cout<<endl;

    }
}

int main()
{
    int nodeNumber;
    cout<<"Enter the node number of the graph:"<<endl;
    cin>>nodeNumber;

    cout<<"Input Matrix"<<endl;
    for(int i=0; i<nodeNumber; i++)
        for(int j=0; j<nodeNumber; j++)
        {
            cin>>warshall[i][j];
            if(warshall[i][j]==0)
                warshall[i][j]=214748;
        }
    for(int k=0;k<nodeNumber; k++)
        for(int i=0; i<nodeNumber; i++)
            for(int j=0; j<nodeNumber; j++)
                warshall[i][j]=min( warshall[i][j],( warshall[i][k])+ warshall[k][j]);


    cout<<"Path Matrix:"<<endl;
    displayPath(nodeNumber);
}
