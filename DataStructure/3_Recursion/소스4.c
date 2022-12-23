#include <stdio.h>

int arrayMax(int *A, int n, int max) {
	if (n < 0)
		return max;

	if (max < A[n])
		max = A[n];
	return arrayMax(A, n - 1, max);
}

int main() {
	int N;
	int *A;

	scanf("%d", &N);
	A = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	printf("%d\n", arrayMax(A, N - 1, 0));

	return 0;
}