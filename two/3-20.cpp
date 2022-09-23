#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct LNode {
	int data, freq;
	struct LNode *next, *pred;
} LNode, *LinkList;

void initList(LinkList &l, int n) { //初始化链表
	LNode *p = l;
	for (int i = 0; i < n; i++) {
		LNode *q = (LNode *)malloc(sizeof(LNode));
		q->data = i;
		q->freq = 0;
		p->next = q;
		q->pred = p;
		p = q;
	}
	p->next = NULL;
}

void printList(LinkList &l) { //打印链表
	LNode *p = l->next;
	while (p) {
		printf("%d,%d ", p->data, p->freq);
		p = p->next;
	}
	printf("\n");
}

LNode *Locate(LinkList &l, int x) { //找到值为x的结点并按查找频度排序
	LNode *p = l->next, *q = l->next; //p结点用于遍历l链表,q结点用来查找频度小于等于p的结点
	while (p) { //遍历链表直到找到结点
		if (p->data == x) {
			p->freq++;//访问频度加一
			while (q->freq > p->freq) {
				q = q->next;//找到第一个小于等于p频度的结点
			}
			if (p == q)
				return p;//位置不变
			p->pred->next = p->next;//断开p结点
			p->next->pred = p->pred;
			q->pred->next = p;//将p插入到q之前
			p->pred = q->pred;
			p->next = q;
			q->pred = p;
			return p;//返回p结点指针
		}
		p = p->next;//查找下一个结点
	}
	return NULL;//未找到结点
}

int main() {
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initList(l, 10);
	printf("初始链表：");
	printList(l);
	int x;
	LNode *p;
	while (scanf("%d", &x) != EOF) {
		p = Locate(l, x);
		if (p) {
			printf("x:%d\n", p->data);
			printList(l);
			printf("\n");
		} else {
			printf("未找到！");
		}
	}
	return 0;
}
