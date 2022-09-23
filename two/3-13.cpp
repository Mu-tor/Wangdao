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

LinkList mergeList(LinkList &A,LinkList &B){
	//�������������Ա�ݼ��ϲ�
	LNode *a = A->next,*b = B->next,*p;//a,b�ֱ���������A��B����
	//pΪ���߽�㣬�����ݴ�ra��rb����һ�����
	LinkList l = (LinkList)malloc(sizeof(LNode));
	l->next = NULL;
	while(a&&b){//�ж��Ƿ�Ϊ�ս��
		if(a->data<b->data){//����Сֵ���뵽l
			p = a->next;   //�ݴ�a����һ����㣬���ö���
			a->next = l->next;//ͷ�巨���뵽l���
			l->next = a;
			a = p;//��a���ָ�����������A����
		}else{
			p = b->next;   //�ݴ�
			b->next = l->next;
			l->next = b;
			b = p;
		}
	}
	if(a){//��Ϊ���������������������
        while(a){
			p = a->next;   //�ݴ�a����һ����㣬���ö���
			a->next = l->next;//ͷ�巨���뵽l���
			l->next = a;
			a = p;//��a���ָ�����������A����
		}
	}else{
		while(b){
			p = b->next;   //�ݴ�a����һ����㣬���ö���
			b->next = l->next;//ͷ�巨���뵽l���
			l->next = b;
			b = p;//��a���ָ�����������A����
		}
	}
	return l;
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,30);
	initTestList(B,10);
	printList(A);
	printList(B);
	LinkList l = mergeList(A,B);
	printList(l);
	return 0;
}

