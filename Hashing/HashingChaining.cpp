#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define sSIZE 10
#define mod 5
using namespace std;

struct DataItem
{
    int key;
    int data;
};

struct DataItem* dataList[SIZE][sSIZE];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key)
{
    return key%mod;
}

void insert(int key,int data)
{
    struct DataItem* item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    int hashIndex = getHashCode(key);

    for(int i=0;i<sSIZE;i++)
    {
        if(dataList[hashIndex][i] == NULL)
        {
            dataList[hashIndex][i]=item;
            break;
        }
    }
}

struct DataItem *search(int key)
{
    int hashIndex=getHashCode(key);

    for(int i=0;i<sSIZE;i++)
    {
        if(dataList[hashIndex][i]==NULL)
            return NULL;

        if(dataList[hashIndex][i]->key == key)
            return dataList[hashIndex][i];
    }

    return NULL;

}

struct DataItem* del(struct DataItem* item)
{
    int delkey = item->key;
    int hashIndex = getHashCode(delkey);

    for(int i=0;i<sSIZE;i++)
    {
        if(dataList[hashIndex][i] != NULL)
        {
            if(dataList[hashIndex][i]->key == delkey)
            {
                struct DataItem* temp = dataList[hashIndex][i];
                dataList[hashIndex][i] = singleItem;
                return temp;
            }
        }
    }
    return NULL;
}

void display()
{
    printf("Inserted Item:\n\n");
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<sSIZE;j++)
        {
            if(dataList[i][j] != NULL)
            printf("(%d %d)",dataList[i][j]->key,dataList[i][j]->data);
            else printf(" -- ");
        }
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
    singleItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    singleItem->key = -1;
    singleItem->data = -1;

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
