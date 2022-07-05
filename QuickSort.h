#pragma once
class QuickSort
{
public:
	void sort(int arr[], int low, int high);
private:
	int partition(int arr[], int low, int high, int pivot);
};

