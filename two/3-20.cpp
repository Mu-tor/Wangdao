#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct LNode {
	int data, freq;
	struct LNode *next, *pred;
} LNode, *LinkList;

void initList(LinkList &l, int n) { //��ʼ������
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

void printList(LinkList &l) { //��ӡ����
	LNode *p = l->next;
	while (p) {
		printf("%d,%d ", p->data, p->freq);
		p = p->next;
	}
	printf("\n");
}

LNode *Locate(LinkList &l, int x) { //�ҵ�ֵΪx�Ľ�㲢������Ƶ������
	LNode *p = l->next, *q = l->next; //p������ڱ���l����,q�����������Ƶ��С�ڵ���p�Ľ��
	while (p) { //��������ֱ���ҵ����
		if (p->data == x) {
			p->freq++;//����Ƶ�ȼ�һ
			while (q->freq > p->freq) {
				q = q->next;//�ҵ���һ��С�ڵ���pƵ�ȵĽ��
			}
			if (p == q)
				return p;//λ�ò���
			p->pred->next = p->next;//�Ͽ�p���
			p->next->pred = p->pred;
			q->pred->next = p;//��p���뵽q֮ǰ
			p->pred = q->pred;
			p->next = q;
			q->pred = p;
			return p;//����p���ָ��
		}
		p = p->next;//������һ�����
	}
	return NULL;//δ�ҵ����
}

int main() {
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initList(l, 10);
	printf("��ʼ����");
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
			printf("δ�ҵ���");
		}
	}
	return 0;
}
