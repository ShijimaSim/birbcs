#include <stdio.h>

int main() {
    char buf[1024];
    int count = 0;
    FILE *in = fopen("README.md", "r");
    FILE *out = fopen("out.md", "w");
    while (fgets(buf, sizeof(buf), in)) {
        ++count;
        for (int i = 0; buf[i] != '\0'; ++i) {
            fprintf(out, "%d ", buf[i]);
        }
    }
    printf("line count: %d\n", count);
    fclose(in);
    fclose(out);
}
