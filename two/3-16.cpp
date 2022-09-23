#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
void printList(LinkList &l){//输出链表
	LNode *p = l->next;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//创建一个测试链表
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
	//pa，pb分别为A，B的工具结点，pre用来恢复到当前遍历到的结点
	while(pa&&pb){
		if(pa->data!=pb->data){
			pre = pre->next;
			pa = pre;   //A从新的结点开始遍历
            pb = B->next;//出现不同的值，B链表重新遍历
		}else{
			pa = pa->next;//继续遍历A链表
			pb = pb->next;//继续遍历B链表
		}
	}
	return pb==NULL;//B链表是否遍历结束
}
int main(){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	initTestList(A,8);
	initTestList(B,5);
	printList(A);
	printList(B);
	if(isBranch(A,B)){
		printf("B是A的连续子序列");
	}else{
		printf("B不是A的连续子序列");
	}
	return 0;
}

