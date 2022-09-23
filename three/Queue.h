#include<cstdio>
#include<cstdlib>
#define MAXSIZE 1000
typedef struct Queue {
	int data[MAXSIZE];
	int front = 0,rear = 0;
}Queue;
int Enqueue(Queue &q,int x) {
	if((q.rear+1)%MAXSIZE==q.front) { //队满
		return 0;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear+1)%MAXSIZE;
	return 1;
}
int Dequeue(Queue &q,int &x) {
	if(q.front==q.rear) { //队空
		return 0;
	}
	x = q.data[q.front];
	q.front = (q.front+1)%MAXSIZE;
	return 1;
}
int QueueEmpty(Queue &q) {
	return q.front==q.rear;
}
void printQueue(Queue &q) { //输出队列内容(仅测试用)
	printf("队内元素:");
	for(int i = q.front;i!=q.rear;i=(i+1)%MAXSIZE){
		printf("%d ",q.data[i]);
	}
	printf("\n");
}
