#include <stdio.h>

int main() {
	int n, m;
	int A[100][100] = { 0 };
	int i = 0, j = 0, num = 1;

	scanf("%d %d", &n, &m);

	while (num <= n * m) {
		while (j < m && A[i][j] == 0) 
			A[i][j++] = num++;
		i++;	 j--;

		while (i < n && A[i][j] == 0) 
			A[i++][j] = num++;
		i--;	 j--;

		while (j >= 0 && A[i][j] == 0) 
			A[i][j--] = num++;
		i--;	j++;

		while (i >= 0 && A[i][j] == 0) 
			A[i--][j] = num++;
		i++;	j++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf(" %d", A[i][j]);
		printf("\n");
	}
	return 0;
}