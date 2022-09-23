#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *link;
}LNode,*LinkList;
void printList(LinkList &l){//�������
	LNode *p = l->link;
	while(p){
		printf("%d ",p->data);
		p = p->link;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int m,int n){//����һ����������
	//mΪ���ȣ�nΪ����
	LNode *p = l;
	for(int i=0;i<m;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = (int)pow(-1.0,(double)i)*rand()%n;
		p->link = q;
		p = q;
	}
	p->link = NULL;
}

void delSameAbs(LNode *head,int n){//ɾ����ͬ����ֵ���
	int *s = (int*)malloc(sizeof(int)*n+1);//����һ������Ϊn������
	memset(s,0,sizeof(int)*n+1);//�����ÿ�
	int abs;//�洢��ǰֵ�ľ���ֵ
	LNode *pre = head,*p = head->link;
	while(p){
		abs = p->data>0?p->data:-p->data;
		if(s[abs] == 0){//δ������ͬԪ�ؾ���ֵ�Ľ��
			s[abs] = 1;//��ǳ��ֹ���Ԫ�صľ���ֵ
			p = p->link;//������һ���
			pre = pre->link;
		}else{//�ѳ���Ԫ�ؾ���ֵ�Ľ��
			pre->link = p->link;//�Ͽ��ýڵ�
			free(p);//ɾ�����
			p = pre->link;//���Ͻ�㣬��������
		}
	}
}
int main(){
	LinkList l = (LinkList)malloc(sizeof(LNode));
	int m = 20,n = 10;
	initTestList(l,m,n);
	printList(l);
	delSameAbs(l,n);
	printList(l);
	return 0;
}

