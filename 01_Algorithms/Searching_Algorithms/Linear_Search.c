#include <stdio.h>  

int linearSearch(int arr[], int n, int k)    
{    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k )
        {
            printf("Element %d Found at %d", k, i);
            return 1;
            // break;
        }
    }    
    return -1;     
}   

int main() {  

  int arr[10] = {11, 14, 25, 30, 40, 41, 52, 57, 70, 77}; // given array  
  int n = sizeof(arr) / sizeof(arr[0]);              // size of array 
  int k = 70;                                        // value to be searched  
  linearSearch(arr, n, k);
  
  return 0;
}  