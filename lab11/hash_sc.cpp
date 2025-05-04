#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    list<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);

        // Check for duplicates before inserting
        for (int item : table[index]) {
            if (item == key) {
                cout << "Duplicate key. Insertion aborted.\n";
                return;
            }
        }

        table[index].push_back(key);
        cout << "Key inserted at index " << index << ".\n";
    }

    void remove(int key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                cout << "Key deleted from index " << index << ".\n";
                return;
            }
        }

        cout << "Key not found.\n";
    }

    void search(int key) {
        int index = hashFunction(key);

        for (int item : table[index]) {
            if (item == key) {
                cout << "Key found at index " << index << ".\n";
                return;
            }
        }

        cout << "Key not found.\n";
    }

    void display() {
        cout << "Hash Table (Separate Chaining):\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "[" << i << "]: ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table with Separate Chaining ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
