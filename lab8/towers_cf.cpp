
// Program to find largest amount of blocks in tower 1 after the moves

#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int cases,towers;

    printf("Enter no of cases :");
    scanf("%d",&cases);

    for(int i=1;i<=cases;i++){
        printf("Enter details of testcase %d:-\n",i);
        printf("Enter number of towers :");
        scanf("%d",&towers);

        int arr[towers];

        for(int i=0;i<towers;i++){
            printf("Enter number of blocks in tower %d:",i+1);
            scanf("%d",&arr[i]);
        }

        sort(arr+1,arr+towers);

        for(int i=0;i<towers;i++){
            if(arr[i]>arr[0]){
                if((arr[i]+arr[0])%2==0){
                    arr[0]=(arr[i]+arr[0])/2;
                }
                else{
                    arr[0]=(arr[i]+arr[0])/2 +1;
                }
            }
        }
        printf("Number of blocks in tower 1 :%d\n\n",arr[0]);
    }
    return 0;
}