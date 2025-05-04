#include <stdio.h>
#include <stdlib.h>

// Implementing list as an Abstract Data Type (ADT)
class List {
    int *arr;
    int cur;
    int n;

public:
    // Constructor: Initializes an empty list with a size of 5
    List() {
        cur = -1;
        n = 5;
        arr = (int *)malloc(n * sizeof(int));
    }

    
    int insertAtBeg(int value);
    int insertAtEnd(int value);
    int insertAtPos(int value, int index);
    void display();
    int deleteAtPos(int index);
    int deleteAtBeg();
    int deleteAtEnd();
    int search(int target);
    int rotate(int k);
};

// Main function with a menu-driven interface
int main() {
    int choice = 1;
    List list1;

    while (choice) {
        printf("\nChoose an operation:\n");
        printf("1) Insert at Beginning\n");
        printf("2) Insert at End\n");
        printf("3) Insert at Position\n");
        printf("4) Delete at Beginning\n");
        printf("5) Delete at End\n");
        printf("6) Delete at Position\n");
        printf("7) Display\n");
        printf("8) Search\n");
        printf("9) Rotate\n");
        printf("10) Exit\n");
        printf("Enter your choice: ");

        int choose;
        scanf("%d", &choose);

        if (choose == 1) {
            printf("Enter value to insert: ");
            int value;
            scanf("%d", &value);
            list1.insertAtBeg(value);
            list1.display();
        } else if (choose == 2) {
            printf("Enter value to insert: ");
            int value;
            scanf("%d", &value);
            list1.insertAtEnd(value);
            list1.display();
        } else if (choose == 3) {
            printf("Enter value to insert: ");
            int value;
            scanf("%d", &value);
            printf("Enter position: ");
            int index;
            scanf("%d", &index);
            list1.insertAtPos(value, index);
            list1.display();
        } else if (choose == 4) {
            printf("Deleted element: %d\n", list1.deleteAtBeg());
            list1.display();
        } else if (choose == 5) {
            printf("Deleted element: %d\n", list1.deleteAtEnd());
            list1.display();
        } else if (choose == 6) {
            printf("Enter position: ");
            int index;
            scanf("%d", &index);
            printf("Deleted element: %d\n", list1.deleteAtPos(index));
            list1.display();
        } else if (choose == 7) {
            list1.display();
        } else if (choose == 8) {
            printf("Enter target value to search: ");
            int target;
            scanf("%d", &target);
            int index = list1.search(target);
            if (index != -1)
                printf("Element found at index: %d\n", index);
            else
                printf("Element not found\n");
        } else if (choose == 9) {
            printf("Enter number of rotations: ");
            int k;
            scanf("%d", &k);
            list1.rotate(k);
            list1.display();
        } else if (choose == 10) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }

    return 0;
}

// Insert at Beginning
int List::insertAtBeg(int value) {
    if (cur == n - 1) {
        printf("Array is full\n");
        return -1;
    }

    for (int i = cur + 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    cur++;
    return 1;
}

// Insert at End
int List::insertAtEnd(int value) {
    if (cur == n - 1) {
        printf("Array is full\n");
        return -1;
    }

    arr[cur + 1] = value;
    cur++;
    return 1;
}

// Insert at a Given Position
int List::insertAtPos(int value, int index) {
    if (index > cur + 1 || index < 0) {
        printf("Index out of bounds\n");
        return -1;
    }
    if (cur == n - 1) {
        printf("Array is full\n");
        return -1;
    }

    for (int i = cur + 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    cur++;
    return 1;
}

// Delete at a Given Position
int List::deleteAtPos(int index) {
    if (index > cur || index < 0) {
        printf("Index out of bounds\n");
        return -1;
    }
    if (cur == -1) {
        printf("Array is empty\n");
        return -1;
    }

    int temp = arr[index];
    for (int i = index; i < cur; i++) {
        arr[i] = arr[i + 1];
    }

    cur--;
    return temp;
}

// Delete at Beginning
int List::deleteAtBeg() {
    if (cur == -1) {
        printf("Array is empty\n");
        return -1;
    }

    int temp = arr[0];
    for (int i = 0; i < cur; i++) {
        arr[i] = arr[i + 1];
    }

    cur--;
    return temp;
}

// Delete at End
int List::deleteAtEnd() {
    if (cur == -1) {
        printf("Array is empty\n");
        return -1;
    }

    int temp = arr[cur];
    cur--;
    return temp;
}

// Display the Array
void List::display() {
    if (cur == -1) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i <= cur; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Search an Element
int List::search(int target) {
    for (int i = 0; i <= cur; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Rotate the List k times 
int List::rotate(int k) {
    if (cur <= 0) return 1;  // No need to rotate an empty or single-element list

   // k = k % (cur + 1);  // Handle cases where k is greater than the list size

    for (int i = 0; i < k; i++) {
        int temp = arr[cur];
        for (int j = cur; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }

    return 1;
}
