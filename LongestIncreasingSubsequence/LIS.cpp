#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int lis(int arr[], int n)
{
    int lis[n],i,j,maxValue = 0;

    for(i=0; i<n; i++)
        lis[i] = 1;

    for(i=1; i<n; i++)
        for(j=0; j<i; j++)
            if(arr[i] > arr[j] && lis[i] <lis[j] +1)
                lis[i] = lis[j]+1;


    for(i=0; i<n; i++)
        if(maxValue < lis[i])
            maxValue = lis[i];

    int ans = maxValue;

    for(int k=n-1;k>=0;k--)
    {
        if(lis[k] == maxValue)
        {
            v.push_back(arr[k]);
            maxValue--;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {10,22,9,33,21,50,41,60};
    int n=8;
    printf("Length of lis is %d\n",lis(arr, n));

    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}
