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
void printList(LinkList &l){//输出链表
	LNode *p = l->link;
	while(p){
		printf("%d ",p->data);
		p = p->link;
	}//while
	printf("\n");
}
void initTestList(LinkList &l,int m,int n){//创建一个测试链表
	//m为长度，n为上限
	LNode *p = l;
	for(int i=0;i<m;i++){
		LNode *q = (LNode*)malloc(sizeof(LNode));
		q->data = (int)pow(-1.0,(double)i)*rand()%n;
		p->link = q;
		p = q;
	}
	p->link = NULL;
}

void delSameAbs(LNode *head,int n){//删除相同绝对值结点
	int *s = (int*)malloc(sizeof(int)*n+1);//定义一个长度为n的数组
	memset(s,0,sizeof(int)*n+1);//数组置空
	int abs;//存储当前值的绝对值
	LNode *pre = head,*p = head->link;
	while(p){
		abs = p->data>0?p->data:-p->data;
		if(s[abs] == 0){//未出现相同元素绝对值的结点
			s[abs] = 1;//标记出现过的元素的绝对值
			p = p->link;//遍历下一结点
			pre = pre->link;
		}else{//已出现元素绝对值的结点
			pre->link = p->link;//断开该节点
			free(p);//删除结点
			p = pre->link;//接上结点，继续遍历
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

