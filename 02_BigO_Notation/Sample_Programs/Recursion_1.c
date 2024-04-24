#include <stdio.h>
#include <conio.h>

int factorial(int n) {
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    else 
    {
        // Recusion depends upon n 
        // As int n will increase, the runtime of the loop will increase gradually
        // Therefore, Below code has a time complexity of Big O(n)
        return n * factorial(n - 1);
    }
}

int main () {
    int n = 10;
    int result = factorial(n);
    printf("%d", result);   
    return 0;
}