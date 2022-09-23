#include<cstdio>
#include<cstdlib>
#define MAXSIZE 5
#define Elemtype int
using namespace std;
typedef struct QNode{//循环队列
	Elemtype data[MAXSIZE];
	int front,rear;
	int tag;//当标志为0时若front=rear则队列为空，否则队满
}*Queue;
void InitQueue(Queue &q){//初始队列
	q->front = q->rear = q->tag = 0;
}
int Enqueue(Queue &q,Elemtype x){//新元素入队
	if(q->front == q->rear&&q->tag==1) return 0;//队满
	q->data[q->rear]=x;//入队
	q->rear = (q->rear+1)%MAXSIZE;//队尾进一
	if(q->front==q->rear){//队满，tag置1
		q->tag = 1;
	}
	return 1;
}
int Dequeue(Queue &q,Elemtype &x){//元素出队并存入x
	if(q->front==q->rear&&q->tag==0)//队为空
		return 0;
	x = q->data[q->front];
	q->front = (q->front+1)%MAXSIZE;
	q->tag = 0;
	return 1;
}
void printQueue(Queue &q){//打印队列中的值(测试用)
	printf("队内元素:");
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
		printf("请输入要进行的操作(0:入队，1:出队):");
		scanf("%d",&sel);
		switch(sel){
			case 0:
				printf("请输入入队的值:");
				scanf("%d",&x);
				if(Enqueue(q,x)){
					printf("入队成功!\n");
				}else
					printf("队满!!!\n");
				printQueue(q);
				break;
			case 1:
				if(Dequeue(q,x)){
					printf("队首元素: %d\n",x);
				}else{
					printf("队空!!!\n");
				}
				printQueue(q);
				break;
		}
	}
	return 0;
}
