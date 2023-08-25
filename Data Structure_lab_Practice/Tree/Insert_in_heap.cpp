#include<bits/stdc++.h>
using namespace std;
int heap[100]={0};
void insertHeap(int data,int pos)
{
    int parent;
    while(pos>0)
    {
        parent =(pos-1)/2;
        if(heap[parent]>=data)
        {
            heap[pos]=data;
            return;
        }
        heap[pos]=heap[parent];
        pos=parent;
    }
    heap[pos]=data;
}
void displayTree(int tree[], int size){		//works better with single-digit nodes.
	int i, j, space, lineGap, level = log2(size)+1;
	for(i=0; i<level; i++){					//levels
		for(j=0;(j<(1<<i) && size--); j++){	//nodes of each level
			space = (1<<(level-i))-1;
			if(j == 0){
				space /= 2;
			}
			while(space--){
				cout<<" ";
			}
			cout<<tree[(1<<i)-1+j];
		}
		for(lineGap=0; lineGap<(level-i-1); lineGap++){
			cout<<"\n";
		}
	}
}
int main()
{
    int data[]={5,7,0,3,1,2,6,1,4,7};
    int data_size=sizeof(data)/sizeof(data[0]);
    for(int i=0;i<data_size;i++)
    {
        insertHeap(data[i],i);
    }
    displayTree(heap, data_size);
}
