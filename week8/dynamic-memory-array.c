#include <stdio.h>
#include <stdlib.h>

// KODE A: Static Memory Allocation
void staticMemoryAllocation() {
    int SIZE = 9;
    int data[SIZE];

    // Entry Data
    for (int i = 0; i < SIZE; i++) {
        data[i] = i * 2;
    }

    // Search Data
    int target = 6;
    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (data[i] == target) {
            printf("Data %d found at index %d (KODE A)\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Data %d not found (KODE A)\n", target);
    }

    // Print All
    printf("Data in KODE A: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// KODE B: Dynamic Memory Allocation
void dynamicMemoryAllocation() {
    int SIZE = 9;
    int *dataptr = (int *)malloc(SIZE * sizeof(int));

    if (dataptr == NULL) {
        printf("Failed to allocate memory (KODE B)\n");
        return;
    }

    // Entry Data
    for (int i = 0; i < SIZE; i++) {
        dataptr[i] = i * 2;
    }

    // Search Data
    int target = 6;
    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (dataptr[i] == target) {
            printf("Data %d found at index %d (KODE B)\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Data %d not found (KODE B)\n", target);
    }

    // Print All
    printf("Data in KODE B: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", dataptr[i]);
    }
    printf("\n");

    free(dataptr); // Release the dynamically allocated memory
}

int main() {
    printf("Static Memory Allocation (KODE A):\n");
    staticMemoryAllocation();

    printf("\nDynamic Memory Allocation (KODE B):\n");
    dynamicMemoryAllocation();

    return 0;
}
