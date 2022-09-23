#include<cstdio>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
int Length(LinkList &l){
	int n = 0;
	LNode *p = l;
	while(p->next){
		++n;
		p = p->next;
	}
	return n;
}
void printList(LinkList &l){//输出链表
	LNode *p = l->next;
	while(p){
		printf("%d",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l1,LinkList &l2,int n){//创建一个测试链表
	LNode *p = l1;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		if(i == n/2) l2->next = p;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
LNode* getSameNode(LinkList &l1,LinkList &l2){
	int len1 = Length(l1),len2 = Length(l2),dist;//dist存储两个链表的长度差
	LinkList longList,sortList;
	if(len1>len2){
		longList = l1;
		sortList = l2;
		dist = len1-len2;
	}else{
		longList = l2;
		sortList = l1;
		dist = len2 - len1;
	}
	while(dist--){
		longList = longList->next;
	}
	while(longList){
		if(longList==sortList)
			return longList;
		else{
			longList = longList->next;
			sortList = sortList->next;
		}
	}
	return NULL;
}
int main(){
	LinkList l1 = (LinkList)malloc(sizeof(LNode));
	LinkList l2 = (LinkList)malloc(sizeof(LNode));
	initTestList(l1,l2,10);
	printList(l1);
	printList(l2);
	LNode *p = getSameNode(l1,l2);
	if(p) printf("%d",p->data);
	else printf("NULL");
	return 0;
}

