#include <stdio.h>

int find_nth_number(int a, int d, int n) {
	if (n == 0) 
	{
		return 0;
	}
	
	else if (n == 1) 
	{
		return a;
	}
	
	else 
	{
		return a + (n - 1) * d;
	}
}

int main () {
	int a, d, n;
	
	printf("Enter a First Term of an AP \n");
	scanf("%d", &a);
	
	printf("Enter a Term Difference of an AP \n");
	scanf("%d", &d);
	
	
	printf("Enter a Term Number you want of an AP \n");
	scanf("%d", &n);
	
	printf("%d", find_nth_number(a, d, n));
	
	
}