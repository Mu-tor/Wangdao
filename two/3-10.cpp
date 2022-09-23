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
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//创建一个测试链表
	LNode *p = l;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
LinkList disIntList(LinkList &A){//将l1按奇偶性分解到l1,l2
	LinkList B = (LinkList)malloc(sizeof(LNode));
	LNode *p = A->next;//p为工作指针，用来遍历初始链表
	LNode *ra = A,*rb = B;//ra，rb分别指向A，B链表的尾结点
	A->next = B->next = NULL;//清空A，B链表
	while(p->next){
		ra->next = p; //先把结点链接到A链表
		ra = ra->next;
		p = p->next;//继续遍历
		if(p->next){//偶序数
			rb->next = p;//将偶数结点链接到l2
			rb = rb->next;//链接到下一个结点
			p = p->next;
		}
	}
	ra->next = rb->next = NULL;//将A,B结尾设为空
	return B;
}
int main(){
	LinkList l1 = (LinkList)malloc(sizeof(LNode));
	initTestList(l1,20);
	printList(l1);
	LinkList l2 = disIntList(l1);
	printList(l1);
	printList(l2);
	return 0;
}

