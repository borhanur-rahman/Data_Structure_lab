#include<bits/stdc++.h>
using namespace std;
int adjacentMatrix[100][100]= {0};
int pathMatrix[100][100]= {0};
int path[100][100];
void multiply(int nodeNumber )
{
    int temp[100][100]= {0};
    int sum=0;
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
        {
            sum=0;
            for(int k=0; k<nodeNumber; k++)
                sum=sum+(pathMatrix[i][k]*adjacentMatrix[k][j]);
            temp[i][j]=sum;
        }

    }
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
        {
            pathMatrix[i][j]= temp[i][j];
            path[i][j]=path[i][j]+temp[i][j];
        }
    }

}
void displayadjacentMatrix(int nodeNumber)
{
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
            cout<<adjacentMatrix[i][j]<<" ";
        cout<<endl;
    }
}
void displayPathMatrix(int nodeNumber)
{
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
            cout<<pathMatrix[i][j]<<" ";
        cout<<endl;
    }
}
void displayPath(int nodeNumber)
{
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int nodeNumber;
    cout<<"Enter number of the NodeOf the Graph:"<<endl;
    cin>>nodeNumber;
    cout<<"Input Adjacent Matrix:"<<endl;
    for(int i=0; i<nodeNumber; i++)
        for(int j=0; j<nodeNumber; j++)
        {
            cin>>adjacentMatrix[i][j];
            pathMatrix[i][j]=adjacentMatrix[i][j];
            path[i][j]=adjacentMatrix[i][j];

        }

    cout<<"Display Path Matrix of length 1:"<<endl;
    displayadjacentMatrix(nodeNumber);
    multiply(nodeNumber );
    cout<<"Display Path Matrix of length 2:"<<endl;
    displayPathMatrix(nodeNumber);
     multiply(nodeNumber );
    cout<<"Display Path Matrix of length 3:"<<endl;
    displayPathMatrix(nodeNumber);
    cout<<"Display Path "<<endl;
    displayPath(nodeNumber);
}
