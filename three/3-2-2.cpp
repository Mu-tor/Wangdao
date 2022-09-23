#include"Stack.h"
#include"Queue.h"
using namespace std;
void ReverseQueue(Queue &q){
	Stack s;
	int x;
	while(!QueueEmpty(q)){//出队入栈
		Dequeue(q,x);
		Push(s,x);
	}
	while(!StackEmpty(s)){//出栈入队
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

