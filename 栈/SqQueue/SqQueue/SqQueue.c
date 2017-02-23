#include <stdio.h>  
#include <stdlib.h>  

#define OK 1  
#define ERROR 0  

#define QUEUE_SIZE 7

typedef  int Status;
typedef  int ElemType;

typedef struct Qnode
{
	ElemType *base;
	int front;
	int rear;
	int count;
} Qnode;
Status InitSqQueue(Qnode *s){
	s->base = (ElemType*)malloc(QUEUE_SIZE*sizeof(ElemType));
	if (!s->base){
		printf("\n申请失败\n");
		return ERROR;
	}
	s->front = s->rear = 0;
	s->count = 0;
	return OK;
}
Status EnSqQueue(Qnode *s,ElemType e){
	if ((s->rear+1)%QUEUE_SIZE==s->front){
		printf("\n队列已满!\n");
		return ERROR;
	}
	s->base[s->rear] = e;
	s->rear=(s->rear+1)% QUEUE_SIZE;
	s->count++;
	return OK;
}
Status DeSqQueue(Qnode *s,ElemType *e){
	if (s->front==s->rear){
		printf("\n队列已空!\n");
		return ERROR;
	}
	*e = s->base[s->front];
	s->front = (s->front + 1) % QUEUE_SIZE;
	s->count--;
	return OK;
}
void Print_SqQeueue(Qnode *s){
	if (s->front==s->rear){
		printf("\n栈为空!\n");
		exit(1);
	}
	for (int i = 0; i<= (s->count)-1; i++){
		printf("%d\n", s->base[(s->front + i) % QUEUE_SIZE]);
	}
}
void main(){
	Qnode s;
	InitSqQueue(&s);
	EnSqQueue(&s, 1);
	EnSqQueue(&s, 2);
	EnSqQueue(&s, 3);
	EnSqQueue(&s, 4);
	EnSqQueue(&s, 5);
	EnSqQueue(&s, 6);
	Print_SqQeueue(&s);
}