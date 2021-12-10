#include <iostream>

int* initArray(int size);
void printArray(int* array, int size);
int solveSum(int*& array, int size);
int solveMulti(int*& array, int size);
void sortArray(int*& array, int size);

int main() 
{
    int size;
    std::cout << "Input array size:\t";
    std::cin >> size;
    int* array = initArray(size);
    printArray(array, size);
    std::cout << "\nSum: " << solveSum(array, size) << '\n';
    std::cout << "Multi: " << solveMulti(array, size) << '\n';
    std::cout << "After sort:\n";
    sortArray(array, size);
    printArray(array, size);
}

int* initArray(int size) 
{
    int* array = new int[size];
    for (int i = 0; i < size; i++) 
    {
        array[i] = rand() % 10 - 5;
    }
    return array;
}

void printArray(int* array, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << array[i] << ' ';
    }
}

int solveSum(int*& array, int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        if (array[i] < 0) 
        {
            sum += array[i];
        }
    }
    return sum;
}

int solveMulti(int*& array, int size) 
{
    int min = array[0], minIndex = 0, max = array[0], maxIndex = 0;
    for (int i = 0; i < size; i++) 
    {
        if (array[i] < min) 
        {
            min = array[i];
            minIndex = i;
        }
        if (array[i] > max) 
        {
            max = array[i];
            maxIndex = i;
        }
    }

    int multi = 1;
    if (minIndex > maxIndex) 
    {
        int temp = minIndex;
        minIndex = maxIndex;
        maxIndex = temp;
    }
    for (int i = minIndex + 1; i < maxIndex; i++) 
    {
        multi *= array[i];
    }
    return multi;
}

void sortArray(int*& array, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i; j < size; j++) 
        {
            if (array[i] > array[j]) 
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
