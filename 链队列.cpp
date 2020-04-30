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

void IniQueue(LinkQueue *s);//��ʼ������ 
void EnterQueue(LinkQueue *s, ElemType a);//����� 
void OutQueue(LinkQueue *s, ElemType *ch);//������ 
int LenQueue(LinkQueue *s);//���ض��еĽ����� 

//123456789#
int main(void)
{
	LinkQueue s;
	ElemType a;
	int len,i;
	
	IniQueue(&s);//��ʼ������ 
	
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
{//��ʼ������ 
	s->front=(QNode *)malloc(sizeof(QNode));
	s->rear=s->front;
}

void EnterQueue(LinkQueue *s, ElemType a)
{//����� 
	QNode *p=s->rear; 
	s->rear=(QNode *)malloc(sizeof(QNode));
	s->rear->data=a;
	p->next=s->rear;
}

void OutQueue(LinkQueue *s, ElemType *a)
{//������ 
//	if(s->front==s->rear)
//	{
//		printf("�����ѿ�\n");
//		return;
//	} 
	QNode *p=s->front->next;
	*a=p->data;
	free(s->front);
	s->front=p;
}

int LenQueue(LinkQueue *s)
{//���ض��еĽ����� 
	int len=0;
	QNode *q=s->front;
	while(q!=s->rear)
	{
		q=q->next;
		len++;
	}
	return len;
}
