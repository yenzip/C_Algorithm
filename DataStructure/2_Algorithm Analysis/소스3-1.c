/* [ 문제 3-1 ] 누적 평균 */
#include <stdio.h>

void prefixAverages1(int X[], int n) {	// O(n^2)
	int *A = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j <= i; j++)
			sum += X[j];
		A[i] = sum / (i + 1) + 0.5;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void prefixAverages2(int X[], int n) {	// O(n)
	int *A = (int *)malloc(sizeof(int) * n);
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += X[i];
		A[i] = sum / (i + 1) + 0.5;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main() {
	int N;
	int *X;

	scanf("%d", &N);
	X = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &X[i]);

	prefixAverages1(X, N);
	prefixAverages2(X, N);

	return 0;
}