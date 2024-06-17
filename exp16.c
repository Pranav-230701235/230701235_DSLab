#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 5
#define LOAD_FACTOR_THRESHOLD 0.7
typedef struct {
    int key;
    int value;
    int is_deleted; // To handle deletion in open addressing
} OAHashTableEntry;
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;
    OAHashTableEntry** entries;
    int size;
    int count;
} OAHashTable;
typedef struct {
    Node** buckets;
    int size;
} CAHashTable;
OAHashTableEntry* create_oa_entry(int key, int value) {
    OAHashTableEntry* entry = malloc(sizeof(OAHashTableEntry));
    entry->key = key;
    entry->value = value;
    entry->is_deleted = 0;
    return entry;
}
Node* create_ca_node(int key, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
OAHashTable* create_oa_table(int size) {
    OAHashTable* table = malloc(sizeof(OAHashTable));
    table->size = size;
    table->count = 0;
    table->entries = calloc(table->size, sizeof(OAHashTableEntry*));
    return table;
}
CAHashTable* create_ca_table(int size) {
    CAHashTable* table = malloc(sizeof(CAHashTable));
    table->size = size;
    table->buckets = calloc(table->size, sizeof(Node*));
    return table;
}
unsigned int hash(int key, int size) {
    return key % size;
}
void oa_insert(OAHashTable* table, int key, int value) {
    int index = hash(key, table->size);

    while (table->entries[index] != NULL && !table->entries[index]->is_deleted) {
        if (table->entries[index]->key == key) {
            table->entries[index]->value = value;
            return;
        }
        index = (index + 1) % table->size;
    }

    table->entries[index] = create_oa_entry(key, value);
    table->count++;
}
void oa_rehash(OAHashTable* table) {
    int old_size = table->size;
    OAHashTableEntry** old_entries = table->entries;

    table->size *= 2;
    table->count = 0;
    table->entries = calloc(table->size, sizeof(OAHashTableEntry*));

    for (int i = 0; i < old_size; i++) {
        if (old_entries[i] != NULL && !old_entries[i]->is_deleted) {
            oa_insert(table, old_entries[i]->key, old_entries[i]->value);
            free(old_entries[i]);
        }
    }
    free(old_entries);
}
void ca_insert(CAHashTable* table, int key, int value) {
    int index = hash(key, table->size);
    Node* new_node = create_ca_node(key, value);

    if (table->buckets[index] == NULL) {
        table->buckets[index] = new_node;
    } else {
        Node* current = table->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
void print_oa_table(OAHashTable* table) {
    for (int i = 0; i < table->size; i++) {
        if (table->entries[i] != NULL && !table->entries[i]->is_deleted) {
            printf("Index %d: Key: %d, Value: %d\n", i, table->entries[i]->key, table->entries[i]->value);
        } else {
            printf("Index %d: NULL\n", i);
        }
    }
}
void print_ca_table(CAHashTable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("Bucket %d: ", i);
        Node* current = table->buckets[i];
        while (current != NULL) {
            printf("Key: %d, Value: %d -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}
int main() {
    OAHashTable* oa_table = create_oa_table(INITIAL_SIZE);
    CAHashTable* ca_table = create_ca_table(INITIAL_SIZE);
    int key, value;
    char choice;
    while (1) {
        printf("Enter a key-value pair (key value) to insert or 'q' to quit: ");
        if (scanf(" %c", &choice) && choice == 'q') {
            break;
        } else {
            ungetc(choice, stdin);
            scanf("%d %d", &key, &value);
            oa_insert(oa_table, key, value);
            if ((float)oa_table->count / oa_table->size > LOAD_FACTOR_THRESHOLD) {
                printf("Rehashing (Open Addressing)...\n");
                oa_rehash(oa_table);
            }
            ca_insert(ca_table, key, value);
            printf("Open Addressing Table:\n");
            print_oa_table(oa_table);
            printf("Closed Addressing Table:\n");
            print_ca_table(ca_table);
        }
    }
    for (int i = 0; i < oa_table->size; i++) {
        if (oa_table->entries[i] != NULL) {
            free(oa_table->entries[i]);
        }
    }
    free(oa_table->entries);
    free(oa_table);
    for (int i = 0; i < ca_table->size; i++) {
        Node* current = ca_table->buckets[i];
        while (current != NULL) {
            Node* to_free = current;
            current = current->next;
            free(to_free);
        }
    }
    free(ca_table->buckets);
    free(ca_table);

    return 0;
}
