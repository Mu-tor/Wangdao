#include<cstdio>
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
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
void reSetList(LinkList &l){
	LNode *p = l->next,*q;//p����ָ��ͷ�巨Ҫ����Ľ��
	l->next = NULL;//��ԭ����ָ�ÿ�
	while(p){
		q = p->next;
		p->next = l->next;
		l->next = p;
		p = q;
	}//while
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initTestList(l,10);
	printList(l);
	reSetList(l);
	printList(l);
	return 0;
}


