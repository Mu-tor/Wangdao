#include<cstdio>
#include<cstdlib>
#define MAXSIZE 1000
typedef struct Stack {
	int data[MAXSIZE];
	int top = -1;
}Stack;
int StackEmpty(Stack &s) {//判断栈空
	return s.top == -1;
}
int StackOverflow(Stack &s) {//判断栈满
	return s.top == MAXSIZE-1;
}
int Push(Stack &s,int x) {//入栈
	if(StackOverflow(s)) return 0;//栈满
	s.data[++s.top] = x;
	return 1;
}
int Pop(Stack &s,int &x){//出栈
	if(StackEmpty(s)) return 0;
	x = s.data[s.top--];
	return 1;
}
void printStack(Stack &s){//输出栈内元素(仅测试用)
	printf("栈内元素:");
	for(int i=0;i<=s.top;i++){
		printf("%d ",s.data[i]);
	}
	printf("\n");
}
