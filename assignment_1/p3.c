#include <stdio.h>

int main() {
    char buf[8192];
    printf("input: ");
    fgets(buf, sizeof(buf), stdin);
    printf("%s", buf);
}
