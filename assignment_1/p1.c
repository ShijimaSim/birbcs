#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    for(int i = 0; i < 100; ++i) {
        printf("%d ", i);
        if (i % 3 == 0) {
            printf("fizz");
        }
        if (i % 5 == 0) {
            printf("buzz");
        }
        printf("\n");
    }
}
