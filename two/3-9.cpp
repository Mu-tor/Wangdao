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
	while(p){
		printf("%d",p->data);
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
	p->next = NULL;
}
void sortPrintDel(LinkList &l){
	LNode *p,*minPre,*q;//minPre��¼��С����ǰһ�����
	int min = __INT_MAX__;
	while(l->next){//ֱ������Ϊ��
		p = l;//��ͷ��ʼ����
		min = __INT_MAX__;//����Сֵ��Ϊ���
		while(p->next){//���������ҵ���С���
			if(p->next->data<min){
				min = p->next->data;//��ȡ��С���ֵ
				minPre = p;//��ȡ��С���λ��
			}//if
			p = p->next;
		}//while
		printf("%d",minPre->next->data);//�����Сֵ
		q = minPre->next;//qΪҪɾ���Ľ��
		minPre->next = q->next;
		free(q);
	}
}
int main(){
    LinkList l = (LinkList)malloc(sizeof(LNode));
    initTestList(l,20);
    printList(l);
    sortPrintDel(l);
	return 0;
}

