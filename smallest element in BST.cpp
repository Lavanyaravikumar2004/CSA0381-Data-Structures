#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    // Prompt the user to enter the size of the array
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Check if size is non-positive
    if (size <= 0) {
        printf("Invalid size entered. Size must be positive.\n");
        return 1;  // Exit the program with an error status
    }

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;  // Exit the program with an error status
    }

    // Input the elements of the array from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the elements of the array as confirmation
    printf("Entered elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;  // Exit the program successfully
}

