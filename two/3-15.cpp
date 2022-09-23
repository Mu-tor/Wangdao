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
void mergeList(LinkList &A,LinkList &B){
	LNode *pa = A->next,*pb = B->next;//pa��pb�ֱ���������A��B����
	A->next = NULL;//��A������Ϊ��
	LNode *q = A,*p;//qָ��A�����β���,p���Ϊ���߽�㣬��ֹ�������
	while(pa&&pb){//����A��B����
		if(pa->data<pb->data){//�ҵ�A��B��ֵͬ�Ľ��
			pa = pa->next;
		}else if(pa->data>pb->data){
			pb = pb->next;
		}else{
			p = pa->next;//�ݴ���һ����㣬���ö���
			pa->next = q->next;//β�巨���뵽A����
			q->next = pa;
			q = pa;
            pa = p;//�ָ����
            pb = pb->next;//����������һ��Ԫ��
		}
	}
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,12);
	initTestList(B,10);
	printList(A);
	printList(B);
	mergeList(A,B);
	printList(A);
	return 0;
}

