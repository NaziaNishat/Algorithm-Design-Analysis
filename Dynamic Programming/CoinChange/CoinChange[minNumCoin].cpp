///Minimum number of coins needed for making specific value
#include<bits/stdc++.h>
using namespace std;

int minNumCoin(int coins[],int sz,int value)
{
    int table[value+1];
    memset(table,999999,sizeof(table));
    table[0] = 0;

    for(int i=1; i<=value; i++)
    {
        for(int j = 0; j<sz; j++)
        {
            if(coins[j] <= i)
            {
                int sub_res = table[i-coins[j]];
                if(sub_res != 999999 && sub_res+1<table[i])
                    table[i] = sub_res + 1;
            }
        }
    }

    return table[value];
}


int main()
{
    int coins[] = {1,2,5};
    int value = 5;
    int sz = sizeof(coins) / sizeof(coins[0]);

    int minCoin = minNumCoin(coins,sz,value);
    printf("Minimum number of coins needed: %d\n",minCoin);
}
