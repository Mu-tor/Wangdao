#include<cstdio>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void rePrint(LinkList &l){
	if(l==NULL) return;
	rePrint(l->next);
	printf("%d",l->data);
}
void initList(LinkList &l,int n){
	LNode *q = l;
	for(int i=1;i<n;i++){
		LNode *p = (LNode*)malloc(sizeof(LNode));
		p->data = i;
		q->next = p;
		q = p;
	}
	q->next = NULL;
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	initList(l,10);
	rePrint(l->next);
	return 0;
}


