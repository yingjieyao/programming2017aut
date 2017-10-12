#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) {
        if (b > c) {
            printf("%d %d %d\n", a, b, c);
        } else if (c > a) {
            printf("%d %d %d\n", c, a, b);
        } else {
            printf("%d %d %d\n", a, c, b);
        }
    } else {
        if (a > c) {
            printf("%d %d %d\n", b, a, c);
        } else if (c > b) {
            printf("%d %d %d\n", c, b, a);
        } else{
            printf("%d %d %d\n", b, c, a);
        }
    }
    return 0;
}
