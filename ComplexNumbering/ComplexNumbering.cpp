#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int N;
char **board;
int sortEx[625];
int check[2][4] = { {1,0,-1,0},{0,-1,0,1} };
int houseNum=0;

void solution(int x, int y) {

	int checkX, checkY;
	
	board[x][y] = '0';
	houseNum++;
	for (int i = 0; i < 4; i++) {
		checkX = x + check[0][i];
		checkY = y + check[1][i];

		if (checkX >= 0 && checkX < N&&checkY >= 0 && checkY < N&&board[checkX][checkY] == '1') {
			solution(checkX, checkY);
		}
	}

}

int main() {

	int count = 0;

	scanf("%d", &N);

	board = (char **)malloc(sizeof(char *)*N + 1);
	for (int i = 0; i < N; i++) {
		board[i] = (char *)malloc(sizeof(char)*N + 1);
		for (int j = 0; j < N; j++) {
			board[i][j] = '0';
		}
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", board[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '1') {
				solution(i, j);
				sortEx[count++] = houseNum;
				houseNum = 0;
			}
		}
	}

	std::sort(sortEx, sortEx + count);

	printf("%d\n",count);

	for (int i = 0; i < count; i++) {
		printf("%d\n", sortEx[i]);
	}

	free(board);

	return 0;
}