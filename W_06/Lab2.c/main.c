#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;}

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);}

    int max = arr[0], min = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];}
        if (arr[i] < min) {
            min = arr[i];}
    }

    printf("\nMaximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    free(arr); //never forget to freeeeeee.
    return 0;
}
