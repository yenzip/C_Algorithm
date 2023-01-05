#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {	// 이중 연결리스트 노드
	char elem;
	struct DListNode *prev;
	struct DListNode *next;
} DListNode;

typedef struct {	// 이중 연결리스트
	DListNode H;
	DListNode T;
	int nCount;
} DListType;

void init(DListType *D) {	// 이중 연결리스트 초기화
	D->H.prev = NULL;
	D->H.next = &D->T;
	D->T.prev = &D->H;
	D->T.next = NULL;
	D->nCount = 0;
}

void add(DListType *D, int r, char e) {	// 노드 추가
	DListNode *n = (DListNode *)malloc(sizeof(DListNode));
	n->elem = e;
	n->prev = NULL;
	n->next = NULL;

	if (r < 1 || r > D->nCount + 1) {
		printf("invalid position\n");
		return;
	}

	DListNode *p = &D->H;
	for (int i = 1; i < r; i++)
		p = p->next;

	n->next = p->next;
	n->prev = p;
	p->next->prev = n;
	p->next = n;

	D->nCount++;
}

void delete(DListType *D, int r) {	// 노드 삭제
	if (r < 1 || r > D->nCount) {
		printf("invalid position\n");
		return;
	}

	DListNode *p = D->H.next;
	for (int i = 1; i < r; i++)
		p = p->next;

	p->next->prev = p->prev;
	p->prev->next = p->next;

	free(p);
	D->nCount--;
}

void get(DListType *D, int r) {	// 원소 반환
	if (r < 1 || r > D->nCount) {
		printf("invalid position\n");
		return;
	}

	DListNode *p = D->H.next;
	for (int i = 1; i < r; i++)
		p = p->next;
	printf("%c\n", p->elem);
}

void print(DListType *D) {	// 이중 연결리스트 출력
	DListNode *p = D->H.next;
	for (; p != &D->T; p = p->next)
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