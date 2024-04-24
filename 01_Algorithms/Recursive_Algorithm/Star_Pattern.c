#include <stdio.h>

// Print Triangular Star Patterns using Loops
void printStar(int n) {
	for (int i =0; i < n; i ++)
	{
		for (int j = 0; j < n -1; j++) 
		{
			printf("*");
		}
		printf(" \n ");
	}
}



int main () {
	printf("Hello World \n");
	printStar(5);
	return 0;
}