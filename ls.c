#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 20
int main(){
int arr[size],n,num,found=0,pos=-1;

printf("\n Enter the number of elements: ");
scanf("%d",&n);

printf("\n Enter the elements: ");
for(int i = 0; i < n; i++){
    scanf("%d",&arr[i]);
}

printf("\n Enter the number to be searched: ");
scanf("%d",&num);

for(int i = 0; i < n; i++){
    if(arr[i] == num){
        found = 1;
        pos = i;
        printf("\n %d is found at position %d",num,i+1);
        break;
    }
}
if(found == 0){
    printf("\n No such number was found");
}

return 0;
}