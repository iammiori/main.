#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int matrix[50][50];
int jirung[50];
void dps(int i, int j, int row, int col) {
	if (matrix[i][j] != 1) return;
	matrix[i][j] = -1;
	if (i != 0 && matrix[i - 1][j]) {
		dps(i - 1, j, row, col);
	}
	if (j != col - 1 && matrix[i][j + 1]) {
		dps(i, j + 1, row, col);
	}
	if (i != row - 1 && matrix[i + 1][j]) {
		dps(i + 1, j, row, col);
	}
	if (j != 0 && matrix[i][j - 1]) {
		dps(i, j - 1, row, col);
	}
}

void many(int row, int col, int*jirung) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 1) {
				dps(i, j, row, col);
				(*jirung)++;
			}
		}
	}
}

void init(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			matrix[i][j] = 0;
	}
}

int main(void) {
	int test, row, col, cabage, i, j, row_cab, col_cab;
	scanf("%d", &test);
	for (i = 0; i < test; i++) {
		int count = 0;
		scanf("%d %d %d", &row, &col, &cabage);
		for (j = 0; j < cabage; j++) {
			scanf("%d %d", &row_cab, &col_cab);
			matrix[row_cab][col_cab] = 1;
		}
		many(row, col, &count);
		jirung[i] = count;
		init(row, col);
	}
	for (i = 0; i < test; i++) {
		printf("%d\n", jirung[i]);
	}
}