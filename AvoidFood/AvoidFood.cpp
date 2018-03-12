#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int N, M, K;
int board[100][100];
int a, b;
int size, max;
int check[2][4] = { { 0,1,0,-1 },{ 1,0,-1,0 } };

void solution(int x, int y) {

	int checkX, checkY;

	board[x][y] = 0;
	size++;

	for (int i = 0; i < 4; i++) {
		checkX = x + check[0][i];
		checkY = y + check[1][i];

		if (checkX >= 0 && checkX < N && checkY >= 0 && checkY < M && board[checkX][checkY]) {
			solution(checkX, checkY);
		}
	}
}

int main() {

	scanf("%d%d%d", &N, &M, &K);
	memset(board, 0, sizeof(board));
	
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &a, &b);
		board[a-1][b-1] = 1;
	}
	size = 0;
	max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) {
				solution(i, j);
				
				if (size > max) {
					max = size;
					size = 0;
				}
				else
					size = 0;
			}
		}
	}

	printf("%d\n", max);

	return 0;
}