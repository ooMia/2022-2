#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h>	// time

int main() {

	// INITIALIZE
	srand((unsigned)time(NULL));
	int user, computer = rand() % 3 + 1;
	char type[][5] = { "","가위","바위","보" };

	// INPUT
	do {
		printf("선택하시오(1:가위, 2:바위, 3:보) "); scanf_s(" %d", &user);
		if (user > 3 || user <= 0) system("cls");
	} while (user > 3 || user <= 0);

	// OUTPUT
	printf("사용자: %s, 컴퓨터: %s\n", type[user], type[computer]);

	if (user == computer) printf("비겼음");
	else if ((user == 1 && computer == 3) || (user > computer)) printf("사용자가 이겼음");
	else printf("사용자가 졌음");

	return 0;
}