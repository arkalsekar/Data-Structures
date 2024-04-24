#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void insertionSort(int *arr, int n) {
    // Number of Steps
    int steps = n;

    for (int i = 1; i < steps; i++)
    {   
        printf("Currently on Step %d \n" ,i);
        for (int j = i; j > 0 ; j--)
        {
            printf("Checking if %d < %d \n", arr[j - 1], arr[j]);
            if (arr[j -1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }   
        }   
    }    

    printf("Insertion Sort is Completed \n");
}

int main () {
    int arr[5] = {111, 2, 440, 55, 66};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);
    
    for (int k = 0; k < n; k++)
    {
        printf("%d \t", arr[k]);
    }
    
    return 0;
}