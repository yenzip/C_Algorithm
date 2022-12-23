#include <stdio.h>

#define SWAP(x, y, tmp) ((tmp = x), (x = y), (y = tmp))

void ABC(int A[], int k) {
	int tmp, max = k;
	for (int i = k+1; i < 10; i++) {
		if (A[max] < A[i])
			max = i;
	}
	SWAP(A[k], A[max], tmp);
}

int main() {
	int A[10] = { 0 };

	for (int i = 0; i < 10; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < 9; i++)
		ABC(A, i);

	for (int i = 0; i < 10; i++)
		printf(" %d", A[i]);
	printf("\n");

	return 0;
}