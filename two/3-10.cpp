#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
void printList(LinkList &l){//�������
	LNode *p = l->next;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//����һ����������
	LNode *p = l;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
LinkList disIntList(LinkList &A){//��l1����ż�Էֽ⵽l1,l2
	LinkList B = (LinkList)malloc(sizeof(LNode));
	LNode *p = A->next;//pΪ����ָ�룬����������ʼ����
	LNode *ra = A,*rb = B;//ra��rb�ֱ�ָ��A��B�����β���
	A->next = B->next = NULL;//���A��B����
	while(p->next){
		ra->next = p; //�Ȱѽ�����ӵ�A����
		ra = ra->next;
		p = p->next;//��������
		if(p->next){//ż����
			rb->next = p;//��ż��������ӵ�l2
			rb = rb->next;//���ӵ���һ�����
			p = p->next;
		}
	}
	ra->next = rb->next = NULL;//��A,B��β��Ϊ��
	return B;
}
int main(){
	LinkList l1 = (LinkList)malloc(sizeof(LNode));
	initTestList(l1,20);
	printList(l1);
	LinkList l2 = disIntList(l1);
	printList(l1);
	printList(l2);
	return 0;
}

