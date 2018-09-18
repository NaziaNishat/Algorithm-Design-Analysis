#include<bits/stdc++.h>
using namespace std;

int knapSack(int cap,int weight[],int val[],int n)
{

    if(n==0 || cap==0) return 0;

    //if capacity is more than nth item weight,we cant include that
    if(weight[n-1]>cap) return knapSack(cap,weight,val,n-1);

    //Retuen maximum value of two cases:
    //1.nth item is included
    //2.nth item is not included
    return max(val[n-1]+knapSack(cap-weight[n-1],weight,val,n-1),knapSack(cap,weight,val,n-1));
}

int main()
{
    int n,cap;

    cout<<"Number of items: ";
    cin>>n;

    int val[n],weight[n];
    cout<<"Enter value and weight:"<<endl;
    for(int i=0;i<n;i++)
        cin>>val[i]>>weight[i];

    cout<<"Enter allowed capacity: ";
    cin>>cap;
    int size = sizeof(weight)/ sizeof(weight[0]);

    cout<<"\nMaximum value of allowed capacity: "<<knapSack(cap,weight,val,size)<<endl;
}
