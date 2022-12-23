#include <stdio.h>

typedef struct {
	int hour;
	int min;
	int sec;
} Time;

int main() {
	Time t1, t2, diff;

	scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
	scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

	if (t2.sec < t1.sec) {
		diff.sec = t2.sec - t1.sec + 60;
		t2.min -= 1;
	}
	else
		diff.sec = t2.sec - t1.sec;

	if (t2.min < t1.min) {
		diff.min = t2.min - t1.min + 60;
		t2.hour -= 1;
	}
	else
		diff.min = t2.min - t1.min;

	diff.hour = t2.hour - t1.hour;

	printf("%d %d %d\n", diff.hour, diff.min, diff.sec);
		
	return 0;
}