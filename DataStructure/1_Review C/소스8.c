#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[8];
	int kor, eng, math;
	double avg;
} Student;

int main() {
	Student *S;
	int N;

	scanf("%d", &N);

	S = (Student *)malloc(sizeof(Student) * N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", S[i].name, &S[i].kor, &S[i].eng, &S[i].math);
		S[i].avg = (S[i].kor + S[i].eng + S[i].math) / 3.0;

		printf("%s %.1f", S[i].name, S[i].avg);
		if (S[i].kor >= 90 || S[i].eng >= 90 || S[i].math >= 90)
			printf(" GREAT");
		if (S[i].kor < 70 || S[i].eng < 70 || S[i].math < 70)
			printf(" BAD");
		printf("\n");
	}
	
	return 0;
}