#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct LNode {
	char data;
	struct LNode *next;
} LNode, *LinkList;

void initList(LinkList &l1, LinkList &l2, int n) { //初始化链表
	LNode *p = l1, *p2 = l2;
	for (int i = 0; i < n; i++) {
		LNode *q = (LNode *)malloc(sizeof(LNode));
		q->data = 'a' + rand() % 26;
		p2->next = q;
		p2 = q;
	}
	for (int i = 0; i < n; i++) {
		LNode *q = (LNode *)malloc(sizeof(LNode));
		q->data = 'a' + rand() % 26;
		if (i == n / 2)
			p2->next = q;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}

void printList(LinkList &l) { //打印链表
	LNode *p = l;
	while (p) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int getLength(LinkList &l) {//获取链表的长度
	int length = 0;
	LNode *p = l;
	while (p->next) {
		length++;
		p = p->next;
	}
	return length;
}

LNode *getSamPoint(LinkList &str1, LinkList &str2) {//获取指向相同结点的指针
	LNode *p, *q;
	int m = getLength(str1);
	int n = getLength(str2);
	int dif = m > n ? m - n : n - m; //获取两个链表长度的差值
	if (m > n) { //将较长链表赋值给p，较短赋值给q
		p = str1->next;
		q = str2->next;
	} else {
		q = str1->next;
		p = str2->next;
	}
	while (dif > 0) { //将较长链表前进两个链表的差值
		p = p->next;
		dif--;
	}
	while (p) { //p,q同时前进，直到两指针指向同一结点或到达表尾
		if (p == q)
			break;
		p = p->next;
		q = q->next;
	}
	return q;//返回相同的结点地址
}

int main() {
	LinkList str1 = (LinkList)malloc(sizeof(LNode));
	LinkList str2 = (LinkList)malloc(sizeof(LNode));
	initList(str1, str2, 10);
	printList(str1->next);
	printList(str2->next);
	LNode *q = getSamPoint(str1, str2);
	if (q) {
		printList(q);
	} else {
		printf("NULL");
	}
	return 0;
}
