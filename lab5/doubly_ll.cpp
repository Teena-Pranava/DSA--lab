// Implementing list ADT using doubly linked list

#include<cstdio>
#include<cstdlib>

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
        head=NULL;
        tail=NULL;

    }
    int insertatbeg(int);
    int insertatend(int);
    int insertatpos(int,int);
    int deleteatbeg();
    int deleteatend();
    int deleteatpos(int);
    void display();
    int search(int);
};

int main(){
    int choice,value,pos,result,target;
    list list1;

    do{
        printf("\nMenu card\n");
        printf("Enter 1:To insert at beginning\n");
        printf("Enter 2:TO insert at end\n");
        printf("Enter 3:To insert at position\n");
        printf("Enter 4:To delete at beginning\n");
        printf("Enter 5:To delete at end\n");
        printf("Enter 6:To delete at position\n");
        printf("Enter 7:To display\n");
        printf("Enter 8:To search a node\n");
        printf("Enter 9:To exit\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to insert at beginning :");
                scanf("%d",&value);
                list1.insertatbeg(value);
                printf("\n");
                break;

            case 2:
                printf("Enter value to insert at end:");
                scanf("%d",&value);
                list1.insertatend(value);
                printf("\n");
                break;

            case 3:
                printf("Enter position to insert :");
                scanf("%d",&pos);
                printf("Enter value to insert :");
                scanf("%d",&value);
                list1.insertatpos(value,pos);
                break;

            case 4:
                result=list1.deleteatbeg();
                printf("Deleted value is :%d",result);
                break;
              
            case 5:
                result=list1.deleteatend();
                printf("Deleted value is :%d",result);
                break;
               
            case 6:
                printf("Enter position to delete :");
                scanf("%d",&pos);
                result=list1.deleteatpos(pos);
                printf("Deleted value is :%d\n",result);
                break;

            case 7:
                printf("List :");
                list1.display();
                break;

            case 8:
                printf("Enter element to search :");
                scanf("%d",&target);
                list1.search(target);
                printf("Element fount at index %d",list1.search(target));
                break;

            case 9:
                printf("Exit\n");
                break;

            default:
                printf("Enter valid choice\n");
        }
    }while(choice!=9);
    return 0;
}

// Insertion of node at beginning

int list::insertatbeg(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=head;

    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    head->prev=newnode;
    head=newnode;

    return 1;
}

// Display of list

void list::display(){
    if(head==NULL){
        printf("List is empty\n");
        return ;
    }

    struct node *temp=head;
    struct node *temp1=tail;

    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\t",temp1->data);
    printf("\n");

    while(temp1!=NULL){
        printf("%d\t",temp1->data);
        temp1=temp1->prev;
    }
    }
    

// Insertion of node at end

int list::insertatend(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(tail==NULL){
        head=newnode;
        tail=newnode;
    }
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;

return 1;
}

// Insertion at a given position

int list::insertatpos(int pos,int value){
    if(pos<1){
        printf("Invalid position\n");
        return -1;
    }
    if(pos==1){
        insertatbeg(value);
        return 1;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    struct node *temp=head;
    int i=1;
    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==tail){
        insertatend(value);
        return 1;
    }

    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    temp=newnode->next;
    temp=temp->next;

    return 1;

}
// Deleteing a node at beginning

int list::deleteatbeg(){
    if(head==NULL){
        printf("List is empty\n");
        return -1;
    }
    if(head==tail){
        struct node *temp=head;
        int result=head->data;
        head=NULL;
        tail=NULL;
        free(temp);
        return result;
    }
    struct node *temp=head;
    int result=temp->data;
    head->prev=NULL;
    head=head->next;

    free(temp);
    return result;
}

// Deleteing a node at end

int list::deleteatend(){
    if(head==NULL){
        printf("List is empty\n");
        return -1;
    }
    if(tail==head){
        int result=head->data;
        deleteatbeg();
        return result;
    }
    struct node *temp=tail;
    int result=temp->data;
    tail->next=NULL;
    tail=tail->prev;

    free(temp);
    return result;
}

// Deleting a node at given position

int list :: deleteatpos(int pos){
    if(pos<1){
        printf("Invalid position\n");
        return 0;
    }
    if (pos==1){
        int result = head->data;
        deleteatbeg();
        return result;
    }
    struct node *temp = head;
    int i =1;
    while(i<pos-1 && temp!=NULL){
        temp = temp->next;
        i++;
    }
    
    if(tail==temp->next){
        temp = temp->next;
        int result = temp->data;
        deleteatbeg();
        return result;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    int result = del->data;
    temp = del->next;
    temp->prev = del->prev;
     return result;

}

// Searching a node in the list

int list::search(int target){
    if(head==NULL){
        printf("List is empty\n");
        return -1;
    }
    struct node *temp=head;
    int count=1;
    while(temp!=NULL){
        if(temp->data==target){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return 1;
}



