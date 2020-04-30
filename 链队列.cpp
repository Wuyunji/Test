#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode;

typedef struct 
{
	QNode *front;
	QNode *rear;
}LinkQueue;

void IniQueue(LinkQueue *s);//初始化队列 
void EnterQueue(LinkQueue *s, ElemType a);//入队列 
void OutQueue(LinkQueue *s, ElemType *ch);//出队列 
int LenQueue(LinkQueue *s);//返回队列的结点个数 

//123456789#
int main(void)
{
	LinkQueue s;
	ElemType a;
	int len,i;
	
	IniQueue(&s);//初始化队列 
	
	scanf("%c", &a);
	while(a!='#')
	{
		EnterQueue(&s, a);
		scanf("%c", &a);
	}
	
	len = LenQueue(&s);
	for(i=0; i<len; i++)
	{
		OutQueue(&s, &a);
		printf("%c", a);
	}
	 
	return 0;
}

void IniQueue(LinkQueue *s)
{//初始化队列 
	s->front=(QNode *)malloc(sizeof(QNode));
	s->rear=s->front;
}

void EnterQueue(LinkQueue *s, ElemType a)
{//入队列 
	QNode *p=s->rear; 
	s->rear=(QNode *)malloc(sizeof(QNode));
	s->rear->data=a;
	p->next=s->rear;
}

void OutQueue(LinkQueue *s, ElemType *a)
{//出队列 
//	if(s->front==s->rear)
//	{
//		printf("队列已空\n");
//		return;
//	} 
	QNode *p=s->front->next;
	*a=p->data;
	free(s->front);
	s->front=p;
}

int LenQueue(LinkQueue *s)
{//返回队列的结点个数 
	int len=0;
	QNode *q=s->front;
	while(q!=s->rear)
	{
		q=q->next;
		len++;
	}
	return len;
}
