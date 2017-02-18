#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define Status int
#define STACKINCREAMENT 10
#define STACK_INIT_SIZE 100
typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack *s){
		int data[STACK_INIT_SIZE];
		s->base = data;
		if (!s->base){
			return ERROR;
		}
		else{
			s->top = s->base;
			s->stacksize = STACK_INIT_SIZE;
			return OK;
		}
}
Status Push(SqStack *s, SElemType e){
	if ((s->top)-(s->base)==STACK_INIT_SIZE){
		printf("\n此栈已满!\n");
		return ERROR;
	}
	else{
		*(s->top) = e;
		s->top++;
		return OK;
	}
}
void Pop(SqStack *s){
	int e;
	if (s->top==s->base){
		printf("\n该栈已空!\n");
		exit(1);
	}
	//e = *--s->top;
	s->top--;
	e = *(s->top);
	printf("%d\n", e);
}
void main(){
	SqStack s;
	if (InitStack(&s)){
		printf("\n初始化成功!\n");
	}
	if (Push(&s,1)){
		printf("\n入栈成功!\n");
	}
	if (Push(&s, 2)){
		printf("\n入栈成功!\n");
	}
	Pop(&s);
	Pop(&s);
}