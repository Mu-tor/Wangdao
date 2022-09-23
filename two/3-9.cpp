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
		printf("%d",p->data);
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
	p->next = NULL;
}
void sortPrintDel(LinkList &l){
	LNode *p,*minPre,*q;//minPre记录最小结点的前一个结点
	int min = __INT_MAX__;
	while(l->next){//直到链表为空
		p = l;//从头开始遍历
		min = __INT_MAX__;//将最小值置为最大
		while(p->next){//遍历链表找到最小结点
			if(p->next->data<min){
				min = p->next->data;//获取最小结点值
				minPre = p;//获取最小结点位置
			}//if
			p = p->next;
		}//while
		printf("%d",minPre->next->data);//输出最小值
		q = minPre->next;//q为要删除的结点
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

