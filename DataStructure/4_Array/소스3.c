#include <stdio.h>

int main() {
	int n;
	int A[100][100] = { 0 };

	scanf("%d", &n);

	for (int i = 0, num = 1; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++)
				A[i][j] = num++;
		}
		else {
			for (int j = n - 1; j >= 0; j--)
				A[i][j] = num++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf(" %d", A[i][j]);
		printf("\n");
	}
	
	return 0;
}