#include"Stack.h"
using namespace std;
Stack s1,s2;
int Enqueue(int x){
	int temp;
	if(StackOverflow(s2)||StackOverflow(s1)){//s1或s2栈满即队满
		return 0;
	}
	while(!StackEmpty(s2)){//将s2中所有元素逆置到s1
		Pop(s2,temp);
		Push(s1,temp);
	}
	Push(s1,x);//s1栈顶即队尾
	return 1;
}
int Dequeue(int &x){
	int temp;
	if(StackEmpty(s1)&&StackEmpty(s2)){//s1,s2栈空即队空
		return 0;
	}
	while(!StackEmpty(s1)){//将s1中所有元素逆置到s2
		Pop(s1,temp);
		Push(s2,temp);
	}
	Pop(s2,x);//s2栈顶即队头
	return 1;
}
int QueueEmpty(){
	return StackEmpty(s1);
}
int main(){
	int select;
	int x;
	while(1){
		printf("输入操作(0:入队,1:出队,2:队是否为空):");
		scanf("%d",&select);
		switch(select){
			case 0:
				printf("入队元素:");
				scanf("%d",&x);
				if(Enqueue(x)){
					printf("入队成功！\n");
				}else{
					printf("队满！\n");
				}
				break;
			case 1:
				if(Dequeue(x)){
					printf("队首元素:%d\n",x);
				}else{
					printf("队空\n");
				}
				break;
			case 2:
				printf(QueueEmpty()?"队空\n":"队不为空\n");
				break;
			default:
				printf("重新输入!\n");
		}
	}
	return 0;
}

