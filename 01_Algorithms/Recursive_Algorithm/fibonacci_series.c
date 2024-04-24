#include <stdio.h>

int fibonacci(int n) {
	if (n == 0) 
	{
		return 0;
	}
	
	else if (n == 1) 
	{
		return 1;
	}
	
	else 
	{
		return n + fibonacci(n -1);
	}
}

int main () {
	int i;
	printf("Enter a Number \n");
	scanf("%d", &i);
	
	printf("%d", fibonacci(i));
	
	
}