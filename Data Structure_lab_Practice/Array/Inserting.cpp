#include<bits/stdc++.h>
using namespace std;


void insertInSortedArray(int nums[],int &size,int item)
{
    int pos=0;
    for(pos=0; item>nums[pos]; pos++);

    for(int i=size; i>pos; i--)
    {
        nums[i]=nums[i-1];
    }
    nums[pos]=item;
    size=size+1;
}

int main()
{
    int numbers[100]  =  {0, 12, 25, 25, 33, 50, 87, 88, 100, 139};
    string names[100] = {"Abdullah", "Ahad", "Bilal", "Delowar", "Fahim", "Hamim", "Mohammad", "Nayeem", "Rashed", "Saidul"};
    int arrSize=10;

    insertInSortedArray(numbers,arrSize,54);


    for(int i=0; i<arrSize; i++)
        cout<<numbers[i]<<" ";
    cout<<endl;


    for(int i=0; i<10; i++)
        cout<<names[i]<<" ";
    cout<<endl;


    int pos=0;
    for(pos=0; "Rahim">names[pos]; pos++);
        for(int i=10; i>pos; i--)
        {
            names[i]=names[i-1];

        }
          names[pos]="Rahim";

    for(int i=0; i<11; i++)
        cout<<names[i]<<" ";
    cout<<endl;
}
