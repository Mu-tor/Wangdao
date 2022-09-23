#include"Stack.h"
using namespace std;
Stack s1,s2;
int Enqueue(int x){
	int temp;
	if(StackOverflow(s2)||StackOverflow(s1)){//s1��s2ջ��������
		return 0;
	}
	while(!StackEmpty(s2)){//��s2������Ԫ�����õ�s1
		Pop(s2,temp);
		Push(s1,temp);
	}
	Push(s1,x);//s1ջ������β
	return 1;
}
int Dequeue(int &x){
	int temp;
	if(StackEmpty(s1)&&StackEmpty(s2)){//s1,s2ջ�ռ��ӿ�
		return 0;
	}
	while(!StackEmpty(s1)){//��s1������Ԫ�����õ�s2
		Pop(s1,temp);
		Push(s2,temp);
	}
	Pop(s2,x);//s2ջ������ͷ
	return 1;
}
int QueueEmpty(){
	return StackEmpty(s1);
}
int main(){
	int select;
	int x;
	while(1){
		printf("�������(0:���,1:����,2:���Ƿ�Ϊ��):");
		scanf("%d",&select);
		switch(select){
			case 0:
				printf("���Ԫ��:");
				scanf("%d",&x);
				if(Enqueue(x)){
					printf("��ӳɹ���\n");
				}else{
					printf("������\n");
				}
				break;
			case 1:
				if(Dequeue(x)){
					printf("����Ԫ��:%d\n",x);
				}else{
					printf("�ӿ�\n");
				}
				break;
			case 2:
				printf(QueueEmpty()?"�ӿ�\n":"�Ӳ�Ϊ��\n");
				break;
			default:
				printf("��������!\n");
		}
	}
	return 0;
}

