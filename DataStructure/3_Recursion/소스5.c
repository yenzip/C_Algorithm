#include <stdio.h>

void rHanoi(int n, char from, char aux, char to) {
	if (n == 1) {
		printf("%c %c\n", from, to);
		return;
	}

	rHanoi(n - 1, from, to, aux);
	printf("%c %c\n", from, to);
	rHanoi(n - 1, aux, from, to);
}


int main() {
	int N;

	scanf("%d", &N);

	rHanoi(N, 'A', 'B', 'C');

	return 0;
}