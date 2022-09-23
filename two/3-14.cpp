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

LinkList setSamValList(LinkList &A,LinkList &B){
	//获取相同结点的链表
	LNode *pa = A->next,*pb = B->next,*q;//pa,pb分别用来遍历A，B链表
	LinkList l = (LinkList)malloc(sizeof(LNode));
	LNode *r = l;//r指向l的尾结点
	while(pa&&pb){
		if(pa->data>pb->data){//找到两个相等的结点
			pb = pb->next;
		}else if(pa->data<pb->data){
			pa = pa->next;
		}else{//两个结点相等
			q = (LNode*)malloc(sizeof(LNode));//创建一个值相同的结点
			q->data = pa->data;//赋值
   			r->next = q;
   			r = q;
			pa = pa->next;
			pb = pb->next;
		}
	}
	r->next = NULL;
	return l;
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,10);
	initTestList(B,12);
	printList(A);
	printList(B);
	LinkList l = setSamValList(A,B);
	printList(l);
	return 0;
}

