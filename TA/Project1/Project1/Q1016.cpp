// TEST 1
// 1 10
// max=10을 넘지 않는 제곱수는 4, 9가 있다.
// 구간 [1, 10]에서 존재하는 제곱수의 약수는 합쳐 4, 8, 9이므로
// 구간 내 제곱ㄴㄴ수 개수는 10-3=7이다.

// TEST 2
// 15 15
// max=15을 넘지 않는 제곱수는 4, 9가 있다.
// 구간 [15, 15]에서 존재하는 제곱수의 약수는 없으므로
// 구간 내 제곱ㄴㄴ수 개수는 1-0=1이다.

// TEST 3
// 1 1000
// max=1000을 넘지 않는 제곱수는 4, 9, 16, 25, 36, ... 31*31=961 가 있다.
// 구간 [1, 1000]에서 존재하는 제곱수의 약수는
//		4,  8, 12, [16] ... [992], 996, 1000,
//		9, 18, 27,		...				 999,
//	 [16], 32, 48,		... [992],
// 						...	 961 로 중복을 제외하고 총 392개이므로	
// 구간 내 제곱ㄴㄴ수 개수는 (1000-1+1)-392=608이다.

// 위에서 알 수 있듯이 소수 2의 배수인 4의 제곱수는 모두 2의 제곱수의 배수에 포함된다.
// 제곱ㄴㄴ수는 '소수'의 제곱의 약수가 아닌 수와 같다
// 왜냐하면 2^2=4의 배수는 4^2=16의 배수를 포함하고
// 일반화하여 n^2의 배수는 (n*k)^2의 배수를 포함하기 때문이다.

// 따라서 에라토스테네스의 체 개념을 도입,
// 구한 소수의 제곱이 max를 넘지 않는 범위 안에서 존재하는 모든 소수를 구하고,
// 구한 소수의 제곱의 배수를 주어진 구간 [min, max]에 한해 약수를 체에서 비활성화시킨다.
//
// 1 ≤ min ≤ 1,000,000,000,000 
// min ≤ max ≤ min + 1, 000, 000
// 
// 만약 시간이 초과된다면, 비활성화 과정 중 제곱ㄴㄴ수를 바로 세어 시간 단축이 가능하다. 

// 주어진 메모리 제한이 512MB = 1024 * 1024 * 512 * 1B 이므로
// 문제에 제시된 최대 길이 1,000,000 길이의 Char형 배열을 512개 사용 가능하다.
// 따라서, 메모리 이슈는 없다

// Q1016.cpp

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <vector>

typedef unsigned long long ull;

char* isPrime;
clock_t calcRunningTime(std::vector<ull> foo(ull, ull), const char* name, ull from, ull to);
std::vector<ull> getPrimeSquaresInRange(ull from, ull to);
int main() {

	ull min = 1, max = 1000;
	size_t len = sizeof(char) * (ull)sqrt((double)max) + 1;

	isPrime = (char*)malloc(len);
	if (isPrime != NULL) memset(isPrime, -1, len);

	{
		std::vector<ull>(*fptr)(ull, ull) = getPrimeSquaresInRange;
		char name[] = "getPrimeSquaresInRange";
		printf("\nrunTime: %dms\n", calcRunningTime(fptr, name, min, max));
	}

	free(isPrime);
	return 0;
}

// STEP 0
// 소요 시간 측정 함수
clock_t calcRunningTime(std::vector<ull> foo(ull, ull), const char* name, ull from, ull to)
{
	clock_t start = clock();
		printf("\n%s(%lld, %lld)\n", name, from, to);
		for (ull i : foo(from, to)) printf("%lld ", i);
	clock_t finished = clock();
	return (finished - start);
}


// STEP 1
// (from <= p) && (p*p <= to)를 만족하는 모든 소수 p를 배열에 저장한다. 
std::vector<ull> getPrimeSquaresInRange(ull from, ull to)
{
	std::vector<ull> res;
	if (2 * 2 <= to) res.push_back(2);
	for (ull p = 3; p * p <= to; p += 2) {
		if (isPrime[p] != 0) {
			if (from <= p) res.push_back(p);
			for (int i = 2; (p * i) * (p * i) <= to; i++) isPrime[p * i] = 0;
		}
	}
	return res;
}