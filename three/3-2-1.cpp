#include<cstdio>
#include<cstdlib>
#define MAXSIZE 5
#define Elemtype int
using namespace std;
typedef struct QNode{//ѭ������
	Elemtype data[MAXSIZE];
	int front,rear;
	int tag;//����־Ϊ0ʱ��front=rear�����Ϊ�գ��������
}*Queue;
void InitQueue(Queue &q){//��ʼ����
	q->front = q->rear = q->tag = 0;
}
int Enqueue(Queue &q,Elemtype x){//��Ԫ�����
	if(q->front == q->rear&&q->tag==1) return 0;//����
	q->data[q->rear]=x;//���
	q->rear = (q->rear+1)%MAXSIZE;//��β��һ
	if(q->front==q->rear){//������tag��1
		q->tag = 1;
	}
	return 1;
}
int Dequeue(Queue &q,Elemtype &x){//Ԫ�س��Ӳ�����x
	if(q->front==q->rear&&q->tag==0)//��Ϊ��
		return 0;
	x = q->data[q->front];
	q->front = (q->front+1)%MAXSIZE;
	q->tag = 0;
	return 1;
}
void printQueue(Queue &q){//��ӡ�����е�ֵ(������)
	printf("����Ԫ��:");
	int length =(q->rear-q->front+MAXSIZE)%MAXSIZE;
	length = q->tag==1?MAXSIZE:length;
	for(int i=q->front,j=0;j<length&&(i!=q->rear||q->tag==1);i++,j++){
		i%=MAXSIZE;
		printf("%d ",q->data[i]);
	}
	printf("\n");
}
int main(){
	Queue q = (Queue)malloc(sizeof(QNode));
	InitQueue(q);
	int sel,x;
	while(1){
		printf("������Ҫ���еĲ���(0:��ӣ�1:����):");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				printf("��������ӵ�ֵ:");
				scanf("%d",&x);
				if(Enqueue(q,x)){
					printf("��ӳɹ�!\n");
				}else
					printf("����!!!\n");
				printQueue(q);
				break;
			case 1:
				if(Dequeue(q,x)){
					printf("����Ԫ��: %d\n",x);
				}else{
					printf("�ӿ�!!!\n");
				}
				printQueue(q);
				break;
		}
	}
	return 0;
}
