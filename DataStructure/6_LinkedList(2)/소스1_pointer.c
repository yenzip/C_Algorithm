/* [ 연결리스트 응용 ] 다항식 덧셈 */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {	// 단일 연결리스트 노드
	int coef;	// 항의 계수
	int exp;	// 항의 차수
	struct ListNode *next;
} ListNode;

typedef struct {	// 단일 연결리스트
	ListNode *H;
} List;

void init(List *L) {	// 단일 연결리스트 초기화
	L->H = NULL;
}

void addTerm(List *L, int c, int e) {	// 노드(항) 추가
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

void addPloy(List *L1, List *L2, List *L) {	// 다항식 덧셈 (연결리스트 합치기)
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

void print(List *L) {	// 단일 연결리스트 출력
	ListNode *p = L->H;
	for (; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
	printf("\n");
}

int main() {
	List L1, L2, L;
	int n;
	int c, e;

	init(&L1);	// 다항식 1
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		addTerm(&L1, c, e);
	}

	init(&L2);	// 다항식 2
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		addTerm(&L2, c, e);
	}

	init(&L);
	addPloy(&L1, &L2, &L);	// 다항식 덧셈
	print(&L);

	return 0;
}