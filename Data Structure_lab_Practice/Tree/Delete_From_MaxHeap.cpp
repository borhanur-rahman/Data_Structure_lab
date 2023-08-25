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
void DeleteHeap(int data,int heap_size)
{
    int pos;
    for( pos=0;pos<heap_size;pos++)
    {
        if(heap[pos]==data)
            break;
    }
    while(pos<heap_size/2)
    {


        int left=2*pos+1;   int right=2*pos+2;
        if(heap[right]>=heap[left])
        {
            heap[pos]=heap[right];
            pos=right;
        }
        else{
                 heap[pos]=heap[left];
            pos=left;
        }


    }
    heap[pos]=heap[heap_size-1];
}
int main()
{
    int data[]={5,7,0,3,1,2,6,1,4,7};
    int data_size=sizeof(data)/sizeof(data[0]);
    for(int i=0;i<data_size;i++)
    {
        insertHeap(data[i],i);
    }
    cout<<"Before delating"<<endl;
     displayTree(heap, data_size);
    DeleteHeap(2,data_size);
     cout<<"After delating"<<endl;
    displayTree(heap, data_size-1);
}

