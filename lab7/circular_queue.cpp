// Implementing circular queue ADT using an array

#include<cstdio>
#define size 5

class queue{
    int arr[size];
    int front;
    int rear;

    public:
    queue(){
        front=-1;
        rear=-1;
    }
    int enque(int);
    int deque();
    int peek();

};

int main(){
    queue obj; 
    int choice,value;

    do{
        printf("MENU CARD\n");
        printf("Enter 1 to insert an element in queue\n");
        printf("Enter 2 to delete an element in queue\n");
        printf("Enter 3 to peek first element\n");
        printf("Enter 4 to exit\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to insert :");
                scanf("%d",&value);
                obj.enque(value);
                break;

            case 2:
                value=obj.deque();
                if(value!=0){
                    printf("Deleted element is : %d\n",value);
                }
                break;

            case 3:
                value=obj.peek();
                if(value!=0){
                    printf("First element is : %d\n",value);
                }
                break;

            case 4:
                printf("Exiting\n");
                break;

            default:
            printf("Enter valid choice\n");
                
        }

    }while(choice!=4);
}

// Function to enque an element

int queue::enque(int value){
    if((rear+1)%size==front){
        printf("Queue is full\n");
        return -1;
    }
    if(front==-1){
        front++;
        rear=(rear+1)%size;
        arr[rear]=value;
        return 0;
    }
    rear=(rear+1)%size;
    arr[rear]=value;
    return 0;
}

// Function to deque an element

int queue::deque(){
    if(front==-1){
        printf("Queue is empty\n");
        return-1;
    }

    if(front==rear){
        int result=arr[front];
        front=-1;
        rear=-1;
        return result;
    }

    int result=arr[front];
    front=(front+1)%size;
    return result;

}

// Function to peek an element

int queue::peek(){
    if(front==-1){
        printf("Queue is empty\n");
        return -1;
    }

    return arr[front];

}
