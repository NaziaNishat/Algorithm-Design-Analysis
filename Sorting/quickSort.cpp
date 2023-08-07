#include<bits/stdc++.h>
using namespace std;

int partition_array(int a[], int start, int en)
{
    int pivot = a[en];
    int partitionIndex = start;

    for(int i=start; i<en; i++)
    {
        if(a[i] <= pivot)
        {
            swap(a[i], a[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(a[partitionIndex],a[en]);
    return partitionIndex;
}

void quicksort(int a[],int start, int en)
{
    if(start<en)
    {
        int partitionIndex = partition_array(a,start,en);
        quicksort(a,start, partitionIndex-1);
        quicksort(a, partitionIndex+1,en);
    }

}

int main()
{
    int a[] = {5,6,4,2,7,1,3,2,60,3,3,3,7};
    int sz = sizeof(a)/sizeof(a[0]);
    quicksort(a,0,sz-1);
    for(int i=0; i<sz; i++) cout<<a[i]<<" ";
    cout<<endl;
}
