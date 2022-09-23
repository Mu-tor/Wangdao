#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *link;
} LNode, *LinkList;

void initList(LinkList &l, int n) { //��ʼ������
	LNode *p = l;
	for (int i = 0; i < n; i++) {
		LNode *q = (LNode *)malloc(sizeof(LNode));
		q->data = i;
		p->link = q;
		p = q;
	}
	p->link = NULL;
}

void printList(LinkList &l) { //��ӡ����
	LNode *p = l->link;
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

int print_Re_K_Value(LNode *&h, int k) {
	LNode *fast = h, *slow = h;
	while (k > 0) { //fastָ��ǰ��k��λ��
		if (fast->link == NULL) //fast ָ����ǰ�����β
			return 0;
		else
			fast = fast->link;
		k--;
	}
	while (fast) { //fatsָ���slowָ��ͬʱǰ����ֱ��fast ָ�뵽���β
		fast = fast->link;
		slow = slow->link;
	}
	printf("value:%d\n", slow->data);
	return 1;
}

int main() {
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initList(l, 10);
	printList(l);
	if (print_Re_K_Value(l, 10)) {
		printf("YES��");
	} else {
		printf("NO! ");
	}
	return 0;
}
