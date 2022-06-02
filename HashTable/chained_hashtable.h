#ifndef CHAINED_HASHTABLE_H
#define CHAINED_HASHTABLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

struct hash_table {
    struct linked_list **table;
    size_t size;
};

struct hash_table *create_table(size_t size);
void delete_table(struct hash_table *table);
void insert_key(struct hash_table *table, uint32_t key);
bool contains_key(struct hash_table *table, uint32_t key);
bool contains_key2(struct hash_table *table, uint32_t key);
void delete_key(struct hash_table *table, uint32_t key);

#endif