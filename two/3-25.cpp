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

int Length(LinkList &l){//获取链表的长度
	int len = 0;
	LNode *p = l;
	while(p->next){
		len++;
		p = p->next;
	}
	return len;
}
void reverse(LinkList &l){//逆置链表
	LNode *p = l->next,*q;//p遍历链表，q为工具指针，防止断链
	l->next = NULL;
	while(p){
		q = p->next;//暂存下一结点，防止断链
		p->next = l->next;//头插法插入结点
		l->next = p;
		p = q;
	}
}
LinkList midList(LinkList &l){
	int len = Length(l),i = 0;//len存放链表长度，i用来遍历到第n/2个结点
	LNode *p = l,*q = l->next;
	while(i<len/2){//遍历到第n/2 -1个结点
		p = p->next;
		i++;
	}
	reverse(p);//将后面结点逆置
	printList(p);
	LNode *r = l;//用来插入结点到链表l
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
	r->next = NULL;//尾结点置空
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

