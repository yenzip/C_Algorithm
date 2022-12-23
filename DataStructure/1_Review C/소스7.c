#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;

	scanf("%d", &N);

	int *A = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int *B = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	int *res = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		res[i] = A[i] + B[N - i - 1];
		printf(" %d", res[i]);
	}
	printf("\n");

	return 0;
}