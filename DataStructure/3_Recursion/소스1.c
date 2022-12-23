#include <stdio.h>

int rSum(int n) {
	if (n == 1)
		return 1;
	return n + rSum(n - 1);
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d\n", rSum(N));

	return 0;
}