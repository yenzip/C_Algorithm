#include <stdio.h>

int main() {
	int n, m;
	int A[100][100] = { 0 };
	int i = 0, num = 1;

	scanf("%d %d", &n, &m);

	while (1) {
		if (num > n*m)
			break;

		for (int r = 0; r < n; r++) {	// 대각선 채우기
			int c = i - r;
			if (c >= 0 && c < m)
				A[r][c] = num++;
		}

		i++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf(" %d", A[i][j]);
		printf("\n");
	}

	return 0;
}