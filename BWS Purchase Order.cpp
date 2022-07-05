// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Helper.h"
#include "LinkedList.h"
#include "Administrator.h"

int binarySearch(int arr[] ,int l, int r, int x) {
    if (l > r) {
        return -1;
    }
    int mid = (l + r) / 2;
    if (arr[mid] == x) {
        return mid;
    }
    else if (x < arr[mid]) {
        binarySearch(arr, l, mid - 1, x);
    }
    else {
        binarySearch(arr, mid + 1, r, x);
    }
}


int main()
{
    int arr[] = { 2,7,9,10,26,129,644,4566 };
    int res = binarySearch(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1, 432);
}
