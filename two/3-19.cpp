#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
void printList(LinkList &l){//�������
	LNode *p = l->next;
	while(p!=l){
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//����һ����������
	LNode *p = l;
	for(int i=0;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = rand()%10;
		p->next = q;
		p = q;
	}
	p->next = l;
}
void del_All(LinkList &A){
	LNode *p,*minP,*pre,*minPre;//pre ָ��ǰ����ǰ����㣬minPreָ����Сֵ��ǰһ�����
	//p������������minP������С������һ�����
	while(A->next!=A){//��Ϊ�գ�������Сֵ
		p = A->next;//��ͷ��ʼ��������
		pre = A;
		minP = p;
		minPre = pre;
		while(p!=A){//�������������Сֵ
			if(p->data<minP->data){
				minP = p;//������Сֵ���
				minPre = pre;//������Сֵ����ǰ��
			}
			pre = p;
			p = p->next;
		}
		printf("%d ",minP->data);//�����Сֵ���
		minPre->next = minP->next;//����Сֵ������
		free(minP);//ɾ����Сֵ���
	}
	free(A);//�ͷ�ͷ���
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	initTestList(A,10);
	printList(A);
	del_All(A);
	if(A)  printf("\nYES!");
	else printf("\nNO!");
	return 0;
}

