#include <stdio.h>
#include <conio.h>

// Array Traversal means printing an Array
int printArr(int arr[], int n) {

    // Traversal of an Array using For Loop
    for (int i = 0; i < n; i++)
    {
        printf("The Value at index[%d] is = %d \n", i, arr[i]);
    }

    // Traversal using While Loop
    int j = 0;
    while (j < n)
    {
        printf("%d \t", arr[j]);
        j++;
    }
        
    // Traversal of an Array using Do While Loop
    int k = 0;
    do
    {
        printf("%d", arr[k]);
        k++;
    } while (k < n);
    
}

int main()

{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = (sizeof(arr) / 4);
    printArr(arr, n);   
    return 0;
}