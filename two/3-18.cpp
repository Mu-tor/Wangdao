#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
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
	LNode *pa = A->next,*pb = B->next;//pa,pb分别遍历A，B链表
	while(pa->next!=A){//遍历A链表，使pa指向A链表的表尾
		pa = pa->next;
	}
	pa->next = pb;//链接A，B链表
	while(pb->next!=B){
		pb = pb->next;
	}
	pb->next = A;//表尾链接到表头
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

