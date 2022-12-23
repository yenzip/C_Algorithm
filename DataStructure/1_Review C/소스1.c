#include <stdio.h>

int sum(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result;
}

int main() {
	int X;
	int result = 0;

	scanf("%d", &X);

	for (int i = 1; i <= X; i++) {
		result += sum(i);
	}

	printf("%d\n", result);

	return 0;
}