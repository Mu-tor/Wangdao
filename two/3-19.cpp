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
	while(p!=l){
		printf("%d ",p->data);
		p = p->next;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int n){//创建一个测试链表
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
	LNode *p,*minP,*pre,*minPre;//pre 指向当前结点的前驱结点，minPre指向最小值的前一个结点
	//p用来遍历链表，minP保存最小结点的上一个结点
	while(A->next!=A){//表不为空，查找最小值
		p = A->next;//从头开始遍历链表
		pre = A;
		minP = p;
		minPre = pre;
		while(p!=A){//遍历链表查找最小值
			if(p->data<minP->data){
				minP = p;//更新最小值结点
				minPre = pre;//更新最小值结点的前驱
			}
			pre = p;
			p = p->next;
		}
		printf("%d ",minP->data);//输出最小值结点
		minPre->next = minP->next;//将最小值结点断链
		free(minP);//删除最小值结点
	}
	free(A);//释放头结点
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

