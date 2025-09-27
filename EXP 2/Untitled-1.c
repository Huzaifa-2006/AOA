#include <stdio.h>

// Global loop variables
int i, j, k;

// Function to merge two subarrays
void merge(int a[], int lb, int mid, int ub)
{
    // Calculate the sizes of two subarrays to be merged
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    // Create temporary arrays to hold the values
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[lb + i];

    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    // Merge the temp arrays back into a[lb..ub]
    i = 0;      // Initial index of first subarray (L)
    j = 0;      // Initial index of second subarray (R)
    k = lb;     // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
        a[k++] = L[i++];

    // Copy the remaining elements of R[], if any
    while (j < n2)
        a[k++] = R[j++];
}

// Recursive Merge Sort function
void mergeSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid;

        // Same as (lb + ub) / 2, but avoids overflow
        mid = lb + (ub - lb) / 2;

        // Sort first and second halves recursively
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);

        // Merge the sorted halves
        merge(a, lb, mid, ub);
    }
}

// Function to print the array
void printArray(int a[], int n)
{
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[100], n;

    // Input the number of elements
    printf("\nEnter n: ");
    scanf("%d", &n);

    // Input array elements
    printf("\nEnter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Print the original array
    printf("\nOriginal array:\n");
    printArray(a, n);

    // Call merge sort
    mergeSort(a, 0, n - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(a, n);

    return 0;
}

