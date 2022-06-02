#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct linked_list{
    uint32_t key;
    char    data[50];
    struct linked_list *next;
};

struct linked_list *create_list();
void delete_list(struct linked_list *list);

void add_element(struct linked_list *list,uint32_t key);
void delete_element(struct linked_list *list,uint32_t key);
bool contains_element(struct linked_list *list,uint32_t key);
bool contains_element2(struct linked_list *list,uint32_t key);

#endif