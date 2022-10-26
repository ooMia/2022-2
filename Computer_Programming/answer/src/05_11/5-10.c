#include <stdio.h>

int main() {

    double x, y;
    printf("x 좌표를 입력하시오: "); scanf_s(" %lf", &x);
    printf("y 좌표를 입력하시오: "); scanf_s(" %lf", &y);

    int result = 
    (x > 0)
        ? (y > 0 ? 1 : 4)
        : (y > 0 ? 2 : 3);

    printf("%d사분면", result);

    return 0;
}