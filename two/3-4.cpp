#include<cstdio>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void delNextNode(LNode *p){//删除p结点的下一个结点
	LNode *q = p->next;
	p->next = q->next;
	free(q);
}

void delMinData(LinkList &l){
	LNode *p = l,*mP;//mp为最小值结点的前一个结点
	int min = __INT_MAX__;
	while(p->next){
		if(p->next->data < min){
			min = p->next->data;
			mP = p;
		}//if
		p = p->next;
	}//while
	delNextNode(mP);//删除mp结点的下一个结点
}
void initList(LinkList &l,int n){//创建一个从n到0再从1到n的链表
	LNode *p = l;
	for(int i=n;i>0;i--){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}//for
	for(int i=0;i<=n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}//for
	p->next = NULL;//末尾设为NULL
}
void printList(LinkList &l){//输出链表
	LNode *p = l->next;
	while(p){
		printf("%d",p->data);
		p = p->next;
	}//while
	printf("\n");
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initList(l,8);
	printList(l);
	delMinData(l);
	printList(l);
	return 0;
}
