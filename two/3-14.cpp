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
	for(int i=n/2;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}

LinkList setSamValList(LinkList &A,LinkList &B){
	//��ȡ��ͬ��������
	LNode *pa = A->next,*pb = B->next,*q;//pa,pb�ֱ���������A��B����
	LinkList l = (LinkList)malloc(sizeof(LNode));
	LNode *r = l;//rָ��l��β���
	while(pa&&pb){
		if(pa->data>pb->data){//�ҵ�������ȵĽ��
			pb = pb->next;
		}else if(pa->data<pb->data){
			pa = pa->next;
		}else{//����������
			q = (LNode*)malloc(sizeof(LNode));//����һ��ֵ��ͬ�Ľ��
			q->data = pa->data;//��ֵ
   			r->next = q;
   			r = q;
			pa = pa->next;
			pb = pb->next;
		}
	}
	r->next = NULL;
	return l;
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,10);
	initTestList(B,12);
	printList(A);
	printList(B);
	LinkList l = setSamValList(A,B);
	printList(l);
	return 0;
}

