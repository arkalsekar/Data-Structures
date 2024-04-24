#include <stdio.h>
#include <conio.h>

int printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("The Value at index[%d] is = %d \n", i, arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int reverseArr(int arr[], int n) {
    for (int i = 0; i < n / 2; i++)
    {
        swap(&arr[i], &arr[n-i]);
        // printf("The Value at index[%d] is = %d \n", i, arr[i]);
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = (sizeof(arr) / 4);
    printReverseArr(arr, n);
    printArr(arr, n);   
    return 0;
}