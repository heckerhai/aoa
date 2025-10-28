#include <stdio.h>

int main() {
    int arr[5] = {29, 10, 14, 37, 13};
    int i, j, min, temp;

    // Selection sort
    for (i = 0; i < 4; i++) {
        min = i;
        for (j = i + 1; j < 5; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap elements
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
