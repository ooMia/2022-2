#include <stdio.h>

int main()
{
	int time, age, charge;
	printf("현재 시간과 나이를 입력하시오(시간, 나이):"); scanf_s(" %d %d", &time, &age);

	if (17 <= time) { charge = 10000; }
	else if ((3 <= age && age <= 12) || 65 <= age) charge = 25000;
	else charge = 34000;

	printf("요금은 %d입니다.", charge);

	return 0;
}