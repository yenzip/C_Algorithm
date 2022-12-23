#include <stdio.h>

void rPrintDigits(int n) {
	if (n == 0)
		return;
	rPrintDigits(n / 10);
	printf("%d\n", n % 10);
}

int main() {
	int N;

	scanf("%d", &N);

	rPrintDigits(N);

	return 0;
}