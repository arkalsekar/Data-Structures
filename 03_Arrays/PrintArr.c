#include <stdio.h>
#include <conio.h>

int printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("The Value at index[%d] is = %d \n", i, arr[i]);
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = (sizeof(arr) / 4);
    
    // Printing the Arr
    printArr(arr, n);   
    return 0;
}