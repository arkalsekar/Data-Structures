#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Creating a Abstract Data Type
struct customArr
{
    int size;
    int capacity;
    int *ptr;
};

// Create an Array
void createArray(struct customArr *a, int capacity, int size)
{
    (*a).capacity = capacity;
    (*a).size = size;
    (*a).ptr = (int *) malloc(capacity * sizeof(int));
}

// Set Values for All the Array
void setVal(struct customArr *a)
{
    int val;
    for (int i = 0; i < (*a).size; i++)
    {
        printf("Enter the Value at index [%d] \n", i);
        scanf("%d", &val);
        a->ptr[i] = val;
    }
}

// Print all the Elements of the Array
void geAll(struct customArr *a)
{
    for (int i = 0; i < a->size; i++)
    {
        printf("%d \n", (*a).ptr[i]);
    }
}

// Get Specific Array
void get(struct customArr *a, int n) {
    for (int i = 0; i < a->size; i++)
    {
        if (i == n)
        {
            printf("%d", a->ptr[i]);
        }
    }
}

int main()
{
    struct customArr marks;
    int capacity, size, index;

    // Get the capacity from the user
    printf("Enter the Capacity of the Array \n");
    scanf("%d", &capacity);

    // Get the Size tobe used
    printf("Enter the Size to be used of the Array \n");
    scanf("%d", &size);

    // Finally Create the Array 
    createArray(&marks, capacity, size);
    
    // Set all the Values
    setVal(&marks);
    
    // Print all the Values
    geAll(&marks);
    
    // Get Specific Values
    printf("Enter the Index of the Array you want \n");
    scanf("%d", &index);

    get(&marks, index);
    return 0;
}