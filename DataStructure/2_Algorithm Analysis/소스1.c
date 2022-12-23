/* [ 문제 1 ] 나머지 연산 */
#include <stdio.h>

int modulo(int a, int b) {
	while (a >= b) {
		a -= b;
	}
	return a;
}

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", modulo(a, b));

	return 0;
}