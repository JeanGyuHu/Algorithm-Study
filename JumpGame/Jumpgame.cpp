#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int C;
int size;
int gameboard[100][100];
int cache[100][100];

int solution(int x, int y) {

	int ret=0;

	if (cache[x][y] != -1) {
		return cache[x][y];
	}

	if (x > size - 1 || y > size - 1)
		return 0;


	int num = gameboard[x][y];

	if (num == 0)
		return 1;

	if ((num + x) < size) {
		cache[x + num][y] = solution(x + num, y);
		ret += cache[x + num][y];
		//cache[x + num][y] = 0;
	}
	if ((num + y) < size) {
		cache[x][num + y] = solution(x, num + y);
		ret += cache[x][num + y];
		//cache[x][num + y] = 0;
	}
	return ret;
}

int main() {

	int i, j, k;

	scanf("%d", &C);

	while (C--) {
		scanf("%d", &size);
		memset(gameboard, 0, sizeof(gameboard));
		memset(cache, -1, sizeof(cache));
		for (j = 0; j < size; j++) {
			for (k = 0; k < size; k++) {
				scanf("%d", &gameboard[j][k]);
			}
		}

		if (solution(0, 0))
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}