#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 2
#define element int
typedef struct stack {
	element data[MAXSIZE];
	int top[2];
}*shareStack,stack;
void initStack(shareStack s){
	s->top[0] = -1;
	s->top[1] = MAXSIZE;
}
int push(shareStack s,int n,int x) { //n为要进的栈，x为要进栈的值
	//n=0为栈s1，n=1为栈s2
	if(n<0||n>1) {
		printf("输入的栈号错误");
		return 0;//要入的栈号错误
	}
	if((s->top[0]+1)>=s->top[1]) { //栈满
		printf("栈满\n");
		return 0;
	}
	switch(n) {
	case 0:
		s->data[++s->top[n]] = x;
		return 1;
		break;
	case 1:
		s->data[--s->top[n]] = x;
		return 1;
	}
	return 0;
}
element pull(shareStack s,int n) { //退栈，成功返回栈顶元素，失败返回-1
	if(n<0||n>1) {
		printf("输入的栈号错误");
		return 0;//要入的栈号错误错误
	}
	switch(n) {
	case 0:
		if(s->top[n]<=-1){
			printf("栈空");
			return -1;
		}else{
			return s->data[s->top[n]--];
		}
		break;
	case 1:
		if(s->top[n]==MAXSIZE){
			printf("栈空");
			return -1;
		}else{
			return s->data[s->top[n]++];
		}
	}
	return -1;
}
int main() {
	int push(shareStack s,int n,int x);
	element pull(shareStack s,int n);
	shareStack s = (shareStack)malloc(sizeof(stack));
	initStack(s);
	int n,i,x;
	while(1){
		printf("输入要进行的操作(0:入，1:出)：");
		scanf("%d",&i);
		switch(i){
			case 0:
				printf("输入要入的栈：");
				scanf("%d",&n);
				printf("输入要入栈的值：");
				scanf("%d",&x);
				push(s,n,x);
				break;
			case 1:
				printf("输入要出的栈：");
				scanf("%d",&n);
				printf("出栈的值:%d\n",pull(s,n));
		}
	}
	return 0;
}

