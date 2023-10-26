#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Define a structure for a key-value pair
typedef struct {
    char* key;
    char* value;
} KeyValuePair;

// Define the hash table structure
typedef struct {
    KeyValuePair** table;
} HashTable;

// Initialize a new hash table
HashTable* initHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (KeyValuePair**)calloc(SIZE, sizeof(KeyValuePair*));
    return ht;
}

// Hash function
int hash(char* key) {
    int sum = 0;
    while (*key) {
        sum += *key++;
    }
    return sum % SIZE;
}

// Insert a key-value pair into the hash table
void insert(HashTable* ht, char* key, char* value) {
    int index = hash(key);

    KeyValuePair* kvp = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    kvp->key = strdup(key);
    kvp->value = strdup(value);

    ht->table[index] = kvp;
}

// Get the value associated with a key
char* get(HashTable* ht, char* key) {
    int index = hash(key);
    return ht->table[index]->value;
}

int main() {
    HashTable* ht = initHashTable();

    insert(ht, "name", "John Doe");
    insert(ht, "age", "30");

    printf("Name: %s\n", get(ht, "name"));
    printf("Age: %s\n", get(ht, "age"));

    return 0;
}
