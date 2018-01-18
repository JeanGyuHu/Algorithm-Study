#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int C, N;
int cache[101];

int solution(int x) {


	if (x <= 100 && cache[x] != -1)
		return cache[x];

	if (x == N)	return 1;
	else if (x > N)	return 0;

	return cache[x] = (solution(x + 1) + solution(x + 2)) % 1000000007;
}
int main() {

	scanf("%d", &C);

	while (C--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		printf("%d\n", solution(0));
	}

	return 0;
}