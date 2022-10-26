#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define PI (3.14) // M_PI

int main()
{
	double distance, degree;
	printf("거리를 입력하시오:"); scanf_s(" %lf", &distance);
	printf("각도를 입력하시오:"); scanf_s(" %lf", &degree);
	printf("지구의 반지름은 %f\n", (360. / degree) * distance / (2. * PI));

	return 0;
}