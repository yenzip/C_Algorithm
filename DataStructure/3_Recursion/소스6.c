#include <stdio.h>

int rGcd(int a, int b) {
	if (b == 0)
		return a;
	return rGcd(b, a%b);
}

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", rGcd(a, b));

	return 0;
}