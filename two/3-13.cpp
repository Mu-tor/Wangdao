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
	for(int i=n/2;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}

LinkList mergeList(LinkList &A,LinkList &B){
	//将两个递增线性表递减合并
	LNode *a = A->next,*b = B->next,*p;//a,b分别用来遍历A，B链表
	//p为工具结点，用于暂存ra，rb的下一个结点
	LinkList l = (LinkList)malloc(sizeof(LNode));
	l->next = NULL;
	while(a&&b){//判断是否为空结点
		if(a->data<b->data){//将较小值插入到l
			p = a->next;   //暂存a的下一个结点，放置断链
			a->next = l->next;//头插法插入到l结点
			l->next = a;
			a = p;//将a结点恢复，继续遍历A链表
		}else{
			p = b->next;   //暂存
			b->next = l->next;
			l->next = b;
			b = p;
		}
	}
	if(a){//将为遍历结束的链表遍历结束
        while(a){
			p = a->next;   //暂存a的下一个结点，放置断链
			a->next = l->next;//头插法插入到l结点
			l->next = a;
			a = p;//将a结点恢复，继续遍历A链表
		}
	}else{
		while(b){
			p = b->next;   //暂存a的下一个结点，放置断链
			b->next = l->next;//头插法插入到l结点
			l->next = b;
			b = p;//将a结点恢复，继续遍历A链表
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

