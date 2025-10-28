#include <stdio.h>

struct Pair {
    int max;
    int min;
};

struct Pair maxMinDivideConquer(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    left = maxMinDivideConquer(arr, low, mid);
    right = maxMinDivideConquer(arr, mid + 1, high);

    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair result = maxMinDivideConquer(arr, 0, n - 1);
    printf("Maximum element is: %d\n", result.max);
    printf("Minimum element is: %d\n", result.min);

    return 0;
}

