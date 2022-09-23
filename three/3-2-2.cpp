#include"Stack.h"
#include"Queue.h"
using namespace std;
void ReverseQueue(Queue &q){
	Stack s;
	int x;
	while(!QueueEmpty(q)){//������ջ
		Dequeue(q,x);
		Push(s,x);
	}
	while(!StackEmpty(s)){//��ջ���
		Pop(s,x);
		Enqueue(q,x);
	}
}

int main() {
	Queue q;
	for(int i=0;i<10;i++){
		Enqueue(q,i);
	}
	printQueue(q);
	ReverseQueue(q);
	printQueue(q);
	return 0;
}

