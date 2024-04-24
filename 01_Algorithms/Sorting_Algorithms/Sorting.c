#include <stdio.h>
#include <conio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


int Sort(int arr[], int n) {
	for (int i = 0; i < n; i++){
		int currentMin = arr[0];
		if (arr[i] < currentMin) {
			swap(&arr[i], &currentMin);
			return 1;
			Sort(arr, n);
		}
	break;
	}
	return 0;
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
}

int main() {
	int arr[5] = {5, 4, 3, 2, 1};
	int n = 5;
	Sort(arr, n);
	printArr(arr, n);
	printf("Hello World");
	return 0;
}