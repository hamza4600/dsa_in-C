/// Different serach i have tried
#include <stdio.h>
#include <stdlib.h>

// main types of search
// linear search
// binary search
// hash table search

// linear search
void linearSearch(int *array, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            printf("Found %d at index %d using linear search\n", value, i);
            return;
        }
    }
    printf("Could not find %d using linear search\n", value);
}

// binary search
void binarySearch(int *array, int size, int value)
{
    int start = 0;
    int end = size - 1;
    int middle = (start + end) / 2;
    while (start <= end)
    {
        if (array[middle] == value)
        {
            printf("Found %d at index %d using binary search\n", value, middle);
            return;
        }
        else if (array[middle] < value)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
        middle = (start + end) / 2;
    }
    printf("Could not find %d using binary search\n", value);
}

// hash table search
void hashTableSearch(int *array, int size, int value)
{
    int hashTable[100] = {0};
    for (int i = 0; i < size; i++)
    {
        hashTable[array[i]]++;
    }
    if (hashTable[value] > 0)
    {
        printf("Found %d using hash table search\n", value);
    }
    else
    {
        printf("Could not find %d using hash table search\n", value);
    }
}

void searching()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int value = 5;
    linearSearch(array, size, value);
    binarySearch(array, size, value);
    hashTableSearch(array, size, value);
}

// Sortings i have tried
// bubble sort
// selection sort
// insertion sort
// merge sort
// quick sort
// heap sort

// bubble sort
void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// selection sort
void selectionSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

// insertion sort
void insertionSort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}

// merge sort (recursive)
void merge(int *array, int start, int middle, int end)
{
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    int left[leftSize];
    int right[rightSize];
    for (int i = 0; i < leftSize; i++)
    {
        left[i] = array[start + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        right[i] = array[middle + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

// quick sort (recursive)
int partition(int *array, int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;
    return i + 1;
}

void quickSort(int *array, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

// heap sort
void heapify(int *array, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

void heapSort(int *array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}

// print array
void printArray(int *array, int size, char by[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n Array is sorted by %s algorithm \n", by);
}

void sortingAll()
{
    int array[] = {1000, 20, 3, 400, 5000, 60, 7, 8000, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);

    // bubbleSort(array, size);
    // printArray(array, size, "bubble");
    // selectionSort(array, size);
    // printArray(array, size, "selection");
    // insertionSort(array, size);
    // mergeSort(array, 0, size - 1);
    // quickSort(array, 0, size - 1);
    // heapSort(array, size);
}

int main()
{
    // searching();
    sortingAll();
    return 0;
}

// Problum
// condier the following code
// if(c1) {
//     if(c2) {
//         if(c3) {
//             if(c4) {
//                 if(c5) {
//                     if(c6) {
//                         if(c7) {
// in which arrangement it wirk more effeciently
// we can use the following code
// if(c1 && c2 && c3 && c4 && c5 && c6 && c7) {
//     // do something
// }