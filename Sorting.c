#include<stdio.h>
#include<stdlib.h>


void selection(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if (arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
        }
    }
}

void bubblesort(int arr[],int n){
    int i,j,temp;
    for ( i = n-2; i >=0 ; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
    
}

void insertion(int arr[],int n){
    int k,j,temp;
    for(k=1;k<n;k++){
        temp=arr[k];
        j=k-1;
        while (j>=0 && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}

void printArr(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}


void main(){
    int i,n;
    printf("Enter the size ");
    scanf("%d",&n);
    int arr[n];
    printf("Eneter the element");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("\nArr after sorting");
    printf("\nBy selection sort");
    selection(arr,n);
    printArr(arr,n);

    printf("\nBy bubble sort");
    bubblesort(arr,n);
    printArr(arr,n);

    printf("\nBy insertion sort");
    insertion(arr,n);
    printArr(arr,n);
}