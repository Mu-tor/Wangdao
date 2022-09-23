#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
void initTestList(LinkList &l,int n){//����һ����������
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
		slow = slow->next;//��ָ��ǰ��һ
		fast = fast->next->next;//��ָ��ǰ����
		if(fast==slow){//����ָ������
			break;
		}
	}
	if(fast==NULL||fast->next==NULL){
		return NULL;//û�л�
	}
	LNode *q1 = l,*q2 = slow;
	while(q1!=q2){//����ָ���������뻷��
		q1 = q1->next;//��ͷ����ǰ��
		q2 = q2->next;//�ڻ���ǰ��
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

