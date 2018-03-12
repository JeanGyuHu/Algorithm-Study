#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int M, N, K;
int T;
int count;
int board[51][51];
int check[2][4] = { {0,1,0,-1},{1,0,-1,0 } };

void solution(int x, int y) {

	int checkX, checkY;
	board[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		checkX = x + check[0][i];
		checkY = y + check[1][i];

		if (checkX >= 0 && checkX < M &&checkY >= 0 && checkY < N&&board[checkX][checkY]) {
			solution(checkX, checkY);
		}
	}
}

int main() {

	int x, y;

	scanf("%d", &T);

	while (T--) {

		scanf("%d%d%d", &M, &N, &K);
		memset(board, 0, sizeof(board));

		for (int i = 0; i < K; i++) {
			scanf("%d%d", &x, &y);
			board[x][y] = 1;
		}

		count = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j]) {
					solution(i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}