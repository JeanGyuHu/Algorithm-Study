#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int N, M;
int board[102][102];
int check[4][2] = { { 1,0 },{ 0,-1 },{0,1},{-1,0} };

int solution(int y, int x) {

	int nowX, nowY;
	int checkX, checkY;

	queue<pair<int, int>> Queue;

	Queue.push(make_pair(y, x));


	while (!Queue.empty()) {

		nowX = Queue.front().second;
		nowY = Queue.front().first;

		Queue.pop();

		if (nowX == M - 1 && nowY == N - 1)
			break;

		for (int i = 0; i < 4; i++) {
			checkX = nowX + check[i][1];
			checkY = nowY + check[i][0];

			if ((checkX >= 0) && (checkX < M) && (checkY >= 0) && (checkY < N) && (board[checkY][checkX]==1)) {
				Queue.push(make_pair(checkY, checkX));
				board[checkY][checkX] += board[nowY][nowX];
			}
		}
		board[nowY][nowX] = 0;
	}

	return board[N-1][M-1];
}

int main() {

	scanf("%d%d", &N, &M);
	
	memset(board, -1, sizeof(board));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%1d", &board[i][j]);
	}

	printf("%d\n", solution(0,0));

	return 0;
}