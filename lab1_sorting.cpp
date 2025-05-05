/*1. Write a C++ menu-driven program to sort a given array in ascending order. Design proper functions, maintain boundary conditions, and follow coding best practices. The menus are as follows,

a.       Bubble Sort

b.      Selection Sort

c.       Insertion Sort

d.      Exit
*/

 #include <stdio.h>
#include "sort.h"

int main(){
    int choice , n;

    //if n is negative or zero input is taken again
    do{
        printf("Enter valid number of elements \n");
        scanf("%d",&n);
    }while(n<=0);

    int arr[n];
    printf("Enter %d elements of array \n",n);
    for(int i=0; i<n;i++){
        scanf("%d",&arr[i]);
    }
    
//menu of the program in a loop

    do{
        printf(" Menu:\n");
        printf("1)Bubble sort \n");
        printf("2)Insertion sort\n");
        printf("3)Selection sort \n");
        printf("4)Exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                bubblesort(arr,n);
                printf("Bubblesorted array is\n");
                printarray(arr,n);
                break;

            case 2:
                selectionsort(arr,n);
                printf("Selectionsort array is\n");
                printarray(arr,n);
                break;
            
            case 3:
                insertionsort(arr,n);
                printf("Insertionsort array is\n");
                printarray(arr,n);
                break;

            case 4:
                printf("Operation exited \n");
                break;

            default:
                printf("Invalid option \n");
                break;
        }
        
    }while(choice!=4);

    return 0;
}