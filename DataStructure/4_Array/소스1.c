#include <stdio.h>

void reverse(int *X, int a, int b) {
	int A[100] = { 0 };

	for (int i = a; i <= b; i++)
		A[i] = X[b - i + a];

	for (int i = a; i <= b; i++)
		X[i] = A[i];
}

int main() {
	int n, m;
	int X[100] = { 0 };
	int a, b;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &X[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		reverse(X, a, b);
	}

	for (int i = 0; i < n; i++)
		printf(" %d", X[i]);
	printf("\n");

	return 0;
}