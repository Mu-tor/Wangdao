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
	for(int i=0,j=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		if(i%2) j = i;
		q->data = j;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
void delSamVal(LinkList &l){
	LNode *p = l->next,*q;
	//p为工作结点，用来遍历链表，q存储相同的结点
	while(p->next){
		if(p->data == p->next->data){
			q = p->next;//保存要删除的结点
			p->next = q->next;
			free(q);
		}else p = p->next;
	}
}
int main(){
    LinkList l = (LinkList)malloc(sizeof(LNode));
    initTestList(l,10);
    printList(l);
    delSamVal(l);
    printList(l);
	return 0;
}

