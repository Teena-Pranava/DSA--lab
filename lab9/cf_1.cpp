// Program to find the no of winners in a game


#include<cstdio>

int findMin(int a,int b);

void  processTectCase(){
    int n,q;

    scanf("%d %d",&n,&q);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    
    while(q--){
        int y;
        scanf("%d",&y);
    
        int result=findMin(arr[0]-1,y);
        printf("%d ",result);
    }

}                                                                                      
// Function to find the minimum

int findMin(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int cases;

    printf("Enter no of test cases :");
    scanf("%d",&cases);

    while(cases--){
        processTectCase();
    }
    return 0;
}