#include <stdio.h>

int rPrintDigits(int n) {
	if (n == 0)
		return;
	printf("%d\n", n % 10);
	rPrintDigits(n / 10);
}

int main() {
	int N;

	scanf("%d", &N);

	rPrintDigits(N);

	return 0;
}