#include <stdio.h>
#include <stdlib.h>

#define STACKMAXSIZE 10  //最大容量 

typedef char ElemType;
typedef struct
{
	ElemType *top;
	ElemType *bottom;
	int stacksize;
}STACK;

void initStack(STACK *s); //创建栈 
void pushStack(STACK *s, ElemType c);//入栈 
void popStack(STACK *s, ElemType *c);//出栈 
int stackLen(STACK *s);//计算栈当前容量 

int main(void)
{
	STACK s;
	ElemType c;
	int i,len,sum;
	
	initStack(&s);
	
	scanf("%c", &c);
	while(c!='#')
	{
		pushStack(&s,c);
		scanf("%c", &c);
	}
	
	len=stackLen(&s);
	sum=0;
	for(i=0; i<len; i++)
	{
		popStack(&s, &c);
		sum+=(c-'0')*(1<<i);//相当于 (1<<i)相当于pow(2,i) 
	}
	printf("\n");
	printf("%d\n", sum);
	
	return 0;
}

void initStack(STACK *s)
{//创建栈 
	s->bottom = (ElemType *)malloc(STACKMAXSIZE*sizeof(ElemType));
	s->top=s->bottom;
	s->stacksize=STACKMAXSIZE;
}

void pushStack(STACK *s, ElemType c)
{//入栈 
	if((s->top)-(s->bottom)>s->stacksize)
	{
		s->bottom=(ElemType *)realloc(s->bottom, (s->stacksize+1)*sizeof(ElemType)); 
		s->stacksize++;
		printf("FULL\n");
		printf("s->stacksize=%d\n", s->stacksize);
	}
	*(s->top)=c;
	s->top++;
}

void popStack(STACK *s, ElemType *c)
{//出栈 
	if(s->top==s->bottom)
		return;
	s->top--;
	*c=*(s->top);
}

int stackLen(STACK *s)
{//计算栈当前容量 
	return (s->top)-(s->bottom);
}
