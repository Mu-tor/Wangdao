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
int push(shareStack s,int n,int x) { //nΪҪ����ջ��xΪҪ��ջ��ֵ
	//n=0Ϊջs1��n=1Ϊջs2
	if(n<0||n>1) {
		printf("�����ջ�Ŵ���");
		return 0;//Ҫ���ջ�Ŵ���
	}
	if((s->top[0]+1)>=s->top[1]) { //ջ��
		printf("ջ��\n");
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
element pull(shareStack s,int n) { //��ջ���ɹ�����ջ��Ԫ�أ�ʧ�ܷ���-1
	if(n<0||n>1) {
		printf("�����ջ�Ŵ���");
		return 0;//Ҫ���ջ�Ŵ������
	}
	switch(n) {
	case 0:
		if(s->top[n]<=-1){
			printf("ջ��");
			return -1;
		}else{
			return s->data[s->top[n]--];
		}
		break;
	case 1:
		if(s->top[n]==MAXSIZE){
			printf("ջ��");
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
		printf("����Ҫ���еĲ���(0:�룬1:��)��");
		scanf("%d",&i);
		switch(i){
			case 0:
				printf("����Ҫ���ջ��");
				scanf("%d",&n);
				printf("����Ҫ��ջ��ֵ��");
				scanf("%d",&x);
				push(s,n,x);
				break;
			case 1:
				printf("����Ҫ����ջ��");
				scanf("%d",&n);
				printf("��ջ��ֵ:%d\n",pull(s,n));
		}
	}
	return 0;
}

