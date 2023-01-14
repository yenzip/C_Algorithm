#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {	// ����
	char data[100];
	int top;
} StackType;

void init(StackType *S) {	// ���� �ʱ�ȭ
	S->top = -1;
}

int isEmpty(StackType *S) {	// �� ���� Ȯ��
	return S->top == -1;
}

int isFull(StackType *S, int n) {	// Ǯ ���� Ȯ��
	return S->top == n - 1;
}

void push(StackType *S, int n, char e) {	// ���� ����
	if (isFull(S, n)) {
		printf("Stack FULL\n");
		return;
	}

	S->top++;
	S->data[S->top] = e;
}

void pop(StackType *S) {	// ���� ����
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return;
	}

	S->top--;
}

void peek(StackType *S) {	// top ���� ���
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return;
	}

	printf("%c\n", S->data[S->top]);
}

void duplicate(StackType *S, int n) {	// pop -> push 2��
	char e = S->data[S->top];
	push(S, n, e);
}

void upRotate(StackType *S, int r) {	// top ���� n-1�� �Ʒ��� �̵�
	int t = S->top;

	if (r > t + 1)
		return;

	char tmp = S->data[t];
	for (int i = 1; i < r; i++, t--)
		S->data[t] = S->data[t - 1];
	S->data[t] = tmp;
}

void downRotate(StackType *S, int r) {	// top���� n��° ���� top���� �̵�
	int t = S->top;

	if (r > t + 1)
		return;

	char tmp = S->data[t - r + 1];
	for (int i = r - 1; i > 0; i--)
		S->data[t - i] = S->data[t - i + 1];
	S->data[t] = tmp;
}

void print(StackType *S) {	// ���� ���
	for (int i = S->top; i >= 0; i--)
		printf("%c", S->data[i]);
	printf("\n");
}

int main() {
	StackType S;
	int n, m, r;
	char calc[10], e;

	init(&S);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", calc);
		getchar();

		if (strcmp(calc, "PUSH") == 0) {
			scanf("%c", &e);
			getchar();
			push(&S, n, e);
		}
		if (strcmp(calc, "POP") == 0) {
			pop(&S);
		}
		if (strcmp(calc, "PEEK") == 0) {
			peek(&S);
		}
		if (strcmp(calc, "DUP") == 0) {
			duplicate(&S, n);
		}
		if (strcmp(calc, "UpR") == 0) {
			scanf("%d", &r);
			getchar();
			upRotate(&S, r);
		}
		if (strcmp(calc, "DownR") == 0) {
			scanf("%d", &r);
			getchar();
			downRotate(&S, r);
		}
		if (strcmp(calc, "PRINT") == 0) {
			print(&S);
		}
	}

	return 0;
}