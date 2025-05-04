#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int table[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key
void insert(int key) {
    int index = hashFunction(key);
    int start = index;

    do {
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != start);

    printf("Hash table is full. Cannot insert %d\n", key);
}

// Remove a key
void removeKey(int key) {
    int index = hashFunction(key);
    int start = index;

    do {
        if (table[index] == key) {
            table[index] = DELETED;
            printf("Deleted %d from index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (table[index] != EMPTY && index != start);

    printf("Key %d not found in the hash table.\n", key);
}

// Search for a key
void search(int key) {
    int index = hashFunction(key);
    int start = index;

    do {
        if (table[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (table[index] != EMPTY && index != start);

    printf("Key %d not found in the hash table.\n", key);
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY) {
            printf("%d : EMPTY\n", i);
        } else if (table[i] == DELETED) {
            printf("%d : DELETED\n", i);
        } else {
            printf("%d : %d\n", i, table[i]);
        }
    }
}

int main() {
    int choice, key;

    // Initialize table with EMPTY values
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = EMPTY;
    }

    do {
        printf("\n----- Hash Table Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                removeKey(key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}