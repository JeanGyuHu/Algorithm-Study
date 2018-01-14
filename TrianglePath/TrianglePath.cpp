#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int C,num;
int numset[100][100];
int cache[100][100];
int ret=0;

int solution(int x,int y) {

	if (cache[x][y] != -1)
		return cache[x][y];

	if (x == num-1)
		return numset[x][y];

	if (cache[x][y] == -1) {
		cache[x][y] = ((solution(x+1, y) + numset[x][y])>(solution(x + 1, y + 1) + numset[x][y]))? (solution(x + 1, y) + numset[x][y]): (solution(x + 1, y + 1) + numset[x][y]);
	}

	return cache[x][y];
}

int main() {

	int i, j, k;

	scanf("%d", &C);

	while(C--) {
		scanf("%d", &num);
		memset(numset, 0, sizeof(numset));
		memset(cache, -1, sizeof(cache));

		for (j = 0; j < num; j++) {
			for (k = 0; k < j+1; k++) {
				scanf("%d", &numset[j][k]);
			}
		}
		printf("%d\n", solution(0, 0));
	}

	return 0;
}