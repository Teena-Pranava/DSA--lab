#include<cstdio>
#include<cstdlib>

class list{
    private:
    struct node{
        int data;
        struct node *next;
    };
    struct node *front;
    struct node *rear;

    public:
    list(){
        front=NULL;
        rear=NULL;
    }
    int enque(int);
    int deque();
    int peek();

};

int main(){
    list obj;
    int choice,value;

    do{
        printf("\nMENU\n");
        printf("1)Enque\n");
        printf("2)Deque\n");
        printf("3)Peek\n");
        printf("4)Exit\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to push :");
                scanf("%d",&value);
                obj.enque(value);
                break;
            
            case 2:
                value=obj.deque();
                if(value!=0){
                    printf("Popped element is :%d",value);
                }
                break;
            
            case 3:
                value=obj.peek();
                if(value!=0){
                    printf("Peek value of stack is :%d",value);
                }
                break;

            case 4:
                printf("Exiting\n");
                break;
            
            default:
                printf("Invalid choice\n");

        }
    }while(choice!=4);

    return 0;
}

int list::enque(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=NULL;

    if(front==NULL){
        front=newnode;
        rear=newnode;
        
    }
    
    rear->next=newnode;
    rear=newnode;

    return 0;

}

int list::deque(){
    if(front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    struct node *temp=front;
    int result=front->data;
    front=front->next;

    if(front==NULL){
        rear=NULL;
    }

    free(temp);
    return result;

}

int list::peek(){
    if(front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}