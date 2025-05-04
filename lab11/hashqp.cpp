#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = EMPTY;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;
            if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
                table[newIndex] = key;
                printf("Key inserted at index %d",newIndex);
                return;
            } else if (table[newIndex] == key) {
               printf("Duplicate key. Insertion aborted.\n");
                return;
            }
            i++;
        }

        printf("Hash table is full. Cannot insert.\n");
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;
            if (table[newIndex] == EMPTY) {
                break;
            } else if (table[newIndex] == key) {
                table[newIndex] = DELETED;
                printf("Key deleted from index %d",newIndex);
                return;
            }
            i++;
        }

        cout << "Key not found.\n";
    }

    void search(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;
            if (table[newIndex] == EMPTY) {
                break;
            } else if (table[newIndex] == key) {
                printf("Key found at index %d",newIndex);
                return;
            }
            i++;
        }

        cout << "Key not found.\n";
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            printf("%d",table[i]);
            if (table[i] == EMPTY)
                cout << "EMPTY";
            else if (table[i] == DELETED)
                cout << "DELETED";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table with Quadratic Probing ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d",&key);
            ht.remove(key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d",&key);
            ht.search(key);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
