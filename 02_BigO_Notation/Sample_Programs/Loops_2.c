#include <stdio.h>
#include <conio.h>

int main () {
    int n = 100;

    // Since there are two loop and they are one below the other and they only depend on n
    // As int n will increase, the runtime of the loop will increase gradually
    // Therefore, Below code has a time complexity of Big O(n)

    for (int i = 0; i < n; i++)
    {
        printf("%d \n", i);
    }

    for (int i = 2; i < n; i++)
    {
        printf("%d \n", i);
    }
    
    return 0;
}