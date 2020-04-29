#include <stdio.h> 

#define MAXSTACK 10

void pushStack(int data[], int *top, int a); 
void oppStack(int data[], int *top);

//1 2 3 4 5 6 7 8 9 10
int main(void)
{
	int data[MAXSTACK];
	int top=-1;
	int temp;
	int i;
	
	for(i=0;i<10;i++)
	{
		scanf("%d", &temp);
		pushStack(data, &top, temp);
	}
	pushStack(data, &top, 520);
	for(i=0;i<10;i++)
	{
		oppStack(data, &top);
	}
	printf("\n"); 
	oppStack(data, &top);
	return 0;
}

void pushStack(int data[], int *top, int a)
{
	if((*top)>=MAXSTACK-1)
		printf("满栈, %d 无法入栈\n", a);
	else
	{ 
		(*top)++;
		data[*top]=a;
	}
}

void oppStack(int data[], int *top)
{
	if(*top==-1)
		printf("栈已空，无法出栈\n");
	else
	{
		printf("%d ",data[*top]);
		(*top)--;
	}
}

