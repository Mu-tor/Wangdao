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
void mergeList(LinkList &A,LinkList &B){
	LNode *pa = A->next,*pb = B->next;//pa，pb分别用来遍历A，B链表
	A->next = NULL;//将A链表置为空
	LNode *q = A,*p;//q指向A链表的尾结点,p结点为工具结点，防止链表断链
	while(pa&&pb){//遍历A，B链表
		if(pa->data<pb->data){//找到A，B相同值的结点
			pa = pa->next;
		}else if(pa->data>pb->data){
			pb = pb->next;
		}else{
			p = pa->next;//暂存下一个结点，放置断链
			pa->next = q->next;//尾插法插入到A链表
			q->next = pa;
			q = pa;
            pa = p;//恢复结点
            pb = pb->next;//继续查找下一个元素
		}
	}
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,12);
	initTestList(B,10);
	printList(A);
	printList(B);
	mergeList(A,B);
	printList(A);
	return 0;
}

