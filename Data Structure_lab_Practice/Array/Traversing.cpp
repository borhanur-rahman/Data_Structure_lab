#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lowest=INT_MAX;
    int higest=INT_MIN;
    int sum=0;
    int array[]={5, 45,74,2,48,47};
    for(int x:array)
    {
        if(x<lowest)
            lowest=x;
        if(x>higest)
            higest=x;
            sum=sum+x;
            cout<<"sign value of"<<x<<"is"<<sin(x)<<endl;
    }
    cout<<lowest<<" "<<higest<<endl;
    cout<<sum/(sizeof(array)/sizeof(array[0]))<<endl;
    cout<<sum<<endl;



}
