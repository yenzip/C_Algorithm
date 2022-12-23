#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int N;
	int a, b;

	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &A[i]);

	scanf("%d %d", &a, &b);

	swap(A + a, A + b);

	for (int i = 0; i < N; i++)
		printf(" %d", A[i]);
	printf("\n");

	return 0;
}