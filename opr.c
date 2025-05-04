#include<stdio.h>

int main(){
int num;
int i;

printf("enter a num:");
scanf("%d",&num);

if(num==10){
    printf("number is 10\n");
    }else if(num > 10){
    printf("number is > 10\n");
}else{
    printf("number is < 10");
}

switch (num)
{
case 10:
case 11:
case 12:
printf("entered number is >= 10 and <= 12\n");
break;
case 13:
case 14:
case 15:
printf("enterd number is >= 13 and < = 15\n");
break;
default:
printf("default case\n");
/*
printf("number is 10 incase 10\n");

case 11: 
printf("number is 11 in case 11\n");

default:
printf("default case\n");
*/
}

printf("\nentered number is > 10 :%s",(num>10)? "true":(num<10)?" < 10":" == 10");

for (i=0;i<num;i++)
{
    printf("%d\n",i);
}
printf("starting while loop\n");
i=0;
while(i<num)
{
    printf("%d\n", i);
    i++;
}
return 0;

}