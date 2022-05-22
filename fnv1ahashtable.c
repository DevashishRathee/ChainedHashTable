#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

const int HASH_TABLE_SIZE = 1000000;

struct hashTableNode{
    uint64_t shmIndex;
};

struct hashTableNode *hashTable = NULL;

uint64_t modHashKey(uint64_t OrderNum){
    return OrderNum%HASH_TABLE_SIZE;
}

uint64_t hash_key(const char *order){
    uint64_t hash = FNV_OFFSET;
    for(const char *p=order;*p;p++){
        hash^= (uint64_t)(unsigned char)(*p);
        hash^= FNV_PRIME;
    }
    return hash;
}

void initHashTable(){
    printf("\n inside initHashTable:");
    hashTable = malloc(HASH_TABLE_SIZE*sizeof(struct hashTableNode));
    memset(hashTable,0,sizeof(struct hashTableNode)*HASH_TABLE_SIZE);
    printf("total memory required is [%lu] bytes",((sizeof(struct hashTableNode))*HASH_TABLE_SIZE));
    printf("\n HASH TABLE INIT COMPLETE!");
    printf("\n base address of HASH TABLE is [%p]",&hashTable[0]);
}

void getFnvHash(){
    printf("\n Inside getFnvHash!!");
    printf("\n Enter the Exchange Order Number to Get Hash -->");
    uint64_t order;
    scanf("%llu",&order);
    printf("\n You have entered [%llu]",order);
    uint64_t hash_value = modHashKey(order);
    printf("\n ***The FNV hash computed is [%llu]***",hash_value);
}

void insertIntoHashTable(){
    printf("\n **** Pushing Sample Exchange Order Numbers to Hash Table Now ***");
    uint64_t collisions = 0;
    uint64_t baseOrder = 1000204560100999;
    printf("base order is [%llu]",baseOrder);
    for(uint64_t i=0;i<HASH_TABLE_SIZE;i++){
        uint64_t cOrder = (baseOrder)+i;
        uint64_t index = modHashKey(cOrder);
        //printf("\n for order[%llu] hash is [%llu]",cOrder,index);
        if(hashTable[index].shmIndex != 0){
            collisions++;
        }
        else{
            hashTable[index].shmIndex = cOrder;
        }
    }
    printf("\n Number of Collisions are [%llu]",collisions);
    printf("\n *** DATA PUSH COMPLETE ***");
    return;
}

void getIndexVal(){
    printf("\n Enter the Index u wanna check:");
    int index;
    scanf("%d",&index);
    printf("\n Exchange Order Number at [%d] index is [%llu]",index,hashTable[index].shmIndex);
}


int main(int argc,char **argv){
    int option;
    
    do{
        printf("\n****HASH TABLE MENU****");
        printf("\n0)Initialize Hash Table");
        printf("\n1)Insert Into Hash Table");
        printf("\n2)Calculate Hash For You Input");
        printf("\n3)Search in Hash Table");
        scanf("%d",&option);
        switch (option)
        {
        case 0:
                initHashTable();
            break;
        case 1:
                insertIntoHashTable();
            break;
        case 2:
                getFnvHash();
            break;
        case 3:
                getIndexVal();
            break;
        default:
            break;
        }
    }
    while(option!=4);
    printf("\nbase address of ht in main is [%p]",&hashTable[0]);
    printf("\nafteyr init value s [%d]",hashTable[0].shmIndex);
    free(hashTable);
    return 0;
}
