/* [ ���Ḯ��Ʈ ���� ] ���׽� ���� */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {	// ���� ���Ḯ��Ʈ ���
	int coef;	// ���� ���
	int exp;	// ���� ����
	struct ListNode *next;
} ListNode;

typedef struct {	// ���� ���Ḯ��Ʈ
	ListNode *H;
} List;

void init(List *L) {	// ���� ���Ḯ��Ʈ �ʱ�ȭ
	L->H = NULL;
}

void addTerm(List *L, int c, int e) {	// ���(��) �߰�
	ListNode *n = (ListNode *)malloc(sizeof(ListNode));
	n->coef = c;
	n->exp = e;
	n->next = NULL;

	ListNode *p = L->H;
	if (p == NULL)
		L->H = n;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = n;
	}
}

void addPloy(List *L1, List *L2, List *L) {	// ���׽� ���� (���Ḯ��Ʈ ��ġ��)
	ListNode *p = L1->H, *q = L2->H;

	while (p != NULL && q != NULL) {
		if (p->exp > q->exp) {
			addTerm(L, p->coef, p->exp);
			p = p->next;
		}
		else if (p->exp < q->exp) {
			addTerm(L, q->coef, q->exp);
			q = q->next;
		}
		else {
			if (p->coef + q->coef != 0)
				addTerm(L, p->coef + q->coef, p->exp);
			p = p->next;	q = q->next;
		}
	}

	while (p != NULL) {
		addTerm(L, p->coef, p->exp);
		p = p->next;
	}

	while (q != NULL) {
		addTerm(L, q->coef, q->exp);
		q = q->next;
	}
}

void print(List *L) {	// ���� ���Ḯ��Ʈ ���
	ListNode *p = L->H;
	for (; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
	printf("\n");
}

int main() {
	List L1, L2, L;
	int n;
	int c, e;

	init(&L1);	// ���׽� 1
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		addTerm(&L1, c, e);
	}

	init(&L2);	// ���׽� 2
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		addTerm(&L2, c, e);
	}

	init(&L);
	addPloy(&L1, &L2, &L);	// ���׽� ����
	print(&L);

	return 0;
}