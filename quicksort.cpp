#include <stdio.h>

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = arr[first];
        int i = first + 1, j = last, temp;

        while (i <= j) {
            while (i <= last && arr[i] <= pivot) i++;
            while (arr[j] > pivot) j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        arr[first] = arr[j];
        arr[j] = pivot;

        quickSort(arr, first, j - 1);
        quickSort(arr, j + 1, last);
    }
}

int main() {
    int n, arr[25];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
