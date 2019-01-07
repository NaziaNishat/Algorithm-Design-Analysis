#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool cmp(Item a,Item b){
    double ratio1 = (double) (a.value/a.weight);
    double ratio2 = (double) (b.value/b.weight);
    return ratio1 > ratio2;
}

int main()
{
    Item items[] = {{60,10},{100,20},{120,30}};
    int i=0;
    int allowedWeight = 50;
    int currentWeight = 0;
    double currentValue = 0.0;

    int size = sizeof(items)/ sizeof(items[0]);

    sort(items,items+size,cmp);
    for(i=0;i<size;i++)
    {
        if(currentWeight + items[i].weight <= allowedWeight)
        {
            currentValue += items[i].value;
            currentWeight += items[i].weight;
        }

        else{
            int remainingWeight = allowedWeight - currentWeight;
            int valueOfRemainingWeight = items[i].value * ((double)  remainingWeight/items[i].weight);
            currentWeight += remainingWeight;
            currentValue += valueOfRemainingWeight;
        }
    }

    printf("%d %.2f\n",currentWeight,currentValue);
}

