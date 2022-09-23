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
		printf("%d",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//����һ����������
	LNode *p = l;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = rand()%10;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
LinkList disCreat(LinkList &A){
	//ͷ�巨��������B
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;//��B�����ÿ�
	LNode *ra = A;//raָ��Aβ���
    LNode *p = A->next,*q;
	A->next = NULL;//��A�����ÿ�
	while(p){
		ra->next = p; ra = ra->next;//β�巨���뵽A���
		p = p->next;
		if(p){
			q = p->next;//����p������һ����㣬��ֹ����
			p->next = B->next;//ͷ�巨�����B���
			B->next = p;
			p = q;
		}
	}
	return B;
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	initTestList(A,3);
	printList(A);
	LinkList B = disCreat(A);
	printList(A);
	printList(B);
	return 0;
}
