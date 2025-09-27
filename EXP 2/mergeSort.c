#include <stdio.h>
#include <stdlib.h>

/*
Merge Sort Time Complexity:

Best Case:    O(n log n)  -> Already sorted input, still divides & merges.
Average Case: O(n log n)  -> Random order input.
Worst Case:   O(n log n)  -> Reverse sorted input, still consistent due to divide-merge.
Space:        O(n)        -> Temporary arrays used during merge.

Merge Sort is a stable, divide-and-conquer algorithm.
*/

// Merges two subarrays of arr[].
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge temp arrays back into arr[l..r]
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Divide
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Conquer (merge)
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[100];
    int n, i;

    printf("\nEnter the size of the array (even number, max 100): ");
    scanf("%d", &n);

    if (n > 100 || n <= 0 || n % 2 != 0) {
        printf("Invalid input. Please enter a positive even number <= 100.\n");
        return 1;
    }

    printf("Enter %d array elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

