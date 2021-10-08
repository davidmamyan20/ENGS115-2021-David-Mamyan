#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int n)
{
	int i,j;
	for (i = 0; i < n-1; i++)
	for(j = 0; j < n-1; j++)
	if(arr[j] > arr[j+1])
	swap(&arr[j], &arr[j+1]);
}

void print_array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d",arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {83,59,20,12,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,n);
	printf("Sorted array:\n");
	print_array(arr,n);
	return 0;
}
