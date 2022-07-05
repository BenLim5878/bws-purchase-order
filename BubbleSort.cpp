#include "BubbleSort.h"

void BubbleSort::swap(int arr[], int fpos, int spos) {
	int t = arr[fpos];
	arr[fpos] = arr[spos];
	arr[spos] = t;
}

void BubbleSort::sort(int arr[], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr,j, j+1);
    }
}


