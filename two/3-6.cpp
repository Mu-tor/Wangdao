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
void Sort(LinkList &l){//直接插入排序
	LNode *p = l->next,*q,*r;//q存储要插入的结点的前驱结点
	r = p->next;//保证不断链
	p->next = NULL;
	p = r;
	while(p){
		r = p->next;//r为p结点的后继，保证不断链
		q = l;//q结点从头开始遍历
		while(q->next&&q->next->data<p->data){//遍历p结点前的结点寻找插入位置
			q = q->next;
		}//while
		p->next = q->next;
		q->next = p;
		p = r;//继续排序
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

