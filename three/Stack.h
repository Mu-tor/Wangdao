#include<cstdio>
#include<cstdlib>
#define MAXSIZE 1000
typedef struct Stack {
	int data[MAXSIZE];
	int top = -1;
}Stack;
int StackEmpty(Stack &s) {//�ж�ջ��
	return s.top == -1;
}
int StackOverflow(Stack &s) {//�ж�ջ��
	return s.top == MAXSIZE-1;
}
int Push(Stack &s,int x) {//��ջ
	if(StackOverflow(s)) return 0;//ջ��
	s.data[++s.top] = x;
	return 1;
}
int Pop(Stack &s,int &x){//��ջ
	if(StackEmpty(s)) return 0;
	x = s.data[s.top--];
	return 1;
}
void printStack(Stack &s){//���ջ��Ԫ��(��������)
	printf("ջ��Ԫ��:");
	for(int i=0;i<=s.top;i++){
		printf("%d ",s.data[i]);
	}
	printf("\n");
}
