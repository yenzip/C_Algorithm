#include <stdio.h>
#include <stdlib.h>

typedef struct SetNode {	// ���� ���
	int elem;
	struct SetNode *next;
} SetNode;

typedef struct {	// ����
	SetNode *H;
} SetType;

void init(SetType *S) {	// ���� �ʱ�ȭ
	S->H = NULL;
}

void add(SetType *S, int e) {	// ��� �߰�
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

void print(SetType *S) {	// ���� ���
	SetNode *p = S->H;
	if (p == NULL) {
		printf(" 0\n");
		return;
	}
	for (; p != NULL; p = p->next)
		printf(" %d", p->elem);
	printf("\n");
}

void unionSet(SetType *A, SetType *B) {	// ������
	SetType S;
	SetNode *p = A->H, *q = B->H;

	init(&S);

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem) {
			add(&S, p->elem);
			p = p->next;
		}
		else if (p->elem > q->elem) {
			add(&S, q->elem);
			q = q->next;
		}
		else {
			add(&S, p->elem);
			p = p->next;	q = q->next;
		}
	}

	while (p != NULL) {
		add(&S, p->elem);
		p = p->next;
	}

	while (q != NULL) {
		add(&S, q->elem);
		q = q->next;
	}

	print(&S);
}

void intersectSet(SetType *A, SetType *B) {	// ������
	SetType S;
	SetNode *p = A->H, *q = B->H;

	init(&S);

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem)
			p = p->next;
		else if (p->elem > q->elem)
			q = q->next;
		else {
			add(&S, p->elem);
			p = p->next;	q = q->next;
		}
	}

	print(&S);
}

void subtractSet(SetType *A, SetType *B) {	// ������ (A-B)
	SetType S;
	SetNode *p = A->H, *q = B->H;

	init(&S);

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem) {
			add(&S, p->elem);
			p = p->next;
		}
		else if (p->elem > q->elem)
			q = q->next;
		else {
			p = p->next;	q = q->next;
		}
	}

	while (p != NULL) {
		add(&S, p->elem);
		p = p->next;
	}

	print(&S);
}

int main() {
	SetType A, B;
	int n, e;

	init(&A);	// ���� A
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		add(&A, e);
	}

	init(&B);	// ���� B
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		add(&B, e);
	}

	unionSet(&A, &B);		// ������
	intersectSet(&A, &B);	// ������
	subtractSet(&A, &B);	// ������

	return 0;
}