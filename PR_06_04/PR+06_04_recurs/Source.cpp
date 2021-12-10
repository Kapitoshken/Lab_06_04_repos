#include <iostream>

void initArray(int*& array, int size, int index);
void printArray(int* array, int size, int index);
void solveSum(int*& array, int size, int index, int& sum);
void setMaxIndex(int* array, int size, int index, int& maxIndex, int& max);
void setMinIndex(int* array, int size, int index, int& minIndex, int& min);
void solveMulti(int*& array, int size, int index, int& multi);
void sortArray(int* array, int left, int right);

int main() 
{
    int size, sum = 0, multi = 1;
    std::cout << "Input array size:\t";
    std::cin >> size;
    int* array = new int[size];
    initArray(array, size, 0);
    int min = array[0];
    int max = array[0];
    int minIndex = 0, maxIndex = 0;
    setMinIndex(array, size, 0, minIndex, min);
    setMaxIndex(array, size, 0, maxIndex, max);
    std::cout << "Before: ";
    printArray(array, size, 0);
    solveSum(array, size, 0, sum);
    if (minIndex > maxIndex) 
    {
        int temp = minIndex;
        minIndex = maxIndex;
        maxIndex = temp;
    }
    solveMulti(array, maxIndex, minIndex + 1, multi);
    std::cout << "\nBelow zero sum: " << sum;
    std::cout << "\nBetween minMax multi: " << multi;
    std::cout << "\nAfter sort: ";
    sortArray(array, 0, size - 1);
    printArray(array, size, 0);
}

void initArray(int*& array, int size, int index) 
{
    if (index < size) 
    {
        array[index] = rand() % 10 - 5;
        if (index + 1 >= size) 
        {
            return;
        }
        else 
        {
            initArray(array, size, index + 1);
        }
    }
}

void printArray(int* array, int size, int index) 
{
    if (index < size) 
    {
        std::cout << array[index] << " ";
        if (index + 1 >= size) 
        {
            return;
        }
        else 
        {
            printArray(array, size, index + 1);
        }
    }
    else 
    {
        return;
    }
}

void solveSum(int*& array, int size, int index, int& sum) 
{
    if (index < size) 
    {
        if (array[index] < 0) 
        {
            sum += array[index];
        }
        if (index + 1 >= size) 
        {
            return;
        }
        else 
        {
            solveSum(array, size, index + 1, sum);
        }
    }
}

void solveMulti(int*& array, int size, int index, int& multi) 
{
    if (index < size) 
    {
        multi *= array[index];
        if (index + 1 >= size) 
        {
            return;
        }
        else 
        {
            solveMulti(array, size, index + 1, multi);
        }
    }
}

void setMinIndex(int* array, int size, int index, int& minIndex, int& min) 
{
    if (index < size) 
    {
        if (array[index] < min) 
        {
            min = array[index];
            minIndex = index;
        }
        if (index + 1 >= size) 
        {
            return;
        }
        else 
        {
            setMinIndex(array, size, index + 1, minIndex, min);
        }
    }
}

void setMaxIndex(int* array, int size, int index, int& maxIndex, int& max) 
{
    if (index < size) 
    {
        if (array[index] > max) 
        {
            max = array[index];
            maxIndex = index;
        }
        if (index + 1 >= size) 
        {
            return;
        }
        else 
        {
            setMaxIndex(array, size, index + 1, maxIndex, max);
        }

    }
}

void sortArray(int* array, int left, int right) 
{
    int pivot; 
    int lHold = left; 
    int rHold = right; 
    pivot = array[left];
    while (left < right) 
    {
        while ((array[right] >= pivot) && (left < right))
            right--;
        if (left != right) 
        {
            array[left] = array[right];
            left++; 
        }
        while ((array[left] <= pivot) && (left < right))
            left++; 
        if (left != right) 
        {
            array[right] = array[left]; 
            right--; 
        }
    }
    array[left] = pivot; 
    pivot = left;
    left = lHold;
    right = rHold;
    if (left < pivot) 
        sortArray(array, left, pivot - 1);
    if (right > pivot)
        sortArray(array, pivot + 1, right);
}
