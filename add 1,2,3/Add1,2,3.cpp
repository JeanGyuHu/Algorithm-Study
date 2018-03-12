#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int T;
int n;


int solution(int x) {

	int rtn=0;

	if (x == n)
		return 1;
	if (x > n)
		return 0;

	if (x + 1 <= n)
		rtn += solution(x + 1);
	if (x + 2 <= n)
		rtn += solution(x + 2);
	if (x + 3 <= n)
		rtn += solution(x + 3);

	return rtn;
}
int main() {

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);

		printf("%d\n", solution(0));
	}

	return 0;
}