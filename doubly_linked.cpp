//Implementing list ADT using doubly linked list

#include<cstdio>
#include<cstdlib>
// Creating a list and node 
class list{
private:
    struct node{
    int data;
    struct node *next;
    struct node *prev;
   };
 struct node *head;
 struct node *tail;

public:

list(){ 
    head = NULL;
    tail = NULL; 
}

// Function prototypes
   int insertBegin(int);
   int insertend(int);
   int insertpos(int,int);
   int deleteBegin();
   int deleteEnd();
   int deletepos(int);
   void display();
   int search(int);
};

int main(){
    int choice,value,pos,result,target;
    list list1;
   
    do{
        printf("MENU CARD\n");
        printf("Enter 1: To Insert the element at the Beginning of the List\n");
        printf("Enter 2: To Insert the element at the End of the List\n");
        printf("Enter 3: To Insert the element at a Specific Positon of the List\n");
        printf("Enter 4: To Delete the element at the Beginning of the List\n");
        printf("Enter 5: To Delete the element at the End of the List\n");
        printf("Enter 6: To Delete the element at a Specific Positon of the List\n");
        printf("Enter 7: To search the element in the List\n");
        printf("Enter 8: To Display the elements of the List\n");
        printf("Enter 9: To Exit the Program\n\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element to insert in the List: ");
            scanf("%d",&value);
            list1.insertBegin(value);
            break;
            case 2:
            printf("Enter the element to insert in the List: ");
            scanf("%d",&value);
            list1.insertend(value);
            break;
            case 3:
            printf("Enter the element to insert in the List: ");
            scanf("%d",&value);
            printf("Enter the position to insert: ");
            scanf("%d",&pos);
            list1.insertpos(pos,value);
            break;
            case 4:
            result = list1.deleteBegin();
            printf("The value of the node deleted is :%d\n",result);
            break;
            case 5:
            result = list1.deleteEnd();
            printf("The value of the node deleted is :%d\n",result);
            break;
            case 6:
            printf("Enter the position to delete: ");
            scanf("%d",&pos);
            result = list1.deletepos(pos);
            printf("The value of the node deleted is :%d\n",result);
            break;
            case 7:
            printf("Enter the element to search: ");
            scanf("%d",&target);
            result = list1.search(target);
            printf("The position of the element in the list is: %d\n",result);
            break;
            case 8:
            list1.display();
            break;
            case 9:
            printf("Exit\n");
            break;
            default:
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 9\n");
            break;
        }
    }
    while(choice!=9);
    return 0;
}
// Program to Insert the element at the Beginning
int list :: insertBegin(int value){
    struct node *newnode = (struct node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = head;
    newnode->prev = NULL;
    if (head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    head->prev = newnode;
    head = newnode;
}
// Program to display the list
void list :: display(){
    if(head == NULL){
        printf("The List is empty\n");
        return;
    }
    printf("The elements in the List are : ");
    struct node *temp = head;
    while(temp!= NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    
}

// program to insert at the end
int list :: insertend(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(tail==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;

}

int list :: insertpos(int pos,int value){
    if(pos<1){
        printf("Invalid position\n");
        return -1;
    }
    if(pos==1){
        insertBegin(value);
        return;
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    struct node *temp = head;
    int i =1;
    while(i<pos-1 && temp!=NULL){
        temp = temp->next;
        i++;
    }

    if (temp==tail){
        insertend(value);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    temp = newnode->next;
    temp->prev  = newnode;
}
int list :: deleteBegin(){
    if(head == NULL){
        printf("The list is empty\n");
        return -1;
    }
    if(head==tail){
        struct node *temp = head;
        int result = head->data;
        head = NULL; //If there’s only one node, sets head = tail = NULL
        tail= NULL;
        free(temp); 

        return result ;
    }
    struct node *temp = head;
    int result = temp->data;
    head = head->next;
    head->prev = NULL;
    
    free(temp);
    return result;

}
int list :: deleteEnd(){
    if(tail==NULL){
        printf("the list is empty\n");
        return -1;
    }
    if(tail==head){
        int result = head->data;
        deleteBegin();
        
        return result;
    }
    struct node *temp = tail;
    int result = temp->data;
    tail = tail->prev;
    tail->next = NULL;

    free(temp);
    return result;
}

int list :: deletepos(int pos){
    if(pos<1){
        printf("Invalid position\n");
        return 0;
    }
    if (pos==1){
        int result = head->data;
        deleteBegin();
        return result;
    }
    struct node *temp = head;
    int i =1;
    while(i<pos-1 && temp!=NULL){
        temp = temp->next;
        i++;
    }
    
    if(tail==temp->next){// what if there are only 2 nodes
        temp = temp->next;
        int result = temp->data;
        deleteEnd();
        return result;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    int result = del->data;
    temp = del->next;
    temp->prev = del->prev;
     return result;

}
int list :: search(int target){
    if(head==NULL){
        printf("the list is empty\n");
        return 0;
    }
    struct node * temp = head;
    int count=1;
    while(temp!=NULL){

        if(temp->data==target){
            return count;
        }
        temp = temp->next;
        count++;
    }
    return 1;
}