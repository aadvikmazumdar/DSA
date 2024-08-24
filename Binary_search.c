#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int BinarySearch(int arr[],int n,int key){
    int l = 0;
    int h = n-1;
    while(l <= h){
        int mid=(l+h)/2;
        if(arr[mid] == key){
            return mid;
            }
        if(key < arr[mid]){
            h=mid-1;
            }
        else{
            l=mid+1;
            }
    }
    return -1;
}
int main(){
    int arr[]={11,22,33,45,54,65,76,87,98,100};
    int n = sizeof(arr);
    int key;

    printf("%d",&arr);
    printf("\n Enter the number to find: ");
    scanf("%d",&key);


    int result = BinarySearch(arr,n,key);

    if(result == -1){
        printf("\n Element is not in the array");
    }
    else{
        printf("\n element is present in the list at %d",result);
    }
    return 0;
}
