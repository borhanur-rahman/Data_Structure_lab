#include<bits/stdc++.h>
using namespace std;
/*int totalStep(int disks)
{
  if(disks==1)
  {
      return 1;
  }
  return 1+2*totalStep(disk-1);
}*/
void towerOfHanai(int begin,int end,int middle,int disks)
{
    if(disks==1)
    {
        cout<<begin<<" "<<end<<endl;

    }
    else
    {
        towerOfHanai(begin,middle,end,disks-1);
        cout<<begin<<" "<<end<<endl;
        towerOfHanai(middle,end,begin,disks-1);

    }
}
int main()
{
    int disk;
    cout<<"Enter the disk number:"<<endl;
    cin>>disk;
    cout<<"Number of the steps"<<round(pow(2,disk))-1<<endl;
    towerOfHanai(1,3,2,disk);
}
