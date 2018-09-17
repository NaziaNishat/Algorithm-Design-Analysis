#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>

#define Size 20

using namespace std;

struct DataItem{
    int key;
    string name;
    int data;
};

struct DataItem* dataList[Size];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key)
{
    return key % Size;
}

struct DataItem *del(struct DataItem* item)
{
    int hashIndex = getHashCode(item->key);

    while(dataList[hashIndex] != NULL)
    {
        if(dataList[hashIndex]-> key == item->key)
            dataList[hashIndex] = singleItem;

        ++hashIndex;
        hashIndex %= Size;
    }
}

struct DataItem *search(int key)
{
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL)
    {
        if(dataList[hashIndex]->key == key)
            return dataList[hashIndex];

        ++hashIndex;
        hashIndex %= Size;
    }

    return NULL;
}

void insert(int key,string name,int data)
{
    item = (struct DataItem*) malloc(100*sizeof(DataItem));
    item->data = data;
    item->name = name;
    item->key = key;

    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL)
    {
        hashIndex++;
        hashIndex %= Size;
    }

    dataList[hashIndex] = item;
}

void display()
{
    int i;
    printf("Inserted Item:\n\n");
    for(int i=0; i<Size; i++)
    {
        if(dataList[i] != NULL)
        {
            printf("(%d ",dataList[i]->key);
            cout<<", "<<dataList[i]->name<<", "<<dataList[i]->data<<" )\n";
        }
        else
            printf(" -- ");
        printf("\n");
    }
}

void searchDisplay(struct DataItem* item)
{
    if(item != NULL)
    {
        printf("At key %d name: ",item->key);
        cout<<item->name<<" point: "<<item->data<<endl;
    }
    else
        printf("Oops! Not found");
}

int main()
{
    singleItem = (struct DataItem*)malloc(sizeof(DataItem));
    singleItem->data = -1;
    singleItem->key = -1;


    insert(1,"Aryana",20);
    insert(2,"Bristi",70);
    insert(42,"Cyan",80.25);
    insert(4,"Dia",25.16);
    insert(12,"Esha",44.12);
    insert(14,"Faria",32);
    insert(17,"Gippi",11.98);
    insert(13,"Hia",78.12);
    insert(37,"Irfan",97.15);

    display();
    printf("\n");
    item=search(37);
    searchDisplay(item);

    del(item);
    item=search(37);
    searchDisplay(item);
    printf("\n");
}

