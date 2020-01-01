#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int *arr,int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
////int main()
////{
////	/*
////	int arr[10] = {21,324,33,11,22,-90,78,17};
////	bubble_sort(arr,10);
////	for (int i = 0; i < 10; i++) {
////		printf("%d\n",arr[i]);
////	}
////	*/
////	return 0;
////}