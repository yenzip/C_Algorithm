#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
	char data;
	struct StackNode *next;
} StackNode;

typedef struct {
	StackNode *top;
	int size;
} StackType;

void init(StackType *S) {
	S->top = NULL;
	S->size = 0;
}

int isEmpty(StackType *S) {
	return S->size == 0;
}

void push(StackType *S, char e) {
	StackNode *n = (StackNode *)malloc(sizeof(StackNode));
	n->data = e;
	n->next = S->top;
	S->top = n;
	S->size++;
}

char pop(StackType *S) {
	StackNode *p = S->top;
	char e = p->data;
	S->top = p->next;
	free(p);
	S->size--;
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

	if (isWrong == 0 && isEmpty(&S))
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