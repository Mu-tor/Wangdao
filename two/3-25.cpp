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

int Length(LinkList &l){//��ȡ����ĳ���
	int len = 0;
	LNode *p = l;
	while(p->next){
		len++;
		p = p->next;
	}
	return len;
}
void reverse(LinkList &l){//��������
	LNode *p = l->next,*q;//p��������qΪ����ָ�룬��ֹ����
	l->next = NULL;
	while(p){
		q = p->next;//�ݴ���һ��㣬��ֹ����
		p->next = l->next;//ͷ�巨������
		l->next = p;
		p = q;
	}
}
LinkList midList(LinkList &l){
	int len = Length(l),i = 0;//len��������ȣ�i������������n/2�����
	LNode *p = l,*q = l->next;
	while(i<len/2){//��������n/2 -1�����
		p = p->next;
		i++;
	}
	reverse(p);//������������
	printList(p);
	LNode *r = l;//���������㵽����l
	while(p&&q){
		r->next = q;
		q = q->next;
		r = r->next;
  		r->next = p;
		p = p->next;
		r = r->next;
	}
	if(p){
		r->next = p;
		p = p->next;
		r = r->next;
	}else if(q){
		r->next = q;
		q = q->next;
		r = r->next;
	}
	r->next = NULL;//β����ÿ�
	return l;
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initTestList(l,10);
	printList(l);
	l = midList(l);
	printList(l);
	return 0;
}

