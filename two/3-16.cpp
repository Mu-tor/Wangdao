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
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//����һ����������
	LNode *p = l;
	for(int i=1;i<n;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
bool isBranch(LinkList &A,LinkList &B){
	LNode *pa = A->next,*pb = B->next,*pre = A->next;
	//pa��pb�ֱ�ΪA��B�Ĺ��߽�㣬pre�����ָ�����ǰ�������Ľ��
	while(pa&&pb){
		if(pa->data!=pb->data){
			pre = pre->next;
			pa = pre;   //A���µĽ�㿪ʼ����
            pb = B->next;//���ֲ�ͬ��ֵ��B�������±���
		}else{
			pa = pa->next;//��������A����
			pb = pb->next;//��������B����
		}
	}
	return pb==NULL;//B�����Ƿ��������
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,8);
	initTestList(B,5);
	printList(A);
	printList(B);
	if(isBranch(A,B)){
		printf("B��A������������");
	}else{
		printf("B����A������������");
	}
	return 0;
}

