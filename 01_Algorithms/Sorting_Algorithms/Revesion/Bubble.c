#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	
    printf("Array has been Sorted Successfully \n");
}

void main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    // int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);
    // bubbleSortOptimized(arr, n);
    
    for (int k = 0; k < n; k++)
    {
        printf("%d \t", arr[k]);
    }
}