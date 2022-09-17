#include <stdio.h>
#include <Windows.h>

int partialSum(int from, int to) {
	// sigma[k=1..to](k) - sigma[k=1..from](k-1)
	return (to + from) * (to - from + 1) / 2;
}

int main()
{
	int limit = 10000, sum, i, from, to;

	// 1: O(n) - brute force
	sum = i = 0;

	while (1) {
		if (sum > limit) break;
		else {
			i += 1;
			sum += i;
		}
	} sum -= i; i -= 1;

	printf("1부터 %d까지의 합이 %d입니다.\n", i, sum);

	// 2: O(n) - brute force, shorten
	sum = from = to = 1;
	while (sum <= limit) { sum += ++to; } sum -= to--;
	printf("%d부터 %d까지의 합이 %d입니다.\n", from, to, sum);

	// 3: O(log log n) - local optimization
	from = i = to = 1;

	// Macro Callibration
	while (partialSum(1, i) < limit) {
		to = (i *= 2);
		from = to / 2;
	}
	// Micro Callibration
	while (from != to - 1) {
		i = from + (to - from) / 2;
		if (partialSum(1, i) > limit) to = i; // [from, i]
		else from = i; // [i, to]
	}

	printf("1부터 %d까지의 합이 %d입니다.\n", from, partialSum(0, from));

	return 0;
}