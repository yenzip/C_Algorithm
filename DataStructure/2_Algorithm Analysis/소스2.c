/* [ 문제 2 ] 비트행렬에서 최대 1행 찾기 */
#include <stdio.h>

int mostOnes(int **A, int n) {
	int i = 0, j = 0, maxRow = 0;
	while (i < n && j < n) {
		if (A[i][j] == 1) {
			j++;
			maxRow = i;
		}
		else
			i++;
	}
	return maxRow;
}

int main() {
	int N;
	int **A;

	scanf("%d", &N);
	A = (int **)malloc(sizeof(int *) * N);
	for (int i = 0; i < N; i++) 
		A[i] = (int *)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	}

	printf("%d\n", mostOnes(A, N));

	return 0;
}