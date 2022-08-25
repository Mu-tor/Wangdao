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
void Sort(LinkList &l){//ֱ�Ӳ�������
	LNode *p = l->next,*q,*r;//q�洢Ҫ����Ľ���ǰ�����
	r = p->next;//��֤������
	p->next = NULL;
	p = r;
	while(p){
		r = p->next;//rΪp���ĺ�̣���֤������
		q = l;//q����ͷ��ʼ����
		while(q->next&&q->next->data<p->data){//����p���ǰ�Ľ��Ѱ�Ҳ���λ��
			q = q->next;
		}//while
		p->next = q->next;
		q->next = p;
		p = r;//��������
	}//while(p)
}

int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initTestList(l,10);
	printList(l);
	Sort(l);
	printList(l);
	return 0;
}

