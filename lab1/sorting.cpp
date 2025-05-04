#include<cstdio> 


void bubblesort(int arr[],int size); 
void selectionsort(int arr[],int size); 
void insertionsort(int arr[],int size); 
void display(int arr[],int size); 

int main(){ 
int size; 

printf("Enter size of array"); 
scanf("%d",&size); 

int arr[size]; 
printf("Enter elememts of array"); 
for(int i=0;i<size;i++){ 
scanf("%d",&arr[i]); 
} 

while(1)
{ 
printf("Enter 1 for bubblesort\n"); 
printf("2 for selection sort\n"); 
printf("3 for insertion sort\n"); 
printf("4 for exit\n"); 

int choice; 
printf("Enter choice\t"); 
scanf("%d",&choice); 

 

switch(choice){ 
case 1: 
bubblesort(arr,size); 
display(arr,size); 
break; 

case 2: 
selectionsort(arr,size); 
display(arr,size); 
break; 

case 3: 
insertionsort(arr,size); 
display(arr,size); 
break; 

case 4: 
return 0; 
break; 

default: 
printf("Enter valid choice"); 
break; 
} 

} 

return 0; 

} 

//sorting the array using bubblesort 

void bubblesort(int arr[],int size){ 
    for(int i=0;i<size-1;i++){ 
        for(int j=0;j<size-i-1;j++){ 
            if(arr[j]>arr[j+1]){ 
                int temp=arr[j]; 
                arr[j]=arr[j+1]; 
                arr[j+1]=temp; 

        }
        } 
    } 
} 
//sorting array using selectionsort 
void selectionsort(int arr[],int size){ 
for(int i=0;i<size-1;i++){ 
int smallindex=i; 
for(int j=i+1;j<size;j++){ 
if(arr[j]<arr[smallindex]){ 
smallindex=j; 
} 
} 
int temp1=arr[i]; 
arr[i]=arr[smallindex]; 
arr[smallindex]=temp1; 

} 

} 

//sorting array using insertionsort 

void insertionsort(int arr[],int size){ 
for(int i=1;i<size;i++){ 
int curr=arr[i]; 
int prev=i-1; 
while(prev>=0 && arr[prev]>curr){ 
arr[prev+1]=arr[prev]; 
prev--; 

} 
arr[prev+1]=curr; 
} 

}
// Display
void display(int arr[],int size){ 
for(int i=0;i<size;i++){ 
printf("%d\n",arr[i]); 

} 

} 

