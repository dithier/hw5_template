#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef EXPERIMENT
#define EXPERIMENT 0
#endif

void merge(int arr[], int left, int mid, int right) {}

void mergeSort(int arr[], int left, int right) {}

void print_array(int arr[], int size) {}

void sortIntegers(int arr[], int size) { mergeSort(arr, 0, size - 1); }

int main(int argc, char* argv[]) {
#if EXPERIMENT == 0
    // test data sets.of all same size
    int dataset1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dataset2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int dataset3[] = {0, 3, 2, 1, 4, 7, 6, 5, 8, 9, 10};
    int dataset4[] = {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int dataset5[] = {100, 201, 52, 3223, 24, 55, 623, 75, 8523, -9, 150};
    int dataset6[] = {-1, 1, 2, -3, 4, 5, -6, 7, 8, -9, 10};

    int size = sizeof(dataset1) / sizeof(dataset1[0]);

    sortIntegers(dataset1, size);
    sortIntegers(dataset2, size);
    sortIntegers(dataset3, size);
    sortIntegers(dataset4, size);
    sortIntegers(dataset5, size);
    sortIntegers(dataset6, size);

    print_array(dataset1, size);
    print_array(dataset2, size);
    print_array(dataset3, size);
    print_array(dataset4, size);
    print_array(dataset5, size);
    print_array(dataset6, size);
#else

    if (argc != 2) {
        printf("One argument expected: ./mergesort 1000\n");
        return 1;
    }

    // Convert the argument of the program into an integer
    const int size = atoi(argv[1]);
    // Generate a random seed
    time_t t;
    srand((unsigned)time(&t));
    // Allocate memory
    int* random = (int*)malloc(sizeof(int) * size);

    // Populate our test data set
    for (int i = 0; i < size; i++) {
        // Generate random values from 0 to 99
        random[i] = rand() % size;
    }

    // You can uncomment if you'd like to see the size sorted
    // printf("Before the sort: ");
    // printIntArray(random, size);

    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
    // Perform the sort
    sortIntegers(random, size);
    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
                        (end.tv_sec - begin.tv_sec);
    printf("Total time = %f seconds\n", time_taken);

    // Confirm the sort worked
    // printf("After the sort: ");
    // printIntArray(random, size);

    // Free our random array
    free(random);
#endif

    return 0;
}
