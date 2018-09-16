#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#define SIZE 20
using namespace std;

struct Info
{
    char name[25];
    double point;
};

struct DataItem{
    int key;
    struct Info info;
};

struct DataItem* dataList[SIZE];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key)
{
    return key%SIZE;
}

struct DataItem *search(int key)
{
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL)
    {
        if(dataList[hashIndex]->key == key)
            return dataList[hashIndex];

        ++hashIndex;
        hashIndex%=SIZE;
    }
};

struct DataItem* del(struct DataItem* item)
{
    int key = item->key;
    int hashIndex=getHashCode(key);

    while(dataList[hashIndex] != NULL)
    {
        if(dataList[hashIndex] ->key == key)
        {
            struct DataItem* temp = dataList[hashIndex];
            dataList[hashIndex]=singleItem;
            return temp;
        }

        ++hashIndex;
        hashIndex %= SIZE;
    }
};

void insert(int key,char name[],double point)
{
    item = (struct DataItem*)malloc(100*sizeof(DataItem));
    item->info.point = point;
    item->key = key;
    strcpy(item->info.name,name);


    int hashIndex=getHashCode(key);

    while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    dataList[hashIndex]=item;
}

void display()
{
    int i;
    printf("Inserted Item:\n\n");
    for(int i=0; i<SIZE; i++)
    {
        if(dataList[i] != NULL){
            printf("[ %d  %s  %.2f ]",dataList[i]->key, dataList[i]->info.name,dataList[i]->info.point);
        }
        else
            printf(" -- ");
        printf("\n");
    }
}

void searchDisplay(struct DataItem* item)
{
    if(item != NULL)
        printf("\n[ At key: %d  name: %s  point: %.2f ]\n",item->key, item->info.name,item->info.point);

    else
        printf("Oops! Not found\n");
}

int main()
{
    singleItem = (struct DataItem*)malloc(100*sizeof(DataItem));
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
    item=search(37);
    searchDisplay(item);

    del(item);
    item=search(37);
    searchDisplay(item);

}


