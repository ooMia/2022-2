#include <stdio.h>
int main()
{
       double x, y, result;
 
       printf("두개의 실수를 입력하시오: ");
       scanf_s("%lf %lf", &x, &y);

       result = x + y;		// 덧셈 연산을 하여서 결과를 result에 대입
       printf("%f / %f = %f\n", x, y, result);
       result = x - y;		
       printf("%f - %f = %f\n", x, y, result);
       result = x * y;		
       printf("%f * %f = %f\n", x, y, result);
       result = x / y;		
       printf("%f / %f = %f\n", x, y, result);
 
       return 0;
}