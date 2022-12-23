/* [ 문제 3-2 ] 누적 평균 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void prefixAverages1(int X[], int n) {	// O(n^2)
	int *A = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j <= i; j++)
			sum += X[j];
		A[i] = sum / (i + 1) + 0.5;
	}
}

void prefixAverages2(int X[], int n) {	// O(n)
	int *A = (int *)malloc(sizeof(int) * n);
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += X[i];
		A[i] = sum / (i + 1) + 0.5;
	}
}

int main() {
	int N;
	int *X;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	srand(time(NULL));

	scanf("%d", &N);
	X = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		X[i] = rand() % 10000 + 1;

	// prefixAverages1 cpu 시간 측정
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	prefixAverages1(X, N);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	// prefixAverages2 cpu 시간 측정
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	prefixAverages2(X, N);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	return 0;
}