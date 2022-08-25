#include<cstdio>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void delNextNode(LNode *p){//ɾ��p������һ�����
	LNode *q = p->next;
	p->next = q->next;
	free(q);
}

void delMinData(LinkList &l){
	LNode *p = l,*mP;//mpΪ��Сֵ����ǰһ�����
	int min = __INT_MAX__;
	while(p->next){
		if(p->next->data < min){
			min = p->next->data;
			mP = p;
		}//if
		p = p->next;
	}//while
	delNextNode(mP);//ɾ��mp������һ�����
}
void initList(LinkList &l,int n){//����һ����n��0�ٴ�1��n������
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
	p->next = NULL;//ĩβ��ΪNULL
}
void printList(LinkList &l){//�������
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
