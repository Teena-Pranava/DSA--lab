#include<stdio.h>
#include<stdlib.h>

class list{
    int *arr;
    int cur;
    int n;

public:
    list(){
        cur=-1;
        n=5;
        arr=(int *)malloc(sizeof(int));
    }
    int insertatbeg(int value);
    int insertatend(int value);
    int insertatpos(int value,int index);
    int delatbeg();
    int delatend();
    int delatpos(int index);
    void display();
    int search(int target);
    int rotate(int k);
};

int main(){
    int choice=1;
    list list1;

    while(choice){
        printf("enter your choice\n");
        printf("1)insertion at beg\n");
        printf("2)insertion at end\n");
        printf("3)insertion at pos\n");
        printf("4)del at beg\n");
        printf("5)del at end\n");
        printf("6)del at pos\n");
        printf("7)display\n");
        printf("8)search\n");
        printf("9)rotate\n");
        printf("10)exit\n");

        int choice;
        printf("enter your choice:");
        scanf("%d",&choice);

        int value,target,index,k;

        switch(choice){
            case 1:
                printf("enter value to insert:\n");
                scanf("%d",&value);
                list1.insertatbeg(value);
                list1.display();
                break;
            case 2:
                printf("enter value to insert:\n");
                scanf("%d",&value);
                list1.insertatend(value);
                list1.display();
                break;
            case 3:
                printf("enter value to insert:\n");
                scanf("%d",&value);
                printf("enter index to insert:\n");
                scanf("%d",&index);
                list1.insertatpos(value,index);
                list1.display();
                break;
            case 4:
                printf("deleted value %d\n",list1.delatbeg());
                list1.display();
                break;
            case 5:
                printf("deleted value %d\n",list1.delatend());
                list1.display();
                break;
            case 6:
                printf("enter index to delete:\n");
                scanf("%d",&index);
                printf("deleted value %d\n",list1.delatpos(index));
                list1.display();
                break;
            case 7:
                list1.display();
                break;
            case 8:
                printf("enter element to search:\n");
                scanf("%d",&target);
                list1.search(index);
                list1.display();
                break;
            case 9:
                printf("enter no of elements to rotate:\n");
                scanf("%d",&k);
                list1.rotate(k);
                list1.display();
            case 10:
                break;
            default:
                printf("enter valid choice\n");

                
        }
    }
    return 0;

}

int list::insertatbeg(int value){
    if(cur==n-1){
        printf("list is full");
        return -1;
    }
    for(int i=cur+1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    cur++;
    return 1;

    }
int list::insertatend(int value){
    if(cur==n-1){
        printf("list is full");
        return -1;
    }
    arr[cur-1]=value;
    cur++;
    return 1;

}

int list::insertatpos(int value,int index){
    if(index>=cur || index<0){
        printf("invalid index");
    }
    if(cur==n-1){
        printf("array is full");
        return -1;
    }
    for(int i=cur+1;i<index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=value;
    cur++;
    return 1;
}

int list::delatbeg(){
    if(cur=-1){
        printf("list is empty");
        return -1;
    }
    int temp=arr[0];
    for(int i=0;i<cur;i++){
        arr[i]=arr[i+1];
    }
    cur--;
    return temp;

}
int list::delatend(){
    if(cur=-1){
        printf("list is full");
        return -1;
    }
    int temp=arr[cur];
    cur--;
    return temp;
}
    
int list::delatpos(int index){
    if(cur=-1){
        printf("list is empty");
        return -1;
    }
    int temp=arr[index];
    for(int i=index;i<cur;i++){
        arr[i]=arr[i+1];
    }
    cur--;
    return -1;
}
void list::display(){
    printf("list:");
    for(int i=0;i<=cur;i++){
        printf("%d\t",arr[i]);
    }
}

int list::search(int target){
    for(int i=0;i<=cur;i++){
        if(arr[i]==target);
        return 1;
    }
    return -1;
}

int list::rotate(int k){
    for(int i=0;i<k;i++){
        int temp=arr[cur+1];
    
    for(int j=cur+1;j>0;j--){
        arr[j]=arr[j-1];
    }
    arr[0]=temp;
    }
    return 1;
}
