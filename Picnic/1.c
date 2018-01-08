#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//STL, Vector
int caseNum, studentNum, friendNum;

int fr[10][10] = { 0, };
int picnic[10] = { 0, };
int ret = 0;

int findFriend() {
	
	int first = -1;
	int i;

	for (i = 0; i < 10; i++) {
		if (picnic[i] == 0) {
			first = i;
			break;
		}
	}
	if (first == -1)
		return 1;
	
	for (i = first + 1; i < 10; i++) {
		if (fr[first][i] == 1 && picnic[i] == 0) {

			picnic[i] = 1;
			picnic[first] = 1;
			ret += findFriend();
			picnic[i] = 0;
			picnic[first] = 0;
		}
	}
	printf("%d\n", ret);
	ret = 0;
	return 0;
}

int main() {

	int x, y;
	int i, j, k, l;
	scanf("%d", &caseNum);

	for (i = 0; i < caseNum; i++) {
		scanf("%d %d", &studentNum, &friendNum);
		for (j = 0; j < friendNum; j++) {
			scanf("%d %d", &x, &y);
			fr[x][y] = 1;
			fr[y][x] = 1;
		}
		findFriend();

		for (k = 0; k < 10; k++) {
			for (l = 0; l < 10; l++) {
				fr[k][l] = 0;
			}
		}
	}

	return 0;

}