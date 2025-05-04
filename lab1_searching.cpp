#include <cstdio>
#include "sort.h"

//linear search
void linearsearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("Element found \n");
            return;
        }
    }
    printf("Element not found. \n");
}

//binary search
void binarysearch(int arr[], int n, int key){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid= left+(right-left)/2;
        if(arr[mid]==key){
            printf("Element found \n",mid);
            return;
        }
        if(key>arr[mid]){
            left=mid+1;
        }
        if(key<arr[mid]){
            right=mid-1;
        }
    }
    printf("Element not found. \n");
}

int main(){
    int n;
    printf("Enter no. of elements: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    //sorting the array
    bubblesort(arr,n);

    int choice, key;
    
    //menu driven program with call functions for searching
    do{
        printf("Menu: \n 1.Linear search \n 2.Binarysearch \n 3.Exit \n Enter your choice: \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                linearsearch(arr, n, key);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                binarysearch(arr, n, key);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);
    return 0;  
}