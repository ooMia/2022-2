#include <stdio.h>
#include <Windows.h> //Sleep, Beep

int main()
{
	int time; scanf_s(" %d", &time);
	
	for (; time > 0; --time) {
		printf("%d ", time), Sleep(1000);
	}
	Beep(350, 500);

	return 0;
}