/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int C, weight, height;
char board[20][20];
int ret = 0;

int boardCover() {

	int x = -1, y = -1;
	int i, j;

	for (i = 0; i < height; i++) {

		for (j = 0; j < weight; j++) {
			if (board[i][j] == '.') {
				x = i;
				y = j;
				break;
			}
		}
	}

	if (x == -1 && y == -1)
		return 1;

	if (board[x][y] == '.'&&board[x - 1][y] == '.'&&board[x][y - 1] == '.'&&x > 0 && x < height&&y>0 && y < weight) {
		board[x][y] = board[x - 1][y] = board[x][y - 1] = '#';
		ret += boardCover();
		board[x][y] = board[x - 1][y] = board[x][y - 1] = '.';
	}	// ┘ 모양

	if (board[x][y] == '.'&&board[x - 1][y] == '.'&&board[x][y + 1] == '.'&&x > 0 && x < height&&y>0 && y < weight) {
		board[x][y] = board[x - 1][y] = board[x][y + 1] = '#';
		ret += boardCover();
		board[x][y] = board[x - 1][y] = board[x][y + 1] = '.';
	}	// └ 모양

	if (board[x][y] == '.'&&board[x][y - 1] == '.'&&board[x + 1][y] == '.'&&x > 0 && x < height&&y>0 && y < weight) {
		board[x][y] = board[x][y - 1] = board[x + 1][y] = '#';
		ret += boardCover();
		board[x][y] = board[x][y - 1] = board[x + 1][y] = '.';
	}	// ┐모양

	if (board[x][y] == '.' &&board[x][y + 1] == '.' &&board[x + 1][y] == '.'&&x > 0 && x < height&&y>0 && y < weight) {
		board[x][y] = board[x][y + 1] = board[x + 1][y] = '#';
		ret += boardCover();
		board[x][y] = board[x][y + 1] = board[x + 1][y] = '.';
	}	// ┌모양

	return 0;
}

int main() {

	int i, j;

	scanf("%d", &C);

	for (i = 0; i < C; i++) {
		scanf("%d %d", &height, &weight);

		for (j = 0; j < height; j++) {
			scanf("%s", &board[j]);
		}
		boardCover();
		printf("%d\n", ret);
		ret = 0;
	}

	return 0;
}*/