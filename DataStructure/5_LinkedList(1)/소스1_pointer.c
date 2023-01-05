#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {	// ���� ���Ḯ��Ʈ ���
	char elem;
	struct DListNode *prev;
	struct DListNode *next;
} DListNode;

typedef struct {	// ���� ���Ḯ��Ʈ
	DListNode *H;
	DListNode *T;
	int nCount;
} DListType;

void init(DListType *D) {	// ���� ���Ḯ��Ʈ �ʱ�ȭ
	D->H = NULL;
	D->T = NULL;
	D->nCount = 0;
}

void add(DListType *D, int r, char e) {	// ��� ����
	DListNode *n = (DListNode *)malloc(sizeof(DListNode));
	n->elem = e;
	n->prev = NULL;
	n->next = NULL;

	if (r < 1 || r > D->nCount + 1) {
		printf("invalid position\n");
		return;
	}

	DListNode *p = D->H;
	if (r == 1) {
		if (p == NULL)	// ���� ó�� ����
			D->H = D->T = n;
		else {	// �� �� ����
			n->next = p;
			p->prev = n;
			D->H = n;
		}
	}
	else {
		for (int i = 1; i < r - 1; i++)
			p = p->next;

		if (p->next == NULL) {	// �� �� ����
			n->prev = p;
			p->next = n;
			D->T = n;
		}
		else {	// �߰� ����
			n->next = p->next;
			n->prev = p;
			p->next->prev = n;
			p->next = n;
		}
	}

	D->nCount++;
}

void delete(DListType *D, int r) {	// ��� ����
	if (r < 1 || r > D->nCount) {
		printf("invalid position\n");
		return;
	}

	DListNode *p = D->H;
	if (r == 1) {	
		if (p->next == NULL)	// ������ ���� �ϳ� ����
			D->H = D->T = NULL;
		else // �� �� ����
			D->H = p->next;
	}
	else {
		for (int i = 1; i < r; i++)
			p = p->next;

		if (p->next == NULL) { 	// �� �� ����
			p->prev->next = NULL;
			D->T = p->prev;
		}		
		else {	// �߰� ����
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
	}
	free(p);
	D->nCount--;
}

void get(DListType *D, int r) {	// ���� ��ȯ
	if (r < 1 || r > D->nCount) {
		printf("invalid position\n");
		return;
	}

	DListNode *p = D->H;
	for (int i = 1; i < r; i++)
		p = p->next;
	printf("%c\n", p->elem);
}

void print(DListType *D) {	// ���� ���Ḯ���z ���
	DListNode *p = D->H;
	for (; p != NULL; p = p->next)
		printf("%c", p->elem);
	printf("\n");
}

int main() {
	DListType D;
	int n, r;
	char c, e;

	init(&D);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);

		if (c == 'A') {
			scanf("%d %c", &r, &e);
			add(&D, r, e);
		}
		else if (c == 'D') {
			scanf("%d", &r);
			delete(&D, r);
		}
		else if (c == 'G') {
			scanf("%d", &r);
			get(&D, r);
		}
		else if (c == 'P')
			print(&D);
	}

	return 0;
}