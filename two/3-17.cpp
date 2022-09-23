#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next,*prior;
}LNode,*LinkList;
void printList(LinkList &l){//输出链表
	LNode *p = l->next;
	while(p!=l){
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//创建一个测试链表
	l->next = l;
	l->prior = l;
	LNode *p = l;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		q->next = p->next;
		q->prior = p;
		p->next->prior = q;
		p->next = q;
		p = q;
	}
	for(int i=n-1;i>=0;i--){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		q->next = p->next;
		q->prior = p;
		p->next->prior = q;
		p->next = q;
		p = q;
	}
}
int isReverse(LinkList &A){
	LNode *p = A->next,*q = A->prior;//p，q分别从右和左两个方向遍历A
	while(p->next!=q&&p!=q){
		if(p->data!=q->data)    return 0;
		else{
			p = p->next;
			q = q->prior;
		}
	}
	return 1;
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	initTestList(A,10);
	printList(A);
	printf(isReverse(A)?"yes":"no");
	return 0;
}

