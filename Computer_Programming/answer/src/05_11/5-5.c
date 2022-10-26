#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    
    do {
        printf("100보다 작은 자연수를 입력하시오:"); scanf_s(" %d", &x);
        if (x >= 100 || x < 0) system("cls");
    } while (x >= 100 || x < 0);
    printf("십의 자리:%d\n일의 자리:%d", x / 10, x % 10);

    return 0;
}