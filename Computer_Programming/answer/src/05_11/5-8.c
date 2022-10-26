#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define PI (M_PI)

int main()
{
	double r;
	printf("구의 반지름을 입력하시오:"); scanf_s(" %lf", &r);
	printf("표면적은 %f입니다.\n", 4. * PI * pow(r, 2.));
	printf("체적은 %f입니다.\n", 4. / 3. * PI * pow(r, 3.));
	
	return 0;
}