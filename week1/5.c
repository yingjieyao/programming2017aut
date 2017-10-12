#include <stdio.h>

int main() {
    int bot, top, h;
    scanf("%d %d %d", &bot, &top, &h);
    printf("%lf\n", (bot + top) * h / 2.0);
    return 0;
}
