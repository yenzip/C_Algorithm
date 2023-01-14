#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char data[1000];
	int top;
} StackType;

void init(StackType *S) {
	S->top = -1;
}

int isEmpty(StackType *S) {
	return S->top == -1;
}

void push(StackType *S, char e) {
	S->top++;
	S->data[S->top] = e;
}

char pop(StackType *S) {
	char e = S->data[S->top];
	S->top--;
	return e;
}

void isBalanced(char str[]) {
	StackType S;
	char e, t;
	int cnt = 0, isWrong = 0;

	init(&S);

	for (int i = 0; i < strlen(str); i++) {
		e = str[i];

		if (e == '(' || e == '{' || e == '[') {
			push(&S, e);
			cnt++;
		}
		else if (e == ')' || e == '}' || e == ']') {
			if (isEmpty(&S))
				isWrong = 1;
			else {
				t = pop(&S);
				if ((t == '(' && e != ')') || (t == '{' && e != '}') || (t == '[' && e != ']'))
					isWrong = 1;
			}
			cnt++;
		}
	}

	if(isWrong == 0 && isEmpty(&S))
		printf("OK_%d\n", cnt);
	else
		printf("Wrong_%d\n", cnt);
}

int main() {
	char str[1001];

	gets(str);

	isBalanced(str);

	return 0;
}