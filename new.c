#include<stdio.h>

int main(){
int i;

int num=20;
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

do
{
printf("%d\n",i);
    /* code */
} while (i<num);

return 0;

}