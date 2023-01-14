#include <stdio.h>
#include <stdlib.h>

typedef struct SetNode {	// 집합 노드
	int elem;
	struct SetNode *next;
} SetNode;

typedef struct {	// 집합
	SetNode *H;
} SetType;

void init(SetType *S) {	// 집합 초기화
	S->H = NULL;
}

void add(SetType *S, int e) {	// 노드 추가
	SetNode *n = (SetNode *)malloc(sizeof(SetNode));
	n->elem = e;
	n->next = NULL;

	SetNode *p = S->H;
	if (p == NULL)
		S->H = n;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = n;
	}
}

void print(SetType *S) {	// 집합 출력
	SetNode *p = S->H;
	for (; p != NULL; p = p->next)
		printf("%d ", p->elem);
	printf("\n");
}

int member(SetType *B, int e) {	// 원소가 집합의 멤버인지 확인
	SetNode *p = B->H;
	while (p != NULL && p->elem != e)
		p = p->next;
	if (p == NULL)
		return 0;
	else
		return 1;
}

int subset(SetType *A, SetType *B) {	// 부분집합 검사
	SetNode *p = A->H;
	if (p == NULL)
		return 0;
	while (p != NULL) {
		if (member(B, p->elem) == 0)
			return p->elem;
		p = p->next;
	}
	return 0;
}

int main() {
	SetType A, B;
	int n, e;

	init(&A);	// 집합 A
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		add(&A, e);
	}

	init(&B);	// 집합 B
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		add(&B, e);
	}

	printf("%d\n", subset(&A, &B));	// 부분집합 검사

	return 0;
}