// BWS Purchase Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Helper.h"
#include "BubbleSort.h"

int main()
{
    hidecursor();
    int arr[] = { 5,546,36,86,25,886,235,34 };
    int len = sizeof(arr) / sizeof(arr[0]);
    BubbleSort sortalgo;
    sortalgo.sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
