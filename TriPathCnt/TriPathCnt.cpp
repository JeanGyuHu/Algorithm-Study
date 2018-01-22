#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int C, num;
int numset[100][100];
int cache[100][100];
int countMax[100][100];

int solution(int x, int y) {

	if (cache[x][y] != -1)
		return cache[x][y];

	if (x == num - 1)
		return numset[x][y];

	if (cache[x][y] == -1) {
		int a = solution(x + 1, y);
		int b = solution(x + 1, y + 1);
		cache[x][y] = ((a + numset[x][y])>(b + numset[x][y])) ? (a + numset[x][y]) : (b + numset[x][y]);
	}

	return cache[x][y];
}

int count(int x, int y) {

	int cnt = 0;

	if (x == num - 1) return 1;

	if (countMax[x][y] != -1) return countMax[x][y];
	
	//solution(x + 1, y) >= solution(x + 1, y + 1) ? cnt += count(x + 1, y) : cnt += count(x + 1, y + 1);

	if (solution(x + 1, y) >= solution(x + 1, y + 1)) {
		cnt += count(x + 1, y);
	}
	if (solution(x + 1, y) <= solution(x + 1, y + 1)) {
		cnt += count(x + 1, y + 1);
	}
	countMax[x][y] = cnt;
	return cnt;
}
int main() {

	int j, k;

	scanf("%d", &C);

	while (C--) {
		scanf("%d", &num);
		memset(numset, 0, sizeof(numset));
		memset(cache, -1, sizeof(cache));
		memset(countMax, -1, sizeof(countMax));

		for (j = 0; j < num; j++) {
			for (k = 0; k < j + 1; k++) {
				scanf("%d", &numset[j][k]);
			}
		}
		printf("%d\n", count(0,0));
	}

	return 0;
}