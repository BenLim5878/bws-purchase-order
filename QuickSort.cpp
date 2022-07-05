#include "QuickSort.h"

void swap(int arr[],int low, int high) {
	int temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

void QuickSort::sort(int arr[], int low, int high)
{
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);
		sort(arr, low, pos - 1);
		sort(arr, pos + 1, high);
	}
}

int QuickSort::partition(int arr[], int low, int high, int pivot)
{
	int i = low;
	int j = low;
	while (i <= high) {
		if (arr[i] > pivot) {
			i++;
		}
		else {
			swap(arr,i, j);
			i++;
			j++;
		}
	}
	return j - 1;
}
