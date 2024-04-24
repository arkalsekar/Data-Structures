#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

// Traversal
// Visiting all the Elements of the Array atleast one time.
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
}

// Insering Initial Values
int insertInitial(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the Value at index[%d] \n", i);
        scanf("%d", &arr[i]);
    }
}

// Insertion at an Index
// Inserting Extra Elements in the Array
int insert(int arr[], int *size, int capacity, int value, int index)
{
    if (*size >= capacity)
    {
        return -1;
    }

    else
    {
        for (int i = (int)*size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        *size = *size + 1;
    }
}

// Append
// Inserting an Element at last of the array
void append(int arr[], int *size, int value)
{
    arr[*size] = value;
    *size = *size + 1;
}

// Deletion
// Deleting Elements from the Array
int delete(int arr[], int index, int *size, int capacity)
{
    if (index > capacity)
    {
        return -1;
    }
    for (int i = index; i < *size; i++)
    {
        arr[i] = arr[i + 1];
    }
    *size = *size -1;
    return 1;
}

// Reversing an Array 
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

// Searching [Linear Search, Binary Search]
int linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return 1;
        }
    }
    return -1;
    
}

int main()
{
    int capacity, size;

    printf("Enter the total Capacity of the Array \n");
    scanf("%d", &capacity);

    printf("Enter the Size of the Array \n");
    scanf("%d", &size);

    // Creating the Array
    int arr[capacity];

    // Inserting Initial Values
    insertInitial(arr, size);

    printArr(arr, size);

    // Insert more Values
    // insert(arr, &size, capacity, 100, 2);

    // Appending Values
    // append(arr, &size, 100);
    
    // Deleting an Item
    int del_index;
    printf("Enter the Index your want to Delete \n");
    scanf("%d", &del_index);
    delete(arr, del_index, &size, capacity);

    // Printing the Array
    printArr(arr, size);
    return 0;
}