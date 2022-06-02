#include "chained_hashtable.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct hash_table *create_table(size_t size){
    struct hash_table *htable = (struct hash_table *)malloc(sizeof(struct hash_table));
    htable->table = (struct linked_list **)malloc(size * sizeof(struct linked_list *));
    for(size_t i=0;i<size;++i){
        htable->table[i] = create_list();
    }
    htable->size = size;
    return htable;
}

void delete_table(struct hash_table *htable){
    for(size_t i=0;i<htable->size;i++){
        delete_list(htable->table[i]);
    }
    free(htable->table);
    free(htable);
}

void insert_key(struct hash_table *htable,uint32_t key){
    uint32_t mask = htable->size-1;
    uint32_t index = key & mask;
    if(!contains_element(htable->table[index],key)){
        add_element(htable->table[index],key);
    }   
}

bool contains_key(struct hash_table *htable,uint32_t key){
    uint32_t mask = htable->size-1;
    uint32_t index = key & mask;
    return contains_element(htable->table[index],key) != 0;
}

bool contains_key2(struct hash_table *htable,uint32_t key){
    uint32_t mask = htable->size-1;
    uint32_t index = key & mask;
    return contains_element2(htable->table[index],key) != 0;
}

void delete_key(struct hash_table *htable,uint32_t key){
    uint32_t mask = htable->size-1;
    uint32_t index = key & mask;
    delete_element(htable->table[index],key);
}