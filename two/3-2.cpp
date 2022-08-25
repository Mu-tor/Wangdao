#include<cstdio>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void deletX(LinkList &l,int x){
	LNode *p = l,*q;
	while(p->next){
		if(p->next->data == x){
			q = p->next;
			p->next = q->next;
			free(q);//ÊÍ·Åq½áµã
		}else p = p->next;
	}//while
}
void inintList(LinkList &l,int n){
	LNode *q = l;
	for(int i=0;i<n;i++){
		LNode *p = (LNode*)malloc(sizeof(LNode));
		p->data = i;
		p->next = NULL;
		q->next = p;
		q = p;
	}
}
void printList(LinkList &l){
	LNode *q = l->next;
	while(q){
		printf("%d",q->data);
		q = q->next;
	}
	printf("\n");
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	inintList(l,10);
	printList(l);
	deletX(l,5);
	printList(l);
	return 0;
}

