// Implementing stack ADT using an array

#include<cstdio>
#include<cstdlib>
#define max 5

class stack{
    int arr[max];
    int top;

    public:
    stack(){
        top=-1;
    }

    int push(int);
    int pop();
    int peek();
    
};

int main(){
    stack obj;
    int choice,value;

    do{
        printf("\nMENU\n");
        printf("1)Push\n2)Pop\n3)Peek\n4)Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to push:");
                scanf("%d",&value);
                obj.push(value);
                break;

            case 2:
                value=obj.pop();
                if(value!=0){
                    printf("Popped value is :%d",value);
                }
                break;

            case 3:
                value=obj.peek();
                if(value!=0){
                    printf("Peek value is : %d",value);
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

// Pushing a value into a stack

int stack::push(int value){
    if(top==max-1){
        printf("Stack is full\n");
        return -1;
    }
    else{
        top++;
        arr[top]=value;
    }
    return 0;
}


// Removing the top element from stack

int stack::pop(){
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    int value;
    value=arr[top];
    return value;
}

// Finding the top element in a stack

int stack::peek(){
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return arr[top];
}