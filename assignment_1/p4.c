#include <stdlib.h>
#include <stdio.h>

#define ARRAY_LENGTH 100000

int* generate_array(int len);

int check_sorted(int *arr, int len);

int main() {
    int *arr = generate_array(ARRAY_LENGTH);
    sort_array(arr);
    printf("array is %ssorted", check_sorted(arr, ARRAY_LENGTH) ? "" : "not ");
}

int* generate_array(int len) {
    srand(time(NULL));
    // you can use the rand() function to generate a positive integer.
    return NULL;
}

void sort_array(int *arr, int len) {
}

// integers are truthy - nonzero values are evaluated as true, zero as false.
int check_sorted(int *arr, int len) {
    int i, previous = -1;
    for (i = 0; i < len; ++i) {
        if (previous < *(arr + i)) {
            
        }
    }
    return 1;
}
