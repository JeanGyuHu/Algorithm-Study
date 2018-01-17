#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int C,N;
int cache[100];

int solution(int x) {

	int result=0;
	
	if (cache[x] != -1)
		return cache[x];
	if (x > N)	return 0;
	if (x == N)	return 1;

	cache[x] = (solution(x + 1) + solution(x + 2)) % 1000000007;

	return cache[x];
}
int main() {

	scanf("%d", &C);

	while (C--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);

		solution(0);

		printf("%d\n", cache[0]);
	}

	return 0;
}