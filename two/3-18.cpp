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
	while(p!=l){
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//����һ����������
	LNode *p = l;
	for(int i=n/2;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = l;
}
void mergeReList(LinkList &A,LinkList &B){
	LNode *pa = A->next,*pb = B->next;//pa,pb�ֱ����A��B����
	while(pa->next!=A){//����A����ʹpaָ��A����ı�β
		pa = pa->next;
	}
	pa->next = pb;//����A��B����
	while(pb->next!=B){
		pb = pb->next;
	}
	pb->next = A;//��β���ӵ���ͷ
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,10);
	initTestList(B,22);
	printList(A);
	printList(B);
	mergeReList(A,B);
	printList(A);
	return 0;
}

