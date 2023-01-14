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
	for (; p != NULL; p = p->next)
		printf("%d ", p->elem);
	printf("\n");
}

int member(SetType *B, int e) {	// ���Ұ� ������ ������� Ȯ��
	SetNode *p = B->H;
	while (p != NULL && p->elem != e)
		p = p->next;
	if (p == NULL)
		return 0;
	else
		return 1;
}

int subset(SetType *A, SetType *B) {	// �κ����� �˻�
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

	printf("%d\n", subset(&A, &B));	// �κ����� �˻�

	return 0;
}