#include <stdio.h>

int main() {

    double x, y;
    printf("x ��ǥ�� �Է��Ͻÿ�: "); scanf_s(" %lf", &x);
    printf("y ��ǥ�� �Է��Ͻÿ�: "); scanf_s(" %lf", &y);

    int result = 
    (x > 0)
        ? (y > 0 ? 1 : 4)
        : (y > 0 ? 2 : 3);

    printf("%d��и�", result);

    return 0;
}