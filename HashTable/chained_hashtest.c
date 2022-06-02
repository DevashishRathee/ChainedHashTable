#include "chained_hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

#define IMAX_BITS(m) ((m)/((m)%255+1) / 255%255*8 + 7-86/((m)%255+12))
#define RAND_MAX_BITWIDTH (IMAX_BITS(RAND_MAX))

static uint32_t random_key(){
  uint32_t r = 0;
  for (int i=0; i<IMAX_BITS(ULONG_MAX); i += RAND_MAX_BITWIDTH) {
    r <<= RAND_MAX_BITWIDTH;
    r |= rand();
  }
  return r;
}

int main(int argc,char **argv){
    int n = 5000000,found = 0,inserted = 0;
    struct timeval start,end;
    FILE *fptr;
    fptr = fopen("C:\\Code\\C\\DSLIB\\HashTable\\keydump.txt","w");
    if(fptr == NULL){
        printf("KeyDump File Open Error \n");
        exit(1);
    }
    uint32_t spkey;
    uint32_t *keys = (uint32_t *)malloc(5000000*sizeof(uint32_t));
    for(int i=0;i<n;i++){
        keys[i] = random_key();
        if(keys[i]%50000 == 0){
            fprintf(fptr,"%lu,",keys[i]);
        }
    }
    fclose(fptr);

    struct hash_table *htable = create_table(1048576);

    gettimeofday(&start,NULL);
 for (int i = 0; i < n; ++i) {
        insert_key(htable, keys[i]);
        inserted++;
    }
    gettimeofday(&end,NULL);
    uint64_t insertTime = (end.tv_sec*(1000000)+end.tv_usec)-((1000000)*start.tv_sec+start.tv_usec);
    printf("\n ALL [%ld] KEYS INSERTED ! Total Time taken [%llu] microseconds!",inserted,insertTime);

    memset(&start,0,sizeof(struct timeval));
    memset(&end,0,sizeof(struct timeval));

    gettimeofday(&start,NULL); 
    for(int i=0;i<1000000;i++){
        if(contains_key(htable, keys[rand()]) == true){
            found++;
        }
        
    }  
    gettimeofday(&end,NULL); 

    uint64_t lookTime = (end.tv_sec*(1000000)+end.tv_usec)-((1000000)*start.tv_sec+start.tv_usec);
    printf("\n KEY LOOKUP COMPLETE , total Keys found [%ld] , total time taken is [%llu] microseconds OR [%llu] miliseconds",found,lookTime,lookTime/1000);
    printf("\n Average Time Per Key Lookup in MicroSeconds is [%lf]",(float)found/lookTime);
    
    uint32_t tfind;
    printf("\n Enter Key for Search :");
    scanf("%lu",&tfind);
    while(tfind!=0){
        contains_key2(htable, tfind);
        printf("\n Enter Key for Search :");
        scanf("%lu",&tfind);       
    }
    delete_table(htable);
    return 0;
}