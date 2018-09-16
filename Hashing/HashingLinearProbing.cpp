#include<stdio.h>
#include<stdlib.h>

#define Size 20

struct DataItem{
    int key;
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

void insert(int key,int data)
{
    item = (struct DataItem*) malloc(sizeof(DataItem));
    item->data = data;
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
            printf("(%d %d)",dataList[i]->key,dataList[i]->data);
        else
            printf(" -- ");
        printf("\n");
    }
}

void searchDisplay(struct DataItem* item)
{
    if(item != NULL)
    {
        printf("Value of key %d is %d\n",item->key,item->data);
    }
    else
        printf("Oops! Not found");
}

int main()
{
    singleItem = (struct DataItem*)malloc(sizeof(DataItem));
    singleItem->data = -1;
    singleItem->key = -1;

    insert(1,20);
    insert(1,25);
    insert(2,70);
    insert(42,80);
    insert(4,25);
    insert(12,44);
    insert(14,32);
    insert(17,11);
    insert(13,78);
    insert(37,97);

    display();
    printf("\n");
    item=search(37);
    searchDisplay(item);

    del(item);
    item=search(37);
    searchDisplay(item);
    printf("\n");
}
