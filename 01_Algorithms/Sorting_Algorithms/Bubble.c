#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bubbleSortOptimized(int *arr, int n)
{
    int isSorted = 0;
    for (int j = 0; j < n - 1; j++)
    {
        printf("Running Step : %d \n", j);
        for (int i = 0; i < n - 1 - j; i++)
        {
            isSorted = 1;
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = 0;
                // printf("Current Largest is %d \n", largest);
            }
            if (isSorted)
            {
                return;
            }
        }
    }
    printf("Array has been Sorted Successfully \n");

}

void bubbleSort(int *arr, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        printf("Running Step : %d \n", j);
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    printf("Array has been Sorted Successfully \n");
}

void main()
{
    // int arr[5] = {5, 4, 3, 2, 1};
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    // bubbleSort(arr, n);
    bubbleSortOptimized(arr, n);
    
    for (int k = 0; k < n; k++)
    {
        printf("%d \t", arr[k]);
    }
}