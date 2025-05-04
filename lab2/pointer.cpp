#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void palindrome(int *num);
void amstrong(int *num);
void perfect(int *num);

int main(){
    int *choice=(int*)malloc(sizeof(int));
    int *number=(int*)malloc(sizeof(int));

    do{
        printf("Enter 1 to check palindrome num\n");
        printf("Enter 2 to chech amstrong num\n");
        printf("Enter 3 to check perfect num\n");
        printf("Enter 4 to exit\n");
        printf("Enter choice :");
        scanf("%d",choice);

    switch(*choice){
        case 1:
            if(*number<0){
                printf("Enter valid num");
            }else{
                palindrome(number);
            }break;
        case 2:
            if(*number<0){
                printf("Enter valid num");
            }else{
                amstrong(number);
            }break;
        case 3:
            if(*number<0){
                printf("Enter valid num");
            }else{
                perfect(number);
            }break;
        case 4:
            printf("Exit");
            break;
        default:
            printf("Invalid choice");
        
    }
    }
    while(*choice!=4);
        free(choice);
        free(number);
    
}

void palindrome(int *num){
    int *temp=(int*)malloc(sizeof(int));
    int *rem=(int*)malloc(sizeof(int));
    int *num2=(int*)malloc(sizeof(int));

    *temp=*num;
    *rem=0;
    *num2=0;

    while(temp!=0){
        *rem=(*temp)%10;
        *num2=(*num2)*10+(*rem);
        *temp=*temp/10;

    }
    if(*num2==*num){
        printf("It is a palindrome ");
    }else{
        printf("It is not a palindrome");
    }
    free(temp);
    free(num2);
    free(rem);
}
void amstrong(int *num){
    int *rem=(int*)malloc(sizeof(int));
    int *temp=(int*)malloc(sizeof(int));
    int *num2=(int*)malloc(sizeof(int));
    int *count=(int*)malloc(sizeof(int));

    *temp=*num;
    *num2=0;
    *count=0;
    *rem=0;

    while(*temp!=0){
        *count++;
        *temp=*temp%10;
    }
    while(temp!=0){
        *rem=(*temp)%10;
        *num2=(*num2)+pow(*rem,*count);
        *temp=*temp/10;
    }
    if(*num2==*num){
        printf("It is an amstrong number");
    }else{
        printf("It is not an amstrong number");
    }
    free(temp);
    free(num2);
    free(count);
    free(rem);
}
void perfect(int *num){
    int *i=(int*)malloc(sizeof(int));
    int *sum=(int*)malloc(sizeof(int));

    *i=1;
    *sum=0;
    while((*i)<(*sum)){
        if((*sum)%(*i)==0){
            *sum+=*i;
        }
        (*i)++;
    }
    if(*sum==*num){
        printf("It is a perfect number");
    }else{
        printf("It is mot a perfect number");
    }
    free(i);
    free(sum);
}