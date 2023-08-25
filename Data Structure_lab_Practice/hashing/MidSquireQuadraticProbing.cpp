#include<bits/stdc++.h>
using namespace std;
#define tablesize 11
int hashTable[tablesize];
bool isoqupaid[tablesize]={false};
int hashFunction(int data)
{
    if(data<10)
    {
        return data;
    }
    else
    {
        data=data*data;
        int length=log10(data)+1;
        if(data%2)
        {
            data=data/pow(10,length/2);
            data=data%10;
        }
        else
        {
           data=data/pow(10,(length/2)-1);
            data=data%100;
        }
        return data%tablesize;
    }
}
int main()
{
    int i,j,index;
    int data[]={145,458,12,569,1452,458,145,2563,458};

    for(i=0;i<9;i++)
    {
       index=hashFunction(data[i]);

       if(!isoqupaid[index])
       {
           hashTable[index]=data[i];
            isoqupaid[index]=true;
       }
       else
       {    j=1;
           while(isoqupaid[index])
           {

               index=(index+j)%tablesize;
               j=j+2;
           }
           hashTable[index]=data[i];
            isoqupaid[index]=true;
       }
    }

    for(int a:hashTable)
        cout<<a<<" ";
}
