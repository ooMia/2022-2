#include <stdio.h>
int main()
{
    int x, y, z;
    printf("3개의 정수를 입력하시오:"); scanf_s("%d %d %d", &x, &y, &z);
    printf("최대값:%d", x > y ? (x > z ? x : z) : (y > z ? y : z));

    return 0;
}