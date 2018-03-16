//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int N, M;
//char **board;
//int cache[100][100];
//
//int solution(int x, int y) {
//
//	if (x == N - 1 && y == M - 1) {
//		
//		return 1;
//	}
//	if (cache[x][y] != -1) {
//		return cache[x][y];
//	}
//
//	board[x][y] = '0';
//	cache[x][y] = 9999999999;
//
//	//아래
//	if (x + 1 < N && board[x + 1][y] == '1') {
//
//		cache[x][y] = (cache[x][y] <=solution(x + 1, y))? cache[x][y] :solution(x+1,y);
//	}
//
//	//위
//	if (x - 1 >= 0 && board[x - 1][y] == '1') {
//
//		cache[x][y] = (cache[x][y] <= solution(x - 1, y)) ? cache[x][y] : solution(x - 1, y);
//	}
//
//	//오른쪽
//	if (y + 1 < M && board[x][y + 1] == '1') {
//		
//		cache[x][y] = (cache[x][y] <= solution(x, y+1)) ? cache[x][y] : solution(x, y+1);
//	}
//
//	//왼쪽
//	if (y - 1 >= 0 && board[x][y - 1] == '1') {
//
//		cache[x][y] = (cache[x][y] <= solution(x, y - 1)) ? cache[x][y] : solution(x, y - 1);
//	}
//
//	cache[x][y]++;
//	board[x][y] = '1';
//
//	return cache[x][y];
//}
//
//int main() {
//
//	scanf("%d%d", &N, &M);
//
//	board = (char **)malloc(sizeof(char *)*(N + 3));
//	for (int i = 0; i < N; i++) {
//		board[i] = (char *)malloc(sizeof(char)*(M + 3));
//	}
//
//	memset(cache, -1, sizeof(cache));
//	for (int i = 0; i < N; i++) {
//		scanf("%s", board[i]);
//	}
//
//	printf("%d\n", solution(0, 0));
//
//	free(board);
//	return 0;
//
//}