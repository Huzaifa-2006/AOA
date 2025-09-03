#include <stdio.h>

int a[100], n, i, j, item, shift = 0;
float pshift;
int t;

int main() {
    printf("Enter how many elements in the array?\n");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Elements Entered are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    // Insertion Sort with Shift Count
    for(j = 1; j < n; j++) {
        item = a[j];
        i = j - 1;

        while(i >= 0 && item < a[i]) {
            a[i + 1] = a[i];
            i = i - 1;
            shift++;
        }
        a[i + 1] = item;
    }

    // Calculate theoretical maximum shifts for insertion sort
    t = (n * (n - 1)) / 2;
    pshift = ((float)shift * 100) / t;

    printf("\nSorted array elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nNumber of Shifts: %d", shift);
    printf("\nPercentage of Shifts: %.2f%%", pshift);

    if(pshift < 33.3) {
        printf("\nBest Case Scenario");
    } else if(pshift < 66.6) {
        printf("\nAverage Case Scenario");
    } else {
        printf("\nWorst Case Scenario");
    }

    return 0;
}

