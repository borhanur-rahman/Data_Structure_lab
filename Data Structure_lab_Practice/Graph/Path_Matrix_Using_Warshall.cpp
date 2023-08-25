#include<bits/stdc++.h>
using namespace std;
int adjMatrix[100][100]= {0};
int pathMatrix[100][100]= {0};
void displayPathMatrix(int nodeNumber)
{
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
            cout<<pathMatrix[i][j]<<" ";
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
            cin>>adjMatrix[i][j];
            pathMatrix[i][j]=adjMatrix[i][j];
        }

        for(int k=0;k<nodeNumber;k++)
            for(int i=0;i<nodeNumber;i++)
                for(int j=0;j<nodeNumber;j++)
                    pathMatrix[i][j]=pathMatrix[i][j]|(pathMatrix[i][k]&pathMatrix[k][j]);

        cout<<"PathMatrix Of the Matrix"<<endl;
        displayPathMatrix(nodeNumber);
}
