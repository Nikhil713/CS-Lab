#include <stdio.h>

void printArray(int[], int);
void heapify(int[], int, int);
void heapSort(int[], int);
void swap(int *, int *);

int main(void)
{
    int i, n = 5, a[] = {34, 54, 66, 12, 9};

    // Print Unsorted array
    printArray(a, n);

    // Sort array using Heap Sort
    heapSort(a, n);

    // Print Sorted array
    printf("\n");
    printArray(a, n);
    printf("\n");
    return 0;
}

void heapSort(int a[], int n)
{
    int i;

    // Build Heap from unsorted array
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Heapify
    for (i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        // Print Each Pass
        printArray(a, n);
        heapify(a, i, 0);
    }
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(&a[largest], &a[i]);
        heapify(a, n, largest);
    }
}

void printArray(int a[], int n)
{
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}