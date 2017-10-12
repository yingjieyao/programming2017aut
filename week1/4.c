#include <stdio.h>

int main() {
    double r, pi = 3.141592653;
    scanf("%lf", &r);
    printf("area = %lf\n", pi * r * r);
    printf("circumference = %lf\n", 2 * pi * r);
    return 0;
}
