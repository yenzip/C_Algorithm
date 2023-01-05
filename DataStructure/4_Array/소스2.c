#include <stdio.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int n, m;
	int X[100] = { 0 }, I[100] = { 0 };	// X: 수열, I: 순서 바꿈 정보
	int tmp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %d", &X[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &I[i]);

	for (int i = 1; i < m - 1; i++)
		swap(X + I[0], X + I[i]);

	for (int i = 0; i < n; i++)
		printf(" %d", X[i]);
	printf("\n");

	return 0;
}