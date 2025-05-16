#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_LENGTH 100000

int *generate_array(int len);

void sort_array(int *arr, int len);

int check_sorted(int *arr, int len);

int main() {
    int *arr = generate_array(ARRAY_LENGTH);
    sort_array(arr, ARRAY_LENGTH);
    printf("array is %ssorted\n", check_sorted(arr, ARRAY_LENGTH) ? "" : "not ");
}

int *generate_array(int len) {
    srand(time(NULL));
    // you can use the rand() function to generate a positive integer.
    return NULL;
}

void heapify(int *arr, int len) {
}

void sift_down(int *arr, int len) {
}

void sort_array(int *arr, int len) {
}

// integers are truthy - nonzero values are evaluated as true, zero as false.
int check_sorted(int *arr, int len) {
    int i, last_checked = -1;
    int tmp;
    for (i = 0; i < len; ++i) {
        tmp = *(arr + i);
        if (last_checked > tmp) {
            return 0;
        }
        last_checked = tmp;
    }
    return 1;
}


