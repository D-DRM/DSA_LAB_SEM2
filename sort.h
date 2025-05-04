//LAB 1
#include <iostream>
#include <cstdio>
using namespace std;
#ifndef SORT_H
#define SORT_H

//Bubble sort function definition
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//selectionsort definition
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minindex]>arr[j]){
                minindex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
}

//insertion sort definition
void insertionsort(int arr[],int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//printing the sorted array
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

#endif