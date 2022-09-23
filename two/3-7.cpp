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
void delMidValue(LinkList &l,int min,int max){
	LNode *p = l,*q;//p���ڴ洢Ҫɾ���Ľ���ǰ�����q
	while(p->next){
		if(p->next->data>min&&p->next->data<max){
			q = p->next;    //q���ΪҪɾ���Ľ��
			p->next = q->next;//pָ��Ҫɾ���Ľ�����һ�����
			free(q);
		}else p = p->next;//p����
	}//while
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initTestList(l,20);
	printList(l);
	delMidValue(l,3,6);
	printList(l);
	return 0;
}

