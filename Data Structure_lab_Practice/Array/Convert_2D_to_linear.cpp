#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n;
    int array[3][4]={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    int rowArray[12],colArray[12];
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
    {
        rowArray[i*4+j]=array[i][j];
        colArray[j*3+i]=array[i][j];
    }

     cout<<"row 3:\n";
    for(i=2*4;i<3*4;i++){
        cout<<rowArray[i]<<" ";
    }
      for(i=2*3;i<3*3;i++){
        cout<<colArray[i]<<" ";
    }

}
