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
		printf("%d",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//创建一个测试链表
	LNode *p = l;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = rand()%10;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
LinkList disCreat(LinkList &A){
	//头插法分配链表B
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;//将B链表置空
	LNode *ra = A;//ra指向A尾结点
    LNode *p = A->next,*q;
	A->next = NULL;//将A链表置空
	while(p){
		ra->next = p; ra = ra->next;//尾插法插入到A结点
		p = p->next;
		if(p){
			q = p->next;//保留p结点的下一个结点，防止断链
			p->next = B->next;//头插法插入带B结点
			B->next = p;
			p = q;
		}
	}
	return B;
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	initTestList(A,3);
	printList(A);
	LinkList B = disCreat(A);
	printList(A);
	printList(B);
	return 0;
}
