#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int low, int hight){
    
    int pivot = arr[hight];
    int i = (low-1);
    
    for(int j = low; j<= hight - 1; ++j){
        
        if(arr[j] <= pivot){
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[hight]); 

    return (i+1);
}

void quicksort(int arr[], int l, int h){
    
    if(l < h){
        int pi = partition(arr, l, h);
        
        quicksort(arr, l, pi -1);
        quicksort(arr, pi+1, h);
    }
    
}

int main()
{
    int a[20];
    
    for (int b=0; b< 20; ++b){
        
        a[b] =  rand() %20;  
        printf("\na(%d)= %d", b, a[b]);
    }
    
     quicksort(a, 0, 20-1);
     
     printf("\nquick\n");
    for (int b=0; b< 20; ++b){
        
        printf("\na(%d)= %d", b, a[b]);
    }
    
}
