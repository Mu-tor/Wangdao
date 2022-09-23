#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
void initTestList(LinkList &l,int n){//创建一个测试链表
	LNode *p = l,*p2;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		if(i==n/2) p2 = q;
		p->next = q;
		p = q;
	}
	p->next = p2;
}
LNode* findLoopStart(LinkList &l){
	LNode *fast = l,*slow = l;
	while(fast!=NULL&&fast->next!=NULL){
		slow = slow->next;//慢指针前进一
		fast = fast->next->next;//快指针前进二
		if(fast==slow){//快慢指针相遇
			break;
		}
	}
	if(fast==NULL||fast->next==NULL){
		return NULL;//没有环
	}
	LNode *q1 = l,*q2 = slow;
	while(q1!=q2){//快慢指针相遇于入环点
		q1 = q1->next;//从头往后前进
		q2 = q2->next;//在环内前进
	}
	return q1;
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initTestList(l,20);
	LNode *loopStart =findLoopStart(l);
	if(loopStart){
		printf("%d",loopStart->data);
	}else printf("NULL");
	return 0;
}

