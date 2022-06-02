#include "linked_list.h"
#include <stdio.h>
#include <string.h>

struct linked_list *create_list(){
    struct linked_list *sentinel = (struct linked_list *)malloc(sizeof(struct linked_list));
    sentinel->key = 0;
    sentinel->next = NULL;
    return sentinel;
}

void delete_list(struct linked_list *list){
    while(list){
        struct linked_list *temp = list->next;
        free(list);
        list = temp;
    }
}

static struct linked_list *get_previous_link(struct linked_list *list,uint32_t key){
    // finds the node pointing to the node containing key desired
    while(list->next){
            if(list->next->key == key){
                return list;
            }
        list = list->next;
    }
    return NULL;
}

static struct linked_list *get_previous_link2(struct linked_list *list,uint32_t key){
    // finds the node pointing to the node containing key desired
    while(list->next){
            if(list->next->key == key){
                printf("DATA AT KEY IS [%s]",list->next->data);
                return list;
            }
        list = list->next;
    }
    return NULL;
}

void add_element(struct linked_list *list,uint32_t key){
    struct linked_list *novelkey = (struct linked_list *)malloc(sizeof(struct linked_list));
    novelkey->key = key;
    memset(novelkey->data,'\0',50);
    sprintf(novelkey->data,"DEV%lu",key);
    novelkey->next = list->next;
    list->next = novelkey;
}


void delete_element(struct linked_list *list,uint32_t key){
    struct linked_list *prev = get_previous_link(list,key);
    if(prev == NULL){
        //means the key do not exist in list at this index so we do nothing
        return;
    }
    struct linked_list *to_delete = prev->next;
    prev->next = to_delete->next;
    free(to_delete);
}

bool contains_element(struct linked_list *list,uint32_t key){
    return get_previous_link(list,key) != NULL;
}

bool contains_element2(struct linked_list *list,uint32_t key){
    return get_previous_link2(list,key) != NULL;
}

uint32_t search_length(struct linked_list *list, uint32_t key) {
    uint32_t probed = 1;
    while (list->next) {
        probed++;
        if (list->next->key == key)
            break;
        list = list->next;
    }
    return probed;
}